/*                          Copyright (C) 2013- by NAIST */
/*                           Primary writer: Y.Nakashima */
/*                                  nakashim@is.naist.jp */
/* monitor.c 2019/10/18 */

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
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <sys/times.h>
#include <sys/resource.h>
#include "ggml-imax.h"
#include "monitor.h"


extern int    NTHREAD; 
double        tmssave, tms;
long          ticksave, ticks;
struct rusage rusage;

double last_times[MAX_NTHREAD][MONITOREND];
double sep_times[MAX_NTHREAD][MONITOREND];

unsigned long last_ticks[MAX_NTHREAD][MONITOREND];
unsigned long sep_ticks[MAX_NTHREAD][MONITOREND];

// New array to track execution counts for each enum type
unsigned long enum_counts[MONITOREND];

// Variables to track xmax_cpyin data transfer for Q3K and Q80
unsigned long long q3k_total_bytes = 0;
unsigned long q3k_transfer_count = 0;
unsigned long long q80_total_bytes = 0;
unsigned long q80_transfer_count = 0;

// Function to reset data transfer statistics
void reset_cpyin_stats(void) {
  q3k_total_bytes = 0;
  q3k_transfer_count = 0;
  q80_total_bytes = 0;
  q80_transfer_count = 0;
}

// Function to count Q3K data transfers
void count_cpyin_q3k(size_t size_bytes) {
  q3k_total_bytes += size_bytes;
  q3k_transfer_count++;
}

// Function to count Q80 data transfers
void count_cpyin_q80(size_t size_bytes) {
  q80_total_bytes += size_bytes;
  q80_transfer_count++;
}

// Function to display data transfer statistics
void show_cpyin_stats(void) {
  printf("\n===== XMAX_CPYIN DATA TRANSFER STATISTICS =====\n");

  printf("Q3K transfers: %lu calls, %llu bytes total (%.2f MB)\n", 
         q3k_transfer_count, 
         q3k_total_bytes, 
         (double)q3k_total_bytes / (1024.0 * 1024.0));
  
  if (q3k_transfer_count > 0) {
    printf("  Average transfer size: %.2f KB per call\n", 
           (double)q3k_total_bytes / (q3k_transfer_count * 1024.0));
  }

  printf("Q80 transfers: %lu calls, %llu bytes total (%.2f MB)\n", 
         q80_transfer_count, 
         q80_total_bytes, 
         (double)q80_total_bytes / (1024.0 * 1024.0));
  
  if (q80_transfer_count > 0) {
    printf("  Average transfer size: %.2f KB per call\n", 
           (double)q80_total_bytes / (q80_transfer_count * 1024.0));
  }

  printf("===== END OF TRANSFER STATISTICS =====\n\n");
}

// Function to increment count for a specific enum type
void monitor_increment_count(int id) {
  enum_counts[id]++;
}

// Reset all counters
void reset_enum_counts() {
  memset(enum_counts, 0, sizeof(enum_counts));
}

// Initialize timing variables and reset counters
void reset_time() {
  struct timeval tv;
  struct tms    utms;
  int i, j;

  // Reset execution counters
  reset_enum_counts();
  
  // Reset data transfer statistics
  reset_cpyin_stats();
  
  // Reset timing arrays
  for (i = 0; i < MAX_NTHREAD; i++) {
    for (j = 0; j < MONITOREND; j++) {
      last_times[i][j] = 0.0;
      sep_times[i][j] = 0.0;
      last_ticks[i][j] = 0;
      sep_ticks[i][j] = 0;
    }
  }

  gettimeofday(&tv, NULL);
  tmssave = tv.tv_sec + tv.tv_usec/1000000.0;

  times(&utms);
  ticksave = utms.tms_utime;
}

void monitor_time_start(int th, int id) {
  struct timeval tv;
  struct tms    utms;

  gettimeofday(&tv, NULL);
  last_times[th][id] = tv.tv_sec + tv.tv_usec/1000000.0;

  times(&utms);
  last_ticks[th][id] = utms.tms_utime;
  
  // Increment execution count for this enum type
  monitor_increment_count(id);
}

