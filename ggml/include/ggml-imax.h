#pragma once

#ifdef  __cplusplus
extern "C" {
#endif

#include <pthread.h>
#include <signal.h>

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

#define MAX_NTHREAD 16
#define IMAX_DMABUF_BLKS 16

extern int NTHREAD;
extern volatile int IMAX_READY;
extern int IMAX_DMABUF_LAST;
extern int is_last_token; // 最後のtokenフラグ（ggml-cpu.cで定義）

// --- 構造体定義を先に書く ---
struct imax_dmabuf_map {
    void * src_blk_top;
    Ull    blk_size;
    Ull    imax_blk_ofs;
    int    dmabufmap;
};

struct th_inference_args {
    int      thid;
    int      dmy0[15];
    int      stat;
    int      dmy1[15];
    sigset_t sigset;
    int      dmy2[15];
    int      deq;
    int      dmy3[15];
    int      enq;
    int      dmy4[15];
    void *   dst;
    Ull      num_rows_per_vec_dot;
    Ull      ir0_start;
    Ull      ir0_end;
    Ull      ir1_start;
    Ull      ir1_end;
    const void * src0;
    const void * src1;
    int      type;
    int      src1_cont;
    void *   vec_dot;
    int      vec_dot_type;
    const void * wdata;
    int      row_size;
    Ull      r2;
    Ull      r3;
    Ull      blck_0;
    Ull      blck_1;
    size_t   src1_col_stride;
};
// --- extern宣言はその後 ---
extern volatile struct imax_dmabuf_map imax_dmabuf_map[IMAX_DMABUF_BLKS];
extern volatile struct th_inference_args th_inference_args[MAX_NTHREAD];
extern volatile int th_inference_retv[MAX_NTHREAD];
extern pthread_t th_inference_t[MAX_NTHREAD];

#define imax_dmabuf_map_register(string, top, size, map)       \
  if (IMAX_DMABUF_LAST < IMAX_DMABUF_BLKS) {                   \
    imax_dmabuf_map[IMAX_DMABUF_LAST].src_blk_top  = (top);    \
    imax_dmabuf_map[IMAX_DMABUF_LAST].blk_size     = (size);   \
    imax_dmabuf_map[IMAX_DMABUF_LAST].imax_blk_ofs = IMAX_DMABUF_LAST==0 ? 0 : imax_dmabuf_map[IMAX_DMABUF_LAST-1].imax_blk_ofs + (imax_dmabuf_map[IMAX_DMABUF_LAST-1].dmabufmap?imax_dmabuf_map[IMAX_DMABUF_LAST-1].blk_size:0);\
    imax_dmabuf_map[IMAX_DMABUF_LAST].dmabufmap    = map;      \
    printf("== %d == %-36.36s: %16.16llx size=%16.16llx %d dmabuf=%16.16llx", IMAX_DMABUF_LAST, string, (top), (size), (map), imax_dmabuf_map[IMAX_DMABUF_LAST].imax_blk_ofs);\
    if (imax_dmabuf_map[IMAX_DMABUF_LAST].imax_blk_ofs + (size) >= 0x100000000LL) { \
      printf(" > 4GB space\n");                                \
    }                                                          \
    else {                                                     \
      printf("\n");                                            \
      IMAX_DMABUF_LAST++;                                      \
    }                                                          \
  } else {} /* free IMAX_DMA space & cpyin() is required */

extern volatile int th_inference_retv[MAX_NTHREAD];
extern pthread_t    th_inference_t[MAX_NTHREAD];

#ifdef  __cplusplus
}
#endif


// extern volatile struct imax_dmabuf_map {
//     void * src_blk_top;  /* in ARM space */
//     Ull    blk_size;     /* bytes */
//     Ull    imax_blk_ofs; /* in DMABUF */
//     int    dmabufmap;    /* 0:no-direct-DMABUF, 1:constant-table 2:src0-direct-DMABUF, 3:src1-direct-DMABUF */
// } imax_dmabuf_map[IMAX_DMABUF_BLKS];