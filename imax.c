/*                          Copyright (C) 2013- by NAIST */
/*                           Primary writer: Y.Nakashima */
/*                                  nakashim@is.naist.jp */

#ifndef UTYPEDEF
#define UTYPEDEF
typedef unsigned char      Uchar;
typedef unsigned short     Ushort;
typedef unsigned int       Uint;
typedef unsigned long long Ull;
typedef long long int      Sll;
#if __AARCH64EL__ == 1
typedef long double Dll;
#else
typedef struct {Ull u[2];} Dll;
#endif
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <fcntl.h>
#include <math.h>
#include <pthread.h>
#include <signal.h>
#include <assert.h>
#ifdef CBLAS_GEMM
#include "cblas.h"
#endif
#define GGML_COMMON_DECL_C
#include "ggml/src/ggml-common.h"
#include "ggml/include/ggml.h"
#include "ggml/include/ggml-imax.h"
#include "include/ggml-cpu.h"
// #include "tools/main/main.cpp"
#include "monitor.h"
#if defined(ARMZYNQ)
#include "../../src/conv-c2d/emax7.h"
#include "../../src/conv-c2d/emax7lib.c"
#else
#include "../../src/conv-c2e/emax8.h"
#include "../../src/conv-c2e/emax8lib.c"
#endif

#if 0
#define QK_K 256
typedef struct {
  uint8_t hmask[QK_K/8]; // quants - high bit
  uint8_t qs[QK_K/4];    // quants - low 2 bits
  uint8_t scales[12];    // scales, quantized with 6 bits
  uint16_t d;            // super-block scale
} block_q3_K; /* FP16 | scales[12B] | qs[64B] | hmask[32B] *//* 110B */
typedef struct {
  float   d;              // delta
  int8_t  qs[QK_K];       // quants
  int16_t bsums[QK_K/16]; // sum of quants in groups of 16
} block_q8_K; /* bsums[16H] | qs[256B] | d(FP32) *//* 292B */

#define QK8_0 32
typedef struct {
  uint16_t d;         // delta
  int8_t   qs[QK8_0]; // quants
} block_q8_0; /* qs[32B] | d(FP16) *//* 34B */
#endif
    static Ull max_SRC0_ROW_LEN_COPY_BYTES = 0;
    static Ull max_SRC1_COL_LEN_COPY_BYTES = 0;
    
int cpyin_skip_count = 0;
void *memcpy();
pthread_barrier_t copy_barrier;
Uchar   *membase;
Ull     memsize_shared; /* shared by IMAXs */
Ull     memsize_local;  /* dedicated to each IMAX */
Ull     memsize;        /* total */
int     memalign;
int     src0_preloaded;
Ull     SRC0_ROW_TOP_DIRECT;

void    *i_i16[EMAX_NLANE]; /* for imax_ggml_compute_forward_mul_mat_q4_0_f32 on ACAP_PL */
void    *i_f16[EMAX_NLANE]; /* for imax_ggml_compute_forward_mul_mat_q4_0_f32 on ACAP_PL */
void    *i_m0A[EMAX_NLANE]; /* for imax_ggml_compute_forward_mul_mat_q4_0_f32 on ACAP_PL */
void    *i_m0B[EMAX_NLANE]; /* for imax_ggml_compute_forward_mul_mat_q4_0_f32 on ACAP_PL */
void    *i_m0C[EMAX_NLANE]; /* for imax_ggml_compute_forward_mul_mat_q4_0_f32 on ACAP_PL */
void    *i_m0D[EMAX_NLANE]; /* for imax_ggml_compute_forward_mul_mat_q4_0_f32 on ACAP_PL */
Ull     i_i16_max_size;
Ull     i_f16_max_size;
Ull     i_m0A_max_size;
Ull     i_m0B_max_size;
Ull     i_m0C_max_size;
Ull     i_m0D_max_size;
int     show_nanosec_count = 0;
Ull     TOTAL_BUFFER_LOAD_SIZE = 0;
Ull     TOTAL_BUFFER_DRAIN_SIZE = 0;
int     counter_imax_operations = 0;
#include <pthread.h>

pthread_barrier_t g_params_wdata_ready_barrier; // バリアオブジェクト
int g_n_consumer_threads = 0;                   // このバリアで同期するコンシューマスレッドの数
#define ERRTH  (5.0E-2)
#define udiff(a,b) (((a)-(b)>=0.0?(a)-(b):(b)-(a))/((a)==0.0?1:(a)))
#define setmax(max, new) { if (max < (new)) max = (new); }

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

#define GGML_FP16_TO_FP32(x) ggml_lookup_fp16_to_fp32(x)
extern float ggml_table_f32_f16[1 << 16];
inline static float ggml_lookup_fp16_to_fp32(ggml_fp16_t f) {
    return ggml_table_f32_f16[*(uint16_t*)&f];
}
#define GGML_INT16_TO_FP32(x) ggml_lookup_int16_to_fp32(x)
extern float ggml_table_f32_i16[1 << 16];
inline static float ggml_lookup_int16_to_fp32(uint16_t i) {
    return ggml_table_f32_i16[i];
}

void init_xmax(int nth)
{
  int l;

#if defined(EMAX7) && defined(ARMZYNQ)
  if ((NLANE = emax7_open(nth)) == NULL) /* EMAX7 MACRO_PIPELIING (vsim-zynq,vsim-zynq.emax7*) */
    exit(1);
  if (NLANE < nth) {
    printf("NLANE(installed=%d) < nth(requested=%d) in init_xmax\n", NLANE, nth);
    exit(1);
  }
#elif defined(EMAX8)
  if ((NLANE = emax8_open(nth)) == NULL) /* EMAX8 MACRO_PIPELIING (vsim-ubuntu,vsim-ubuntu.emax8*) */
    exit(1);
  if (NLANE < nth) {
    printf("NLANE(installed=%d) < nth(requested=%d) in init_xmax\n", NLANE, nth);
    exit(1);
  }
#else
  NLANE = nth; /* EMAX MACRO_PIPELIING (vsim.emax7nc,vsim.emax8nc) */
#endif
  
  // original ggml code for llama
  setmax(i_i16_max_size,     0x40000); /* sizeof(float) 16bit-index           (256KB) */
  setmax(i_f16_max_size,     0x40000); /* sizeof(float) 16bit-index           (256KB) */
  // setmax(i_m0A_max_size,     0x80000); /* 512KB */
  setmax(i_m0A_max_size,  0xEA000000); /* 3.8GB for direct-Q3K */
//setmax(i_m0B_max_size,      0x8000); /* bytes 0x2200,0x5b60                 ( 32KB) */
  setmax(i_m0B_max_size,    0x20000); /*                                          */
  // setmax(i_m0C_max_size,      0x40*8); /* sizeof(float)  0x10             x2x4(256 B) */
  setmax(i_m0C_max_size,      0x20000); /* sizeof(float)  0x10           1KB */
  //  setmax(i_m0C_max_size,  0x40*16); /* 512B for dst data (approx 20MB needed) */
  // setmax(i_m0D_max_size,      0x80000); /* 512KB for dst data (approx 20MB needed) */
  setmax(memsize_shared, i_i16_max_size+i_f16_max_size+i_m0A_max_size);
  setmax(memsize_local,  i_m0B_max_size+i_m0C_max_size);
  memsize = memsize_shared + memsize_local*NLANE; /* bytes */
  memalign = 32;

#if (defined(EMAX7) && defined(ARMZYNQ)) || defined(EMAX8)
  if (memsize > DDR_MMAP_SIZE) {
    printf("memsize*NLANE: %08.8x+%08.8x exceeds DDR_MMAP_SIZE=%08.8x\n", (Uint)memsize_shared, (Uint)memsize_local*NLANE, (Uint)DDR_MMAP_SIZE);
    exit(1);
  }
  membase = emax_info[0].ddr_mmap;
  /*{int i; for (i=0; i<(memsize+sizeof(Dll)-1)/sizeof(Dll); i++) *((Dll*)membase+i)=0;}*/
#elif __linux__ == 1
  if (posix_memalign(&membase, memalign, memsize) != 0) {
    printf("posix_memalign: failed to allocate size=%08.8x\n", (Uint)memsize);
    exit(1);
  }
#else
  if ((membase = (void*)malloc(memsize+memalign)) == NULL) {
    printf("malloc: failed to allocate size=%08.8x\n", (Uint)memsize+memalign);
    exit(1);
  }
  if ((Ull)membase & (Ull)(memalign-1))
    membase = (void*)(((Ull)membase & ~(Ull)(memalign-1))+memalign);
#endif

  printf("membase: %08.8x_%08.8x\n", (Uint)((Ull)membase>>32), (Uint)(Ull)membase);





   for (l=0; l<NLANE; l++) {
    i_i16[l] = (Uchar*)membase;
    i_f16[l] = (Uchar*)i_i16[l] + i_i16_max_size;
    i_m0A[l] = (Uchar*)i_f16[l] + i_f16_max_size;
    i_m0B[l] = (Uchar*)i_m0A[l] + i_m0A_max_size + memsize_local*l;
    i_m0C[l] = (Uchar*)i_m0B[l] + i_m0B_max_size;
    i_m0D[l] = (Uchar*)i_m0C[l] + i_m0C_max_size;
    printf("i_i16[%d] : %08.8x_%08.8x-%08.8x_%08.8x\n", l, (Uint)((Ull)i_i16[l]>>32), (Uint)i_i16[l], (Uint)(((Ull)i_i16[l]+i_i16_max_size-1)>>32), (Uint)(i_i16[l]+i_i16_max_size-1));
    printf("i_f16[%d] : %08.8x_%08.8x-%08.8x_%08.8x\n", l, (Uint)((Ull)i_f16[l]>>32), (Uint)i_f16[l], (Uint)(((Ull)i_f16[l]+i_f16_max_size-1)>>32), (Uint)(i_f16[l]+i_f16_max_size-1));
    printf("i_m0A[%d] : %08.8x_%08.8x-%08.8x_%08.8x\n", l, (Uint)((Ull)i_m0A[l]>>32), (Uint)i_m0A[l], (Uint)(((Ull)i_m0A[l]+i_m0A_max_size-1)>>32), (Uint)(i_m0A[l]+i_m0A_max_size-1));
    printf("i_m0B[%d] : %08.8x_%08.8x-%08.8x_%08.8x\n", l, (Uint)((Ull)i_m0B[l]>>32), (Uint)i_m0B[l], (Uint)(((Ull)i_m0B[l]+i_m0B_max_size-1)>>32), (Uint)(i_m0B[l]+i_m0B_max_size-1));
    printf("i_m0C[%d] : %08.8x_%08.8x-%08.8x_%08.8x\n", l, (Uint)((Ull)i_m0C[l]>>32), (Uint)i_m0C[l], (Uint)(((Ull)i_m0C[l]+i_m0C_max_size-1)>>32), (Uint)(i_m0C[l]+i_m0C_max_size-1));
  }
  int ctmp;
  printf("Initializing i_i16[0]/DMABUF from ggml_table_f32_i16 size=%16.16llx\n", i_i16_max_size);
  xmax_cpyin(3, i_i16[0], &ctmp, ggml_table_f32_i16, 1, 1, i_i16_max_size/sizeof(int), 1, 1);
  printf("Initializing i_i16[0]/DMABUF from ggml_table_f32_f16 size=%16.16llx\n", i_f16_max_size);
  xmax_cpyin(3, i_f16[0], &ctmp, ggml_table_f32_f16, 1, 1, i_f16_max_size/sizeof(int), 1, 1);

#if 1
  for (l=0; l<IMAX_DMABUF_LAST; l++) {
    if (imax_dmabuf_map[l].dmabufmap == 2) /* src0 */
      break;
  }

  printf("imax_dmabuf_map[%d].blk_size=%16.16llx\n", l, imax_dmabuf_map[l].blk_size);
  printf("i_m0A_max_size=%16.16llx\n", i_m0A_max_size);
  if (l < IMAX_DMABUF_LAST && imax_dmabuf_map[l].blk_size < i_m0A_max_size) { /* for Q3K */
    printf("Found imax_dmabuf_map[%d] src_blk_top=%16.16llx blk_size=%16.16llx\n", l, imax_dmabuf_map[l].src_blk_top, imax_dmabuf_map[l].blk_size, imax_dmabuf_map[l].imax_blk_ofs);
    printf("Initializing i_m0A[0]/DMABUF from imax_dmabuf_map[%d].src_blk_top size=%16.16llx\n", l, imax_dmabuf_map[l].blk_size);
    monitor_time_start(0, IMAX_CPYIN_PRELOAD);
    xmax_cpyin(3, i_m0A[0], &ctmp, imax_dmabuf_map[l].src_blk_top, 1, 1, imax_dmabuf_map[l].blk_size/sizeof(int), 1, 1);
    monitor_time_end(0, IMAX_CPYIN_PRELOAD);
    printf("preload ok\n");
    src0_preloaded = 1;
    SRC0_ROW_TOP_DIRECT = imax_dmabuf_map[l].src_blk_top;
  }
  
if (NLANE > 0) { // NLANE が有効な値であることを確認
    if (pthread_barrier_init(&g_params_wdata_ready_barrier, NULL, NLANE) != 0) {
        perror("ERROR: pthread_barrier_init for g_params_wdata_ready_barrier failed");
        // 致命的なエラーとして処理 (例: exit)
    }
    printf("INFO: g_params_wdata_ready_barrier initialized for %d consumer threads.\n", NLANE);
} else {
    // NLANE が0または負の場合の警告またはエラー処理
    printf("WARN: NLANE is %d, g_params_wdata_ready_barrier not initialized.\n", NLANE);
}
#endif

#if defined(EMAX7) && defined(ARMZYNQ)
  { int i;
    int stat;
    for (i=0; i<NLANE; i++) {
      emax7[i].dma_ctrl  = emax_info[i].dma_mmap;
      emax7[i].reg_ctrl  = emax_info[i].reg_mmap;
      ((struct reg_ctrl*)emax7[i].reg_ctrl)->i[0].cmd = CMD_RESET;  // ?????? RESET
#if defined(ARMZYNQ)
      usleep(1);
#endif
      ((struct reg_ctrl*)emax7[i].reg_ctrl)->i[0].adtr = emax_info[i].ddr_mmap - emax_info[i].lmm_phys;
      ((struct reg_ctrl*)emax7[i].reg_ctrl)->i[0].dmrp = 0LL;
      stat = ((struct reg_ctrl*)emax7[i].reg_ctrl)->i[0].stat>>8 & 0xf;
      switch (stat) {
      case  0:EMAX_DEPTH =  8;break;
      case  1:EMAX_DEPTH = 16;break;
      case  2:EMAX_DEPTH = 32;break;
      case  3:EMAX_DEPTH = 64;break;
      default:
        printf("init_xmax: illegal stat=%x for setting EMAX_DEPTH\n", stat);
        exit(1);
      }

      stat = ((struct reg_ctrl*)emax7[i].reg_ctrl)->i[0].stat>>12 & 0xf;
      switch (stat) {
      case  0:LMM_SIZE =  32768;break;
      case  1:LMM_SIZE =  65536;break;
      case  2:LMM_SIZE = 131072;break;
      case  3:LMM_SIZE = 262144;break;
      case  4:LMM_SIZE = 524288;break;
      default:
        printf("init_xmax: illegal stat=%x for setting LMM_SIZE\n", stat);
        exit(1);
      }
      printf("EMAX7[%d].DEPTH=%d LMM_SIZE=%d\n", i, EMAX_DEPTH, LMM_SIZE);
    }
  }
  printf("EMAX7: NLANE=%d DEPTH=%d LMM_SIZE=%d\n", NLANE, EMAX_DEPTH, LMM_SIZE);
#endif
#if defined(EMAX8)
  { int i;
    int stat;
    for (i=0; i<NLANE; i++) {
      emax8[i].dma_ctrl  = emax_info[i].dma_mmap;
      emax8[i].reg_ctrl  = emax_info[i].reg_mmap;
      ((struct reg_ctrl*)emax8[i].reg_ctrl)->i[0].cmd = CMD_RESET;  // ?????? RESET
      usleep(1);
      ((struct reg_ctrl*)emax8[i].reg_ctrl)->i[0].adtr = emax_info[i].ddr_mmap - emax_info[i].lmm_phys;
      ((struct reg_ctrl*)emax8[i].reg_ctrl)->i[0].dmrp = 0LL;
      stat = ((struct reg_ctrl*)emax8[i].reg_ctrl)->i[0].stat>>8 & 0xf;
      switch (stat) {
      case  0:EMAX_DEPTH =  8;break;
      case  1:EMAX_DEPTH = 16;break;
      case  2:EMAX_DEPTH = 32;break;
      case  3:EMAX_DEPTH = 64;break;
      default:
        printf("init_xmax: illegal stat=%x for setting EMAX_DEPTH\n", stat);
        exit(1);
      }

      stat = ((struct reg_ctrl*)emax8[i].reg_ctrl)->i[0].stat>>12 & 0xf;
      switch (stat) {
      case  0:LMM_SIZE =  32768;break;
      case  1:LMM_SIZE =  65536;break;
      case  2:LMM_SIZE = 131072;break;
      case  3:LMM_SIZE = 262144;break;
      case  4:LMM_SIZE = 524288;break;
      default:
        printf("init_xmax: illegal stat=%x for setting LMM_SIZE\n", stat);
        exit(1);
      }
      printf("EMAX8[%d].DEPTH=%d LMM_SIZE=%d\n", i, EMAX_DEPTH, LMM_SIZE);
    }
  }
  printf("EMAX8: NLANE=%d DEPTH=%d LMM_SIZE=%d\n", NLANE, EMAX_DEPTH, LMM_SIZE);
#endif
}

// void imemcpy_byte_by_byte(unsigned char * restrict dst, unsigned char * restrict src, size_t bytes) {
//     const size_t word_size = sizeof(unsigned long); // または sizeof(uintptr_t) などアーキテクチャのワードサイズ
//     unsigned char *d = dst;
//     const unsigned char *s = src;

//     // 0. 小さなコピーはバイト単位で処理 (閾値は調整可能)
//     if (bytes < word_size * 2) {
//         for (size_t i = 0; i < bytes; ++i) d[i] = s[i];
//         return;
//     }

//     // 1. dst がワード境界にアライメントされるまでバイト単位でコピー
//     size_t head_bytes = (word_size - ((uintptr_t)d % word_size)) % word_size;
//     if (head_bytes > bytes) head_bytes = bytes;
//     for (size_t i = 0; i < head_bytes; ++i) d[i] = s[i];
    
//     d += head_bytes;
//     s += head_bytes;
//     size_t remaining_bytes = bytes - head_bytes;

//     // 2. ワード単位でまとめてコピー (dst はアライメント済み)
//     unsigned long *d_word = (unsigned long *)d;
//     // src のアライメントに応じて処理を分岐するのが理想的だが、ここでは簡易化
//     // 多くのCPUでは、宛先がアライメントされていれば、ソースの非アライメント読み出しは可能(遅い可能性あり)
//     const unsigned long *s_word_potentially_unaligned = (const unsigned long *)s; 
                                                                        
//     size_t num_words = remaining_bytes / word_size;
//     for (size_t i = 0; i < num_words; ++i) {
//         // アライメントされていないsrcからの読み出しが安全か、性能に影響するかは環境依存
//         // 安全策を取るなら、memcpyのようにsrcのアライメントも考慮した複雑な分岐が必要
//         d_word[i] = s_word_potentially_unaligned[i]; 
//     }

//     size_t body_copied_bytes = num_words * word_size;
//     d += body_copied_bytes;
//     s += body_copied_bytes;

//     // 3. 残りの端数バイトをバイト単位でコピー
//     size_t tail_bytes = remaining_bytes - body_copied_bytes;
//     for (size_t i = 0; i < tail_bytes; ++i) d[i] = s[i];
// }
// 既存のimemcpy関数の前に新しい関数を追加
void imemcpy_byte_by_byte2(volatile Uchar *dst, volatile Uchar *src, int bytes,int lane) {

  // printf("imemcpy_byte_by_byte: dst=%16.16llx src=%16.16llx bytes=%d\n", (Ull)dst, (Ull)src, bytes);
  // printf("  dst alignment: %lld, src alignment: %lld\n", (Ull)dst & 0xF, (Ull)src & 0xF);
  
  // // Print first few addresses to analyze memory access patterns
  // if (bytes > 0) printf("  First byte: dst[0]=%16.16llx src[0]=%16.16llx value=%02x\n", 
  //                      (Ull)&dst[0], (Ull)&src[0], src[0]);
  // if (bytes > 16) printf("  16th byte: dst[16]=%16.16llx src[16]=%16.16llx value=%02x\n", 
  //                       (Ull)&dst[16], (Ull)&src[16], src[16]);
  // if (bytes > 32) printf("  32nd byte: dst[32]=%16.16llx src[32]=%16.16llx value=%02x\n", 
  //                       (Ull)&dst[32], (Ull)&src[32], src[32]);
  printf("LANE %d: imemcpy_byte_by_byte: dst=%16.16llx src=%16.16llx bytes=%d\n", lane, (Ull)dst, (Ull)src, bytes);
  for (int i = 0; i < bytes; i++) {
    // src[i] からの読み出しと dst[i] への書き込みは、
    // それぞれ volatile アクセスとして扱われます。
    dst[i] = src[i];
  }
  
  // // Print last byte to see end of memory region
  // if (bytes > 0) printf("  Last byte: dst[%d]=%16.16llx src[%d]=%16.16llx value=%02x\n", 
  //                      bytes-1, (Ull)&dst[bytes-1], bytes-1, (Ull)&src[bytes-1], src[bytes-1]);
}
// void imemcpy_byte_by_byte(Uchar *dst, Uchar *src, int bytes) {
void imemcpy_byte_by_byte(volatile Uchar *dst, volatile Uchar *src, int bytes) {

  // printf("imemcpy_byte_by_byte: dst=%16.16llx src=%16.16llx bytes=%d\n", (Ull)dst, (Ull)src, bytes);
  // printf("  dst alignment: %lld, src alignment: %lld\n", (Ull)dst & 0xF, (Ull)src & 0xF);
  
  // // Print first few addresses to analyze memory access patterns
  // if (bytes > 0) printf("  First byte: dst[0]=%16.16llx src[0]=%16.16llx value=%02x\n", 
  //                      (Ull)&dst[0], (Ull)&src[0], src[0]);
  // if (bytes > 16) printf("  16th byte: dst[16]=%16.16llx src[16]=%16.16llx value=%02x\n", 
  //                       (Ull)&dst[16], (Ull)&src[16], src[16]);
  // if (bytes > 32) printf("  32nd byte: dst[32]=%16.16llx src[32]=%16.16llx value=%02x\n", 
  //                       (Ull)&dst[32], (Ull)&src[32], src[32]);
  // printf("LANE %d: imemcpy_byte_by_byte: dst=%16.16llx src=%16.16llx bytes=%d\n", LANE, (Ull)dst, (Ull)src, bytes);
  for (int i = 0; i < bytes; i++) {
    // src[i] からの読み出しと dst[i] への書き込みは、
    // それぞれ volatile アクセスとして扱われます。
    dst[i] = src[i];
  }
}
//   // // Print last byte to see end of memory region
//   // if (bytes > 0) printf("  Last byte: dst[%d]=%16.16llx src[%d]=%16.16llx value=%02x\n", 
//   //                      bytes-1, (Ull)&dst[bytes-1], bytes-1, (Ull)&src[bytes-1], src[bytes-1]);
// }
void imemcpy(Uint *dst, Uint *src, int words)
{
  // cpy_count++;
  // if (words > 16) {
  //   cpy_count++;
  //   if (cpy_count > 200000) {
  //     printf("imemcpy called with words=%d (total calls: %d)\n", words, cpy_count);
  //   }
  // }

  union {
    Uint i[4];
    Ull  l[2];
    Dll  d;
  } buf;
  // printf("imemcpy,dst=%16.16llx src=%16.16llx words=%d\n", (Ull)dst, (Ull)src, words);
  // printf("imemcpy,dst=%16.16llx src=%16.16llx words=%d\n", (Ull)dst, (Ull)src, words);
  Uint loop, i;
  if (words >= 1 && ((Ull)dst & sizeof(Uint))) { /* 4B-access odd */
    *dst++ = *src++;
    words--;
    // printf("4B,dst=%16.16llx src=%16.16llx words=%d\n", (Ull)dst, (Ull)src, words);
  }
  if (words >= 2 && ((Ull)dst & sizeof(Ull))) { /* 8B-access odd */
    if ((Ull)src & sizeof(Uint)) {
      buf.i[0] = *src++;
      buf.i[1] = *src++;
      *(Ull*)dst = buf.l[0];
      // printf("8B_1,dst=%16.16llx src=%16.16llx words=%d\n", (Ull)dst, (Ull)src, words);
    }
    else {
      *(Ull*)dst = *(Ull*)src;
      src += sizeof(Ull)/sizeof(Uint);
      // printf("8B_2,dst=%16.16llx src=%16.16llx words=%d\n", (Ull)dst, (Ull)src, words);
    }
    dst += sizeof(Ull)/sizeof(Uint);
    words-=2;
    // printf("8B_3,dst=%16.16llx src=%16.16llx words=%d\n", (Ull)dst, (Ull)src, words);
  }

  if (loop = words/(sizeof(Dll)/sizeof(Uint))) {
    if ((Ull)src & sizeof(Uint)) {
      for(i=0; i<loop; i++) {
        buf.i[0] = *src++;
        buf.i[1] = *src++;
        buf.i[2] = *src++;
        buf.i[3] = *src++;
        *(Dll*)dst = buf.d;
        dst += sizeof(Dll)/sizeof(Uint);
        // printf("16B_1,dst=%16.16llx src=%16.16llx words=%d\n", (Ull)dst, (Ull)src, words);
      }
    }
    else if ((Ull)src & sizeof(Ull)) {
      for(i=0; i<loop; i++) {
        buf.l[0] = *(Ull*)src;src += sizeof(Ull)/sizeof(Uint);
        buf.l[1] = *(Ull*)src;src += sizeof(Ull)/sizeof(Uint);
        *(Dll*)dst = buf.d;
        dst += sizeof(Dll)/sizeof(Uint);
        // printf("16B_2,dst=%16.16llx src=%16.16llx words=%d\n", (Ull)dst, (Ull)src, words);
      }
    }
    else {
	  // monitor_time_start(0,IMAX_MEMCPY); /* Nakashima */
      // printf("loop=%d\n", loop);
      // printf("sizeof(Dll)=%d\n", sizeof(Dll));
      // printf("sizeof(Uint)=%d\n", sizeof(Uint));
      // printf("sizeof(Ull)=%d\n", sizeof(Ull));

      for(i=0; i<loop; i++) {
        *(Dll*)dst = *(Dll*)src;
        src += sizeof(Dll)/sizeof(Uint);
        dst += sizeof(Dll)/sizeof(Uint);
        // printf("16B_3,dst=%16.16llx src=%16.16llx words=%d\n", (Ull)dst, (Ull)src, words);
      }
      // monitor_time_end(0,IMAX_MEMCPY); /* Nakashima */
    }
    words -= loop*(sizeof(Dll)/sizeof(Uint));
    // printf("16B_4,dst=%16.16llx src=%16.16llx words=%d\n", (Ull)dst, (Ull)src, words);
  }

  if (words >= 2) { /* 8B-access */
    if ((Ull)src & sizeof(Uint)) {
      buf.i[0] = *src++;
      buf.i[1] = *src++;
      *(Ull*)dst = buf.l[0];
    }
    else {
      *(Ull*)dst = *(Ull*)src;
      src += sizeof(Ull)/sizeof(Uint);
    }
    dst += sizeof(Ull)/sizeof(Uint);
    words-=2;
    // printf("8B_1,dst=%16.16llx src=%16.16llx words=%d\n", (Ull)dst, (Ull)src, words);
  }
  if (words >= 1) { /* 4B-access */
    *dst++ = *src++;
    words--;
    // printf("4B_1,dst=%16.16llx src=%16.16llx words=%d\n", (Ull)dst, (Ull)src, words);
  }
}

// DMA高速化: アライメント済みかつ大きなブロック用の最適化版
// プリフェッチとループ展開を組み合わせた高速パス
void __attribute__((optimize("O3"))) imemcpy_fast_aligned(Dll *dst_aligned, Dll *src_aligned, int words)
{
  // 事前条件: dst_aligned と src_aligned は 16バイトアライメント済み
  // words は 4の倍数（16バイト単位）
  int loop = words / (sizeof(Dll)/sizeof(Uint));
  
  // 大きなブロックはループ展開 + プリフェッチ
  if (loop >= 32) {
    int unrolled_loops = loop / 8;
    int remainder = loop % 8;
    
    for (int i = 0; i < unrolled_loops; i++) {
      // 8ループ先をプリフェッチ
      __builtin_prefetch(&src_aligned[i*8+8], 0, 3);  // 読み取り、temporal locality
      __builtin_prefetch(&dst_aligned[i*8+8], 1, 3);  // 書き込み、temporal locality
      
      // ループ展開: 8回分を一度に処理
      dst_aligned[i*8+0] = src_aligned[i*8+0];
      dst_aligned[i*8+1] = src_aligned[i*8+1];
      dst_aligned[i*8+2] = src_aligned[i*8+2];
      dst_aligned[i*8+3] = src_aligned[i*8+3];
      dst_aligned[i*8+4] = src_aligned[i*8+4];
      dst_aligned[i*8+5] = src_aligned[i*8+5];
      dst_aligned[i*8+6] = src_aligned[i*8+6];
      dst_aligned[i*8+7] = src_aligned[i*8+7];
    }
    
    // 残りを処理
    Dll *dst_rem = &dst_aligned[unrolled_loops*8];
    Dll *src_rem = &src_aligned[unrolled_loops*8];
    for (int i = 0; i < remainder; i++) {
      dst_rem[i] = src_rem[i];
    }
  } else {
    // 小さなブロックは通常のループ
    for (int i = 0; i < loop; i++) {
      dst_aligned[i] = src_aligned[i];
    }
  }
}

// xmax_bzero の最適化版: 大きなブロックは一括処理
void __attribute__((optimize("O3"))) xmax_bzero_fast_large(Uint *dst, int words)
{
  // 大きなブロック（64ワード = 256バイト以上）はmemsetを使用
  if (words >= 64) {
    memset(dst, 0, words * sizeof(Uint));
    return;
  }
  // 小さいブロックは従来の方法
  xmax_bzero(dst, words);
}


void __attribute__((optimize("O3"))) xmax_bzero(Uint *dst, int words)
{
  /* +----+-m-----+ */
  /* |3x3 |       | */
  /* |    |    src| */
  /* +----+       | */
  /* |       +----+ */
  /* |       |    | */
  /* |       | 3x3| */
  /* +-------+----+ */
  Uint loop, i;
  if (words >= 1 && ((Ull)dst & sizeof(Uint))) { /* 4B-access odd */
    *dst++ = 0;
    words--;
  }
  if (words >= 2 && ((Ull)dst & sizeof(Ull))) { /* 8B-access odd */
    *(Ull*)dst = 0;
    dst += sizeof(Ull)/sizeof(Uint);
    words-=2;
  }

  if (loop = words/(sizeof(Dll)/sizeof(Uint))) {
    for(i=0; i<loop; i++) {
#if __AARCH64EL__ == 1
      *((Dll*)dst) = 0;
#else
      ((Dll*)dst)->u[0] = 0;
      ((Dll*)dst)->u[1] = 0;
#endif
      dst += sizeof(Dll)/sizeof(Uint);
    }
    words -= loop*(sizeof(Dll)/sizeof(Uint));
  }

  if (words >= 2) { /* 8B-access */
    *(Ull*)dst = 0;
    dst += sizeof(Ull)/sizeof(Uint);
      words-=2;
    }
  if (words >= 1) { /* 4B-access */
    *dst++ = 0;
    words--;
  }
}

void __attribute__((optimize("O3"))) xmax_cpyin(int order, Uint *dst, int *imo, Uint *src, int batch, int ic, int im, int m, int k)
{
  /* order 0: dst[batch][ic][im*im]  <- src[batch][ic][im*im] */
  /* order 1: dst[ic][oc][im*im]     <- src[oc][ic][im*im] */
  /* order 2: dst[ic][im][batch][im] <- src[batch][ic][im*im] */
  /* order 3: dst[im][m]             <- src[im][m]            */

  switch (order) {
  case 0:
    /* num=batch+ichan                            */
    /* imi?��????0??????imo??????            */
    /* k=3,(IM==M)             k=2,(IM==M)        */
    /* +-------+imo-------+    +-----+--imo----+  */
    /* | 0 0 0 |       dst|    | 0 0 |      dst|  */
    /* |  +----+im=m---+  |    |  +--+--im=m---+  */
    /* | 0|3x3 |       |  |    | 0|  |         |  */
    /* | 0|    |    src|  |    +--+--+      src|  */
    /* +--+----+       |  |    |  |            |  */
    /* |  |       +----+--+    |  |            |  */
    /* |  |       |    |0 |    |  |            |  */
    /* |  |       | 3x3|0 |    |  |            |  */
    /* |  +-------+----+  |    +--+------------+  */
    /* |          | 0 0 0 |                       */
    /* +----------+-------+                       */

    /* imi??imo?????????????????                                 */
    /* k=3,(IM-k)/1+1==M       k=2,(IM-k)/1+1==M    k=1,(IM==M)     */
    /* +-------+im--------+    +-----+--im-----+                    */
    /* | x x x |       dst|    | x x |      dst|                    */
    /* |  +----+-m-----+  |    |  +--+---m-----+    +--+--im=m---+  */
    /* | x|3x3 |       |  |    | x|  |         |    |  |         |  */
    /* | x|    |    src|  |    +--+--+      src|    +--+      src|  */
    /* +--+----+       |  |    |  |            |    |            |  */
    /* |  |       +----+--+    |  |            |    |            |  */
    /* |  |       |    |x |    |  |            |    |         +--+  */
    /* |  |       | 3x3|x |    |  |            |    |         |  |  */
    /* |  +-------+----+  |    +--+------------+    +---------+--+  */
    /* |          | x x x |                                         */
    /* +----------+-------+                                         */
    /* EMAX for large IM/M                                   *//*         burst_exe 6*6    ||         burst_exe 6*6    */
    /*     +-----+  +----+-+----+---------+    +-----------+ *//* 7*8... | 7*8... | 7*8... || 7*8... | 7*8... | 7*8... */
    /* unit|2    |  |7*7 | |7*7 |*IC  *100|    |2          | *//*-- -- --                  ||-- -- --                  *//* LMM=7*8*4B */
    /*  |  |*    |  |ch0 | |ch1 |         | -> |*          | *//*         -- -- --         ||         -- -- --         *//*    =244B   */
    /*  V  |2    |  +----+ +----+         |    |2          | *//*                  -- -- --||                  -- -- --*/
    /*     |*ich |  |loop=RMGRP(6)*M(6)   |    |*ich       | *//* stg2     stg4     stg6   || stg2     stg4     stg6   *//* out=6*6*4B*4och */
    /*     +-och-+  +---------------------+    +6*6*och----+ *//* img0     img0     img0   || img1     img1     img1   *//*    =576B        */
    /*        32 ... lmf+lmx???DMA            |    32/4   | *//* ch0      ch1      ch2    || ch0      ch1      ch2    */
    /*                                         +-----------+ */
    if (im == m && 1<k) {
      int n, i, w = im+k-1;
      for (n=0; n<batch*ic; n++,dst+=w*w,src+=im*im) {
        for (i=0; i<k/2; i++)
          xmax_bzero(dst+i*w, w);
        for (i=k/2; i<=im+k/2-1; i++) {
          xmax_bzero (dst+i*w,               (k/2) );
          imemcpy(dst+i*w+(k/2),   src+(i-k/2)*im, im);
          if (k-1-(k/2)) xmax_bzero (dst+i*w+(k/2)+im, k-1-(k/2));
        }
        for (i=im+k/2; i<w; i++)
          xmax_bzero(dst+i*w, w);
      }
      *imo = w;
    }
    else {
      imemcpy(dst, src, batch*ic*im*im);
      *imo = im;
    }
    break;
  case 1:  /* dst[ic][oc][im*im] <- src[oc][ic][im*im] */
    {
      int i, o;
      for (o=0; o<batch; o++) {
        for (i=0; i<ic; i++)
          imemcpy(dst+(i*batch+o)*im*im, src+(o*ic+i)*im*im, im*im);
      }
      *imo = im;
    }
    break;
  case 2:
    /* EMAX for small IM/M                                   */
    /*     +-----+  +---------------------+    +-----------+ *//*         burst_exe 6*100  ||         burst_exe 6*100  *//* 100??????1??(7*700pix)??(7*100??7??) */
    /* unit|     |  |+----PAD----+        |    |           | *//* 7*8*100| 7*8*100| 7*8*100|| 7*8*100| 7*8*100| 7*8*100*//* ?????7*7?????????100?????     */
    /*  |  |2    |  ||7*7 | |7*7 |*100 *IC| -> |2          | *//*-- -- --                    -- -- --                  *//* LMM=7*8*4B*100 LMMstg2-7??load       */
    /*  |  |*    |  ||im0 | |im1 |        |    |*          | *//* top=0   -- -- --            top=1   -- -- --         *//*    =22400B(RMGRP=7??2???????)<32KB  */
    /*  V  |2    |  |+----+ +----+        |    |2          | *//*                  -- -- --                    -- -- --*/
    /*     |*ich |  |loop=M(6)*BATCH(100) |    |*ich       | *//* stg2     stg4     stg6   || stg2     stg4     stg6   *//* out=6*4B*100*4och */
    /*     +-och-+  +---------------------+    +6*100*och--+ *//* img0-99  img0-99  img0-99|| img0-99  img0-99  img0-99*//*    =9600B         */
    /*        32 ... lmf+lmx???DMA            |      32/4 | *//* ch0      ch1      ch2    || ch0      ch1      ch2    */
    /*                                         +-----------+ */
    if (im == m && 1<k) {
      int n1, n0, i, w = im+k-1;
      for (n1=0; n1<batch; n1++) {           /* src-data?? */
        for (n0=0; n0<ic; n0++,src+=im*im) { /* src-data?? */
          int ofs  = (n0*w*batch+n1)*w;      /* ???img??1?????,ch????? */
          int dist =  batch*w;               /* ???img??1?????,???????????? */
          for (i=0; i<k/2; i++)
            xmax_bzero(dst+ofs+i*dist, w);
          for (i=k/2; i<=im+k/2-1; i++) {
            xmax_bzero (dst+ofs+i*dist,               (k/2) );
            imemcpy(dst+ofs+i*dist+(k/2),   src+(i-k/2)*im, im);
            if (k-1-(k/2)) xmax_bzero (dst+ofs+i*dist+(k/2)+im, k-1-(k/2));
          }
          for (i=im+k/2; i<w; i++)
            xmax_bzero(dst+ofs+i*dist, w);
        }
      }
      *imo = w;
    }
    else {
      int n1, n0, i;
      for (n1=0; n1<batch; n1++) {           /* src-data?? */
        for (n0=0; n0<ic; n0++,src+=im*im) { /* src-data?? */
          int ofs  = (n0*im*batch+n1)*im;
          int dist =  batch*im;
          for (i=0; i<im; i++)
            imemcpy(dst+ofs+i*dist, src+i*im, im);
        }
      }
      *imo = im;
    }
    break;
 case 3:
    // printf("xmax_cpyin case 3: imemcpy words = %d\n", im*m);
    
    // Experiment: Use a fixed data size for testing
    // const int FIXED_DATA_WORDS = 6912; // Example: 128KB in words (27 * 1024 / 4)
    
    // Define a flag to switch between normal imemcpy and byte-by-byte version
    // #define BYTE_BY_BYTE_TEST 1
    // #define MEMCOPY 1
    
    // Ull byte_size = (Ull)FIXED_DATA_WORDS * sizeof(Uint);
    Ull byte_size = (Ull)(im*m) * sizeof(Uint);

    // DMA高速化: アライメント済みかつ大きなブロックは最適化版を使用
    const Ull dst_aligned_16 = ((Ull)dst & 0xF) == 0;
    const Ull src_aligned_16 = ((Ull)src & 0xF) == 0;
    const int words_aligned_4 = (im*m % 4) == 0;
    
    if (dst_aligned_16 && src_aligned_16 && words_aligned_4 && im*m >= 32) {
      // 高速パス: 16バイトアライメント済み、かつ4ワードの倍数、かつ大きいブロック
      imemcpy_fast_aligned((Dll*)dst, (Dll*)src, im*m);
    } else {
      // 通常パス: アライメントが合わないか小さいブロック
      #if BYTE_BY_BYTE_TEST
      // Use byte-by-byte copy to test alignment theory
      imemcpy_byte_by_byte((Uchar*)dst, (Uchar*)src, im*m*sizeof(Uint));
      #elif MEMCOPY
      memcpy(dst, src, byte_size); // wordsをバイト数に変換
      #else
      // Use normal optimized copy
      imemcpy(dst, src, im*m);
      // コピーできたかチェック
      #endif
    }

    // if (byte_size < 64 * 1024) {
     
    // } else if ( byte_size > 64 * 1024&&byte_size < 256 * 1024) {
    //   monitor_time_start(0, IMAX_MEMCPY_B);
    // } else {
    //   monitor_time_end(0, IMAX_MEMCPY_C);
    // }
    
    // if (byte_size < 64 * 1024) {
      
    // } else if (byte_size > 64 * 1024&&byte_size < 256 * 1024) {
    //   monitor_time_end(0, IMAX_MEMCPY_B);
    // } else {
    //   monitor_time_end(0, IMAX_MEMCPY_C);
    // }
    

    *imo = im; 
    // monitor_time_start(0, IMAX_MEMCPY_A);
    // // // DMAバッファに送ったデータを別のDMAバッファにコピー
    // // Uint* dummy_dst = i_m0A[0];
    // // if (dummy_dst == NULL) {
    // //   printf("Failed to allocate dummy destination buffer\n");
    // //   return;
    // // }
    // // memcpy(dummy_dst, src, byte_size);
    // monitor_time_end(0, IMAX_MEMCPY_A);
    // dst と dummy_dst を比較 上位16byteのデータを表示
    // Keep original im value for downstream logic if needed
     // Create dummy destination buffer
    //  Uint* dummy_dst = (Uint*)malloc(byte_size);
    //  if (dummy_dst == NULL) {
    //      printf("Failed to allocate dummy destination buffer\n");
    //      return;
    //  }
     
    //  monitor_time_start(0, IMAX_MEMCPY_A);
    //  memcpy(dummy_dst, src,byte_size);
    //  monitor_time_end(0, IMAX_MEMCPY_A);
    // //  printf("dummy_dst=%16.16llx\n", (Ull)dummy_dst);
    // //  srcとdummy_dstを比較
    // if (memcmp(src, dummy_dst, byte_size) != 0) {
    //   printf("Error: src and dummy_dst are different\n");
    // }
    //  free(dummy_dst);

    break;
  }
}