void monitor_time_end(int th, int id) {
  struct timeval tv;
  struct tms    utms;
  double now;
  unsigned long now_ticks;
  
  gettimeofday(&tv, NULL);
  now = tv.tv_sec + tv.tv_usec/1000000.0;
  sep_times[th][id] += now - last_times[th][id];

  times(&utms);
  now_ticks = utms.tms_utime;
  sep_ticks[th][id] += now_ticks - last_ticks[th][id];
}

void show_time() {
  struct timeval tv;
  struct tms    utms;

  gettimeofday(&tv, NULL);
  tms = tv.tv_sec+tv.tv_usec/1000000.0;
  printf("====TOTAL-EXEC-TIME(w/o IO) %g sec===\n", (double)(tms - tmssave));

  times(&utms);
  ticks = utms.tms_utime;
  printf("====TOTAL-CPUS-TIME(w/o IO) %g sec===\n", (double)(ticks-ticksave)/sysconf(_SC_CLK_TCK));

  printf("====PARENT(w/ IO)===\n");
  getrusage(RUSAGE_SELF, &rusage);
  printf("\033[31;1m ru_utime   = %d.%06dsec ", rusage.ru_utime.tv_sec, (int)rusage.ru_utime.tv_usec);
  printf(" ru_stime   = %d.%06dsec\033[0m\n", rusage.ru_stime.tv_sec, (int)rusage.ru_stime.tv_usec);
  printf(" ru_maxrss  = %6dKB  ", (int)rusage.ru_maxrss);        /* max resident set size */
  printf(" ru_ixrss   = %6dKB  ", (int)(rusage.ru_ixrss/ticks)); /* integral shared text memory size */
  printf(" ru_idrss   = %6dKB  ", (int)(rusage.ru_idrss/ticks)); /* integral unshared data size */
  printf(" ru_isrss   = %6dKB\n", (int)(rusage.ru_isrss/ticks)); /* integral unshared stack size */
  printf(" ru_minflt  = %8d  ", (int)rusage.ru_minflt);          /* page reclaims */
  printf(" ru_majflt  = %8d  ", (int)rusage.ru_majflt);          /* page faults */
  printf(" ru_nswap   = %8d  ", (int)rusage.ru_nswap);           /* swaps */
  printf(" ru_inblock = %8d\n", (int)rusage.ru_inblock);         /* block input operations */
  printf(" ru_oublock = %8d  ", (int)rusage.ru_oublock);         /* block output operations */
  printf(" ru_msgsnd  = %8d  ", (int)rusage.ru_msgsnd);          /* messages sent */
  printf(" ru_msgrcv  = %8d  ", (int)rusage.ru_msgrcv);          /* messages received */
  printf(" ru_nsignals= %8d\n", (int)rusage.ru_nsignals);        /* signals received */
  printf(" ru_nvcsww  = %8d  ", (int)rusage.ru_nvcsw);           /* voluntary context switches */
  printf(" ru_nivcsw  = %8d\n", (int)rusage.ru_nivcsw);          /* involuntary context switches */

  printf("====CHILD(w/ IO)===\n");
  getrusage(RUSAGE_CHILDREN, &rusage);
  printf("\033[31;1m ru_utime   = %d.%06dsec ", rusage.ru_utime.tv_sec, (int)rusage.ru_utime.tv_usec);
  printf(" ru_stime   = %d.%06dsec\033[0m\n", rusage.ru_stime.tv_sec, (int)rusage.ru_stime.tv_usec);
  printf(" ru_maxrss  = %6dKB  ", (int)rusage.ru_maxrss);        /* max resident set size */
  printf(" ru_ixrss   = %6dKB  ", (int)(rusage.ru_ixrss/ticks)); /* integral shared text memory size */
  printf(" ru_idrss   = %6dKB  ", (int)(rusage.ru_idrss/ticks)); /* integral unshared data size */
  printf(" ru_isrss   = %6dKB\n", (int)(rusage.ru_isrss/ticks)); /* integral unshared stack size */
  printf(" ru_minflt  = %8d  ", (int)rusage.ru_minflt);          /* page reclaims */
  printf(" ru_majflt  = %8d  ", (int)rusage.ru_majflt);          /* page faults */
  printf(" ru_nswap   = %8d  ", (int)rusage.ru_nswap);           /* swaps */
  printf(" ru_inblock = %8d\n", (int)rusage.ru_inblock);         /* block input operations */
  printf(" ru_oublock = %8d  ", (int)rusage.ru_oublock);         /* block output operations */
  printf(" ru_msgsnd  = %8d  ", (int)rusage.ru_msgsnd);          /* messages sent */
  printf(" ru_msgrcv  = %8d  ", (int)rusage.ru_msgrcv);          /* messages received */
  printf(" ru_nsignals= %8d\n", (int)rusage.ru_nsignals);        /* signals received */
  printf(" ru_nvcsww  = %8d  ", (int)rusage.ru_nvcsw);           /* voluntary context switches */
  printf(" ru_nivcsw  = %8d\n", (int)rusage.ru_nivcsw);          /* involuntary context switches */
}








