# DMA高速化の最適化案

## 実装状況

✅ **実装済み** (2024年実装):
1. `imemcpy_fast_aligned`: アライメント済み大ブロック用高速コピー関数
2. `xmax_bzero_fast_large`: 大ブロック用ゼロクリア最適化関数
3. `xmax_cpyin` case 3: 条件分岐による最適化パスの選択

## 分析結果

現在のコードを分析した結果、以下のDMA効率化の機会が確認されました。

## 1. メモリコピー関数の最適化

### 1.1 `imemcpy`の最適化
**現状**: アライメントチェックと複数の分岐がある
**提案**: 
- DMAバッファは事前にアライメント済みと仮定して、アライメントチェックをスキップする高速パスを追加
- キャッシュラインサイズ（64バイト/128バイト）に合わせたブロックコピー
- SIMD命令（NEON）を使用した128ビット/256ビット転送

```c
// 最適化案: アライメント済みパス
void imemcpy_aligned(Dll *dst, Dll *src, int words) {
    int loop = words / (sizeof(Dll)/sizeof(Uint));
    for(int i = 0; i < loop; i += 8) {  // ループ展開
        *(Dll*)(dst+i) = *(Dll*)(src+i);
        *(Dll*)(dst+i+1) = *(Dll*)(src+i+1);
        *(Dll*)(dst+i+2) = *(Dll*)(src+i+2);
        *(Dll*)(dst+i+3) = *(Dll*)(src+i+3);
        *(Dll*)(dst+i+4) = *(Dll*)(src+i+4);
        *(Dll*)(dst+i+5) = *(Dll*)(src+i+5);
        *(Dll*)(dst+i+6) = *(Dll*)(src+i+6);
        *(Dll*)(dst+i+7) = *(Dll*)(src+i+7);
    }
    // 残りを処理
}
```

### 1.2 `imemcpy_byte_by_byte`の削除または置き換え
**現状**: バイト単位のコピーでvolatile使用、非常に非効率
**提案**: 
- 通常の`imemcpy`を使用
- 必要に応じてキャッシュフラッシュを明示的に行う

## 2. キャッシュ最適化

### 2.1 プリフェッチの追加
**現状**: プリフェッチが使用されていない
**提案**: 次のデータを事前に読み込む

```c
// ARM64用プリフェッチ
void imemcpy_with_prefetch(Uint *dst, Uint *src, int words) {
    int loop = words / (sizeof(Dll)/sizeof(Uint));
    for(int i = 0; i < loop; i++) {
        // 次のキャッシュラインをプリフェッチ（4-8ループ先）
        if (i + 8 < loop) {
            __builtin_prefetch(src + (i+8)*sizeof(Dll)/sizeof(Uint), 0, 3);
            __builtin_prefetch(dst + (i+8)*sizeof(Dll)/sizeof(Uint), 1, 3);
        }
        *(Dll*)dst = *(Dll*)src;
        src += sizeof(Dll)/sizeof(Uint);
        dst += sizeof(Dll)/sizeof(Uint);
    }
}
```

### 2.2 キャッシュフラッシュ/クリーニング
**現状**: DMAバッファへの書き込み後のキャッシュ処理が不明確
**提案**: 
- `xmax_cpyin`で書き込み後に`__builtin___clear_cache`または`__dsb()`を追加
- ARM64の非キャッシュ可能メモリ属性の利用を検討

```c
// DMA転送前のキャッシュクリーニング
void dma_cache_clean(void *addr, size_t size) {
    __asm__ volatile (
        "dc civac, %0\n\t"
        "dsb sy\n\t"
        : : "r" (addr) : "memory"
    );
}
```

## 3. データ転送の最適化

### 3.1 不要なコピーの回避
**現状**: `xmax_cpyin`でデータが同じかチェックしているが、比較が非効率
**提案**:
- より効率的な比較（ハッシュまたはチェックサム）
- 転送フラグの最適化

```c
// 高速な比較（64ビット×数ワード）
static inline int fast_memcmp_64bit(Ull *a, Ull *b, int word_count) {
    int ull_count = (word_count + 1) / 2;
    for (int i = 0; i < ull_count; i++) {
        if (a[i] != b[i]) return 1;
    }
    return 0;
}
```

### 3.2 非連続転送の最適化
**現状**: `xmax_cpyin`のorder 2で非連続アクセスが多い
**提案**:
- 転送をバッチ化して連続アクセスに変換
- 中間バッファを使用してアクセスパターンを改善

### 3.3 ゼロクリアの最適化
**現状**: `xmax_bzero`で16バイト単位でクリア
**提案**:
- 大きなブロックは一括ゼロクリア（memset最適化版）
- SIMD命令を使用