void __attribute__((optimize("O3"))) xmax_cpyout(int order, Uint *dst, int batch, int oc, Uint *src, int m, int n, int oc4)
{
  /* order 0: dst[batch][oc][m*n] <- src[batch][oc4][m*n]  */
  /* order 1: dst[batch][oc][m*n] <- src[oc4][m][batch][n] */
  /* order 2: dst[m][n]           <- src[m][oc4=(n+3)&~3]  */
  /* order 3: dst[n=5][batch][m=5120/batch]<- src[batch][m=5120/batch][n=5] */
  /* order 4: dst[oc:stride*m][n=16] <- src[m][n=16] */
  int k, k2, k1, k0;

  switch (order) {
  case 0:
    /* +-dst--------------+    +-imo--------------+ */
    /* | OC | OC | OC |   | <- | OC4   | OC4   |  | */
    /* +------------------+    +------------------+ */
    for (k=0; k<batch; k++,dst+=oc*m*n,src+=oc4*m*n)
      imemcpy(dst, src, oc*m*n);
    break;
  case 1:
    for (k2=0; k2<batch; k2++) {
      for (k1=0; k1<oc; k1++) {
        for (k0=0; k0<m; k0++,dst+=n)
          imemcpy(dst, src+((k1*m+k0)*batch+k2)*n, n);
      }
    }
    break;
  case 2:
    if (n == oc4)
      imemcpy(dst, src, m*n);
    else {
      for (k=0; k<m; k++,dst+=n,src+=oc4)
        imemcpy(dst, src, n);
    }
    break;
  case 3:
    /* <-batch->                                                      */
    /* <-m->                              n   n   n          n        */
    /* +-dst-----------------------+    +-src------------------+----+ */
    /* |  5120  |  5120  ||  5120  | <- | 5 | 5 | 5 |......| 5 |    | */
    /* +---ch0------ch1---0---ch4--+    +0(ir0)--ir1-ir0-1(ir1)+----+ */
    /*               n                  <----m---->                   */
    /*                                  <-----------batch-----------> */
    for (k1=0; k1<n; k1++) { /* 5 */
      for (k0=0; k0<m; k0++) /* 5120/NTHREAD */
	dst[k1*batch+k0]=src[k1+k0*n];
    }
    break;
  case 4:
    /* <----oc----->                                                       */
    /* <n><n>..                         n           n          n      n    */
    /* +-dst-------------------+    +-src-------+-----------+------+------ */
    /* | 16xN |----| 16xN |----| <- | 16xN/IMAP | 16xN/IMAP |...   |       */
    /* +--nb1=4096-+--nb1=4096-+    +----m0-----+-----m1----+--m0--+--m1-- */
    /* <--m0-->    <--m1-->         <---------IMAP#0-------><---IMAP#1---> */

    /* DST_COL_TOP, 1, nb1/sizeof(int), i_m0C[LANE], IR1_LOOPS, DST_COL_LENdIMAP, IMAP */
    /* *dst,    batch, oc,              *src,        m,         n,                oc4  */
    for (k1=0; k1<m; k1++) { /* 2 */
      for (k0=0; k0<oc4; k0++) { /* IMAP */
	imemcpy(dst+k1*oc+k0*n, src+k1*n+k0*m*n, n);
      }
    }
    break;
  }
  // // dstの先頭10個をダンプ
  // printf("[xmax_cpyout] dst dump (first 10): ");
  // for (int i = 0; i < 10; ++i) {
  //   printf("%08x ", dst[i]);
  // }
  // printf("\n");
  // dstの先頭100個でNaNチェック
  // for (int i = 0; i < 100; ++i) {
  //   float f = ((float*)dst)[i];
  //   if (isnan(f)) {
  //     printf("[xmax_cpyout] NaN detected at dst[%d]: %e\n", i, f);
  //   }
  // }
}

void imax_compute_forward_mul_mat_one_chunk_f32(struct th_inference_args *args)
{
  int                                THREAD       = args->thid; /* < NTHREAD vsim.cpp NTHREAD=2                  */
  int                                LANE         = args->thid; /* < NLANE   emax7.h  init_xmax(){NLANE=NTHREAD} */
  struct ggml_tensor *               dst          = args->dst;
  const int64_t                      num_rows_per_vec_dot = args->num_rows_per_vec_dot;
  const int64_t                      ir0_start    = args->ir0_start;
  const int64_t                      ir0_end      = args->ir0_end;
  const int64_t                      ir1_start    = args->ir1_start;
  const int64_t                      ir1_end      = args->ir1_end;
  const struct ggml_tensor *         src0         = args->src0;
  const struct ggml_tensor *         src1         = args->src1;
  const enum ggml_type               type         = args->type; /* 0:F32 1:F16 8:Q8_0 10:Q2_K 11:Q3_K 14:Q6_K */
  const bool                         src1_cont    = args->src1_cont;
  ggml_vec_dot_t const               vec_dot      = args->vec_dot;
  enum ggml_type const               vec_dot_type = args->vec_dot_type;
  const void *                       wdata        = args->wdata;
  const size_t                       row_size     = args->row_size;
  const int64_t                      r2           = args->r2;
  const int64_t                      r3           = args->r3;
  const int64_t                      blck_0       = args->blck_0;
  const int64_t                      blck_1       = args->blck_1;
  const size_t                       src1_col_stride = args->src1_col_stride;
  int   i;
  float tmp[32];
  GGML_TENSOR_BINARY_OP_LOCALS
  int       n  = ne00;
  // printf("imax_compute_forward_mul_mat_one_chunk_f32\n");
  // printf("after src0\n");
  // print_ggml_tensor(src0, 10);
  // printf("after src1\n");
  // print_ggml_tensor(src1, 10);
  if (1) { /* check LMM_SIZE, and start ARM if NG */
    monitor_time_start(THREAD, IMAX_COMPUTE_FORWARD_MUL_MAT_ONE_CHUNK_F32_ARM); /* Nakashima */
    for (int64_t iir1 = ir1_start; iir1 < ir1_end; iir1 += blck_1) { /* weight top loop */
      for (int64_t iir0 = ir0_start; iir0 < ir0_end; iir0 += blck_0) { /* sdata top loop */
	for (int64_t ir1 = iir1; ir1 < iir1 + blck_1 && ir1 < ir1_end; ir1 += num_rows_per_vec_dot) { /* weight sub loop */
	  const int64_t i13 = (ir1 / (ne12 * ne1));
	  const int64_t i12 = (ir1 - i13 * ne12 * ne1) / ne1;
	  const int64_t i11 = (ir1 - i13 * ne12 * ne1 - i12 * ne1);
          const int64_t i03 = i13 / r3;
          const int64_t i02 = i12 / r2;
	  const int64_t i1 = i11;
	  const int64_t i2 = i12;
	  const int64_t i3 = i13;

	  const char * src0_row = (const char*)src0->data + (0 + i02 * nb02 + i03 * nb03);
	  const char * src1_col = (const char*)wdata + (src1_cont || src1->type != vec_dot_type ? (i11 + i12 * ne11 + i13 * ne12 * ne11) * row_size
	                                                                                        : (i11 * nb11 + i12 * nb12 + i13 * nb13));
	  float * dst_col = (float*)((char*)dst->data + (i1 * nb1 + i2 * nb2 + i3 * nb3));

        //printf("src0_row=%16.16llx ir0=%16.16llx-%16.16llx (step=%16.16llx) ne00=%08.08x nb01=%08.08x\n", src0_row, iir0, iir0 + blck_0, num_rows_per_vec_dot, (int)ne00, (int)nb01);
	  for (int64_t ir0 = iir0; ir0 < iir0 + blck_0 && ir0 < ir0_end; ir0 += num_rows_per_vec_dot) { /* ne00=4096(0x1000) 4096/32*34=0x1100??��?,0x1100B??????????? */
	    vec_dot(ne00, &tmp[ir0 - iir0], (num_rows_per_vec_dot > 1 ? 16 : 0), src0_row + ir0 * nb01, (num_rows_per_vec_dot > 1 ? nb01 : 0), src1_col, (num_rows_per_vec_dot > 1 ? src1_col_stride : 0), num_rows_per_vec_dot);

	//  float sumf = 0.0;
	//  for (int i = 0; i < n; ++i)
	//    sumf += (float)(GGML_FP16_TO_FP32(((ggml_fp16_t *)(src0_row + ir0 * nb01))[i])*GGML_FP16_TO_FP32(((ggml_fp16_t *)src1_col)[i]));
	//  tmp[ir0 - iir0] = sumf;
	    // printf("tmp[ir0 - iir0]=%f\n", tmp[ir0 - iir0]);
	  }
	  monitor_time_start(THREAD, ARM_MEMCPY); /* Nakashima */
	  for (int cn = 0; cn < num_rows_per_vec_dot; ++cn) /* num_rows_per_vec_dot=1 */
	    memcpy(&dst_col[iir0 + cn * nb1 / nb0], tmp + (cn * 16), (MIN(iir0 + blck_0, ir0_end) - iir0) * sizeof(float));
	  monitor_time_end(THREAD, ARM_MEMCPY); /* Nakashima */
	}
      }
    }
    monitor_time_end(THREAD, IMAX_COMPUTE_FORWARD_MUL_MAT_ONE_CHUNK_F32_ARM); /* Nakashima */
  }
}

void imax_compute_forward_mul_mat_one_chunk_f16(struct th_inference_args *args)
{
  int                                THREAD       = args->thid; /* < NTHREAD vsim.cpp NTHREAD=2                  */
  int                                LANE         = args->thid; /* < NLANE   emax7.h  init_xmax(){NLANE=NTHREAD} */
  struct ggml_tensor *               dst          = args->dst;
  const int64_t                      num_rows_per_vec_dot = args->num_rows_per_vec_dot;
  const int64_t                      ir0_start    = args->ir0_start;
  const int64_t                      ir0_end      = args->ir0_end;
  const int64_t                      ir1_start    = args->ir1_start;
  const int64_t                      ir1_end      = args->ir1_end;
  const struct ggml_tensor *         src0         = args->src0;
  const struct ggml_tensor *         src1         = args->src1;
  const enum ggml_type               type         = args->type; /* 0:F32 1:F16 8:Q8_0 10:Q2_K 11:Q3_K 14:Q6_K */
  const bool                         src1_cont    = args->src1_cont;
  ggml_vec_dot_t const               vec_dot      = args->vec_dot;
  enum ggml_type const               vec_dot_type = args->vec_dot_type;
  const void *                       wdata        = args->wdata;
  const size_t                       row_size     = args->row_size;
  const int64_t                      r2           = args->r2;
  const int64_t                      r3           = args->r3;
  const int64_t                      blck_0       = args->blck_0;
  const int64_t                      blck_1       = args->blck_1;
  const size_t                       src1_col_stride = args->src1_col_stride;
  int   i;
  float tmp[32];
  GGML_TENSOR_BINARY_OP_LOCALS
  static int ne00_count[1000000] = {0}; // 適当な最大値を設定（必要に応じて調整）
  int       n  = ne00;
  const int nb = n / 1; //n/ggml_blck_size(src0->type)


    ne00_count[ne00]++;
    // 必要なら頻度を出力
    // printf("f16\n");
    
  
  

  Ull   IIR1_LOOPS         = (ir1_end-ir1_start)/blck_1;                         /* src1 の範囲 (ir1_end - ir1_start) の中に、サイズ blck_1 のブロックが完全に収まる回数を計                  */
  Ull   IIR0_LOOPS         = (ir0_end-ir0_start)/blck_0;                         /* ??iir0-loop???                  */
  Ull   IR1_LOOPS          = MIN(ir1_start+blck_1,ir1_end)-ir1_start;  
  // // printf("IIR0_LOOPS = %lld\n", IIR0_LOOPS);
  if (ir1_start+blck_1<ir1_end){
    IR1_LOOPS = ir1_end-ir1_start;
    // printf("arm--------------------------------\n");
    // printf("ir1_end=%lld\n", ir1_end);
    // printf("ir1_start=%lld\n", ir1_start);
    // printf("IR1_LOOPS = %lld\n", IR1_LOOPS);
    
    }
 
  Ull   SRC0_ROW_LEN       = ne00 * blck_0 * IIR0_LOOPS;/* ??iir0-loop????                */
  Ull   SRC1_COL_LEN       = ne00;                  /* ??ir1-loop????                 */
  Ull   SRC1_COL_LEN_TOTAL = SRC1_COL_LEN*IR1_LOOPS;                             /* ??ir1-loop????                 */
  Ull   DST_COL_LEN        = blck_0*IIR0_LOOPS;                                  /* ??ir1-loop????????(nb1-byte*iir0-loop) */
  Ull   DST_COL_LEN_TOTAL  = DST_COL_LEN*IR1_LOOPS;     

  // Ull   SRC0_ROW_BYTES       = ne00 * sizeof(ggml_fp16_t) * (ir0_end-ir0_start);/* ??iir0-loop????                */
  
  // if (SRC0_ROW_LEN > 512/sizeof(ggml_fp16_t)  || ((ir0_end - ir0_start) % blck_0) || num_rows_per_vec_dot !=1 ||counter_imax_operations > 600  || IR1_LOOPS!=16){ /* check LMM_SIZE, and start ARM if NG */

// int verbose_dot_product_debug = 1;
// #define DEBUG_DOT_PRODUCT 


  // static int first_call = 1;
  // if (first_call) {
  // // #ifdef DEBUG_DOT_PRODUCT
  // if (counter_imax_operations < 4800) {
  //     printf("\n\n[T%d] TENSOR LAYOUT INFO (first call)\n", THREAD);
  //     printf("  src0->type = %2d, shape = [%5lld, %5lld, %5lld, %5lld], strides (bytes) = [%5zu, %5zu, %5zu, %5zu]\n",
  //            src0->type, ne00, ne01, ne02, ne03, nb00, nb01, nb02, nb03);
  //     printf("  src1->type = %2d, shape = [%5lld, %5lld, %5lld, %5lld], strides (bytes) = [%5zu, %5zu, %5zu, %5zu]\n",
  //            src1->type, ne10, ne11, ne12, ne13, nb10, nb11, nb12, nb13);
  //     printf("  dst->type  = %2d, shape = [%5lld, %5lld, %5lld, %5lld], strides (bytes) = [%5zu, %5zu, %5zu, %5zu]\n",
  //            dst->type, ne0, ne1, ne2, ne3, nb0, nb1, nb2, nb3);
  //              printf("  K (ne00) = %lld, src1_cont = %d, row_size = %zu bytes, blck_0=%lld, blck_1=%lld\n", (long long)ne00, src1_cont, row_size, blck_0, blck_1);
  // }
    
      // first_call = 0;}
  // // #endif
  // if ((counter_imax_operations < 10000 || counter_imax_operations > 20000) || ((ir0_end - ir0_start) % blck_0) || num_rows_per_vec_dot != 1) { /* check LMM_SIZE, and start ARM if NG */
  
    // if (ne00 == 1500) count1500++;printf("count1500=%d\n", count1500);
counter_imax_operations++;
// const size_t src0_bytes = ne00 * (ir0_end - ir0_start) * sizeof(ggml_fp16_t);
// const size_t src1_bytes = ne00 * (ir1_end - ir1_start) * sizeof(ggml_fp16_t);
// const int64_t dst_size = (ir1_end - ir1_start) * (ir0_end - ir0_start) * sizeof(float);
// Ull TOTAL_SIZE2 = src0_bytes + src1_bytes + dst_size;
#define IMAX_DEBUG 
int imax_run_count = 10000;
const int64_t i13_start = ir1_start / (ne12 * ne1);
const int64_t i13_end   = (ir1_end - 1) / (ne12 * ne1);

const int64_t i12_start = (ir1_start - i13_start * ne12 * ne1) / ne1;
const int64_t i12_end   = ((ir1_end - 1) - i13_end * ne12 * ne1) / ne1;

// チャンクが次元境界をまたぐ（= i12かi13の値がチャンク内で変わる可能性がある）かチェック
const bool cross_boundary = ( i13_start != i13_end);
// if (counter_imax_operations == imax_run_count) {
//   printf("src0->data=%016llx\n", src0->data);
//     // Ull SRC0_ROW_TOP = (Ull)((const char*)src0->data + (0 + i02_top * nb02 + i03_top * nb03) + ir0_start * nb01);
//     // printf("SRC0_ROW_TOP [128bit]: ");
//     // for (int i = 0; i < 16; ++i) {
//     //     printf("%02x ", ((unsigned char*)SRC0_ROW_TOP)[i]);
//       printf("\n");
//     }
  
if (ne00 % 32 != 0) {
    printf("[IMAX_DEBUG] Warning: ne00 (%lld) is not a multiple of 32\n", (long long)ne00);
}

// if(1){64
 Ull TOTAL_SIZE = SRC0_ROW_LEN*sizeof(ggml_fp16_t) + SRC1_COL_LEN_TOTAL*sizeof(ggml_fp16_t) + DST_COL_LEN_TOTAL*sizeof(float);
// printf("ne00=%lld\n", (long long)ne00);
//  printf("TOTAL_SIZE=%lld\n", TOTAL_SIZE);
// printf("counter_imax_operations=%d\n", counter_imax_operations);
#if defined(IMAX_DEBUG)

// if(TOTAL_SIZE >512*1024  || ((ir0_end - ir0_start) % blck_0) || num_rows_per_vec_dot != 1) {
if(1){
#else
    if (1) {
#endif
// if(SRC0_ROW_LEN > 1024*100/sizeof(ggml_fp16_t) || ((ir0_end - ir0_start) % blck_0) || num_rows_per_vec_dot != 1 || IR1_LOOPS!=16 || counter_imax_operations < 70000 || counter_imax_operations > 80000 || (ne00 % 4 != 0))  { /* check LMM_SIZE, and start ARM if NG */

    monitor_time_start(THREAD, IMAX_COMPUTE_FORWARD_MUL_MAT_ONE_CHUNK_F16_ARM); /* Nakashima */
   
    // =================================================================================
    // ARM PATH DEBUGGING
    // =================================================================================
    #ifdef DEBUG_DOT_PRODUCT
    printf("\n\n>>> [T%d] ENTERING ARM PATH (ir0=[%lld,%lld), ir1=[%lld,%lld)) <<<\n", THREAD, ir0_start, ir0_end, ir1_start, ir1_end);
    #endif
   
   
  //   IIR1_LOOPS，だいたい１回で終わる， += blck_16なので実質sub loopが担う
    for (int64_t iir1 = ir1_start; iir1 < ir1_end; iir1 += blck_1) { /* weight top loop  */
// だいたい１回で終わる， += blck_16なので実質

      for (int64_t iir0 = ir0_start; iir0 < ir0_end; iir0 += blck_0) { /* sdata top loop */
	for (int64_t ir1 = iir1; ir1 < iir1 + blck_1 && ir1 < ir1_end; ir1 += num_rows_per_vec_dot) { /* weight sub loop */
	          #ifdef DEBUG_DOT_PRODUCT
          printf("\n--- [ARM_LOOP] ir1=%-4lld ---\n", ir1);
    #endif

    const int64_t i13 = (ir1 / (ne12 * ne1));
	  const int64_t i12 = (ir1 - i13 * ne12 * ne1) / ne1;
	  const int64_t i11 = (ir1 - i13 * ne12 * ne1 - i12 * ne1);
          const int64_t i03 = i13 / r3;
          const int64_t i02 = i12 / r2;
	  const int64_t i1 = i11;
	  const int64_t i2 = i12;
	  const int64_t i3 = i13;
	  const char * src0_row = (const char*)src0->data + (0 + i02 * nb02 + i03 * nb03);
	  const char * src1_col = (const char*)wdata + (src1_cont || src1->type != vec_dot_type ? (i11 + i12 * ne11 + i13 * ne12 * ne11) * row_size
	                                                                                        : (i11 * nb11 + i12 * nb12 + i13 * nb13));
	  float * dst_col = (float*)((char*)dst->data + (i1 * nb1 + i2 * nb2 + i3 * nb3));
    
    // if (counter_imax_operations == imax_run_count) {
    //   printf("src0_row[0..7]= ");
    //   for (int j = 0; j < 8; ++j) {
    //     printf("%04x ", ((const uint16_t *)src0_row)[j]);
    //   }
    //   printf("\n");
    // }
    for (int64_t ir0 = iir0; ir0 < iir0 + blck_0 && ir0 < ir0_end; ir0 += num_rows_per_vec_dot) { /* ne00=4096(0x1000) 4096/32*34=0x1100??��?,0x1100B??????????? */

// #ifdef IMAX_DEBUG 
      vec_dot(ne00, &tmp[ir0 - iir0], (num_rows_per_vec_dot > 1 ? 16 : 0), src0_row + ir0 * nb01, (num_rows_per_vec_dot > 1 ? nb01 : 0), src1_col, (num_rows_per_vec_dot > 1 ? src1_col_stride : 0), num_rows_per_vec_dot);
  // vec_dot の代わりに手動で計算してデバッグ情報を出力
// #else 
	//  float sumf = 0.0;
  //  if (counter_imax_operations == imax_run_count) {
	//  for (int i = 0; i < n; ++i){
  //   // 16進数のデータを表示
  //   printf("src0_row[%d]=0x%04x, src1_col[%d]=0x%04x\n", i, ((const uint16_t *)((src0_row + ir0 * nb01)))[i], i, ((const uint16_t *)(src1_col))[i]);
	//    float src0_val = GGML_FP16_TO_FP32(((const uint16_t *)((src0_row + ir0 * nb01)))[i]);
	//    float src1_val = GGML_FP16_TO_FP32(((const uint16_t *)(src1_col))[i]);
	//    printf("src0_row1[%d]=0x%04x (%016llx), src1_col1[%d]=0x%04x (%016llx)\n", 
	//           i, ((const uint16_t *)((src0_row + ir0 * nb01)))[i], *(Ull*)&src0_val, 
	//           i, ((const uint16_t *)(src1_col))[i], *(Ull*)&src1_val);
	//    float product = src0_val * src1_val;
	//   //  printf("product=%016llx\n", *(Ull*)&product);
  //   sumf += product;
      
  //    }}

	  

	//  tmp[ir0 - iir0] = sumf;
  
	  
// #endif
    }
	  monitor_time_start(THREAD, ARM_MEMCPY); /* Nakashima */
	  for (int cn = 0; cn < num_rows_per_vec_dot; ++cn) /* num_rows_per_vec_dot=1 */
	    memcpy(&dst_col[iir0 + cn * nb1 / nb0], tmp + (cn * 16), (MIN(iir0 + blck_0, ir0_end) - iir0) * sizeof(float));
    //  size_t copy_size = (MIN(iir0 + blck_0, ir0_end) - iir0) * sizeof(float);
    //  size_t copy_count = MIN(iir0 + blck_0, ir0_end) - iir0;
    //         #ifdef DEBUG_DOT_PRODUCT

    //    printf("  < [ARM_MEMCPY] tmp -> dst | count=%zu, size=%zu bytes | src: %p, dst: %p\n", copy_count, copy_size, (void*)tmp, (void*)&dst_col[iir0]);
    //         #endif

    // memcpy(&dst_col[iir0], tmp, copy_size);
    
    monitor_time_end(THREAD, ARM_MEMCPY); /* Nakashima */

	}
      }
    }

    monitor_time_end(THREAD, IMAX_COMPUTE_FORWARD_MUL_MAT_ONE_CHUNK_F16_ARM); /* Nakashima */

  }
else {/* IMAX */


  
#undef  IMAP
#undef  NCHIP
#define IMAP  1
#define NCHIP 1
    int SIMD = 32;
    Ull   CHIP, rofs, cofs, iofs, oofs, fp16_cofs;
    Ull   LOOP1, LOOP0;
    Ull   INIT1, INIT0;
    Ull   AR[64][4];                     /* output of EX     in each unit */
    Ull   BR[64][4][4];                  /* output registers in each unit */
    Ull   r00, r01, r02, r03, r04, r05, r06, r07, r08, r09, r10, r11, r12, r13, r14, r15;
    Ull   r16, r17, r18, r19, r20, r21, r22, r23, r24, r25, r26, r27, r28, r29, r30, r31;
    Ull   cc0, cc1, cc2, cc3, ex0, ex1, out0, out1, out2, out10;
    Ull   Force0, Force1, Force2; /* force to LMM */
    Ull   MNB01_M4    = (0LL-ne00 * sizeof(ggml_fp16_t)               )<<32|((0LL-sizeof(float)      )&0xffffffffLL);
    Ull   MBKF16_0000 = (0LL-(sizeof(ggml_fp16_t)*SIMD)                     )<<32|((0LL-sizeof(ggml_fp16_t))&0xffffffffLL);
    Ull   NB01_4      = (0LL+ne00 * sizeof(ggml_fp16_t)               )<<32|((0LL+sizeof(float)      )&0xffffffffLL);
    Ull   BKF16_0000  = (0LL+(sizeof(ggml_fp16_t)*SIMD)                     )<<32|((0LL+sizeof(ggml_fp16_t))&0xffffffffLL);
  
    const int64_t i13_top = (ir1_start          / (ne12 * ne1));          /* ==0 */
    const int64_t i12_top = (ir1_start - i13_top * ne12 * ne1) / ne1;     /* ==0 */
    const int64_t i11_top = (ir1_start - i13_top * ne12 * ne1 - i12_top * ne1);
    const int64_t i03_top = i13_top / r3;
    const int64_t i02_top = i12_top / r2;
    
    // Ull   cc0, cc1, cc2, cc3, ex0, ex1;
// iMAX側のコードの先頭

    Ull SRC0_ROW_TOP = (Ull)((const char*)src0->data + (0 + i02_top * nb02 + i03_top * nb03) + ir0_start * nb01);
    // 128bit (16byte) 表示
    // printf("SRC0_ROW_TOP [128bit]: ");
    // for (int i = 0; i < 16; ++i) {
    //     printf("%02x ", ((unsigned char*)SRC0_ROW_TOP)[i]);
    // }
    // printf("\n");
    Ull   SRC0_ROW_LENdIMAP  = SRC0_ROW_LEN/IMAP;

    // Ull   i_m0A_TOP          = (const char*)i_m0A[LANE] + (0 + i02_top * nb02 + i03_top * nb03) + ir0_start*nb01;
    // Ull   i_m0A_TOP          = (const char*)i_m0A[LANE] + (0 + i02_top * nb02 + i03_top * nb03) + ir0_start*nb01;
    Ull   SRC1_COL_TOP       = (const char*)wdata       + (src1_cont || src1->type != vec_dot_type ? (i11_top + i12_top * ne11 + i13_top * ne12 * ne11) * row_size /* 4352(0x1100),11696(0x2db0) */
	                                                                                           : (i11_top * nb11 + i12_top * nb12 + i13_top * nb13));
    Ull   DST_COL_TOP        = (float*)((char*)dst->data + (i11_top * nb1 + i12_top * nb2 + i13_top * nb3)) + ir0_start;
    Ull   DST_COL_LENdIMAP   = DST_COL_LEN/IMAP;         /* TOTAL = [[blck_0(16) x IIR0_LOOPS(1,4)]/IMAP] x IIR1_LOOPS(2,1) x IMAP */
    Ull   DST_COL_LEN_TOTdIMAP = DST_COL_LEN_TOTAL/IMAP; /* TOTAL = [[blck_0(16) x IIR0_LOOPS(1,4)]/IMAP] x IIR1_LOOPS(2,1) x IMAP */
    Ull   i_m0C_TOP_IMAP[IMAP][EMAX_NLANE]; for (i=0; i<IMAP; i++) i_m0C_TOP_IMAP[i][LANE] = (Ull)i_m0C[LANE] + i*sizeof(float)*DST_COL_LEN_TOTdIMAP;


    int ctmp;
    // imaxパス内


//  xmax_cpyin(3,i_m0A_TOP,  &ctmp,SRC0_ROW_TOP,1,1,SRC0_ROW_LEN,1,1);
// xmax_cpyin(3,i_m0B[LANE],&ctmp,SRC1_COL_TOP,1,1,SRC1_COL_LEN_TOTAL,1,1);
    // --- 1. src0 (アクティベーション) -> 共有ローカルメモリ i_m0A にコピー ---
    // このチャンクで必要な全範囲 (ir0_start から ir0_end) をコピーする
    //  monitor_time_start(THREAD, IMAX_CPYIN_A);
    // const char* gm_a_base = (const char*)src0->data + (0 + i02_top * nb02 + i03_top * nb03);
    // const size_t src0_row_bytes = ne00 * sizeof(ggml_fp16_t);



    // // char* lm_a_ptr = (char*)i_m0A[LANE]; // i_m0Aの先頭から詰めていく
    // char* lm_a_ptr = (char*)i_m0A[LANE] + ir0_start * src0_row_bytes;
    //  Force0=1;


    // for (int64_t ir0 = ir0_start; ir0 < ir0_end; ++ir0) {
    //     // グローバルメモリ上の、現在のir0に対応する行の先頭アドレス（非連続）
    //     const char* gm_a_row = gm_a_base + ir0 * nb01;

    //     // ローカルメモリに1行分をコピー
    //     memcpy(lm_a_ptr, gm_a_row, src0_row_bytes);

    //     // ローカルメモリの書き込み先ポインタを連続的に進める
    //     lm_a_ptr += src0_row_bytes;
    // }
    //   monitor_time_end(THREAD, IMAX_CPYIN_A);
    
    // // --- 2. src1 (重み) -> スレッド毎のローカルメモリ i_m0B にコピー ---
    // // こちらは各スレッドが独立して使用する
      monitor_time_start(THREAD, IMAX_CPYIN_B);

    char* lm_b_ptr = (char*)i_m0B[LANE];
    const size_t src1_row_bytes = ne00 * sizeof(ggml_fp16_t);
    for (int64_t ir1 = ir1_start; ir1 < ir1_end; ++ir1) {
        const int64_t i13 = (ir1 / (ne12 * ne1));
        const int64_t i12 = (ir1 - i13 * ne12 * ne1) / ne1;
        const int64_t i11 = (ir1 - i13 * ne12 * ne1 - i12 * ne1);
        const char* gm_b_row = (const char*)wdata +
            (src1_cont || src1->type != vec_dot_type ?
             (i11 + i12 * ne11 + i13 * ne12 * ne11) * row_size :
             (i11 * nb11 + i12 * nb12 + i13 * nb13));
        memcpy(lm_b_ptr, gm_b_row, src1_row_bytes);
        lm_b_ptr += src1_row_bytes;
    }
    monitor_time_end(THREAD, IMAX_CPYIN_B);
     Force1=1;
    
    monitor_time_start(THREAD, IMAX_BZERO);

    // --- 3. 出力先ローカルメモリをゼロクリア ---
    const int64_t dst_total_elements = (ir1_end - ir1_start) * (ir0_end - ir0_start);
    memset(i_m0C[LANE], 0, dst_total_elements * sizeof(float));
    // xmax_bzero(i_m0C[LANE],dst_total_elements);

    
    monitor_time_end(THREAD, IMAX_BZERO);
    Force2 = 1; /* force dst  to LMM */


    // =========================================================================================
    // STEP 2: 計算 (COMPUTE) - i_m0Aが共有であることを反映wさせたロジック
    // =========================================================================================
    
    // **重要**: `i_m0A_TOP` を元の設計通りに計算する。これは共有i_m0A内の、
    // このチャンク計算の基点となるアドレスを指す。
    
    // const char* i_m0A_TOP = (const char*)i_m0A[LANE] + (0 + i02_top * nb02 + i03_top * nb03);
    

    float sumf1,sumf2,sumf3;
    int n , m, k,j,r ;
    // Ull rofs;
    // 出力を行ごと (ir1ごと) にループ
 monitor_time_start(THREAD, IMAX_TERM_1);
//  if (ne00 % 8 != 0){
//   printf("n=%d\n",n);
//   printf("ne00=%d\n",ne00); 
//  }

# if 1
  for (int64_t iir1 = ir1_start; iir1 < ir1_end; iir1 += blck_1) { /* weight top loop */
      for (int64_t ir1 = iir1; ir1 < iir1 + blck_1 && ir1 < ir1_end; ir1 += num_rows_per_vec_dot) { /* weight sub loop */
          // 出力を列ごと (ir0ごと) にループ
          const int64_t i13 = (ir1 / (ne12 * ne1));
	  const int64_t i12 = (ir1 - i13 * ne12 * ne1) / ne1;
	  const int64_t i11 = (ir1 - i13 * ne12 * ne1 - i12 * ne1);
        const int64_t i03 = i13 / r3;
        const int64_t i02 = i12 / r2;
        const char* gm_a_base = (const char*)src0->data + (0 + i02 * nb02 + i03 * nb03);
           const int64_t blck_00 = blck_0*IIR0_LOOPS; //DST_COL_LEN   Ull   IIR0_LOOPS         = (ir0_end-ir0_start)/blck_0;         
	         const int64_t blck_00dIMAP = blck_00/IMAP; //DST_COL_LEN
          //  const char*  src0_row = (const char*)i_m0A[LANE];


              //  monitor_time_start(THREAD, IMAX_CPYIN_A);
    // const char* gm_a_base = (const char*)src0->data + (0 + i02_top * nb02 + i03_top * nb03);
    const size_t src0_row_bytes = ne00 * sizeof(ggml_fp16_t);



    // char* lm_a_ptr = (char*)i_m0A[LANE]; // i_m0Aの先頭から詰めていく
    char* lm_a_ptr = (char*)i_m0A[LANE] + ir0_start * src0_row_bytes;
     Force0=1;

    monitor_time_start(THREAD, IMAX_CPYIN_A);
    for (int64_t ir0 = ir0_start; ir0 < ir0_end; ++ir0) {
        // グローバルメモリ上の、現在のir0に対応する行の先頭アドレス（非連続）
        const char* gm_a_row = gm_a_base + ir0 * nb01;

        // ローカルメモリに1行分をコピー
        memcpy(lm_a_ptr, gm_a_row, src0_row_bytes);

        // ローカルメモリの書き込み先ポインタを連続的に進める
        lm_a_ptr += src0_row_bytes;
    }

    monitor_time_end(THREAD, IMAX_CPYIN_A);

          ggml_fp16_t* src0_row = (ggml_fp16_t*)((char*)i_m0A[LANE] + ir0_start * src0_row_bytes);

 
          Ull src0_row_base_p0[16]; for (j=0; j<16;  j++) src0_row_base_p0[j] = (Ull)src0_row+ 0+j*8;
          Ull src0_row_base_p8[16]; for (j=0; j<16;  j++) src0_row_base_p8[j] = (Ull)src0_row+ 8+j*8;



          ggml_fp16_t* src1_col = (ggml_fp16_t*)i_m0B[LANE]+ (ir1 - ir1_start) * ne00;
          Ull          src1_col_base_p0[16]; for (j=0; j<16;  j++) src1_col_base_p0[j] = (Ull)src1_col+ 0+j*8;
	        Ull          src1_col_base_p8[16]; for (j=0; j<16;  j++) src1_col_base_p8[j] = (Ull)src1_col+8+j*8;

          float*       dst_col  = (float*)i_m0C[LANE] + (ir1 - ir1_start) * (ir0_end - ir0_start);
   
#if 0
#define f16(r, cb0, cb1, init0, init1, init2, init3, dst0, dst1, dst2, dst3) \
  mop(OP_LDR, 0 , &BR[r][0][1], src0_row_base_p8[cb0], (Ull)iofs, MSK_W1,src0_row, SRC0_ROW_LEN, 0, Force0, (Ull)NULL, SRC0_ROW_LEN); \
  mop(OP_LDR, 3 , &BR[r][0][0], src0_row_base_p0[cb0], (Ull)iofs, MSK_W1,src0_row, SRC0_ROW_LEN, 0, Force0, (Ull)NULL, SRC0_ROW_LEN); \
  mop(OP_LDR, 0 , &BR[r][1][1], src0_row_base_p8[cb1], (Ull)iofs, MSK_W1,src0_row, SRC0_ROW_LEN, 0, Force0, (Ull)NULL, SRC0_ROW_LEN); \
  mop(OP_LDR, 3 , &BR[r][1][0], src0_row_base_p0[cb1], (Ull)iofs, MSK_W1,src0_row, SRC0_ROW_LEN, 0, Force0, (Ull)NULL, SRC0_ROW_LEN); \
\
  exe(OP_NOP,     &r10, BR[r][0][0], EXP_H3210, 0LL, EXP_H3210, 0LL, EXP_H3210, OP_AND,     0x0000ffff0000ffffLL, OP_SLL, 2LL); \
  exe(OP_NOP,     &r12, BR[r][0][0], EXP_H3210, 0LL, EXP_H3210, 0LL, EXP_H3210, OP_AND,     0xffff0000ffff0000LL, OP_SRL, 14LL);\
  exe(OP_NOP,     &r04, BR[r][1][0], EXP_H3210, 0LL, EXP_H3210, 0LL, EXP_H3210, OP_AND,     0x0000ffff0000ffffLL, OP_SLL, 2LL); \
  exe(OP_NOP,     &r05, BR[r][1][0], EXP_H3210, 0LL, EXP_H3210, 0LL, EXP_H3210, OP_AND,     0xffff0000ffff0000LL, OP_SRL, 14LL);\
  mop(OP_LDR,  0, &BR[r+1][0][1], src1_col_base_p8[cb0], (Ull)cofs, MSK_W1,i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)NULL, SRC1_COL_LEN_TOTAL); \
  mop(OP_LDR,  3, &BR[r+1][0][0], src1_col_base_p0[cb0], (Ull)cofs, MSK_W1,i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)NULL, SRC1_COL_LEN_TOTAL); \
  mop(OP_LDR,  0, &BR[r+1][1][1], src1_col_base_p8[cb1], (Ull)cofs, MSK_W1,i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)NULL, SRC1_COL_LEN_TOTAL); \
  mop(OP_LDR,  3, &BR[r+1][1][0], src1_col_base_p0[cb1], (Ull)cofs, MSK_W1,i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)NULL, SRC1_COL_LEN_TOTAL); \
\
  exe(OP_NOP,     &r11, BR[r+1][0][0], EXP_H3210, 0LL, EXP_H3210, 0LL, EXP_H3210, OP_AND,     0x0000ffff0000ffffLL, OP_SLL, 2LL); \
  exe(OP_NOP,     &r13, BR[r+1][0][0], EXP_H3210, 0LL, EXP_H3210, 0LL, EXP_H3210, OP_AND,     0xffff0000ffff0000LL, OP_SRL, 14LL);\
  exe(OP_NOP,     &r01, BR[r+1][1][0], EXP_H3210, 0LL, EXP_H3210, 0LL, EXP_H3210, OP_AND,     0x0000ffff0000ffffLL, OP_SLL, 2LL);\
  exe(OP_NOP,     &r06, BR[r+1][1][0], EXP_H3210, 0LL, EXP_H3210, 0LL, EXP_H3210, OP_AND,     0xffff0000ffff0000LL, OP_SRL, 14LL);\
\
  mop(OP_LDWR, 3, &BR[r+3][0][1], (Ull)i_f16[LANE], (Ull)r10, MSK_W0, (Ull)i_f16[LANE], 65536, 0, 0, (Ull)NULL, 65536); \
  mop(OP_LDWR, 3, &BR[r+3][0][0], (Ull)i_f16[LANE], (Ull)r10, MSK_W1, (Ull)i_f16[LANE], 65536, 0, 0, (Ull)NULL, 65536); \
  mop(OP_LDWR, 3, &BR[r+3][1][1], (Ull)i_f16[LANE], (Ull)r11, MSK_W0, (Ull)i_f16[LANE], 65536, 0, 0, (Ull)NULL, 65536);\
  mop(OP_LDWR, 3, &BR[r+3][1][0], (Ull)i_f16[LANE], (Ull)r11, MSK_W1, (Ull)i_f16[LANE], 65536, 0, 0, (Ull)NULL, 65536);\
  mop(OP_LDWR, 3, &BR[r+3][2][1], (Ull)i_f16[LANE], (Ull)r12, MSK_W0, (Ull)i_f16[LANE], 65536, 0, 0, (Ull)NULL, 65536); \
  mop(OP_LDWR, 3, &BR[r+3][2][0], (Ull)i_f16[LANE], (Ull)r12, MSK_W1, (Ull)i_f16[LANE], 65536, 0, 0, (Ull)NULL, 65536); \
  mop(OP_LDWR, 3, &BR[r+3][3][1], (Ull)i_f16[LANE], (Ull)r13, MSK_W0, (Ull)i_f16[LANE], 65536, 0, 0, (Ull)NULL, 65536); \
  mop(OP_LDWR, 3, &BR[r+3][3][0], (Ull)i_f16[LANE], (Ull)r13, MSK_W1, (Ull)i_f16[LANE], 65536, 0, 0, (Ull)NULL, 65536); \
\
  exe(OP_CMOV,    &r15,   0x0000000000000001LL, EXP_H3210 ,BR[r+3][0][1],   EXP_H1010, BR[r+3][0][0],  EXP_H1010, OP_NOP,  0LL,          OP_NOP,   0LL);\
  exe(OP_CMOV,    &r16,   0x0000000000000001LL, EXP_H3210 ,BR[r+3][1][1],   EXP_H1010, BR[r+3][1][0],  EXP_H1010, OP_NOP,  0LL,          OP_NOP,   0LL); \
  exe(OP_CMOV,    &r17,   0x0000000000000001LL, EXP_H3210 ,BR[r+3][2][1],   EXP_H1010, BR[r+3][2][0],  EXP_H1010, OP_NOP,  0LL,          OP_NOP,   0LL);\
  exe(OP_CMOV,    &r18,   0x0000000000000001LL, EXP_H3210 ,BR[r+3][3][1],   EXP_H1010, BR[r+3][3][0],  EXP_H1010, OP_NOP,  0LL,          OP_NOP,   0LL); \
\
  mop(OP_LDWR, 3, &BR[r+4][0][1], (Ull)i_f16[LANE], (Ull)r04, MSK_W0, (Ull)i_f16[LANE], 65536, 0, 0, (Ull)NULL, 65536); \
  mop(OP_LDWR, 3, &BR[r+4][0][0], (Ull)i_f16[LANE], (Ull)r04, MSK_W1, (Ull)i_f16[LANE], 65536, 0, 0, (Ull)NULL, 65536); \
  mop(OP_LDWR, 3, &BR[r+4][1][1], (Ull)i_f16[LANE], (Ull)r01, MSK_W0, (Ull)i_f16[LANE], 65536, 0, 0, (Ull)NULL, 65536);\
  mop(OP_LDWR, 3, &BR[r+4][1][0], (Ull)i_f16[LANE], (Ull)r01, MSK_W1, (Ull)i_f16[LANE], 65536, 0, 0, (Ull)NULL, 65536);\
  mop(OP_LDWR, 3, &BR[r+4][2][1], (Ull)i_f16[LANE], (Ull)r05, MSK_W0, (Ull)i_f16[LANE], 65536, 0, 0, (Ull)NULL, 65536); \
  mop(OP_LDWR, 3, &BR[r+4][2][0], (Ull)i_f16[LANE], (Ull)r05, MSK_W1, (Ull)i_f16[LANE], 65536, 0, 0, (Ull)NULL, 65536); \
  mop(OP_LDWR, 3, &BR[r+4][3][1], (Ull)i_f16[LANE], (Ull)r06, MSK_W0, (Ull)i_f16[LANE], 65536, 0, 0, (Ull)NULL, 65536);\
  mop(OP_LDWR, 3, &BR[r+4][3][0], (Ull)i_f16[LANE], (Ull)r06, MSK_W1, (Ull)i_f16[LANE], 65536, 0, 0, (Ull)NULL, 65536); \
\
  exe(OP_CMOV,    &r02,   0x0000000000000001LL, EXP_H3210 ,BR[r+4][0][1],   EXP_H1010, BR[r+4][0][0],  EXP_H1010, OP_NOP,  0LL,          OP_NOP,   0LL);\
  exe(OP_CMOV,    &r03,   0x0000000000000001LL, EXP_H3210 ,BR[r+4][1][1],   EXP_H1010, BR[r+4][1][0],  EXP_H1010, OP_NOP,  0LL,          OP_NOP,   0LL);\
  exe(OP_CMOV,    &r04,   0x0000000000000001LL, EXP_H3210 ,BR[r+4][2][1],   EXP_H1010, BR[r+4][2][0],  EXP_H1010, OP_NOP,  0LL,          OP_NOP,   0LL); \
  exe(OP_CMOV,    &r05,   0x0000000000000001LL, EXP_H3210 ,BR[r+4][3][1],   EXP_H1010, BR[r+4][3][0],  EXP_H1010, OP_NOP,  0LL,          OP_NOP,   0LL); \
\
  exe(OP_FMA,      &dst0,  init0,  EXP_H3210, r15, EXP_H3210, r16, EXP_H3210, OP_NOP,  0LL,  OP_NOP,  0LL);    /* sdata,wdata */\
  exe(OP_FMA,      &dst1,  init1,  EXP_H3210, r17, EXP_H3210, r18, EXP_H3210, OP_NOP,  0LL,  OP_NOP,  0LL);    /* sdata,wdata */\
  exe(OP_FMA,      &dst2,  init2,  EXP_H3210, r02, EXP_H3210, r03, EXP_H3210, OP_NOP,  0LL,  OP_NOP,  0LL);    /* sdata,wdata */\
  // exe(OP_FMA,      &dst3,  init3,  EXP_H3210, r04, EXP_H3210, r05, EXP_H3210, OP_NOP,  0LL,  OP_NOP,  0LL)    /* sdata,wdata */

#else


#define f16(r, cb, cb00, init0, init1, init2, init3, dst0, dst1, dst2, dst3) \
	mop(OP_LDR,   0, &BR[r][0][1],   src0_row_base_p8[cb], (Ull)iofs, MSK_W1, src0_row,   SRC0_ROW_LEN,       0, Force0, (Ull)NULL, SRC0_ROW_LEN); /* dismissible */\
	mop(OP_LDR,   3, &BR[r][0][0],   src0_row_base_p0[cb], (Ull)iofs, MSK_W1, src0_row,   SRC0_ROW_LEN,       0, Force0, (Ull)NULL, SRC0_ROW_LEN); /* unaligned */\
\
        exe(OP_NOP,      &r10,  BR[r][0][0],   EXP_H3210, 0LL,            EXP_H3210, 0LL, EXP_H3210, OP_AND, 0x0000ffff0000ffffLL, OP_SLL, 2LL);        /* x.d   fp16->fp32 */\
        exe(OP_NOP,      &r11,  BR[r][0][0],   EXP_H3210, 0LL,            EXP_H3210, 0LL, EXP_H3210, OP_AND, 0xffff0000ffff0000LL, OP_SRL,14LL);        /* x.d   fp16->fp32 */\
  	  mop(OP_LDR, 0, &BR[r+1][0][1], src1_col_base_p8[cb], (Ull)cofs, MSK_W1, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)NULL, SRC1_COL_LEN_TOTAL); /* dismissible */\
	  mop(OP_LDR, 3, &BR[r+1][0][0], src1_col_base_p0[cb], (Ull)cofs, MSK_W1, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)NULL, SRC1_COL_LEN_TOTAL); /* unaligned */\