const char *monitor_names[MONITOREND] = {
  "T_MAIN",
  " T_MAIN_WHILE",
  "  T_MAIN_GA_N_EQ1",
  "  T_MAIN_GA_N_NE1",
  "  T_MAIN_SESSION",
  "  T_MAIN_EMBD_SIZE",
  "  T_LLAMA_GRAPH_COMPUTE",
  "  T_GGML_BACKEND_SCHED_COMPUTE_SPLITS",
  "  T_GGML_GRAPH_COMPUTE",
  "  T_COMPUTE_FORWARD",
  "   T_COMPUTE_FORWARD_DUP",
  "   T_COMPUTE_FORWARD_ADD",
  "   T_COMPUTE_FORWARD_ADD_ID",
  "   T_COMPUTE_FORWARD_ADD1",
  "   T_COMPUTE_FORWARD_ACC",
  "   T_COMPUTE_FORWARD_SUB",
  "   T_COMPUTE_FORWARD_MUL",
  "   T_COMPUTE_FORWARD_DIV",
  "   T_COMPUTE_FORWARD_SQR",
  "   T_COMPUTE_FORWARD_SQRT",
  "   T_COMPUTE_FORWARD_LOG",
  "   T_COMPUTE_FORWARD_SUM",
  "   T_COMPUTE_FORWARD_SUM_ROWS",
  "   T_COMPUTE_FORWARD_MEAN",
  "   T_COMPUTE_FORWARD_ARGMAX",
  "   T_COMPUTE_FORWARD_REPEAT",
  "   T_COMPUTE_FORWARD_REPEAT_BACK",
  "   T_COMPUTE_FORWARD_CONCAT",
  "   T_COMPUTE_FORWARD_SILU_BACK",
  "   T_COMPUTE_FORWARD_NORM",
  "   T_COMPUTE_FORWARD_RMS_NORM",
  "   T_COMPUTE_FORWARD_RMS_NORM_BACK",
  "   T_COMPUTE_FORWARD_GROUP_NORM",
  "   T_COMPUTE_FORWARD_MUL_MAT",
  "   T_COMPUTE_FORWARD_MUL_MAT_NE_VEC_DOT",
  "   T_COMPUTE_FORWARD_MUL_MAT_NDIMS_EQ_2",
  "   T_COMPUTE_FORWARD_MUL_MAT_WHILE_CHUNK",
  "   T_COMPUTE_FORWARD_MUL_MAT_ONE_CHUNK",
  "     IMAX_COMPUTE_FORWARD_MUL_MAT_ONE_CHUNK_F32",  
  "     IMAX_COMPUTE_FORWARD_MUL_MAT_ONE_CHUNK_F32_ARM",
  "     IMAX_COMPUTE_FORWARD_MUL_MAT_ONE_CHUNK_F16",
  "     IMAX_COMPUTE_FORWARD_MUL_MAT_ONE_CHUNK_F16_ARM",
  "     IMAX_COMPUTE_FORWARD_MUL_MAT_ONE_CHUNK_Q2K",
  "     IMAX_COMPUTE_FORWARD_MUL_MAT_ONE_CHUNK_Q2K_ARM",
  "     IMAX_COMPUTE_FORWARD_MUL_MAT_ONE_CHUNK_Q3K",  
  "     IMAX_COMPUTE_FORWARD_MUL_MAT_ONE_CHUNK_Q3K_ARM",
  // "     IMAX_COMPUTE_FORWARD_MUL_MAT_ONE_CHUNK_Q4K",
  // "     IMAX_COMPUTE_FORWARD_MUL_MAT_ONE_CHUNK_Q4K_ARM",
  // "     IMAX_COMPUTE_FORWARD_MUL_MAT_ONE_CHUNK_Q5K",
  // "     IMAX_COMPUTE_FORWARD_MUL_MAT_ONE_CHUNK_Q5K_ARM",
  "     IMAX_COMPUTE_FORWARD_MUL_MAT_ONE_CHUNK_Q6K",
  "     IMAX_COMPUTE_FORWARD_MUL_MAT_ONE_CHUNK_Q6K_ARM",
  "     IMAX_COMPUTE_FORWARD_MUL_MAT_ONE_CHUNK_Q80",
  "     IMAX_COMPUTE_FORWARD_MUL_MAT_ONE_CHUNK_Q80_ARM",
  // "     IMAX_COMPUTE_FORWARD_MUL_MAT_ONE_CHUNK_Q8K",
  // "     IMAX_COMPUTE_FORWARD_MUL_MAT_ONE_CHUNK_Q8K_ARM",
  "     IMAX_COMPUTE_FORWARD_MUL_MAT_ONE_CHUNK_OTHER_ARM",
  "     VEC_DOT_OPERATION",
  "     ARM_MEMCPY",
  "     IMAX_CPYIN_PRELOAD",
  "     IMAX_CPYIN_A",
  "     IMAX_CPYIN_A_Q80",
  "     IMAX_CPYIN_B",
  "     IMAX_CPYIN_A_Q3K",
  "     IMAX_CPYIN_B_Q3K",
  "     IMAX_BZERO_Q3K",
  "     IMAX_CPYOUT_Q3K",
  "     IMAX_CPYIN_A_Q6K",
  "     IMAX_CPYIN_B_Q6K",
  "     IMAX_BZERO_Q6K",
  "     IMAX_CPYOUT_Q6K",
  "     IMAX_BZERO",
  "     IMAX_CPYOUT",
  "     IMAX_MEMCPY",
  "     IMAX_MEMCPY_A",
  "     IMAX_MEMCPY_B",
  "     IMAX_MEMCPY_C",
  "     IMAX_PIOCPY",
  "     IMAX_TERM_1",
  "     IMAX_TERM_2",
  "     IMAX_TERM_3",
  "     IMAX_TERM_4",
  "     IMAX_TERM_5",
  "     IMAX_TERM_6",
  "     IMAX_TERM_7",
  "     IMAX_TERM_8",
  "   T_COMPUTE_FORWARD_MUL_MAT_ID",
  "   T_COMPUTE_FORWARD_OUT_PROD",
  "   T_COMPUTE_FORWARD_SCALE",
  "   T_COMPUTE_FORWARD_SET",
  "   T_COMPUTE_FORWARD_CPY",
  "   T_COMPUTE_FORWARD_CONT",
  "   T_COMPUTE_FORWARD_RESHAPE",
  "   T_COMPUTE_FORWARD_VIEW",
  "   T_COMPUTE_FORWARD_PERMUTE",
  "   T_COMPUTE_FORWARD_TRANSPOSE",
  "   T_COMPUTE_FORWARD_GET_ROWS",
  "   T_COMPUTE_FORWARD_GET_ROWS_BACK",
  "   T_COMPUTE_FORWARD_DIAG",
  "   T_COMPUTE_FORWARD_DIAG_MASK_INF",
  "   T_COMPUTE_FORWARD_DIAG_MASK_ZERO",
  "   T_COMPUTE_FORWARD_SET_ROWS",
  "   T_COMPUTE_FORWARD_GLU",
  "   T_COMPUTE_FORWARD_SOFT_MAX",
  "   T_COMPUTE_FORWARD_SOFT_MAX_BACK",
  "   T_COMPUTE_FORWARD_ROPE",
  "   T_COMPUTE_FORWARD_ROPE_BACK",
  "   T_COMPUTE_FORWARD_ROLL",
  "   T_COMPUTE_FORWARD_CLAMP",
  "   T_COMPUTE_FORWARD_CONV_TRANSPOSE_1D",
  "   T_COMPUTE_FORWARD_IM2COL",
  "   T_COMPUTE_FORWARD_IM2COL_BACK",
  "   T_COMPUTE_FORWARD_IM2COL_3D",
  "   T_COMPUTE_FORWARD_CONV_2D",
  "   T_COMPUTE_FORWARD_CONV_3D",
  "   T_COMPUTE_FORWARD_CONV_2D_DW",
  "   T_COMPUTE_FORWARD_CONV_TRANSPOSE_2D",
  "   T_COMPUTE_FORWARD_POOL_1D",
  "   T_COMPUTE_FORWARD_POOL_2D",
  "   T_COMPUTE_FORWARD_POOL_2D_BACK",
  "   T_COMPUTE_FORWARD_UPSCALE",
  "   T_COMPUTE_FORWARD_PAD",
  "   T_COMPUTE_FORWARD_PAD_REFLECT_1D",
  "   T_COMPUTE_FORWARD_ARANGE",
  "   T_COMPUTE_FORWARD_TIMESTEP_EMBEDDING",
  "   T_COMPUTE_FORWARD_ARGSORT",
  "   T_COMPUTE_FORWARD_LEAKY_RELU",
  "   T_COMPUTE_FORWARD_FLASH_ATTN_EXT",
  "   T_COMPUTE_FORWARD_FLASH_ATTN_BACK",
  "   T_COMPUTE_FORWARD_SSM_CONV",
  "   T_COMPUTE_FORWARD_SSM_SCAN",
  "   T_COMPUTE_FORWARD_WIN_PART",
  "   T_COMPUTE_FORWARD_WIN_UNPART",
  "   T_COMPUTE_FORWARD_UNARY",
  "   T_COMPUTE_FORWARD_GET_REL_POS",
  "   T_COMPUTE_FORWARD_ADD_REL_POS",
  "   T_COMPUTE_FORWARD_MAP_UNARY",
  "   T_COMPUTE_FORWARD_MAP_BINARY",
  "   T_COMPUTE_FORWARD_MAP_CUSTOM1_F32",
  "   T_COMPUTE_FORWARD_MAP_CUSTOM2_F32",
  "   T_COMPUTE_FORWARD_MAP_CUSTOM3_F32",
  "   T_COMPUTE_FORWARD_MAP_CUSTOM1",
  "   T_COMPUTE_FORWARD_MAP_CUSTOM2",
  "   T_COMPUTE_FORWARD_MAP_CUSTOM3",
  "   T_COMPUTE_FORWARD_CROSS_ENTROPY_LOSS",
  "   T_COMPUTE_FORWARD_CROSS_ENTROPY_LOSS_BACK",
  "   T_COMPUTE_FORWARD_NONE",
  "   T_COMPUTE_FORWARD_COUNT",
  "   T_COMPUTE_FORWARD_SIN",
  "   T_COMPUTE_FORWARD_COS",
  "   T_COMPUTE_FORWARD_COUNT_EQUAL",
  "   T_COMPUTE_FORWARD_L2_NORM",
  "   T_COMPUTE_FORWARD_RWKV_WKV6",
  "   T_COMPUTE_FORWARD_GATED_LINEAR_ATTN",
  "   T_COMPUTE_FORWARD_RWKV_WKV7",
  "   T_COMPUTE_FORWARD_CUSTOM",
  "   T_COMPUTE_FORWARD_OPT_STEP_ADAMW",
  "   T_COMPUTE_FORWARD_OPT_STEP_SGD",
 };