```c
void __attribute__((optimize("O3"))) xmax_bzero_optimized(Uint *dst, int words) {
    if (words >= 64) {
        // 大きなブロックは一括処理
        memset(dst, 0, words * sizeof(Uint));
        return;
    }
    // 小さなブロックは従来通り
    // ... 既存のコード ...
}
```

## 4. 並列化の最適化

### 4.1 複数LANE間の効率的なデータ共有
**現状**: 各LANEが独立してDMA転送を実行
**提案**:
- 共有データ（SRC0など）の転送を1回だけ実行
- 転送済みデータの共有メカニズムを追加

### 4.2 非同期DMA転送
**現状**: 同期転送が多い
**提案**:
- 次のデータを事前に転送開始
- 転送完了をポーリングまたはコールバックで確認

## 5. メモリアクセスパターンの最適化

### 5.1 連続アクセスの確保
**現状**: 一部で非連続アクセスがある
**提案**:
- データレイアウトの再検討
- ストライドアクセスを最小化

### 5.2 ページサイズへのアライメント
**現状**: 4KB/2MBページ境界への最適化が不明
**提案**:
- 大きな転送はページ境界にアライメント
- ヒュージページの活用

## 6. コンパイラ最適化

### 6.1 インライン化
**提案**: 小さな関数は`__attribute__((always_inline))`を追加

### 6.2 ループ展開
**提案**: 小さいループは手動で展開（コンパイラに依存せず）

### 6.3 レジスタ最適化
**提案**: 頻繁に使用される変数はレジスタ変数として宣言

## 7. 実装優先順位

### 高優先度（即座に実装可能）
1. `imemcpy`のアライメント済み高速パスの追加
2. プリフェッチの追加
3. `xmax_bzero`の最適化（大きなブロックの一括処理）

### 中優先度（効果的だが実装が複雑）
4. キャッシュフラッシュ/クリーニングの最適化
5. 不要なコピーの回避（より効率的な比較）
6. 非連続転送のバッチ化

### 低優先度（アーキテクチャ変更が必要）
7. 非同期DMA転送
8. メモリレイアウトの再設計

## 8. 測定と検証

各最適化を実装した後、以下を測定：
- DMA転送時間（monitor_timeを使用）
- 全体の実行時間
- キャッシュミス率
- メモリ帯域幅使用率

## 9. 実装例

### 例1: 最適化されたimemcpy（アライメント済みパス付き）

```c
void imemcpy_opt(Uint *dst, Uint *src, int words) {
    // アライメントチェックを簡略化
    const Ull dst_aligned = ((Ull)dst & 0xF) == 0;
    const Ull src_aligned = ((Ull)src & 0xF) == 0;
    
    if (dst_aligned && src_aligned && words >= 4) {
        // 高速パス: 16バイトアライメント済み
        Dll *dst16 = (Dll*)dst;
        Dll *src16 = (Dll*)src;
        int loop = words / 4;
        int remainder = words % 4;
        
        // プリフェッチ付きループ
        for (int i = 0; i < loop; i++) {
            if (i + 8 < loop) {
                __builtin_prefetch(&src16[i+8], 0, 3);
                __builtin_prefetch(&dst16[i+8], 1, 3);
            }
            dst16[i] = src16[i];
        }
        
        // 残りを処理
        dst = (Uint*)&dst16[loop];
        src = (Uint*)&src16[loop];
        words = remainder;
    }
    
    // 従来のコードで残りを処理
    // ... 既存のimemcpyの残り部分 ...
}
```

### 例2: 最適化されたxmax_cpyin case 3

```c
case 3:
    {
        Ull byte_size = (Ull)(im*m) * sizeof(Uint);
        
        // 大きな転送は最適化された関数を使用
        if (byte_size >= 4096) {
            // キャッシュラインサイズ（64バイト）にアライメント済みと仮定
            imemcpy_aligned_fast(dst, src, im*m);
        } else {
            // 小さな転送は従来通り
            imemcpy(dst, src, im*m);
        }
        
        // DMA転送の前にキャッシュをクリーニング
        if (byte_size >= 256) {
            dma_cache_clean(dst, byte_size);
        }
    }
    break;
```

## 10. 注意事項

1. **volatileアクセスの必要性**: DMAバッファへのアクセスがvolatileでない場合は、最適化の余地が大きい
2. **メモリ順序**: マルチスレッド環境での順序保証が必要な場合は、適切なメモリバリアを使用
3. **プラットフォーム依存**: ARM64固有の最適化が含まれるため、他のプラットフォームでは条件コンパイルが必要

## 11. 参考情報

- ARM64 NEON命令セット
- ARM Architecture Reference Manual (キャッシュ制御)
- GCC/Clang組み込み関数のドキュメント