\
          exe(OP_NOP,    &r12,  BR[r+1][0][0], EXP_H3210, 0LL,            EXP_H3210, 0LL, EXP_H3210, OP_AND, 0x0000ffff0000ffffLL, OP_SLL, 2LL);        /* x.d   fp16->fp32 */\
          exe(OP_NOP,    &r13,  BR[r+1][0][0], EXP_H3210, 0LL,            EXP_H3210, 0LL, EXP_H3210, OP_AND, 0xffff0000ffff0000LL, OP_SRL,14LL);        /* x.d   fp16->fp32 */\
\
	mop(OP_LDWR,  3, &BR[r+3][0][1], (Ull)i_f16[LANE],     (Ull)r10,  MSK_W0, (Ull)i_f16[LANE], 65536, 0, 0, (Ull)NULL, 65536); /* x.d   fp16->fp32 */\
	mop(OP_LDWR,  3, &BR[r+3][0][0], (Ull)i_f16[LANE],     (Ull)r10,  MSK_W1, (Ull)i_f16[LANE], 65536, 0, 0, (Ull)NULL, 65536); /* x.d   fp16->fp32 */\
	mop(OP_LDWR,  3, &BR[r+3][1][1], (Ull)i_f16[LANE],     (Ull)r11,  MSK_W0, (Ull)i_f16[LANE], 65536, 0, 0, (Ull)NULL, 65536); /* x.d   fp16->fp32 */\
	mop(OP_LDWR,  3, &BR[r+3][1][0], (Ull)i_f16[LANE],     (Ull)r11,  MSK_W1, (Ull)i_f16[LANE], 65536, 0, 0, (Ull)NULL, 65536); /* x.d   fp16->fp32 */\
	mop(OP_LDWR,  3, &BR[r+3][2][1], (Ull)i_f16[LANE],     (Ull)r12,  MSK_W0, (Ull)i_f16[LANE], 65536, 0, 0, (Ull)NULL, 65536); /* x.d   fp16->fp32 */\
	mop(OP_LDWR,  3, &BR[r+3][2][0], (Ull)i_f16[LANE],     (Ull)r12,  MSK_W1, (Ull)i_f16[LANE], 65536, 0, 0, (Ull)NULL, 65536); /* x.d   fp16->fp32 */\
	mop(OP_LDWR,  3, &BR[r+3][3][1], (Ull)i_f16[LANE],     (Ull)r13,  MSK_W0, (Ull)i_f16[LANE], 65536, 0, 0, (Ull)NULL, 65536); /* x.d   fp16->fp32 */\
	mop(OP_LDWR,  3, &BR[r+3][3][0], (Ull)i_f16[LANE],     (Ull)r13,  MSK_W1, (Ull)i_f16[LANE], 65536, 0, 0, (Ull)NULL, 65536); /* x.d   fp16->fp32 */\
\
        exe(OP_FMA,   &dst0,  init0,  EXP_H3210, BR[r+3][0][1], EXP_H3210, BR[r+3][2][1], EXP_H3210, OP_NOP,  0LL,  OP_NOP,  0LL);   /* sdata,wdata */\
        exe(OP_FMA,   &dst1,  init1,  EXP_H3210, BR[r+3][0][0], EXP_H3210, BR[r+3][2][0], EXP_H3210, OP_NOP,  0LL,  OP_NOP,  0LL);   /* sdata,wdata */\
        exe(OP_FMA,   &dst2,  init2,  EXP_H3210, BR[r+3][1][1], EXP_H3210, BR[r+3][3][1], EXP_H3210, OP_NOP,  0LL,  OP_NOP,  0LL);   /* sdata,wdata */\
        exe(OP_FMA,   &dst3,  init3,  EXP_H3210, BR[r+3][1][0], EXP_H3210, BR[r+3][3][0], EXP_H3210, OP_NOP,  0LL,  OP_NOP,  0LL)    /* sdata,wdata */
#endif

//EMAX5A begin mul_mat_one_chunk_fp16 mapdist=0
         /*3*/for (CHIP = 0; CHIP < NCHIP; CHIP++) { /* will be parallelized by multi-chip (M/#chip) */
             /*2*/for (INIT1 = 1, LOOP1 = blck_00dIMAP, rofs = MNB01_M4; LOOP1--; INIT1 = 0) { /* stage#0 *//* mapped to FOR() on BR[63][1][0] *//* blck_0=16 *//* stage#0 *//* mapped to FOR() on BR[63][1][0] *//* blck_0=16 , (ir0_end-ir0_start)/blck_0=1 */
               /*1*/for (INIT0 = 1, LOOP0 = ne00/SIMD, cofs=MBKF16_0000; LOOP0--; INIT0 = 0) {  /* stage#0 *//* mapped to FOR() on BR[63][0][0] *//* nb=128,344 LMM=17408,46784word */
#if 1
          exe(OP_ADD,      &rofs, rofs,                   EXP_H3210, INIT0?NB01_4:0, EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL,                  OP_NOP, 0LL);
          exe(OP_ADD,      &cofs, INIT0?cofs:cofs,        EXP_H3210, BKF16_0000,     EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL,                  OP_NOP, 0LL);
          exe(OP_ADD,      &iofs, rofs,                   EXP_H3210, cofs,           EXP_H3210, 0LL, EXP_H3210, OP_AND, 0xffffffff00000000LL, OP_NOP, 0LL);
          exe(OP_ADD,      &oofs, rofs,                   EXP_H3210, 0LL,            EXP_H3210, 0LL, EXP_H3210, OP_AND, 0x00000000ffffffffLL, OP_NOP, 0LL);

           
#endif
          

#if 0
                if (INIT0 == 1) sumf1 = 0.0f;
                m = blck_00dIMAP - LOOP1 -1;
                k = n-LOOP0 -1; //note 1ずれている;
                // ggml_fp16_t* p_src0 = (ggml_fp16_t*)(src0_row + (ir0_start + m) * ne00) + k;
                sumf3=0.0f;
           

                for(int i=0;i<4;i++){
                ggml_fp16_t* p_src0_row = (ggml_fp16_t*)((char*)src0_row + m * ne00*sizeof(ggml_fp16_t));
                ggml_fp16_t* p_src0 = p_src0_row + k*4+i;

                ggml_fp16_t* p_src1 = src1_col + k*4+i;
                // printf("%d,p_src0=%016llx, p_src1=%016llx\n", i, *p_src0, *p_src1);
                float val0 = GGML_FP16_TO_FP32(*p_src0);
                float val1 = GGML_FP16_TO_FP32(*p_src1);
                printf("%d,val0=%016llx, val1=%016llx\n", i, *(Ull*)&val0, *(Ull*)&val1);
                // *(float*)&r01 = val0 * val1;
                sumf1 += val0 * val1;
                sumf3 += val0 * val1;}
                // printf("sumf3=0x%016llx\n", *(Ull*)&sumf3);

                
#endif
#if 0
                if (INIT0 == 1) sumf2 = 0.0f;
                ggml_fp16_t* p_src01 = (ggml_fp16_t*)((char*)src0_row + (iofs>>32));
                ggml_fp16_t* p_src11 = (ggml_fp16_t*)((char*)src1_col + (cofs>>32));
                	   // Print the fp16 values and their float conversions for debug
                	   printf("p_src01=0x%04x (float=%016llx), p_src11=0x%04x (float=%016llx)\n",
                	          *(uint16_t*)p_src01, *(Ull*)&(float){GGML_FP16_TO_FP32(*p_src01)},
                	          *(uint16_t*)p_src11, *(Ull*)&(float){GGML_FP16_TO_FP32(*p_src11)});
                	   float val0 = GGML_FP16_TO_FP32(*p_src01);
                	   float val1 = GGML_FP16_TO_FP32(*p_src11);
                	   float product = val0 * val1;
                	   printf("product=%016llx\n", *(Ull*)&product);
                	   sumf2 += product;

                // ggml_fp16_t* p_src02 = (ggml_fp16_t*)((char*)src0_row + (rof>>32));
                // ggml_fp16_t* p_src12 = (ggml_fp16_t*)((char*)src1_col + (cofs>>32));
                // float val0 = GGML_FP16_TO_FP32(*p_src01);
                // float val1 = GGML_FP16_TO_FP32(*p_src11);
                // *(float*)&r01 = val0 * val1;




                // printf("r01=%016llx\n", r01);

                // printf("val0=%016llx\n",*(Ull*)&val0);
                // sumf2 += GGML_FP16_TO_FP32(*p_src01) * GGML_FP16_TO_FP32(*p_src11);
                //  *(float*)&r01 = GGML_FP16_TO_FP32(*p_src01) * GGML_FP16_TO_FP32(*p_src11);
                // sumf1 += val0 * val1;
                // if (sumf1 != sumf2) {
                //     printf("sumf1=%f, sumf2=%f (NOT MATCH)\n", sumf1, sumf2);
                //     printf("p_src00=%016llx,p_src01=%016llx\n",*p_src0,*p_src1);
                //     printf("p_src01=%016llx,p_src11=%016llx\n",*p_src01,*p_src11);
                // }


                

                // ggml_fp16_t* p_src0 = (ggml_fp16_t*)((char*)src0_row + (rofs>>32)+(cofs>>32));
#endif     
#if 0
          // printf("iofs=%016llx\n",iofs);
          mop(OP_LDR,  0, &BR[2][0][1], src0_row_base_p8[0], (Ull)iofs, MSK_W1,src0_row, SRC0_ROW_LEN, 0, Force0, (Ull)NULL, SRC0_ROW_LEN);
          mop(OP_LDR,  3, &BR[2][0][0], src0_row_base_p0[0], (Ull)iofs, MSK_W1,src0_row, SRC0_ROW_LEN, 0, Force0, (Ull)NULL, SRC0_ROW_LEN);
          mop(OP_LDR,  0, &BR[2][1][1], src0_row_base_p8[1], (Ull)iofs, MSK_W1,src0_row, SRC0_ROW_LEN, 0, Force0, (Ull)NULL, SRC0_ROW_LEN);
          mop(OP_LDR,  3, &BR[2][1][0], src0_row_base_p0[1], (Ull)iofs, MSK_W1,src0_row, SRC0_ROW_LEN, 0, Force0, (Ull)NULL, SRC0_ROW_LEN);

          exe(OP_NOP,     &r10, BR[2][0][0], EXP_H3210, 0LL, EXP_H3210, 0LL, EXP_H3210, OP_AND,     0x0000ffff0000ffffLL, OP_SLL, 2LL);
          exe(OP_NOP,     &r15, BR[2][0][0], EXP_H3210, 0LL, EXP_H3210, 0LL, EXP_H3210, OP_AND,     0xffff0000ffff0000LL, OP_SRL, 14LL);
          exe(OP_NOP,     &r20, BR[2][1][0], EXP_H3210, 0LL, EXP_H3210, 0LL, EXP_H3210, OP_AND,     0x0000ffff0000ffffLL, OP_SLL, 2LL);
          exe(OP_NOP,     &r25, BR[2][1][0], EXP_H3210, 0LL, EXP_H3210, 0LL, EXP_H3210, OP_AND,     0xffff0000ffff0000LL, OP_SRL, 14LL);
          mop(OP_LDR,  0, &BR[3][0][1], src1_col_base_p8[0], (Ull)cofs, MSK_W1,i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)NULL, SRC1_COL_LEN_TOTAL);
          mop(OP_LDR,  3, &BR[3][0][0], src1_col_base_p0[0], (Ull)cofs, MSK_W1,i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)NULL, SRC1_COL_LEN_TOTAL);
          mop(OP_LDR,  0, &BR[3][1][1], src1_col_base_p8[1], (Ull)cofs, MSK_W1,i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)NULL, SRC1_COL_LEN_TOTAL);
          mop(OP_LDR,  3, &BR[3][1][0], src1_col_base_p0[1], (Ull)cofs, MSK_W1,i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)NULL, SRC1_COL_LEN_TOTAL);

         
          exe(OP_NOP,     &r11, BR[3][0][0], EXP_H3210, 0LL, EXP_H3210, 0LL, EXP_H3210, OP_AND,     0x0000ffff0000ffffLL, OP_SLL, 2LL);
          exe(OP_NOP,     &r16, BR[3][0][0], EXP_H3210, 0LL, EXP_H3210, 0LL, EXP_H3210, OP_AND,     0xffff0000ffff0000LL, OP_SRL, 14LL);
          exe(OP_NOP,     &r21, BR[3][1][0], EXP_H3210, 0LL, EXP_H3210, 0LL, EXP_H3210, OP_AND,     0x0000ffff0000ffffLL, OP_SLL, 2LL);
          exe(OP_NOP,     &r26, BR[3][1][0], EXP_H3210, 0LL, EXP_H3210, 0LL, EXP_H3210, OP_AND,     0xffff0000ffff0000LL, OP_SRL, 14LL);
          mop(OP_LDWR, 3, &BR[5][0][1], (Ull)i_f16[LANE], (Ull)r10, MSK_W0, (Ull)i_f16[LANE], 65536, 0, 0, (Ull)NULL, 65536);
          mop(OP_LDWR, 3, &BR[5][1][1], (Ull)i_f16[LANE], (Ull)r10, MSK_W1, (Ull)i_f16[LANE], 65536, 0, 0, (Ull)NULL, 65536); 
          mop(OP_LDWR, 3, &BR[5][2][1], (Ull)i_f16[LANE], (Ull)r11, MSK_W0, (Ull)i_f16[LANE], 65536, 0, 0, (Ull)NULL, 65536);
          mop(OP_LDWR, 3, &BR[5][3][1], (Ull)i_f16[LANE], (Ull)r11, MSK_W1, (Ull)i_f16[LANE], 65536, 0, 0, (Ull)NULL, 65536);
          // printf("BR[5][0][1]=%016llx, BR[5][1][1]=%016llx, BR[5][2][1]=%016llx, BR[5][3][1]=%016llx\n", BR[5][0][1], BR[5][1][1], BR[5][2][1], BR[5][3][1]);

          
          exe(OP_CMOV,    &r12,   0x0000000000000001LL, EXP_H3210 ,BR[5][0][1],   EXP_H1010, BR[5][1][1],  EXP_H1010, OP_NOP,  0LL,          OP_NOP,   0LL);
          exe(OP_CMOV,    &r13,   0x0000000000000001LL, EXP_H3210 ,BR[5][2][1],   EXP_H1010, BR[5][3][1],  EXP_H1010, OP_NOP,  0LL,          OP_NOP,   0LL);
          // printf("r12=%016llx, r13=%016llx\n", r12, r13);

          mop(OP_LDWR, 3, &BR[6][0][1], (Ull)i_f16[LANE], (Ull)r15, MSK_W0, (Ull)i_f16[LANE], 65536, 0, 0, (Ull)NULL, 65536);
          mop(OP_LDWR, 3, &BR[6][1][1], (Ull)i_f16[LANE], (Ull)r15, MSK_W1, (Ull)i_f16[LANE], 65536, 0, 0, (Ull)NULL, 65536); 
          mop(OP_LDWR, 3, &BR[6][2][1], (Ull)i_f16[LANE], (Ull)r16, MSK_W0, (Ull)i_f16[LANE], 65536, 0, 0, (Ull)NULL, 65536);
          mop(OP_LDWR, 3, &BR[6][3][1], (Ull)i_f16[LANE], (Ull)r16, MSK_W1, (Ull)i_f16[LANE], 65536, 0, 0, (Ull)NULL, 65536);
          // printf("BR[6][0][1]=%016llx, BR[6][1][1]=%016llx, BR[6][2][1]=%016llx, BR[6][3][1]=%016llx\n", BR[6][0][1], BR[6][1][1], BR[6][2][1], BR[6][3][1]);

          exe(OP_CMOV,    &r17,   0x0000000000000001LL, EXP_H3210 ,BR[6][0][1],   EXP_H1010, BR[6][1][1],  EXP_H1010, OP_NOP,  0LL,          OP_NOP,   0LL);
          exe(OP_CMOV,    &r18,   0x0000000000000001LL, EXP_H3210 ,BR[6][2][1],   EXP_H1010, BR[6][3][1],  EXP_H1010, OP_NOP,  0LL,          OP_NOP,   0LL);
        

          //3,4
          mop(OP_LDWR, 3, &BR[7][0][1], (Ull)i_f16[LANE], (Ull)r20, MSK_W0, (Ull)i_f16[LANE], 65536, 0, 0, (Ull)NULL, 65536);
          mop(OP_LDWR, 3, &BR[7][1][1], (Ull)i_f16[LANE], (Ull)r20, MSK_W1, (Ull)i_f16[LANE], 65536, 0, 0, (Ull)NULL, 65536); 
          mop(OP_LDWR, 3, &BR[7][2][1], (Ull)i_f16[LANE], (Ull)r21, MSK_W0, (Ull)i_f16[LANE], 65536, 0, 0, (Ull)NULL, 65536);
          mop(OP_LDWR, 3, &BR[7][3][1], (Ull)i_f16[LANE], (Ull)r21, MSK_W1, (Ull)i_f16[LANE], 65536, 0, 0, (Ull)NULL, 65536);
          // printf("BR[5][0][1]=%016llx, BR[5][1][1]=%016llx, BR[5][2][1]=%016llx, BR[5][3][1]=%016llx\n", BR[5][0][1], BR[5][1][1], BR[5][2][1], BR[5][3][1]);

          
          exe(OP_CMOV,    &r22,   0x0000000000000001LL, EXP_H3210 ,BR[7][0][1],   EXP_H1010, BR[7][1][1],  EXP_H1010, OP_NOP,  0LL,          OP_NOP,   0LL);
          exe(OP_CMOV,    &r23,   0x0000000000000001LL, EXP_H3210 ,BR[7][2][1],   EXP_H1010, BR[7][3][1],  EXP_H1010, OP_NOP,  0LL,          OP_NOP,   0LL);
          // printf("r12=%016llx, r13=%016llx\n", r12, r13);

          mop(OP_LDWR, 3, &BR[8][0][1], (Ull)i_f16[LANE], (Ull)r25, MSK_W0, (Ull)i_f16[LANE], 65536, 0, 0, (Ull)NULL, 65536);
          mop(OP_LDWR, 3, &BR[8][1][1], (Ull)i_f16[LANE], (Ull)r25, MSK_W1, (Ull)i_f16[LANE], 65536, 0, 0, (Ull)NULL, 65536); 
          mop(OP_LDWR, 3, &BR[8][2][1], (Ull)i_f16[LANE], (Ull)r26, MSK_W0, (Ull)i_f16[LANE], 65536, 0, 0, (Ull)NULL, 65536);
          mop(OP_LDWR, 3, &BR[8][3][1], (Ull)i_f16[LANE], (Ull)r26, MSK_W1, (Ull)i_f16[LANE], 65536, 0, 0, (Ull)NULL, 65536);
          // printf("BR[6][0][1]=%016llx, BR[6][1][1]=%016llx, BR[6][2][1]=%016llx, BR[6][3][1]=%016llx\n", BR[6][0][1], BR[6][1][1], BR[6][2][1], BR[6][3][1]);

          exe(OP_CMOV,    &r27,   0x0000000000000001LL, EXP_H3210 ,BR[8][0][1],   EXP_H1010, BR[8][1][1],  EXP_H1010, OP_NOP,  0LL,          OP_NOP,   0LL);
          exe(OP_CMOV,    &r28,   0x0000000000000001LL, EXP_H3210 ,BR[8][2][1],   EXP_H1010, BR[8][3][1],  EXP_H1010, OP_NOP,  0LL,          OP_NOP,   0LL);

          exe(OP_FMA,      &r14,  0,  EXP_H3210, r12, EXP_H3210, r13, EXP_H3210, OP_NOP,  0LL,  OP_NOP,  0LL);    /* sdata,wdata */
          exe(OP_FMA,      &r19,  0,  EXP_H3210, r17, EXP_H3210, r18, EXP_H3210, OP_NOP,  0LL,  OP_NOP,  0LL);    /* sdata,wdata */
          exe(OP_FMA,      &r24,  0,  EXP_H3210, r22, EXP_H3210, r23, EXP_H3210, OP_NOP,  0LL,  OP_NOP,  0LL);    /* sdata,wdata */
          exe(OP_FMA,      &r30,  0,  EXP_H3210, r27, EXP_H3210, r28, EXP_H3210, OP_NOP,  0LL,  OP_NOP,  0LL);    /* sdata,wdata */
         



  // // printf("iofs=%016llx\n",iofs);
          mop(OP_LDR,  0, &BR[10][0][1], src0_row_base_p8[2], (Ull)iofs, MSK_W1,src0_row, SRC0_ROW_LEN, 0, Force0, (Ull)NULL, SRC0_ROW_LEN);
          mop(OP_LDR,  3, &BR[10][0][0], src0_row_base_p0[2], (Ull)iofs, MSK_W1,src0_row, SRC0_ROW_LEN, 0, Force0, (Ull)NULL, SRC0_ROW_LEN);
          mop(OP_LDR,  0, &BR[10][1][1], src0_row_base_p8[3], (Ull)iofs, MSK_W1,src0_row, SRC0_ROW_LEN, 0, Force0, (Ull)NULL, SRC0_ROW_LEN);
          mop(OP_LDR,  3, &BR[10][1][0], src0_row_base_p0[3], (Ull)iofs, MSK_W1,src0_row, SRC0_ROW_LEN, 0, Force0, (Ull)NULL, SRC0_ROW_LEN);

          exe(OP_NOP,     &r10, BR[10][0][0], EXP_H3210, 0LL, EXP_H3210, 0LL, EXP_H3210, OP_AND,     0x0000ffff0000ffffLL, OP_SLL, 2LL);
          exe(OP_NOP,     &r15, BR[10][0][0], EXP_H3210, 0LL, EXP_H3210, 0LL, EXP_H3210, OP_AND,     0xffff0000ffff0000LL, OP_SRL, 14LL);
          exe(OP_NOP,     &r20, BR[10][1][0], EXP_H3210, 0LL, EXP_H3210, 0LL, EXP_H3210, OP_AND,     0x0000ffff0000ffffLL, OP_SLL, 2LL);
          exe(OP_NOP,     &r25, BR[10][1][0], EXP_H3210, 0LL, EXP_H3210, 0LL, EXP_H3210, OP_AND,     0xffff0000ffff0000LL, OP_SRL, 14LL);

          mop(OP_LDR,  0, &BR[11][0][1], src1_col_base_p8[2], (Ull)cofs, MSK_W1,i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)NULL, SRC1_COL_LEN_TOTAL);
          mop(OP_LDR,  3, &BR[11][0][0], src1_col_base_p0[2], (Ull)cofs, MSK_W1,i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)NULL, SRC1_COL_LEN_TOTAL);
          mop(OP_LDR,  0, &BR[11][1][1], src1_col_base_p8[3], (Ull)cofs, MSK_W1,i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)NULL, SRC1_COL_LEN_TOTAL);
          mop(OP_LDR,  3, &BR[11][1][0], src1_col_base_p0[3], (Ull)cofs, MSK_W1,i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)NULL, SRC1_COL_LEN_TOTAL);
          
          
          exe(OP_NOP,     &r11, BR[11][0][0], EXP_H3210, 0LL, EXP_H3210, 0LL, EXP_H3210, OP_AND,     0x0000ffff0000ffffLL, OP_SLL, 2LL);
          exe(OP_NOP,     &r16, BR[11][0][0], EXP_H3210, 0LL, EXP_H3210, 0LL, EXP_H3210, OP_AND,     0xffff0000ffff0000LL, OP_SRL, 14LL);
          exe(OP_NOP,     &r21, BR[11][1][0], EXP_H3210, 0LL, EXP_H3210, 0LL, EXP_H3210, OP_AND,     0x0000ffff0000ffffLL, OP_SLL, 2LL);
          exe(OP_NOP,     &r26, BR[11][1][0], EXP_H3210, 0LL, EXP_H3210, 0LL, EXP_H3210, OP_AND,     0xffff0000ffff0000LL, OP_SRL, 14LL);


          // printf("BR[3][0][0]=%016llx\n", BR[3][0][0]);
          //1,2
          mop(OP_LDWR, 3, &BR[13][0][1], (Ull)i_f16[LANE], (Ull)r10, MSK_W0, (Ull)i_f16[LANE], 65536, 0, 0, (Ull)NULL, 65536);
          mop(OP_LDWR, 3, &BR[13][1][1], (Ull)i_f16[LANE], (Ull)r10, MSK_W1, (Ull)i_f16[LANE], 65536, 0, 0, (Ull)NULL, 65536); 
          mop(OP_LDWR, 3, &BR[13][2][1], (Ull)i_f16[LANE], (Ull)r11, MSK_W0, (Ull)i_f16[LANE], 65536, 0, 0, (Ull)NULL, 65536);
          mop(OP_LDWR, 3, &BR[13][3][1], (Ull)i_f16[LANE], (Ull)r11, MSK_W1, (Ull)i_f16[LANE], 65536, 0, 0, (Ull)NULL, 65536);
          // printf("BR[5][0][1]=%016llx, BR[5][1][1]=%016llx, BR[5][2][1]=%016llx, BR[5][3][1]=%016llx\n", BR[5][0][1], BR[5][1][1], BR[5][2][1], BR[5][3][1]);

          
          exe(OP_CMOV,    &r12,   0x0000000000000001LL, EXP_H3210 ,BR[13][0][1],   EXP_H1010, BR[13][1][1],  EXP_H1010, OP_NOP,  0LL,          OP_NOP,   0LL);
          exe(OP_CMOV,    &r13,   0x0000000000000001LL, EXP_H3210 ,BR[13][2][1],   EXP_H1010, BR[13][3][1],  EXP_H1010, OP_NOP,  0LL,          OP_NOP,   0LL);
          // printf("r12=%016llx, r13=%016llx\n", r12, r13);

          mop(OP_LDWR, 3, &BR[14][0][1], (Ull)i_f16[LANE], (Ull)r15, MSK_W0, (Ull)i_f16[LANE], 65536, 0, 0, (Ull)NULL, 65536);
          mop(OP_LDWR, 3, &BR[14][1][1], (Ull)i_f16[LANE], (Ull)r15, MSK_W1, (Ull)i_f16[LANE], 65536, 0, 0, (Ull)NULL, 65536); 
          mop(OP_LDWR, 3, &BR[14][2][1], (Ull)i_f16[LANE], (Ull)r16, MSK_W0, (Ull)i_f16[LANE], 65536, 0, 0, (Ull)NULL, 65536);
          mop(OP_LDWR, 3, &BR[14][3][1], (Ull)i_f16[LANE], (Ull)r16, MSK_W1, (Ull)i_f16[LANE], 65536, 0, 0, (Ull)NULL, 65536);
          // printf("BR[6][0][1]=%016llx, BR[6][1][1]=%016llx, BR[6][2][1]=%016llx, BR[6][3][1]=%016llx\n", BR[6][0][1], BR[6][1][1], BR[6][2][1], BR[6][3][1]);
          exe(OP_CMOV,    &r17,   0x0000000000000001LL, EXP_H3210 ,BR[14][0][1],   EXP_H1010, BR[14][1][1],  EXP_H1010, OP_NOP,  0LL,          OP_NOP,   0LL);
          exe(OP_CMOV,    &r18,   0x0000000000000001LL, EXP_H3210 ,BR[14][2][1],   EXP_H1010, BR[14][3][1],  EXP_H1010, OP_NOP,  0LL,          OP_NOP,   0LL);
        

          //3,4
          mop(OP_LDWR, 3, &BR[15][0][1], (Ull)i_f16[LANE], (Ull)r20, MSK_W0, (Ull)i_f16[LANE], 65536, 0, 0, (Ull)NULL, 65536);
          mop(OP_LDWR, 3, &BR[15][1][1], (Ull)i_f16[LANE], (Ull)r20, MSK_W1, (Ull)i_f16[LANE], 65536, 0, 0, (Ull)NULL, 65536); 
          mop(OP_LDWR, 3, &BR[15][2][1], (Ull)i_f16[LANE], (Ull)r21, MSK_W0, (Ull)i_f16[LANE], 65536, 0, 0, (Ull)NULL, 65536);
          mop(OP_LDWR, 3, &BR[15][3][1], (Ull)i_f16[LANE], (Ull)r21, MSK_W1, (Ull)i_f16[LANE], 65536, 0, 0, (Ull)NULL, 65536);
          // printf("BR[5][0][1]=%016llx, BR[5][1][1]=%016llx, BR[5][2][1]=%016llx, BR[5][3][1]=%016llx\n", BR[5][0][1], BR[5][1][1], BR[5][2][1], BR[5][3][1]);

          
          exe(OP_CMOV,    &r22,   0x0000000000000001LL, EXP_H3210 ,BR[15][0][1],   EXP_H1010, BR[15][1][1],  EXP_H1010, OP_NOP,  0LL,          OP_NOP,   0LL);
          exe(OP_CMOV,    &r23,   0x0000000000000001LL, EXP_H3210 ,BR[15][2][1],   EXP_H1010, BR[15][3][1],  EXP_H1010, OP_NOP,  0LL,          OP_NOP,   0LL);
          // printf("r12=%016llx, r13=%016llx\n", r12, r13);

          mop(OP_LDWR, 3, &BR[16][0][1], (Ull)i_f16[LANE], (Ull)r25, MSK_W0, (Ull)i_f16[LANE], 65536, 0, 0, (Ull)NULL, 65536);
          mop(OP_LDWR, 3, &BR[16][1][1], (Ull)i_f16[LANE], (Ull)r25, MSK_W1, (Ull)i_f16[LANE], 65536, 0, 0, (Ull)NULL, 65536); 
          mop(OP_LDWR, 3, &BR[16][2][1], (Ull)i_f16[LANE], (Ull)r26, MSK_W0, (Ull)i_f16[LANE], 65536, 0, 0, (Ull)NULL, 65536);
          mop(OP_LDWR, 3, &BR[16][3][1], (Ull)i_f16[LANE], (Ull)r26, MSK_W1, (Ull)i_f16[LANE], 65536, 0, 0, (Ull)NULL, 65536);
          // printf("BR[6][0][1]=%016llx, BR[6][1][1]=%016llx, BR[6][2][1]=%016llx, BR[6][3][1]=%016llx\n", BR[6][0][1], BR[6][1][1], BR[6][2][1], BR[6][3][1]);

          exe(OP_CMOV,    &r27,   0x0000000000000001LL, EXP_H3210 ,BR[16][0][1],   EXP_H1010, BR[16][1][1],  EXP_H1010, OP_NOP,  0LL,          OP_NOP,   0LL);
          exe(OP_CMOV,    &r28,   0x0000000000000001LL, EXP_H3210 ,BR[16][2][1],   EXP_H1010, BR[16][3][1],  EXP_H1010, OP_NOP,  0LL,          OP_NOP,   0LL);

          exe(OP_FMA,      &r03,  r14,  EXP_H3210, r12, EXP_H3210, r13, EXP_H3210, OP_NOP,  0LL,  OP_NOP,  0LL);    /* sdata,wdata */
          exe(OP_FMA,      &r04,  r19,  EXP_H3210, r17, EXP_H3210, r18, EXP_H3210, OP_NOP,  0LL,  OP_NOP,  0LL);    /* sdata,wdata */
          exe(OP_FMA,      &r05,  r24,  EXP_H3210, r22, EXP_H3210, r23, EXP_H3210, OP_NOP,  0LL,  OP_NOP,  0LL);    /* sdata,wdata */
          exe(OP_FMA,      &r06,  r30,  EXP_H3210, r27, EXP_H3210, r28, EXP_H3210, OP_NOP,  0LL,  OP_NOP,  0LL);    /* sdata,wdata */    
          
          
          
          
          exe(OP_FAD,      &r07,  r03,  EXP_H3210, r04,   EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);                       /* ��x*y */
	        exe(OP_FAD,      &r08,  r05,  EXP_H3210, r06,   EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);                       /* ��x*y */
	        exe(OP_FAD,      &r09,  r07,  EXP_H3210, r08,   EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);                       /* ��x*y */
          exe(OP_FAD,      &r31,  r09,  EXP_H3232, r09,   EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);          
              