void print_sep(int i)
{
  int t;
  double total_time;

  // Skip if this enum type was never called
  if (enum_counts[i] == 0) {
    return;
  }

  // Get total time from T_MAIN, avoid division by zero
  total_time = sep_times[0][T_MAIN];
  if (total_time <= 0.0) {
    // If T_MAIN is zero, skip percentage calculation
    printf("%-54s:", monitor_names[i]);
    for (t=0; t<(!NTHREAD?1:NTHREAD); t++) {
      printf(" %5.1fs(N/A%%)", (double)sep_times[t][i]);
    }
    printf("\n");
    return;
  }

  printf("%-54s:", monitor_names[i]);
  for (t=0; t<(!NTHREAD?1:NTHREAD); t++) {
    printf(" %5.1fs(%5.1f%%)",
           (double)sep_times[t][i],
           (double)sep_times[t][i]*100.0 / total_time);
  }
  printf("\n");
}

// Function to print execution counts for each enum type
void print_enum_count(int i)
{
  printf("%-54s: %8lu calls\n", monitor_names[i], enum_counts[i]);
}

// Function to display all execution counts
void show_enum_counts(void) {
  int i;
  
  printf("\n===== EXECUTION COUNTS FOR EACH ENUM TYPE =====\n");
  for (i = 0; i < MONITOREND; i++) {
    if (enum_counts[i] > 0) {
      print_enum_count(i);
    }
  }
  printf("===== END OF EXECUTION COUNTS =====\n\n");
}

void show_time_sep(void) {
  int t;

  printf("\n");
  printf("%-54s:", " ");
  for (t=0; t<(!NTHREAD?1:NTHREAD); t++)
    printf("   TH%02.2d        ", t);
  printf("\n");
  print_sep(T_MAIN);
  print_sep(T_MAIN_WHILE);
  print_sep(T_MAIN_GA_N_EQ1);
  print_sep(T_MAIN_GA_N_NE1);
  print_sep(T_MAIN_SESSION);
  print_sep(T_MAIN_EMBD_SIZE);
  print_sep(T_LLAMA_GRAPH_COMPUTE);
  print_sep(T_GGML_BACKEND_SCHED_COMPUTE_SPLITS);
  print_sep(T_GGML_GRAPH_COMPUTE);
  print_sep(T_COMPUTE_FORWARD);
  print_sep(T_COMPUTE_FORWARD_DUP);
  print_sep(T_COMPUTE_FORWARD_ADD);
  print_sep(T_COMPUTE_FORWARD_ADD_ID);
  print_sep(T_COMPUTE_FORWARD_ADD1);
  print_sep(T_COMPUTE_FORWARD_ACC);
  print_sep(T_COMPUTE_FORWARD_SUB);
  print_sep(T_COMPUTE_FORWARD_MUL);
  print_sep(T_COMPUTE_FORWARD_DIV);
  print_sep(T_COMPUTE_FORWARD_SQR);
  print_sep(T_COMPUTE_FORWARD_SQRT);
  print_sep(T_COMPUTE_FORWARD_LOG);
  print_sep(T_COMPUTE_FORWARD_SUM);
  print_sep(T_COMPUTE_FORWARD_SUM_ROWS);
  print_sep(T_COMPUTE_FORWARD_MEAN);
  print_sep(T_COMPUTE_FORWARD_ARGMAX);
  print_sep(T_COMPUTE_FORWARD_REPEAT);
  print_sep(T_COMPUTE_FORWARD_REPEAT_BACK);
  print_sep(T_COMPUTE_FORWARD_CONCAT);
  print_sep(T_COMPUTE_FORWARD_SILU_BACK);
  print_sep(T_COMPUTE_FORWARD_NORM);
  print_sep(T_COMPUTE_FORWARD_RMS_NORM);
  print_sep(T_COMPUTE_FORWARD_RMS_NORM_BACK);
  print_sep(T_COMPUTE_FORWARD_GROUP_NORM);
  print_sep(T_COMPUTE_FORWARD_MUL_MAT);
  print_sep(T_COMPUTE_FORWARD_MUL_MAT_NE_VEC_DOT);
  print_sep(T_COMPUTE_FORWARD_MUL_MAT_NDIMS_EQ_2);
  print_sep(T_COMPUTE_FORWARD_MUL_MAT_WHILE_CHUNK);
  print_sep(T_COMPUTE_FORWARD_MUL_MAT_ONE_CHUNK);
  print_sep(IMAX_COMPUTE_FORWARD_MUL_MAT_ONE_CHUNK_F32);
  print_sep(IMAX_COMPUTE_FORWARD_MUL_MAT_ONE_CHUNK_F32_ARM);
  print_sep(IMAX_COMPUTE_FORWARD_MUL_MAT_ONE_CHUNK_F16);
  print_sep(IMAX_COMPUTE_FORWARD_MUL_MAT_ONE_CHUNK_F16_ARM);
  print_sep(IMAX_COMPUTE_FORWARD_MUL_MAT_ONE_CHUNK_Q2K);
  print_sep(IMAX_COMPUTE_FORWARD_MUL_MAT_ONE_CHUNK_Q2K_ARM);
  print_sep(IMAX_COMPUTE_FORWARD_MUL_MAT_ONE_CHUNK_Q3K);
  print_sep(IMAX_COMPUTE_FORWARD_MUL_MAT_ONE_CHUNK_Q3K_ARM);
  // print_sep(IMAX_COMPUTE_FORWARD_MUL_MAT_ONE_CHUNK_Q4K);
  // print_sep(IMAX_COMPUTE_FORWARD_MUL_MAT_ONE_CHUNK_Q4K_ARM);
  // print_sep(IMAX_COMPUTE_FORWARD_MUL_MAT_ONE_CHUNK_Q5K);
  // print_sep(IMAX_COMPUTE_FORWARD_MUL_MAT_ONE_CHUNK_Q5K_ARM);
  print_sep(IMAX_COMPUTE_FORWARD_MUL_MAT_ONE_CHUNK_Q6K);
  print_sep(IMAX_COMPUTE_FORWARD_MUL_MAT_ONE_CHUNK_Q6K_ARM);
  print_sep(IMAX_COMPUTE_FORWARD_MUL_MAT_ONE_CHUNK_Q80);
  print_sep(IMAX_COMPUTE_FORWARD_MUL_MAT_ONE_CHUNK_Q80_ARM);
  // print_sep(IMAX_COMPUTE_FORWARD_MUL_MAT_ONE_CHUNK_Q8K);
  // print_sep(IMAX_COMPUTE_FORWARD_MUL_MAT_ONE_CHUNK_Q8K_ARM);
  print_sep(IMAX_COMPUTE_FORWARD_MUL_MAT_ONE_CHUNK_OTHER_ARM);
  print_sep(VEC_DOT_OPERATION);
  print_sep(ARM_MEMCPY);
  print_sep(IMAX_CPYIN_PRELOAD);
  print_sep(IMAX_CPYIN_A);
  print_sep(IMAX_CPYIN_A_Q80);
  print_sep(IMAX_CPYIN_B);
  print_sep(IMAX_CPYIN_A_Q3K);
  print_sep(IMAX_CPYIN_B_Q3K);
  print_sep(IMAX_BZERO_Q3K);
  print_sep(IMAX_CPYOUT_Q3K);
  print_sep(IMAX_CPYIN_A_Q6K);
  print_sep(IMAX_CPYIN_B_Q6K);
  print_sep(IMAX_BZERO_Q6K);
  print_sep(IMAX_CPYOUT_Q6K);
  print_sep(IMAX_BZERO);
  print_sep(IMAX_CPYOUT);
  print_sep(IMAX_MEMCPY);
  print_sep(IMAX_MEMCPY_A);
  print_sep(IMAX_MEMCPY_B);
  print_sep(IMAX_MEMCPY_C);
  print_sep(IMAX_PIOCPY);
  print_sep(IMAX_TERM_1);
  print_sep(IMAX_TERM_2);
  print_sep(IMAX_TERM_3);
  print_sep(IMAX_TERM_4);
  print_sep(IMAX_TERM_5);
  print_sep(IMAX_TERM_6);
  print_sep(IMAX_TERM_7);
  print_sep(IMAX_TERM_8);
  print_sep(T_COMPUTE_FORWARD_MUL_MAT_ID);
  print_sep(T_COMPUTE_FORWARD_OUT_PROD);
  print_sep(T_COMPUTE_FORWARD_SCALE);
  print_sep(T_COMPUTE_FORWARD_SET);
  print_sep(T_COMPUTE_FORWARD_CPY);
  print_sep(T_COMPUTE_FORWARD_CONT);  
  print_sep(T_COMPUTE_FORWARD_RESHAPE);
  print_sep(T_COMPUTE_FORWARD_VIEW);
  print_sep(T_COMPUTE_FORWARD_PERMUTE);
  print_sep(T_COMPUTE_FORWARD_TRANSPOSE);
  print_sep(T_COMPUTE_FORWARD_GET_ROWS);
  print_sep(T_COMPUTE_FORWARD_GET_ROWS_BACK);
  print_sep(T_COMPUTE_FORWARD_DIAG);
  print_sep(T_COMPUTE_FORWARD_DIAG_MASK_INF);
  print_sep(T_COMPUTE_FORWARD_DIAG_MASK_ZERO);
  print_sep(T_COMPUTE_FORWARD_SET_ROWS);
  print_sep(T_COMPUTE_FORWARD_GLU);
  print_sep(T_COMPUTE_FORWARD_SOFT_MAX);
  print_sep(T_COMPUTE_FORWARD_SOFT_MAX_BACK);
  print_sep(T_COMPUTE_FORWARD_ROPE);
  print_sep(T_COMPUTE_FORWARD_ROPE_BACK);
  print_sep(T_COMPUTE_FORWARD_ROLL);
  print_sep(T_COMPUTE_FORWARD_CLAMP);
  print_sep(T_COMPUTE_FORWARD_CONV_TRANSPOSE_1D);
  print_sep(T_COMPUTE_FORWARD_IM2COL);
  print_sep(T_COMPUTE_FORWARD_IM2COL_BACK);
  print_sep(T_COMPUTE_FORWARD_IM2COL_3D);
  print_sep(T_COMPUTE_FORWARD_CONV_2D);
  print_sep(T_COMPUTE_FORWARD_CONV_3D);
  print_sep(T_COMPUTE_FORWARD_CONV_2D_DW);
  print_sep(T_COMPUTE_FORWARD_CONV_TRANSPOSE_2D);
  print_sep(T_COMPUTE_FORWARD_POOL_1D);
  print_sep(T_COMPUTE_FORWARD_POOL_2D);
  print_sep(T_COMPUTE_FORWARD_POOL_2D_BACK);
  print_sep(T_COMPUTE_FORWARD_UPSCALE);
  print_sep(T_COMPUTE_FORWARD_PAD);
  print_sep(T_COMPUTE_FORWARD_PAD_REFLECT_1D);
  print_sep(T_COMPUTE_FORWARD_ARANGE);
  print_sep(T_COMPUTE_FORWARD_TIMESTEP_EMBEDDING);
  print_sep(T_COMPUTE_FORWARD_ARGSORT);
  print_sep(T_COMPUTE_FORWARD_LEAKY_RELU);
  print_sep(T_COMPUTE_FORWARD_FLASH_ATTN_EXT);
  print_sep(T_COMPUTE_FORWARD_FLASH_ATTN_BACK);
  print_sep(T_COMPUTE_FORWARD_SSM_CONV);
  print_sep(T_COMPUTE_FORWARD_SSM_SCAN);
  print_sep(T_COMPUTE_FORWARD_WIN_PART);
  print_sep(T_COMPUTE_FORWARD_WIN_UNPART);
  print_sep(T_COMPUTE_FORWARD_UNARY);
  print_sep(T_COMPUTE_FORWARD_GET_REL_POS);
  print_sep(T_COMPUTE_FORWARD_ADD_REL_POS);
  print_sep(T_COMPUTE_FORWARD_MAP_UNARY);
  print_sep(T_COMPUTE_FORWARD_MAP_BINARY);
  print_sep(T_COMPUTE_FORWARD_MAP_CUSTOM1_F32);
  print_sep(T_COMPUTE_FORWARD_MAP_CUSTOM2_F32);
  print_sep(T_COMPUTE_FORWARD_MAP_CUSTOM3_F32);
  print_sep(T_COMPUTE_FORWARD_MAP_CUSTOM1);
  print_sep(T_COMPUTE_FORWARD_MAP_CUSTOM2);
  print_sep(T_COMPUTE_FORWARD_MAP_CUSTOM3);
  print_sep(T_COMPUTE_FORWARD_CROSS_ENTROPY_LOSS);
  print_sep(T_COMPUTE_FORWARD_CROSS_ENTROPY_LOSS_BACK);
  print_sep(T_COMPUTE_FORWARD_NONE);
  print_sep(T_COMPUTE_FORWARD_COUNT);
  print_sep(T_COMPUTE_FORWARD_SIN);
  print_sep(T_COMPUTE_FORWARD_COS);
  print_sep(T_COMPUTE_FORWARD_COUNT_EQUAL);
  print_sep(T_COMPUTE_FORWARD_L2_NORM);
  print_sep(T_COMPUTE_FORWARD_RWKV_WKV6);
  print_sep(T_COMPUTE_FORWARD_GATED_LINEAR_ATTN);
  print_sep(T_COMPUTE_FORWARD_RWKV_WKV7);
  print_sep(T_COMPUTE_FORWARD_CUSTOM);
  print_sep(T_COMPUTE_FORWARD_OPT_STEP_ADAMW);
  print_sep(T_COMPUTE_FORWARD_OPT_STEP_SGD);
  
  // Show execution counts
  show_enum_counts();
  
  // Show data transfer statistics
  // show_cpyin_stats();
}