#else
	          // f16( 2, 0, 0, 0LL, 0LL, 0LL, 0LL, r24, r25, r26, r27);

	          f16( 2, 0, 0, 0LL, 0LL, 0LL, 0LL, r20, r21, r22, r23);
	          f16( 6, 1, 0, r20, r21, r22, r23, r24, r25, r26, r27);
	          f16(10, 2, 0, r24, r25, r26, r27, r20, r21, r22, r23);
	          f16(14, 3, 0, r20, r21, r22, r23, r24, r25, r26, r27);
	          f16(18, 4, 0, r24, r25, r26, r27, r20, r21, r22, r23);
	          f16(22, 5, 0, r20, r21, r22, r23, r24, r25, r26, r27);
	          f16(26, 6, 0, r24, r25, r26, r27, r20, r21, r22, r23);
	          f16(30, 7, 0, r20, r21, r22, r23, r24, r25, r26, r27);
	          // f16(34, 8, 0, r24, r25, r26, r27, r20, r21, r22, r23);
	          // f16(38, 9, 0, r20, r21, r22, r23, r24, r25, r26, r27);
	          // f16(42, 10, 0, r24, r25, r26, r27, r20, r21, r22, r23);
            // f16(46, 11, 0, r20, r21, r22, r23, r24, r25, r26, r27);
            // f16(50, 12, 0, r24, r25, r26, r27, r20, r21, r22, r23);
            // f16(54, 13, 0, r20, r21, r22, r23, r24, r25, r26, r27);

  

	          
            // printf("dst0=0x%016llx, dst1=0x%016llx, dst2=0x%016llx, dst3=0x%016llx\n", r24, r25,r26,r27);
            exe(OP_FAD,      &r25,  r24,  EXP_H3210, r25,   EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);                       /* ��x*y */
	          exe(OP_FAD,      &r27,  r26,  EXP_H3210, r27,   EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);                       /* ��x*y */
	          exe(OP_FAD,      &r31,  r25,  EXP_H3210, r27,   EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);                       /* ��x*y */
            // exe(OP_FAD,      &r31,  r20,  EXP_H3232, r20,   EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);
#endif



#if 0
         // mop(OP_LDR,  0, &BR[22][0][1], src0_row_base_p8[4], (Ull)iofs, MSK_W1,src0_row, SRC0_ROW_LEN, 0, Force0, (Ull)NULL, SRC0_ROW_LEN);
          // mop(OP_LDR,  3, &BR[22][0][0], src0_row_base_p0[4], (Ull)iofs, MSK_W1,src0_row, SRC0_ROW_LEN, 0, Force0, (Ull)NULL, SRC0_ROW_LEN);
          // mop(OP_LDR,  0, &BR[22][1][1], src0_row_base_p8[5], (Ull)iofs, MSK_W1,src0_row, SRC0_ROW_LEN, 0, Force0, (Ull)NULL, SRC0_ROW_LEN);
          // mop(OP_LDR,  3, &BR[22][1][0], src0_row_base_p0[5], (Ull)iofs, MSK_W1,src0_row, SRC0_ROW_LEN, 0, Force0, (Ull)NULL, SRC0_ROW_LEN);

          // mop(OP_LDR,  0, &BR[23][0][1], src1_col_base_p8[4], (Ull)cofs, MSK_W1,i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)NULL, SRC1_COL_LEN_TOTAL);
          // mop(OP_LDR,  3, &BR[23][0][0], src1_col_base_p0[4], (Ull)cofs, MSK_W1,i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)NULL, SRC1_COL_LEN_TOTAL);
          // mop(OP_LDR,  0, &BR[23][1][1], src1_col_base_p8[5], (Ull)cofs, MSK_W1,i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)NULL, SRC1_COL_LEN_TOTAL);
          // mop(OP_LDR,  3, &BR[23][1][0], src1_col_base_p0[5], (Ull)cofs, MSK_W1,i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)NULL, SRC1_COL_LEN_TOTAL);
          
          // exe(OP_NOP,     &r10, BR[22][0][0], EXP_H3210, 0LL, EXP_H3210, 0LL, EXP_H3210, OP_AND,     0x0000ffff0000ffffLL, OP_SLL, 2LL);
          // exe(OP_NOP,     &r11, BR[23][0][0], EXP_H3210, 0LL, EXP_H3210, 0LL, EXP_H3210, OP_AND,     0x0000ffff0000ffffLL, OP_SLL, 2LL);
          // exe(OP_NOP,     &r15, BR[22][0][0], EXP_H3210, 0LL, EXP_H3210, 0LL, EXP_H3210, OP_AND,     0xffff0000ffff0000LL, OP_SRL, 14LL);
          // exe(OP_NOP,     &r16, BR[23][0][0], EXP_H3210, 0LL, EXP_H3210, 0LL, EXP_H3210, OP_AND,     0xffff0000ffff0000LL, OP_SRL, 14LL);
          

          // exe(OP_NOP,     &r20, BR[22][1][0], EXP_H3210, 0LL, EXP_H3210, 0LL, EXP_H3210, OP_AND,     0x0000ffff0000ffffLL, OP_SLL, 2LL);
          // exe(OP_NOP,     &r21, BR[23][1][0], EXP_H3210, 0LL, EXP_H3210, 0LL, EXP_H3210, OP_AND,     0x0000ffff0000ffffLL, OP_SLL, 2LL);
          // exe(OP_NOP,     &r25, BR[22][1][0], EXP_H3210, 0LL, EXP_H3210, 0LL, EXP_H3210, OP_AND,     0xffff0000ffff0000LL, OP_SRL, 14LL);
          // exe(OP_NOP,     &r26, BR[23][1][0], EXP_H3210, 0LL, EXP_H3210, 0LL, EXP_H3210, OP_AND,     0xffff0000ffff0000LL, OP_SRL, 14LL);


          // // printf("BR[3][0][0]=%016llx\n", BR[3][0][0]);
          // //1,2
          // mop(OP_LDWR, 3, &BR[25][0][1], (Ull)i_f16[LANE], (Ull)r10, MSK_W0, (Ull)i_f16[LANE], 65536, 0, 0, (Ull)NULL, 65536);
          // mop(OP_LDWR, 3, &BR[25][1][1], (Ull)i_f16[LANE], (Ull)r10, MSK_W1, (Ull)i_f16[LANE], 65536, 0, 0, (Ull)NULL, 65536); 
          // mop(OP_LDWR, 3, &BR[25][2][1], (Ull)i_f16[LANE], (Ull)r11, MSK_W0, (Ull)i_f16[LANE], 65536, 0, 0, (Ull)NULL, 65536);
          // mop(OP_LDWR, 3, &BR[25][3][1], (Ull)i_f16[LANE], (Ull)r11, MSK_W1, (Ull)i_f16[LANE], 65536, 0, 0, (Ull)NULL, 65536);
          // // printf("BR[5][0][1]=%016llx, BR[5][1][1]=%016llx, BR[5][2][1]=%016llx, BR[5][3][1]=%016llx\n", BR[5][0][1], BR[5][1][1], BR[5][2][1], BR[5][3][1]);

          
          // exe(OP_CMOV,    &r12,   0x0000000000000001LL, EXP_H3210 ,BR[25][0][1],   EXP_H1010, BR[25][1][1],  EXP_H1010, OP_NOP,  0LL,          OP_NOP,   0LL);
          // exe(OP_CMOV,    &r13,   0x0000000000000001LL, EXP_H3210 ,BR[25][2][1],   EXP_H1010, BR[25][3][1],  EXP_H1010, OP_NOP,  0LL,          OP_NOP,   0LL);
          // // printf("r12=%016llx, r13=%016llx\n", r12, r13);

          // mop(OP_LDWR, 3, &BR[26][0][1], (Ull)i_f16[LANE], (Ull)r15, MSK_W0, (Ull)i_f16[LANE], 65536, 0, 0, (Ull)NULL, 65536);
          // mop(OP_LDWR, 3, &BR[26][1][1], (Ull)i_f16[LANE], (Ull)r15, MSK_W1, (Ull)i_f16[LANE], 65536, 0, 0, (Ull)NULL, 65536); 
          // mop(OP_LDWR, 3, &BR[26][2][1], (Ull)i_f16[LANE], (Ull)r16, MSK_W0, (Ull)i_f16[LANE], 65536, 0, 0, (Ull)NULL, 65536);
          // mop(OP_LDWR, 3, &BR[26][3][1], (Ull)i_f16[LANE], (Ull)r16, MSK_W1, (Ull)i_f16[LANE], 65536, 0, 0, (Ull)NULL, 65536);
          // // printf("BR[6][0][1]=%016llx, BR[6][1][1]=%016llx, BR[6][2][1]=%016llx, BR[6][3][1]=%016llx\n", BR[6][0][1], BR[6][1][1], BR[6][2][1], BR[6][3][1]);

          // exe(OP_CMOV,    &r17,   0x0000000000000001LL, EXP_H3210 ,BR[26][0][1],   EXP_H1010, BR[26][1][1],  EXP_H1010, OP_NOP,  0LL,          OP_NOP,   0LL);
          // exe(OP_CMOV,    &r18,   0x0000000000000001LL, EXP_H3210 ,BR[26][2][1],   EXP_H1010, BR[26][3][1],  EXP_H1010, OP_NOP,  0LL,          OP_NOP,   0LL);
        

          // //3,4
          // mop(OP_LDWR, 3, &BR[27][0][1], (Ull)i_f16[LANE], (Ull)r20, MSK_W0, (Ull)i_f16[LANE], 65536, 0, 0, (Ull)NULL, 65536);
          // mop(OP_LDWR, 3, &BR[27][1][1], (Ull)i_f16[LANE], (Ull)r20, MSK_W1, (Ull)i_f16[LANE], 65536, 0, 0, (Ull)NULL, 65536); 
          // mop(OP_LDWR, 3, &BR[27][2][1], (Ull)i_f16[LANE], (Ull)r21, MSK_W0, (Ull)i_f16[LANE], 65536, 0, 0, (Ull)NULL, 65536);
          // mop(OP_LDWR, 3, &BR[27][3][1], (Ull)i_f16[LANE], (Ull)r21, MSK_W1, (Ull)i_f16[LANE], 65536, 0, 0, (Ull)NULL, 65536);
          // // printf("BR[5][0][1]=%016llx, BR[5][1][1]=%016llx, BR[5][2][1]=%016llx, BR[5][3][1]=%016llx\n", BR[5][0][1], BR[5][1][1], BR[5][2][1], BR[5][3][1]);

          
          // exe(OP_CMOV,    &r22,   0x0000000000000001LL, EXP_H3210 ,BR[27][0][1],   EXP_H1010, BR[27][1][1],  EXP_H1010, OP_NOP,  0LL,          OP_NOP,   0LL);
          // exe(OP_CMOV,    &r23,   0x0000000000000001LL, EXP_H3210 ,BR[27][2][1],   EXP_H1010, BR[27][3][1],  EXP_H1010, OP_NOP,  0LL,          OP_NOP,   0LL);
          // // printf("r12=%016llx, r13=%016llx\n", r12, r13);

          // mop(OP_LDWR, 3, &BR[28][0][1], (Ull)i_f16[LANE], (Ull)r25, MSK_W0, (Ull)i_f16[LANE], 65536, 0, 0, (Ull)NULL, 65536);
          // mop(OP_LDWR, 3, &BR[28][1][1], (Ull)i_f16[LANE], (Ull)r25, MSK_W1, (Ull)i_f16[LANE], 65536, 0, 0, (Ull)NULL, 65536); 
          // mop(OP_LDWR, 3, &BR[28][2][1], (Ull)i_f16[LANE], (Ull)r26, MSK_W0, (Ull)i_f16[LANE], 65536, 0, 0, (Ull)NULL, 65536);
          // mop(OP_LDWR, 3, &BR[28][3][1], (Ull)i_f16[LANE], (Ull)r26, MSK_W1, (Ull)i_f16[LANE], 65536, 0, 0, (Ull)NULL, 65536);
          // // printf("BR[6][0][1]=%016llx, BR[6][1][1]=%016llx, BR[6][2][1]=%016llx, BR[6][3][1]=%016llx\n", BR[6][0][1], BR[6][1][1], BR[6][2][1], BR[6][3][1]);

          // exe(OP_CMOV,    &r27,   0x0000000000000001LL, EXP_H3210 ,BR[28][0][1],   EXP_H1010, BR[28][1][1],  EXP_H1010, OP_NOP,  0LL,          OP_NOP,   0LL);
          // exe(OP_CMOV,    &r28,   0x0000000000000001LL, EXP_H3210 ,BR[28][2][1],   EXP_H1010, BR[28][3][1],  EXP_H1010, OP_NOP,  0LL,          OP_NOP,   0LL);

          // exe(OP_FMA,      &r14,  r31,    EXP_H3210, r12, EXP_H3210, r13, EXP_H3210, OP_NOP,  0LL,  OP_NOP,  0LL);    /* sdata,wdata */
          // exe(OP_FMA,      &r19,  r14,  EXP_H3210, r17, EXP_H3210, r18, EXP_H3210, OP_NOP,  0LL,  OP_NOP,  0LL);    /* sdata,wdata */
          // exe(OP_FMA,      &r24,  r19,  EXP_H3210, r22, EXP_H3210, r23, EXP_H3210, OP_NOP,  0LL,  OP_NOP,  0LL);    /* sdata,wdata */
          // exe(OP_FMA,      &r32,  r24,  EXP_H3210, r27, EXP_H3210, r28, EXP_H3210, OP_NOP,  0LL,  OP_NOP,  0LL);    /* sdata,wdata */    
          // exe(OP_FAD, &r02, r32, EXP_H3232, r32, EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);          



  //         mop(OP_LDR,  0, &BR[32][0][1], src0_row_base_p8[6], (Ull)iofs, MSK_W1,src0_row, SRC0_ROW_LEN, 0, Force0, (Ull)NULL, SRC0_ROW_LEN);
  //         mop(OP_LDR,  3, &BR[32][0][0], src0_row_base_p0[6], (Ull)iofs, MSK_W1,src0_row, SRC0_ROW_LEN, 0, Force0, (Ull)NULL, SRC0_ROW_LEN);
  //         mop(OP_LDR,  0, &BR[32][1][1], src0_row_base_p8[7], (Ull)iofs, MSK_W1,src0_row, SRC0_ROW_LEN, 0, Force0, (Ull)NULL, SRC0_ROW_LEN);
  //         mop(OP_LDR,  3, &BR[32][1][0], src0_row_base_p0[7], (Ull)iofs, MSK_W1,src0_row, SRC0_ROW_LEN, 0, Force0, (Ull)NULL, SRC0_ROW_LEN);

  //         mop(OP_LDR,  0, &BR[33][0][1], src1_col_base_p8[6], (Ull)cofs, MSK_W1,i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)NULL, SRC1_COL_LEN_TOTAL);
  //         mop(OP_LDR,  3, &BR[33][0][0], src1_col_base_p0[6], (Ull)cofs, MSK_W1,i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)NULL, SRC1_COL_LEN_TOTAL);
  //         mop(OP_LDR,  0, &BR[33][1][1], src1_col_base_p8[7], (Ull)cofs, MSK_W1,i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)NULL, SRC1_COL_LEN_TOTAL);
  //         mop(OP_LDR,  3, &BR[33][1][0], src1_col_base_p0[7], (Ull)cofs, MSK_W1,i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)NULL, SRC1_COL_LEN_TOTAL);
          
  //         exe(OP_NOP,     &r10, BR[32][0][0], EXP_H3210, 0LL, EXP_H3210, 0LL, EXP_H3210, OP_AND,     0x0000ffff0000ffffLL, OP_SLL, 2LL);
  //         exe(OP_NOP,     &r11, BR[33][0][0], EXP_H3210, 0LL, EXP_H3210, 0LL, EXP_H3210, OP_AND,     0x0000ffff0000ffffLL, OP_SLL, 2LL);
  //         exe(OP_NOP,     &r15, BR[32][0][0], EXP_H3210, 0LL, EXP_H3210, 0LL, EXP_H3210, OP_AND,     0xffff0000ffff0000LL, OP_SRL, 14LL);
  //         exe(OP_NOP,     &r16, BR[33][0][0], EXP_H3210, 0LL, EXP_H3210, 0LL, EXP_H3210, OP_AND,     0xffff0000ffff0000LL, OP_SRL, 14LL);
          

  //         exe(OP_NOP,     &r20, BR[32][1][0], EXP_H3210, 0LL, EXP_H3210, 0LL, EXP_H3210, OP_AND,     0x0000ffff0000ffffLL, OP_SLL, 2LL);
  //         exe(OP_NOP,     &r21, BR[33][1][0], EXP_H3210, 0LL, EXP_H3210, 0LL, EXP_H3210, OP_AND,     0x0000ffff0000ffffLL, OP_SLL, 2LL);
  //         exe(OP_NOP,     &r25, BR[32][1][0], EXP_H3210, 0LL, EXP_H3210, 0LL, EXP_H3210, OP_AND,     0xffff0000ffff0000LL, OP_SRL, 14LL);
  //         exe(OP_NOP,     &r26, BR[33][1][0], EXP_H3210, 0LL, EXP_H3210, 0LL, EXP_H3210, OP_AND,     0xffff0000ffff0000LL, OP_SRL, 14LL);


  //         // printf("BR[3][0][0]=%016llx\n", BR[3][0][0]);
  //         //1,2
  //         mop(OP_LDWR, 3, &BR[35][0][1], (Ull)i_f16[LANE], (Ull)r10, MSK_W0, (Ull)i_f16[LANE], 65536, 0, 0, (Ull)NULL, 65536);
  //         mop(OP_LDWR, 3, &BR[35][1][1], (Ull)i_f16[LANE], (Ull)r10, MSK_W1, (Ull)i_f16[LANE], 65536, 0, 0, (Ull)NULL, 65536); 
  //         mop(OP_LDWR, 3, &BR[35][2][1], (Ull)i_f16[LANE], (Ull)r11, MSK_W0, (Ull)i_f16[LANE], 65536, 0, 0, (Ull)NULL, 65536);
  //         mop(OP_LDWR, 3, &BR[35][3][1], (Ull)i_f16[LANE], (Ull)r11, MSK_W1, (Ull)i_f16[LANE], 65536, 0, 0, (Ull)NULL, 65536);
  //         // printf("BR[5][0][1]=%016llx, BR[5][1][1]=%016llx, BR[5][2][1]=%016llx, BR[5][3][1]=%016llx\n", BR[5][0][1], BR[5][1][1], BR[5][2][1], BR[5][3][1]);

          
  //         exe(OP_CMOV,    &r12,   0x0000000000000001LL, EXP_H3210 ,BR[35][0][1],   EXP_H1010, BR[35][1][1],  EXP_H1010, OP_NOP,  0LL,          OP_NOP,   0LL);
  //         exe(OP_CMOV,    &r13,   0x0000000000000001LL, EXP_H3210 ,BR[35][2][1],   EXP_H1010, BR[35][3][1],  EXP_H1010, OP_NOP,  0LL,          OP_NOP,   0LL);
  //         // printf("r12=%016llx, r13=%016llx\n", r12, r13);

  //         mop(OP_LDWR, 3, &BR[36][0][1], (Ull)i_f16[LANE], (Ull)r15, MSK_W0, (Ull)i_f16[LANE], 65536, 0, 0, (Ull)NULL, 65536);
  //         mop(OP_LDWR, 3, &BR[36][1][1], (Ull)i_f16[LANE], (Ull)r15, MSK_W1, (Ull)i_f16[LANE], 65536, 0, 0, (Ull)NULL, 65536); 
  //         mop(OP_LDWR, 3, &BR[36][2][1], (Ull)i_f16[LANE], (Ull)r16, MSK_W0, (Ull)i_f16[LANE], 65536, 0, 0, (Ull)NULL, 65536);
  //         mop(OP_LDWR, 3, &BR[36][3][1], (Ull)i_f16[LANE], (Ull)r16, MSK_W1, (Ull)i_f16[LANE], 65536, 0, 0, (Ull)NULL, 65536);
  //         // printf("BR[6][0][1]=%016llx, BR[6][1][1]=%016llx, BR[6][2][1]=%016llx, BR[6][3][1]=%016llx\n", BR[6][0][1], BR[6][1][1], BR[6][2][1], BR[6][3][1]);

  //         exe(OP_CMOV,    &r17,   0x0000000000000001LL, EXP_H3210 ,BR[36][0][1],   EXP_H1010, BR[36][1][1],  EXP_H1010, OP_NOP,  0LL,          OP_NOP,   0LL);
  //         exe(OP_CMOV,    &r18,   0x0000000000000001LL, EXP_H3210 ,BR[36][2][1],   EXP_H1010, BR[36][3][1],  EXP_H1010, OP_NOP,  0LL,          OP_NOP,   0LL);
        

  //         //3,4
  //         mop(OP_LDWR, 3, &BR[37][0][1], (Ull)i_f16[LANE], (Ull)r20, MSK_W0, (Ull)i_f16[LANE], 65536, 0, 0, (Ull)NULL, 65536);
  //         mop(OP_LDWR, 3, &BR[37][1][1], (Ull)i_f16[LANE], (Ull)r20, MSK_W1, (Ull)i_f16[LANE], 65536, 0, 0, (Ull)NULL, 65536); 
  //         mop(OP_LDWR, 3, &BR[37][2][1], (Ull)i_f16[LANE], (Ull)r21, MSK_W0, (Ull)i_f16[LANE], 65536, 0, 0, (Ull)NULL, 65536);
  //         mop(OP_LDWR, 3, &BR[37][3][1], (Ull)i_f16[LANE], (Ull)r21, MSK_W1, (Ull)i_f16[LANE], 65536, 0, 0, (Ull)NULL, 65536);
  //         // printf("BR[5][0][1]=%016llx, BR[5][1][1]=%016llx, BR[5][2][1]=%016llx, BR[5][3][1]=%016llx\n", BR[5][0][1], BR[5][1][1], BR[5][2][1], BR[5][3][1]);

          
  //         exe(OP_CMOV,    &r22,   0x0000000000000001LL, EXP_H3210 ,BR[37][0][1],   EXP_H1010, BR[37][1][1],  EXP_H1010, OP_NOP,  0LL,          OP_NOP,   0LL);
  //         exe(OP_CMOV,    &r23,   0x0000000000000001LL, EXP_H3210 ,BR[37][2][1],   EXP_H1010, BR[37][3][1],  EXP_H1010, OP_NOP,  0LL,          OP_NOP,   0LL);
  //         // printf("r12=%016llx, r13=%016llx\n", r12, r13);

  //         mop(OP_LDWR, 3, &BR[38][0][1], (Ull)i_f16[LANE], (Ull)r25, MSK_W0, (Ull)i_f16[LANE], 65536, 0, 0, (Ull)NULL, 65536);
  //         mop(OP_LDWR, 3, &BR[38][1][1], (Ull)i_f16[LANE], (Ull)r25, MSK_W1, (Ull)i_f16[LANE], 65536, 0, 0, (Ull)NULL, 65536); 
  //         mop(OP_LDWR, 3, &BR[38][2][1], (Ull)i_f16[LANE], (Ull)r26, MSK_W0, (Ull)i_f16[LANE], 65536, 0, 0, (Ull)NULL, 65536);
  //         mop(OP_LDWR, 3, &BR[38][3][1], (Ull)i_f16[LANE], (Ull)r26, MSK_W1, (Ull)i_f16[LANE], 65536, 0, 0, (Ull)NULL, 65536);
  //         // printf("BR[6][0][1]=%016llx, BR[6][1][1]=%016llx, BR[6][2][1]=%016llx, BR[6][3][1]=%016llx\n", BR[6][0][1], BR[6][1][1], BR[6][2][1], BR[6][3][1]);

  //         exe(OP_CMOV,    &r27,   0x0000000000000001LL, EXP_H3210 ,BR[38][0][1],   EXP_H1010, BR[38][1][1],  EXP_H1010, OP_NOP,  0LL,          OP_NOP,   0LL);
  //         exe(OP_CMOV,    &r28,   0x0000000000000001LL, EXP_H3210 ,BR[38][2][1],   EXP_H1010, BR[38][3][1],  EXP_H1010, OP_NOP,  0LL,          OP_NOP,   0LL);

  //         exe(OP_FMA,      &r14,  r32,    EXP_H3210, r12, EXP_H3210, r13, EXP_H3210, OP_NOP,  0LL,  OP_NOP,  0LL);    /* sdata,wdata */
  //         exe(OP_FMA,      &r19,  r14,  EXP_H3210, r17, EXP_H3210, r18, EXP_H3210, OP_NOP,  0LL,  OP_NOP,  0LL);    /* sdata,wdata */
  //         exe(OP_FMA,      &r24,  r19,  EXP_H3210, r22, EXP_H3210, r23, EXP_H3210, OP_NOP,  0LL,  OP_NOP,  0LL);    /* sdata,wdata */
  //         exe(OP_FMA,      &r03,  r24,  EXP_H3210, r27, EXP_H3210, r28, EXP_H3210, OP_NOP,  0LL,  OP_NOP,  0LL);    /* sdata,wdata */    
  //         exe(OP_FAD, &r02, r03, EXP_H3232, r03, EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);          

#endif






#if 0
          exe(OP_FMA,      &r14,  0,  EXP_H3210, r12, EXP_H3210, r13, EXP_H3210, OP_NOP,  0LL,  OP_NOP,  0LL);    /* sdata,wdata */
          exe(OP_FMA,      &r19,  0,  EXP_H3210, r17, EXP_H3210, r18, EXP_H3210, OP_NOP,  0LL,  OP_NOP,  0LL);    /* sdata,wdata */
          exe(OP_FMA,      &r20,  r14,  EXP_H3210, r22, EXP_H3210, r23, EXP_H3210, OP_NOP,  0LL,  OP_NOP,  0LL);    /* sdata,wdata */
          exe(OP_FMA,      &r21,  r19,  EXP_H3210, r27, EXP_H3210, r28, EXP_H3210, OP_NOP,  0LL,  OP_NOP,  0LL);    /* sdata,wdata */
          // printf("r20=%016llx\n", r20);
#endif

#if 0 //for debug
          // printf("BR[5][0][1]=%016llx, BR[5][1][1]=%016llx, BR[5][2][1]=%016llx, BR[5][3][1]=%016llx\n", BR[5][0][1], BR[5][1][1], BR[5][2][1], BR[5][3][1]);
          // exe(OP_FML,      &r12, BR[5][0][1], EXP_H3210, BR[5][1][1], EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);
          // exe(OP_FMA,      &r14,  0,  EXP_H3210, BR[5][0][0], EXP_H3210, BR[5][2][0], EXP_H3210, OP_NOP,  0LL,  OP_NOP,  0LL);    /* sdata,wdata */
          // printf("r14=%016llx\n", r14);

          // float val0 = GGML_FP16_TO_FP32(*p_src01);
          // float val1 = GGML_FP16_TO_FP32(*p_src11);
          // printf("  C float (val0): %f, Sim float (br): %f\n", val0, br_as_float);
          // printf("  Sim float (r01)   : %f\n", *(float*)&r01);
          
         
          // exe(OP_NOP,     &r04, BR[2][0][1], EXP_H3210, 0LL, EXP_H3210, 0LL, EXP_H3210, OP_AND, 0x000000000000ffffLL, OP_SLL, 2LL);
          // mop(OP_LDWR, 3, &BR[4][0][1], (Ull)i_f16[LANE], (Ull)r04, MSK_W0, (Ull)i_f16[LANE], 65536, 0, 0, (Ull)NULL, 65536);
          
          // printf("BR[3][0][0]=%016llx, *p_src11=%016llx\n", BR[3][0][0], *(Ull*)p_src11);
          
          // printf("BR[3][0][1]=%016llx, *p_src11=%016llx\n", BR[3][0][1], *(Ull*)p_src11);
          // printf("BR[4][0][1]=%lld\n", BR[4][0][1]);


          
          // ggml_fp16_t* p_src01 = (ggml_fp16_t*)((char*)src0_row + (iofs>>32));
          // ggml_fp16_t* p_src11 = (ggml_fp16_t*)((char*)src1_col + (cofs>>32));
          float val0 = GGML_FP16_TO_FP32(*p_src01);
          float val1 = GGML_FP16_TO_FP32(*p_src11);
           *(float*)&r01 = val0 * val1;
          //  printf("BR[2][0][0]=%016llx, *p_src01=%016llx\n", BR[2][0][0], *(Ull*)p_src01);
          //  printf("BR[5][0][1]=%016llx, BR[5][1][1]=%016llx, BR[5][2][1]=%016llx, BR[5][3][1]=%016llx\n", BR[5][0][1], BR[5][1][1], BR[5][2][1], BR[5][3][1]);
          // printf("DEBUG: r01=0x%08x, r14=0x%08x\n", *(unsigned int*)&r01, *(unsigned int*)&r14);
#endif

          

#if 1              

            
            exe(OP_NOP, &AR[40][0], 0LL, EXP_H3210, 0LL, EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL); 
            // exe(OP_NOP, &AR[38][0], 0LL, EXP_H3210, 0LL, EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL); 
            mop(OP_LDWR, 1, &r00, dst_col, oofs, MSK_W0,  i_m0C_TOP_IMAP[0][LANE], dst_total_elements, 0, Force2, (Ull)NULL,dst_total_elements);
            exe(OP_FAD, &r00, INIT0 ? r00: r00, EXP_H3210, r31, EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);
            mop(OP_STWR, 1, &r00, oofs, dst_col, MSK_D0, i_m0C_TOP_IMAP[0][LANE], dst_total_elements, 0, Force2, (Ull)NULL,dst_total_elements);
           
#endif
            }
#if 0            
            dst_col[blck_00dIMAP - LOOP1 -1] = sumf2;
            // if (dst_col[blck_00dIMAP - LOOP1 -1] != sumf1) {
            //     printf("DEBUG: dst_col[%lld]=%f, sumf1=%f (NOT MATCH)\n", blck_00dIMAP - LOOP1 -1, dst_col[blck_00dIMAP - LOOP1 -1], sumf1);
            // }
#endif
        }
         }
//EMAX5A end

          if (Force0) Force0 = 0; /* reset sdat to LMM */
          if (Force1) Force1 = 0; /* reset wdat to LMM */
          if (Force2) Force2 = 0; /* reset dst  to LMM */
    }
  }
//EMAX5A drain_dirty_lmm


   
  monitor_time_end(THREAD, IMAX_TERM_1);
#endif

    // // =========================================================================================
    // // STEP 3: データ書き出し (CPYOUT) - 変更なし
    // // =========================================================================================
  // monitor_time_start(THREAD, IMAX_CPYOUT);
  //   if (!((Ull)DST_COL_TOP & 63) && !((Ull)i_m0C[LANE] & 63) && DST_COL_LENdIMAP == 16 && IMAP == 1) { // 64B aligned
  //     for (int i=0; i<IR1_LOOPS; i++) { /* stride */
	// Dll *dst = (int*)DST_COL_TOP+i*nb1/sizeof(int);
	// Dll *src = (int*)i_m0C[LANE]+i*16;
	// *dst++ = *src++; /* 4word */
	// *dst++ = *src++; /* 4word */
	// *dst++ = *src++; /* 4word */
	// *dst++ = *src++; /* 4word */
  //     }
  //   }
  //   else
  //     xmax_cpyout(4, DST_COL_TOP, 1, nb1/sizeof(float), i_m0C[LANE], (Ull)IR1_LOOPS, (Ull)DST_COL_LENdIMAP, IMAP); /* stride */
  //   monitor_time_end(THREAD, IMAX_CPYOUT);
  //   // Ull   DST_COL_TOP        = (float*)((char*)dst->data + (i11_top * nb1 + i12_top * nb2 + i13_top * nb3)) + ir0_start;

    monitor_time_start(THREAD, IMAX_CPYOUT);
    
    float* src_buffer = (float*)i_m0C[LANE];
    const int64_t elements_per_vector = ir0_end - ir0_start;
    const size_t bytes_per_vector = elements_per_vector * sizeof(float);

    for (int64_t ir1 = ir1_start; ir1 < ir1_end; ++ir1) {
        float* src_ptr = src_buffer + (ir1 - ir1_start) * elements_per_vector;

        const int64_t i13 = (ir1 / (ne12 * ne1));
        const int64_t i12 = (ir1 - i13 * ne12 * ne1) / ne1;
        const int64_t i11 = (ir1 - i13 * ne12 * ne1 - i12 * ne1);
        
        float* dst_ptr = (float*)((char*)dst->data + i11 * nb1 + i12 * nb2 + i13 * nb3) + ir0_start;
        memcpy(dst_ptr, src_ptr, bytes_per_vector);
   
    }
    monitor_time_end(THREAD, IMAX_CPYOUT);


}
}

void imax_compute_forward_mul_mat_one_chunk_q2_k(struct th_inference_args *args)
{
  int                                THREAD       = args->thid; /* < NTHREAD vsim.cpp NTHREAD=2                  */
  int                                LANE         = args->thid; /* < NLANE   emax7.h  init_xmax(){NLANE=NTHREAD} */
  struct ggml_tensor *               dst          = args->dst;
  const int64_t                      num_rows_per_vec_dot = args->num_rows_per_vec_dot;
  const int64_t                      ir0_start    = args->ir0_start;
  const int64_t                      ir0_end      = args->ir0_end;
  const int64_t                      ir1_start    = args->ir1_start;
  const int64_t                      ir1_end      = args->ir1_end;
  const struct ggml_tensor *         src0         = args->src0;
  const struct ggml_tensor *         src1         = args->src1;
  const enum ggml_type               type         = args->type; /* 0:F32 1:F16 8:Q8_0 10:Q2_K 11:Q3_K 14:Q6_K */
  const bool                         src1_cont    = args->src1_cont;
  ggml_vec_dot_t const               vec_dot      = args->vec_dot;
  enum ggml_type const               vec_dot_type = args->vec_dot_type;
  const void *                       wdata        = args->wdata;
  const size_t                       row_size     = args->row_size;
  const int64_t                      r2           = args->r2;
  const int64_t                      r3           = args->r3;
  const int64_t                      blck_0       = args->blck_0;
  const int64_t                      blck_1       = args->blck_1;
  const size_t                       src1_col_stride = args->src1_col_stride;
  int   i;
  float tmp[32];
  GGML_TENSOR_BINARY_OP_LOCALS
  int       n  = ne00;

  if (1) { /* check LMM_SIZE, and start ARM if NG */
    monitor_time_start(THREAD, IMAX_COMPUTE_FORWARD_MUL_MAT_ONE_CHUNK_Q2K_ARM); /* Nakashima */
    for (int64_t iir1 = ir1_start; iir1 < ir1_end; iir1 += blck_1) { /* weight top loop */
      for (int64_t iir0 = ir0_start; iir0 < ir0_end; iir0 += blck_0) { /* sdata top loop */
	for (int64_t ir1 = iir1; ir1 < iir1 + blck_1 && ir1 < ir1_end; ir1 += num_rows_per_vec_dot) { /* weight sub loop */
	  const int64_t i13 = (ir1 / (ne12 * ne1));
	  const int64_t i12 = (ir1 - i13 * ne12 * ne1) / ne1;
	  const int64_t i11 = (ir1 - i13 * ne12 * ne1 - i12 * ne1);
          const int64_t i03 = i13 / r3;
          const int64_t i02 = i12 / r2;
	  const int64_t i1 = i11;
	  const int64_t i2 = i12;
	  const int64_t i3 = i13;

	  const char * src0_row = (const char*)src0->data + (0 + i02 * nb02 + i03 * nb03);
	  const char * src1_col = (const char*)wdata + (src1_cont || src1->type != vec_dot_type ? (i11 + i12 * ne11 + i13 * ne12 * ne11) * row_size
	                                                                                        : (i11 * nb11 + i12 * nb12 + i13 * nb13));
	  float * dst_col = (float*)((char*)dst->data + (i1 * nb1 + i2 * nb2 + i3 * nb3));

        //printf("src0_row=%16.16llx ir0=%16.16llx-%16.16llx (step=%16.16llx) ne00=%08.08x nb01=%08.08x\n", src0_row, iir0, iir0 + blck_0, num_rows_per_vec_dot, (int)ne00, (int)nb01);
	  for (int64_t ir0 = iir0; ir0 < iir0 + blck_0 && ir0 < ir0_end; ir0 += num_rows_per_vec_dot) { /* ne00=4096(0x1000) 4096/32*34=0x1100??��?,0x1100B??????????? */
	    vec_dot(ne00, &tmp[ir0 - iir0], (num_rows_per_vec_dot > 1 ? 16 : 0), src0_row + ir0 * nb01, (num_rows_per_vec_dot > 1 ? nb01 : 0), src1_col, (num_rows_per_vec_dot > 1 ? src1_col_stride : 0), num_rows_per_vec_dot);

	//  float sumf = 0;
	//  for (int i = 0; i < nb; ++i) {
	//    const uint8_t * q2 = x[i].qs;
	//    const  int8_t * q8 = y[i].qs;
	//    const uint8_t * sc = x[i].scales;
	//    int summs = 0;
	//    for (int j = 0; j < 16; ++j) {
	//      summs += y[i].bsums[j] * (sc[j] >> 4);
	//    }
	//    const float dall = y[i].d * GGML_FP16_TO_FP32(x[i].d);
	//    const float dmin = y[i].d * GGML_FP16_TO_FP32(x[i].dmin);
	//    int isum = 0;
	//    int is = 0;
	//    int d;
	//    for (int k = 0; k < QK_K/128; ++k) {
	//      int shift = 0;
	//      for (int j = 0; j < 4; ++j) {
	//        d = sc[is++] & 0xF;
	//        int isuml = 0;
	//        for (int l =  0; l < 16; ++l) isuml += q8[l] * ((q2[l] >> shift) & 3);
	//        isum += d * isuml;
	//        d = sc[is++] & 0xF;
	//        isuml = 0;
	//        for (int l = 16; l < 32; ++l) isuml += q8[l] * ((q2[l] >> shift) & 3);
	//        isum += d * isuml;
	//        shift += 2;
	//        q8 += 32;
	//      }
	//      q2 += 32;
	//    }
	//    sumf += dall * isum - dmin * summs;
	//  }
	//  tmp[ir0 - iir0] = sumf;
	    
	  }
	  monitor_time_start(THREAD, ARM_MEMCPY); /* Nakashima */
	  for (int cn = 0; cn < num_rows_per_vec_dot; ++cn) /* num_rows_per_vec_dot=1 */
	    memcpy(&dst_col[iir0 + cn * nb1 / nb0], tmp + (cn * 16), (MIN(iir0 + blck_0, ir0_end) - iir0) * sizeof(float));
	  monitor_time_end(THREAD, ARM_MEMCPY); /* Nakashima */
	}
      }
    }
    monitor_time_end(THREAD, IMAX_COMPUTE_FORWARD_MUL_MAT_ONE_CHUNK_Q2K_ARM); /* Nakashima */
  }
}

void imax_compute_forward_mul_mat_one_chunk_q3_k(struct th_inference_args *args)
{
  int                                THREAD       = args->thid; /* < NTHREAD vsim.cpp NTHREAD=2                  */
  int                                LANE         = args->thid; /* < NLANE   emax7.h  init_xmax(){NLANE=NTHREAD} */
  struct ggml_tensor *               dst          = args->dst;
  const int64_t                      num_rows_per_vec_dot = args->num_rows_per_vec_dot;
  const int64_t                      ir0_start    = args->ir0_start;
  const int64_t                      ir0_end      = args->ir0_end;
  const int64_t                      ir1_start    = args->ir1_start;
  const int64_t                      ir1_end      = args->ir1_end;
  const struct ggml_tensor *         src0         = args->src0;
  const struct ggml_tensor *         src1         = args->src1;
  const enum ggml_type               type         = args->type; /* 0:F32 1:F16 8:Q8_0 10:Q2_K 11:Q3_K 14:Q6_K */
  const bool                         src1_cont    = args->src1_cont;
  ggml_vec_dot_t const               vec_dot      = args->vec_dot;
  enum ggml_type const               vec_dot_type = args->vec_dot_type;
  const void *                       wdata        = args->wdata;
  const size_t                       row_size     = args->row_size;
  const int64_t                      r2           = args->r2;
  const int64_t                      r3           = args->r3;
  const int64_t                      blck_0       = args->blck_0;
  const int64_t                      blck_1       = args->blck_1;
  const size_t                       src1_col_stride = args->src1_col_stride;
  int   i, j;
  float tmp[32];
  GGML_TENSOR_BINARY_OP_LOCALS
  int       n  = ne00;
  const int nb = n / QK_K; /* 16,43 */

  Ull   IIR1_LOOPS         = (ir1_end-ir1_start)/blck_1;                         /* ??iir1-loop???                  */
  Ull   IIR0_LOOPS         = (ir0_end-ir0_start)/blck_0;                         /* ??iir0-loop???                  */
  Ull   IR1_LOOPS          = MIN(ir1_start+blck_1,ir1_end)-ir1_start;            /* ??ir1-loop???                   */
  Ull   SRC0_ROW_LEN       = sizeof(block_q3_K)*nb*blck_0*IIR0_LOOPS/sizeof(int);/* ??iir0-loop????                */
  Ull   SRC1_COL_LEN       = (sizeof(block_q8_K)*nb+3)/sizeof(int);              /* ??ir1-loop????                 */
  Ull   SRC1_COL_LEN_TOTAL = SRC1_COL_LEN*IR1_LOOPS;                             /* ??ir1-loop????                 */
  Ull   DST_COL_LEN        = blck_0*IIR0_LOOPS;                                  /* ??ir1-loop????????(nb1-byte*iir0-loop) */
  Ull   DST_COL_LEN_TOTAL  = DST_COL_LEN*IR1_LOOPS;                              /* ??ir1-loop????????(nb1-byte*iir0-loop) */

// printf("src0_row=%16.16llx src1_col=%16.16llx dst_col=%16.16llx\n", (const char*)src0->data, (const char*)wdata, (float*)((char*)dst->data));
// #if defined(IMAX_DEBUG)
  // if(1) { /* DEBUG */
// #else
// printf("nb=%d\n", nb);
// printf("SRC0_ROW_SIZE=%dKB\n", SRC0_ROW_LEN*sizeof(int)/1024);
// printf("SRC1_COL_LEN_TOTAL=%dKB\n", SRC1_COL_LEN_TOTAL*sizeof(int)/1024);
// printf("ir0_end - ir0_start=%d\n", ir0_end - ir0_start);
  if (SRC0_ROW_LEN >512*1024/sizeof(int) || ((ir0_end - ir0_start) % blck_0) || num_rows_per_vec_dot != 1) { /* check LMM_SIZE, and start ARM if NG */
 //なぜこの分岐なのか表示

    // #endif
    // if(1) {
      monitor_time_start(THREAD, IMAX_COMPUTE_FORWARD_MUL_MAT_ONE_CHUNK_Q3K_ARM); /* Nakashima */
    for (int64_t iir1 = ir1_start; iir1 < ir1_end; iir1 += blck_1) { /* weight top loop, decoedはGRMVのため1 */
      for (int64_t iir0 = ir0_start; iir0 < ir0_end; iir0 += blck_0) { /* sdata top loop */
	for (int64_t ir1 = iir1; ir1 < iir1 + blck_1 && ir1 < ir1_end; ir1 += num_rows_per_vec_dot) { /* weight sub loop */
	  const int64_t i13 = (ir1 / (ne12 * ne1));
	  const int64_t i12 = (ir1 - i13 * ne12 * ne1) / ne1;
	  const int64_t i11 = (ir1 - i13 * ne12 * ne1 - i12 * ne1);
          const int64_t i03 = i13 / r3;
          const int64_t i02 = i12 / r2;
	  const int64_t i1 = i11;
	  const int64_t i2 = i12;
	  const int64_t i3 = i13;

	  const char * src0_row = (const char*)src0->data + (0 + i02 * nb02 + i03 * nb03);
	  const char * src1_col = (const char*)wdata + (src1_cont || src1->type != vec_dot_type ? (i11 + i12 * ne11 + i13 * ne12 * ne11) * row_size
	                                                                                        : (i11 * nb11 + i12 * nb12 + i13 * nb13));
	  float * dst_col = (float*)((char*)dst->data + (i1 * nb1 + i2 * nb2 + i3 * nb3));

        //printf("src0_row=%16.16llx ir0=%16.16llx-%16.16llx (step=%16.16llx) ne00=%08.08x nb01=%08.08x\n", src0_row, iir0, iir0 + blck_0, num_rows_per_vec_dot, (int)ne00, (int)nb01);
	  for (int64_t ir0 = iir0; ir0 < iir0 + blck_0 && ir0 < ir0_end; ir0 += num_rows_per_vec_dot) { /* ne00=4096(0x1000) 4096/32*34=0x1100??��?,0x1100B??????????? */
	    vec_dot(ne00, &tmp[ir0 - iir0], (num_rows_per_vec_dot > 1 ? 16 : 0), src0_row + ir0 * nb01, (num_rows_per_vec_dot > 1 ? nb01 : 0), src1_col, (num_rows_per_vec_dot > 1 ? src1_col_stride : 0), num_rows_per_vec_dot);

	//  int8_t  aux8[QK_K];
	//  int16_t aux16[8];
	//  float   sums [8];
	//  int32_t aux32[8];
	//  memset(sums, 0, 8*sizeof(float));
	//  uint32_t auxs[4];
	//  const int8_t * scales = (const int8_t*)auxs;
	//  float sumf = 0;
	//  for (int i = 0; i < nb; ++i) {
	//    const uint8_t * restrict q3 = x[i].qs;
	//    const uint8_t * restrict hm = x[i].hmask;
	//    const  int8_t * restrict q8 = y[i].qs;
	//    memset(aux32, 0, 8*sizeof(int32_t));
	//    int8_t * restrict a = aux8;
	//    uint8_t m = 1;
	//    for (int j = 0; j < QK_K; j += 128) {
	//	for (int l = 0; l < 32; ++l) a[l] = q3[l] & 3;
	//	for (int l = 0; l < 32; ++l) a[l] -= (hm[l] & m ? 0 : 4);
	//	a += 32; m <<= 1;
	//	for (int l = 0; l < 32; ++l) a[l] = (q3[l] >> 2) & 3;
	//	for (int l = 0; l < 32; ++l) a[l] -= (hm[l] & m ? 0 : 4);
	//	a += 32; m <<= 1;
	//	for (int l = 0; l < 32; ++l) a[l] = (q3[l] >> 4) & 3;
	//	for (int l = 0; l < 32; ++l) a[l] -= (hm[l] & m ? 0 : 4);
	//	a += 32; m <<= 1;
	//	for (int l = 0; l < 32; ++l) a[l] = (q3[l] >> 6) & 3;
	//	for (int l = 0; l < 32; ++l) a[l] -= (hm[l] & m ? 0 : 4);
	//	a += 32; m <<= 1;
	//	q3 += 32;
	//    }
	//    a = aux8;
	//    memcpy(auxs, x[i].scales, 12);
	//    uint32_t tmp = auxs[2];
	//    auxs[2] = ((auxs[0] >> 4) & kmask2) | (((tmp >> 4) & kmask1) << 4);
	//    auxs[3] = ((auxs[1] >> 4) & kmask2) | (((tmp >> 6) & kmask1) << 4);
	//    auxs[0] = (auxs[0] & kmask2) | (((tmp >> 0) & kmask1) << 4);
	//    auxs[1] = (auxs[1] & kmask2) | (((tmp >> 2) & kmask1) << 4);
	//    for (int j = 0; j < QK_K/16; ++j) {
	//	for (int l = 0; l < 8; ++l) aux16[l] = q8[l] * a[l];
	//	for (int l = 0; l < 8; ++l) aux32[l] += (scales[j] - 32) * aux16[l];
	//	q8 += 8; a += 8;
	//	for (int l = 0; l < 8; ++l) aux16[l] = q8[l] * a[l];
	//	for (int l = 0; l < 8; ++l) aux32[l] += (scales[j] - 32) * aux16[l];
	//	q8 += 8; a += 8;
	//    }
	//    const float d = GGML_FP16_TO_FP32(x[i].d) * y[i].d;
	//    for (int l = 0; l < 8; ++l) sums[l] += d * aux32[l];
	//  }
	//  for (int l = 0; l < 8; ++l) sumf += sums[l];
	//  tmp[ir0 - iir0] = sumf;
	    
	  }
	  monitor_time_start(THREAD, ARM_MEMCPY); /* Nakashima */
	  for (int cn = 0; cn < num_rows_per_vec_dot; ++cn) /* num_rows_per_vec_dot=1 */

	    memcpy(&dst_col[iir0 + cn * nb1 / nb0], tmp + (cn * 16), (MIN(iir0 + blck_0, ir0_end) - iir0) * sizeof(float));
	  monitor_time_end(THREAD, ARM_MEMCPY); /* Nakashima */

    
	}
      }
    }
   
    monitor_time_end(THREAD, IMAX_COMPUTE_FORWARD_MUL_MAT_ONE_CHUNK_Q3K_ARM); /* Nakashima */
  }
  else { /* IMAX */
#undef  IMAP
#undef  NCHIP
#define IMAP  1
#define NCHIP 1
    Ull   CHIP, rofs, cofs, xofs, yofs, iofs, oofs;
    Ull   LOOP1, LOOP0;
    Ull   INIT1, INIT0;
    Ull   AR[64][4];                     /* output of EX     in each unit */
    Ull   BR[64][4][4];                  /* output registers in each unit */
    Ull   r00, r01, r02, r03, r04, r05, r06, r07, r08, r09, r10, r11, r12, r13, r14, r15;
    Ull   r16, r17, r18, r19, r20, r21, r22, r23, r24, r25, r26, r27, r28, r29, r30, r31;
    Ull   cc0, cc1, cc2, cc3, ex0, ex1, out0, out1, out2, out10;
    Ull   Force0, Force1, Force2; /* force to LMM */

    Ull   MNB01_M4    = (0LL-nb01              )<<32|((0LL-sizeof(float))     &0xffffffffLL);
    Ull   MBKQ3_MBKQ8 = (0LL-sizeof(block_q3_K))<<32|((0LL-sizeof(block_q8_K))&0xffffffffLL);
    Ull   NB01_4      = (0LL+nb01              )<<32|((0LL+sizeof(float))     &0xffffffffLL);
    Ull   BKQ3_BKQ8   = (0LL+sizeof(block_q3_K))<<32|((0LL+sizeof(block_q8_K))&0xffffffffLL);

    const int64_t i13_top = (ir1_start          / (ne12 * ne1));          /* ==0 */
    const int64_t i12_top = (ir1_start - i13_top * ne12 * ne1) / ne1;     /* ==0 */
    const int64_t i11_top = (ir1_start - i13_top * ne12 * ne1 - i12_top * ne1);
    const int64_t i03_top = i13_top / r3;
    const int64_t i02_top = i12_top / r2;
    Ull   SRC0_ROW_TOP       = (const char*)src0->data  + (0 + i02_top * nb02 + i03_top * nb03) + ir0_start*nb01;
    Ull   SRC0_ROW_LENdIMAP  = SRC0_ROW_LEN/IMAP;
    Ull   i_m0A_TOP          = (const char*)i_m0A[LANE] + (0 + i02_top * nb02 + i03_top * nb03) + ir0_start*nb01;
    Ull   SRC1_COL_TOP       = (const char*)wdata       + (src1_cont || src1->type != vec_dot_type ? (i11_top + i12_top * ne11 + i13_top * ne12 * ne11) * row_size /* 4352(0x1100),11696(0x2db0) */
	                                                                                           : (i11_top * nb11 + i12_top * nb12 + i13_top * nb13));
    Ull   DST_COL_TOP        = (float*)((char*)dst->data + (i11_top * nb1 + i12_top * nb2 + i13_top * nb3)) + ir0_start;
    Ull   DST_COL_LENdIMAP   = DST_COL_LEN/IMAP;         /* TOTAL = [[blck_0(16) x IIR0_LOOPS(1,4)]/IMAP] x IIR1_LOOPS(2,1) x IMAP */
    Ull   DST_COL_LEN_TOTdIMAP = DST_COL_LEN_TOTAL/IMAP; /* TOTAL = [[blck_0(16) x IIR0_LOOPS(1,4)]/IMAP] x IIR1_LOOPS(2,1) x IMAP */
    Ull   i_m0C_TOP_IMAP[IMAP][EMAX_NLANE]; for (i=0; i<IMAP; i++) i_m0C_TOP_IMAP[i][LANE] = (Ull)i_m0C[LANE] + i*sizeof(float)*DST_COL_LEN_TOTdIMAP;
    // printf("imax_compute_forward_mul_mat_one_chunk_q3_k (IMAX path) - Thread %d, Lane %d\n", THREAD, LANE);
#if 0
    static Ull max_SRC0_ROW_LEN=0;
    static Ull max_SRC1_COL_LEN_TOTAL=0;
    static Ull max_DST_COL_LEN_TOTAL=0;
    if (max_SRC0_ROW_LEN       < SRC0_ROW_LEN)       { max_SRC0_ROW_LEN       = SRC0_ROW_LEN      ; printf("max_SRC0_ROW_LEN=%16.16llx\n",       max_SRC0_ROW_LEN); }
    if (max_SRC1_COL_LEN_TOTAL < SRC1_COL_LEN_TOTAL) { max_SRC1_COL_LEN_TOTAL = SRC1_COL_LEN_TOTAL; printf("max_SRC1_COL_LEN_TOTAL=%16.16llx\n", max_SRC1_COL_LEN_TOTAL); }
    if (max_DST_COL_LEN_TOTAL  < DST_COL_LEN_TOTAL)  { max_DST_COL_LEN_TOTAL  = DST_COL_LEN_TOTAL;  printf("max_DST_COL_LEN_TOTAL=%16.16llx\n",  max_DST_COL_LEN_TOTAL);  }
    /* max_SRC0_ROW_LEN      =0000000000001b80 */
    /* max_SRC0_ROW_LEN      =00000000000049e0 */
    /* max_SRC0_ROW_LEN      =0000000000006e00 */
    /* max_SRC0_ROW_LEN      =0000000000012780 */
    /* max_SRC1_COL_LEN_TOTAL=0000000000000920 */
    /* max_SRC1_COL_LEN_TOTAL=0000000000001886 */
    /* max_DST_COL_LEN_TOTAL =0000000000000020 */
    /* max_DST_COL_LEN_TOTAL =0000000000000040 */
#endif
    // monitor_time_start(THREAD, IMAX_CPYIN);
    int ctmp;
    if (src0_preloaded) { /* in init_xmax() */
      /* override i_m0A_TOP */
      i_m0A_TOP = i_m0A[0] + (SRC0_ROW_TOP - SRC0_ROW_TOP_DIRECT);
      // printf("skip\n");
      Force0=1; /* everytime new address for LMM */
    }
    else if (*(Ull*)i_m0A_TOP   == *(Ull*)SRC0_ROW_TOP) {
    //printf("%d. i_m0A_TOP:%16.16llx %16.16llx S0_TOP:%16.16llx %16.16llx reuse\n", THREAD, i_m0A_TOP, *(Ull*)i_m0A_TOP, SRC0_ROW_TOP, *(Ull*)SRC0_ROW_TOP);
      Force0=0;
    }
    else {
    //printf("%d. i_m0A_TOP:%16.16llx %16.16llx S0_TOP:%16.16llx %16.16llx new\n", THREAD, i_m0A_TOP, *(Ull*)i_m0A_TOP, SRC0_ROW_TOP, *(Ull*)SRC0_ROW_TOP);
      monitor_time_start(THREAD, IMAX_CPYIN_A_Q3K);
      xmax_cpyin(3,i_m0A_TOP,  &ctmp,SRC0_ROW_TOP,1,1,SRC0_ROW_LEN,1,1);
      // TOTAL_BUFFER_LOAD_SIZE += SRC0_ROW_LEN*sizeof(int);
      // Update max copy size for SRC0 in bytes
      // Ull current_copy_size_bytes = SRC0_ROW_LEN * sizeof(int);
      // if (max_SRC0_ROW_LEN_COPY_BYTES <= current_copy_size_bytes) {
      //   max_SRC0_ROW_LEN_COPY_BYTES = current_copy_size_bytes;
      //   printf("max_SRC0_ROW_LEN_COPY_BYTES=%d KB\n", max_SRC0_ROW_LEN_COPY_BYTES/1024);
      // }

      // count_cpyin_q3k(SRC0_ROW_LEN * sizeof(int));
      
      Force0=1; /* force sdat to LMM */
      monitor_time_end(THREAD, IMAX_CPYIN_A_Q3K);
      
      Force0=1; /* force sdat to LMM */
    }
    if (*(Ull*)i_m0B[LANE] == *(Ull*)SRC1_COL_TOP) {
    //printf("%d.B:%16.16llx reuse\n", THREAD, SRC1_COL_TOP);
      Force1=0;
    }
    else {
    //printf("%d.B:%16.16llx new\n", THREAD, SRC1_COL_TOP);
      monitor_time_start(THREAD, IMAX_CPYIN_B_Q3K);
      xmax_cpyin(3,i_m0B[LANE],&ctmp,SRC1_COL_TOP,1,1,SRC1_COL_LEN_TOTAL,1,1);
      TOTAL_BUFFER_LOAD_SIZE += SRC1_COL_LEN_TOTAL*sizeof(int);
      // Q3Kのデータ転送量をカウント
      // count_cpyin_q3k(SRC1_COL_LEN_TOTAL * sizeof(int));
      // Update max copy size for SRC1 in bytes
      // Ull current_copy_size_bytes = SRC1_COL_LEN_TOTAL * sizeof(int);
      // if (max_SRC1_COL_LEN_COPY_BYTES <= current_copy_size_bytes) {
      //   max_SRC1_COL_LEN_COPY_BYTES = current_copy_size_bytes;
      //   printf("max_SRC1_COL_LEN_COPY_BYTES=%d KB\n", max_SRC1_COL_LEN_COPY_BYTES/1024);
      // }
      
      Force1=1; /* force wdat to LMM */
      monitor_time_end(THREAD, IMAX_CPYIN_B_Q3K);
    }
    monitor_time_start(THREAD, IMAX_BZERO_Q3K);
    xmax_bzero(i_m0C[LANE], DST_COL_LEN_TOTAL);
    TOTAL_BUFFER_DRAIN_SIZE += DST_COL_LEN_TOTAL*sizeof(int);
    Force2 = 1; /* force dst  to LMM */
    monitor_time_end(THREAD, IMAX_BZERO_Q3K);
//  reset_nanosec(LANE);

///////////////////////////////////////////////////////////////////////IMAX????:????????///////////////////

    /*          <----------------------------------src0->data : 110B          x 16  x (16x256=4096) -------------------------------------->   */
    /*                                        cpyin(i_m0A, sizeof(block_q3_K) x nb  x     nr0(4096)                                           */
    /*          <----------------------------------SRC0_ROW_LEN-------------------------------------------------------------------------->    */
    /*          <---------------------nb01(1760,4730)--------------------->xofs=rofs+cofs(hi)   [            blck00dIMAP            ]         */
    /*          [[     110B      ] [     110B      ]     [     110B      ]]:nb(16,43)         x [[blck_0(16) x IIR0_LOOPS(1,4)]/IMAP]         */
    /* SRC0_ROW [i8x32][i8x64][i8x12]F16                                                                                                      */
    /* imax_compute_forward_mul_mat_one_chunk_q3_K()?��???????i_m0A?????��???????Force-load???(vsim??,LMM?????????Force????)    */
    
    /*          <----------------------------------src1->data : 292B          x 16 x (2) 0----------------------------------------------->    */
    /*                                        cpyin(i_m0B, sizeof(block_q8_K) x nb  x (2)                                                     */
    /*           <--------------------SRC1_COL_LEN_TOTAL-------------------------------------------------------------->                       */
    /*           <--------------------SRC1_COL_LEN_TOTAL------------------->                                                                  */
    /*            <----BKQ8------->cofs(hi)                                                                                                   */
    /*           [[     292B      ] [     292B      ]     [     292B      ]]:nb(16,43)                x IR1_LOOPS(2,1)                        */
    /* SRC1_COL  F32[i8x256][i16x16]                                                                                                          */
    /* imax_compute_forward_mul_mat_one_chunk_q3_K()?��??????????��?1?????Force-load???                                                 */
                       
    /*           <---------------------nb1/sizeof(int)-------------------------------------------------------------->:nb*32                   */
    /*           [                          4B                             ] x  [blck_0(16) x IIR0_LOOPS(1,4)] x IR1_LOOPS(2,1) x nb1/sizeof(int)*/
    /* DST_COL   [                         f32                             ]                         ]                                        */
    /* imax_compute_forward_mul_mat_one_chunk_q3_K()?��???????i_m0C???????��?1?????Force-load???                                      */
    
    /*           <-------------------------------------DST_COL_LEN_TOTAL--------------------------------------------------------------------> */
    /*           <-------------------------------------DST_COL_LENdIMAP---------------------------------------------------------->        */
    /*           <-------------------------------------DST_COL_LENdIMAP-------------------------------------------->                          */
    /*                                                                         [            blck_00dIMAP           ]                          */
    /*           [                          4B                             ] x [[blck_0(16) x IIR0_LOOPS(1,4)]/IMAP] x IIR1_LOOPS(2,1) x IMAP */
    /* i_m0C     [                         f32                             ]                                                                  */
    /* imax_compute_forward_mul_mat_one_chunk_q3_K()?��???????i_m0C???????��???????Force-load???                                     */

  //printf("th=%d ir1_start=%lld ir1_end=%lld SRC1_TOP=%16.16llx SRC1_LEN_TOTAL=%d IR1_LOOPS=%d ir0_start=%lld ir0_end=%lld SRC0_TOP=%16.16llx SRC0_LEN=%d IIR0_LOOPS=%d DST_TOP=%16.16llx DST_LEN_TOTAL=%d(dist=%d)\n", THREAD, ir1_start, ir1_end, SRC1_COL_TOP, (int)SRC1_COL_LEN_TOTAL, (int)IR1_LOOPS, ir0_start, ir0_end, SRC0_ROW_TOP, (int)SRC0_ROW_LEN, (int)IIR0_LOOPS, DST_COL_TOP, (int)DST_COL_LEN_TOTAL, (int)nb1);
    /* S1LEN_TOT=2336(292*16(nb)/4*2(ir1loop)),S0LEN=7040(110*16(nb)/4*16),DSTLEN_TOT=32(dist=16384) */
    for (int64_t iir1 = ir1_start; iir1 < ir1_end; iir1 += blck_1) { /* weight top loop */
      for (int64_t ir1 = iir1; ir1 < iir1 + blck_1 && ir1 < ir1_end; ir1 += num_rows_per_vec_dot) { /* weight sub loop */
      //for (int64_t iir0 = ir0_start; iir0 < ir0_end; iir0 += blck_0) { /* sdata top loop */
	  const int64_t i13 = (ir1 / (ne12 * ne1));
	  const int64_t i12 = (ir1 - i13 * ne12 * ne1) / ne1;
	  const int64_t i11 = (ir1 - i13 * ne12 * ne1 - i12 * ne1);
          const int64_t i03 = i13 / r3;
          const int64_t i02 = i12 / r2;
	  const int64_t i1 = i11;
	  const int64_t i2 = i12;
	  const int64_t i3 = i13;
	  const int64_t blck_00 = blck_0*IIR0_LOOPS;
	  const int64_t blck_00dIMAP = blck_00/IMAP;

	//const char * src0_row = (const char*)SRC0_ROW_TOP;
	  const char * src0_row = (const char*)i_m0A_TOP;
	  Ull          src0_row_hmbase[5];     for (j=0; j<5;  j++) src0_row_hmbase[j]    = (Ull)src0_row+ 0+j*8; /* 32B */
	  Ull          src0_row_qsbase[2][5];  for (j=0; j<5;  j++) src0_row_qsbase[0][j] = (Ull)src0_row+32+j*8; /* 32B */
	                                       for (j=0; j<5;  j++) src0_row_qsbase[1][j] = (Ull)src0_row+64+j*8; /* 32B */
	  Ull          src0_row_scbase[12];    for (j=0; j<12; j++) src0_row_scbase[j] = (Ull)src0_row+96+j;   /* 12B */
	  Ull          src0_row_dbase_p0;                        src0_row_dbase_p0  = (Ull)src0_row+108;    /*  2B */
	  Ull          src0_row_dbase_p8;                        src0_row_dbase_p8  = (Ull)src0_row+108+8;  /*  2B */

	//const char * src1_col = (const char*)wdata + (src1_cont || src1->type != vec_dot_type ? (i11 + i12 * ne11 + i13 * ne12 * ne11) * row_size
	//                                                                                      : (i11 * nb11 + i12 * nb12 + i13 * nb13));
	//const char * src1_col = (const char*)SRC1_COL_TOP + (ir1-ir1_start)*nb11);
	  const char * src1_col = (const char*)i_m0B[LANE]  + (ir1-ir1_start)*sizeof(int)*SRC1_COL_LEN;
	  Ull          src1_col_dbase_p0 = (Ull)src1_col;        /*  4B */
	  Ull          src1_col_dbase_p8 = (Ull)src1_col+8;      /*  4B */
	  Ull          src1_col_base[8][5]; for (i=0; i<8; i++) for (j=0; j<5;  j++) src1_col_base[i][j] = (Ull)src1_col+4+i*32+j*8; /* 256B */

	//float      * dst_col = (float*)((char*)dst->data + (i1 * nb1 + i2 * nb2 + i3 * nb3)) + ir0_start;
	//float      * dst_col = (float*)DST_COL_TOP + (ir1-ir1_start)*nb1/sizeof(int); /* stride nb1/sizeof(int)=4096=nb*32 */
	  float      * dst_col = (float*)i_m0C[LANE] + (ir0_start-ir0_start) + (ir1-ir1_start)*DST_COL_LENdIMAP;/* contiguous */

        //printf("src0_row=%16.16llx ir0=%16.16llx-%16.16llx (step=%16.16llx) ne00=%08.08x nb01=%08.08x\n", src0_row, iir0, iir0 + blck_0, num_rows_per_vec_dot, (int)ne00, (int)nb01);

#define q3_k(r, b0, b1, b2, b3, lh, cvt, cb) \
	mop(OP_LDBR,  3, &BR[r][0][1],  src0_row_scbase[b0], (Ull)iofs,  MSK_W1, i_m0A_TOP,   SRC0_ROW_LEN,       0, Force0, (Ull)NULL, SRC0_ROW_LEN); /* ..------|-------- -------- -------- ----XXXX */\
	mop(OP_LDBR,  3, &BR[r][1][1],  src0_row_scbase[b1], (Ull)iofs,  MSK_W1, i_m0A_TOP,   SRC0_ROW_LEN,       0, Force0, (Ull)NULL, SRC0_ROW_LEN); /* ..------|-------- -------- -------- ------YY */\
	mop(OP_LDBR,  3, &BR[r][2][1],  src0_row_scbase[b2], (Ull)iofs,  MSK_W1, i_m0A_TOP,   SRC0_ROW_LEN,       0, Force0, (Ull)NULL, SRC0_ROW_LEN); /* ..------|-------- -------- -------- ----ZZZZ */\
	mop(OP_LDBR,  3, &BR[r][3][1],  src0_row_scbase[b3], (Ull)iofs,  MSK_W1, i_m0A_TOP,   SRC0_ROW_LEN,       0, Force0, (Ull)NULL, SRC0_ROW_LEN); /* ..------|-------- -------- -------- ------WW */\
\
	exe(OP_MMRG, &r00, 0LL, EXP_H1010,  BR[r][1][1], EXP_H1010, BR[r][0][1], EXP_H1010,  OP_NOP, 0LL, OP_SRL, 8LL);           /* sc 6bit->5bit */ /* ..--XXXX|-------- -------- ------YY ----XXXX */\
	exe(OP_MMRG, &r01, 0LL, EXP_H1010,  BR[r][3][1], EXP_H1010, BR[r][2][1], EXP_H1010,  OP_NOP, 0LL, OP_SRL, 8LL);           /* sc 6bit->5bit */ /* ..--ZZZZ|-------- -------- ------WW ----ZZZZ */\
	mop(OP_LDR,   0, &BR[r+1][0][1],  src0_row_qsbase[lh][1], (Ull)iofs,  MSK_W1, i_m0A_TOP,   SRC0_ROW_LEN,       0, Force0, (Ull)NULL, SRC0_ROW_LEN); /* qs 2bit |------qq ------qq ------qq ------QQ */\
	mop(OP_LDR,   3, &BR[r+1][0][0],  src0_row_qsbase[lh][0], (Ull)iofs,  MSK_W1, i_m0A_TOP,   SRC0_ROW_LEN,       0, Force0, (Ull)NULL, SRC0_ROW_LEN); /* unaligned */\
	mop(OP_LDR,   0, &BR[r+1][1][1],  src0_row_qsbase[lh][2], (Ull)iofs,  MSK_W1, i_m0A_TOP,   SRC0_ROW_LEN,       0, Force0, (Ull)NULL, SRC0_ROW_LEN); /* dismissible */\
	mop(OP_LDR,   3, &BR[r+1][1][0],  src0_row_qsbase[lh][1], (Ull)iofs,  MSK_W1, i_m0A_TOP,   SRC0_ROW_LEN,       0, Force0, (Ull)NULL, SRC0_ROW_LEN); /* unaligned */\
	mop(OP_LDR,   0, &BR[r+1][2][1],  src0_row_qsbase[lh][3], (Ull)iofs,  MSK_W1, i_m0A_TOP,   SRC0_ROW_LEN,       0, Force0, (Ull)NULL, SRC0_ROW_LEN); /* dismissible */\
	mop(OP_LDR,   3, &BR[r+1][2][0],  src0_row_qsbase[lh][2], (Ull)iofs,  MSK_W1, i_m0A_TOP,   SRC0_ROW_LEN,       0, Force0, (Ull)NULL, SRC0_ROW_LEN); /* unaligned */\
	mop(OP_LDR,   0, &BR[r+1][3][1],  src0_row_qsbase[lh][4], (Ull)iofs,  MSK_W1, i_m0A_TOP,   SRC0_ROW_LEN,       0, Force0, (Ull)NULL, SRC0_ROW_LEN); /* dismissible */\
	mop(OP_LDR,   3, &BR[r+1][3][0],  src0_row_qsbase[lh][3], (Ull)iofs,  MSK_W1, i_m0A_TOP,   SRC0_ROW_LEN,       0, Force0, (Ull)NULL, SRC0_ROW_LEN); /* unaligned */\
\
	mop(OP_LDR,   0, &BR[r+2][0][1],  src0_row_hmbase[1], (Ull)iofs,  MSK_W1, i_m0A_TOP,   SRC0_ROW_LEN,       0, Force0, (Ull)NULL, SRC0_ROW_LEN); /* hm 1bit |-------h -------h -------h -------H */\
	mop(OP_LDR,   3, &BR[r+2][0][0],  src0_row_hmbase[0], (Ull)iofs,  MSK_W1, i_m0A_TOP,   SRC0_ROW_LEN,       0, Force0, (Ull)NULL, SRC0_ROW_LEN); /* unaligned */\
	mop(OP_LDR,   0, &BR[r+2][1][1],  src0_row_hmbase[2], (Ull)iofs,  MSK_W1, i_m0A_TOP,   SRC0_ROW_LEN,       0, Force0, (Ull)NULL, SRC0_ROW_LEN); /* dismissible */\
	mop(OP_LDR,   3, &BR[r+2][1][0],  src0_row_hmbase[1], (Ull)iofs,  MSK_W1, i_m0A_TOP,   SRC0_ROW_LEN,       0, Force0, (Ull)NULL, SRC0_ROW_LEN); /* unaligned */\
	mop(OP_LDR,   0, &BR[r+2][2][1],  src0_row_hmbase[3], (Ull)iofs,  MSK_W1, i_m0A_TOP,   SRC0_ROW_LEN,       0, Force0, (Ull)NULL, SRC0_ROW_LEN); /* dismissible */\
	mop(OP_LDR,   3, &BR[r+2][2][0],  src0_row_hmbase[2], (Ull)iofs,  MSK_W1, i_m0A_TOP,   SRC0_ROW_LEN,       0, Force0, (Ull)NULL, SRC0_ROW_LEN); /* unaligned */\
	mop(OP_LDR,   0, &BR[r+2][3][1],  src0_row_hmbase[4], (Ull)iofs,  MSK_W1, i_m0A_TOP,   SRC0_ROW_LEN,       0, Force0, (Ull)NULL, SRC0_ROW_LEN); /* dismissible */\
	mop(OP_LDR,   3, &BR[r+2][3][0],  src0_row_hmbase[3], (Ull)iofs,  MSK_W1, i_m0A_TOP,   SRC0_ROW_LEN,       0, Force0, (Ull)NULL, SRC0_ROW_LEN); /* unaligned */\
\
	exe(OP_CVT53, &r04, r00, cvt,  BR[r+2][0][0], EXP_H3210, BR[r+1][0][0], EXP_H3210, OP_NOP, 0LL, OP_NOP, 8LL);   /* YYXXX-(6->5bit)*HQQ (sc * hm|qs) -> x[ 7: 0] */\
	exe(OP_CVT53, &r05, r00, cvt,  BR[r+2][1][0], EXP_H3210, BR[r+1][1][0], EXP_H3210, OP_NOP, 0LL, OP_NOP, 8LL);   /* YYXXX-(6->5bit)*HQQ (sc * hm|qs) -> x[15: 8] */\
	exe(OP_CVT53, &r06, r01, cvt,  BR[r+2][2][0], EXP_H3210, BR[r+1][2][0], EXP_H3210, OP_NOP, 0LL, OP_NOP, 8LL);   /* YYXXX-(6->5bit)*HQQ (sc * hm|qs) -> x[23:16] */\
	exe(OP_CVT53, &r07, r01, cvt,  BR[r+2][3][0], EXP_H3210, BR[r+1][3][0], EXP_H3210, OP_NOP, 0LL, OP_NOP, 8LL);   /* YYXXX-(6->5bit)*hQQ (sc * hm|qs) -> x[31:24] */\
	mop(OP_LDR,   0, &BR[r+3][0][1], src1_col_base[cb][1], (Ull)iofs,  MSK_W0, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)NULL, SRC1_COL_LEN_TOTAL); /* dismissible */\
	mop(OP_LDR,   3, &BR[r+3][0][0], src1_col_base[cb][0], (Ull)iofs,  MSK_W0, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)NULL, SRC1_COL_LEN_TOTAL); /* unaligned */\
	mop(OP_LDR,   0, &BR[r+3][1][1], src1_col_base[cb][2], (Ull)iofs,  MSK_W0, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)NULL, SRC1_COL_LEN_TOTAL); /* dismissible */\
	mop(OP_LDR,   3, &BR[r+3][1][0], src1_col_base[cb][1], (Ull)iofs,  MSK_W0, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)NULL, SRC1_COL_LEN_TOTAL); /* unaligned */\
	mop(OP_LDR,   0, &BR[r+3][2][1], src1_col_base[cb][3], (Ull)iofs,  MSK_W0, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)NULL, SRC1_COL_LEN_TOTAL); /* dismissible */\
	mop(OP_LDR,   3, &BR[r+3][2][0], src1_col_base[cb][2], (Ull)iofs,  MSK_W0, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)NULL, SRC1_COL_LEN_TOTAL); /* unaligned */\
	mop(OP_LDR,   0, &BR[r+3][3][1], src1_col_base[cb][4], (Ull)iofs,  MSK_W0, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)NULL, SRC1_COL_LEN_TOTAL); /* dismissible */\
	mop(OP_LDR,   3, &BR[r+3][3][0], src1_col_base[cb][3], (Ull)iofs,  MSK_W0, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)NULL, SRC1_COL_LEN_TOTAL); /* unaligned */\
\
        exe(OP_SML8,     &r20,  r04,  EXP_B5410, BR[r+3][0][0],    EXP_B5410, 0LL, EXP_H3210,  OP_AD32, r24, OP_NOP, 0LL); /* sdata,wdata */\
        exe(OP_SML8,     &r21,  r05,  EXP_B5410, BR[r+3][1][0],    EXP_B5410, 0LL, EXP_H3210,  OP_AD32, r25, OP_NOP, 0LL); /* sdata,wdata */\
        exe(OP_SML8,     &r22,  r06,  EXP_B5410, BR[r+3][2][0],    EXP_B5410, 0LL, EXP_H3210,  OP_AD32, r26, OP_NOP, 0LL); /* sdata,wdata */\
        exe(OP_SML8,     &r23,  r07,  EXP_B5410, BR[r+3][3][0],    EXP_B5410, 0LL, EXP_H3210,  OP_AD32, r27, OP_NOP, 0LL); /* sdata,wdata */\
\
        exe(OP_SML8,     &r24,  r04,  EXP_B7632, BR[r+3][0][0],    EXP_B7632, 0LL, EXP_H3210,  OP_AD32, r20, OP_NOP, 0LL); /* sdata,wdata */\
        exe(OP_SML8,     &r25,  r05,  EXP_B7632, BR[r+3][1][0],    EXP_B7632, 0LL, EXP_H3210,  OP_AD32, r21, OP_NOP, 0LL); /* sdata,wdata */\
        exe(OP_SML8,     &r26,  r06,  EXP_B7632, BR[r+3][2][0],    EXP_B7632, 0LL, EXP_H3210,  OP_AD32, r22, OP_NOP, 0LL); /* sdata,wdata */\
        exe(OP_SML8,     &r27,  r07,  EXP_B7632, BR[r+3][3][0],    EXP_B7632, 0LL, EXP_H3210,  OP_AD32, r23, OP_NOP, 0LL)  /* sdata,wdata */

//EMAX5A begin mul_mat_one_chunk_q3k mapdist=0
     /*3*/for (CHIP=0; CHIP<NCHIP; CHIP++) { /* will be parallelized by multi-chip (M/#chip) */
       /*2*/for (INIT1=1,LOOP1=blck_00dIMAP,rofs=MNB01_M4; LOOP1--; INIT1=0) { /* stage#0 *//* mapped to FOR() on BR[63][1][0] *//* sdata  sub loop *//* blck_0=16 */
         /*1*/for (INIT0=1,LOOP0=nb,cofs=MBKQ3_MBKQ8; LOOP0--; INIT0=0) { /* stage#0 *//* mapped to FOR() on BR[63][0][0] *//* 34B   x nb loop *//* nb=128,344 LMM=17408,46784word */
		exe(OP_ADD,      &rofs,  rofs,            EXP_H3210, INIT0?NB01_4:0, EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL,                  OP_NOP, 0LL); /* |x:NB01|d:   4| stage#0 */
                exe(OP_ADD,      &cofs,  INIT0?cofs:cofs, EXP_H3210, BKQ3_BKQ8,      EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL,                  OP_NOP, 0LL); /* |x:BKQ8|d:   0| stage#0 */
	        exe(OP_ADD,      &xofs,  rofs,            EXP_H3210, cofs,           EXP_H3210, 0LL, EXP_H3210, OP_AND, 0xffffffff00000000LL, OP_NOP, 0LL); /*                 stage#1 */
	        exe(OP_ADD,      &yofs,  0LL,             EXP_H3210, cofs,           EXP_H3210, 0LL, EXP_H3210, OP_AND, 0x00000000ffffffffLL, OP_NOP, 0LL); /*                 stage#1 */
	        exe(OP_ADD,      &oofs,  rofs,            EXP_H3210, 0LL,            EXP_H3210, 0LL, EXP_H3210, OP_AND, 0x00000000ffffffffLL, OP_NOP, 0LL); /*                 stage#1 */
	        exe(OP_NOP,      &iofs,  xofs,            EXP_H3210, 0LL,            EXP_H3210, 0LL, EXP_H3210, OP_OR,  yofs,                 OP_NOP, 0LL); /*                 stage#2 */
	        exe(OP_ADD,      &r24,   0LL,             EXP_H3210, 0LL,            EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL,                  OP_NOP, 0LL); /*                 stage#3 */        
	        exe(OP_ADD,      &r25,   0LL,             EXP_H3210, 0LL,            EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL,                  OP_NOP, 0LL); /*                 stage#3 */
	        exe(OP_ADD,      &r26,   0LL,             EXP_H3210, 0LL,            EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL,                  OP_NOP, 0LL); /*                 stage#3 */
	        exe(OP_ADD,      &r27,   0LL,             EXP_H3210, 0LL,            EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL,                  OP_NOP, 0LL); /*                 stage#3 */
#if 0
		/****************************************************************************************************************************************/
		/* x[i].scales           [11][10][ 9][ 8][ 7][ 6][ 5][ 4][ 3][ 2][ 1][ 0] */
		/* auxs  [       3      ][       2      ][       1      ][       0      ] */
		/*                  auxs0 0 3 0 3 0 3 0 3                 0 f 0 f 0 f 0 f */
		/*                  auxs1 0 c 0 c 0 c 0 c 0 f 0 f 0 f 0 f                 */
		/*                  auxs2 3 0 3 0 3 0 3 0                 f 0 f 0 f 0 f 0 */
		/*                  auxs3 c 0 c 0 c 0 c 0 f 0 f 0 f 0 f 0                 */
		/* auxs  [       3      ][       2      ][       1      ][       0      ] */
		/*        3f  3f  3f  3f  3f  3f  3f  3f  3f  3f  3f  3f  3f  3f  3f  3f  */
		/* scales[15][14][13][12][11][10][ 9][ 8][ 7][ 6][ 5][ 4][ 3][ 2][ 1][ 0] */
		/*                   LDB              LDB              LDB              LDB x[i].sc 12B auxs[2].bit[5:4,1:0]|auxs[0].bit[11:8,3:0] 6bit */
		/*                   [9]              [1]              [8]              [0]                                                             */
		/*              ----ff--         ----ff--         ------ff         ------ff                                                             */
		/*              ----03--AND SLL4 ----0f-- >[1]AND ------03AND SLL4 ------0f >[0]AND                                                     */
		/*                       3f--3f--3f--3f-- H1010 OP_OR      --3f--3f--3f--3f H1010 OP_OR                                                 */
		/*                       fffefffefffefffe OP_SUB(-32)|DUPH fffefffefffefffe OP_SUB(-32)|DUPH(op3)??                                     */
		/*                                                                       or  ????1???OP_SCL6 auxs2,auxs0,loc_loc??????                 */
		uint32_t auxs[4];
		memcpy(auxs, x[xi].scales, 12);
		uint32_t tmp = auxs[2];
		const int8_t * auxp = (const int8_t*)auxs;
		auxs[2] = ((tmp & 0x30303030)     )|((auxs[0] >> 4) & 0x0f0f0f0f);
		auxs[3] = ((tmp & 0xc0c0c0c0) >> 2)|((auxs[1] >> 4) & 0x0f0f0f0f);
		auxs[0] = ((tmp & 0x03030303) << 4)|( auxs[0]       & 0x0f0f0f0f);
		auxs[1] = ((tmp & 0x0c0c0c0c) << 2)|( auxs[1]       & 0x0f0f0f0f);
		/***********************************************************************************************/
		/*  qs0-31  2 2 2 2  2 2 2 2  2 2 2 2  2 2 2 2  2 2 2 2  2 2 2 2  2 2 2 2  2 2 2 2 ... x32     */
		/*                x        x        x        x        x        x        x        x *//*  0- 31 */
		/*              x        x        x        x        x        x        x        x   *//* 32- 63 */
		/*            x        x        x        x        x        x        x        x     *//* 64- 95 */
		/*          x        x        x        x        x        x        x        x       *//* 96-127 */
		/*  qs32-63 2 2 2 2  2 2 2 2  2 2 2 2  2 2 2 2  2 2 2 2  2 2 2 2  2 2 2 2  2 2 2 2 ... x32     */
		/*                x        x        x        x        x        x        x        x *//*128-159 */
		/*              x        x        x        x        x        x        x        x   *//*160-191 */
		/*            x        x        x        x        x        x        x        x     *//*192-223 */
		/*          x        x        x        x        x        x        x        x       *//*224-255 */
		int8_t   aux8[QK_K];
		for (int l = 0; l < 32; ++l) aux8[l    ] = ((x[xi].qs[l   ]     ) & 3) - (x[xi].hmask[l] & 0x01 ? 0 : 4);
		for (int l = 0; l < 32; ++l) aux8[l+ 32] = ((x[xi].qs[l   ] >> 2) & 3) - (x[xi].hmask[l] & 0x02 ? 0 : 4);
		for (int l = 0; l < 32; ++l) aux8[l+ 64] = ((x[xi].qs[l   ] >> 4) & 3) - (x[xi].hmask[l] & 0x04 ? 0 : 4);
		for (int l = 0; l < 32; ++l) aux8[l+ 96] = ((x[xi].qs[l   ] >> 6) & 3) - (x[xi].hmask[l] & 0x08 ? 0 : 4);
		for (int l = 0; l < 32; ++l) aux8[l+128] = ((x[xi].qs[l+32]     ) & 3) - (x[xi].hmask[l] & 0x10 ? 0 : 4);
		for (int l = 0; l < 32; ++l) aux8[l+160] = ((x[xi].qs[l+32] >> 2) & 3) - (x[xi].hmask[l] & 0x20 ? 0 : 4);
		for (int l = 0; l < 32; ++l) aux8[l+192] = ((x[xi].qs[l+32] >> 4) & 3) - (x[xi].hmask[l] & 0x40 ? 0 : 4);
		for (int l = 0; l < 32; ++l) aux8[l+224] = ((x[xi].qs[l+32] >> 6) & 3) - (x[xi].hmask[l] & 0x80 ? 0 : 4);
		/* ??32          LDR&LDR          LDR&LDR          LDR&LDR          LDR&LDR x[i].qs 32B.bit[1:0]      2bit */
		/*               [31:24]          [23:16]          [15: 8]          [ 7: 0]                                */
		/*      0303030303030303 0303030303030303 0303030303030303 0303030303030303                                */
		/*               LDR&LDR          LDR&LDR          LDR&LDR          LDR&LDR x[i].hm 32B.bit[0]        1bit */
		/*               [31:24]          [23:16]          [15: 8]          [ 7: 0]                                */
		/*      0101010101010101 0101010101010101 0101010101010101 0101010101010101  OP_CMOV8(op1)?? 1->00, 0->04  */
		/*      0404040404040404 0404040404040404 0404040404040404                                */
		/*      fdfdfdfdfdfdfdfd fdfdfdfdfdfdfdfd fdfdfdfdfdfdfdfd fdfdfdfdfdfdfdfd  OP_SSB8(op1)??  -> aux8       */
		for (int l = 0; l < QK_K; ++l) auxx[l] = ((auxp[l/16]>>1) - 16) * aux8[l]; /* 8bit <- (6-1)bit x 3bit */
		int32_t aux32 = 0;
		const block_q3_K * restrict x = src0_row;
		const block_q8_K * restrict y = src1_col;
		int xi = (xofs>>32)/sizeof(block_q3_K);
		int yi = yofs/sizeof(block_q8_K);
		for (int l = 0; l < QK_K; ++l) aux32 += auxx[l] * y[yi].qs[l]; /* (25-1)bit <- ??256((9-1)bit x 8bit) */
		*(float*)&r01 = GGML_FP16_TO_FP32(x[xi].d) * y[yi].d * (*(int32_t*)&r31 * 2);
#endif
		/*********************************************************************************************************************************************/
		/*   ?????  x[i]????????????      OP_CVT36 ??hm,LOChm[7-0],??qs,LOCqs[3-0], ??sc[H8|L8bit],LOCsc[H3-0(L1-0????)] 3b*6b->8b?????        */
		/*                   LDB              LDB              LDB              LDB x[i].sc                                                          */
		/*                               MMRG|SRL                          MMRG|SRL                                                                  */
		/*               LDR&LDR          LDR&LDR          LDR&LDR          LDR&LDR x[i].qs                                                     2bit */
		/*               LDR&LDR          LDR&LDR          LDR&LDR          LDR&LDR x[i].hm                                                     1bit */
		/*                 CVT53            CVT53            CVT53            CVT53                                                                  */
		/* EXP_CVT00 0: src1(sc)=-----s-c|-----s-c  src2(hm)=..|-------h -------h -------h -------h  src3(qs)=..|------qq ------qq ------qq ------qq */
		/* EXP_CVT01 1: src1(sc)=-----s-c|-----s-c  src2(hm)=..|------h- ------h- ------h- ------h-  src3(qs)=..|----qq-- ----qq-- ----qq-- ----qq-- */
		/* EXP_CVT02 2: src1(sc)=-----s-c|-----s-c  src2(hm)=..|-----h-- -----h-- -----h-- -----h--  src3(qs)=..|--qq---- --qq---- --qq---- --qq---- */
		/* EXP_CVT03 3: src1(sc)=-----s-c|-----s-c  src2(hm)=..|----h--- ----h--- ----h--- ----h---  src3(qs)=..|qq------ qq------ qq------ qq------ */
		/* EXP_CVT04 4: src1(sc)=-----s-c|-----s-c  src2(hm)=..|---h---- ---h---- ---h---- ---h----  src3(qs)=..|------qq ------qq ------qq ------qq */
		/* EXP_CVT05 5: src1(sc)=-----s-c|-----s-c  src2(hm)=..|--h----- --h----- --h----- --h-----  src3(qs)=..|----qq-- ----qq-- ----qq-- ----qq-- */
		/* EXP_CVT06 6: src1(sc)=-----s-c|-----s-c  src2(hm)=..|-h------ -h------ -h------ -h------  src3(qs)=..|--qq---- --qq---- --qq---- --qq---- */
		/* EXP_CVT07 7: src1(sc)=-----s-c|-----s-c  src2(hm)=..|h------- h------- h------- h-------  src3(qs)=..|qq------ qq------ qq------ qq------ */
		/*      ffffffffffffffff ffffffffffffffff ffffffffffffffff ffffffffffffffff                                                                  */
		/*               LDR&LDR          LDR&LDR          LDR&LDR          LDR&LDR y[i].qs 32B                                                 8bit */
		/*               [31:24]          [23:16]          [15: 8]          [ 7: 0]                                                                  */
		/*      ffffffffffffffff ffffffffffffffff ffffffffffffffff ffffffffffffffff                                                                  */
		/*               dual(8b*8b + 8b*8b) -> dual(24bit) ??32(8b*8b) -> ??32(16bit) -> 21bit                                                      */
		/*               SML8             SML8             SML8             SML8    EXP_B5410                                                        */
		/*               SML8             SML8             SML8             SML8    EXP_B7632                                                        */
		/*  :x8 = ??256                                                                                                                              */
#if 0
printf("==be %02.2x%02.2x%02.2x%02.2x%02.2x%02.2x%02.2x%02.2x\n", (Uchar)auxx[224],(Uchar)auxx[225],(Uchar)auxx[226],(Uchar)auxx[227],(Uchar)auxx[228],(Uchar)auxx[229],(Uchar)auxx[230],(Uchar)auxx[231]);
printf("==be %02.2x%02.2x%02.2x%02.2x%02.2x%02.2x%02.2x%02.2x\n", (Uchar)auxx[232],(Uchar)auxx[233],(Uchar)auxx[234],(Uchar)auxx[235],(Uchar)auxx[236],(Uchar)auxx[237],(Uchar)auxx[238],(Uchar)auxx[239]);
printf("==be %02.2x%02.2x%02.2x%02.2x%02.2x%02.2x%02.2x%02.2x\n", (Uchar)auxx[240],(Uchar)auxx[241],(Uchar)auxx[242],(Uchar)auxx[243],(Uchar)auxx[244],(Uchar)auxx[245],(Uchar)auxx[246],(Uchar)auxx[247]);
printf("==be %02.2x%02.2x%02.2x%02.2x%02.2x%02.2x%02.2x%02.2x\n", (Uchar)auxx[248],(Uchar)auxx[249],(Uchar)auxx[250],(Uchar)auxx[251],(Uchar)auxx[252],(Uchar)auxx[253],(Uchar)auxx[254],(Uchar)auxx[255]);
#endif
		/*********************************************************************************************************************************************/
		/* #0 of 32/256 */
                q3_k( 3,  0,  8,  1,  9, 0, EXP_CVT00, 0);
		/*********************************************************************************************************************************************/
		/* #1 of auxx[32]/256 */
                q3_k( 8,  2, 10,  3, 11, 0, EXP_CVT01, 1);
		/*********************************************************************************************************************************************/
		/* #2 of auxx[32]/256 */
                q3_k(13,  4,  8,  5,  9, 0, EXP_CVT02, 2);
		/*********************************************************************************************************************************************/
		/* #3 of auxx[32]/256 */
                q3_k(18,  6, 10,  7, 11, 0, EXP_CVT03, 3);
		/*********************************************************************************************************************************************/
		/* #4 of auxx[32]/256 */
                q3_k(23,  0,  8,  1,  9, 1, EXP_CVT04, 4);
		/*********************************************************************************************************************************************/
		/* #5 of auxx[32]/256 */
                q3_k(28,  2, 10,  3, 11, 1, EXP_CVT05, 5);
		/*********************************************************************************************************************************************/
		/* #6 of auxx[32]/256 */
                q3_k(33,  4,  8,  5,  9, 1, EXP_CVT06, 6);
		/*********************************************************************************************************************************************/
		/* #7 of auxx[32]/256 */
                q3_k(38,  6, 10,  7, 11, 1, EXP_CVT07, 7);
		/*********************************************************************************************************************************************/
		/* Sum */
	        exe(OP_NOP,      &r28,  r24,          EXP_H3210, 0LL,            EXP_H3210, 0LL, EXP_H3210, OP_AD32, r25, OP_NOP, 0LL);                      /* stage #44 */
	        exe(OP_NOP,      &r29,  r26,          EXP_H3210, 0LL,            EXP_H3210, 0LL, EXP_H3210, OP_AD32, r27, OP_NOP, 0LL);                      /* stage #44 */
		mop(OP_LDR,   0, &BR[44][0][1], src0_row_dbase_p8,   (Ull)iofs,  MSK_W1, i_m0A_TOP,  SRC0_ROW_LEN,       0, Force0, (Ull)NULL, SRC0_ROW_LEN);  /* stage #44 */ /* dismissible */
		mop(OP_LDR,   3, &BR[44][0][0], src0_row_dbase_p0,   (Ull)iofs,  MSK_W1, i_m0A_TOP,  SRC0_ROW_LEN,       0, Force0, (Ull)NULL, SRC0_ROW_LEN);  /* stage #44 */ /* unaligned */

	        exe(OP_NOP,      &r30,  r28,          EXP_H3210, 0LL,            EXP_H3210, 0LL, EXP_H3210, OP_AD32, r29, OP_NOP, 0LL);                      /* stage #45 */
		mop(OP_LDR,   0, &BR[45][0][1], src1_col_dbase_p8,   (Ull)iofs,  MSK_W0, i_m0B[LANE],SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)NULL, SRC1_COL_LEN_TOTAL);  /* stage #45 */ /* dismissible */
		mop(OP_LDR,   3, &BR[45][0][0], src1_col_dbase_p0,   (Ull)iofs,  MSK_W0, i_m0B[LANE],SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)NULL, SRC1_COL_LEN_TOTAL);  /* stage #45 */ /* unaligned */

	        exe(OP_NOP,      &r31,  r30,          EXP_H3232, 0LL,            EXP_H3210, 0LL, EXP_H3210, OP_AD32, r30, OP_SRAB,8LL); /* aux32 */          /* stage #46 */

	      /**(float*)&r01 = GGML_FP16_TO_FP32((uint16_t)BR[50][0][0]) * *(float*)&BR[51][0][0] * (*(int32_t*)&r31 * 512);*/ /* 1+8bit */                 /* ?????INT24->FP32?????? */
	      /**(float*)&r01 = GGML_FP16_TO_FP32((uint16_t)BR[50][0][0]) * *(float*)&BR[51][0][0] * (GGML_INT16_TO_FP32((int16_t)(r31&0xffffLL)) * 512);*/  /* ?????INT24->FP32?????? */
	        exe(OP_NOP,      &r12,  r31,          EXP_H3210, 0LL,            EXP_H3210, 0LL, EXP_H3210, OP_AND, 0x000000000000ffffLL, OP_SLL, 2LL); /* aux32 int16->fp32*//* stage #47 */
	        exe(OP_NOP,      &r13,  BR[44][0][0], EXP_H3210, 0LL,            EXP_H3210, 0LL, EXP_H3210, OP_AND, 0x000000000000ffffLL, OP_SLL, 2LL); /* x.d   fp16->fp32 *//* stage #47 */

		mop(OP_LDWR,  3, &BR[48][0][1], (Ull)i_i16[LANE],    (Ull)r12,   MSK_W0, (Ull)i_i16[LANE], 65536, 0, 0, (Ull)NULL, 65536); /* aux32 int16->fp32*//* stage #48 */
		mop(OP_LDWR,  3, &BR[48][2][1], (Ull)i_f16[LANE],    (Ull)r13,   MSK_W0, (Ull)i_f16[LANE], 65536, 0, 0, (Ull)NULL, 65536); /* x.d   fp16->fp32 *//* stage #48 */

		exe(OP_FML,      &r03, BR[48][0][1],  EXP_H3210, 0x44000000LL,   EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL); /* aux32 * 512.0 */
		exe(OP_FML,      &r02, BR[48][2][1],  EXP_H3210, BR[45][0][0],   EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL); /* x.d * y.d */

	        exe(OP_NOP,      &AR[50][0], 0LL,     EXP_H3210, 0LL,            EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);              /* stage#63 (dummy to set target location) */
	        mop(OP_LDWR,  1, &r00,       dst_col,            oofs,           MSK_W0, i_m0C_TOP_IMAP[0][LANE], DST_COL_LEN_TOTdIMAP,  0, Force2, (Ull)NULL, DST_COL_LEN_TOTdIMAP); /* stage#50 */
	        exe(OP_FMA,      &r00, INIT0?r00:r00, EXP_H3210, r03,            EXP_H3210, r02, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);              /* x.d * y.d * aux32 * 512 */
	        mop(OP_STWR,  1, &r00,       oofs,               dst_col,        MSK_D0, i_m0C_TOP_IMAP[0][LANE], DST_COL_LEN_TOTdIMAP,  0, Force2, (Ull)NULL, DST_COL_LEN_TOTdIMAP);
	      }
	    }
          }
//EMAX5A end
          if (Force0) Force0 = 0; /* reset sdat to LMM */
          if (Force1) Force1 = 0; /* reset wdat to LMM */
          if (Force2) Force2 = 0; /* reset dst  to LMM */
      //}
      }
    }
//EMAX5A drain_dirty_lmm
///////////////////////////////////////////////////////////////////////IMAX????:???????///////////////////

//  get_nanosec(LANE,0);

 
// プログラム終了時に表示
    monitor_time_start(THREAD, IMAX_CPYOUT_Q3K);
    if (!((Ull)DST_COL_TOP & 63) && !((Ull)i_m0C[LANE] & 63) && DST_COL_LENdIMAP == 16 && IMAP == 1) { // 64B aligned
      for (int i=0; i<IR1_LOOPS; i++) { /* stride */
	Dll *dst = (int*)DST_COL_TOP+i*nb1/sizeof(int);
	Dll *src = (int*)i_m0C[LANE]+i*16;
	*dst++ = *src++; /* 4word */
	*dst++ = *src++; /* 4word */
	*dst++ = *src++; /* 4word */
	*dst++ = *src++; /* 4word */
      }
    }
    else
      xmax_cpyout(4, DST_COL_TOP, 1, nb1/sizeof(int), i_m0C[LANE], IR1_LOOPS, DST_COL_LENdIMAP, IMAP); /* stride */
    monitor_time_end(THREAD, IMAX_CPYOUT_Q3K);
    // dstの値をチェック
    // printf("Q3k_DST_COL_TOP=%16.16llx\n", DST_COL_TOP);
    
    // /* --- 演算結果を表示 (IMAX path) : ARM パスと同一フォーマット --- */
    // printf("q3k----------------------------------\n");
    // printf("演算結果 (dst_col):\n");
    // {
    //     float *dst_ptr = (float *)DST_COL_TOP;            /* 出力先先頭 */
    //     for (size_t idx = 0; idx < DST_COL_LEN_TOTAL; ++idx) {
    //         float v = dst_ptr[idx];
    //         printf("  dst_col[%zu] = %f (0x%08x)\n", idx, v, *(uint32_t *)&v);
    //     }
    //     printf("結果のサイズ: %zu bytes\n", DST_COL_LEN_TOTAL * sizeof(float));
    //     if (DST_COL_LEN_TOTAL > 0) {
    //         printf("上位16bit: 0x%04x\n", (*(uint32_t *)dst_ptr >> 16) & 0xFFFF);
    //     }
    // }
    // printf("----------------------------------\n");

  // show_nanosec(LANE);

  }
}

void imax_compute_forward_mul_mat_one_chunk_q6_k(struct th_inference_args *args)
{
  int                                THREAD       = args->thid; /* < NTHREAD vsim.cpp NTHREAD=2                  */
  int                                LANE         = args->thid; /* < NLANE   emax7.h  init_xmax(){NLANE=NTHREAD} */
  struct ggml_tensor *               dst          = args->dst;
  const int64_t                      num_rows_per_vec_dot = args->num_rows_per_vec_dot;
  const int64_t                      ir0_start    = args->ir0_start;
  const int64_t                      ir0_end      = args->ir0_end;
  const int64_t                      ir1_start    = args->ir1_start;
  const int64_t                      ir1_end      = args->ir1_end;
  const struct ggml_tensor *         src0         = args->src0;
  const struct ggml_tensor *         src1         = args->src1;
  const enum ggml_type               type         = args->type; /* 0:F32 1:F16 8:Q8_0 10:Q2_K 11:Q3_K 14:Q6_K */
  const bool                         src1_cont    = args->src1_cont;
  ggml_vec_dot_t const               vec_dot      = args->vec_dot;
  enum ggml_type const               vec_dot_type = args->vec_dot_type;
  const void *                       wdata        = args->wdata;
  const size_t                       row_size     = args->row_size;
  const int64_t                      r2           = args->r2;
  const int64_t                      r3           = args->r3;
  const int64_t                      blck_0       = args->blck_0;
  const int64_t                      blck_1       = args->blck_1;
  const size_t                       src1_col_stride = args->src1_col_stride;
  int   i, j;
  float tmp[32];
  GGML_TENSOR_BINARY_OP_LOCALS
  int       n  = ne00;
  const int nb = n / QK_K; /* 16,43 */

  Ull   IIR1_LOOPS         = (ir1_end-ir1_start)/blck_1;                         /* ��iir1-loop���                  */
  Ull   IIR0_LOOPS         = (ir0_end-ir0_start)/blck_0;                         /* ��iir0-loop���                  */
  Ull   IR1_LOOPS          = MIN(ir1_start+blck_1,ir1_end)-ir1_start;            /* ��ir1-loop���                   */
  Ull   SRC0_ROW_LEN       = sizeof(block_q6_K)*nb*blck_0*IIR0_LOOPS/sizeof(int);/* ��iir0-loop��Ϣ³                */
  Ull   SRC1_COL_LEN       = (sizeof(block_q8_K)*nb+3)/sizeof(int);              /* ��ir1-loop��Ϣ³                 */
  Ull   SRC1_COL_LEN_TOTAL = SRC1_COL_LEN*IR1_LOOPS;                             /* ��ir1-loop��Ϣ³                 */
  Ull   DST_COL_LEN        = blck_0*IIR0_LOOPS;                                  /* ��ir1-loop�ǥ��ȥ饤��(nb1-byte*iir0-loop) */
  Ull   DST_COL_LEN_TOTAL  = DST_COL_LEN*IR1_LOOPS;                              /* ��ir1-loop�ǥ��ȥ饤��(nb1-byte*iir0-loop) */

//printf("q6k: n=%d ir1_start=%16.16llx ir1_end=%16.16llx blk_1=%16.16llx ir0_start=%16.16llx ir0_end=%16.16llx blk_0=%16.16llx num_dot=%16.16llx\n", n, ir1_start, ir1_end, blck_1, ir0_start, ir0_end, blck_0, num_rows_per_vec_dot);
// if(1){
  if (SRC0_ROW_LEN >512*1024/sizeof(int) || ((ir0_end - ir0_start) % blck_0) || num_rows_per_vec_dot != 1) { /* check LMM_SIZE, and start ARM if NG */
    monitor_time_start(THREAD, IMAX_COMPUTE_FORWARD_MUL_MAT_ONE_CHUNK_Q6K_ARM); /* Nakashima */
    for (int64_t iir1 = ir1_start; iir1 < ir1_end; iir1 += blck_1) { /* weight top loop */
      for (int64_t iir0 = ir0_start; iir0 < ir0_end; iir0 += blck_0) { /* sdata top loop */
	for (int64_t ir1 = iir1; ir1 < iir1 + blck_1 && ir1 < ir1_end; ir1 += num_rows_per_vec_dot) { /* weight sub loop */
	  const int64_t i13 = (ir1 / (ne12 * ne1));
	  const int64_t i12 = (ir1 - i13 * ne12 * ne1) / ne1;
	  const int64_t i11 = (ir1 - i13 * ne12 * ne1 - i12 * ne1);
          const int64_t i03 = i13 / r3;
          const int64_t i02 = i12 / r2;
	  const int64_t i1 = i11;
	  const int64_t i2 = i12;
	  const int64_t i3 = i13;

	  const char * src0_row = (const char*)src0->data + (0 + i02 * nb02 + i03 * nb03);
	  const char * src1_col = (const char*)wdata + (src1_cont || src1->type != vec_dot_type ? (i11 + i12 * ne11 + i13 * ne12 * ne11) * row_size
	                                                                                        : (i11 * nb11 + i12 * nb12 + i13 * nb13));
	  float * dst_col = (float*)((char*)dst->data + (i1 * nb1 + i2 * nb2 + i3 * nb3));

	  for (int64_t ir0 = iir0; ir0 < iir0 + blck_0 && ir0 < ir0_end; ir0 += num_rows_per_vec_dot) { /* ne00=4096(0x1000) 4096/32*34=0x1100�ʤΤ�,0x1100B��Ϣ³���Ƥ��� */
	    vec_dot(ne00, &tmp[ir0 - iir0], (num_rows_per_vec_dot > 1 ? 16 : 0), src0_row + ir0 * nb01, (num_rows_per_vec_dot > 1 ? nb01 : 0), src1_col, (num_rows_per_vec_dot > 1 ? src1_col_stride : 0), num_rows_per_vec_dot);

        // const block_q6_K * restrict x = vx;
        // const block_q8_K * restrict y = vy;

	//  int8_t  aux8[QK_K];
	//  int16_t aux16[8];
	//  float   sums [8];
	//  int32_t aux32[8];
	//  memset(sums, 0, 8*sizeof(float));
	//  float sumf = 0;
	//  for (int i = 0; i < nb; ++i) {
	//    const uint8_t * restrict q4 = x[i].ql;
	//    const uint8_t * restrict qh = x[i].qh;
	//    const  int8_t * restrict q8 = y[i].qs;
	//    memset(aux32, 0, 8*sizeof(int32_t));
	//    int8_t * restrict a = aux8;
	//    for (int j = 0; j < QK_K; j += 128) {
	//      for (int l = 0; l < 32; ++l) {
	//	  a[l +  0] = (int8_t)((q4[l +  0] & 0xF) | (((qh[l] >> 0) & 3) << 4)) - 32;  -> CVT86(sc * qh|ql)->14bit*4
	//	  a[l + 32] = (int8_t)((q4[l + 32] & 0xF) | (((qh[l] >> 2) & 3) << 4)) - 32;  -> CVT86(sc * qh|ql)->14bit*4
	//	  a[l + 64] = (int8_t)((q4[l +  0] >>  4) | (((qh[l] >> 4) & 3) << 4)) - 32;  -> CVT86(sc * qh|ql)->14bit*4
	//	  a[l + 96] = (int8_t)((q4[l + 32] >>  4) | (((qh[l] >> 6) & 3) << 4)) - 32;  -> CVT86(sc * qh|ql)->14bit*4
	//	}
	//	a  += 128;
	//	q4 += 64;
	//	qh += 32;
	//    }
	//    a = aux8;
	//    int is = 0;
	//    for (int j = 0; j < QK_K/16; ++j) {
	//	int scale = x[i].scales[is++];
	//	for (int l = 0; l < 8; ++l) aux16[l] = q8[l] * a[l];       -> CVT86(q8(y) * a6(x))
	//	for (int l = 0; l < 8; ++l) aux32[l] += scale * aux16[l];  -> SML16(s8 * a14)
	//	q8 += 8; a += 8;
	//	for (int l = 0; l < 8; ++l) aux16[l] = q8[l] * a[l];       -> CVT86(q8(y) * a6(x))
	//	for (int l = 0; l < 8; ++l) aux32[l] += scale * aux16[l];  -> SML16(s8 * a14)
	//	q8 += 8; a += 8;
	//    }
	//    const float d = GGML_FP16_TO_FP32(x[i].d) * y[i].d;
	//    for (int l = 0; l < 8; ++l) sums[l] += d * aux32[l];         -> FMI:FP32*INT32 (not ADD24>>16 -> INT16_TO_FP32 in q3k)
	//  }
	//  for (int l = 0; l < 8; ++l) sumf += sums[l];
	//  tmp[ir0 - iir0] = sumf;
	    
	  }
	  monitor_time_start(THREAD, ARM_MEMCPY); /* Nakashima */
	  for (int cn = 0; cn < num_rows_per_vec_dot; ++cn) /* num_rows_per_vec_dot=1 */
	    memcpy(&dst_col[iir0 + cn * nb1 / nb0], tmp + (cn * 16), (MIN(iir0 + blck_0, ir0_end) - iir0) * sizeof(float));
	  monitor_time_end(THREAD, ARM_MEMCPY); /* Nakashima */
	}
      }
    }
    monitor_time_end(THREAD, IMAX_COMPUTE_FORWARD_MUL_MAT_ONE_CHUNK_Q6K_ARM); /* Nakashima */
  }
  else { /* IMAX */
#undef  IMAP
#undef  NCHIP
#define IMAP  1
#define NCHIP 1
    Ull   CHIP, rofs, cofs, xofs, yofs, iofs, oofs;
    Ull   LOOP1, LOOP0;
    Ull   INIT1, INIT0;
    Ull   AR[64][4];                     /* output of EX     in each unit */
    Ull   BR[64][4][4];                  /* output registers in each unit */
    Ull   r00, r01, r02, r03, r04, r05, r06, r07, r08, r09, r10, r11, r12, r13, r14, r15;
    Ull   r16, r17, r18, r19, r20, r21, r22, r23, r24, r25, r26, r27, r28, r29, r30, r31;
    Ull   cc0, cc1, cc2, cc3, ex0, ex1, out0, out1, out2, out10;
    Ull   Force0, Force1, Force2; /* force to LMM */

    Ull   MNB01_M4    = (0LL-nb01              )<<32|((0LL-sizeof(float))     &0xffffffffLL);
    Ull   MBKQ6_MBKQ8 = (0LL-sizeof(block_q6_K))<<32|((0LL-sizeof(block_q8_K))&0xffffffffLL);
    Ull   NB01_4      = (0LL+nb01              )<<32|((0LL+sizeof(float))     &0xffffffffLL);
    Ull   BKQ6_BKQ8   = (0LL+sizeof(block_q6_K))<<32|((0LL+sizeof(block_q8_K))&0xffffffffLL);

    const int64_t i13_top = (ir1_start          / (ne12 * ne1));          /* ==0 */
    const int64_t i12_top = (ir1_start - i13_top * ne12 * ne1) / ne1;     /* ==0 */
    const int64_t i11_top = (ir1_start - i13_top * ne12 * ne1 - i12_top * ne1);
    const int64_t i03_top = i13_top / r3;
    const int64_t i02_top = i12_top / r2;
    Ull   SRC0_ROW_TOP       = (const char*)src0->data  + (0 + i02_top * nb02 + i03_top * nb03) + ir0_start*nb01;
    Ull   SRC0_ROW_LENdIMAP  = SRC0_ROW_LEN/IMAP;
    Ull   i_m0A_TOP          = (const char*)i_m0A[LANE] + (0 + i02_top * nb02 + i03_top * nb03) + ir0_start*nb01;
    Ull   SRC1_COL_TOP       = (const char*)wdata       + (src1_cont || src1->type != vec_dot_type ? (i11_top + i12_top * ne11 + i13_top * ne12 * ne11) * row_size /* 4352(0x1100),11696(0x2db0) */
	                                                                                           : (i11_top * nb11 + i12_top * nb12 + i13_top * nb13));
    Ull   DST_COL_TOP        = (float*)((char*)dst->data + (i11_top * nb1 + i12_top * nb2 + i13_top * nb3)) + ir0_start;
    Ull   DST_COL_LENdIMAP   = DST_COL_LEN/IMAP;         /* TOTAL = [[blck_0(16) x IIR0_LOOPS(1,4)]/IMAP] x IIR1_LOOPS(2,1) x IMAP */
    Ull   DST_COL_LEN_TOTdIMAP = DST_COL_LEN_TOTAL/IMAP; /* TOTAL = [[blck_0(16) x IIR0_LOOPS(1,4)]/IMAP] x IIR1_LOOPS(2,1) x IMAP */
    Ull   i_m0C_TOP_IMAP[IMAP][EMAX_NLANE]; for (i=0; i<IMAP; i++) i_m0C_TOP_IMAP[i][LANE] = (Ull)i_m0C[LANE] + i*sizeof(float)*DST_COL_LEN_TOTdIMAP;
#if 0
    static Ull max_SRC0_ROW_LEN=0;
    static Ull max_SRC1_COL_LEN_TOTAL=0;
    static Ull max_DST_COL_LEN_TOTAL=0;
    if (max_SRC0_ROW_LEN       < SRC0_ROW_LEN)       { max_SRC0_ROW_LEN       = SRC0_ROW_LEN      ; printf("max_SRC0_ROW_LEN=%16.16llx\n",       max_SRC0_ROW_LEN); }
    if (max_SRC1_COL_LEN_TOTAL < SRC1_COL_LEN_TOTAL) { max_SRC1_COL_LEN_TOTAL = SRC1_COL_LEN_TOTAL; printf("max_SRC1_COL_LEN_TOTAL=%16.16llx\n", max_SRC1_COL_LEN_TOTAL); }
    if (max_DST_COL_LEN_TOTAL  < DST_COL_LEN_TOTAL)  { max_DST_COL_LEN_TOTAL  = DST_COL_LEN_TOTAL;  printf("max_DST_COL_LEN_TOTAL=%16.16llx\n",  max_DST_COL_LEN_TOTAL);  }
    /* max_SRC0_ROW_LEN      =0000000000001b80 */
    /* max_SRC0_ROW_LEN      =00000000000049e0 */
    /* max_SRC0_ROW_LEN      =0000000000006e00 */
    /* max_SRC0_ROW_LEN      =0000000000012780 */
    /* max_SRC1_COL_LEN_TOTAL=0000000000000920 */
    /* max_SRC1_COL_LEN_TOTAL=0000000000001886 */
    /* max_DST_COL_LEN_TOTAL =0000000000000020 */
    /* max_DST_COL_LEN_TOTAL =0000000000000040 */
#endif
    // monitor_time_start(THREAD, IMAX_CPYIN);
    int ctmp;
    if (src0_preloaded) { /* in init_xmax() */
      /* override i_m0A_TOP */
      i_m0A_TOP = i_m0A[0] + (SRC0_ROW_TOP - SRC0_ROW_TOP_DIRECT);
      Force0=1; /* everytime new address for LMM */
    }
    else if (*(Ull*)i_m0A_TOP   == *(Ull*)SRC0_ROW_TOP) {
    //printf("%d. i_m0A_TOP:%16.16llx %16.16llx S0_TOP:%16.16llx %16.16llx reuse\n", THREAD, i_m0A_TOP, *(Ull*)i_m0A_TOP, SRC0_ROW_TOP, *(Ull*)SRC0_ROW_TOP);
      Force0=0;
    }
    else {
    //printf("%d. i_m0A_TOP:%16.16llx %16.16llx S0_TOP:%16.16llx %16.16llx new\n", THREAD, i_m0A_TOP, *(Ull*)i_m0A_TOP, SRC0_ROW_TOP, *(Ull*)SRC0_ROW_TOP);
      monitor_time_start(THREAD, IMAX_CPYIN_A_Q6K);
      xmax_cpyin(3,i_m0A_TOP,&ctmp,SRC0_ROW_TOP,1,1,SRC0_ROW_LEN,1,1);
      monitor_time_end(THREAD, IMAX_CPYIN_A_Q6K);
      Force0=1; /* force sdat to LMM */
    }
    if (*(Ull*)i_m0B[LANE] == *(Ull*)SRC1_COL_TOP) {
    //printf("%d.B:%16.16llx reuse\n", THREAD, SRC1_COL_TOP);
      Force1=0;
    }
    else {
    //printf("%d.B:%16.16llx new\n", THREAD, SRC1_COL_TOP);
      monitor_time_start(THREAD, IMAX_CPYIN_B_Q6K);
      xmax_cpyin(3,i_m0B[LANE],&ctmp,SRC1_COL_TOP,1,1,SRC1_COL_LEN_TOTAL,1,1);
      monitor_time_end(THREAD, IMAX_CPYIN_B_Q6K);
      Force1=1; /* force wdat to LMM */
    }
    // monitor_time_end(THREAD, IMAX_CPYIN);
    monitor_time_start(THREAD, IMAX_BZERO_Q6K);
    xmax_bzero(i_m0C[LANE], (Ull)DST_COL_LEN_TOTAL);
    Force2 = 1; /* force dst  to LMM */
    monitor_time_end(THREAD, IMAX_BZERO_Q6K);
//  reset_nanosec(LANE);

///////////////////////////////////////////////////////////////////////IMAX����:��������///////////////////

    /*          <----------------------------------src0->data : 110B          x 16  x (16x256=4096) -------------------------------------->   */
    /*                                        cpyin(i_m0A, sizeof(block_q6_K) x nb  x     nr0(4096)                                           */
    /*          <----------------------------------SRC0_ROW_LEN-------------------------------------------------------------------------->    */
    /*          <---------------------nb01(1760,4730)--------------------->xofs=rofs+cofs(hi)   [            blck00dIMAP            ]         */
    /*          [[     110B      ] [     110B      ]     [     110B      ]]:nb(16,43)         x [[blck_0(16) x IIR0_LOOPS(1,4)]/IMAP]         */
    /* SRC0_ROW [i8x32][i8x64][i8x12]F16                                                                                                      */
    /* imax_compute_forward_mul_mat_one_chunk_q6_K()�γ����Ѥ�뤬i_m0A���ѤʤΤǰ��٤���Force-loadɬ��(vsim��,LMM��Ǥ���뤿��Force����)    */
    
    /*          <----------------------------------src1->data : 292B          x 16 x (2) 0----------------------------------------------->    */
    /*                                        cpyin(i_m0B, sizeof(block_q8_K) x nb  x (2)                                                     */
    /*           <--------------------SRC1_COL_LEN_TOTAL-------------------------------------------------------------->                       */
    /*           <--------------------SRC1_COL_LEN_TOTAL------------------->                                                                  */
    /*            <----BKQ8------->cofs(hi)                                                                                                   */
    /*           [[     292B      ] [     292B      ]     [     292B      ]]:nb(16,43)                x IR1_LOOPS(2,1)                        */
    /* SRC1_COL  F32[i8x256][i16x16]                                                                                                          */
    /* imax_compute_forward_mul_mat_one_chunk_q6_K()�γ����Ѥ��ʤ��Τ�1�٤���Force-loadɬ��                                                 */
                       
    /*           <---------------------nb1/sizeof(int)-------------------------------------------------------------->:nb*32                   */
    /*           [                          4B                             ] x  [blck_0(16) x IIR0_LOOPS(1,4)] x IR1_LOOPS(2,1) x nb1/sizeof(int)*/
    /* DST_COL   [                         f32                             ]                         ]                                        */
    /* imax_compute_forward_mul_mat_one_chunk_q6_K()�γ����Ѥ�뤬i_m0C�����ѤʤΤ�1�٤���Force-loadɬ��                                      */
    
    /*           <-------------------------------------DST_COL_LEN_TOTAL--------------------------------------------------------------------> */
    /*           <-------------------------------------DST_COL_LEN_TOTdIMAP---------------------------------------------------------->        */
    /*           <-------------------------------------DST_COL_LENdIMAP-------------------------------------------->                          */
    /*                                                                         [            blck_00dIMAP           ]                          */
    /*           [                          4B                             ] x [[blck_0(16) x IIR0_LOOPS(1,4)]/IMAP] x IIR1_LOOPS(2,1) x IMAP */
    /* i_m0C     [                         f32                             ]                                                                  */
    /* imax_compute_forward_mul_mat_one_chunk_q6_K()�γ����Ѥ�뤬i_m0C�����ѤʤΤǰ��٤���Force-loadɬ��                                     */

    /* S1LEN_TOT=2336(292*16(nb)/4*2(ir1loop)),S0LEN=7040(110*16(nb)/4*16),DSTLEN_TOT=32(dist=16384) */
    for (int64_t iir1 = ir1_start; iir1 < ir1_end; iir1 += blck_1) { /* weight top loop */
      for (int64_t ir1 = iir1; ir1 < iir1 + blck_1 && ir1 < ir1_end; ir1 += num_rows_per_vec_dot) { /* weight sub loop */
      //for (int64_t iir0 = ir0_start; iir0 < ir0_end; iir0 += blck_0) { /* sdata top loop */
	  const int64_t i13 = (ir1 / (ne12 * ne1));
	  const int64_t i12 = (ir1 - i13 * ne12 * ne1) / ne1;
	  const int64_t i11 = (ir1 - i13 * ne12 * ne1 - i12 * ne1);
          const int64_t i03 = i13 / r3;
          const int64_t i02 = i12 / r2;
	  const int64_t i1 = i11;
	  const int64_t i2 = i12;
	  const int64_t i3 = i13;
	  const int64_t blck_00 = blck_0*IIR0_LOOPS;
	  const int64_t blck_00dIMAP = blck_00/IMAP;

	//const char * src0_row = (const char*)SRC0_ROW_TOP;
	  const char * src0_row = (const char*)i_m0A_TOP;
	  Ull          src0_row_qlbase[4][5];  for (j=0; j<5;  j++) src0_row_qlbase[0][j] = (Ull)src0_row+  0+j*8; /* 32B */
	                                       for (j=0; j<5;  j++) src0_row_qlbase[1][j] = (Ull)src0_row+ 32+j*8; /* 32B */
	                                       for (j=0; j<5;  j++) src0_row_qlbase[2][j] = (Ull)src0_row+ 64+j*8; /* 32B */
	                                       for (j=0; j<5;  j++) src0_row_qlbase[3][j] = (Ull)src0_row+ 96+j*8; /* 32B */
	  Ull          src0_row_qhbase[2][5];  for (j=0; j<5;  j++) src0_row_qhbase[0][j] = (Ull)src0_row+128+j*8; /* 32B */
                                         for (j=0; j<5;  j++) src0_row_qhbase[1][j] = (Ull)src0_row+160+j*8; /* 32B */
                                         
	  Ull          src0_row_scbase[16];    for (j=0; j<16; j++) src0_row_scbase[j]    = (Ull)src0_row+192+j;   /* 16B */
	  Ull          src0_row_dbase_p0;                           src0_row_dbase_p0     = (Ull)src0_row+208;     /*  2B */
	  Ull          src0_row_dbase_p8;                           src0_row_dbase_p8     = (Ull)src0_row+208+8;   /*  2B */

	//const char * src1_col = (const char*)wdata + (src1_cont || src1->type != vec_dot_type ? (i11 + i12 * ne11 + i13 * ne12 * ne11) * row_size
	//                                                                                      : (i11 * nb11 + i12 * nb12 + i13 * nb13));
	//const char * src1_col = (const char*)SRC1_COL_TOP + (ir1-ir1_start)*nb11);
	  const char * src1_col = (const char*)i_m0B[LANE]  + (ir1-ir1_start)*sizeof(int)*SRC1_COL_LEN;
	  Ull          src1_col_dbase_p0 = (Ull)src1_col;        /*  4B */
	  Ull          src1_col_dbase_p8 = (Ull)src1_col+8;      /*  4B */
	  Ull          src1_col_base[8][5]; for (i=0; i<8; i++) for (j=0; j<5;  j++) src1_col_base[i][j] = (Ull)src1_col+4+i*32+j*8; /* 256B */

	//float      * dst_col = (float*)((char*)dst->data + (i1 * nb1 + i2 * nb2 + i3 * nb3)) + ir0_start;
	//float      * dst_col = (float*)DST_COL_TOP + (ir1-ir1_start)*nb1/sizeof(int); /* stride nb1/sizeof(int)=4096=nb*32 */
	  float      * dst_col = (float*)i_m0C[LANE] + (ir0_start-ir0_start) + (ir1-ir1_start)*DST_COL_LENdIMAP;/* contiguous */

#define q6_k(r, b0, b1, ql, qh, cvt, cb, tofs, init0, init1, init2, init3) \
	mop(OP_LDBR,  3, &BR[r][0][1],  src0_row_scbase[b0], (Ull)tofs,  MSK_W1, i_m0A_TOP,   SRC0_ROW_LEN,       0, Force0, (Ull)NULL, SRC0_ROW_LEN); /* ..------|-------- -------- -------- XXXXXXXX */\
	mop(OP_LDBR,  3, &BR[r][2][1],  src0_row_scbase[b1], (Ull)tofs,  MSK_W1, i_m0A_TOP,   SRC0_ROW_LEN,       0, Force0, (Ull)NULL, SRC0_ROW_LEN); /* ..------|-------- -------- -------- ZZZZZZZZ */\
\
        exe(OP_MMRG, &r00, 0LL, EXP_H1010,  0LL, EXP_H1010, BR[r][0][1], EXP_H1010,  OP_NOP, 0LL, OP_SRL, 8LL);       /* H1010 */\
        exe(OP_MMRG, &r01, 0LL, EXP_H1010,  0LL, EXP_H1010, BR[r][2][1], EXP_H1010,  OP_NOP, 0LL, OP_SRL, 8LL);       /* H1010 */\
	mop(OP_LDR,   0, &BR[r+1][0][1],  src0_row_qlbase[ql][1], (Ull)iofs,  MSK_W1, i_m0A_TOP,   SRC0_ROW_LEN,       0, Force0, (Ull)NULL, SRC0_ROW_LEN); /* ql 4bit |----llll ----llll ----llll ----LLLL */\
	mop(OP_LDR,   3, &BR[r+1][0][0],  src0_row_qlbase[ql][0], (Ull)iofs,  MSK_W1, i_m0A_TOP,   SRC0_ROW_LEN,       0, Force0, (Ull)NULL, SRC0_ROW_LEN); /* unaligned */\
	mop(OP_LDR,   0, &BR[r+1][1][1],  src0_row_qlbase[ql][2], (Ull)iofs,  MSK_W1, i_m0A_TOP,   SRC0_ROW_LEN,       0, Force0, (Ull)NULL, SRC0_ROW_LEN); /* dismissible */\
	mop(OP_LDR,   3, &BR[r+1][1][0],  src0_row_qlbase[ql][1], (Ull)iofs,  MSK_W1, i_m0A_TOP,   SRC0_ROW_LEN,       0, Force0, (Ull)NULL, SRC0_ROW_LEN); /* unaligned */\
\
	mop(OP_LDR,   0, &BR[r+2][0][1],  src0_row_qhbase[qh][1], (Ull)iofs,  MSK_W1, i_m0A_TOP,   SRC0_ROW_LEN,       0, Force0, (Ull)NULL, SRC0_ROW_LEN); /* qh 2bit |------hh ------hh ------hh ------HH */\
	mop(OP_LDR,   3, &BR[r+2][0][0],  src0_row_qhbase[qh][0], (Ull)iofs,  MSK_W1, i_m0A_TOP,   SRC0_ROW_LEN,       0, Force0, (Ull)NULL, SRC0_ROW_LEN); /* unaligned */\
	mop(OP_LDR,   0, &BR[r+2][1][1],  src0_row_qhbase[qh][2], (Ull)iofs,  MSK_W1, i_m0A_TOP,   SRC0_ROW_LEN,       0, Force0, (Ull)NULL, SRC0_ROW_LEN); /* dismissible */\
	mop(OP_LDR,   3, &BR[r+2][1][0],  src0_row_qhbase[qh][1], (Ull)iofs,  MSK_W1, i_m0A_TOP,   SRC0_ROW_LEN,       0, Force0, (Ull)NULL, SRC0_ROW_LEN); /* unaligned */\
\
	exe(OP_CVT86, &r04, r00, cvt,  BR[r+2][0][0], EXP_B5410, BR[r+1][0][0], EXP_B5410, OP_NOP, 0LL, OP_NOP, 8LL);   /* XXXXXXXX-(8bit)*HQQ (sc * qh|ql) -> x[ 7: 0] */\
	exe(OP_CVT86, &r05, r00, cvt,  BR[r+2][0][0], EXP_B7632, BR[r+1][0][0], EXP_B7632, OP_NOP, 0LL, OP_NOP, 8LL);   /* XXXXXXXX-(8bit)*HQQ (sc * qh|ql) -> x[ 7: 0] */\
	exe(OP_CVT86, &r06, r00, cvt,  BR[r+2][1][0], EXP_B5410, BR[r+1][1][0], EXP_B5410, OP_NOP, 0LL, OP_NOP, 8LL);   /* XXXXXXXX-(8bit)*HQQ (sc * qh|ql) -> x[15: 8] */\
	exe(OP_CVT86, &r07, r00, cvt,  BR[r+2][1][0], EXP_B7632, BR[r+1][1][0], EXP_B7632, OP_NOP, 0LL, OP_NOP, 8LL);   /* XXXXXXXX-(8bit)*HQQ (sc * qh|ql) -> x[15: 8] */\
	mop(OP_LDR,   0, &BR[r+3][0][1], src1_col_base[cb][1], (Ull)iofs,  MSK_W0, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)NULL, SRC1_COL_LEN_TOTAL); /* dismissible */\
	mop(OP_LDR,   3, &BR[r+3][0][0], src1_col_base[cb][0], (Ull)iofs,  MSK_W0, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)NULL, SRC1_COL_LEN_TOTAL); /* unaligned */\
	mop(OP_LDR,   0, &BR[r+3][1][1], src1_col_base[cb][2], (Ull)iofs,  MSK_W0, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)NULL, SRC1_COL_LEN_TOTAL); /* dismissible */\
	mop(OP_LDR,   3, &BR[r+3][1][0], src1_col_base[cb][1], (Ull)iofs,  MSK_W0, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)NULL, SRC1_COL_LEN_TOTAL); /* unaligned */\
\
        exe(OP_SML16,    &r20,  r04,  EXP_H3210, BR[r+3][0][0],    EXP_B5410, 0LL, EXP_H3210,  OP_AD32, init0, OP_NOP, 0LL); /* sdata,wdata */\
        exe(OP_SML16,    &r21,  r05,  EXP_H3210, BR[r+3][0][0],    EXP_B7632, 0LL, EXP_H3210,  OP_AD32, init1, OP_NOP, 0LL); /* sdata,wdata */\
        exe(OP_SML16,    &r22,  r06,  EXP_H3210, BR[r+3][1][0],    EXP_B5410, 0LL, EXP_H3210,  OP_AD32, init2, OP_NOP, 0LL); /* sdata,wdata */\
        exe(OP_SML16,    &r23,  r07,  EXP_H3210, BR[r+3][1][0],    EXP_B7632, 0LL, EXP_H3210,  OP_AD32, init3, OP_NOP, 0LL); /* sdata,wdata */\
	mop(OP_LDR,   0, &BR[r+4][2][1],  src0_row_qlbase[ql][3], (Ull)iofs,  MSK_W1, i_m0A_TOP,   SRC0_ROW_LEN,       0, Force0, (Ull)NULL, SRC0_ROW_LEN); /* dismissible */\
	mop(OP_LDR,   3, &BR[r+4][2][0],  src0_row_qlbase[ql][2], (Ull)iofs,  MSK_W1, i_m0A_TOP,   SRC0_ROW_LEN,       0, Force0, (Ull)NULL, SRC0_ROW_LEN); /* unaligned */\
	mop(OP_LDR,   0, &BR[r+4][3][1],  src0_row_qlbase[ql][4], (Ull)iofs,  MSK_W1, i_m0A_TOP,   SRC0_ROW_LEN,       0, Force0, (Ull)NULL, SRC0_ROW_LEN); /* dismissible */\
	mop(OP_LDR,   3, &BR[r+4][3][0],  src0_row_qlbase[ql][3], (Ull)iofs,  MSK_W1, i_m0A_TOP,   SRC0_ROW_LEN,       0, Force0, (Ull)NULL, SRC0_ROW_LEN); /* unaligned */\
\
	mop(OP_LDR,   0, &BR[r+5][2][1],  src0_row_qhbase[qh][3], (Ull)iofs,  MSK_W1, i_m0A_TOP,   SRC0_ROW_LEN,       0, Force0, (Ull)NULL, SRC0_ROW_LEN); /* dismissible */\
	mop(OP_LDR,   3, &BR[r+5][2][0],  src0_row_qhbase[qh][2], (Ull)iofs,  MSK_W1, i_m0A_TOP,   SRC0_ROW_LEN,       0, Force0, (Ull)NULL, SRC0_ROW_LEN); /* unaligned */\
	mop(OP_LDR,   0, &BR[r+5][3][1],  src0_row_qhbase[qh][4], (Ull)iofs,  MSK_W1, i_m0A_TOP,   SRC0_ROW_LEN,       0, Force0, (Ull)NULL, SRC0_ROW_LEN); /* dismissible */\
	mop(OP_LDR,   3, &BR[r+5][3][0],  src0_row_qhbase[qh][3], (Ull)iofs,  MSK_W1, i_m0A_TOP,   SRC0_ROW_LEN,       0, Force0, (Ull)NULL, SRC0_ROW_LEN); /* unaligned */\
\
	exe(OP_CVT86, &r08, r01, cvt,  BR[r+5][2][0], EXP_B5410, BR[r+4][2][0], EXP_B5410, OP_NOP, 0LL, OP_NOP, 8LL);   /* ZZZZZZZZ-(8bit)*HQQ (sc * qh|ql) -> x[23:16] */\
	exe(OP_CVT86, &r09, r01, cvt,  BR[r+5][2][0], EXP_B7632, BR[r+4][2][0], EXP_B7632, OP_NOP, 0LL, OP_NOP, 8LL);   /* ZZZZZZZZ-(8bit)*HQQ (sc * qh|ql) -> x[23:16] */\
	exe(OP_CVT86, &r10, r01, cvt,  BR[r+5][3][0], EXP_B5410, BR[r+4][3][0], EXP_B5410, OP_NOP, 0LL, OP_NOP, 8LL);   /* ZZZZZZZZ-(8bit)*hQQ (sc * qh|ql) -> x[31:24] */\
	exe(OP_CVT86, &r11, r01, cvt,  BR[r+5][3][0], EXP_B7632, BR[r+4][3][0], EXP_B7632, OP_NOP, 0LL, OP_NOP, 8LL);   /* ZZZZZZZZ-(8bit)*hQQ (sc * qh|ql) -> x[31:24] */\
	mop(OP_LDR,   0, &BR[r+6][2][1], src1_col_base[cb][3], (Ull)iofs,  MSK_W0, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)NULL, SRC1_COL_LEN_TOTAL); /* dismissible */\
	mop(OP_LDR,   3, &BR[r+6][2][0], src1_col_base[cb][2], (Ull)iofs,  MSK_W0, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)NULL, SRC1_COL_LEN_TOTAL); /* unaligned */\
	mop(OP_LDR,   0, &BR[r+6][3][1], src1_col_base[cb][4], (Ull)iofs,  MSK_W0, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)NULL, SRC1_COL_LEN_TOTAL); /* dismissible */\
	mop(OP_LDR,   3, &BR[r+6][3][0], src1_col_base[cb][3], (Ull)iofs,  MSK_W0, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)NULL, SRC1_COL_LEN_TOTAL); /* unaligned */\
\
        exe(OP_SML16,    &r24,  r08,  EXP_H3210, BR[r+6][2][0],    EXP_B5410, 0LL, EXP_H3210,  OP_AD32, r20, OP_NOP, 0LL); /* sdata,wdata */\
        exe(OP_SML16,    &r25,  r09,  EXP_H3210, BR[r+6][2][0],    EXP_B7632, 0LL, EXP_H3210,  OP_AD32, r21, OP_NOP, 0LL); /* sdata,wdata */\
        exe(OP_SML16,    &r26,  r10,  EXP_H3210, BR[r+6][3][0],    EXP_B5410, 0LL, EXP_H3210,  OP_AD32, r22, OP_NOP, 0LL); /* sdata,wdata */\
        exe(OP_SML16,    &r27,  r11,  EXP_H3210, BR[r+6][3][0],    EXP_B7632, 0LL, EXP_H3210,  OP_AD32, r23, OP_NOP, 0LL)  /* sdata,wdata */

      //printf("q6k: blck_00dIMAP=%d nb01=%d nb=%d\n", (Uint)blck_00dIMAP, (Uint)nb01, (Uint)nb);
      //              q6k=210B blk0=16 nb=14(3584/QK256) ->47040B /4=11760(=SRC0_LEN) nb01=2940 = 210B*14(nb)
//EMAX5A begin mul_mat_one_chunk_q6k mapdist=0
     /*3*/for (CHIP=0; CHIP<NCHIP; CHIP++) { /* will be parallelized by multi-chip (M/#chip) */
       /*2*/for (INIT1=1,LOOP1=blck_00dIMAP,rofs=MNB01_M4; LOOP1--; INIT1=0) { /* stage#0 *//* mapped to FOR() on BR[63][1][0] *//* sdata  sub loop *//* blck_0=16 */
         /*1*/for (INIT0=1,LOOP0=nb,cofs=MBKQ6_MBKQ8; LOOP0--; INIT0=0) { /* stage#0 *//* mapped to FOR() on BR[63][0][0] *//* 34B   x nb loop *//* nb=128,344 LMM=17408,46784word */
		exe(OP_ADD,      &rofs,  rofs,            EXP_H3210, INIT0?NB01_4:0, EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL,                  OP_NOP, 0LL); /* |x:NB01|d:   4| stage#0 */
                exe(OP_ADD,      &cofs,  INIT0?cofs:cofs, EXP_H3210, BKQ6_BKQ8,      EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL,                  OP_NOP, 0LL); /* |x:BKQ8|d:   0| stage#0 */
	        exe(OP_ADD,      &xofs,  rofs,            EXP_H3210, cofs,           EXP_H3210, 0LL, EXP_H3210, OP_AND, 0xffffffff00000000LL, OP_NOP, 0LL); /*                 stage#1 */
	        exe(OP_ADD,      &yofs,  0LL,             EXP_H3210, cofs,           EXP_H3210, 0LL, EXP_H3210, OP_AND, 0x00000000ffffffffLL, OP_NOP, 0LL); /*                 stage#1 */
	        exe(OP_ADD,      &oofs,  rofs,            EXP_H3210, 0LL,            EXP_H3210, 0LL, EXP_H3210, OP_AND, 0x00000000ffffffffLL, OP_NOP, 0LL); /*                 stage#1 */
	        exe(OP_NOP,      &iofs,  xofs,            EXP_H3210, 0LL,            EXP_H3210, 0LL, EXP_H3210, OP_OR,  yofs,                 OP_NOP, 0LL); /*                 stage#2 */
#if 0
		/************************************************************************************************/
		/*  qh0-31   2222  2222  2222  2222  2222  2222  2222  2222  ... x32     */
		/*              x     x     x     x     x     x     x     x  *//*  0- 31 */
		/*             x     x     x     x     x     x     x     x   *//* 32- 63 */
		/*            x     x     x     x     x     x     x     x    *//* 64- 95 */
		/*           x     x     x     x     x     x     x     x     *//* 96-127 */
		/*  qh32-63  2222  2222  2222  2222  2222  2222  2222  2222  ... x32     */
		/*              x     x     x     x     x     x     x     x  *//*128-159 */
		/*             x     x     x     x     x     x     x     x   *//*160-191 */
		/*            x     x     x     x     x     x     x     x    *//*192-223 */
		/*           x     x     x     x     x     x     x     x     *//*224-255 */
		/*  ql0-31   44 44 44 44 44 44 44 44 44 44 44 44 44 44 44 44 ... x32     */
		/*            x  x  x  x  x  x  x  x  x  x  x  x  x  x  x  x *//*  0- 31 */
		/*           x  x  x  x  x  x  x  x  x  x  x  x  x  x  x  x  *//* 64- 95 */
		/*  ql32-63  44 44 44 44 44 44 44 44 44 44 44 44 44 44 44 44 ... x32     */
		/*            x  x  x  x  x  x  x  x  x  x  x  x  x  x  x  x *//* 32- 63 */
		/*           x  x  x  x  x  x  x  x  x  x  x  x  x  x  x  x  *//* 96-127 */
		/*  ql64-95  44 44 44 44 44 44 44 44 44 44 44 44 44 44 44 44 ... x32     */
		/*            x  x  x  x  x  x  x  x  x  x  x  x  x  x  x  x *//*128-159 */
		/*           x  x  x  x  x  x  x  x  x  x  x  x  x  x  x  x  *//*192-223 */
		/*  ql96-127 44 44 44 44 44 44 44 44 44 44 44 44 44 44 44 44 ... x32     */
		/*            x  x  x  x  x  x  x  x  x  x  x  x  x  x  x  x *//*160-191 */
		/*           x  x  x  x  x  x  x  x  x  x  x  x  x  x  x  x  *//*224-255 */
		int8_t   aux8[QK_K]; /* 6bit: -32 ..+31 */
		for (int l = 0; l < 32; ++l) aux8[l    ] = ((((x[xi].qh[l   ] >> 0) & 3) << 4) | (x[xi].ql[l    ] & 0xF)) - 32;
		for (int l = 0; l < 32; ++l) aux8[l+ 32] = ((((x[xi].qh[l   ] >> 2) & 3) << 4) | (x[xi].ql[l+ 32] & 0xF)) - 32;
		for (int l = 0; l < 32; ++l) aux8[l+ 64] = ((((x[xi].qh[l   ] >> 4) & 3) << 4) | (x[xi].ql[l    ] >>  4)) - 32;
		for (int l = 0; l < 32; ++l) aux8[l+ 96] = ((((x[xi].qh[l   ] >> 6) & 3) << 4) | (x[xi].ql[l+ 32] >>  4)) - 32;
		for (int l = 0; l < 32; ++l) aux8[l+128] = ((((x[xi].qh[l+32] >> 0) & 3) << 4) | (x[xi].ql[l+ 64] & 0xF)) - 32;
		for (int l = 0; l < 32; ++l) aux8[l+160] = ((((x[xi].qh[l+32] >> 2) & 3) << 4) | (x[xi].ql[l+ 96] & 0xF)) - 32;
		for (int l = 0; l < 32; ++l) aux8[l+192] = ((((x[xi].qh[l+32] >> 4) & 3) << 4) | (x[xi].ql[l+ 64] >>  4)) - 32;
		for (int l = 0; l < 32; ++l) aux8[l+224] = ((((x[xi].qh[l+32] >> 6) & 3) << 4) | (x[xi].ql[l+ 96] >>  4)) - 32;
		/***********************************************************************************************************************************************************************************/
		/* x[i].scales[15][14][13][12][11][10][ 9][ 8][ 7][ 6][ 5][ 4][ 3][ 2][ 1][ 0]                                                                                                     */
		/* q8[255]*aux8[255] q8[254]*aux8[254] ... q8[16]*aux8[16] | q8[15]*aux8[15] ... q8[6]*aux8[6] q8[5]*aux8[5] q8[4]*aux8[4] q8[3]*aux8[3] q8[2]*aux8[2] q8[1]*aux8[1] q8[0]*aux8[0] */
                /*        *                 *                    *         |       *                  *             *             *             *             *             *             *        */
                /*     scale[15]         scale[15]            scale[1]     |    scale[0]           scale[0]      scale[0]      scale[0]      scale[0]      scale[0]      scale[0]      scale[0]    */
                /* ��(8bit*8bit*8bit)                                      | ��(8bit*8bit*8bit)                                                                                                    */
                /*     aux32[7]          aux32[6]             aux32[0]     |    aux32[7]           aux32[6]      aux32[5]      aux32[4]      aux32[3]      aux32[2]      aux32[1]      aux32[0]    */
		/***********************************************************************************************************************************************************************************/
#endif
		/*******************************************************************************************************************************************/
		/*                   LDB              LDB              LDB              LDB x[i].sc                                                   8bit */
		/*               LDR&LDR          LDR&LDR          LDR&LDR          LDR&LDR x[i].ql                                                   4bit */
		/*               LDR&LDR          LDR&LDR          LDR&LDR          LDR&LDR x[i].qh                                                   2bit */
		/*                 CVT86            CVT86            CVT86            CVT86                                                                */
		/* EXP_CVT00 0: src1(sc)=-----sc|-----sc  src2(qh)=..|------hh ------hh ------hh ------hh  src3(ql)=..|----llll ----llll ----llll ----llll */
		/* EXP_CVT01 1: src1(sc)=-----sc|-----sc  src2(qh)=..|----hh-- ----hh-- ----hh-- ----hh--  src3(ql)=..|llll---- llll---- llll---- llll---- */
		/* EXP_CVT02 2: src1(sc)=-----sc|-----sc  src2(qh)=..|--hh---- --hh---- --hh---- --hh----  src3(ql)=..|----llll ----llll ----llll ----llll */
		/* EXP_CVT03 3: src1(sc)=-----sc|-----sc  src2(qh)=..|hh------ hh------ hh------ hh------  src3(ql)=..|llll---- llll---- llll---- llll---- */
		/*(EXP_CVT04 4: src1(sc)=-----sc|-----sc  src2(qh)=..|------hh ------hh ------hh ------hh  src3(ql)=..|----llll ----llll ----llll ----llll)*/
		/*(EXP_CVT05 5: src1(sc)=-----sc|-----sc  src2(qh)=..|----hh-- ----hh-- ----hh-- ----hh--  src3(ql)=..|llll---- llll---- llll---- llll----)*/
		/*(EXP_CVT06 6: src1(sc)=-----sc|-----sc  src2(qh)=..|--hh---- --hh---- --hh---- --hh----  src3(ql)=..|----llll ----llll ----llll ----llll)*/
		/*(EXP_CVT07 7: src1(sc)=-----sc|-----sc  src2(qh)=..|hh------ hh------ hh------ hh------  src3(ql)=..|llll---- llll---- llll---- llll----)*/
		/*      ffffffffffffffff ffffffffffffffff ffffffffffffffff ffffffffffffffff                                                                */
		/*               LDR&LDR          LDR&LDR          LDR&LDR          LDR&LDR y[i].qs 32B                                               8bit */
		/*               [31:24]          [23:16]          [15: 8]          [ 7: 0]                                                                */
		/*      ffffffffffffffff ffffffffffffffff ffffffffffffffff ffffffffffffffff                                                                */
		/*               dual(8b*6b + 8b*6b) -> dual(15bit) ��32(8b*6b) -> ��32(14bit) -> 19bit                                                    */
		/*               SML16            SML16            SML16            SML16   EXP_H3210                                                      */
		/*               SML16            SML16            SML16            SML16   EXP_H3210                                                      */
		/*  :x8 = ��256                                                                                                                            */
		/*********************************************************************************************************************************************/
   	        /* #0 of auxx[32]/256 */
	        q6_k( 2,  0,  1,  0,  0, EXP_CVT00, 0, xofs, 0LL, 0LL, 0LL, 0LL);
 	        /*********************************************************************************************************************************************/
	        /* #1 of auxx[32]/256 */
	        q6_k( 9,  2,  3,  1,  0, EXP_CVT01, 1, iofs, r24, r25, r26, r27);
	        /*********************************************************************************************************************************************/
	        /* #2 of auxx[32]/256 */
	        q6_k(16,  4,  5,  0,  0, EXP_CVT02, 2, iofs, r24, r25, r26, r27);
	        /*********************************************************************************************************************************************/
	        /* #3 of auxx[32]/256 */
	        q6_k(23,  6,  7,  1,  0, EXP_CVT03, 3, iofs, r24, r25, r26, r27);
	        /*********************************************************************************************************************************************/
	        /* #4 of auxx[32]/256 */
	        q6_k(30,  8,  9,  2,  1, EXP_CVT04, 4, iofs, r24, r25, r26, r27);
	        /*********************************************************************************************************************************************/
 	        /* #5 of auxx[32]/256 */
	        q6_k(37, 10, 11,  3,  1, EXP_CVT05, 5, iofs, r24, r25, r26, r27);
	        /*********************************************************************************************************************************************/
	        /* #6 of auxx[32]/256 */
	        q6_k(44, 12, 13,  2,  1, EXP_CVT06, 6, iofs, r24, r25, r26, r27);
	        /*********************************************************************************************************************************************/
   	        /* #7 of auxx[32]/256 */
	        q6_k(51, 14, 15,  3,  1, EXP_CVT07, 7, iofs, r24, r25, r26, r27);
		/*********************************************************************************************************************************************/
		/* Reduction */
	        exe(OP_NOP,      &r28,  r24,          EXP_H3210, 0LL,            EXP_H3210, 0LL, EXP_H3210, OP_AD32, r25, OP_NOP, 0LL);                      /* stage #59 */
	        exe(OP_NOP,      &r29,  r26,          EXP_H3210, 0LL,            EXP_H3210, 0LL, EXP_H3210, OP_AD32, r27, OP_NOP, 0LL);                      /* stage #59 */
		mop(OP_LDR,   0, &BR[59][0][1], src0_row_dbase_p8,   (Ull)iofs,  MSK_W1, i_m0A_TOP,  SRC0_ROW_LEN,       0, Force0, (Ull)NULL, SRC0_ROW_LEN);/* stage #59 */ /* dismissible */
		mop(OP_LDR,   3, &BR[59][0][0], src0_row_dbase_p0,   (Ull)iofs,  MSK_W1, i_m0A_TOP,  SRC0_ROW_LEN,       0, Force0, (Ull)NULL, SRC0_ROW_LEN);/* stage #59 */ /* unaligned */

	        exe(OP_NOP,      &r30,  r28,          EXP_H3210, 0LL,            EXP_H3210, 0LL, EXP_H3210, OP_AD32, r29, OP_NOP, 0LL);                      /* stage #60 */
	        exe(OP_NOP,      &r13,  BR[59][0][0], EXP_H3210, 0LL,            EXP_H3210, 0LL, EXP_H3210, OP_AND, 0x000000000000ffffLL, OP_SLL, 2LL);      /* x.d   fp16->fp32 *//* stage #60 */
		mop(OP_LDR,   0, &BR[60][0][1], src1_col_dbase_p8,   (Ull)iofs,  MSK_W0, i_m0B[LANE],SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)NULL, SRC1_COL_LEN_TOTAL);/* stage #60 */ /* dismissible */
		mop(OP_LDR,   3, &BR[60][0][0], src1_col_dbase_p0,   (Ull)iofs,  MSK_W0, i_m0B[LANE],SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)NULL, SRC1_COL_LEN_TOTAL);/* stage #60 */ /* unaligned */

	        exe(OP_NOP,      &r31,  r30,          EXP_H3232, 0LL,            EXP_H3210, 0LL, EXP_H3210, OP_AD32, r30, OP_NOP, 0LL); /* aux32 */          /* stage #61 */
		mop(OP_LDWR,  3, &BR[61][2][1], (Ull)i_f16[LANE],    (Ull)r13,   MSK_W0, (Ull)i_f16[LANE], 65536, 0, 0, (Ull)NULL, 65536);                   /* x.d   fp16->fp32 *//* stage #61 */

              //*(float*)&r02 = *(float*)&BR[60][0][0] * (int)r31; /* FMI */
                exe(OP_FMI,      &r02,  BR[60][0][0], EXP_H3210, r31,            EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);                       /* y.d * aux32 */
		/* Sum */
	        exe(OP_NOP,      &AR[63][0], 0LL,     EXP_H3210, 0LL,            EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);                       /* stage#63 (dummy to set target location) */
	        mop(OP_LDWR,  1, &r00,       dst_col,            oofs,           MSK_W0, i_m0C_TOP_IMAP[0][LANE], DST_COL_LEN_TOTdIMAP,  0, Force2, (Ull)NULL, DST_COL_LEN_TOTdIMAP); /* stage#63 */
	        exe(OP_FMA,      &r00, INIT0?r00:r00, EXP_H3210, r02,            EXP_H3210, BR[61][2][1], EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);                       /* x.d * y.d * aux32 * 512 */
	        mop(OP_STWR,  1, &r00,       oofs,               dst_col,        MSK_D0, i_m0C_TOP_IMAP[0][LANE], DST_COL_LEN_TOTdIMAP,  0, Force2, (Ull)NULL, DST_COL_LEN_TOTdIMAP);
	      }
	    }
          }
//EMAX5A end
          if (Force0) Force0 = 0; /* reset sdat to LMM */
          if (Force1) Force1 = 0; /* reset wdat to LMM */
          if (Force2) Force2 = 0; /* reset dst  to LMM */
      //}
      }
    }
//EMAX5A drain_dirty_lmm
///////////////////////////////////////////////////////////////////////IMAX����:�����ޤ�///////////////////

//  get_nanosec(LANE,0);
//  show_nanosec(LANE);
    monitor_time_start(THREAD, IMAX_CPYOUT_Q6K);
    if (!((Ull)DST_COL_TOP & 63) && !((Ull)i_m0C[LANE] & 63) && DST_COL_LENdIMAP == 16 && IMAP == 1) { // 64B aligned
      for (int i=0; i<IR1_LOOPS; i++) { /* stride */
	Dll *dst = (int*)DST_COL_TOP+i*nb1/sizeof(int);
	Dll *src = (int*)i_m0C[LANE]+i*16;
	*dst++ = *src++; /* 4word */
	*dst++ = *src++; /* 4word */
	*dst++ = *src++; /* 4word */
	*dst++ = *src++; /* 4word */
      }
    }
    else
      xmax_cpyout(4, DST_COL_TOP, 1, nb1/sizeof(int), i_m0C[LANE], (Ull)IR1_LOOPS, (Ull)DST_COL_LENdIMAP, IMAP); /* stride */
    monitor_time_end(THREAD, IMAX_CPYOUT_Q6K);
  }
}


void imax_compute_forward_mul_mat_one_chunk_q8_0(struct th_inference_args *args)
{
  int                                THREAD       = args->thid; /* < NTHREAD vsim.cpp NTHREAD=2                  */
  int                                LANE         = args->thid; /* < NLANE   emax7.h  init_xmax(){NLANE=NTHREAD} */
  struct ggml_tensor *               dst          = args->dst;
  const int64_t                      num_rows_per_vec_dot = args->num_rows_per_vec_dot;
  const int64_t                      ir0_start    = args->ir0_start;
  const int64_t                      ir0_end      = args->ir0_end;
  const int64_t                      ir1_start    = args->ir1_start;
  const int64_t                      ir1_end      = args->ir1_end;
  const struct ggml_tensor *         src0         = args->src0;
  const struct ggml_tensor *         src1         = args->src1;
  const enum ggml_type               type         = args->type; /* 0:F32 1:F16 8:Q8_0 10:Q2_K 11:Q3_K 14:Q6_K */
  const bool                         src1_cont    = args->src1_cont;
  ggml_vec_dot_t const               vec_dot      = args->vec_dot;
  enum ggml_type const               vec_dot_type = args->vec_dot_type;
  const void *                       wdata        = args->wdata;
  const size_t                       row_size     = args->row_size;
  const int64_t                      r2           = args->r2;
  const int64_t                      r3           = args->r3;
  const int64_t                      blck_0       = args->blck_0;
  const int64_t                      blck_1       = args->blck_1;
  const size_t                       src1_col_stride = args->src1_col_stride;
  int   i, j;
  float tmp[32];
  GGML_TENSOR_BINARY_OP_LOCALS
  int       n  = ne00;
  const int nb = n / QK8_0; /* 128,344 */
// printf("nb=%d\n", nb);
  Ull   IIR1_LOOPS         = (ir1_end-ir1_start)/blck_1;                         /* src1 の範囲 (ir1_end - ir1_start) の中に、サイズ blck_1 のブロックが完全に収まる回数を計                  */
  Ull   IIR0_LOOPS         = (ir0_end-ir0_start)/blck_0;                         /* ??iir0-loop???                  */
  Ull   IR1_LOOPS          = MIN(ir1_start+blck_1,ir1_end)-ir1_start;            /* ??ir1-loop???                   */
  Ull   SRC0_ROW_LEN       = sizeof(block_q8_0)*nb*blck_0*IIR0_LOOPS/sizeof(int);/* ??iir0-loop????                */
  Ull   SRC1_COL_LEN       = sizeof(block_q8_0)*nb/sizeof(int);                  /* ??ir1-loop????                 */
  Ull   SRC1_COL_LEN_TOTAL = SRC1_COL_LEN*IR1_LOOPS;                             /* ??ir1-loop????                 */
  Ull   DST_COL_LEN        = blck_0*IIR0_LOOPS;                                  /* ??ir1-loop????????(nb1-byte*iir0-loop) */
  Ull   DST_COL_LEN_TOTAL  = DST_COL_LEN*IR1_LOOPS;                              /* ??ir1-loop????????(nb1-byte*iir0-loop) */
  // if (SRC0_ROW_LEN>32*1024/sizeof(int)){printf("over size!!!!!!");}
    //  printf("wdata=%16.16llx\n",*(Ull*)wdata);
  if (SRC0_ROW_LEN >512*1024/sizeof(int) || ((ir0_end - ir0_start) % blck_0) || num_rows_per_vec_dot != 1) { /* check LMM_SIZE, and start ARM if NG */
  // if ( 1) { /* check LMM_SIZE, and start ARM if NG */
    monitor_time_start(THREAD, IMAX_COMPUTE_FORWARD_MUL_MAT_ONE_CHUNK_Q80_ARM); /* Nakashima */
    // printf("imax_compute_forward_mul_mat_one_chunk_q8_0\n");
    for (int64_t iir1 = ir1_start; iir1 < ir1_end; iir1 += blck_1) { /* weight top loop */
      for (int64_t iir0 = ir0_start; iir0 < ir0_end; iir0 += blck_0) { /* sdata top loop */
	for (int64_t ir1 = iir1; ir1 < iir1 + blck_1 && ir1 < ir1_end; ir1 += num_rows_per_vec_dot) { /* weight sub loop */
	  const int64_t i13 = (ir1 / (ne12 * ne1));
	  const int64_t i12 = (ir1 - i13 * ne12 * ne1) / ne1;
	  const int64_t i11 = (ir1 - i13 * ne12 * ne1 - i12 * ne1);
          const int64_t i03 = i13 / r3;
          const int64_t i02 = i12 / r2;
	  const int64_t i1 = i11;
	  const int64_t i2 = i12;
	  const int64_t i3 = i13;

	  const char * src0_row = (const char*)src0->data + (0 + i02 * nb02 + i03 * nb03);
	  const char * src1_col = (const char*)wdata + (src1_cont || src1->type != vec_dot_type ? (i11 + i12 * ne11 + i13 * ne12 * ne11) * row_size
	                                                                                        : (i11 * nb11 + i12 * nb12 + i13 * nb13));
	  float * dst_col = (float*)((char*)dst->data + (i1 * nb1 + i2 * nb2 + i3 * nb3));
    
        //printf("src0_row=%16.16llx ir0=%16.16llx-%16.16llx (step=%16.16llx) ne00=%08.08x nb01=%08.08x\n", src0_row, iir0, iir0 + blck_0, num_rows_per_vec_dot, (int)ne00, (int)nb01);
	  for (int64_t ir0 = iir0; ir0 < iir0 + blck_0 && ir0 < ir0_end; ir0 += num_rows_per_vec_dot) /* ne00=4096(0x1000) 4096/32*34=0x1100??��?,0x1100B??????????? */
	    vec_dot(ne00, &tmp[ir0 - iir0], (num_rows_per_vec_dot > 1 ? 16 : 0), src0_row + ir0 * nb01, (num_rows_per_vec_dot > 1 ? nb01 : 0), src1_col, (num_rows_per_vec_dot > 1 ? src1_col_stride : 0), num_rows_per_vec_dot);
        // for (int t = 0; t < 32; ++t) {
        //                 if (isnan(tmp[t])) printf("NaN in tmp[%d] ", t);
        //             }

	  monitor_time_start(THREAD, ARM_MEMCPY); /* Nakashima */
	  for (int cn = 0; cn < num_rows_per_vec_dot; ++cn) /* num_rows_per_vec_dot=1 */
	    memcpy(&dst_col[iir0 + cn * nb1 / nb0], tmp + (cn * 16), (MIN(iir0 + blck_0, ir0_end) - iir0) * sizeof(float));
	  monitor_time_end(THREAD, ARM_MEMCPY); /* Nakashima */
	}
      }
    }
    monitor_time_end(THREAD, IMAX_COMPUTE_FORWARD_MUL_MAT_ONE_CHUNK_Q80_ARM); /* Nakashima */
  }

  else { /* IMAX */
#undef  IMAP
#undef  NCHIP
#define IMAP  4
#define NCHIP 1

    // printf("imax_compute_forward_mul_mat_one_chunk_q8_0 (IMAX path) - Thread %d, Lane %d\n", THREAD, LANE);
    // printf("  data copied: SRC0_ROW_LEN=%llu bytes, SRC1_COL_LEN_TOTAL=%llu bytes\n", SRC0_ROW_LEN * sizeof(int), SRC1_COL_LEN_TOTAL * sizeof(int));
    // printf("  max buffer sizes: i_m0A=%llu bytes, i_m0B=%llu bytes, i_m0C=%llu bytes\n", i_m0A_max_size, i_m0B_max_size, i_m0C_max_size);

    Ull   CHIP, rofs, cofs, iofs, oofs;
    Ull   LOOP1, LOOP0;
    Ull   INIT1, INIT0;
    Ull   AR[64][4];                     /* output of EX     in each unit */
    Ull   BR[64][4][4];                  /* output registers in each unit */
    Ull   r00, r01, r02, r03, r04, r05, r06, r07, r08, r09, r10, r11, r12, r13, r14, r15;
    Ull   r16, r17, r18, r19, r20, r21, r22, r23, r24, r25, r26, r27, r28, r29, r30, r31;
    Ull   cc0, cc1, cc2, cc3, ex0, ex1, out0, out1, out2, out10;
    Ull   Force0, Force1, Force2; /* force to LMM */

    Ull   MNB01_M4    = (0LL-nb01              )<<32|((0LL-sizeof(float))&0xffffffffLL);
    Ull   MBKQ8_0000  = (0LL-sizeof(block_q8_0))<<32|((0LL-4LL          )&0xffffffffLL);
    Ull   NB01_4      = (0LL+nb01              )<<32|((0LL+sizeof(float))&0xffffffffLL);
    Ull   BKQ8_0000   = (0LL+sizeof(block_q8_0))<<32|((0LL+4LL          )&0xffffffffLL);

    const int64_t i13_top = (ir1_start          / (ne12 * ne1));          /* ==0 */
    const int64_t i12_top = (ir1_start - i13_top * ne12 * ne1) / ne1;     /* ==0 */
    const int64_t i11_top = (ir1_start - i13_top * ne12 * ne1 - i12_top * ne1);
    const int64_t i03_top = i13_top / r3;
    const int64_t i02_top = i12_top / r2;
    Ull   SRC0_ROW_TOP       = (const char*)src0->data  + (0 + i02_top * nb02 + i03_top * nb03) + ir0_start*nb01;
    Ull   SRC0_ROW_LENdIMAP  = SRC0_ROW_LEN/IMAP;

    Ull   i_m0A_TOP          = (const char*)i_m0A[LANE] + (0 + i02_top * nb02 + i03_top * nb03) + ir0_start*nb01;
    Ull   SRC1_COL_TOP       = (const char*)wdata       + (src1_cont || src1->type != vec_dot_type ? (i11_top + i12_top * ne11 + i13_top * ne12 * ne11) * row_size /* 4352(0x1100),11696(0x2db0) */
	                                                                                           : (i11_top * nb11 + i12_top * nb12 + i13_top * nb13));
 
    Ull   DST_COL_TOP        = (float*)((char*)dst->data + (i11_top * nb1 + i12_top * nb2 + i13_top * nb3)) + ir0_start;
    Ull   DST_COL_LENdIMAP   = DST_COL_LEN/IMAP;         /* TOTAL = [[blck_0(16) x IIR0_LOOPS(1,4)]/IMAP] x IIR1_LOOPS(2,1) x IMAP */
    Ull   DST_COL_LEN_TOTdIMAP = DST_COL_LEN_TOTAL/IMAP; /* TOTAL = [[blck_0(16) x IIR0_LOOPS(1,4)]/IMAP] x IIR1_LOOPS(2,1) x IMAP */
    Ull   i_m0C_TOP_IMAP[IMAP][EMAX_NLANE]; for (i=0; i<IMAP; i++) i_m0C_TOP_IMAP[i][LANE] = (Ull)i_m0C[LANE] + i*sizeof(float)*DST_COL_LEN_TOTdIMAP;

  
#if 0
    static Ull max_SRC0_ROW_LEN=0;
    static Ull max_SRC1_COL_LEN_TOTAL=0;
    static Ull max_DST_COL_LEN_TOTAL=0;
    if (max_SRC0_ROW_LEN       < SRC0_ROW_LEN)       { max_SRC0_ROW_LEN       = SRC0_ROW_LEN      ; printf("max_SRC0_ROW_LEN=%16.16llx\n",       max_SRC0_ROW_LEN); }
    if (max_SRC1_COL_LEN_TOTAL < SRC1_COL_LEN_TOTAL) { max_SRC1_COL_LEN_TOTAL = SRC1_COL_LEN_TOTAL; printf("max_SRC1_COL_LEN_TOTAL=%16.16llx\n", max_SRC1_COL_LEN_TOTAL); }
    if (max_DST_COL_LEN_TOTAL  < DST_COL_LEN_TOTAL)  { max_DST_COL_LEN_TOTAL  = DST_COL_LEN_TOTAL;  printf("max_DST_COL_LEN_TOTAL=%16.16llx\n",  max_DST_COL_LEN_TOTAL);  }
    /* max_SRC0_ROW_LEN      =0000000000004400 */
    /* max_SRC0_ROW_LEN      =000000000000b6c0 */
    /* max_SRC0_ROW_LEN      =0000000000011000 */
    /* max_SRC1_COL_LEN_TOTAL=0000000000000880 */
    /* max_SRC1_COL_LEN_TOTAL=00000000000016d8 */
    /* max_DST_COL_LEN_TOTAL =0000000000000020 */
    /* max_DST_COL_LEN_TOTAL =0000000000000040 */
#endif
    // printf("LANE %d\n,SRC1_COL_TOP=%16.16llx\n", LANE,*(Ull*)SRC1_COL_TOP);
    int ctmp;
    // printf("start_one_chunk\n");
    // データ転送

    if (src0_preloaded) { /* in init_xmax() */
      /* override i_m0A_TOP */
      i_m0A_TOP = i_m0A[0] + (SRC0_ROW_TOP - SRC0_ROW_TOP_DIRECT);
      // printf("skip\n");
      Force0=1; /* everytime new address for LMM */
    }
    else if (*(Ull*)i_m0A_TOP == *(Ull*)SRC0_ROW_TOP) {
      Force0=0;
    }
    else {
      monitor_time_start(THREAD, IMAX_CPYIN_A_Q80);
      xmax_cpyin(3,i_m0A_TOP,  &ctmp,SRC0_ROW_TOP,1,1,SRC0_ROW_LEN,1,1);
      Force0=1; /* force sdat to LMM */
      monitor_time_end(THREAD, IMAX_CPYIN_A_Q80);
      // TOTAL_BUFFER_LOAD_SIZE += SRC0_ROW_LEN*sizeof(int);
      
      // Update max copy size for SRC0 in bytes
      Ull current_copy_size_bytes = SRC0_ROW_LEN * sizeof(int);
      if (max_SRC0_ROW_LEN_COPY_BYTES <= current_copy_size_bytes) {
        max_SRC0_ROW_LEN_COPY_BYTES = current_copy_size_bytes;
        // printf("max_SRC0_ROW_LEN_COPY_BYTES=%d KB\n", max_SRC0_ROW_LEN_COPY_BYTES/1024);
      }
     
     
    }
    // printf("LANE %d:SRC0_ROW_LEN=%d KB\n", LANE,SRC0_ROW_LEN*sizeof(float)/1024);
    // printf("LANE %d\n", LANE);
    if (*(Ull*)i_m0B[LANE] == *(Ull*)SRC1_COL_TOP) {
      Force1=0;
    }
    else {
      Force1=1; /* force wdat to LMM */
      monitor_time_start(THREAD, IMAX_CPYIN_B);
      // (C) Copy from SRC1_COL_TOP to i_m0B[LANE]
      xmax_cpyin(3,i_m0B[LANE],&ctmp,SRC1_COL_TOP,1,1,SRC1_COL_LEN_TOTAL,1,1);
      monitor_time_end(THREAD, IMAX_CPYIN_B);
      // TOTAL_BUFFER_LOAD_SIZE += SRC1_COL_LEN_TOTAL*sizeof(int);
      
      // Update max copy size for SRC1 in bytes
      Ull current_copy_size_bytes = SRC1_COL_LEN_TOTAL * sizeof(int);
      if (max_SRC1_COL_LEN_COPY_BYTES <= current_copy_size_bytes) {
        max_SRC1_COL_LEN_COPY_BYTES = current_copy_size_bytes;
        // printf("max_SRC1_COL_LEN_COPY_BYTES=%d KB\n", max_SRC1_COL_LEN_COPY_BYTES/1024);
      }
      
      // printf("----------------------------------LANE %d:SRC1_COL_LEN=%d KB\n", LANE,SRC1_COL_LEN_TOTAL*sizeof(float)/1024);
    }
    monitor_time_start(THREAD, IMAX_BZERO);
    xmax_bzero(i_m0C[LANE], DST_COL_LEN_TOTAL);
    // コピーサイズを表示
    // printf("DST_COL_LEN_TOTAL=%d\nbyte=%d\n", DST_COL_LEN_TOTAL, DST_COL_LEN_TOTAL*sizeof(float));
    Force2 = 1; /* force dst  to LMM */
    // printf("DST_COL_LEN_TOTAL=%d\n", DST_COL_LEN_TOTAL);
    monitor_time_end(THREAD, IMAX_BZERO);
    
// ------------------------------------------------------------------------------------
//  reset_nanosec(LANE);

///////////////////////////////////////////////////////////////////////IMAX????:????????///////////////////

    /*          <----------------------------------src0->data : 34B           x 128 x (16x256=4096) -------------------------------------->   */
    /*                                        cpyin(i_m0A, sizeof(block_q8_0) x nb  x     nr0(4096)                                           */
    /*          <----------------------------------SRC0_ROW_LEN-------------------------------------------------------------------------->    */
    /*          <---------------------nb01(4352,11696)-------------------->iofs=rofs+iofs(hi)   [            blck00dIMAP            ]         */
    /*          [[      34B      ] [      34B      ]     [      34B      ]]:nb(128,344)       x [[blck_0(16) x IIR0_LOOPS(1,4)]/IMAP]         */
    /* SRC0_ROW [[f16|i8|i8|..|i8] [f16|i8|i8|..|i8] ... [f16|i8|i8|..|i8]]                                                                   */
    /* imax_compute_forward_mul_mat_one_chunk_q8_0()?��???????i_m0A?????��???????Force-load???(vsim??,LMM?????????Force????)    */
    
    /*          <----------------------------------src1->data : 34B           x 128 x (2) ----------------------------------------------->    */
    /*                                        cpyin(i_m0B, sizeof(block_q8_0) x nb  x (2)                                                     */
    /*           <--------------------SRC1_COL_LEN_TOTAL-------------------------------------------------------------->                       */
    /*           <--------------------SRC1_COL_LEN_TOTAL------------------->                                                                  */
    /*            <----BKQ8------->cofs(hi)                                                                                                   */
    /*           [[      34B      ] [      34B      ]     [      34B      ]]:nb(128,344)              x IR1_LOOPS(2,1)                        */
    /* SRC1_COL  [[f16|i8|i8|..|i8] [f16|i8|i8|..|i8] ... [f16|i8|i8|..|i8]]                                                                  */
    /* imax_compute_forward_mul_mat_one_chunk_q8_0()?��??????????��?1?????Force-load???                                                 */
                       
    /*           <---------------------nb1/sizeof(int)-------------------------------------------------------------->:nb*32                   */
    /*           [                          4B                             ] x  [blck_0(16) x IIR0_LOOPS(1,4)] x IR1_LOOPS(2,1) x nb1/sizeof(int)*/
    /* DST_COL   [                         f32                             ]                         ]                                        */
    /* imax_compute_forward_mul_mat_one_chunk_q8_0()?��???????i_m0C???????��?1?????Force-load???                                      */
    
    /*           <-------------------------------------DST_COL_LEN_TOTAL--------------------------------------------------------------------> */
    /*           <-------------------------------------DST_COL_LENdIMAP---------------------------------------------------------->        */
    /*           <-------------------------------------DST_COL_LENdIMAP-------------------------------------------->                          */
    /*                                                                         [            blck_00dIMAP           ]                          */
    /*           [                          4B                             ] x [[blck_0(16) x IIR0_LOOPS(1,4)]/IMAP] x IIR1_LOOPS(2,1) x IMAP */
    /* i_m0C     [                         f32                             ]                                                                  */
    /* imax_compute_forward_mul_mat_one_chunk_q8_0()?��???????i_m0C???????��???????Force-load???                                     */

  // printf("th=%d ir1_start=%lld ir1_end=%lld SRC1_TOP=%16.16llx SRC1_LEN_TOTAL=%d IR1_LOOPS=%d ir0_start=%lld ir0_end=%lld SRC0_TOP=%16.16llx SRC0_LEN=%d IIR0_LOOPS=%d DST_TOP=%16.16llx DST_LEN_TOTAL=%d(dist=%d)\n", THREAD, ir1_start, ir1_end, SRC1_COL_TOP, (int)SRC1_COL_LEN_TOTAL, (int)IR1_LOOPS, ir0_start, ir0_end, SRC0_ROW_TOP, (int)SRC0_ROW_LEN, (int)IIR0_LOOPS, DST_COL_TOP, (int)DST_COL_LEN_TOTAL, (int)nb1);
    
    /* S1LEN_TOT=2176(34*128(nb)/4*2(ir1loop)),S0LEN=17408(34*128(nb)/4*16),DSTLEN_TOT=32(dist=16384) */
    
    
    for (int64_t iir1 = ir1_start; iir1 < ir1_end; iir1 += blck_1) {          /* weight top loop *//* ????1??loop */
      for (int64_t ir1 = iir1; ir1 < iir1 + blck_1 && ir1 < ir1_end; ir1 += num_rows_per_vec_dot) { /* weight sub loop *//* ????IR1_LOOPS??  (2,1) */
        // printf("ir1=%lld\n", ir1);
      //for (int64_t iir0 = ir0_start; iir0 < ir0_end; iir0 += blck_0) {      /* sdata  top loop *//* ????IIR0_LOOPS?? (1,4) */
	  const int64_t i13 = (ir1 / (ne12 * ne1));           /* ==0 */
	  const int64_t i12 = (ir1 - i13 * ne12 * ne1) / ne1; /* ==0 */
	  const int64_t i11 = (ir1 - i13 * ne12 * ne1 - i12 * ne1);
	  const int64_t i03 = i13 / r3;
	  const int64_t i02 = i12 / r2;
	  const int64_t i1 = i11;
	  const int64_t i2 = i12;
	  const int64_t i3 = i13;
	  const int64_t blck_00 = blck_0*IIR0_LOOPS;
	  const int64_t blck_00dIMAP = blck_00/IMAP;


	//const char * src0_row = (const char*)SRC0_ROW_TOP;
	  const char * src0_row = (const char*)i_m0A_TOP;
	  Ull          src0_row_p8[IMAP];      for (i=0; i<IMAP; i++)                     src0_row_p8[i]      = (Ull)src0_row+8+i*sizeof(int)*SRC0_ROW_LENdIMAP;
	  Ull          src0_row_p0[IMAP];      for (i=0; i<IMAP; i++)                     src0_row_p0[i]      = (Ull)src0_row+0+i*sizeof(int)*SRC0_ROW_LENdIMAP;
	  Ull          src0_row_base[IMAP][5]; for (i=0; i<IMAP; i++) for (j=0; j<5; j++) src0_row_base[i][j] = (Ull)src0_row+2+i*sizeof(int)*SRC0_ROW_LENdIMAP+j*8;

	//const char * src1_col = (const char*)wdata        + (src1_cont || src1->type != vec_dot_type ? (i11 + i12 * ne11 + i13 * ne12 * ne11) * row_size /* 4352(0x1100),11696(0x2db0) */
	//                                                                                             : (i11 * nb11 + i12 * nb12 + i13 * nb13));
	//const char * src1_col = (const char*)SRC1_COL_TOP + (ir1-ir1_start)*nb11);
	  const char * src1_col = (const char*)i_m0B[LANE]  + (ir1-ir1_start)*sizeof(int)*SRC1_COL_LEN;
	  Ull          src1_col_p0 = (Ull)src1_col;
	  Ull          src1_col_p8 = (Ull)src1_col+8;
	  Ull          src1_col_base[5]; for (j=0; j<5; j++) src1_col_base[j] = (Ull)src1_col+2+j*8;

	//float      * dst_col = (float*)((char*)dst->data + (i1 * nb1 + i2 * nb2 + i3 * nb3)) + iir0;
	//float      * dst_col = (float*)DST_COL_TOP + (iir0-ir0_start) + (ir1-ir1_start)*nb1/sizeof(int); /* stride nb1/sizeof(int)=4096=nb*32 */
	  float      * dst_col = (float*)i_m0C[LANE] + (ir0_start-ir0_start) + (ir1-ir1_start)*DST_COL_LENdIMAP;/* contiguous */
	  float      * dst_col_base[IMAP];     for (i=0; i<IMAP; i++)                     dst_col_base[i] = (Ull)dst_col+i*sizeof(float)*DST_COL_LEN_TOTdIMAP;/* contiguous */

	  /* SRC1_COL_LEN = 0x440/0xb6c DST_COL_LEN = 0x10 ??????��?�y? */
	  /* SRC0??ir1-loop???????.SRC1??2???????��????????��?LOOP0?????????????,???????��?DMA???2????????????? */
        // printf(" src0_row/len=%16.16llx/%d src1_col/len=%16.16llx/%d dst_col/len=%16.16llx/%d\n", src0_row,SRC0_ROW_LEN,src1_col,SRC1_COL_LEN,dst_col,DST_COL_LEN);

#define q8_0(r, i) \
	mop(OP_LDR,   0, &BR[r][0][1],   src0_row_base[i][1], (Ull)iofs,  MSK_W1, i_m0A_TOP,   SRC0_ROW_LEN,       0, Force0, (Ull)NULL, SRC0_ROW_LEN); /* dismissible */\
	mop(OP_LDR,   3, &BR[r][0][0],   src0_row_base[i][0], (Ull)iofs,  MSK_W1, i_m0A_TOP,   SRC0_ROW_LEN,       0, Force0, (Ull)NULL, SRC0_ROW_LEN); /* unaligned */\
	mop(OP_LDR,   0, &BR[r][1][1],   src0_row_base[i][2], (Ull)iofs,  MSK_W1, i_m0A_TOP,   SRC0_ROW_LEN,       0, Force0, (Ull)NULL, SRC0_ROW_LEN); /* dismissible */\
	mop(OP_LDR,   3, &BR[r][1][0],   src0_row_base[i][1], (Ull)iofs,  MSK_W1, i_m0A_TOP,   SRC0_ROW_LEN,       0, Force0, (Ull)NULL, SRC0_ROW_LEN); /* unaligned */\
	mop(OP_LDR,   0, &BR[r][2][1],   src0_row_base[i][3], (Ull)iofs,  MSK_W1, i_m0A_TOP,   SRC0_ROW_LEN,       0, Force0, (Ull)NULL, SRC0_ROW_LEN); /* dismissible */\
	mop(OP_LDR,   3, &BR[r][2][0],   src0_row_base[i][2], (Ull)iofs,  MSK_W1, i_m0A_TOP,   SRC0_ROW_LEN,       0, Force0, (Ull)NULL, SRC0_ROW_LEN); /* unaligned */\
	mop(OP_LDR,   0, &BR[r][3][1],   src0_row_base[i][4], (Ull)iofs,  MSK_W1, i_m0A_TOP,   SRC0_ROW_LEN,       0, Force0, (Ull)NULL, SRC0_ROW_LEN); /* dismissible */\
	mop(OP_LDR,   3, &BR[r][3][0],   src0_row_base[i][3], (Ull)iofs,  MSK_W1, i_m0A_TOP,   SRC0_ROW_LEN,       0, Force0, (Ull)NULL, SRC0_ROW_LEN); /* unaligned */\
\
	mop(OP_LDR,   0, &BR[r+1][0][1], src1_col_base[1],    (Ull)cofs,  MSK_W1, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)NULL, SRC1_COL_LEN_TOTAL); /* dismissible */\
	mop(OP_LDR,   3, &BR[r+1][0][0], src1_col_base[0],    (Ull)cofs,  MSK_W1, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)NULL, SRC1_COL_LEN_TOTAL); /* unaligned */\
	mop(OP_LDR,   0, &BR[r+1][1][1], src1_col_base[2],    (Ull)cofs,  MSK_W1, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)NULL, SRC1_COL_LEN_TOTAL); /* dismissible */\
	mop(OP_LDR,   3, &BR[r+1][1][0], src1_col_base[1],    (Ull)cofs,  MSK_W1, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)NULL, SRC1_COL_LEN_TOTAL); /* unaligned */\
	mop(OP_LDR,   0, &BR[r+1][2][1], src1_col_base[3],    (Ull)cofs,  MSK_W1, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)NULL, SRC1_COL_LEN_TOTAL); /* dismissible */\
	mop(OP_LDR,   3, &BR[r+1][2][0], src1_col_base[2],    (Ull)cofs,  MSK_W1, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)NULL, SRC1_COL_LEN_TOTAL); /* unaligned */\
	mop(OP_LDR,   0, &BR[r+1][3][1], src1_col_base[4],    (Ull)cofs,  MSK_W1, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)NULL, SRC1_COL_LEN_TOTAL); /* dismissible */\
	mop(OP_LDR,   3, &BR[r+1][3][0], src1_col_base[3],    (Ull)cofs,  MSK_W1, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)NULL, SRC1_COL_LEN_TOTAL); /* unaligned */\
\
        exe(OP_SML8,     &r20,  BR[r][0][0],   EXP_B5410, BR[r+1][0][0],  EXP_B5410, 0LL, EXP_H3210, OP_NOP,  0LL, OP_NOP, 0LL); /* sdata,wdata */\
        exe(OP_SML8,     &r21,  BR[r][1][0],   EXP_B5410, BR[r+1][1][0],  EXP_B5410, 0LL, EXP_H3210, OP_NOP,  0LL, OP_NOP, 0LL); /* sdata,wdata */\
        exe(OP_SML8,     &r22,  BR[r][2][0],   EXP_B5410, BR[r+1][2][0],  EXP_B5410, 0LL, EXP_H3210, OP_NOP,  0LL, OP_NOP, 0LL); /* sdata,wdata */\
        exe(OP_SML8,     &r23,  BR[r][3][0],   EXP_B5410, BR[r+1][3][0],  EXP_B5410, 0LL, EXP_H3210, OP_NOP,  0LL, OP_NOP, 0LL); /* sdata,wdata */\
\
        exe(OP_SML8,     &r24,  BR[r][0][0],   EXP_B7632, BR[r+1][0][0],  EXP_B7632, 0LL, EXP_H3210, OP_AD32, r20, OP_NOP, 0LL); /* sdata,wdata */\
        exe(OP_SML8,     &r25,  BR[r][1][0],   EXP_B7632, BR[r+1][1][0],  EXP_B7632, 0LL, EXP_H3210, OP_AD32, r21, OP_NOP, 0LL); /* sdata,wdata */\
        exe(OP_SML8,     &r26,  BR[r][2][0],   EXP_B7632, BR[r+1][2][0],  EXP_B7632, 0LL, EXP_H3210, OP_AD32, r22, OP_NOP, 0LL); /* sdata,wdata */\
        exe(OP_SML8,     &r27,  BR[r][3][0],   EXP_B7632, BR[r+1][3][0],  EXP_B7632, 0LL, EXP_H3210, OP_AD32, r23, OP_NOP, 0LL); /* sdata,wdata */\
\
        exe(OP_NOP,      &r28,  r24,           EXP_H3210, 0LL,            EXP_H3210, 0LL, EXP_H3210, OP_AD32, r25, OP_NOP, 0LL);\
        exe(OP_NOP,      &r29,  r26,           EXP_H3210, 0LL,            EXP_H3210, 0LL, EXP_H3210, OP_AD32, r27, OP_NOP, 0LL);\
\
	mop(OP_LDR,   0, &BR[r+5][0][1],  (Ull)src0_row_p8[i], (Ull)iofs, MSK_W1, i_m0A_TOP,   SRC0_ROW_LEN, 0, Force0, (Ull)NULL, SRC0_ROW_LEN); /* dismissible */\
	mop(OP_LDR,   3, &BR[r+5][0][0],  (Ull)src0_row_p0[i], (Ull)iofs, MSK_W1, i_m0A_TOP,   SRC0_ROW_LEN, 0, Force0, (Ull)NULL, SRC0_ROW_LEN); /* unaligned */\
        exe(OP_NOP,      &r30,  r28,           EXP_H3210, 0LL,            EXP_H3210, 0LL, EXP_H3210, OP_AD32, r29, OP_NOP, 0LL);\
\
	mop(OP_LDR,   0, &BR[r+6][0][1],  (Ull)src1_col_p8,    (Ull)cofs, MSK_W1, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)NULL, SRC1_COL_LEN_TOTAL); /* dismissible */\
	mop(OP_LDR,   3, &BR[r+6][0][0],  (Ull)src1_col_p0,    (Ull)cofs, MSK_W1, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)NULL, SRC1_COL_LEN_TOTAL); /* unaligned */\
        exe(OP_NOP,      &r31,  r30,           EXP_H3232, 0LL,            EXP_H3210, 0LL, EXP_H3210, OP_AD32, r30, OP_SRAB, 5LL);\
\
        exe(OP_NOP,      &r12,  r31,           EXP_H3210, 0LL,            EXP_H3210, 0LL, EXP_H3210, OP_AND, 0x000000000000ffffLL, OP_SLL, 2LL); /* sdata int16->fp32 */\
        exe(OP_NOP,      &r13,  BR[r+5][0][0], EXP_H3210, 0LL,            EXP_H3210, 0LL, EXP_H3210, OP_AND, 0x000000000000ffffLL, OP_SLL, 2LL); /* sdata fp16->fp32 */\
        exe(OP_NOP,      &r14,  BR[r+6][0][0], EXP_H3210, 0LL,            EXP_H3210, 0LL, EXP_H3210, OP_AND, 0x000000000000ffffLL, OP_SLL, 2LL); /* wdata fp16->fp32 */\
\
	mop(OP_LDWR,  3, &BR[r+8][0][1],  (Ull)i_i16[LANE],    (Ull)r12,  MSK_W0, (Ull)i_i16[LANE], 65536, 0, 0, (Ull)NULL, 65536);\
	mop(OP_LDWR,  3, &BR[r+8][2][1],  (Ull)i_f16[LANE],    (Ull)r13,  MSK_W0, (Ull)i_f16[LANE], 65536, 0, 0, (Ull)NULL, 65536);\
	mop(OP_LDWR,  3, &BR[r+8][3][1],  (Ull)i_f16[LANE],    (Ull)r14,  MSK_W0, (Ull)i_f16[LANE], 65536, 0, 0, (Ull)NULL, 65536);\
\
	exe(OP_FML,      &r03, BR[r+8][0][1],  EXP_H3210, 0x42000000LL,   EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL); /* *32.0 */\
	exe(OP_FML,      &r02, BR[r+8][2][1],  EXP_H3210, BR[r+8][3][1],  EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL); /* s * w */\
\
        exe(OP_NOP,      &AR[r+10][0], 0LL,    EXP_H3210, 0LL,            EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);                  /* stage#12 (dummy to set target location) */\
        mop(OP_LDWR,  1, &r00,      dst_col_base[i],      oofs,           MSK_W0, i_m0C_TOP_IMAP[i][LANE], DST_COL_LEN_TOTdIMAP,  0, Force2, (Ull)NULL, DST_COL_LEN_TOTdIMAP); /* stage#12 */\
        exe(OP_FMA,      &r00, INIT0?r00:r00, EXP_H3210,  r03,            EXP_H3210, r02, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);/**(float*)&r01=32.0**(float*)&r15**(float*)&r16**(float*)&r17;*/\
        mop(OP_STWR,  1, &r00,      oofs,                 dst_col_base[i],MSK_D0, i_m0C_TOP_IMAP[i][LANE], DST_COL_LEN_TOTdIMAP,  0, Force2, (Ull)NULL, DST_COL_LEN_TOTdIMAP)

//EMAX5A begin mul_mat_one_chunk_q80 mapdist=0
     /*3*/for (CHIP=0; CHIP<NCHIP; CHIP++) { /* will be parallelized by multi-chip (M/#chip) */
       /*2*/for (INIT1=1,LOOP1=blck_00dIMAP,rofs=MNB01_M4; LOOP1--; INIT1=0) { /* stage#0 *//* mapped to FOR() on BR[63][1][0] *//* sdata  sub loop *//* blck_0=16 */
         /*1*/for (INIT0=1,LOOP0=nb,cofs=MBKQ8_0000; LOOP0--; INIT0=0) { /* stage#0 *//* mapped to FOR() on BR[63][0][0] *//* 34B   x nb loop *//* nb=128,344 LMM=17408,46784word */
		exe(OP_ADD,      &rofs,  rofs,            EXP_H3210, INIT0?NB01_4:0, EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL,                  OP_NOP, 0LL); /* |x:NB01|d:   4| stage#0 */
                exe(OP_ADD,      &cofs,  INIT0?cofs:cofs, EXP_H3210, BKQ8_0000,      EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL,                  OP_NOP, 0LL); /* |x:BKQ8|d:   0| stage#0 */
	        exe(OP_ADD,      &iofs,  rofs,            EXP_H3210, cofs,           EXP_H3210, 0LL, EXP_H3210, OP_AND, 0xffffffff00000000LL, OP_NOP, 0LL); /*                 stage#1 */
	        exe(OP_ADD,      &oofs,  rofs,            EXP_H3210, 0LL,            EXP_H3210, 0LL, EXP_H3210, OP_AND, 0x00000000ffffffffLL, OP_NOP, 0LL); /*                 stage#1 */
// 意図的に1秒スリープ
                        
// time_t t3 = get_nanosec(LANE,0);
// printf("q8_0(imax) time: %.2f ms\n", t4 - t3);
#if 0
		int sumi = 0;
		for (int j = 0; j < QK8_0; j++) { /* 8bit*8bit x32 */
		  sumi += ((block_q8_0*)((char*)src0_row+(iofs>>32)))->qs[j] * ((block_q8_0*)((char*)src1_col+(cofs>>32)))->qs[j];
		}
		sumi >>= 5;
	        *(float*)&r01 = 32.0*(GGML_INT16_TO_FP32(sumi))*(GGML_FP16_TO_FP32(((block_q8_0*)((char*)src0_row+(iofs>>32)))->d)*GGML_FP16_TO_FP32(((block_q8_0*)((char*)src1_col+(cofs>>32)))->d));
#endif

#if (IMAP>0)
		/* IMAP#0 */
		q8_0( 2, 0);
#endif
#if (IMAP>1)
		/* IMAP#1 */
		q8_0(13, 1);
#endif
#if (IMAP>2)
		/* IMAP#2 */
		q8_0(24, 2);
#endif
#if (IMAP>3)
		/* IMAP#3 */
		q8_0(35, 3);
#endif
              }
            }
          }
         
//EMAX5A end
          if (Force0) Force0 = 0; /* reset sdat to LMM */
          if (Force1) Force1 = 0; /* reset wdat to LMM */
          if (Force2) Force2 = 0; /* reset dst  to LMM */
      //}
      }
    }
//EMAX5A drain_dirty_lmm
///////////////////////////////////////////////////////////////////////IMAX????:???????///////////////////

//  get_nanosec(LANE,0);
//  show_nanosec(LANE);
  // tensorの内容を表示
  // printf("xmax_cpyout\n");

// monitor_time_end(THREAD,IMAX_TERM_5);
// monitor_time_end(THREAD,IMAX_TERM_6);
// monitor_time_end(THREAD,IMAX_TERM_7);

  // これは演算結果をステージングバッファからGGMLに転送， LMMから転送しているわけではない！
    monitor_time_start(THREAD, IMAX_CPYOUT);

    xmax_cpyout(4, DST_COL_TOP, 1, nb1/sizeof(int), i_m0C[LANE], IR1_LOOPS, DST_COL_LENdIMAP, IMAP); /* stride */
    monitor_time_end(THREAD, IMAX_CPYOUT);
    //dstのアドレスを表示
    // printf("DST_COL_TOP=%16.16llx\n", DST_COL_TOP);
    // コピー内容をチェック DST_COL_TOPとi_m0C[LANE]の内容をチェック
    TOTAL_BUFFER_DRAIN_SIZE += DST_COL_LEN_TOTAL*sizeof(int);
    // printf("DST_COL_LEN_TOTAL=%d\nbyte=%d\n", DST_COL_LEN_TOTAL, DST_COL_LEN_TOTAL*sizeof(float));
    
  }
}

void get_show_nanosec(int LANE)
{
  //改行を入れる
  printf("\n");
  show_nanosec(LANE);
}

void get_show_dma_size(void)
{
  // printf("TOTAL_DMA_LOAD_SIZE(BUFF)=%lld KB,TOTAL_DMA_DRAIN_SIZE(BUFF)=%lld bytes\n", TOTAL_BUFFER_LOAD_SIZE/1024, TOTAL_BUFFER_DRAIN_SIZE);
}