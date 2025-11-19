typedef unsigned char Uchar;
typedef unsigned short Ushort;
typedef unsigned int Uint;
typedef unsigned long long Ull;
typedef long long int Sll;
typedef long double Dll;

typedef long unsigned int size_t;
typedef __builtin_va_list __gnuc_va_list;
typedef unsigned char __u_char;
typedef unsigned short int __u_short;
typedef unsigned int __u_int;
typedef unsigned long int __u_long;
typedef signed char __int8_t;
typedef unsigned char __uint8_t;
typedef signed short int __int16_t;
typedef unsigned short int __uint16_t;
typedef signed int __int32_t;
typedef unsigned int __uint32_t;
typedef signed long int __int64_t;
typedef unsigned long int __uint64_t;
typedef __int8_t __int_least8_t;
typedef __uint8_t __uint_least8_t;
typedef __int16_t __int_least16_t;
typedef __uint16_t __uint_least16_t;
typedef __int32_t __int_least32_t;
typedef __uint32_t __uint_least32_t;
typedef __int64_t __int_least64_t;
typedef __uint64_t __uint_least64_t;
typedef long int __quad_t;
typedef unsigned long int __u_quad_t;
typedef long int __intmax_t;
typedef unsigned long int __uintmax_t;
typedef unsigned long int __dev_t;
typedef unsigned int __uid_t;
typedef unsigned int __gid_t;
typedef unsigned long int __ino_t;
typedef unsigned long int __ino64_t;
typedef unsigned int __mode_t;
typedef unsigned int __nlink_t;
typedef long int __off_t;
typedef long int __off64_t;
typedef int __pid_t;
typedef struct { int __val[2]; } __fsid_t;
typedef long int __clock_t;
typedef unsigned long int __rlim_t;
typedef unsigned long int __rlim64_t;
typedef unsigned int __id_t;
typedef long int __time_t;
typedef unsigned int __useconds_t;
typedef long int __suseconds_t;
typedef long int __suseconds64_t;
typedef int __daddr_t;
typedef int __key_t;
typedef int __clockid_t;
typedef void * __timer_t;
typedef int __blksize_t;
typedef long int __blkcnt_t;
typedef long int __blkcnt64_t;
typedef unsigned long int __fsblkcnt_t;
typedef unsigned long int __fsblkcnt64_t;
typedef unsigned long int __fsfilcnt_t;
typedef unsigned long int __fsfilcnt64_t;
typedef long int __fsword_t;
typedef long int __ssize_t;
typedef long int __syscall_slong_t;
typedef unsigned long int __syscall_ulong_t;
typedef __off64_t __loff_t;
typedef char *__caddr_t;
typedef long int __intptr_t;
typedef unsigned int __socklen_t;
typedef int __sig_atomic_t;
typedef struct
{
  int __count;
  union
  {
    unsigned int __wch;
    char __wchb[4];
  } __value;
} __mbstate_t;
typedef struct _G_fpos_t
{
  __off_t __pos;
  __mbstate_t __state;
} __fpos_t;
typedef struct _G_fpos64_t
{
  __off64_t __pos;
  __mbstate_t __state;
} __fpos64_t;
struct _IO_FILE;
typedef struct _IO_FILE __FILE;
struct _IO_FILE;
typedef struct _IO_FILE FILE;
struct _IO_FILE;
struct _IO_marker;
struct _IO_codecvt;
struct _IO_wide_data;
typedef void _IO_lock_t;
struct _IO_FILE
{
  int _flags;
  char *_IO_read_ptr;
  char *_IO_read_end;
  char *_IO_read_base;
  char *_IO_write_base;
  char *_IO_write_ptr;
  char *_IO_write_end;
  char *_IO_buf_base;
  char *_IO_buf_end;
  char *_IO_save_base;
  char *_IO_backup_base;
  char *_IO_save_end;
  struct _IO_marker *_markers;
  struct _IO_FILE *_chain;
  int _fileno;
  int _flags2;
  __off_t _old_offset;
  unsigned short _cur_column;
  signed char _vtable_offset;
  char _shortbuf[1];
  _IO_lock_t *_lock;
  __off64_t _offset;
  struct _IO_codecvt *_codecvt;
  struct _IO_wide_data *_wide_data;
  struct _IO_FILE *_freeres_list;
  void *_freeres_buf;
  size_t __pad5;
  int _mode;
  char _unused2[15 * sizeof (int) - 4 * sizeof (void *) - sizeof (size_t)];
};
typedef __ssize_t cookie_read_function_t (void *__cookie, char *__buf,
                                          size_t __nbytes);
typedef __ssize_t cookie_write_function_t (void *__cookie, const char *__buf,
                                           size_t __nbytes);
typedef int cookie_seek_function_t (void *__cookie, __off64_t *__pos, int __w);
typedef int cookie_close_function_t (void *__cookie);
typedef struct _IO_cookie_io_functions_t
{
  cookie_read_function_t *read;
  cookie_write_function_t *write;
  cookie_seek_function_t *seek;
  cookie_close_function_t *close;
} cookie_io_functions_t;
typedef __gnuc_va_list va_list;
typedef __off_t off_t;
typedef __off64_t off64_t;
typedef __ssize_t ssize_t;
typedef __fpos_t fpos_t;
typedef __fpos64_t fpos64_t;
extern FILE *stdin;
extern FILE *stdout;
extern FILE *stderr;
extern int remove (const char *__filename) __attribute__ ((__nothrow__ , __leaf__));
extern int rename (const char *__old, const char *__new) __attribute__ ((__nothrow__ , __leaf__));
extern int renameat (int __oldfd, const char *__old, int __newfd,
       const char *__new) __attribute__ ((__nothrow__ , __leaf__));
extern int renameat2 (int __oldfd, const char *__old, int __newfd,
        const char *__new, unsigned int __flags) __attribute__ ((__nothrow__ , __leaf__));
extern int fclose (FILE *__stream);
extern FILE *tmpfile (void)
  __attribute__ ((__malloc__)) __attribute__ ((__malloc__ (fclose, 1))) ;
extern FILE *tmpfile64 (void)
   __attribute__ ((__malloc__)) __attribute__ ((__malloc__ (fclose, 1))) ;
extern char *tmpnam (char[20]) __attribute__ ((__nothrow__ , __leaf__)) ;
extern char *tmpnam_r (char __s[20]) __attribute__ ((__nothrow__ , __leaf__)) ;
extern char *tempnam (const char *__dir, const char *__pfx)
   __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__malloc__)) __attribute__ ((__malloc__ (__builtin_free, 1)));
extern int fflush (FILE *__stream);
extern int fflush_unlocked (FILE *__stream);
extern int fcloseall (void);
extern FILE *fopen (const char *__restrict __filename,
      const char *__restrict __modes)
  __attribute__ ((__malloc__)) __attribute__ ((__malloc__ (fclose, 1))) ;
extern FILE *freopen (const char *__restrict __filename,
        const char *__restrict __modes,
        FILE *__restrict __stream) ;
extern FILE *fopen64 (const char *__restrict __filename,
        const char *__restrict __modes)
  __attribute__ ((__malloc__)) __attribute__ ((__malloc__ (fclose, 1))) ;
extern FILE *freopen64 (const char *__restrict __filename,
   const char *__restrict __modes,
   FILE *__restrict __stream) ;
extern FILE *fdopen (int __fd, const char *__modes) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__malloc__)) __attribute__ ((__malloc__ (fclose, 1))) ;
extern FILE *fopencookie (void *__restrict __magic_cookie,
     const char *__restrict __modes,
     cookie_io_functions_t __io_funcs) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__malloc__)) __attribute__ ((__malloc__ (fclose, 1))) ;
extern FILE *fmemopen (void *__s, size_t __len, const char *__modes)
  __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__malloc__)) __attribute__ ((__malloc__ (fclose, 1))) ;
extern FILE *open_memstream (char **__bufloc, size_t *__sizeloc) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__malloc__)) __attribute__ ((__malloc__ (fclose, 1))) ;
extern void setbuf (FILE *__restrict __stream, char *__restrict __buf) __attribute__ ((__nothrow__ , __leaf__));
extern int setvbuf (FILE *__restrict __stream, char *__restrict __buf,
      int __modes, size_t __n) __attribute__ ((__nothrow__ , __leaf__));
extern void setbuffer (FILE *__restrict __stream, char *__restrict __buf,
         size_t __size) __attribute__ ((__nothrow__ , __leaf__));
extern void setlinebuf (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__));
extern int fprintf (FILE *__restrict __stream,
      const char *__restrict __format, ...);
extern int printf (const char *__restrict __format, ...);
extern int sprintf (char *__restrict __s,
      const char *__restrict __format, ...) __attribute__ ((__nothrow__));
extern int vfprintf (FILE *__restrict __s, const char *__restrict __format,
       __gnuc_va_list __arg);
extern int vprintf (const char *__restrict __format, __gnuc_va_list __arg);
extern int vsprintf (char *__restrict __s, const char *__restrict __format,
       __gnuc_va_list __arg) __attribute__ ((__nothrow__));
extern int snprintf (char *__restrict __s, size_t __maxlen,
       const char *__restrict __format, ...)
     __attribute__ ((__nothrow__)) __attribute__ ((__format__ (__printf__, 3, 4)));
extern int vsnprintf (char *__restrict __s, size_t __maxlen,
        const char *__restrict __format, __gnuc_va_list __arg)
     __attribute__ ((__nothrow__)) __attribute__ ((__format__ (__printf__, 3, 0)));
extern int vasprintf (char **__restrict __ptr, const char *__restrict __f,
        __gnuc_va_list __arg)
     __attribute__ ((__nothrow__)) __attribute__ ((__format__ (__printf__, 2, 0))) ;
extern int __asprintf (char **__restrict __ptr,
         const char *__restrict __fmt, ...)
     __attribute__ ((__nothrow__)) __attribute__ ((__format__ (__printf__, 2, 3))) ;
extern int asprintf (char **__restrict __ptr,
       const char *__restrict __fmt, ...)
     __attribute__ ((__nothrow__)) __attribute__ ((__format__ (__printf__, 2, 3))) ;
extern int vdprintf (int __fd, const char *__restrict __fmt,
       __gnuc_va_list __arg)
     __attribute__ ((__format__ (__printf__, 2, 0)));
extern int dprintf (int __fd, const char *__restrict __fmt, ...)
     __attribute__ ((__format__ (__printf__, 2, 3)));
extern int fscanf (FILE *__restrict __stream,
     const char *__restrict __format, ...) ;
extern int scanf (const char *__restrict __format, ...) ;
extern int sscanf (const char *__restrict __s,
     const char *__restrict __format, ...) __attribute__ ((__nothrow__ , __leaf__));
extern int fscanf (FILE *__restrict __stream, const char *__restrict __format, ...) __asm__ ("" "__isoc99_fscanf") ;
extern int scanf (const char *__restrict __format, ...) __asm__ ("" "__isoc99_scanf") ;
extern int sscanf (const char *__restrict __s, const char *__restrict __format, ...) __asm__ ("" "__isoc99_sscanf") __attribute__ ((__nothrow__ , __leaf__));
extern int vfscanf (FILE *__restrict __s, const char *__restrict __format,
      __gnuc_va_list __arg)
     __attribute__ ((__format__ (__scanf__, 2, 0))) ;
extern int vscanf (const char *__restrict __format, __gnuc_va_list __arg)
     __attribute__ ((__format__ (__scanf__, 1, 0))) ;
extern int vsscanf (const char *__restrict __s,
      const char *__restrict __format, __gnuc_va_list __arg)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__format__ (__scanf__, 2, 0)));
extern int vfscanf (FILE *__restrict __s, const char *__restrict __format, __gnuc_va_list __arg) __asm__ ("" "__isoc99_vfscanf")
     __attribute__ ((__format__ (__scanf__, 2, 0))) ;
extern int vscanf (const char *__restrict __format, __gnuc_va_list __arg) __asm__ ("" "__isoc99_vscanf")
     __attribute__ ((__format__ (__scanf__, 1, 0))) ;
extern int vsscanf (const char *__restrict __s, const char *__restrict __format, __gnuc_va_list __arg) __asm__ ("" "__isoc99_vsscanf") __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__format__ (__scanf__, 2, 0)));
extern int fgetc (FILE *__stream);
extern int getc (FILE *__stream);
extern int getchar (void);
extern int getc_unlocked (FILE *__stream);
extern int getchar_unlocked (void);
extern int fgetc_unlocked (FILE *__stream);
extern int fputc (int __c, FILE *__stream);
extern int putc (int __c, FILE *__stream);
extern int putchar (int __c);
extern int fputc_unlocked (int __c, FILE *__stream);
extern int putc_unlocked (int __c, FILE *__stream);
extern int putchar_unlocked (int __c);
extern int getw (FILE *__stream);
extern int putw (int __w, FILE *__stream);
extern char *fgets (char *__restrict __s, int __n, FILE *__restrict __stream)
     __attribute__ ((__access__ (__write_only__, 1, 2)));
extern char *fgets_unlocked (char *__restrict __s, int __n,
        FILE *__restrict __stream)
    __attribute__ ((__access__ (__write_only__, 1, 2)));
extern __ssize_t __getdelim (char **__restrict __lineptr,
                             size_t *__restrict __n, int __delimiter,
                             FILE *__restrict __stream) ;
extern __ssize_t getdelim (char **__restrict __lineptr,
                           size_t *__restrict __n, int __delimiter,
                           FILE *__restrict __stream) ;
extern __ssize_t getline (char **__restrict __lineptr,
                          size_t *__restrict __n,
                          FILE *__restrict __stream) ;
extern int fputs (const char *__restrict __s, FILE *__restrict __stream);
extern int puts (const char *__s);
extern int ungetc (int __c, FILE *__stream);
extern size_t fread (void *__restrict __ptr, size_t __size,
       size_t __n, FILE *__restrict __stream) ;
extern size_t fwrite (const void *__restrict __ptr, size_t __size,
        size_t __n, FILE *__restrict __s);
extern int fputs_unlocked (const char *__restrict __s,
      FILE *__restrict __stream);
extern size_t fread_unlocked (void *__restrict __ptr, size_t __size,
         size_t __n, FILE *__restrict __stream) ;
extern size_t fwrite_unlocked (const void *__restrict __ptr, size_t __size,
          size_t __n, FILE *__restrict __stream);
extern int fseek (FILE *__stream, long int __off, int __whence);
extern long int ftell (FILE *__stream) ;
extern void rewind (FILE *__stream);
extern int fseeko (FILE *__stream, __off_t __off, int __whence);
extern __off_t ftello (FILE *__stream) ;
extern int fgetpos (FILE *__restrict __stream, fpos_t *__restrict __pos);
extern int fsetpos (FILE *__stream, const fpos_t *__pos);
extern int fseeko64 (FILE *__stream, __off64_t __off, int __whence);
extern __off64_t ftello64 (FILE *__stream) ;
extern int fgetpos64 (FILE *__restrict __stream, fpos64_t *__restrict __pos);
extern int fsetpos64 (FILE *__stream, const fpos64_t *__pos);
extern void clearerr (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__));
extern int feof (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) ;
extern int ferror (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) ;
extern void clearerr_unlocked (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__));
extern int feof_unlocked (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) ;
extern int ferror_unlocked (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) ;
extern void perror (const char *__s);
extern int fileno (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) ;
extern int fileno_unlocked (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) ;
extern int pclose (FILE *__stream);
extern FILE *popen (const char *__command, const char *__modes)
  __attribute__ ((__malloc__)) __attribute__ ((__malloc__ (pclose, 1))) ;
extern char *ctermid (char *__s) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__access__ (__write_only__, 1)));
extern char *cuserid (char *__s)
  __attribute__ ((__access__ (__write_only__, 1)));
struct obstack;
extern int obstack_printf (struct obstack *__restrict __obstack,
      const char *__restrict __format, ...)
     __attribute__ ((__nothrow__)) __attribute__ ((__format__ (__printf__, 2, 3)));
extern int obstack_vprintf (struct obstack *__restrict __obstack,
       const char *__restrict __format,
       __gnuc_va_list __args)
     __attribute__ ((__nothrow__)) __attribute__ ((__format__ (__printf__, 2, 0)));
extern void flockfile (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__));
extern int ftrylockfile (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) ;
extern void funlockfile (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__));
extern int __uflow (FILE *);
extern int __overflow (FILE *, int);
extern __inline __attribute__ ((__gnu_inline__)) int
vprintf (const char *__restrict __fmt, __gnuc_va_list __arg)
{
  return vfprintf (stdout, __fmt, __arg);
}
extern __inline __attribute__ ((__gnu_inline__)) int
getchar (void)
{
  return getc (stdin);
}
extern __inline __attribute__ ((__gnu_inline__)) int
fgetc_unlocked (FILE *__fp)
{
  return (__builtin_expect (((__fp)->_IO_read_ptr >= (__fp)->_IO_read_end), 0) ? __uflow (__fp) : *(unsigned char *) (__fp)->_IO_read_ptr++);
}
extern __inline __attribute__ ((__gnu_inline__)) int
getc_unlocked (FILE *__fp)
{
  return (__builtin_expect (((__fp)->_IO_read_ptr >= (__fp)->_IO_read_end), 0) ? __uflow (__fp) : *(unsigned char *) (__fp)->_IO_read_ptr++);
}
extern __inline __attribute__ ((__gnu_inline__)) int
getchar_unlocked (void)
{
  return (__builtin_expect (((stdin)->_IO_read_ptr >= (stdin)->_IO_read_end), 0) ? __uflow (stdin) : *(unsigned char *) (stdin)->_IO_read_ptr++);
}
extern __inline __attribute__ ((__gnu_inline__)) int
putchar (int __c)
{
  return putc (__c, stdout);
}
extern __inline __attribute__ ((__gnu_inline__)) int
fputc_unlocked (int __c, FILE *__stream)
{
  return (__builtin_expect (((__stream)->_IO_write_ptr >= (__stream)->_IO_write_end), 0) ? __overflow (__stream, (unsigned char) (__c)) : (unsigned char) (*(__stream)->_IO_write_ptr++ = (__c)));
}
extern __inline __attribute__ ((__gnu_inline__)) int
putc_unlocked (int __c, FILE *__stream)
{
  return (__builtin_expect (((__stream)->_IO_write_ptr >= (__stream)->_IO_write_end), 0) ? __overflow (__stream, (unsigned char) (__c)) : (unsigned char) (*(__stream)->_IO_write_ptr++ = (__c)));
}
extern __inline __attribute__ ((__gnu_inline__)) int
putchar_unlocked (int __c)
{
  return (__builtin_expect (((stdout)->_IO_write_ptr >= (stdout)->_IO_write_end), 0) ? __overflow (stdout, (unsigned char) (__c)) : (unsigned char) (*(stdout)->_IO_write_ptr++ = (__c)));
}
extern __inline __attribute__ ((__gnu_inline__)) __ssize_t
getline (char **__lineptr, size_t *__n, FILE *__stream)
{
  return __getdelim (__lineptr, __n, '\n', __stream);
}
extern __inline __attribute__ ((__gnu_inline__)) int
__attribute__ ((__nothrow__ , __leaf__)) feof_unlocked (FILE *__stream)
{
  return (((__stream)->_flags & 0x0010) != 0);
}
extern __inline __attribute__ ((__gnu_inline__)) int
__attribute__ ((__nothrow__ , __leaf__)) ferror_unlocked (FILE *__stream)
{
  return (((__stream)->_flags & 0x0020) != 0);
}

typedef unsigned int wchar_t;

typedef struct
  {
    int quot;
    int rem;
  } div_t;
typedef struct
  {
    long int quot;
    long int rem;
  } ldiv_t;
__extension__ typedef struct
  {
    long long int quot;
    long long int rem;
  } lldiv_t;
extern size_t __ctype_get_mb_cur_max (void) __attribute__ ((__nothrow__ , __leaf__)) ;
extern double atof (const char *__nptr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1))) ;
extern int atoi (const char *__nptr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1))) ;
extern long int atol (const char *__nptr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1))) ;
__extension__ extern long long int atoll (const char *__nptr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1))) ;
extern double strtod (const char *__restrict __nptr,
        char **__restrict __endptr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern float strtof (const char *__restrict __nptr,
       char **__restrict __endptr) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern long double strtold (const char *__restrict __nptr,
       char **__restrict __endptr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern _Float32 strtof32 (const char *__restrict __nptr,
     char **__restrict __endptr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern _Float64 strtof64 (const char *__restrict __nptr,
     char **__restrict __endptr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern _Float128 strtof128 (const char *__restrict __nptr,
       char **__restrict __endptr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern _Float32x strtof32x (const char *__restrict __nptr,
       char **__restrict __endptr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern _Float64x strtof64x (const char *__restrict __nptr,
       char **__restrict __endptr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern long int strtol (const char *__restrict __nptr,
   char **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern unsigned long int strtoul (const char *__restrict __nptr,
      char **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
__extension__
extern long long int strtoq (const char *__restrict __nptr,
        char **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
__extension__
extern unsigned long long int strtouq (const char *__restrict __nptr,
           char **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
__extension__
extern long long int strtoll (const char *__restrict __nptr,
         char **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
__extension__
extern unsigned long long int strtoull (const char *__restrict __nptr,
     char **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int strfromd (char *__dest, size_t __size, const char *__format,
       double __f)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3)));
extern int strfromf (char *__dest, size_t __size, const char *__format,
       float __f)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3)));
extern int strfroml (char *__dest, size_t __size, const char *__format,
       long double __f)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3)));
extern int strfromf32 (char *__dest, size_t __size, const char * __format,
         _Float32 __f)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3)));
extern int strfromf64 (char *__dest, size_t __size, const char * __format,
         _Float64 __f)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3)));
extern int strfromf128 (char *__dest, size_t __size, const char * __format,
   _Float128 __f)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3)));
extern int strfromf32x (char *__dest, size_t __size, const char * __format,
   _Float32x __f)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3)));
extern int strfromf64x (char *__dest, size_t __size, const char * __format,
   _Float64x __f)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3)));
struct __locale_struct
{
  struct __locale_data *__locales[13];
  const unsigned short int *__ctype_b;
  const int *__ctype_tolower;
  const int *__ctype_toupper;
  const char *__names[13];
};
typedef struct __locale_struct *__locale_t;
typedef __locale_t locale_t;
extern long int strtol_l (const char *__restrict __nptr,
     char **__restrict __endptr, int __base,
     locale_t __loc) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 4)));
extern unsigned long int strtoul_l (const char *__restrict __nptr,
        char **__restrict __endptr,
        int __base, locale_t __loc)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 4)));
__extension__
extern long long int strtoll_l (const char *__restrict __nptr,
    char **__restrict __endptr, int __base,
    locale_t __loc)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 4)));
__extension__
extern unsigned long long int strtoull_l (const char *__restrict __nptr,
       char **__restrict __endptr,
       int __base, locale_t __loc)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 4)));
extern double strtod_l (const char *__restrict __nptr,
   char **__restrict __endptr, locale_t __loc)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 3)));
extern float strtof_l (const char *__restrict __nptr,
         char **__restrict __endptr, locale_t __loc)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 3)));
extern long double strtold_l (const char *__restrict __nptr,
         char **__restrict __endptr,
         locale_t __loc)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 3)));
extern _Float32 strtof32_l (const char *__restrict __nptr,
       char **__restrict __endptr,
       locale_t __loc)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 3)));
extern _Float64 strtof64_l (const char *__restrict __nptr,
       char **__restrict __endptr,
       locale_t __loc)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 3)));
extern _Float128 strtof128_l (const char *__restrict __nptr,
         char **__restrict __endptr,
         locale_t __loc)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 3)));
extern _Float32x strtof32x_l (const char *__restrict __nptr,
         char **__restrict __endptr,
         locale_t __loc)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 3)));
extern _Float64x strtof64x_l (const char *__restrict __nptr,
         char **__restrict __endptr,
         locale_t __loc)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 3)));
extern __inline __attribute__ ((__gnu_inline__)) int
__attribute__ ((__nothrow__ , __leaf__)) atoi (const char *__nptr)
{
  return (int) strtol (__nptr, (char **) ((void *)0), 10);
}
extern __inline __attribute__ ((__gnu_inline__)) long int
__attribute__ ((__nothrow__ , __leaf__)) atol (const char *__nptr)
{
  return strtol (__nptr, (char **) ((void *)0), 10);
}
__extension__ extern __inline __attribute__ ((__gnu_inline__)) long long int
__attribute__ ((__nothrow__ , __leaf__)) atoll (const char *__nptr)
{
  return strtoll (__nptr, (char **) ((void *)0), 10);
}
extern char *l64a (long int __n) __attribute__ ((__nothrow__ , __leaf__)) ;
extern long int a64l (const char *__s)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1))) ;

typedef __u_char u_char;
typedef __u_short u_short;
typedef __u_int u_int;
typedef __u_long u_long;
typedef __quad_t quad_t;
typedef __u_quad_t u_quad_t;
typedef __fsid_t fsid_t;
typedef __loff_t loff_t;
typedef __ino_t ino_t;
typedef __ino64_t ino64_t;
typedef __dev_t dev_t;
typedef __gid_t gid_t;
typedef __mode_t mode_t;
typedef __nlink_t nlink_t;
typedef __uid_t uid_t;
typedef __pid_t pid_t;
typedef __id_t id_t;
typedef __daddr_t daddr_t;
typedef __caddr_t caddr_t;
typedef __key_t key_t;
typedef __clock_t clock_t;
typedef __clockid_t clockid_t;
typedef __time_t time_t;
typedef __timer_t timer_t;
typedef __useconds_t useconds_t;
typedef __suseconds_t suseconds_t;
typedef unsigned long int ulong;
typedef unsigned short int ushort;
typedef unsigned int uint;
typedef __int8_t int8_t;
typedef __int16_t int16_t;
typedef __int32_t int32_t;
typedef __int64_t int64_t;
typedef __uint8_t u_int8_t;
typedef __uint16_t u_int16_t;
typedef __uint32_t u_int32_t;
typedef __uint64_t u_int64_t;
typedef int register_t __attribute__ ((__mode__ (__word__)));
static __inline __uint16_t
__bswap_16 (__uint16_t __bsx)
{
  return __builtin_bswap16 (__bsx);
}
static __inline __uint32_t
__bswap_32 (__uint32_t __bsx)
{
  return __builtin_bswap32 (__bsx);
}
__extension__ static __inline __uint64_t
__bswap_64 (__uint64_t __bsx)
{
  return __builtin_bswap64 (__bsx);
}
static __inline __uint16_t
__uint16_identity (__uint16_t __x)
{
  return __x;
}
static __inline __uint32_t
__uint32_identity (__uint32_t __x)
{
  return __x;
}
static __inline __uint64_t
__uint64_identity (__uint64_t __x)
{
  return __x;
}
typedef struct
{
  unsigned long int __val[(1024 / (8 * sizeof (unsigned long int)))];
} __sigset_t;
typedef __sigset_t sigset_t;
struct timeval
{
  __time_t tv_sec;
  __suseconds_t tv_usec;
};
struct timespec
{
  __time_t tv_sec;
  __syscall_slong_t tv_nsec;
};
typedef long int __fd_mask;
typedef struct
  {
    __fd_mask fds_bits[1024 / (8 * (int) sizeof (__fd_mask))];
  } fd_set;
typedef __fd_mask fd_mask;

extern int select (int __nfds, fd_set *__restrict __readfds,
     fd_set *__restrict __writefds,
     fd_set *__restrict __exceptfds,
     struct timeval *__restrict __timeout);
extern int pselect (int __nfds, fd_set *__restrict __readfds,
      fd_set *__restrict __writefds,
      fd_set *__restrict __exceptfds,
      const struct timespec *__restrict __timeout,
      const __sigset_t *__restrict __sigmask);

typedef __blksize_t blksize_t;
typedef __blkcnt_t blkcnt_t;
typedef __fsblkcnt_t fsblkcnt_t;
typedef __fsfilcnt_t fsfilcnt_t;
typedef __blkcnt64_t blkcnt64_t;
typedef __fsblkcnt64_t fsblkcnt64_t;
typedef __fsfilcnt64_t fsfilcnt64_t;
typedef union
{
  __extension__ unsigned long long int __value64;
  struct
  {
    unsigned int __low;
    unsigned int __high;
  } __value32;
} __atomic_wide_counter;
typedef struct __pthread_internal_list
{
  struct __pthread_internal_list *__prev;
  struct __pthread_internal_list *__next;
} __pthread_list_t;
typedef struct __pthread_internal_slist
{
  struct __pthread_internal_slist *__next;
} __pthread_slist_t;
struct __pthread_mutex_s
{
  int __lock ;
  unsigned int __count;
  int __owner;
  unsigned int __nusers;
  int __kind;
  int __spins;
  __pthread_list_t __list;
};
struct __pthread_rwlock_arch_t
{
  unsigned int __readers;
  unsigned int __writers;
  unsigned int __wrphase_futex;
  unsigned int __writers_futex;
  unsigned int __pad3;
  unsigned int __pad4;
  int __cur_writer;
  int __shared;
  unsigned long int __pad1;
  unsigned long int __pad2;
  unsigned int __flags;
};
struct __pthread_cond_s
{
  __atomic_wide_counter __wseq;
  __atomic_wide_counter __g1_start;
  unsigned int __g_refs[2] ;
  unsigned int __g_size[2];
  unsigned int __g1_orig_size;
  unsigned int __wrefs;
  unsigned int __g_signals[2];
};
typedef unsigned int __tss_t;
typedef unsigned long int __thrd_t;
typedef struct
{
  int __data ;
} __once_flag;
typedef unsigned long int pthread_t;
typedef union
{
  char __size[8];
  int __align;
} pthread_mutexattr_t;
typedef union
{
  char __size[8];
  int __align;
} pthread_condattr_t;
typedef unsigned int pthread_key_t;
typedef int pthread_once_t;
union pthread_attr_t
{
  char __size[64];
  long int __align;
};
typedef union pthread_attr_t pthread_attr_t;
typedef union
{
  struct __pthread_mutex_s __data;
  char __size[48];
  long int __align;
} pthread_mutex_t;
typedef union
{
  struct __pthread_cond_s __data;
  char __size[48];
  __extension__ long long int __align;
} pthread_cond_t;
typedef union
{
  struct __pthread_rwlock_arch_t __data;
  char __size[56];
  long int __align;
} pthread_rwlock_t;
typedef union
{
  char __size[8];
  long int __align;
} pthread_rwlockattr_t;
typedef volatile int pthread_spinlock_t;
typedef union
{
  char __size[32];
  long int __align;
} pthread_barrier_t;
typedef union
{
  char __size[8];
  int __align;
} pthread_barrierattr_t;

extern long int random (void) __attribute__ ((__nothrow__ , __leaf__));
extern void srandom (unsigned int __seed) __attribute__ ((__nothrow__ , __leaf__));
extern char *initstate (unsigned int __seed, char *__statebuf,
   size_t __statelen) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));
extern char *setstate (char *__statebuf) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
struct random_data
  {
    int32_t *fptr;
    int32_t *rptr;
    int32_t *state;
    int rand_type;
    int rand_deg;
    int rand_sep;
    int32_t *end_ptr;
  };
extern int random_r (struct random_data *__restrict __buf,
       int32_t *__restrict __result) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int srandom_r (unsigned int __seed, struct random_data *__buf)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));
extern int initstate_r (unsigned int __seed, char *__restrict __statebuf,
   size_t __statelen,
   struct random_data *__restrict __buf)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2, 4)));
extern int setstate_r (char *__restrict __statebuf,
         struct random_data *__restrict __buf)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int rand (void) __attribute__ ((__nothrow__ , __leaf__));
extern void srand (unsigned int __seed) __attribute__ ((__nothrow__ , __leaf__));
extern int rand_r (unsigned int *__seed) __attribute__ ((__nothrow__ , __leaf__));
extern double drand48 (void) __attribute__ ((__nothrow__ , __leaf__));
extern double erand48 (unsigned short int __xsubi[3]) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern long int lrand48 (void) __attribute__ ((__nothrow__ , __leaf__));
extern long int nrand48 (unsigned short int __xsubi[3])
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern long int mrand48 (void) __attribute__ ((__nothrow__ , __leaf__));
extern long int jrand48 (unsigned short int __xsubi[3])
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern void srand48 (long int __seedval) __attribute__ ((__nothrow__ , __leaf__));
extern unsigned short int *seed48 (unsigned short int __seed16v[3])
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern void lcong48 (unsigned short int __param[7]) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
struct drand48_data
  {
    unsigned short int __x[3];
    unsigned short int __old_x[3];
    unsigned short int __c;
    unsigned short int __init;
    __extension__ unsigned long long int __a;
  };
extern int drand48_r (struct drand48_data *__restrict __buffer,
        double *__restrict __result) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int erand48_r (unsigned short int __xsubi[3],
        struct drand48_data *__restrict __buffer,
        double *__restrict __result) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int lrand48_r (struct drand48_data *__restrict __buffer,
        long int *__restrict __result)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int nrand48_r (unsigned short int __xsubi[3],
        struct drand48_data *__restrict __buffer,
        long int *__restrict __result)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int mrand48_r (struct drand48_data *__restrict __buffer,
        long int *__restrict __result)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int jrand48_r (unsigned short int __xsubi[3],
        struct drand48_data *__restrict __buffer,
        long int *__restrict __result)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int srand48_r (long int __seedval, struct drand48_data *__buffer)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));
extern int seed48_r (unsigned short int __seed16v[3],
       struct drand48_data *__buffer) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int lcong48_r (unsigned short int __param[7],
        struct drand48_data *__buffer)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern __uint32_t arc4random (void)
     __attribute__ ((__nothrow__ , __leaf__)) ;
extern void arc4random_buf (void *__buf, size_t __size)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern __uint32_t arc4random_uniform (__uint32_t __upper_bound)
     __attribute__ ((__nothrow__ , __leaf__)) ;
extern void *malloc (size_t __size) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__malloc__))
     __attribute__ ((__alloc_size__ (1))) ;
extern void *calloc (size_t __nmemb, size_t __size)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__malloc__)) __attribute__ ((__alloc_size__ (1, 2))) ;
extern void *realloc (void *__ptr, size_t __size)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__warn_unused_result__)) __attribute__ ((__alloc_size__ (2)));
extern void free (void *__ptr) __attribute__ ((__nothrow__ , __leaf__));
extern void *reallocarray (void *__ptr, size_t __nmemb, size_t __size)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__warn_unused_result__))
     __attribute__ ((__alloc_size__ (2, 3)))
    __attribute__ ((__malloc__ (__builtin_free, 1)));
extern void *reallocarray (void *__ptr, size_t __nmemb, size_t __size)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__malloc__ (reallocarray, 1)));

extern void *alloca (size_t __size) __attribute__ ((__nothrow__ , __leaf__));

extern void *valloc (size_t __size) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__malloc__))
     __attribute__ ((__alloc_size__ (1))) ;
extern int posix_memalign (void **__memptr, size_t __alignment, size_t __size)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) ;
extern void *aligned_alloc (size_t __alignment, size_t __size)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__malloc__)) __attribute__ ((__alloc_align__ (1)))
     __attribute__ ((__alloc_size__ (2))) ;
extern void abort (void) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__noreturn__));
extern int atexit (void (*__func) (void)) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int at_quick_exit (void (*__func) (void)) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int on_exit (void (*__func) (int __status, void *__arg), void *__arg)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern void exit (int __status) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__noreturn__));
extern void quick_exit (int __status) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__noreturn__));
extern void _Exit (int __status) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__noreturn__));
extern char *getenv (const char *__name) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) ;
extern char *secure_getenv (const char *__name)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) ;
extern int putenv (char *__string) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int setenv (const char *__name, const char *__value, int __replace)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));
extern int unsetenv (const char *__name) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int clearenv (void) __attribute__ ((__nothrow__ , __leaf__));
extern char *mktemp (char *__template) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int mkstemp (char *__template) __attribute__ ((__nonnull__ (1))) ;
extern int mkstemp64 (char *__template) __attribute__ ((__nonnull__ (1))) ;
extern int mkstemps (char *__template, int __suffixlen) __attribute__ ((__nonnull__ (1))) ;
extern int mkstemps64 (char *__template, int __suffixlen)
     __attribute__ ((__nonnull__ (1))) ;
extern char *mkdtemp (char *__template) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) ;
extern int mkostemp (char *__template, int __flags) __attribute__ ((__nonnull__ (1))) ;
extern int mkostemp64 (char *__template, int __flags) __attribute__ ((__nonnull__ (1))) ;
extern int mkostemps (char *__template, int __suffixlen, int __flags)
     __attribute__ ((__nonnull__ (1))) ;
extern int mkostemps64 (char *__template, int __suffixlen, int __flags)
     __attribute__ ((__nonnull__ (1))) ;
extern int system (const char *__command) ;
extern char *canonicalize_file_name (const char *__name)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) __attribute__ ((__malloc__))
     __attribute__ ((__malloc__ (__builtin_free, 1))) ;
extern char *realpath (const char *__restrict __name,
         char *__restrict __resolved) __attribute__ ((__nothrow__ , __leaf__)) ;
typedef int (*__compar_fn_t) (const void *, const void *);
typedef __compar_fn_t comparison_fn_t;
typedef int (*__compar_d_fn_t) (const void *, const void *, void *);
extern void *bsearch (const void *__key, const void *__base,
        size_t __nmemb, size_t __size, __compar_fn_t __compar)
     __attribute__ ((__nonnull__ (1, 2, 5))) ;
extern __inline __attribute__ ((__gnu_inline__)) void *
bsearch (const void *__key, const void *__base, size_t __nmemb, size_t __size,
  __compar_fn_t __compar)
{
  size_t __l, __u, __idx;
  const void *__p;
  int __comparison;
  __l = 0;
  __u = __nmemb;
  while (__l < __u)
    {
      __idx = (__l + __u) / 2;
      __p = (const void *) (((const char *) __base) + (__idx * __size));
      __comparison = (*__compar) (__key, __p);
      if (__comparison < 0)
 __u = __idx;
      else if (__comparison > 0)
 __l = __idx + 1;
      else
 {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wcast-qual"
   return (void *) __p;
#pragma GCC diagnostic pop
 }
    }
  return ((void *)0);
}
extern void qsort (void *__base, size_t __nmemb, size_t __size,
     __compar_fn_t __compar) __attribute__ ((__nonnull__ (1, 4)));
extern void qsort_r (void *__base, size_t __nmemb, size_t __size,
       __compar_d_fn_t __compar, void *__arg)
  __attribute__ ((__nonnull__ (1, 4)));
extern int abs (int __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)) ;
extern long int labs (long int __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)) ;
__extension__ extern long long int llabs (long long int __x)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)) ;
extern div_t div (int __numer, int __denom)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)) ;
extern ldiv_t ldiv (long int __numer, long int __denom)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)) ;
__extension__ extern lldiv_t lldiv (long long int __numer,
        long long int __denom)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)) ;
extern char *ecvt (double __value, int __ndigit, int *__restrict __decpt,
     int *__restrict __sign) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3, 4))) ;
extern char *fcvt (double __value, int __ndigit, int *__restrict __decpt,
     int *__restrict __sign) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3, 4))) ;
extern char *gcvt (double __value, int __ndigit, char *__buf)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3))) ;
extern char *qecvt (long double __value, int __ndigit,
      int *__restrict __decpt, int *__restrict __sign)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3, 4))) ;
extern char *qfcvt (long double __value, int __ndigit,
      int *__restrict __decpt, int *__restrict __sign)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3, 4))) ;
extern char *qgcvt (long double __value, int __ndigit, char *__buf)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3))) ;
extern int ecvt_r (double __value, int __ndigit, int *__restrict __decpt,
     int *__restrict __sign, char *__restrict __buf,
     size_t __len) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3, 4, 5)));
extern int fcvt_r (double __value, int __ndigit, int *__restrict __decpt,
     int *__restrict __sign, char *__restrict __buf,
     size_t __len) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3, 4, 5)));
extern int qecvt_r (long double __value, int __ndigit,
      int *__restrict __decpt, int *__restrict __sign,
      char *__restrict __buf, size_t __len)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3, 4, 5)));
extern int qfcvt_r (long double __value, int __ndigit,
      int *__restrict __decpt, int *__restrict __sign,
      char *__restrict __buf, size_t __len)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3, 4, 5)));
extern int mblen (const char *__s, size_t __n) __attribute__ ((__nothrow__ , __leaf__));
extern int mbtowc (wchar_t *__restrict __pwc,
     const char *__restrict __s, size_t __n) __attribute__ ((__nothrow__ , __leaf__));
extern int wctomb (char *__s, wchar_t __wchar) __attribute__ ((__nothrow__ , __leaf__));
extern size_t mbstowcs (wchar_t *__restrict __pwcs,
   const char *__restrict __s, size_t __n) __attribute__ ((__nothrow__ , __leaf__))
    __attribute__ ((__access__ (__read_only__, 2)));
extern size_t wcstombs (char *__restrict __s,
   const wchar_t *__restrict __pwcs, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__access__ (__write_only__, 1, 3)))
  __attribute__ ((__access__ (__read_only__, 2)));
extern int rpmatch (const char *__response) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) ;
extern int getsubopt (char **__restrict __optionp,
        char *const *__restrict __tokens,
        char **__restrict __valuep)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2, 3))) ;
extern int posix_openpt (int __oflag) ;
extern int grantpt (int __fd) __attribute__ ((__nothrow__ , __leaf__));
extern int unlockpt (int __fd) __attribute__ ((__nothrow__ , __leaf__));
extern char *ptsname (int __fd) __attribute__ ((__nothrow__ , __leaf__)) ;
extern int ptsname_r (int __fd, char *__buf, size_t __buflen)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2))) __attribute__ ((__access__ (__write_only__, 2, 3)));
extern int getpt (void);
extern int getloadavg (double __loadavg[], int __nelem)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern __inline __attribute__ ((__gnu_inline__)) double
__attribute__ ((__nothrow__ , __leaf__)) atof (const char *__nptr)
{
  return strtod (__nptr, (char **) ((void *)0));
}


extern void *memcpy (void *__restrict __dest, const void *__restrict __src,
       size_t __n) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern void *memmove (void *__dest, const void *__src, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern void *memccpy (void *__restrict __dest, const void *__restrict __src,
        int __c, size_t __n)
    __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2))) __attribute__ ((__access__ (__write_only__, 1, 4)));
extern void *memset (void *__s, int __c, size_t __n) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int memcmp (const void *__s1, const void *__s2, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
extern int __memcmpeq (const void *__s1, const void *__s2, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
extern void *memchr (const void *__s, int __c, size_t __n)
      __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));
extern void *rawmemchr (const void *__s, int __c)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));
extern void *memrchr (const void *__s, int __c, size_t __n)
      __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)))
      __attribute__ ((__access__ (__read_only__, 1, 3)));
extern char *strcpy (char *__restrict __dest, const char *__restrict __src)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern char *strncpy (char *__restrict __dest,
        const char *__restrict __src, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern char *strcat (char *__restrict __dest, const char *__restrict __src)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern char *strncat (char *__restrict __dest, const char *__restrict __src,
        size_t __n) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int strcmp (const char *__s1, const char *__s2)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
extern int strncmp (const char *__s1, const char *__s2, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
extern int strcoll (const char *__s1, const char *__s2)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
extern size_t strxfrm (char *__restrict __dest,
         const char *__restrict __src, size_t __n)
    __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2))) __attribute__ ((__access__ (__write_only__, 1, 3)));
extern int strcoll_l (const char *__s1, const char *__s2, locale_t __l)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2, 3)));
extern size_t strxfrm_l (char *__dest, const char *__src, size_t __n,
    locale_t __l) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2, 4)))
     __attribute__ ((__access__ (__write_only__, 1, 3)));
extern char *strdup (const char *__s)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__malloc__)) __attribute__ ((__nonnull__ (1)));
extern char *strndup (const char *__string, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__malloc__)) __attribute__ ((__nonnull__ (1)));
extern char *strchr (const char *__s, int __c)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));
extern char *strrchr (const char *__s, int __c)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));
extern char *strchrnul (const char *__s, int __c)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));
extern size_t strcspn (const char *__s, const char *__reject)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
extern size_t strspn (const char *__s, const char *__accept)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
extern char *strpbrk (const char *__s, const char *__accept)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
extern char *strstr (const char *__haystack, const char *__needle)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
extern char *strtok (char *__restrict __s, const char *__restrict __delim)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));
extern char *__strtok_r (char *__restrict __s,
    const char *__restrict __delim,
    char **__restrict __save_ptr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2, 3)));
extern char *strtok_r (char *__restrict __s, const char *__restrict __delim,
         char **__restrict __save_ptr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2, 3)));
extern char *strcasestr (const char *__haystack, const char *__needle)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
extern void *memmem (const void *__haystack, size_t __haystacklen,
       const void *__needle, size_t __needlelen)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 3)))
    __attribute__ ((__access__ (__read_only__, 1, 2)))
    __attribute__ ((__access__ (__read_only__, 3, 4)));
extern void *__mempcpy (void *__restrict __dest,
   const void *__restrict __src, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern void *mempcpy (void *__restrict __dest,
        const void *__restrict __src, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern size_t strlen (const char *__s)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));
extern size_t strnlen (const char *__string, size_t __maxlen)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));
extern char *strerror (int __errnum) __attribute__ ((__nothrow__ , __leaf__));
extern char *strerror_r (int __errnum, char *__buf, size_t __buflen)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2))) __attribute__ ((__access__ (__write_only__, 2, 3)));
extern const char *strerrordesc_np (int __err) __attribute__ ((__nothrow__ , __leaf__));
extern const char *strerrorname_np (int __err) __attribute__ ((__nothrow__ , __leaf__));
extern char *strerror_l (int __errnum, locale_t __l) __attribute__ ((__nothrow__ , __leaf__));

extern int bcmp (const void *__s1, const void *__s2, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
extern void bcopy (const void *__src, void *__dest, size_t __n)
  __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern void bzero (void *__s, size_t __n) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern char *index (const char *__s, int __c)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));
extern char *rindex (const char *__s, int __c)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));
extern int ffs (int __i) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern int ffsl (long int __l) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
__extension__ extern int ffsll (long long int __ll)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern int strcasecmp (const char *__s1, const char *__s2)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
extern int strncasecmp (const char *__s1, const char *__s2, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
extern int strcasecmp_l (const char *__s1, const char *__s2, locale_t __loc)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2, 3)));
extern int strncasecmp_l (const char *__s1, const char *__s2,
     size_t __n, locale_t __loc)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2, 4)));

extern void explicit_bzero (void *__s, size_t __n) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)))
    __attribute__ ((__access__ (__write_only__, 1, 2)));
extern char *strsep (char **__restrict __stringp,
       const char *__restrict __delim)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern char *strsignal (int __sig) __attribute__ ((__nothrow__ , __leaf__));
extern const char *sigabbrev_np (int __sig) __attribute__ ((__nothrow__ , __leaf__));
extern const char *sigdescr_np (int __sig) __attribute__ ((__nothrow__ , __leaf__));
extern char *__stpcpy (char *__restrict __dest, const char *__restrict __src)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern char *stpcpy (char *__restrict __dest, const char *__restrict __src)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern char *__stpncpy (char *__restrict __dest,
   const char *__restrict __src, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern char *stpncpy (char *__restrict __dest,
        const char *__restrict __src, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int strverscmp (const char *__s1, const char *__s2)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
extern char *strfry (char *__string) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern void *memfrob (void *__s, size_t __n) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)))
    __attribute__ ((__access__ (__read_write__, 1, 2)));
extern char *basename (const char *__filename) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));

struct timex
{
  unsigned int modes;
  __syscall_slong_t offset;
  __syscall_slong_t freq;
  __syscall_slong_t maxerror;
  __syscall_slong_t esterror;
  int status;
  __syscall_slong_t constant;
  __syscall_slong_t precision;
  __syscall_slong_t tolerance;
  struct timeval time;
  __syscall_slong_t tick;
  __syscall_slong_t ppsfreq;
  __syscall_slong_t jitter;
  int shift;
  __syscall_slong_t stabil;
  __syscall_slong_t jitcnt;
  __syscall_slong_t calcnt;
  __syscall_slong_t errcnt;
  __syscall_slong_t stbcnt;
  int tai;
  int :32; int :32; int :32; int :32;
  int :32; int :32; int :32; int :32;
  int :32; int :32; int :32;
};

extern int clock_adjtime (__clockid_t __clock_id, struct timex *__utx) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));

struct tm
{
  int tm_sec;
  int tm_min;
  int tm_hour;
  int tm_mday;
  int tm_mon;
  int tm_year;
  int tm_wday;
  int tm_yday;
  int tm_isdst;
  long int tm_gmtoff;
  const char *tm_zone;
};
struct itimerspec
  {
    struct timespec it_interval;
    struct timespec it_value;
  };
struct sigevent;

extern clock_t clock (void) __attribute__ ((__nothrow__ , __leaf__));
extern time_t time (time_t *__timer) __attribute__ ((__nothrow__ , __leaf__));
extern double difftime (time_t __time1, time_t __time0)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern time_t mktime (struct tm *__tp) __attribute__ ((__nothrow__ , __leaf__));
extern size_t strftime (char *__restrict __s, size_t __maxsize,
   const char *__restrict __format,
   const struct tm *__restrict __tp) __attribute__ ((__nothrow__ , __leaf__));
extern char *strptime (const char *__restrict __s,
         const char *__restrict __fmt, struct tm *__tp)
     __attribute__ ((__nothrow__ , __leaf__));
extern size_t strftime_l (char *__restrict __s, size_t __maxsize,
     const char *__restrict __format,
     const struct tm *__restrict __tp,
     locale_t __loc) __attribute__ ((__nothrow__ , __leaf__));
extern char *strptime_l (const char *__restrict __s,
    const char *__restrict __fmt, struct tm *__tp,
    locale_t __loc) __attribute__ ((__nothrow__ , __leaf__));
extern struct tm *gmtime (const time_t *__timer) __attribute__ ((__nothrow__ , __leaf__));
extern struct tm *localtime (const time_t *__timer) __attribute__ ((__nothrow__ , __leaf__));
extern struct tm *gmtime_r (const time_t *__restrict __timer,
       struct tm *__restrict __tp) __attribute__ ((__nothrow__ , __leaf__));
extern struct tm *localtime_r (const time_t *__restrict __timer,
          struct tm *__restrict __tp) __attribute__ ((__nothrow__ , __leaf__));
extern char *asctime (const struct tm *__tp) __attribute__ ((__nothrow__ , __leaf__));
extern char *ctime (const time_t *__timer) __attribute__ ((__nothrow__ , __leaf__));
extern char *asctime_r (const struct tm *__restrict __tp,
   char *__restrict __buf) __attribute__ ((__nothrow__ , __leaf__));
extern char *ctime_r (const time_t *__restrict __timer,
        char *__restrict __buf) __attribute__ ((__nothrow__ , __leaf__));
extern char *__tzname[2];
extern int __daylight;
extern long int __timezone;
extern char *tzname[2];
extern void tzset (void) __attribute__ ((__nothrow__ , __leaf__));
extern int daylight;
extern long int timezone;
extern time_t timegm (struct tm *__tp) __attribute__ ((__nothrow__ , __leaf__));
extern time_t timelocal (struct tm *__tp) __attribute__ ((__nothrow__ , __leaf__));
extern int dysize (int __year) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern int nanosleep (const struct timespec *__requested_time,
        struct timespec *__remaining);
extern int clock_getres (clockid_t __clock_id, struct timespec *__res) __attribute__ ((__nothrow__ , __leaf__));
extern int clock_gettime (clockid_t __clock_id, struct timespec *__tp)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));
extern int clock_settime (clockid_t __clock_id, const struct timespec *__tp)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));
extern int clock_nanosleep (clockid_t __clock_id, int __flags,
       const struct timespec *__req,
       struct timespec *__rem);
extern int clock_getcpuclockid (pid_t __pid, clockid_t *__clock_id) __attribute__ ((__nothrow__ , __leaf__));
extern int timer_create (clockid_t __clock_id,
    struct sigevent *__restrict __evp,
    timer_t *__restrict __timerid) __attribute__ ((__nothrow__ , __leaf__));
extern int timer_delete (timer_t __timerid) __attribute__ ((__nothrow__ , __leaf__));
extern int timer_settime (timer_t __timerid, int __flags,
     const struct itimerspec *__restrict __value,
     struct itimerspec *__restrict __ovalue) __attribute__ ((__nothrow__ , __leaf__));
extern int timer_gettime (timer_t __timerid, struct itimerspec *__value)
     __attribute__ ((__nothrow__ , __leaf__));
extern int timer_getoverrun (timer_t __timerid) __attribute__ ((__nothrow__ , __leaf__));
extern int timespec_get (struct timespec *__ts, int __base)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int timespec_getres (struct timespec *__ts, int __base)
     __attribute__ ((__nothrow__ , __leaf__));
extern int getdate_err;
extern struct tm *getdate (const char *__string);
extern int getdate_r (const char *__restrict __string,
        struct tm *__restrict __resbufp);


struct flock
  {
    short int l_type;
    short int l_whence;
    __off_t l_start;
    __off_t l_len;
    __pid_t l_pid;
  };
struct flock64
  {
    short int l_type;
    short int l_whence;
    __off64_t l_start;
    __off64_t l_len;
    __pid_t l_pid;
  };
struct iovec
  {
    void *iov_base;
    size_t iov_len;
  };
enum __pid_type
  {
    F_OWNER_TID = 0,
    F_OWNER_PID,
    F_OWNER_PGRP,
    F_OWNER_GID = F_OWNER_PGRP
  };
struct f_owner_ex
  {
    enum __pid_type type;
    __pid_t pid;
  };
struct file_handle
{
  unsigned int handle_bytes;
  int handle_type;
  unsigned char f_handle[0];
};

extern __ssize_t readahead (int __fd, __off64_t __offset, size_t __count)
    __attribute__ ((__nothrow__ , __leaf__));
extern int sync_file_range (int __fd, __off64_t __offset, __off64_t __count,
       unsigned int __flags);
extern __ssize_t vmsplice (int __fdout, const struct iovec *__iov,
      size_t __count, unsigned int __flags);
extern __ssize_t splice (int __fdin, __off64_t *__offin, int __fdout,
    __off64_t *__offout, size_t __len,
    unsigned int __flags);
extern __ssize_t tee (int __fdin, int __fdout, size_t __len,
        unsigned int __flags);
extern int fallocate (int __fd, int __mode, __off_t __offset, __off_t __len);
extern int fallocate64 (int __fd, int __mode, __off64_t __offset,
   __off64_t __len);
extern int name_to_handle_at (int __dfd, const char *__name,
         struct file_handle *__handle, int *__mnt_id,
         int __flags) __attribute__ ((__nothrow__ , __leaf__));
extern int open_by_handle_at (int __mountdirfd, struct file_handle *__handle,
         int __flags);

struct stat
  {
    __dev_t st_dev;
    __ino_t st_ino;
    __mode_t st_mode;
    __nlink_t st_nlink;
    __uid_t st_uid;
    __gid_t st_gid;
    __dev_t st_rdev;
    __dev_t __pad1;
    __off_t st_size;
    __blksize_t st_blksize;
    int __pad2;
    __blkcnt_t st_blocks;
    struct timespec st_atim;
    struct timespec st_mtim;
    struct timespec st_ctim;
    int __glibc_reserved[2];
  };
struct stat64
  {
    __dev_t st_dev;
    __ino64_t st_ino;
    __mode_t st_mode;
    __nlink_t st_nlink;
    __uid_t st_uid;
    __gid_t st_gid;
    __dev_t st_rdev;
    __dev_t __pad1;
    __off64_t st_size;
    __blksize_t st_blksize;
    int __pad2;
    __blkcnt64_t st_blocks;
    struct timespec st_atim;
    struct timespec st_mtim;
    struct timespec st_ctim;
    int __glibc_reserved[2];
  };
extern int fcntl (int __fd, int __cmd, ...);
extern int fcntl64 (int __fd, int __cmd, ...);
extern int open (const char *__file, int __oflag, ...) __attribute__ ((__nonnull__ (1)));
extern int open64 (const char *__file, int __oflag, ...) __attribute__ ((__nonnull__ (1)));
extern int openat (int __fd, const char *__file, int __oflag, ...)
     __attribute__ ((__nonnull__ (2)));
extern int openat64 (int __fd, const char *__file, int __oflag, ...)
     __attribute__ ((__nonnull__ (2)));
extern int creat (const char *__file, mode_t __mode) __attribute__ ((__nonnull__ (1)));
extern int creat64 (const char *__file, mode_t __mode) __attribute__ ((__nonnull__ (1)));
extern int lockf (int __fd, int __cmd, off_t __len);
extern int lockf64 (int __fd, int __cmd, off64_t __len);
extern int posix_fadvise (int __fd, off_t __offset, off_t __len,
     int __advise) __attribute__ ((__nothrow__ , __leaf__));
extern int posix_fadvise64 (int __fd, off64_t __offset, off64_t __len,
       int __advise) __attribute__ ((__nothrow__ , __leaf__));
extern int posix_fallocate (int __fd, off_t __offset, off_t __len);
extern int posix_fallocate64 (int __fd, off64_t __offset, off64_t __len);


typedef float float_t;
typedef double double_t;
enum
  {
    FP_INT_UPWARD =
      0,
    FP_INT_DOWNWARD =
      1,
    FP_INT_TOWARDZERO =
      2,
    FP_INT_TONEARESTFROMZERO =
      3,
    FP_INT_TONEAREST =
      4,
  };
extern int __fpclassify (double __value) __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__const__));
extern int __signbit (double __value) __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__const__));
extern int __isinf (double __value) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__const__));
extern int __finite (double __value) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__const__));
extern int __isnan (double __value) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__const__));
extern int __iseqsig (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__));
extern int __issignaling (double __value) __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__const__));
 extern double acos (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __acos (double __x) __attribute__ ((__nothrow__ , __leaf__));
 extern double asin (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __asin (double __x) __attribute__ ((__nothrow__ , __leaf__));
 extern double atan (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __atan (double __x) __attribute__ ((__nothrow__ , __leaf__));
 extern double atan2 (double __y, double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __atan2 (double __y, double __x) __attribute__ ((__nothrow__ , __leaf__));
 extern double cos (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __cos (double __x) __attribute__ ((__nothrow__ , __leaf__));
 extern double sin (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __sin (double __x) __attribute__ ((__nothrow__ , __leaf__));
 extern double tan (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __tan (double __x) __attribute__ ((__nothrow__ , __leaf__));
 extern double cosh (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __cosh (double __x) __attribute__ ((__nothrow__ , __leaf__));
 extern double sinh (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __sinh (double __x) __attribute__ ((__nothrow__ , __leaf__));
 extern double tanh (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __tanh (double __x) __attribute__ ((__nothrow__ , __leaf__));
 extern void sincos (double __x, double *__sinx, double *__cosx) __attribute__ ((__nothrow__ , __leaf__)); extern void __sincos (double __x, double *__sinx, double *__cosx) __attribute__ ((__nothrow__ , __leaf__));
 extern double acosh (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __acosh (double __x) __attribute__ ((__nothrow__ , __leaf__));
 extern double asinh (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __asinh (double __x) __attribute__ ((__nothrow__ , __leaf__));
 extern double atanh (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __atanh (double __x) __attribute__ ((__nothrow__ , __leaf__));
 extern double exp (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __exp (double __x) __attribute__ ((__nothrow__ , __leaf__));
extern double frexp (double __x, int *__exponent) __attribute__ ((__nothrow__ , __leaf__)); extern double __frexp (double __x, int *__exponent) __attribute__ ((__nothrow__ , __leaf__));
extern double ldexp (double __x, int __exponent) __attribute__ ((__nothrow__ , __leaf__)); extern double __ldexp (double __x, int __exponent) __attribute__ ((__nothrow__ , __leaf__));
 extern double log (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __log (double __x) __attribute__ ((__nothrow__ , __leaf__));
 extern double log10 (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __log10 (double __x) __attribute__ ((__nothrow__ , __leaf__));
extern double modf (double __x, double *__iptr) __attribute__ ((__nothrow__ , __leaf__)); extern double __modf (double __x, double *__iptr) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));
 extern double exp10 (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __exp10 (double __x) __attribute__ ((__nothrow__ , __leaf__));
 extern double expm1 (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __expm1 (double __x) __attribute__ ((__nothrow__ , __leaf__));
 extern double log1p (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __log1p (double __x) __attribute__ ((__nothrow__ , __leaf__));
extern double logb (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __logb (double __x) __attribute__ ((__nothrow__ , __leaf__));
 extern double exp2 (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __exp2 (double __x) __attribute__ ((__nothrow__ , __leaf__));
 extern double log2 (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __log2 (double __x) __attribute__ ((__nothrow__ , __leaf__));
 extern double pow (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)); extern double __pow (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__));
extern double sqrt (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __sqrt (double __x) __attribute__ ((__nothrow__ , __leaf__));
 extern double hypot (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)); extern double __hypot (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__));
 extern double cbrt (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __cbrt (double __x) __attribute__ ((__nothrow__ , __leaf__));
extern double ceil (double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern double __ceil (double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern double fabs (double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern double __fabs (double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern double floor (double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern double __floor (double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern double fmod (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)); extern double __fmod (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__));
extern int isinf (double __value) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__const__));
extern int finite (double __value) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__const__));
extern double drem (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)); extern double __drem (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__));
extern double significand (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __significand (double __x) __attribute__ ((__nothrow__ , __leaf__));
extern double copysign (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern double __copysign (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern double nan (const char *__tagb) __attribute__ ((__nothrow__ , __leaf__)); extern double __nan (const char *__tagb) __attribute__ ((__nothrow__ , __leaf__));
extern int isnan (double __value) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__const__));
extern double j0 (double) __attribute__ ((__nothrow__ , __leaf__)); extern double __j0 (double) __attribute__ ((__nothrow__ , __leaf__));
extern double j1 (double) __attribute__ ((__nothrow__ , __leaf__)); extern double __j1 (double) __attribute__ ((__nothrow__ , __leaf__));
extern double jn (int, double) __attribute__ ((__nothrow__ , __leaf__)); extern double __jn (int, double) __attribute__ ((__nothrow__ , __leaf__));
extern double y0 (double) __attribute__ ((__nothrow__ , __leaf__)); extern double __y0 (double) __attribute__ ((__nothrow__ , __leaf__));
extern double y1 (double) __attribute__ ((__nothrow__ , __leaf__)); extern double __y1 (double) __attribute__ ((__nothrow__ , __leaf__));
extern double yn (int, double) __attribute__ ((__nothrow__ , __leaf__)); extern double __yn (int, double) __attribute__ ((__nothrow__ , __leaf__));
 extern double erf (double) __attribute__ ((__nothrow__ , __leaf__)); extern double __erf (double) __attribute__ ((__nothrow__ , __leaf__));
 extern double erfc (double) __attribute__ ((__nothrow__ , __leaf__)); extern double __erfc (double) __attribute__ ((__nothrow__ , __leaf__));
extern double lgamma (double) __attribute__ ((__nothrow__ , __leaf__)); extern double __lgamma (double) __attribute__ ((__nothrow__ , __leaf__));
extern double tgamma (double) __attribute__ ((__nothrow__ , __leaf__)); extern double __tgamma (double) __attribute__ ((__nothrow__ , __leaf__));
extern double gamma (double) __attribute__ ((__nothrow__ , __leaf__)); extern double __gamma (double) __attribute__ ((__nothrow__ , __leaf__));
extern double lgamma_r (double, int *__signgamp) __attribute__ ((__nothrow__ , __leaf__)); extern double __lgamma_r (double, int *__signgamp) __attribute__ ((__nothrow__ , __leaf__));
extern double rint (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __rint (double __x) __attribute__ ((__nothrow__ , __leaf__));
extern double nextafter (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)); extern double __nextafter (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__));
extern double nexttoward (double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)); extern double __nexttoward (double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__));
extern double nextdown (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __nextdown (double __x) __attribute__ ((__nothrow__ , __leaf__));
extern double nextup (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __nextup (double __x) __attribute__ ((__nothrow__ , __leaf__));
extern double remainder (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)); extern double __remainder (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__));
extern double scalbn (double __x, int __n) __attribute__ ((__nothrow__ , __leaf__)); extern double __scalbn (double __x, int __n) __attribute__ ((__nothrow__ , __leaf__));
extern int ilogb (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern int __ilogb (double __x) __attribute__ ((__nothrow__ , __leaf__));
extern long int llogb (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long int __llogb (double __x) __attribute__ ((__nothrow__ , __leaf__));
extern double scalbln (double __x, long int __n) __attribute__ ((__nothrow__ , __leaf__)); extern double __scalbln (double __x, long int __n) __attribute__ ((__nothrow__ , __leaf__));
extern double nearbyint (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __nearbyint (double __x) __attribute__ ((__nothrow__ , __leaf__));
extern double round (double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern double __round (double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern double trunc (double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern double __trunc (double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern double remquo (double __x, double __y, int *__quo) __attribute__ ((__nothrow__ , __leaf__)); extern double __remquo (double __x, double __y, int *__quo) __attribute__ ((__nothrow__ , __leaf__));
extern long int lrint (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long int __lrint (double __x) __attribute__ ((__nothrow__ , __leaf__));
__extension__
extern long long int llrint (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long long int __llrint (double __x) __attribute__ ((__nothrow__ , __leaf__));
extern long int lround (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long int __lround (double __x) __attribute__ ((__nothrow__ , __leaf__));
__extension__
extern long long int llround (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long long int __llround (double __x) __attribute__ ((__nothrow__ , __leaf__));
extern double fdim (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)); extern double __fdim (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__));
extern double fmax (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern double __fmax (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern double fmin (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern double __fmin (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern double fma (double __x, double __y, double __z) __attribute__ ((__nothrow__ , __leaf__)); extern double __fma (double __x, double __y, double __z) __attribute__ ((__nothrow__ , __leaf__));
extern double roundeven (double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern double __roundeven (double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern __intmax_t fromfp (double __x, int __round, unsigned int __width) __attribute__ ((__nothrow__ , __leaf__)); extern __intmax_t __fromfp (double __x, int __round, unsigned int __width) __attribute__ ((__nothrow__ , __leaf__));
extern __uintmax_t ufromfp (double __x, int __round, unsigned int __width) __attribute__ ((__nothrow__ , __leaf__)); extern __uintmax_t __ufromfp (double __x, int __round, unsigned int __width) __attribute__ ((__nothrow__ , __leaf__));
extern __intmax_t fromfpx (double __x, int __round, unsigned int __width) __attribute__ ((__nothrow__ , __leaf__)); extern __intmax_t __fromfpx (double __x, int __round, unsigned int __width) __attribute__ ((__nothrow__ , __leaf__));
extern __uintmax_t ufromfpx (double __x, int __round, unsigned int __width) __attribute__ ((__nothrow__ , __leaf__)); extern __uintmax_t __ufromfpx (double __x, int __round, unsigned int __width) __attribute__ ((__nothrow__ , __leaf__));
extern int canonicalize (double *__cx, const double *__x) __attribute__ ((__nothrow__ , __leaf__));
extern double fmaxmag (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern double __fmaxmag (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern double fminmag (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern double __fminmag (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern double fmaximum (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern double __fmaximum (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern double fminimum (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern double __fminimum (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern double fmaximum_num (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern double __fmaximum_num (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern double fminimum_num (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern double __fminimum_num (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern double fmaximum_mag (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern double __fmaximum_mag (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern double fminimum_mag (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern double __fminimum_mag (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern double fmaximum_mag_num (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern double __fmaximum_mag_num (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern double fminimum_mag_num (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern double __fminimum_mag_num (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern int totalorder (const double *__x, const double *__y) __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__pure__));
extern int totalordermag (const double *__x, const double *__y) __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__pure__));
extern double getpayload (const double *__x) __attribute__ ((__nothrow__ , __leaf__)); extern double __getpayload (const double *__x) __attribute__ ((__nothrow__ , __leaf__));
extern int setpayload (double *__x, double __payload) __attribute__ ((__nothrow__ , __leaf__));
extern int setpayloadsig (double *__x, double __payload) __attribute__ ((__nothrow__ , __leaf__));
extern double scalb (double __x, double __n) __attribute__ ((__nothrow__ , __leaf__)); extern double __scalb (double __x, double __n) __attribute__ ((__nothrow__ , __leaf__));
extern int __fpclassifyf (float __value) __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__const__));
extern int __signbitf (float __value) __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__const__));
extern int __isinff (float __value) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__const__));
extern int __finitef (float __value) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__const__));
extern int __isnanf (float __value) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__const__));
extern int __iseqsigf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__));
extern int __issignalingf (float __value) __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__const__));
 extern float acosf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __acosf (float __x) __attribute__ ((__nothrow__ , __leaf__));
 extern float asinf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __asinf (float __x) __attribute__ ((__nothrow__ , __leaf__));
 extern float atanf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __atanf (float __x) __attribute__ ((__nothrow__ , __leaf__));
 extern float atan2f (float __y, float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __atan2f (float __y, float __x) __attribute__ ((__nothrow__ , __leaf__));
 extern float cosf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __cosf (float __x) __attribute__ ((__nothrow__ , __leaf__));
 extern float sinf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __sinf (float __x) __attribute__ ((__nothrow__ , __leaf__));
 extern float tanf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __tanf (float __x) __attribute__ ((__nothrow__ , __leaf__));
 extern float coshf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __coshf (float __x) __attribute__ ((__nothrow__ , __leaf__));
 extern float sinhf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __sinhf (float __x) __attribute__ ((__nothrow__ , __leaf__));
 extern float tanhf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __tanhf (float __x) __attribute__ ((__nothrow__ , __leaf__));
 extern void sincosf (float __x, float *__sinx, float *__cosx) __attribute__ ((__nothrow__ , __leaf__)); extern void __sincosf (float __x, float *__sinx, float *__cosx) __attribute__ ((__nothrow__ , __leaf__));
 extern float acoshf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __acoshf (float __x) __attribute__ ((__nothrow__ , __leaf__));
 extern float asinhf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __asinhf (float __x) __attribute__ ((__nothrow__ , __leaf__));
 extern float atanhf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __atanhf (float __x) __attribute__ ((__nothrow__ , __leaf__));
 extern float expf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __expf (float __x) __attribute__ ((__nothrow__ , __leaf__));
extern float frexpf (float __x, int *__exponent) __attribute__ ((__nothrow__ , __leaf__)); extern float __frexpf (float __x, int *__exponent) __attribute__ ((__nothrow__ , __leaf__));
extern float ldexpf (float __x, int __exponent) __attribute__ ((__nothrow__ , __leaf__)); extern float __ldexpf (float __x, int __exponent) __attribute__ ((__nothrow__ , __leaf__));
 extern float logf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __logf (float __x) __attribute__ ((__nothrow__ , __leaf__));
 extern float log10f (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __log10f (float __x) __attribute__ ((__nothrow__ , __leaf__));
extern float modff (float __x, float *__iptr) __attribute__ ((__nothrow__ , __leaf__)); extern float __modff (float __x, float *__iptr) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));
 extern float exp10f (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __exp10f (float __x) __attribute__ ((__nothrow__ , __leaf__));
 extern float expm1f (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __expm1f (float __x) __attribute__ ((__nothrow__ , __leaf__));
 extern float log1pf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __log1pf (float __x) __attribute__ ((__nothrow__ , __leaf__));
extern float logbf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __logbf (float __x) __attribute__ ((__nothrow__ , __leaf__));
 extern float exp2f (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __exp2f (float __x) __attribute__ ((__nothrow__ , __leaf__));
 extern float log2f (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __log2f (float __x) __attribute__ ((__nothrow__ , __leaf__));
 extern float powf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)); extern float __powf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__));
extern float sqrtf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __sqrtf (float __x) __attribute__ ((__nothrow__ , __leaf__));
 extern float hypotf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)); extern float __hypotf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__));
 extern float cbrtf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __cbrtf (float __x) __attribute__ ((__nothrow__ , __leaf__));
extern float ceilf (float __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern float __ceilf (float __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern float fabsf (float __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern float __fabsf (float __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern float floorf (float __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern float __floorf (float __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern float fmodf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)); extern float __fmodf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__));
extern int isinff (float __value) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__const__));
extern int finitef (float __value) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__const__));
extern float dremf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)); extern float __dremf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__));
extern float significandf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __significandf (float __x) __attribute__ ((__nothrow__ , __leaf__));
extern float copysignf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern float __copysignf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern float nanf (const char *__tagb) __attribute__ ((__nothrow__ , __leaf__)); extern float __nanf (const char *__tagb) __attribute__ ((__nothrow__ , __leaf__));
extern int isnanf (float __value) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__const__));
extern float j0f (float) __attribute__ ((__nothrow__ , __leaf__)); extern float __j0f (float) __attribute__ ((__nothrow__ , __leaf__));
extern float j1f (float) __attribute__ ((__nothrow__ , __leaf__)); extern float __j1f (float) __attribute__ ((__nothrow__ , __leaf__));
extern float jnf (int, float) __attribute__ ((__nothrow__ , __leaf__)); extern float __jnf (int, float) __attribute__ ((__nothrow__ , __leaf__));
extern float y0f (float) __attribute__ ((__nothrow__ , __leaf__)); extern float __y0f (float) __attribute__ ((__nothrow__ , __leaf__));
extern float y1f (float) __attribute__ ((__nothrow__ , __leaf__)); extern float __y1f (float) __attribute__ ((__nothrow__ , __leaf__));
extern float ynf (int, float) __attribute__ ((__nothrow__ , __leaf__)); extern float __ynf (int, float) __attribute__ ((__nothrow__ , __leaf__));
 extern float erff (float) __attribute__ ((__nothrow__ , __leaf__)); extern float __erff (float) __attribute__ ((__nothrow__ , __leaf__));
 extern float erfcf (float) __attribute__ ((__nothrow__ , __leaf__)); extern float __erfcf (float) __attribute__ ((__nothrow__ , __leaf__));
extern float lgammaf (float) __attribute__ ((__nothrow__ , __leaf__)); extern float __lgammaf (float) __attribute__ ((__nothrow__ , __leaf__));
extern float tgammaf (float) __attribute__ ((__nothrow__ , __leaf__)); extern float __tgammaf (float) __attribute__ ((__nothrow__ , __leaf__));
extern float gammaf (float) __attribute__ ((__nothrow__ , __leaf__)); extern float __gammaf (float) __attribute__ ((__nothrow__ , __leaf__));
extern float lgammaf_r (float, int *__signgamp) __attribute__ ((__nothrow__ , __leaf__)); extern float __lgammaf_r (float, int *__signgamp) __attribute__ ((__nothrow__ , __leaf__));
extern float rintf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __rintf (float __x) __attribute__ ((__nothrow__ , __leaf__));
extern float nextafterf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)); extern float __nextafterf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__));
extern float nexttowardf (float __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)); extern float __nexttowardf (float __x, long double __y) __attribute__ ((__nothrow__ , __leaf__));
extern float nextdownf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __nextdownf (float __x) __attribute__ ((__nothrow__ , __leaf__));
extern float nextupf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __nextupf (float __x) __attribute__ ((__nothrow__ , __leaf__));
extern float remainderf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)); extern float __remainderf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__));
extern float scalbnf (float __x, int __n) __attribute__ ((__nothrow__ , __leaf__)); extern float __scalbnf (float __x, int __n) __attribute__ ((__nothrow__ , __leaf__));
extern int ilogbf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern int __ilogbf (float __x) __attribute__ ((__nothrow__ , __leaf__));
extern long int llogbf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern long int __llogbf (float __x) __attribute__ ((__nothrow__ , __leaf__));
extern float scalblnf (float __x, long int __n) __attribute__ ((__nothrow__ , __leaf__)); extern float __scalblnf (float __x, long int __n) __attribute__ ((__nothrow__ , __leaf__));
extern float nearbyintf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __nearbyintf (float __x) __attribute__ ((__nothrow__ , __leaf__));
extern float roundf (float __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern float __roundf (float __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern float truncf (float __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern float __truncf (float __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern float remquof (float __x, float __y, int *__quo) __attribute__ ((__nothrow__ , __leaf__)); extern float __remquof (float __x, float __y, int *__quo) __attribute__ ((__nothrow__ , __leaf__));
extern long int lrintf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern long int __lrintf (float __x) __attribute__ ((__nothrow__ , __leaf__));
__extension__
extern long long int llrintf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern long long int __llrintf (float __x) __attribute__ ((__nothrow__ , __leaf__));
extern long int lroundf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern long int __lroundf (float __x) __attribute__ ((__nothrow__ , __leaf__));
__extension__
extern long long int llroundf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern long long int __llroundf (float __x) __attribute__ ((__nothrow__ , __leaf__));
extern float fdimf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)); extern float __fdimf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__));
extern float fmaxf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern float __fmaxf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern float fminf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern float __fminf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern float fmaf (float __x, float __y, float __z) __attribute__ ((__nothrow__ , __leaf__)); extern float __fmaf (float __x, float __y, float __z) __attribute__ ((__nothrow__ , __leaf__));
extern float roundevenf (float __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern float __roundevenf (float __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern __intmax_t fromfpf (float __x, int __round, unsigned int __width) __attribute__ ((__nothrow__ , __leaf__)); extern __intmax_t __fromfpf (float __x, int __round, unsigned int __width) __attribute__ ((__nothrow__ , __leaf__));
extern __uintmax_t ufromfpf (float __x, int __round, unsigned int __width) __attribute__ ((__nothrow__ , __leaf__)); extern __uintmax_t __ufromfpf (float __x, int __round, unsigned int __width) __attribute__ ((__nothrow__ , __leaf__));
extern __intmax_t fromfpxf (float __x, int __round, unsigned int __width) __attribute__ ((__nothrow__ , __leaf__)); extern __intmax_t __fromfpxf (float __x, int __round, unsigned int __width) __attribute__ ((__nothrow__ , __leaf__));
extern __uintmax_t ufromfpxf (float __x, int __round, unsigned int __width) __attribute__ ((__nothrow__ , __leaf__)); extern __uintmax_t __ufromfpxf (float __x, int __round, unsigned int __width) __attribute__ ((__nothrow__ , __leaf__));
extern int canonicalizef (float *__cx, const float *__x) __attribute__ ((__nothrow__ , __leaf__));
extern float fmaxmagf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern float __fmaxmagf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern float fminmagf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern float __fminmagf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern float fmaximumf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern float __fmaximumf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern float fminimumf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern float __fminimumf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern float fmaximum_numf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern float __fmaximum_numf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern float fminimum_numf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern float __fminimum_numf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern float fmaximum_magf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern float __fmaximum_magf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern float fminimum_magf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern float __fminimum_magf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern float fmaximum_mag_numf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern float __fmaximum_mag_numf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern float fminimum_mag_numf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern float __fminimum_mag_numf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern int totalorderf (const float *__x, const float *__y) __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__pure__));
extern int totalordermagf (const float *__x, const float *__y) __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__pure__));
extern float getpayloadf (const float *__x) __attribute__ ((__nothrow__ , __leaf__)); extern float __getpayloadf (const float *__x) __attribute__ ((__nothrow__ , __leaf__));
extern int setpayloadf (float *__x, float __payload) __attribute__ ((__nothrow__ , __leaf__));
extern int setpayloadsigf (float *__x, float __payload) __attribute__ ((__nothrow__ , __leaf__));
extern float scalbf (float __x, float __n) __attribute__ ((__nothrow__ , __leaf__)); extern float __scalbf (float __x, float __n) __attribute__ ((__nothrow__ , __leaf__));
extern int __fpclassifyl (long double __value) __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__const__));
extern int __signbitl (long double __value) __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__const__));
extern int __isinfl (long double __value) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__const__));
extern int __finitel (long double __value) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__const__));
extern int __isnanl (long double __value) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__const__));
extern int __iseqsigl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__));
extern int __issignalingl (long double __value) __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__const__));
 extern long double acosl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __acosl (long double __x) __attribute__ ((__nothrow__ , __leaf__));
 extern long double asinl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __asinl (long double __x) __attribute__ ((__nothrow__ , __leaf__));
 extern long double atanl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __atanl (long double __x) __attribute__ ((__nothrow__ , __leaf__));
 extern long double atan2l (long double __y, long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __atan2l (long double __y, long double __x) __attribute__ ((__nothrow__ , __leaf__));
 extern long double cosl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __cosl (long double __x) __attribute__ ((__nothrow__ , __leaf__));
 extern long double sinl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __sinl (long double __x) __attribute__ ((__nothrow__ , __leaf__));
 extern long double tanl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __tanl (long double __x) __attribute__ ((__nothrow__ , __leaf__));
 extern long double coshl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __coshl (long double __x) __attribute__ ((__nothrow__ , __leaf__));
 extern long double sinhl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __sinhl (long double __x) __attribute__ ((__nothrow__ , __leaf__));
 extern long double tanhl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __tanhl (long double __x) __attribute__ ((__nothrow__ , __leaf__));
 extern void sincosl (long double __x, long double *__sinx, long double *__cosx) __attribute__ ((__nothrow__ , __leaf__)); extern void __sincosl (long double __x, long double *__sinx, long double *__cosx) __attribute__ ((__nothrow__ , __leaf__));
 extern long double acoshl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __acoshl (long double __x) __attribute__ ((__nothrow__ , __leaf__));
 extern long double asinhl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __asinhl (long double __x) __attribute__ ((__nothrow__ , __leaf__));
 extern long double atanhl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __atanhl (long double __x) __attribute__ ((__nothrow__ , __leaf__));
 extern long double expl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __expl (long double __x) __attribute__ ((__nothrow__ , __leaf__));
extern long double frexpl (long double __x, int *__exponent) __attribute__ ((__nothrow__ , __leaf__)); extern long double __frexpl (long double __x, int *__exponent) __attribute__ ((__nothrow__ , __leaf__));
extern long double ldexpl (long double __x, int __exponent) __attribute__ ((__nothrow__ , __leaf__)); extern long double __ldexpl (long double __x, int __exponent) __attribute__ ((__nothrow__ , __leaf__));
 extern long double logl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __logl (long double __x) __attribute__ ((__nothrow__ , __leaf__));
 extern long double log10l (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __log10l (long double __x) __attribute__ ((__nothrow__ , __leaf__));
extern long double modfl (long double __x, long double *__iptr) __attribute__ ((__nothrow__ , __leaf__)); extern long double __modfl (long double __x, long double *__iptr) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));
 extern long double exp10l (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __exp10l (long double __x) __attribute__ ((__nothrow__ , __leaf__));
 extern long double expm1l (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __expm1l (long double __x) __attribute__ ((__nothrow__ , __leaf__));
 extern long double log1pl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __log1pl (long double __x) __attribute__ ((__nothrow__ , __leaf__));
extern long double logbl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __logbl (long double __x) __attribute__ ((__nothrow__ , __leaf__));
 extern long double exp2l (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __exp2l (long double __x) __attribute__ ((__nothrow__ , __leaf__));
 extern long double log2l (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __log2l (long double __x) __attribute__ ((__nothrow__ , __leaf__));
 extern long double powl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)); extern long double __powl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__));
extern long double sqrtl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __sqrtl (long double __x) __attribute__ ((__nothrow__ , __leaf__));
 extern long double hypotl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)); extern long double __hypotl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__));
 extern long double cbrtl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __cbrtl (long double __x) __attribute__ ((__nothrow__ , __leaf__));
extern long double ceill (long double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern long double __ceill (long double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern long double fabsl (long double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern long double __fabsl (long double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern long double floorl (long double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern long double __floorl (long double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern long double fmodl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)); extern long double __fmodl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__));
extern int isinfl (long double __value) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__const__));
extern int finitel (long double __value) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__const__));
extern long double dreml (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)); extern long double __dreml (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__));
extern long double significandl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __significandl (long double __x) __attribute__ ((__nothrow__ , __leaf__));
extern long double copysignl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern long double __copysignl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern long double nanl (const char *__tagb) __attribute__ ((__nothrow__ , __leaf__)); extern long double __nanl (const char *__tagb) __attribute__ ((__nothrow__ , __leaf__));
extern int isnanl (long double __value) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__const__));
extern long double j0l (long double) __attribute__ ((__nothrow__ , __leaf__)); extern long double __j0l (long double) __attribute__ ((__nothrow__ , __leaf__));
extern long double j1l (long double) __attribute__ ((__nothrow__ , __leaf__)); extern long double __j1l (long double) __attribute__ ((__nothrow__ , __leaf__));
extern long double jnl (int, long double) __attribute__ ((__nothrow__ , __leaf__)); extern long double __jnl (int, long double) __attribute__ ((__nothrow__ , __leaf__));
extern long double y0l (long double) __attribute__ ((__nothrow__ , __leaf__)); extern long double __y0l (long double) __attribute__ ((__nothrow__ , __leaf__));
extern long double y1l (long double) __attribute__ ((__nothrow__ , __leaf__)); extern long double __y1l (long double) __attribute__ ((__nothrow__ , __leaf__));
extern long double ynl (int, long double) __attribute__ ((__nothrow__ , __leaf__)); extern long double __ynl (int, long double) __attribute__ ((__nothrow__ , __leaf__));
 extern long double erfl (long double) __attribute__ ((__nothrow__ , __leaf__)); extern long double __erfl (long double) __attribute__ ((__nothrow__ , __leaf__));
 extern long double erfcl (long double) __attribute__ ((__nothrow__ , __leaf__)); extern long double __erfcl (long double) __attribute__ ((__nothrow__ , __leaf__));
extern long double lgammal (long double) __attribute__ ((__nothrow__ , __leaf__)); extern long double __lgammal (long double) __attribute__ ((__nothrow__ , __leaf__));
extern long double tgammal (long double) __attribute__ ((__nothrow__ , __leaf__)); extern long double __tgammal (long double) __attribute__ ((__nothrow__ , __leaf__));
extern long double gammal (long double) __attribute__ ((__nothrow__ , __leaf__)); extern long double __gammal (long double) __attribute__ ((__nothrow__ , __leaf__));
extern long double lgammal_r (long double, int *__signgamp) __attribute__ ((__nothrow__ , __leaf__)); extern long double __lgammal_r (long double, int *__signgamp) __attribute__ ((__nothrow__ , __leaf__));
extern long double rintl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __rintl (long double __x) __attribute__ ((__nothrow__ , __leaf__));
extern long double nextafterl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)); extern long double __nextafterl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__));
extern long double nexttowardl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)); extern long double __nexttowardl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__));
extern long double nextdownl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __nextdownl (long double __x) __attribute__ ((__nothrow__ , __leaf__));
extern long double nextupl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __nextupl (long double __x) __attribute__ ((__nothrow__ , __leaf__));
extern long double remainderl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)); extern long double __remainderl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__));
extern long double scalbnl (long double __x, int __n) __attribute__ ((__nothrow__ , __leaf__)); extern long double __scalbnl (long double __x, int __n) __attribute__ ((__nothrow__ , __leaf__));
extern int ilogbl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern int __ilogbl (long double __x) __attribute__ ((__nothrow__ , __leaf__));
extern long int llogbl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long int __llogbl (long double __x) __attribute__ ((__nothrow__ , __leaf__));
extern long double scalblnl (long double __x, long int __n) __attribute__ ((__nothrow__ , __leaf__)); extern long double __scalblnl (long double __x, long int __n) __attribute__ ((__nothrow__ , __leaf__));
extern long double nearbyintl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __nearbyintl (long double __x) __attribute__ ((__nothrow__ , __leaf__));
extern long double roundl (long double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern long double __roundl (long double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern long double truncl (long double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern long double __truncl (long double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern long double remquol (long double __x, long double __y, int *__quo) __attribute__ ((__nothrow__ , __leaf__)); extern long double __remquol (long double __x, long double __y, int *__quo) __attribute__ ((__nothrow__ , __leaf__));
extern long int lrintl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long int __lrintl (long double __x) __attribute__ ((__nothrow__ , __leaf__));
__extension__
extern long long int llrintl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long long int __llrintl (long double __x) __attribute__ ((__nothrow__ , __leaf__));
extern long int lroundl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long int __lroundl (long double __x) __attribute__ ((__nothrow__ , __leaf__));
__extension__
extern long long int llroundl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long long int __llroundl (long double __x) __attribute__ ((__nothrow__ , __leaf__));
extern long double fdiml (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)); extern long double __fdiml (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__));
extern long double fmaxl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern long double __fmaxl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern long double fminl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern long double __fminl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern long double fmal (long double __x, long double __y, long double __z) __attribute__ ((__nothrow__ , __leaf__)); extern long double __fmal (long double __x, long double __y, long double __z) __attribute__ ((__nothrow__ , __leaf__));
extern long double roundevenl (long double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern long double __roundevenl (long double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern __intmax_t fromfpl (long double __x, int __round, unsigned int __width) __attribute__ ((__nothrow__ , __leaf__)); extern __intmax_t __fromfpl (long double __x, int __round, unsigned int __width) __attribute__ ((__nothrow__ , __leaf__));
extern __uintmax_t ufromfpl (long double __x, int __round, unsigned int __width) __attribute__ ((__nothrow__ , __leaf__)); extern __uintmax_t __ufromfpl (long double __x, int __round, unsigned int __width) __attribute__ ((__nothrow__ , __leaf__));
extern __intmax_t fromfpxl (long double __x, int __round, unsigned int __width) __attribute__ ((__nothrow__ , __leaf__)); extern __intmax_t __fromfpxl (long double __x, int __round, unsigned int __width) __attribute__ ((__nothrow__ , __leaf__));
extern __uintmax_t ufromfpxl (long double __x, int __round, unsigned int __width) __attribute__ ((__nothrow__ , __leaf__)); extern __uintmax_t __ufromfpxl (long double __x, int __round, unsigned int __width) __attribute__ ((__nothrow__ , __leaf__));
extern int canonicalizel (long double *__cx, const long double *__x) __attribute__ ((__nothrow__ , __leaf__));
extern long double fmaxmagl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern long double __fmaxmagl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern long double fminmagl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern long double __fminmagl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern long double fmaximuml (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern long double __fmaximuml (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern long double fminimuml (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern long double __fminimuml (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern long double fmaximum_numl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern long double __fmaximum_numl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern long double fminimum_numl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern long double __fminimum_numl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern long double fmaximum_magl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern long double __fmaximum_magl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern long double fminimum_magl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern long double __fminimum_magl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern long double fmaximum_mag_numl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern long double __fmaximum_mag_numl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern long double fminimum_mag_numl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern long double __fminimum_mag_numl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern int totalorderl (const long double *__x, const long double *__y) __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__pure__));
extern int totalordermagl (const long double *__x, const long double *__y) __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__pure__));
extern long double getpayloadl (const long double *__x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __getpayloadl (const long double *__x) __attribute__ ((__nothrow__ , __leaf__));
extern int setpayloadl (long double *__x, long double __payload) __attribute__ ((__nothrow__ , __leaf__));
extern int setpayloadsigl (long double *__x, long double __payload) __attribute__ ((__nothrow__ , __leaf__));
extern long double scalbl (long double __x, long double __n) __attribute__ ((__nothrow__ , __leaf__)); extern long double __scalbl (long double __x, long double __n) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float32 acosf32 (_Float32 __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32 __acosf32 (_Float32 __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float32 asinf32 (_Float32 __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32 __asinf32 (_Float32 __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float32 atanf32 (_Float32 __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32 __atanf32 (_Float32 __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float32 atan2f32 (_Float32 __y, _Float32 __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32 __atan2f32 (_Float32 __y, _Float32 __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float32 cosf32 (_Float32 __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32 __cosf32 (_Float32 __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float32 sinf32 (_Float32 __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32 __sinf32 (_Float32 __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float32 tanf32 (_Float32 __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32 __tanf32 (_Float32 __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float32 coshf32 (_Float32 __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32 __coshf32 (_Float32 __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float32 sinhf32 (_Float32 __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32 __sinhf32 (_Float32 __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float32 tanhf32 (_Float32 __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32 __tanhf32 (_Float32 __x) __attribute__ ((__nothrow__ , __leaf__));
 extern void sincosf32 (_Float32 __x, _Float32 *__sinx, _Float32 *__cosx) __attribute__ ((__nothrow__ , __leaf__)); extern void __sincosf32 (_Float32 __x, _Float32 *__sinx, _Float32 *__cosx) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float32 acoshf32 (_Float32 __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32 __acoshf32 (_Float32 __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float32 asinhf32 (_Float32 __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32 __asinhf32 (_Float32 __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float32 atanhf32 (_Float32 __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32 __atanhf32 (_Float32 __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float32 expf32 (_Float32 __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32 __expf32 (_Float32 __x) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32 frexpf32 (_Float32 __x, int *__exponent) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32 __frexpf32 (_Float32 __x, int *__exponent) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32 ldexpf32 (_Float32 __x, int __exponent) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32 __ldexpf32 (_Float32 __x, int __exponent) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float32 logf32 (_Float32 __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32 __logf32 (_Float32 __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float32 log10f32 (_Float32 __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32 __log10f32 (_Float32 __x) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32 modff32 (_Float32 __x, _Float32 *__iptr) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32 __modff32 (_Float32 __x, _Float32 *__iptr) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));
 extern _Float32 exp10f32 (_Float32 __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32 __exp10f32 (_Float32 __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float32 expm1f32 (_Float32 __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32 __expm1f32 (_Float32 __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float32 log1pf32 (_Float32 __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32 __log1pf32 (_Float32 __x) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32 logbf32 (_Float32 __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32 __logbf32 (_Float32 __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float32 exp2f32 (_Float32 __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32 __exp2f32 (_Float32 __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float32 log2f32 (_Float32 __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32 __log2f32 (_Float32 __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float32 powf32 (_Float32 __x, _Float32 __y) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32 __powf32 (_Float32 __x, _Float32 __y) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32 sqrtf32 (_Float32 __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32 __sqrtf32 (_Float32 __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float32 hypotf32 (_Float32 __x, _Float32 __y) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32 __hypotf32 (_Float32 __x, _Float32 __y) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float32 cbrtf32 (_Float32 __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32 __cbrtf32 (_Float32 __x) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32 ceilf32 (_Float32 __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float32 __ceilf32 (_Float32 __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float32 fabsf32 (_Float32 __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float32 __fabsf32 (_Float32 __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float32 floorf32 (_Float32 __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float32 __floorf32 (_Float32 __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float32 fmodf32 (_Float32 __x, _Float32 __y) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32 __fmodf32 (_Float32 __x, _Float32 __y) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32 copysignf32 (_Float32 __x, _Float32 __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float32 __copysignf32 (_Float32 __x, _Float32 __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float32 nanf32 (const char *__tagb) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32 __nanf32 (const char *__tagb) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32 j0f32 (_Float32) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32 __j0f32 (_Float32) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32 j1f32 (_Float32) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32 __j1f32 (_Float32) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32 jnf32 (int, _Float32) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32 __jnf32 (int, _Float32) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32 y0f32 (_Float32) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32 __y0f32 (_Float32) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32 y1f32 (_Float32) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32 __y1f32 (_Float32) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32 ynf32 (int, _Float32) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32 __ynf32 (int, _Float32) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float32 erff32 (_Float32) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32 __erff32 (_Float32) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float32 erfcf32 (_Float32) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32 __erfcf32 (_Float32) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32 lgammaf32 (_Float32) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32 __lgammaf32 (_Float32) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32 tgammaf32 (_Float32) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32 __tgammaf32 (_Float32) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32 lgammaf32_r (_Float32, int *__signgamp) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32 __lgammaf32_r (_Float32, int *__signgamp) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32 rintf32 (_Float32 __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32 __rintf32 (_Float32 __x) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32 nextafterf32 (_Float32 __x, _Float32 __y) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32 __nextafterf32 (_Float32 __x, _Float32 __y) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32 nextdownf32 (_Float32 __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32 __nextdownf32 (_Float32 __x) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32 nextupf32 (_Float32 __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32 __nextupf32 (_Float32 __x) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32 remainderf32 (_Float32 __x, _Float32 __y) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32 __remainderf32 (_Float32 __x, _Float32 __y) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32 scalbnf32 (_Float32 __x, int __n) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32 __scalbnf32 (_Float32 __x, int __n) __attribute__ ((__nothrow__ , __leaf__));
extern int ilogbf32 (_Float32 __x) __attribute__ ((__nothrow__ , __leaf__)); extern int __ilogbf32 (_Float32 __x) __attribute__ ((__nothrow__ , __leaf__));
extern long int llogbf32 (_Float32 __x) __attribute__ ((__nothrow__ , __leaf__)); extern long int __llogbf32 (_Float32 __x) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32 scalblnf32 (_Float32 __x, long int __n) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32 __scalblnf32 (_Float32 __x, long int __n) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32 nearbyintf32 (_Float32 __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32 __nearbyintf32 (_Float32 __x) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32 roundf32 (_Float32 __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float32 __roundf32 (_Float32 __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float32 truncf32 (_Float32 __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float32 __truncf32 (_Float32 __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float32 remquof32 (_Float32 __x, _Float32 __y, int *__quo) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32 __remquof32 (_Float32 __x, _Float32 __y, int *__quo) __attribute__ ((__nothrow__ , __leaf__));
extern long int lrintf32 (_Float32 __x) __attribute__ ((__nothrow__ , __leaf__)); extern long int __lrintf32 (_Float32 __x) __attribute__ ((__nothrow__ , __leaf__));
__extension__
extern long long int llrintf32 (_Float32 __x) __attribute__ ((__nothrow__ , __leaf__)); extern long long int __llrintf32 (_Float32 __x) __attribute__ ((__nothrow__ , __leaf__));
extern long int lroundf32 (_Float32 __x) __attribute__ ((__nothrow__ , __leaf__)); extern long int __lroundf32 (_Float32 __x) __attribute__ ((__nothrow__ , __leaf__));
__extension__
extern long long int llroundf32 (_Float32 __x) __attribute__ ((__nothrow__ , __leaf__)); extern long long int __llroundf32 (_Float32 __x) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32 fdimf32 (_Float32 __x, _Float32 __y) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32 __fdimf32 (_Float32 __x, _Float32 __y) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32 fmaxf32 (_Float32 __x, _Float32 __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float32 __fmaxf32 (_Float32 __x, _Float32 __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float32 fminf32 (_Float32 __x, _Float32 __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float32 __fminf32 (_Float32 __x, _Float32 __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float32 fmaf32 (_Float32 __x, _Float32 __y, _Float32 __z) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32 __fmaf32 (_Float32 __x, _Float32 __y, _Float32 __z) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32 roundevenf32 (_Float32 __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float32 __roundevenf32 (_Float32 __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern __intmax_t fromfpf32 (_Float32 __x, int __round, unsigned int __width) __attribute__ ((__nothrow__ , __leaf__)); extern __intmax_t __fromfpf32 (_Float32 __x, int __round, unsigned int __width) __attribute__ ((__nothrow__ , __leaf__));
extern __uintmax_t ufromfpf32 (_Float32 __x, int __round, unsigned int __width) __attribute__ ((__nothrow__ , __leaf__)); extern __uintmax_t __ufromfpf32 (_Float32 __x, int __round, unsigned int __width) __attribute__ ((__nothrow__ , __leaf__));
extern __intmax_t fromfpxf32 (_Float32 __x, int __round, unsigned int __width) __attribute__ ((__nothrow__ , __leaf__)); extern __intmax_t __fromfpxf32 (_Float32 __x, int __round, unsigned int __width) __attribute__ ((__nothrow__ , __leaf__));
extern __uintmax_t ufromfpxf32 (_Float32 __x, int __round, unsigned int __width) __attribute__ ((__nothrow__ , __leaf__)); extern __uintmax_t __ufromfpxf32 (_Float32 __x, int __round, unsigned int __width) __attribute__ ((__nothrow__ , __leaf__));
extern int canonicalizef32 (_Float32 *__cx, const _Float32 *__x) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32 fmaxmagf32 (_Float32 __x, _Float32 __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float32 __fmaxmagf32 (_Float32 __x, _Float32 __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float32 fminmagf32 (_Float32 __x, _Float32 __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float32 __fminmagf32 (_Float32 __x, _Float32 __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float32 fmaximumf32 (_Float32 __x, _Float32 __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float32 __fmaximumf32 (_Float32 __x, _Float32 __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float32 fminimumf32 (_Float32 __x, _Float32 __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float32 __fminimumf32 (_Float32 __x, _Float32 __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float32 fmaximum_numf32 (_Float32 __x, _Float32 __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float32 __fmaximum_numf32 (_Float32 __x, _Float32 __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float32 fminimum_numf32 (_Float32 __x, _Float32 __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float32 __fminimum_numf32 (_Float32 __x, _Float32 __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float32 fmaximum_magf32 (_Float32 __x, _Float32 __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float32 __fmaximum_magf32 (_Float32 __x, _Float32 __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float32 fminimum_magf32 (_Float32 __x, _Float32 __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float32 __fminimum_magf32 (_Float32 __x, _Float32 __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float32 fmaximum_mag_numf32 (_Float32 __x, _Float32 __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float32 __fmaximum_mag_numf32 (_Float32 __x, _Float32 __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float32 fminimum_mag_numf32 (_Float32 __x, _Float32 __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float32 __fminimum_mag_numf32 (_Float32 __x, _Float32 __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern int totalorderf32 (const _Float32 *__x, const _Float32 *__y) __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__pure__));
extern int totalordermagf32 (const _Float32 *__x, const _Float32 *__y) __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__pure__));
extern _Float32 getpayloadf32 (const _Float32 *__x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32 __getpayloadf32 (const _Float32 *__x) __attribute__ ((__nothrow__ , __leaf__));
extern int setpayloadf32 (_Float32 *__x, _Float32 __payload) __attribute__ ((__nothrow__ , __leaf__));
extern int setpayloadsigf32 (_Float32 *__x, _Float32 __payload) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float64 acosf64 (_Float64 __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64 __acosf64 (_Float64 __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float64 asinf64 (_Float64 __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64 __asinf64 (_Float64 __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float64 atanf64 (_Float64 __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64 __atanf64 (_Float64 __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float64 atan2f64 (_Float64 __y, _Float64 __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64 __atan2f64 (_Float64 __y, _Float64 __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float64 cosf64 (_Float64 __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64 __cosf64 (_Float64 __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float64 sinf64 (_Float64 __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64 __sinf64 (_Float64 __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float64 tanf64 (_Float64 __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64 __tanf64 (_Float64 __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float64 coshf64 (_Float64 __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64 __coshf64 (_Float64 __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float64 sinhf64 (_Float64 __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64 __sinhf64 (_Float64 __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float64 tanhf64 (_Float64 __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64 __tanhf64 (_Float64 __x) __attribute__ ((__nothrow__ , __leaf__));
 extern void sincosf64 (_Float64 __x, _Float64 *__sinx, _Float64 *__cosx) __attribute__ ((__nothrow__ , __leaf__)); extern void __sincosf64 (_Float64 __x, _Float64 *__sinx, _Float64 *__cosx) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float64 acoshf64 (_Float64 __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64 __acoshf64 (_Float64 __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float64 asinhf64 (_Float64 __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64 __asinhf64 (_Float64 __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float64 atanhf64 (_Float64 __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64 __atanhf64 (_Float64 __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float64 expf64 (_Float64 __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64 __expf64 (_Float64 __x) __attribute__ ((__nothrow__ , __leaf__));
extern _Float64 frexpf64 (_Float64 __x, int *__exponent) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64 __frexpf64 (_Float64 __x, int *__exponent) __attribute__ ((__nothrow__ , __leaf__));
extern _Float64 ldexpf64 (_Float64 __x, int __exponent) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64 __ldexpf64 (_Float64 __x, int __exponent) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float64 logf64 (_Float64 __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64 __logf64 (_Float64 __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float64 log10f64 (_Float64 __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64 __log10f64 (_Float64 __x) __attribute__ ((__nothrow__ , __leaf__));
extern _Float64 modff64 (_Float64 __x, _Float64 *__iptr) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64 __modff64 (_Float64 __x, _Float64 *__iptr) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));
 extern _Float64 exp10f64 (_Float64 __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64 __exp10f64 (_Float64 __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float64 expm1f64 (_Float64 __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64 __expm1f64 (_Float64 __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float64 log1pf64 (_Float64 __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64 __log1pf64 (_Float64 __x) __attribute__ ((__nothrow__ , __leaf__));
extern _Float64 logbf64 (_Float64 __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64 __logbf64 (_Float64 __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float64 exp2f64 (_Float64 __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64 __exp2f64 (_Float64 __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float64 log2f64 (_Float64 __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64 __log2f64 (_Float64 __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float64 powf64 (_Float64 __x, _Float64 __y) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64 __powf64 (_Float64 __x, _Float64 __y) __attribute__ ((__nothrow__ , __leaf__));
extern _Float64 sqrtf64 (_Float64 __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64 __sqrtf64 (_Float64 __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float64 hypotf64 (_Float64 __x, _Float64 __y) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64 __hypotf64 (_Float64 __x, _Float64 __y) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float64 cbrtf64 (_Float64 __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64 __cbrtf64 (_Float64 __x) __attribute__ ((__nothrow__ , __leaf__));
extern _Float64 ceilf64 (_Float64 __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float64 __ceilf64 (_Float64 __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float64 fabsf64 (_Float64 __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float64 __fabsf64 (_Float64 __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float64 floorf64 (_Float64 __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float64 __floorf64 (_Float64 __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float64 fmodf64 (_Float64 __x, _Float64 __y) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64 __fmodf64 (_Float64 __x, _Float64 __y) __attribute__ ((__nothrow__ , __leaf__));
extern _Float64 copysignf64 (_Float64 __x, _Float64 __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float64 __copysignf64 (_Float64 __x, _Float64 __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float64 nanf64 (const char *__tagb) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64 __nanf64 (const char *__tagb) __attribute__ ((__nothrow__ , __leaf__));
extern _Float64 j0f64 (_Float64) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64 __j0f64 (_Float64) __attribute__ ((__nothrow__ , __leaf__));
extern _Float64 j1f64 (_Float64) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64 __j1f64 (_Float64) __attribute__ ((__nothrow__ , __leaf__));
extern _Float64 jnf64 (int, _Float64) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64 __jnf64 (int, _Float64) __attribute__ ((__nothrow__ , __leaf__));
extern _Float64 y0f64 (_Float64) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64 __y0f64 (_Float64) __attribute__ ((__nothrow__ , __leaf__));
extern _Float64 y1f64 (_Float64) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64 __y1f64 (_Float64) __attribute__ ((__nothrow__ , __leaf__));
extern _Float64 ynf64 (int, _Float64) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64 __ynf64 (int, _Float64) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float64 erff64 (_Float64) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64 __erff64 (_Float64) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float64 erfcf64 (_Float64) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64 __erfcf64 (_Float64) __attribute__ ((__nothrow__ , __leaf__));
extern _Float64 lgammaf64 (_Float64) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64 __lgammaf64 (_Float64) __attribute__ ((__nothrow__ , __leaf__));
extern _Float64 tgammaf64 (_Float64) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64 __tgammaf64 (_Float64) __attribute__ ((__nothrow__ , __leaf__));
extern _Float64 lgammaf64_r (_Float64, int *__signgamp) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64 __lgammaf64_r (_Float64, int *__signgamp) __attribute__ ((__nothrow__ , __leaf__));
extern _Float64 rintf64 (_Float64 __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64 __rintf64 (_Float64 __x) __attribute__ ((__nothrow__ , __leaf__));
extern _Float64 nextafterf64 (_Float64 __x, _Float64 __y) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64 __nextafterf64 (_Float64 __x, _Float64 __y) __attribute__ ((__nothrow__ , __leaf__));
extern _Float64 nextdownf64 (_Float64 __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64 __nextdownf64 (_Float64 __x) __attribute__ ((__nothrow__ , __leaf__));
extern _Float64 nextupf64 (_Float64 __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64 __nextupf64 (_Float64 __x) __attribute__ ((__nothrow__ , __leaf__));
extern _Float64 remainderf64 (_Float64 __x, _Float64 __y) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64 __remainderf64 (_Float64 __x, _Float64 __y) __attribute__ ((__nothrow__ , __leaf__));
extern _Float64 scalbnf64 (_Float64 __x, int __n) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64 __scalbnf64 (_Float64 __x, int __n) __attribute__ ((__nothrow__ , __leaf__));
extern int ilogbf64 (_Float64 __x) __attribute__ ((__nothrow__ , __leaf__)); extern int __ilogbf64 (_Float64 __x) __attribute__ ((__nothrow__ , __leaf__));
extern long int llogbf64 (_Float64 __x) __attribute__ ((__nothrow__ , __leaf__)); extern long int __llogbf64 (_Float64 __x) __attribute__ ((__nothrow__ , __leaf__));
extern _Float64 scalblnf64 (_Float64 __x, long int __n) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64 __scalblnf64 (_Float64 __x, long int __n) __attribute__ ((__nothrow__ , __leaf__));
extern _Float64 nearbyintf64 (_Float64 __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64 __nearbyintf64 (_Float64 __x) __attribute__ ((__nothrow__ , __leaf__));
extern _Float64 roundf64 (_Float64 __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float64 __roundf64 (_Float64 __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float64 truncf64 (_Float64 __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float64 __truncf64 (_Float64 __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float64 remquof64 (_Float64 __x, _Float64 __y, int *__quo) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64 __remquof64 (_Float64 __x, _Float64 __y, int *__quo) __attribute__ ((__nothrow__ , __leaf__));
extern long int lrintf64 (_Float64 __x) __attribute__ ((__nothrow__ , __leaf__)); extern long int __lrintf64 (_Float64 __x) __attribute__ ((__nothrow__ , __leaf__));
__extension__
extern long long int llrintf64 (_Float64 __x) __attribute__ ((__nothrow__ , __leaf__)); extern long long int __llrintf64 (_Float64 __x) __attribute__ ((__nothrow__ , __leaf__));
extern long int lroundf64 (_Float64 __x) __attribute__ ((__nothrow__ , __leaf__)); extern long int __lroundf64 (_Float64 __x) __attribute__ ((__nothrow__ , __leaf__));
__extension__
extern long long int llroundf64 (_Float64 __x) __attribute__ ((__nothrow__ , __leaf__)); extern long long int __llroundf64 (_Float64 __x) __attribute__ ((__nothrow__ , __leaf__));
extern _Float64 fdimf64 (_Float64 __x, _Float64 __y) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64 __fdimf64 (_Float64 __x, _Float64 __y) __attribute__ ((__nothrow__ , __leaf__));
extern _Float64 fmaxf64 (_Float64 __x, _Float64 __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float64 __fmaxf64 (_Float64 __x, _Float64 __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float64 fminf64 (_Float64 __x, _Float64 __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float64 __fminf64 (_Float64 __x, _Float64 __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float64 fmaf64 (_Float64 __x, _Float64 __y, _Float64 __z) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64 __fmaf64 (_Float64 __x, _Float64 __y, _Float64 __z) __attribute__ ((__nothrow__ , __leaf__));
extern _Float64 roundevenf64 (_Float64 __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float64 __roundevenf64 (_Float64 __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern __intmax_t fromfpf64 (_Float64 __x, int __round, unsigned int __width) __attribute__ ((__nothrow__ , __leaf__)); extern __intmax_t __fromfpf64 (_Float64 __x, int __round, unsigned int __width) __attribute__ ((__nothrow__ , __leaf__));
extern __uintmax_t ufromfpf64 (_Float64 __x, int __round, unsigned int __width) __attribute__ ((__nothrow__ , __leaf__)); extern __uintmax_t __ufromfpf64 (_Float64 __x, int __round, unsigned int __width) __attribute__ ((__nothrow__ , __leaf__));
extern __intmax_t fromfpxf64 (_Float64 __x, int __round, unsigned int __width) __attribute__ ((__nothrow__ , __leaf__)); extern __intmax_t __fromfpxf64 (_Float64 __x, int __round, unsigned int __width) __attribute__ ((__nothrow__ , __leaf__));
extern __uintmax_t ufromfpxf64 (_Float64 __x, int __round, unsigned int __width) __attribute__ ((__nothrow__ , __leaf__)); extern __uintmax_t __ufromfpxf64 (_Float64 __x, int __round, unsigned int __width) __attribute__ ((__nothrow__ , __leaf__));
extern int canonicalizef64 (_Float64 *__cx, const _Float64 *__x) __attribute__ ((__nothrow__ , __leaf__));
extern _Float64 fmaxmagf64 (_Float64 __x, _Float64 __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float64 __fmaxmagf64 (_Float64 __x, _Float64 __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float64 fminmagf64 (_Float64 __x, _Float64 __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float64 __fminmagf64 (_Float64 __x, _Float64 __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float64 fmaximumf64 (_Float64 __x, _Float64 __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float64 __fmaximumf64 (_Float64 __x, _Float64 __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float64 fminimumf64 (_Float64 __x, _Float64 __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float64 __fminimumf64 (_Float64 __x, _Float64 __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float64 fmaximum_numf64 (_Float64 __x, _Float64 __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float64 __fmaximum_numf64 (_Float64 __x, _Float64 __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float64 fminimum_numf64 (_Float64 __x, _Float64 __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float64 __fminimum_numf64 (_Float64 __x, _Float64 __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float64 fmaximum_magf64 (_Float64 __x, _Float64 __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float64 __fmaximum_magf64 (_Float64 __x, _Float64 __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float64 fminimum_magf64 (_Float64 __x, _Float64 __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float64 __fminimum_magf64 (_Float64 __x, _Float64 __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float64 fmaximum_mag_numf64 (_Float64 __x, _Float64 __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float64 __fmaximum_mag_numf64 (_Float64 __x, _Float64 __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float64 fminimum_mag_numf64 (_Float64 __x, _Float64 __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float64 __fminimum_mag_numf64 (_Float64 __x, _Float64 __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern int totalorderf64 (const _Float64 *__x, const _Float64 *__y) __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__pure__));
extern int totalordermagf64 (const _Float64 *__x, const _Float64 *__y) __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__pure__));
extern _Float64 getpayloadf64 (const _Float64 *__x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64 __getpayloadf64 (const _Float64 *__x) __attribute__ ((__nothrow__ , __leaf__));
extern int setpayloadf64 (_Float64 *__x, _Float64 __payload) __attribute__ ((__nothrow__ , __leaf__));
extern int setpayloadsigf64 (_Float64 *__x, _Float64 __payload) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float128 acosf128 (_Float128 __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float128 __acosf128 (_Float128 __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float128 asinf128 (_Float128 __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float128 __asinf128 (_Float128 __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float128 atanf128 (_Float128 __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float128 __atanf128 (_Float128 __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float128 atan2f128 (_Float128 __y, _Float128 __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float128 __atan2f128 (_Float128 __y, _Float128 __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float128 cosf128 (_Float128 __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float128 __cosf128 (_Float128 __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float128 sinf128 (_Float128 __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float128 __sinf128 (_Float128 __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float128 tanf128 (_Float128 __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float128 __tanf128 (_Float128 __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float128 coshf128 (_Float128 __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float128 __coshf128 (_Float128 __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float128 sinhf128 (_Float128 __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float128 __sinhf128 (_Float128 __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float128 tanhf128 (_Float128 __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float128 __tanhf128 (_Float128 __x) __attribute__ ((__nothrow__ , __leaf__));
 extern void sincosf128 (_Float128 __x, _Float128 *__sinx, _Float128 *__cosx) __attribute__ ((__nothrow__ , __leaf__)); extern void __sincosf128 (_Float128 __x, _Float128 *__sinx, _Float128 *__cosx) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float128 acoshf128 (_Float128 __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float128 __acoshf128 (_Float128 __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float128 asinhf128 (_Float128 __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float128 __asinhf128 (_Float128 __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float128 atanhf128 (_Float128 __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float128 __atanhf128 (_Float128 __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float128 expf128 (_Float128 __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float128 __expf128 (_Float128 __x) __attribute__ ((__nothrow__ , __leaf__));
extern _Float128 frexpf128 (_Float128 __x, int *__exponent) __attribute__ ((__nothrow__ , __leaf__)); extern _Float128 __frexpf128 (_Float128 __x, int *__exponent) __attribute__ ((__nothrow__ , __leaf__));
extern _Float128 ldexpf128 (_Float128 __x, int __exponent) __attribute__ ((__nothrow__ , __leaf__)); extern _Float128 __ldexpf128 (_Float128 __x, int __exponent) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float128 logf128 (_Float128 __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float128 __logf128 (_Float128 __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float128 log10f128 (_Float128 __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float128 __log10f128 (_Float128 __x) __attribute__ ((__nothrow__ , __leaf__));
extern _Float128 modff128 (_Float128 __x, _Float128 *__iptr) __attribute__ ((__nothrow__ , __leaf__)); extern _Float128 __modff128 (_Float128 __x, _Float128 *__iptr) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));
 extern _Float128 exp10f128 (_Float128 __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float128 __exp10f128 (_Float128 __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float128 expm1f128 (_Float128 __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float128 __expm1f128 (_Float128 __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float128 log1pf128 (_Float128 __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float128 __log1pf128 (_Float128 __x) __attribute__ ((__nothrow__ , __leaf__));
extern _Float128 logbf128 (_Float128 __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float128 __logbf128 (_Float128 __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float128 exp2f128 (_Float128 __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float128 __exp2f128 (_Float128 __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float128 log2f128 (_Float128 __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float128 __log2f128 (_Float128 __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float128 powf128 (_Float128 __x, _Float128 __y) __attribute__ ((__nothrow__ , __leaf__)); extern _Float128 __powf128 (_Float128 __x, _Float128 __y) __attribute__ ((__nothrow__ , __leaf__));
extern _Float128 sqrtf128 (_Float128 __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float128 __sqrtf128 (_Float128 __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float128 hypotf128 (_Float128 __x, _Float128 __y) __attribute__ ((__nothrow__ , __leaf__)); extern _Float128 __hypotf128 (_Float128 __x, _Float128 __y) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float128 cbrtf128 (_Float128 __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float128 __cbrtf128 (_Float128 __x) __attribute__ ((__nothrow__ , __leaf__));
extern _Float128 ceilf128 (_Float128 __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float128 __ceilf128 (_Float128 __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float128 fabsf128 (_Float128 __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float128 __fabsf128 (_Float128 __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float128 floorf128 (_Float128 __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float128 __floorf128 (_Float128 __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float128 fmodf128 (_Float128 __x, _Float128 __y) __attribute__ ((__nothrow__ , __leaf__)); extern _Float128 __fmodf128 (_Float128 __x, _Float128 __y) __attribute__ ((__nothrow__ , __leaf__));
extern _Float128 copysignf128 (_Float128 __x, _Float128 __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float128 __copysignf128 (_Float128 __x, _Float128 __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float128 nanf128 (const char *__tagb) __attribute__ ((__nothrow__ , __leaf__)); extern _Float128 __nanf128 (const char *__tagb) __attribute__ ((__nothrow__ , __leaf__));
extern _Float128 j0f128 (_Float128) __attribute__ ((__nothrow__ , __leaf__)); extern _Float128 __j0f128 (_Float128) __attribute__ ((__nothrow__ , __leaf__));
extern _Float128 j1f128 (_Float128) __attribute__ ((__nothrow__ , __leaf__)); extern _Float128 __j1f128 (_Float128) __attribute__ ((__nothrow__ , __leaf__));
extern _Float128 jnf128 (int, _Float128) __attribute__ ((__nothrow__ , __leaf__)); extern _Float128 __jnf128 (int, _Float128) __attribute__ ((__nothrow__ , __leaf__));
extern _Float128 y0f128 (_Float128) __attribute__ ((__nothrow__ , __leaf__)); extern _Float128 __y0f128 (_Float128) __attribute__ ((__nothrow__ , __leaf__));
extern _Float128 y1f128 (_Float128) __attribute__ ((__nothrow__ , __leaf__)); extern _Float128 __y1f128 (_Float128) __attribute__ ((__nothrow__ , __leaf__));
extern _Float128 ynf128 (int, _Float128) __attribute__ ((__nothrow__ , __leaf__)); extern _Float128 __ynf128 (int, _Float128) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float128 erff128 (_Float128) __attribute__ ((__nothrow__ , __leaf__)); extern _Float128 __erff128 (_Float128) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float128 erfcf128 (_Float128) __attribute__ ((__nothrow__ , __leaf__)); extern _Float128 __erfcf128 (_Float128) __attribute__ ((__nothrow__ , __leaf__));
extern _Float128 lgammaf128 (_Float128) __attribute__ ((__nothrow__ , __leaf__)); extern _Float128 __lgammaf128 (_Float128) __attribute__ ((__nothrow__ , __leaf__));
extern _Float128 tgammaf128 (_Float128) __attribute__ ((__nothrow__ , __leaf__)); extern _Float128 __tgammaf128 (_Float128) __attribute__ ((__nothrow__ , __leaf__));
extern _Float128 lgammaf128_r (_Float128, int *__signgamp) __attribute__ ((__nothrow__ , __leaf__)); extern _Float128 __lgammaf128_r (_Float128, int *__signgamp) __attribute__ ((__nothrow__ , __leaf__));
extern _Float128 rintf128 (_Float128 __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float128 __rintf128 (_Float128 __x) __attribute__ ((__nothrow__ , __leaf__));
extern _Float128 nextafterf128 (_Float128 __x, _Float128 __y) __attribute__ ((__nothrow__ , __leaf__)); extern _Float128 __nextafterf128 (_Float128 __x, _Float128 __y) __attribute__ ((__nothrow__ , __leaf__));
extern _Float128 nextdownf128 (_Float128 __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float128 __nextdownf128 (_Float128 __x) __attribute__ ((__nothrow__ , __leaf__));
extern _Float128 nextupf128 (_Float128 __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float128 __nextupf128 (_Float128 __x) __attribute__ ((__nothrow__ , __leaf__));
extern _Float128 remainderf128 (_Float128 __x, _Float128 __y) __attribute__ ((__nothrow__ , __leaf__)); extern _Float128 __remainderf128 (_Float128 __x, _Float128 __y) __attribute__ ((__nothrow__ , __leaf__));
extern _Float128 scalbnf128 (_Float128 __x, int __n) __attribute__ ((__nothrow__ , __leaf__)); extern _Float128 __scalbnf128 (_Float128 __x, int __n) __attribute__ ((__nothrow__ , __leaf__));
extern int ilogbf128 (_Float128 __x) __attribute__ ((__nothrow__ , __leaf__)); extern int __ilogbf128 (_Float128 __x) __attribute__ ((__nothrow__ , __leaf__));
extern long int llogbf128 (_Float128 __x) __attribute__ ((__nothrow__ , __leaf__)); extern long int __llogbf128 (_Float128 __x) __attribute__ ((__nothrow__ , __leaf__));
extern _Float128 scalblnf128 (_Float128 __x, long int __n) __attribute__ ((__nothrow__ , __leaf__)); extern _Float128 __scalblnf128 (_Float128 __x, long int __n) __attribute__ ((__nothrow__ , __leaf__));
extern _Float128 nearbyintf128 (_Float128 __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float128 __nearbyintf128 (_Float128 __x) __attribute__ ((__nothrow__ , __leaf__));
extern _Float128 roundf128 (_Float128 __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float128 __roundf128 (_Float128 __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float128 truncf128 (_Float128 __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float128 __truncf128 (_Float128 __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float128 remquof128 (_Float128 __x, _Float128 __y, int *__quo) __attribute__ ((__nothrow__ , __leaf__)); extern _Float128 __remquof128 (_Float128 __x, _Float128 __y, int *__quo) __attribute__ ((__nothrow__ , __leaf__));
extern long int lrintf128 (_Float128 __x) __attribute__ ((__nothrow__ , __leaf__)); extern long int __lrintf128 (_Float128 __x) __attribute__ ((__nothrow__ , __leaf__));
__extension__
extern long long int llrintf128 (_Float128 __x) __attribute__ ((__nothrow__ , __leaf__)); extern long long int __llrintf128 (_Float128 __x) __attribute__ ((__nothrow__ , __leaf__));
extern long int lroundf128 (_Float128 __x) __attribute__ ((__nothrow__ , __leaf__)); extern long int __lroundf128 (_Float128 __x) __attribute__ ((__nothrow__ , __leaf__));
__extension__
extern long long int llroundf128 (_Float128 __x) __attribute__ ((__nothrow__ , __leaf__)); extern long long int __llroundf128 (_Float128 __x) __attribute__ ((__nothrow__ , __leaf__));
extern _Float128 fdimf128 (_Float128 __x, _Float128 __y) __attribute__ ((__nothrow__ , __leaf__)); extern _Float128 __fdimf128 (_Float128 __x, _Float128 __y) __attribute__ ((__nothrow__ , __leaf__));
extern _Float128 fmaxf128 (_Float128 __x, _Float128 __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float128 __fmaxf128 (_Float128 __x, _Float128 __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float128 fminf128 (_Float128 __x, _Float128 __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float128 __fminf128 (_Float128 __x, _Float128 __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float128 fmaf128 (_Float128 __x, _Float128 __y, _Float128 __z) __attribute__ ((__nothrow__ , __leaf__)); extern _Float128 __fmaf128 (_Float128 __x, _Float128 __y, _Float128 __z) __attribute__ ((__nothrow__ , __leaf__));
extern _Float128 roundevenf128 (_Float128 __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float128 __roundevenf128 (_Float128 __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern __intmax_t fromfpf128 (_Float128 __x, int __round, unsigned int __width) __attribute__ ((__nothrow__ , __leaf__)); extern __intmax_t __fromfpf128 (_Float128 __x, int __round, unsigned int __width) __attribute__ ((__nothrow__ , __leaf__));
extern __uintmax_t ufromfpf128 (_Float128 __x, int __round, unsigned int __width) __attribute__ ((__nothrow__ , __leaf__)); extern __uintmax_t __ufromfpf128 (_Float128 __x, int __round, unsigned int __width) __attribute__ ((__nothrow__ , __leaf__));
extern __intmax_t fromfpxf128 (_Float128 __x, int __round, unsigned int __width) __attribute__ ((__nothrow__ , __leaf__)); extern __intmax_t __fromfpxf128 (_Float128 __x, int __round, unsigned int __width) __attribute__ ((__nothrow__ , __leaf__));
extern __uintmax_t ufromfpxf128 (_Float128 __x, int __round, unsigned int __width) __attribute__ ((__nothrow__ , __leaf__)); extern __uintmax_t __ufromfpxf128 (_Float128 __x, int __round, unsigned int __width) __attribute__ ((__nothrow__ , __leaf__));
extern int canonicalizef128 (_Float128 *__cx, const _Float128 *__x) __attribute__ ((__nothrow__ , __leaf__));
extern _Float128 fmaxmagf128 (_Float128 __x, _Float128 __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float128 __fmaxmagf128 (_Float128 __x, _Float128 __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float128 fminmagf128 (_Float128 __x, _Float128 __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float128 __fminmagf128 (_Float128 __x, _Float128 __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float128 fmaximumf128 (_Float128 __x, _Float128 __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float128 __fmaximumf128 (_Float128 __x, _Float128 __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float128 fminimumf128 (_Float128 __x, _Float128 __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float128 __fminimumf128 (_Float128 __x, _Float128 __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float128 fmaximum_numf128 (_Float128 __x, _Float128 __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float128 __fmaximum_numf128 (_Float128 __x, _Float128 __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float128 fminimum_numf128 (_Float128 __x, _Float128 __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float128 __fminimum_numf128 (_Float128 __x, _Float128 __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float128 fmaximum_magf128 (_Float128 __x, _Float128 __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float128 __fmaximum_magf128 (_Float128 __x, _Float128 __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float128 fminimum_magf128 (_Float128 __x, _Float128 __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float128 __fminimum_magf128 (_Float128 __x, _Float128 __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float128 fmaximum_mag_numf128 (_Float128 __x, _Float128 __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float128 __fmaximum_mag_numf128 (_Float128 __x, _Float128 __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float128 fminimum_mag_numf128 (_Float128 __x, _Float128 __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float128 __fminimum_mag_numf128 (_Float128 __x, _Float128 __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern int totalorderf128 (const _Float128 *__x, const _Float128 *__y) __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__pure__));
extern int totalordermagf128 (const _Float128 *__x, const _Float128 *__y) __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__pure__));
extern _Float128 getpayloadf128 (const _Float128 *__x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float128 __getpayloadf128 (const _Float128 *__x) __attribute__ ((__nothrow__ , __leaf__));
extern int setpayloadf128 (_Float128 *__x, _Float128 __payload) __attribute__ ((__nothrow__ , __leaf__));
extern int setpayloadsigf128 (_Float128 *__x, _Float128 __payload) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float32x acosf32x (_Float32x __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32x __acosf32x (_Float32x __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float32x asinf32x (_Float32x __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32x __asinf32x (_Float32x __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float32x atanf32x (_Float32x __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32x __atanf32x (_Float32x __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float32x atan2f32x (_Float32x __y, _Float32x __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32x __atan2f32x (_Float32x __y, _Float32x __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float32x cosf32x (_Float32x __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32x __cosf32x (_Float32x __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float32x sinf32x (_Float32x __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32x __sinf32x (_Float32x __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float32x tanf32x (_Float32x __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32x __tanf32x (_Float32x __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float32x coshf32x (_Float32x __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32x __coshf32x (_Float32x __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float32x sinhf32x (_Float32x __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32x __sinhf32x (_Float32x __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float32x tanhf32x (_Float32x __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32x __tanhf32x (_Float32x __x) __attribute__ ((__nothrow__ , __leaf__));
 extern void sincosf32x (_Float32x __x, _Float32x *__sinx, _Float32x *__cosx) __attribute__ ((__nothrow__ , __leaf__)); extern void __sincosf32x (_Float32x __x, _Float32x *__sinx, _Float32x *__cosx) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float32x acoshf32x (_Float32x __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32x __acoshf32x (_Float32x __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float32x asinhf32x (_Float32x __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32x __asinhf32x (_Float32x __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float32x atanhf32x (_Float32x __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32x __atanhf32x (_Float32x __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float32x expf32x (_Float32x __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32x __expf32x (_Float32x __x) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32x frexpf32x (_Float32x __x, int *__exponent) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32x __frexpf32x (_Float32x __x, int *__exponent) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32x ldexpf32x (_Float32x __x, int __exponent) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32x __ldexpf32x (_Float32x __x, int __exponent) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float32x logf32x (_Float32x __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32x __logf32x (_Float32x __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float32x log10f32x (_Float32x __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32x __log10f32x (_Float32x __x) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32x modff32x (_Float32x __x, _Float32x *__iptr) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32x __modff32x (_Float32x __x, _Float32x *__iptr) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));
 extern _Float32x exp10f32x (_Float32x __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32x __exp10f32x (_Float32x __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float32x expm1f32x (_Float32x __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32x __expm1f32x (_Float32x __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float32x log1pf32x (_Float32x __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32x __log1pf32x (_Float32x __x) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32x logbf32x (_Float32x __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32x __logbf32x (_Float32x __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float32x exp2f32x (_Float32x __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32x __exp2f32x (_Float32x __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float32x log2f32x (_Float32x __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32x __log2f32x (_Float32x __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float32x powf32x (_Float32x __x, _Float32x __y) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32x __powf32x (_Float32x __x, _Float32x __y) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32x sqrtf32x (_Float32x __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32x __sqrtf32x (_Float32x __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float32x hypotf32x (_Float32x __x, _Float32x __y) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32x __hypotf32x (_Float32x __x, _Float32x __y) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float32x cbrtf32x (_Float32x __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32x __cbrtf32x (_Float32x __x) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32x ceilf32x (_Float32x __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float32x __ceilf32x (_Float32x __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float32x fabsf32x (_Float32x __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float32x __fabsf32x (_Float32x __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float32x floorf32x (_Float32x __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float32x __floorf32x (_Float32x __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float32x fmodf32x (_Float32x __x, _Float32x __y) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32x __fmodf32x (_Float32x __x, _Float32x __y) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32x copysignf32x (_Float32x __x, _Float32x __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float32x __copysignf32x (_Float32x __x, _Float32x __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float32x nanf32x (const char *__tagb) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32x __nanf32x (const char *__tagb) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32x j0f32x (_Float32x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32x __j0f32x (_Float32x) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32x j1f32x (_Float32x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32x __j1f32x (_Float32x) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32x jnf32x (int, _Float32x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32x __jnf32x (int, _Float32x) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32x y0f32x (_Float32x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32x __y0f32x (_Float32x) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32x y1f32x (_Float32x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32x __y1f32x (_Float32x) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32x ynf32x (int, _Float32x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32x __ynf32x (int, _Float32x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float32x erff32x (_Float32x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32x __erff32x (_Float32x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float32x erfcf32x (_Float32x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32x __erfcf32x (_Float32x) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32x lgammaf32x (_Float32x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32x __lgammaf32x (_Float32x) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32x tgammaf32x (_Float32x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32x __tgammaf32x (_Float32x) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32x lgammaf32x_r (_Float32x, int *__signgamp) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32x __lgammaf32x_r (_Float32x, int *__signgamp) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32x rintf32x (_Float32x __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32x __rintf32x (_Float32x __x) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32x nextafterf32x (_Float32x __x, _Float32x __y) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32x __nextafterf32x (_Float32x __x, _Float32x __y) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32x nextdownf32x (_Float32x __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32x __nextdownf32x (_Float32x __x) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32x nextupf32x (_Float32x __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32x __nextupf32x (_Float32x __x) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32x remainderf32x (_Float32x __x, _Float32x __y) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32x __remainderf32x (_Float32x __x, _Float32x __y) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32x scalbnf32x (_Float32x __x, int __n) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32x __scalbnf32x (_Float32x __x, int __n) __attribute__ ((__nothrow__ , __leaf__));
extern int ilogbf32x (_Float32x __x) __attribute__ ((__nothrow__ , __leaf__)); extern int __ilogbf32x (_Float32x __x) __attribute__ ((__nothrow__ , __leaf__));
extern long int llogbf32x (_Float32x __x) __attribute__ ((__nothrow__ , __leaf__)); extern long int __llogbf32x (_Float32x __x) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32x scalblnf32x (_Float32x __x, long int __n) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32x __scalblnf32x (_Float32x __x, long int __n) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32x nearbyintf32x (_Float32x __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32x __nearbyintf32x (_Float32x __x) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32x roundf32x (_Float32x __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float32x __roundf32x (_Float32x __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float32x truncf32x (_Float32x __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float32x __truncf32x (_Float32x __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float32x remquof32x (_Float32x __x, _Float32x __y, int *__quo) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32x __remquof32x (_Float32x __x, _Float32x __y, int *__quo) __attribute__ ((__nothrow__ , __leaf__));
extern long int lrintf32x (_Float32x __x) __attribute__ ((__nothrow__ , __leaf__)); extern long int __lrintf32x (_Float32x __x) __attribute__ ((__nothrow__ , __leaf__));
__extension__
extern long long int llrintf32x (_Float32x __x) __attribute__ ((__nothrow__ , __leaf__)); extern long long int __llrintf32x (_Float32x __x) __attribute__ ((__nothrow__ , __leaf__));
extern long int lroundf32x (_Float32x __x) __attribute__ ((__nothrow__ , __leaf__)); extern long int __lroundf32x (_Float32x __x) __attribute__ ((__nothrow__ , __leaf__));
__extension__
extern long long int llroundf32x (_Float32x __x) __attribute__ ((__nothrow__ , __leaf__)); extern long long int __llroundf32x (_Float32x __x) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32x fdimf32x (_Float32x __x, _Float32x __y) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32x __fdimf32x (_Float32x __x, _Float32x __y) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32x fmaxf32x (_Float32x __x, _Float32x __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float32x __fmaxf32x (_Float32x __x, _Float32x __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float32x fminf32x (_Float32x __x, _Float32x __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float32x __fminf32x (_Float32x __x, _Float32x __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float32x fmaf32x (_Float32x __x, _Float32x __y, _Float32x __z) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32x __fmaf32x (_Float32x __x, _Float32x __y, _Float32x __z) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32x roundevenf32x (_Float32x __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float32x __roundevenf32x (_Float32x __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern __intmax_t fromfpf32x (_Float32x __x, int __round, unsigned int __width) __attribute__ ((__nothrow__ , __leaf__)); extern __intmax_t __fromfpf32x (_Float32x __x, int __round, unsigned int __width) __attribute__ ((__nothrow__ , __leaf__));
extern __uintmax_t ufromfpf32x (_Float32x __x, int __round, unsigned int __width) __attribute__ ((__nothrow__ , __leaf__)); extern __uintmax_t __ufromfpf32x (_Float32x __x, int __round, unsigned int __width) __attribute__ ((__nothrow__ , __leaf__));
extern __intmax_t fromfpxf32x (_Float32x __x, int __round, unsigned int __width) __attribute__ ((__nothrow__ , __leaf__)); extern __intmax_t __fromfpxf32x (_Float32x __x, int __round, unsigned int __width) __attribute__ ((__nothrow__ , __leaf__));
extern __uintmax_t ufromfpxf32x (_Float32x __x, int __round, unsigned int __width) __attribute__ ((__nothrow__ , __leaf__)); extern __uintmax_t __ufromfpxf32x (_Float32x __x, int __round, unsigned int __width) __attribute__ ((__nothrow__ , __leaf__));
extern int canonicalizef32x (_Float32x *__cx, const _Float32x *__x) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32x fmaxmagf32x (_Float32x __x, _Float32x __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float32x __fmaxmagf32x (_Float32x __x, _Float32x __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float32x fminmagf32x (_Float32x __x, _Float32x __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float32x __fminmagf32x (_Float32x __x, _Float32x __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float32x fmaximumf32x (_Float32x __x, _Float32x __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float32x __fmaximumf32x (_Float32x __x, _Float32x __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float32x fminimumf32x (_Float32x __x, _Float32x __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float32x __fminimumf32x (_Float32x __x, _Float32x __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float32x fmaximum_numf32x (_Float32x __x, _Float32x __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float32x __fmaximum_numf32x (_Float32x __x, _Float32x __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float32x fminimum_numf32x (_Float32x __x, _Float32x __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float32x __fminimum_numf32x (_Float32x __x, _Float32x __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float32x fmaximum_magf32x (_Float32x __x, _Float32x __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float32x __fmaximum_magf32x (_Float32x __x, _Float32x __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float32x fminimum_magf32x (_Float32x __x, _Float32x __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float32x __fminimum_magf32x (_Float32x __x, _Float32x __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float32x fmaximum_mag_numf32x (_Float32x __x, _Float32x __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float32x __fmaximum_mag_numf32x (_Float32x __x, _Float32x __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float32x fminimum_mag_numf32x (_Float32x __x, _Float32x __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float32x __fminimum_mag_numf32x (_Float32x __x, _Float32x __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern int totalorderf32x (const _Float32x *__x, const _Float32x *__y) __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__pure__));
extern int totalordermagf32x (const _Float32x *__x, const _Float32x *__y) __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__pure__));
extern _Float32x getpayloadf32x (const _Float32x *__x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32x __getpayloadf32x (const _Float32x *__x) __attribute__ ((__nothrow__ , __leaf__));
extern int setpayloadf32x (_Float32x *__x, _Float32x __payload) __attribute__ ((__nothrow__ , __leaf__));
extern int setpayloadsigf32x (_Float32x *__x, _Float32x __payload) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float64x acosf64x (_Float64x __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64x __acosf64x (_Float64x __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float64x asinf64x (_Float64x __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64x __asinf64x (_Float64x __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float64x atanf64x (_Float64x __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64x __atanf64x (_Float64x __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float64x atan2f64x (_Float64x __y, _Float64x __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64x __atan2f64x (_Float64x __y, _Float64x __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float64x cosf64x (_Float64x __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64x __cosf64x (_Float64x __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float64x sinf64x (_Float64x __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64x __sinf64x (_Float64x __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float64x tanf64x (_Float64x __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64x __tanf64x (_Float64x __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float64x coshf64x (_Float64x __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64x __coshf64x (_Float64x __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float64x sinhf64x (_Float64x __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64x __sinhf64x (_Float64x __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float64x tanhf64x (_Float64x __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64x __tanhf64x (_Float64x __x) __attribute__ ((__nothrow__ , __leaf__));
 extern void sincosf64x (_Float64x __x, _Float64x *__sinx, _Float64x *__cosx) __attribute__ ((__nothrow__ , __leaf__)); extern void __sincosf64x (_Float64x __x, _Float64x *__sinx, _Float64x *__cosx) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float64x acoshf64x (_Float64x __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64x __acoshf64x (_Float64x __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float64x asinhf64x (_Float64x __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64x __asinhf64x (_Float64x __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float64x atanhf64x (_Float64x __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64x __atanhf64x (_Float64x __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float64x expf64x (_Float64x __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64x __expf64x (_Float64x __x) __attribute__ ((__nothrow__ , __leaf__));
extern _Float64x frexpf64x (_Float64x __x, int *__exponent) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64x __frexpf64x (_Float64x __x, int *__exponent) __attribute__ ((__nothrow__ , __leaf__));
extern _Float64x ldexpf64x (_Float64x __x, int __exponent) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64x __ldexpf64x (_Float64x __x, int __exponent) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float64x logf64x (_Float64x __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64x __logf64x (_Float64x __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float64x log10f64x (_Float64x __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64x __log10f64x (_Float64x __x) __attribute__ ((__nothrow__ , __leaf__));
extern _Float64x modff64x (_Float64x __x, _Float64x *__iptr) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64x __modff64x (_Float64x __x, _Float64x *__iptr) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));
 extern _Float64x exp10f64x (_Float64x __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64x __exp10f64x (_Float64x __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float64x expm1f64x (_Float64x __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64x __expm1f64x (_Float64x __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float64x log1pf64x (_Float64x __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64x __log1pf64x (_Float64x __x) __attribute__ ((__nothrow__ , __leaf__));
extern _Float64x logbf64x (_Float64x __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64x __logbf64x (_Float64x __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float64x exp2f64x (_Float64x __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64x __exp2f64x (_Float64x __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float64x log2f64x (_Float64x __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64x __log2f64x (_Float64x __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float64x powf64x (_Float64x __x, _Float64x __y) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64x __powf64x (_Float64x __x, _Float64x __y) __attribute__ ((__nothrow__ , __leaf__));
extern _Float64x sqrtf64x (_Float64x __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64x __sqrtf64x (_Float64x __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float64x hypotf64x (_Float64x __x, _Float64x __y) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64x __hypotf64x (_Float64x __x, _Float64x __y) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float64x cbrtf64x (_Float64x __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64x __cbrtf64x (_Float64x __x) __attribute__ ((__nothrow__ , __leaf__));
extern _Float64x ceilf64x (_Float64x __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float64x __ceilf64x (_Float64x __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float64x fabsf64x (_Float64x __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float64x __fabsf64x (_Float64x __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float64x floorf64x (_Float64x __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float64x __floorf64x (_Float64x __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float64x fmodf64x (_Float64x __x, _Float64x __y) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64x __fmodf64x (_Float64x __x, _Float64x __y) __attribute__ ((__nothrow__ , __leaf__));
extern _Float64x copysignf64x (_Float64x __x, _Float64x __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float64x __copysignf64x (_Float64x __x, _Float64x __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float64x nanf64x (const char *__tagb) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64x __nanf64x (const char *__tagb) __attribute__ ((__nothrow__ , __leaf__));
extern _Float64x j0f64x (_Float64x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64x __j0f64x (_Float64x) __attribute__ ((__nothrow__ , __leaf__));
extern _Float64x j1f64x (_Float64x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64x __j1f64x (_Float64x) __attribute__ ((__nothrow__ , __leaf__));
extern _Float64x jnf64x (int, _Float64x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64x __jnf64x (int, _Float64x) __attribute__ ((__nothrow__ , __leaf__));
extern _Float64x y0f64x (_Float64x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64x __y0f64x (_Float64x) __attribute__ ((__nothrow__ , __leaf__));
extern _Float64x y1f64x (_Float64x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64x __y1f64x (_Float64x) __attribute__ ((__nothrow__ , __leaf__));
extern _Float64x ynf64x (int, _Float64x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64x __ynf64x (int, _Float64x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float64x erff64x (_Float64x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64x __erff64x (_Float64x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float64x erfcf64x (_Float64x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64x __erfcf64x (_Float64x) __attribute__ ((__nothrow__ , __leaf__));
extern _Float64x lgammaf64x (_Float64x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64x __lgammaf64x (_Float64x) __attribute__ ((__nothrow__ , __leaf__));
extern _Float64x tgammaf64x (_Float64x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64x __tgammaf64x (_Float64x) __attribute__ ((__nothrow__ , __leaf__));
extern _Float64x lgammaf64x_r (_Float64x, int *__signgamp) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64x __lgammaf64x_r (_Float64x, int *__signgamp) __attribute__ ((__nothrow__ , __leaf__));
extern _Float64x rintf64x (_Float64x __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64x __rintf64x (_Float64x __x) __attribute__ ((__nothrow__ , __leaf__));
extern _Float64x nextafterf64x (_Float64x __x, _Float64x __y) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64x __nextafterf64x (_Float64x __x, _Float64x __y) __attribute__ ((__nothrow__ , __leaf__));
extern _Float64x nextdownf64x (_Float64x __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64x __nextdownf64x (_Float64x __x) __attribute__ ((__nothrow__ , __leaf__));
extern _Float64x nextupf64x (_Float64x __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64x __nextupf64x (_Float64x __x) __attribute__ ((__nothrow__ , __leaf__));
extern _Float64x remainderf64x (_Float64x __x, _Float64x __y) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64x __remainderf64x (_Float64x __x, _Float64x __y) __attribute__ ((__nothrow__ , __leaf__));
extern _Float64x scalbnf64x (_Float64x __x, int __n) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64x __scalbnf64x (_Float64x __x, int __n) __attribute__ ((__nothrow__ , __leaf__));
extern int ilogbf64x (_Float64x __x) __attribute__ ((__nothrow__ , __leaf__)); extern int __ilogbf64x (_Float64x __x) __attribute__ ((__nothrow__ , __leaf__));
extern long int llogbf64x (_Float64x __x) __attribute__ ((__nothrow__ , __leaf__)); extern long int __llogbf64x (_Float64x __x) __attribute__ ((__nothrow__ , __leaf__));
extern _Float64x scalblnf64x (_Float64x __x, long int __n) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64x __scalblnf64x (_Float64x __x, long int __n) __attribute__ ((__nothrow__ , __leaf__));
extern _Float64x nearbyintf64x (_Float64x __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64x __nearbyintf64x (_Float64x __x) __attribute__ ((__nothrow__ , __leaf__));
extern _Float64x roundf64x (_Float64x __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float64x __roundf64x (_Float64x __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float64x truncf64x (_Float64x __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float64x __truncf64x (_Float64x __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float64x remquof64x (_Float64x __x, _Float64x __y, int *__quo) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64x __remquof64x (_Float64x __x, _Float64x __y, int *__quo) __attribute__ ((__nothrow__ , __leaf__));
extern long int lrintf64x (_Float64x __x) __attribute__ ((__nothrow__ , __leaf__)); extern long int __lrintf64x (_Float64x __x) __attribute__ ((__nothrow__ , __leaf__));
__extension__
extern long long int llrintf64x (_Float64x __x) __attribute__ ((__nothrow__ , __leaf__)); extern long long int __llrintf64x (_Float64x __x) __attribute__ ((__nothrow__ , __leaf__));
extern long int lroundf64x (_Float64x __x) __attribute__ ((__nothrow__ , __leaf__)); extern long int __lroundf64x (_Float64x __x) __attribute__ ((__nothrow__ , __leaf__));
__extension__
extern long long int llroundf64x (_Float64x __x) __attribute__ ((__nothrow__ , __leaf__)); extern long long int __llroundf64x (_Float64x __x) __attribute__ ((__nothrow__ , __leaf__));
extern _Float64x fdimf64x (_Float64x __x, _Float64x __y) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64x __fdimf64x (_Float64x __x, _Float64x __y) __attribute__ ((__nothrow__ , __leaf__));
extern _Float64x fmaxf64x (_Float64x __x, _Float64x __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float64x __fmaxf64x (_Float64x __x, _Float64x __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float64x fminf64x (_Float64x __x, _Float64x __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float64x __fminf64x (_Float64x __x, _Float64x __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float64x fmaf64x (_Float64x __x, _Float64x __y, _Float64x __z) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64x __fmaf64x (_Float64x __x, _Float64x __y, _Float64x __z) __attribute__ ((__nothrow__ , __leaf__));
extern _Float64x roundevenf64x (_Float64x __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float64x __roundevenf64x (_Float64x __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern __intmax_t fromfpf64x (_Float64x __x, int __round, unsigned int __width) __attribute__ ((__nothrow__ , __leaf__)); extern __intmax_t __fromfpf64x (_Float64x __x, int __round, unsigned int __width) __attribute__ ((__nothrow__ , __leaf__));
extern __uintmax_t ufromfpf64x (_Float64x __x, int __round, unsigned int __width) __attribute__ ((__nothrow__ , __leaf__)); extern __uintmax_t __ufromfpf64x (_Float64x __x, int __round, unsigned int __width) __attribute__ ((__nothrow__ , __leaf__));
extern __intmax_t fromfpxf64x (_Float64x __x, int __round, unsigned int __width) __attribute__ ((__nothrow__ , __leaf__)); extern __intmax_t __fromfpxf64x (_Float64x __x, int __round, unsigned int __width) __attribute__ ((__nothrow__ , __leaf__));
extern __uintmax_t ufromfpxf64x (_Float64x __x, int __round, unsigned int __width) __attribute__ ((__nothrow__ , __leaf__)); extern __uintmax_t __ufromfpxf64x (_Float64x __x, int __round, unsigned int __width) __attribute__ ((__nothrow__ , __leaf__));
extern int canonicalizef64x (_Float64x *__cx, const _Float64x *__x) __attribute__ ((__nothrow__ , __leaf__));
extern _Float64x fmaxmagf64x (_Float64x __x, _Float64x __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float64x __fmaxmagf64x (_Float64x __x, _Float64x __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float64x fminmagf64x (_Float64x __x, _Float64x __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float64x __fminmagf64x (_Float64x __x, _Float64x __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float64x fmaximumf64x (_Float64x __x, _Float64x __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float64x __fmaximumf64x (_Float64x __x, _Float64x __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float64x fminimumf64x (_Float64x __x, _Float64x __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float64x __fminimumf64x (_Float64x __x, _Float64x __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float64x fmaximum_numf64x (_Float64x __x, _Float64x __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float64x __fmaximum_numf64x (_Float64x __x, _Float64x __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float64x fminimum_numf64x (_Float64x __x, _Float64x __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float64x __fminimum_numf64x (_Float64x __x, _Float64x __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float64x fmaximum_magf64x (_Float64x __x, _Float64x __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float64x __fmaximum_magf64x (_Float64x __x, _Float64x __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float64x fminimum_magf64x (_Float64x __x, _Float64x __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float64x __fminimum_magf64x (_Float64x __x, _Float64x __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float64x fmaximum_mag_numf64x (_Float64x __x, _Float64x __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float64x __fmaximum_mag_numf64x (_Float64x __x, _Float64x __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float64x fminimum_mag_numf64x (_Float64x __x, _Float64x __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float64x __fminimum_mag_numf64x (_Float64x __x, _Float64x __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern int totalorderf64x (const _Float64x *__x, const _Float64x *__y) __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__pure__));
extern int totalordermagf64x (const _Float64x *__x, const _Float64x *__y) __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__pure__));
extern _Float64x getpayloadf64x (const _Float64x *__x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64x __getpayloadf64x (const _Float64x *__x) __attribute__ ((__nothrow__ , __leaf__));
extern int setpayloadf64x (_Float64x *__x, _Float64x __payload) __attribute__ ((__nothrow__ , __leaf__));
extern int setpayloadsigf64x (_Float64x *__x, _Float64x __payload) __attribute__ ((__nothrow__ , __leaf__));
extern float fadd (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__));
extern float fdiv (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__));
extern float ffma (double __x, double __y, double __z) __attribute__ ((__nothrow__ , __leaf__));
extern float fmul (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__));
extern float fsqrt (double __x) __attribute__ ((__nothrow__ , __leaf__));
extern float fsub (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__));
extern float faddl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__));
extern float fdivl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__));
extern float ffmal (long double __x, long double __y, long double __z) __attribute__ ((__nothrow__ , __leaf__));
extern float fmull (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__));
extern float fsqrtl (long double __x) __attribute__ ((__nothrow__ , __leaf__));
extern float fsubl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__));
extern double daddl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__));
extern double ddivl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__));
extern double dfmal (long double __x, long double __y, long double __z) __attribute__ ((__nothrow__ , __leaf__));
extern double dmull (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__));
extern double dsqrtl (long double __x) __attribute__ ((__nothrow__ , __leaf__));
extern double dsubl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32 f32addf32x (_Float32x __x, _Float32x __y) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32 f32divf32x (_Float32x __x, _Float32x __y) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32 f32fmaf32x (_Float32x __x, _Float32x __y, _Float32x __z) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32 f32mulf32x (_Float32x __x, _Float32x __y) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32 f32sqrtf32x (_Float32x __x) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32 f32subf32x (_Float32x __x, _Float32x __y) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32 f32addf64 (_Float64 __x, _Float64 __y) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32 f32divf64 (_Float64 __x, _Float64 __y) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32 f32fmaf64 (_Float64 __x, _Float64 __y, _Float64 __z) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32 f32mulf64 (_Float64 __x, _Float64 __y) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32 f32sqrtf64 (_Float64 __x) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32 f32subf64 (_Float64 __x, _Float64 __y) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32 f32addf64x (_Float64x __x, _Float64x __y) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32 f32divf64x (_Float64x __x, _Float64x __y) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32 f32fmaf64x (_Float64x __x, _Float64x __y, _Float64x __z) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32 f32mulf64x (_Float64x __x, _Float64x __y) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32 f32sqrtf64x (_Float64x __x) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32 f32subf64x (_Float64x __x, _Float64x __y) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32 f32addf128 (_Float128 __x, _Float128 __y) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32 f32divf128 (_Float128 __x, _Float128 __y) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32 f32fmaf128 (_Float128 __x, _Float128 __y, _Float128 __z) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32 f32mulf128 (_Float128 __x, _Float128 __y) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32 f32sqrtf128 (_Float128 __x) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32 f32subf128 (_Float128 __x, _Float128 __y) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32x f32xaddf64 (_Float64 __x, _Float64 __y) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32x f32xdivf64 (_Float64 __x, _Float64 __y) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32x f32xfmaf64 (_Float64 __x, _Float64 __y, _Float64 __z) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32x f32xmulf64 (_Float64 __x, _Float64 __y) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32x f32xsqrtf64 (_Float64 __x) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32x f32xsubf64 (_Float64 __x, _Float64 __y) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32x f32xaddf64x (_Float64x __x, _Float64x __y) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32x f32xdivf64x (_Float64x __x, _Float64x __y) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32x f32xfmaf64x (_Float64x __x, _Float64x __y, _Float64x __z) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32x f32xmulf64x (_Float64x __x, _Float64x __y) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32x f32xsqrtf64x (_Float64x __x) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32x f32xsubf64x (_Float64x __x, _Float64x __y) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32x f32xaddf128 (_Float128 __x, _Float128 __y) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32x f32xdivf128 (_Float128 __x, _Float128 __y) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32x f32xfmaf128 (_Float128 __x, _Float128 __y, _Float128 __z) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32x f32xmulf128 (_Float128 __x, _Float128 __y) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32x f32xsqrtf128 (_Float128 __x) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32x f32xsubf128 (_Float128 __x, _Float128 __y) __attribute__ ((__nothrow__ , __leaf__));
extern _Float64 f64addf64x (_Float64x __x, _Float64x __y) __attribute__ ((__nothrow__ , __leaf__));
extern _Float64 f64divf64x (_Float64x __x, _Float64x __y) __attribute__ ((__nothrow__ , __leaf__));
extern _Float64 f64fmaf64x (_Float64x __x, _Float64x __y, _Float64x __z) __attribute__ ((__nothrow__ , __leaf__));
extern _Float64 f64mulf64x (_Float64x __x, _Float64x __y) __attribute__ ((__nothrow__ , __leaf__));
extern _Float64 f64sqrtf64x (_Float64x __x) __attribute__ ((__nothrow__ , __leaf__));
extern _Float64 f64subf64x (_Float64x __x, _Float64x __y) __attribute__ ((__nothrow__ , __leaf__));
extern _Float64 f64addf128 (_Float128 __x, _Float128 __y) __attribute__ ((__nothrow__ , __leaf__));
extern _Float64 f64divf128 (_Float128 __x, _Float128 __y) __attribute__ ((__nothrow__ , __leaf__));
extern _Float64 f64fmaf128 (_Float128 __x, _Float128 __y, _Float128 __z) __attribute__ ((__nothrow__ , __leaf__));
extern _Float64 f64mulf128 (_Float128 __x, _Float128 __y) __attribute__ ((__nothrow__ , __leaf__));
extern _Float64 f64sqrtf128 (_Float128 __x) __attribute__ ((__nothrow__ , __leaf__));
extern _Float64 f64subf128 (_Float128 __x, _Float128 __y) __attribute__ ((__nothrow__ , __leaf__));
extern _Float64x f64xaddf128 (_Float128 __x, _Float128 __y) __attribute__ ((__nothrow__ , __leaf__));
extern _Float64x f64xdivf128 (_Float128 __x, _Float128 __y) __attribute__ ((__nothrow__ , __leaf__));
extern _Float64x f64xfmaf128 (_Float128 __x, _Float128 __y, _Float128 __z) __attribute__ ((__nothrow__ , __leaf__));
extern _Float64x f64xmulf128 (_Float128 __x, _Float128 __y) __attribute__ ((__nothrow__ , __leaf__));
extern _Float64x f64xsqrtf128 (_Float128 __x) __attribute__ ((__nothrow__ , __leaf__));
extern _Float64x f64xsubf128 (_Float128 __x, _Float128 __y) __attribute__ ((__nothrow__ , __leaf__));
extern int signgam;
enum
  {
    FP_NAN =
      0,
    FP_INFINITE =
      1,
    FP_ZERO =
      2,
    FP_SUBNORMAL =
      3,
    FP_NORMAL =
      4
  };

struct sched_param
{
  int sched_priority;
};

extern int clone (int (*__fn) (void *__arg), void *__child_stack,
    int __flags, void *__arg, ...) __attribute__ ((__nothrow__ , __leaf__));
extern int unshare (int __flags) __attribute__ ((__nothrow__ , __leaf__));
extern int sched_getcpu (void) __attribute__ ((__nothrow__ , __leaf__));
extern int getcpu (unsigned int *, unsigned int *) __attribute__ ((__nothrow__ , __leaf__));
extern int setns (int __fd, int __nstype) __attribute__ ((__nothrow__ , __leaf__));

typedef unsigned long int __cpu_mask;
typedef struct
{
  __cpu_mask __bits[1024 / (8 * sizeof (__cpu_mask))];
} cpu_set_t;

extern int __sched_cpucount (size_t __setsize, const cpu_set_t *__setp)
     __attribute__ ((__nothrow__ , __leaf__));
extern cpu_set_t *__sched_cpualloc (size_t __count) __attribute__ ((__nothrow__ , __leaf__)) ;
extern void __sched_cpufree (cpu_set_t *__set) __attribute__ ((__nothrow__ , __leaf__));


extern int sched_setparam (__pid_t __pid, const struct sched_param *__param)
     __attribute__ ((__nothrow__ , __leaf__));
extern int sched_getparam (__pid_t __pid, struct sched_param *__param) __attribute__ ((__nothrow__ , __leaf__));
extern int sched_setscheduler (__pid_t __pid, int __policy,
          const struct sched_param *__param) __attribute__ ((__nothrow__ , __leaf__));
extern int sched_getscheduler (__pid_t __pid) __attribute__ ((__nothrow__ , __leaf__));
extern int sched_yield (void) __attribute__ ((__nothrow__ , __leaf__));
extern int sched_get_priority_max (int __algorithm) __attribute__ ((__nothrow__ , __leaf__));
extern int sched_get_priority_min (int __algorithm) __attribute__ ((__nothrow__ , __leaf__));
extern int sched_rr_get_interval (__pid_t __pid, struct timespec *__t) __attribute__ ((__nothrow__ , __leaf__));
extern int sched_setaffinity (__pid_t __pid, size_t __cpusetsize,
         const cpu_set_t *__cpuset) __attribute__ ((__nothrow__ , __leaf__));
extern int sched_getaffinity (__pid_t __pid, size_t __cpusetsize,
         cpu_set_t *__cpuset) __attribute__ ((__nothrow__ , __leaf__));

__extension__ typedef unsigned long long __jmp_buf [22];
struct __jmp_buf_tag
  {
    __jmp_buf __jmpbuf;
    int __mask_was_saved;
    __sigset_t __saved_mask;
  };

extern long int __sysconf (int __name) __attribute__ ((__nothrow__ , __leaf__));

enum
{
  PTHREAD_CREATE_JOINABLE,
  PTHREAD_CREATE_DETACHED
};
enum
{
  PTHREAD_MUTEX_TIMED_NP,
  PTHREAD_MUTEX_RECURSIVE_NP,
  PTHREAD_MUTEX_ERRORCHECK_NP,
  PTHREAD_MUTEX_ADAPTIVE_NP
  ,
  PTHREAD_MUTEX_NORMAL = PTHREAD_MUTEX_TIMED_NP,
  PTHREAD_MUTEX_RECURSIVE = PTHREAD_MUTEX_RECURSIVE_NP,
  PTHREAD_MUTEX_ERRORCHECK = PTHREAD_MUTEX_ERRORCHECK_NP,
  PTHREAD_MUTEX_DEFAULT = PTHREAD_MUTEX_NORMAL
  , PTHREAD_MUTEX_FAST_NP = PTHREAD_MUTEX_TIMED_NP
};
enum
{
  PTHREAD_MUTEX_STALLED,
  PTHREAD_MUTEX_STALLED_NP = PTHREAD_MUTEX_STALLED,
  PTHREAD_MUTEX_ROBUST,
  PTHREAD_MUTEX_ROBUST_NP = PTHREAD_MUTEX_ROBUST
};
enum
{
  PTHREAD_PRIO_NONE,
  PTHREAD_PRIO_INHERIT,
  PTHREAD_PRIO_PROTECT
};
enum
{
  PTHREAD_RWLOCK_PREFER_READER_NP,
  PTHREAD_RWLOCK_PREFER_WRITER_NP,
  PTHREAD_RWLOCK_PREFER_WRITER_NONRECURSIVE_NP,
  PTHREAD_RWLOCK_DEFAULT_NP = PTHREAD_RWLOCK_PREFER_READER_NP
};
enum
{
  PTHREAD_INHERIT_SCHED,
  PTHREAD_EXPLICIT_SCHED
};
enum
{
  PTHREAD_SCOPE_SYSTEM,
  PTHREAD_SCOPE_PROCESS
};
enum
{
  PTHREAD_PROCESS_PRIVATE,
  PTHREAD_PROCESS_SHARED
};
struct _pthread_cleanup_buffer
{
  void (*__routine) (void *);
  void *__arg;
  int __canceltype;
  struct _pthread_cleanup_buffer *__prev;
};
enum
{
  PTHREAD_CANCEL_ENABLE,
  PTHREAD_CANCEL_DISABLE
};
enum
{
  PTHREAD_CANCEL_DEFERRED,
  PTHREAD_CANCEL_ASYNCHRONOUS
};

extern int pthread_create (pthread_t *__restrict __newthread,
      const pthread_attr_t *__restrict __attr,
      void *(*__start_routine) (void *),
      void *__restrict __arg) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 3)));
extern void pthread_exit (void *__retval) __attribute__ ((__noreturn__));
extern int pthread_join (pthread_t __th, void **__thread_return);
extern int pthread_tryjoin_np (pthread_t __th, void **__thread_return) __attribute__ ((__nothrow__ , __leaf__));
extern int pthread_timedjoin_np (pthread_t __th, void **__thread_return,
     const struct timespec *__abstime);
extern int pthread_clockjoin_np (pthread_t __th, void **__thread_return,
                                 clockid_t __clockid,
     const struct timespec *__abstime);
extern int pthread_detach (pthread_t __th) __attribute__ ((__nothrow__ , __leaf__));
extern pthread_t pthread_self (void) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern int pthread_equal (pthread_t __thread1, pthread_t __thread2)
  __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern int pthread_attr_init (pthread_attr_t *__attr) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_attr_destroy (pthread_attr_t *__attr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_attr_getdetachstate (const pthread_attr_t *__attr,
     int *__detachstate)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int pthread_attr_setdetachstate (pthread_attr_t *__attr,
     int __detachstate)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_attr_getguardsize (const pthread_attr_t *__attr,
          size_t *__guardsize)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int pthread_attr_setguardsize (pthread_attr_t *__attr,
          size_t __guardsize)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_attr_getschedparam (const pthread_attr_t *__restrict __attr,
           struct sched_param *__restrict __param)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int pthread_attr_setschedparam (pthread_attr_t *__restrict __attr,
           const struct sched_param *__restrict
           __param) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int pthread_attr_getschedpolicy (const pthread_attr_t *__restrict
     __attr, int *__restrict __policy)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int pthread_attr_setschedpolicy (pthread_attr_t *__attr, int __policy)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_attr_getinheritsched (const pthread_attr_t *__restrict
      __attr, int *__restrict __inherit)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int pthread_attr_setinheritsched (pthread_attr_t *__attr,
      int __inherit)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_attr_getscope (const pthread_attr_t *__restrict __attr,
      int *__restrict __scope)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int pthread_attr_setscope (pthread_attr_t *__attr, int __scope)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_attr_getstackaddr (const pthread_attr_t *__restrict
          __attr, void **__restrict __stackaddr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2))) __attribute__ ((__deprecated__));
extern int pthread_attr_setstackaddr (pthread_attr_t *__attr,
          void *__stackaddr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) __attribute__ ((__deprecated__));
extern int pthread_attr_getstacksize (const pthread_attr_t *__restrict
          __attr, size_t *__restrict __stacksize)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int pthread_attr_setstacksize (pthread_attr_t *__attr,
          size_t __stacksize)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_attr_getstack (const pthread_attr_t *__restrict __attr,
      void **__restrict __stackaddr,
      size_t *__restrict __stacksize)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2, 3)));
extern int pthread_attr_setstack (pthread_attr_t *__attr, void *__stackaddr,
      size_t __stacksize) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_attr_setaffinity_np (pthread_attr_t *__attr,
     size_t __cpusetsize,
     const cpu_set_t *__cpuset)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 3)));
extern int pthread_attr_getaffinity_np (const pthread_attr_t *__attr,
     size_t __cpusetsize,
     cpu_set_t *__cpuset)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 3)));
extern int pthread_getattr_default_np (pthread_attr_t *__attr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_attr_setsigmask_np (pthread_attr_t *__attr,
           const __sigset_t *sigmask);
extern int pthread_attr_getsigmask_np (const pthread_attr_t *__attr,
           __sigset_t *sigmask);
extern int pthread_setattr_default_np (const pthread_attr_t *__attr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_getattr_np (pthread_t __th, pthread_attr_t *__attr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));
extern int pthread_setschedparam (pthread_t __target_thread, int __policy,
      const struct sched_param *__param)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3)));
extern int pthread_getschedparam (pthread_t __target_thread,
      int *__restrict __policy,
      struct sched_param *__restrict __param)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2, 3)));
extern int pthread_setschedprio (pthread_t __target_thread, int __prio)
     __attribute__ ((__nothrow__ , __leaf__));
extern int pthread_getname_np (pthread_t __target_thread, char *__buf,
          size_t __buflen)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));
extern int pthread_setname_np (pthread_t __target_thread, const char *__name)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));
extern int pthread_getconcurrency (void) __attribute__ ((__nothrow__ , __leaf__));
extern int pthread_setconcurrency (int __level) __attribute__ ((__nothrow__ , __leaf__));
extern int pthread_yield (void) __attribute__ ((__nothrow__ , __leaf__));
extern int pthread_yield (void) __asm__ ("" "sched_yield") __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__deprecated__ ("pthread_yield is deprecated, use sched_yield instead")));
extern int pthread_setaffinity_np (pthread_t __th, size_t __cpusetsize,
       const cpu_set_t *__cpuset)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3)));
extern int pthread_getaffinity_np (pthread_t __th, size_t __cpusetsize,
       cpu_set_t *__cpuset)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3)));
extern int pthread_once (pthread_once_t *__once_control,
    void (*__init_routine) (void)) __attribute__ ((__nonnull__ (1, 2)));
extern int pthread_setcancelstate (int __state, int *__oldstate);
extern int pthread_setcanceltype (int __type, int *__oldtype);
extern int pthread_cancel (pthread_t __th);
extern void pthread_testcancel (void);
struct __cancel_jmp_buf_tag
{
  __jmp_buf __cancel_jmp_buf;
  int __mask_was_saved;
};
typedef struct
{
  struct __cancel_jmp_buf_tag __cancel_jmp_buf[1];
  void *__pad[4];
} __pthread_unwind_buf_t __attribute__ ((__aligned__));
struct __pthread_cleanup_frame
{
  void (*__cancel_routine) (void *);
  void *__cancel_arg;
  int __do_it;
  int __cancel_type;
};
extern void __pthread_register_cancel (__pthread_unwind_buf_t *__buf)
     ;
extern void __pthread_unregister_cancel (__pthread_unwind_buf_t *__buf)
  ;
extern void __pthread_register_cancel_defer (__pthread_unwind_buf_t *__buf)
     ;
extern void __pthread_unregister_cancel_restore (__pthread_unwind_buf_t *__buf)
  ;
extern void __pthread_unwind_next (__pthread_unwind_buf_t *__buf)
     __attribute__ ((__noreturn__))
     __attribute__ ((__weak__))
     ;
extern int __sigsetjmp_cancel (struct __cancel_jmp_buf_tag __env[1], int __savemask) __asm__ ("" "__sigsetjmp") __attribute__ ((__nothrow__)) __attribute__ ((__returns_twice__));
extern int pthread_mutex_init (pthread_mutex_t *__mutex,
          const pthread_mutexattr_t *__mutexattr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_mutex_destroy (pthread_mutex_t *__mutex)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_mutex_trylock (pthread_mutex_t *__mutex)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_mutex_lock (pthread_mutex_t *__mutex)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_mutex_timedlock (pthread_mutex_t *__restrict __mutex,
        const struct timespec *__restrict
        __abstime) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));
extern int pthread_mutex_clocklock (pthread_mutex_t *__restrict __mutex,
        clockid_t __clockid,
        const struct timespec *__restrict
        __abstime) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 3)));
extern int pthread_mutex_unlock (pthread_mutex_t *__mutex)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_mutex_getprioceiling (const pthread_mutex_t *
      __restrict __mutex,
      int *__restrict __prioceiling)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int pthread_mutex_setprioceiling (pthread_mutex_t *__restrict __mutex,
      int __prioceiling,
      int *__restrict __old_ceiling)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 3)));
extern int pthread_mutex_consistent (pthread_mutex_t *__mutex)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_mutex_consistent_np (pthread_mutex_t *) __asm__ ("" "pthread_mutex_consistent") __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)))
  __attribute__ ((__deprecated__ ("pthread_mutex_consistent_np is deprecated, use pthread_mutex_consistent")));
extern int pthread_mutexattr_init (pthread_mutexattr_t *__attr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_mutexattr_destroy (pthread_mutexattr_t *__attr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_mutexattr_getpshared (const pthread_mutexattr_t *
      __restrict __attr,
      int *__restrict __pshared)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int pthread_mutexattr_setpshared (pthread_mutexattr_t *__attr,
      int __pshared)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_mutexattr_gettype (const pthread_mutexattr_t *__restrict
          __attr, int *__restrict __kind)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int pthread_mutexattr_settype (pthread_mutexattr_t *__attr, int __kind)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_mutexattr_getprotocol (const pthread_mutexattr_t *
       __restrict __attr,
       int *__restrict __protocol)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int pthread_mutexattr_setprotocol (pthread_mutexattr_t *__attr,
       int __protocol)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_mutexattr_getprioceiling (const pthread_mutexattr_t *
          __restrict __attr,
          int *__restrict __prioceiling)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int pthread_mutexattr_setprioceiling (pthread_mutexattr_t *__attr,
          int __prioceiling)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_mutexattr_getrobust (const pthread_mutexattr_t *__attr,
     int *__robustness)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int pthread_mutexattr_getrobust_np (pthread_mutexattr_t *, int *) __asm__ ("" "pthread_mutexattr_getrobust") __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)))
  __attribute__ ((__deprecated__ ("pthread_mutexattr_getrobust_np is deprecated, use pthread_mutexattr_getrobust")));
extern int pthread_mutexattr_setrobust (pthread_mutexattr_t *__attr,
     int __robustness)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_mutexattr_setrobust_np (pthread_mutexattr_t *, int) __asm__ ("" "pthread_mutexattr_setrobust") __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)))
  __attribute__ ((__deprecated__ ("pthread_mutexattr_setrobust_np is deprecated, use pthread_mutexattr_setrobust")));
extern int pthread_rwlock_init (pthread_rwlock_t *__restrict __rwlock,
    const pthread_rwlockattr_t *__restrict
    __attr) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_rwlock_destroy (pthread_rwlock_t *__rwlock)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_rwlock_rdlock (pthread_rwlock_t *__rwlock)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_rwlock_tryrdlock (pthread_rwlock_t *__rwlock)
  __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_rwlock_timedrdlock (pthread_rwlock_t *__restrict __rwlock,
           const struct timespec *__restrict
           __abstime) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));
extern int pthread_rwlock_clockrdlock (pthread_rwlock_t *__restrict __rwlock,
           clockid_t __clockid,
           const struct timespec *__restrict
           __abstime) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 3)));
extern int pthread_rwlock_wrlock (pthread_rwlock_t *__rwlock)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_rwlock_trywrlock (pthread_rwlock_t *__rwlock)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_rwlock_timedwrlock (pthread_rwlock_t *__restrict __rwlock,
           const struct timespec *__restrict
           __abstime) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));
extern int pthread_rwlock_clockwrlock (pthread_rwlock_t *__restrict __rwlock,
           clockid_t __clockid,
           const struct timespec *__restrict
           __abstime) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 3)));
extern int pthread_rwlock_unlock (pthread_rwlock_t *__rwlock)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_rwlockattr_init (pthread_rwlockattr_t *__attr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_rwlockattr_destroy (pthread_rwlockattr_t *__attr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_rwlockattr_getpshared (const pthread_rwlockattr_t *
       __restrict __attr,
       int *__restrict __pshared)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int pthread_rwlockattr_setpshared (pthread_rwlockattr_t *__attr,
       int __pshared)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_rwlockattr_getkind_np (const pthread_rwlockattr_t *
       __restrict __attr,
       int *__restrict __pref)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int pthread_rwlockattr_setkind_np (pthread_rwlockattr_t *__attr,
       int __pref) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_cond_init (pthread_cond_t *__restrict __cond,
         const pthread_condattr_t *__restrict __cond_attr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_cond_destroy (pthread_cond_t *__cond)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_cond_signal (pthread_cond_t *__cond)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_cond_broadcast (pthread_cond_t *__cond)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_cond_wait (pthread_cond_t *__restrict __cond,
         pthread_mutex_t *__restrict __mutex)
     __attribute__ ((__nonnull__ (1, 2)));
extern int pthread_cond_timedwait (pthread_cond_t *__restrict __cond,
       pthread_mutex_t *__restrict __mutex,
       const struct timespec *__restrict __abstime)
     __attribute__ ((__nonnull__ (1, 2, 3)));
extern int pthread_cond_clockwait (pthread_cond_t *__restrict __cond,
       pthread_mutex_t *__restrict __mutex,
       __clockid_t __clock_id,
       const struct timespec *__restrict __abstime)
     __attribute__ ((__nonnull__ (1, 2, 4)));
extern int pthread_condattr_init (pthread_condattr_t *__attr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_condattr_destroy (pthread_condattr_t *__attr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_condattr_getpshared (const pthread_condattr_t *
     __restrict __attr,
     int *__restrict __pshared)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int pthread_condattr_setpshared (pthread_condattr_t *__attr,
     int __pshared) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_condattr_getclock (const pthread_condattr_t *
          __restrict __attr,
          __clockid_t *__restrict __clock_id)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int pthread_condattr_setclock (pthread_condattr_t *__attr,
          __clockid_t __clock_id)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_spin_init (pthread_spinlock_t *__lock, int __pshared)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_spin_destroy (pthread_spinlock_t *__lock)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_spin_lock (pthread_spinlock_t *__lock)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_spin_trylock (pthread_spinlock_t *__lock)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_spin_unlock (pthread_spinlock_t *__lock)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_barrier_init (pthread_barrier_t *__restrict __barrier,
     const pthread_barrierattr_t *__restrict
     __attr, unsigned int __count)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_barrier_destroy (pthread_barrier_t *__barrier)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_barrier_wait (pthread_barrier_t *__barrier)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_barrierattr_init (pthread_barrierattr_t *__attr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_barrierattr_destroy (pthread_barrierattr_t *__attr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_barrierattr_getpshared (const pthread_barrierattr_t *
        __restrict __attr,
        int *__restrict __pshared)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int pthread_barrierattr_setpshared (pthread_barrierattr_t *__attr,
        int __pshared)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_key_create (pthread_key_t *__key,
          void (*__destr_function) (void *))
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_key_delete (pthread_key_t __key) __attribute__ ((__nothrow__ , __leaf__));
extern void *pthread_getspecific (pthread_key_t __key) __attribute__ ((__nothrow__ , __leaf__));
extern int pthread_setspecific (pthread_key_t __key,
    const void *__pointer)
  __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__access__ (__none__, 2)));
extern int pthread_getcpuclockid (pthread_t __thread_id,
      __clockid_t *__clock_id)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));
extern int pthread_atfork (void (*__prepare) (void),
      void (*__parent) (void),
      void (*__child) (void)) __attribute__ ((__nothrow__ , __leaf__));
extern __inline __attribute__ ((__gnu_inline__)) int
__attribute__ ((__nothrow__ , __leaf__)) pthread_equal (pthread_t __thread1, pthread_t __thread2)
{
  return __thread1 == __thread2;
}


typedef __sig_atomic_t sig_atomic_t;
union sigval
{
  int sival_int;
  void *sival_ptr;
};
typedef union sigval __sigval_t;
typedef struct
  {
    int si_signo;
    int si_errno;
    int si_code;
    int __pad0;
    union
      {
 int _pad[((128 / sizeof (int)) - 4)];
 struct
   {
     __pid_t si_pid;
     __uid_t si_uid;
   } _kill;
 struct
   {
     int si_tid;
     int si_overrun;
     __sigval_t si_sigval;
   } _timer;
 struct
   {
     __pid_t si_pid;
     __uid_t si_uid;
     __sigval_t si_sigval;
   } _rt;
 struct
   {
     __pid_t si_pid;
     __uid_t si_uid;
     int si_status;
     __clock_t si_utime;
     __clock_t si_stime;
   } _sigchld;
 struct
   {
     void *si_addr;
    
     short int si_addr_lsb;
     union
       {
  struct
    {
      void *_lower;
      void *_upper;
    } _addr_bnd;
  __uint32_t _pkey;
       } _bounds;
   } _sigfault;
 struct
   {
     long int si_band;
     int si_fd;
   } _sigpoll;
 struct
   {
     void *_call_addr;
     int _syscall;
     unsigned int _arch;
   } _sigsys;
      } _sifields;
  } siginfo_t ;
enum
{
  SI_ASYNCNL = -60,
  SI_DETHREAD = -7,
  SI_TKILL,
  SI_SIGIO,
  SI_ASYNCIO,
  SI_MESGQ,
  SI_TIMER,
  SI_QUEUE,
  SI_USER,
  SI_KERNEL = 0x80
};
enum
{
  ILL_ILLOPC = 1,
  ILL_ILLOPN,
  ILL_ILLADR,
  ILL_ILLTRP,
  ILL_PRVOPC,
  ILL_PRVREG,
  ILL_COPROC,
  ILL_BADSTK,
  ILL_BADIADDR
};
enum
{
  FPE_INTDIV = 1,
  FPE_INTOVF,
  FPE_FLTDIV,
  FPE_FLTOVF,
  FPE_FLTUND,
  FPE_FLTRES,
  FPE_FLTINV,
  FPE_FLTSUB,
  FPE_FLTUNK = 14,
  FPE_CONDTRAP
};
enum
{
  SEGV_MAPERR = 1,
  SEGV_ACCERR,
  SEGV_BNDERR,
  SEGV_PKUERR,
  SEGV_ACCADI,
  SEGV_ADIDERR,
  SEGV_ADIPERR,
  SEGV_MTEAERR,
  SEGV_MTESERR
};
enum
{
  BUS_ADRALN = 1,
  BUS_ADRERR,
  BUS_OBJERR,
  BUS_MCEERR_AR,
  BUS_MCEERR_AO
};
enum
{
  TRAP_BRKPT = 1,
  TRAP_TRACE,
  TRAP_BRANCH,
  TRAP_HWBKPT,
  TRAP_UNK
};
enum
{
  CLD_EXITED = 1,
  CLD_KILLED,
  CLD_DUMPED,
  CLD_TRAPPED,
  CLD_STOPPED,
  CLD_CONTINUED
};
enum
{
  POLL_IN = 1,
  POLL_OUT,
  POLL_MSG,
  POLL_ERR,
  POLL_PRI,
  POLL_HUP
};
typedef __sigval_t sigval_t;
typedef struct sigevent
  {
    __sigval_t sigev_value;
    int sigev_signo;
    int sigev_notify;
    union
      {
 int _pad[((64 / sizeof (int)) - 4)];
 __pid_t _tid;
 struct
   {
     void (*_function) (__sigval_t);
     pthread_attr_t *_attribute;
   } _sigev_thread;
      } _sigev_un;
  } sigevent_t;
enum
{
  SIGEV_SIGNAL = 0,
  SIGEV_NONE,
  SIGEV_THREAD,
  SIGEV_THREAD_ID = 4
};
typedef void (*__sighandler_t) (int);
extern __sighandler_t __sysv_signal (int __sig, __sighandler_t __handler)
     __attribute__ ((__nothrow__ , __leaf__));
extern __sighandler_t sysv_signal (int __sig, __sighandler_t __handler)
     __attribute__ ((__nothrow__ , __leaf__));
extern __sighandler_t signal (int __sig, __sighandler_t __handler)
     __attribute__ ((__nothrow__ , __leaf__));
extern int kill (__pid_t __pid, int __sig) __attribute__ ((__nothrow__ , __leaf__));
extern int killpg (__pid_t __pgrp, int __sig) __attribute__ ((__nothrow__ , __leaf__));
extern int raise (int __sig) __attribute__ ((__nothrow__ , __leaf__));
extern __sighandler_t ssignal (int __sig, __sighandler_t __handler)
     __attribute__ ((__nothrow__ , __leaf__));
extern int gsignal (int __sig) __attribute__ ((__nothrow__ , __leaf__));
extern void psignal (int __sig, const char *__s);
extern void psiginfo (const siginfo_t *__pinfo, const char *__s);
extern int sigpause (int __sig) __asm__ ("__xpg_sigpause")
  __attribute__ ((__deprecated__ ("Use the sigsuspend function instead")));
extern int sigblock (int __mask) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__deprecated__));
extern int sigsetmask (int __mask) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__deprecated__));
extern int siggetmask (void) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__deprecated__));
typedef __sighandler_t sighandler_t;
typedef __sighandler_t sig_t;
extern int sigemptyset (sigset_t *__set) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int sigfillset (sigset_t *__set) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int sigaddset (sigset_t *__set, int __signo) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int sigdelset (sigset_t *__set, int __signo) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int sigismember (const sigset_t *__set, int __signo)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int sigisemptyset (const sigset_t *__set) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int sigandset (sigset_t *__set, const sigset_t *__left,
        const sigset_t *__right) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2, 3)));
extern int sigorset (sigset_t *__set, const sigset_t *__left,
       const sigset_t *__right) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2, 3)));
struct sigaction
  {
    union
      {
 __sighandler_t sa_handler;
 void (*sa_sigaction) (int, siginfo_t *, void *);
      }
    __sigaction_handler;
    __sigset_t sa_mask;
    int sa_flags;
    void (*sa_restorer) (void);
  };
extern int sigprocmask (int __how, const sigset_t *__restrict __set,
   sigset_t *__restrict __oset) __attribute__ ((__nothrow__ , __leaf__));
extern int sigsuspend (const sigset_t *__set) __attribute__ ((__nonnull__ (1)));
extern int sigaction (int __sig, const struct sigaction *__restrict __act,
        struct sigaction *__restrict __oact) __attribute__ ((__nothrow__ , __leaf__));
extern int sigpending (sigset_t *__set) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int sigwait (const sigset_t *__restrict __set, int *__restrict __sig)
     __attribute__ ((__nonnull__ (1, 2)));
extern int sigwaitinfo (const sigset_t *__restrict __set,
   siginfo_t *__restrict __info) __attribute__ ((__nonnull__ (1)));
extern int sigtimedwait (const sigset_t *__restrict __set,
    siginfo_t *__restrict __info,
    const struct timespec *__restrict __timeout)
     __attribute__ ((__nonnull__ (1)));
extern int sigqueue (__pid_t __pid, int __sig, const union sigval __val)
     __attribute__ ((__nothrow__ , __leaf__));
typedef __signed__ char __s8;
typedef unsigned char __u8;
typedef __signed__ short __s16;
typedef unsigned short __u16;
typedef __signed__ int __s32;
typedef unsigned int __u32;
__extension__ typedef __signed__ long long __s64;
__extension__ typedef unsigned long long __u64;
typedef struct {
 unsigned long fds_bits[1024 / (8 * sizeof(long))];
} __kernel_fd_set;
typedef void (*__kernel_sighandler_t)(int);
typedef int __kernel_key_t;
typedef int __kernel_mqd_t;
typedef unsigned short __kernel_old_uid_t;
typedef unsigned short __kernel_old_gid_t;
typedef long __kernel_long_t;
typedef unsigned long __kernel_ulong_t;
typedef __kernel_ulong_t __kernel_ino_t;
typedef unsigned int __kernel_mode_t;
typedef int __kernel_pid_t;
typedef int __kernel_ipc_pid_t;
typedef unsigned int __kernel_uid_t;
typedef unsigned int __kernel_gid_t;
typedef __kernel_long_t __kernel_suseconds_t;
typedef int __kernel_daddr_t;
typedef unsigned int __kernel_uid32_t;
typedef unsigned int __kernel_gid32_t;
typedef unsigned int __kernel_old_dev_t;
typedef __kernel_ulong_t __kernel_size_t;
typedef __kernel_long_t __kernel_ssize_t;
typedef __kernel_long_t __kernel_ptrdiff_t;
typedef struct {
 int val[2];
} __kernel_fsid_t;
typedef __kernel_long_t __kernel_off_t;
typedef long long __kernel_loff_t;
typedef __kernel_long_t __kernel_old_time_t;
typedef __kernel_long_t __kernel_time_t;
typedef long long __kernel_time64_t;
typedef __kernel_long_t __kernel_clock_t;
typedef int __kernel_timer_t;
typedef int __kernel_clockid_t;
typedef char * __kernel_caddr_t;
typedef unsigned short __kernel_uid16_t;
typedef unsigned short __kernel_gid16_t;
typedef __u16 __le16;
typedef __u16 __be16;
typedef __u32 __le32;
typedef __u32 __be32;
typedef __u64 __le64;
typedef __u64 __be64;
typedef __u16 __sum16;
typedef __u32 __wsum;
typedef unsigned __poll_t;
struct sigcontext {
 __u64 fault_address;
 __u64 regs[31];
 __u64 sp;
 __u64 pc;
 __u64 pstate;
 __u8 __reserved[4096] __attribute__((__aligned__(16)));
};
struct _aarch64_ctx {
 __u32 magic;
 __u32 size;
};
struct fpsimd_context {
 struct _aarch64_ctx head;
 __u32 fpsr;
 __u32 fpcr;
 __uint128_t vregs[32];
};
struct esr_context {
 struct _aarch64_ctx head;
 __u64 esr;
};
struct extra_context {
 struct _aarch64_ctx head;
 __u64 datap;
 __u32 size;
 __u32 __reserved[3];
};
struct sve_context {
 struct _aarch64_ctx head;
 __u16 vl;
 __u16 flags;
 __u16 __reserved[2];
};
struct za_context {
 struct _aarch64_ctx head;
 __u16 vl;
 __u16 __reserved[3];
};
extern int sigreturn (struct sigcontext *__scp) __attribute__ ((__nothrow__ , __leaf__));
typedef struct
  {
    void *ss_sp;
    int ss_flags;
    size_t ss_size;
  } stack_t;

struct timezone
  {
    int tz_minuteswest;
    int tz_dsttime;
  };
extern int gettimeofday (struct timeval *__restrict __tv,
    void *__restrict __tz) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int settimeofday (const struct timeval *__tv,
    const struct timezone *__tz)
     __attribute__ ((__nothrow__ , __leaf__));
extern int adjtime (const struct timeval *__delta,
      struct timeval *__olddelta) __attribute__ ((__nothrow__ , __leaf__));
enum __itimer_which
  {
    ITIMER_REAL = 0,
    ITIMER_VIRTUAL = 1,
    ITIMER_PROF = 2
  };
struct itimerval
  {
    struct timeval it_interval;
    struct timeval it_value;
  };
typedef enum __itimer_which __itimer_which_t;
extern int getitimer (__itimer_which_t __which,
        struct itimerval *__value) __attribute__ ((__nothrow__ , __leaf__));
extern int setitimer (__itimer_which_t __which,
        const struct itimerval *__restrict __new,
        struct itimerval *__restrict __old) __attribute__ ((__nothrow__ , __leaf__));
extern int utimes (const char *__file, const struct timeval __tvp[2])
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int lutimes (const char *__file, const struct timeval __tvp[2])
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int futimes (int __fd, const struct timeval __tvp[2]) __attribute__ ((__nothrow__ , __leaf__));
extern int futimesat (int __fd, const char *__file,
        const struct timeval __tvp[2]) __attribute__ ((__nothrow__ , __leaf__));

struct user_regs_struct
{
  unsigned long long regs[31];
  unsigned long long sp;
  unsigned long long pc;
  unsigned long long pstate;
};
struct user_fpsimd_struct
{
  __uint128_t vregs[32];
  unsigned int fpsr;
  unsigned int fpcr;
};
typedef __uint64_t elf_greg_t;
typedef elf_greg_t elf_gregset_t[(sizeof (struct user_regs_struct) / sizeof (elf_greg_t))];
typedef struct user_fpsimd_struct elf_fpregset_t;
typedef unsigned int __pr_uid_t;
typedef unsigned int __pr_gid_t;

struct elf_siginfo
  {
    int si_signo;
    int si_code;
    int si_errno;
  };
struct elf_prstatus
  {
    struct elf_siginfo pr_info;
    short int pr_cursig;
    unsigned long int pr_sigpend;
    unsigned long int pr_sighold;
    __pid_t pr_pid;
    __pid_t pr_ppid;
    __pid_t pr_pgrp;
    __pid_t pr_sid;
    struct timeval pr_utime;
    struct timeval pr_stime;
    struct timeval pr_cutime;
    struct timeval pr_cstime;
    elf_gregset_t pr_reg;
    int pr_fpvalid;
  };
struct elf_prpsinfo
  {
    char pr_state;
    char pr_sname;
    char pr_zomb;
    char pr_nice;
    unsigned long int pr_flag;
    __pr_uid_t pr_uid;
    __pr_gid_t pr_gid;
    int pr_pid, pr_ppid, pr_pgrp, pr_sid;
    char pr_fname[16];
    char pr_psargs[(80)];
  };
typedef void *psaddr_t;
typedef elf_gregset_t __prgregset_t;
typedef elf_fpregset_t __prfpregset_t;
typedef __prgregset_t prgregset_t;
typedef __prfpregset_t prfpregset_t;
typedef __pid_t lwpid_t;
typedef struct elf_prstatus prstatus_t;
typedef struct elf_prpsinfo prpsinfo_t;

typedef elf_greg_t greg_t;
typedef elf_gregset_t gregset_t;
typedef elf_fpregset_t fpregset_t;
typedef struct
  {
    unsigned long long int fault_address;
    unsigned long long int regs[31];
    unsigned long long int sp;
    unsigned long long int pc;
    unsigned long long int pstate;
    unsigned char __reserved[4096] __attribute__ ((__aligned__ (16)));
  } mcontext_t;
typedef struct ucontext_t
  {
    unsigned long uc_flags;
    struct ucontext_t *uc_link;
    stack_t uc_stack;
    sigset_t uc_sigmask;
    mcontext_t uc_mcontext;
  } ucontext_t;
extern int siginterrupt (int __sig, int __interrupt) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__deprecated__ ("Use sigaction with SA_RESTART instead")));

typedef __intptr_t intptr_t;
typedef __socklen_t socklen_t;
extern int access (const char *__name, int __type) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int euidaccess (const char *__name, int __type)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int eaccess (const char *__name, int __type)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int execveat (int __fd, const char *__path, char *const __argv[],
                     char *const __envp[], int __flags)
    __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2, 3)));
extern int faccessat (int __fd, const char *__file, int __type, int __flag)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2))) ;
extern __off_t lseek (int __fd, __off_t __offset, int __whence) __attribute__ ((__nothrow__ , __leaf__));
extern __off64_t lseek64 (int __fd, __off64_t __offset, int __whence)
     __attribute__ ((__nothrow__ , __leaf__));
extern int close (int __fd);
extern void closefrom (int __lowfd) __attribute__ ((__nothrow__ , __leaf__));
extern ssize_t read (int __fd, void *__buf, size_t __nbytes)
    __attribute__ ((__access__ (__write_only__, 2, 3)));
extern ssize_t write (int __fd, const void *__buf, size_t __n)
    __attribute__ ((__access__ (__read_only__, 2, 3)));
extern ssize_t pread (int __fd, void *__buf, size_t __nbytes,
        __off_t __offset)
    __attribute__ ((__access__ (__write_only__, 2, 3)));
extern ssize_t pwrite (int __fd, const void *__buf, size_t __n,
         __off_t __offset)
    __attribute__ ((__access__ (__read_only__, 2, 3)));
extern ssize_t pread64 (int __fd, void *__buf, size_t __nbytes,
   __off64_t __offset)
    __attribute__ ((__access__ (__write_only__, 2, 3)));
extern ssize_t pwrite64 (int __fd, const void *__buf, size_t __n,
    __off64_t __offset)
    __attribute__ ((__access__ (__read_only__, 2, 3)));
extern int pipe (int __pipedes[2]) __attribute__ ((__nothrow__ , __leaf__)) ;
extern int pipe2 (int __pipedes[2], int __flags) __attribute__ ((__nothrow__ , __leaf__)) ;
extern unsigned int alarm (unsigned int __seconds) __attribute__ ((__nothrow__ , __leaf__));
extern unsigned int sleep (unsigned int __seconds);
extern __useconds_t ualarm (__useconds_t __value, __useconds_t __interval)
     __attribute__ ((__nothrow__ , __leaf__));
extern int usleep (__useconds_t __useconds);
extern int pause (void);
extern int chown (const char *__file, __uid_t __owner, __gid_t __group)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) ;
extern int fchown (int __fd, __uid_t __owner, __gid_t __group) __attribute__ ((__nothrow__ , __leaf__)) ;
extern int lchown (const char *__file, __uid_t __owner, __gid_t __group)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) ;
extern int fchownat (int __fd, const char *__file, __uid_t __owner,
       __gid_t __group, int __flag)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2))) ;
extern int chdir (const char *__path) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) ;
extern int fchdir (int __fd) __attribute__ ((__nothrow__ , __leaf__)) ;
extern char *getcwd (char *__buf, size_t __size) __attribute__ ((__nothrow__ , __leaf__)) ;
extern char *get_current_dir_name (void) __attribute__ ((__nothrow__ , __leaf__));
extern char *getwd (char *__buf)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) __attribute__ ((__deprecated__))
    __attribute__ ((__access__ (__write_only__, 1)));
extern int dup (int __fd) __attribute__ ((__nothrow__ , __leaf__)) ;
extern int dup2 (int __fd, int __fd2) __attribute__ ((__nothrow__ , __leaf__));
extern int dup3 (int __fd, int __fd2, int __flags) __attribute__ ((__nothrow__ , __leaf__));
extern char **__environ;
extern char **environ;
extern int execve (const char *__path, char *const __argv[],
     char *const __envp[]) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int fexecve (int __fd, char *const __argv[], char *const __envp[])
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));
extern int execv (const char *__path, char *const __argv[])
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int execle (const char *__path, const char *__arg, ...)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int execl (const char *__path, const char *__arg, ...)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int execvp (const char *__file, char *const __argv[])
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int execlp (const char *__file, const char *__arg, ...)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int execvpe (const char *__file, char *const __argv[],
      char *const __envp[])
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int nice (int __inc) __attribute__ ((__nothrow__ , __leaf__)) ;
extern void _exit (int __status) __attribute__ ((__noreturn__));
enum
  {
    _PC_LINK_MAX,
    _PC_MAX_CANON,
    _PC_MAX_INPUT,
    _PC_NAME_MAX,
    _PC_PATH_MAX,
    _PC_PIPE_BUF,
    _PC_CHOWN_RESTRICTED,
    _PC_NO_TRUNC,
    _PC_VDISABLE,
    _PC_SYNC_IO,
    _PC_ASYNC_IO,
    _PC_PRIO_IO,
    _PC_SOCK_MAXBUF,
    _PC_FILESIZEBITS,
    _PC_REC_INCR_XFER_SIZE,
    _PC_REC_MAX_XFER_SIZE,
    _PC_REC_MIN_XFER_SIZE,
    _PC_REC_XFER_ALIGN,
    _PC_ALLOC_SIZE_MIN,
    _PC_SYMLINK_MAX,
    _PC_2_SYMLINKS
  };
enum
  {
    _SC_ARG_MAX,
    _SC_CHILD_MAX,
    _SC_CLK_TCK,
    _SC_NGROUPS_MAX,
    _SC_OPEN_MAX,
    _SC_STREAM_MAX,
    _SC_TZNAME_MAX,
    _SC_JOB_CONTROL,
    _SC_SAVED_IDS,
    _SC_REALTIME_SIGNALS,
    _SC_PRIORITY_SCHEDULING,
    _SC_TIMERS,
    _SC_ASYNCHRONOUS_IO,
    _SC_PRIORITIZED_IO,
    _SC_SYNCHRONIZED_IO,
    _SC_FSYNC,
    _SC_MAPPED_FILES,
    _SC_MEMLOCK,
    _SC_MEMLOCK_RANGE,
    _SC_MEMORY_PROTECTION,
    _SC_MESSAGE_PASSING,
    _SC_SEMAPHORES,
    _SC_SHARED_MEMORY_OBJECTS,
    _SC_AIO_LISTIO_MAX,
    _SC_AIO_MAX,
    _SC_AIO_PRIO_DELTA_MAX,
    _SC_DELAYTIMER_MAX,
    _SC_MQ_OPEN_MAX,
    _SC_MQ_PRIO_MAX,
    _SC_VERSION,
    _SC_PAGESIZE,
    _SC_RTSIG_MAX,
    _SC_SEM_NSEMS_MAX,
    _SC_SEM_VALUE_MAX,
    _SC_SIGQUEUE_MAX,
    _SC_TIMER_MAX,
    _SC_BC_BASE_MAX,
    _SC_BC_DIM_MAX,
    _SC_BC_SCALE_MAX,
    _SC_BC_STRING_MAX,
    _SC_COLL_WEIGHTS_MAX,
    _SC_EQUIV_CLASS_MAX,
    _SC_EXPR_NEST_MAX,
    _SC_LINE_MAX,
    _SC_RE_DUP_MAX,
    _SC_CHARCLASS_NAME_MAX,
    _SC_2_VERSION,
    _SC_2_C_BIND,
    _SC_2_C_DEV,
    _SC_2_FORT_DEV,
    _SC_2_FORT_RUN,
    _SC_2_SW_DEV,
    _SC_2_LOCALEDEF,
    _SC_PII,
    _SC_PII_XTI,
    _SC_PII_SOCKET,
    _SC_PII_INTERNET,
    _SC_PII_OSI,
    _SC_POLL,
    _SC_SELECT,
    _SC_UIO_MAXIOV,
    _SC_IOV_MAX = _SC_UIO_MAXIOV,
    _SC_PII_INTERNET_STREAM,
    _SC_PII_INTERNET_DGRAM,
    _SC_PII_OSI_COTS,
    _SC_PII_OSI_CLTS,
    _SC_PII_OSI_M,
    _SC_T_IOV_MAX,
    _SC_THREADS,
    _SC_THREAD_SAFE_FUNCTIONS,
    _SC_GETGR_R_SIZE_MAX,
    _SC_GETPW_R_SIZE_MAX,
    _SC_LOGIN_NAME_MAX,
    _SC_TTY_NAME_MAX,
    _SC_THREAD_DESTRUCTOR_ITERATIONS,
    _SC_THREAD_KEYS_MAX,
    _SC_THREAD_STACK_MIN,
    _SC_THREAD_THREADS_MAX,
    _SC_THREAD_ATTR_STACKADDR,
    _SC_THREAD_ATTR_STACKSIZE,
    _SC_THREAD_PRIORITY_SCHEDULING,
    _SC_THREAD_PRIO_INHERIT,
    _SC_THREAD_PRIO_PROTECT,
    _SC_THREAD_PROCESS_SHARED,
    _SC_NPROCESSORS_CONF,
    _SC_NPROCESSORS_ONLN,
    _SC_PHYS_PAGES,
    _SC_AVPHYS_PAGES,
    _SC_ATEXIT_MAX,
    _SC_PASS_MAX,
    _SC_XOPEN_VERSION,
    _SC_XOPEN_XCU_VERSION,
    _SC_XOPEN_UNIX,
    _SC_XOPEN_CRYPT,
    _SC_XOPEN_ENH_I18N,
    _SC_XOPEN_SHM,
    _SC_2_CHAR_TERM,
    _SC_2_C_VERSION,
    _SC_2_UPE,
    _SC_XOPEN_XPG2,
    _SC_XOPEN_XPG3,
    _SC_XOPEN_XPG4,
    _SC_CHAR_BIT,
    _SC_CHAR_MAX,
    _SC_CHAR_MIN,
    _SC_INT_MAX,
    _SC_INT_MIN,
    _SC_LONG_BIT,
    _SC_WORD_BIT,
    _SC_MB_LEN_MAX,
    _SC_NZERO,
    _SC_SSIZE_MAX,
    _SC_SCHAR_MAX,
    _SC_SCHAR_MIN,
    _SC_SHRT_MAX,
    _SC_SHRT_MIN,
    _SC_UCHAR_MAX,
    _SC_UINT_MAX,
    _SC_ULONG_MAX,
    _SC_USHRT_MAX,
    _SC_NL_ARGMAX,
    _SC_NL_LANGMAX,
    _SC_NL_MSGMAX,
    _SC_NL_NMAX,
    _SC_NL_SETMAX,
    _SC_NL_TEXTMAX,
    _SC_XBS5_ILP32_OFF32,
    _SC_XBS5_ILP32_OFFBIG,
    _SC_XBS5_LP64_OFF64,
    _SC_XBS5_LPBIG_OFFBIG,
    _SC_XOPEN_LEGACY,
    _SC_XOPEN_REALTIME,
    _SC_XOPEN_REALTIME_THREADS,
    _SC_ADVISORY_INFO,
    _SC_BARRIERS,
    _SC_BASE,
    _SC_C_LANG_SUPPORT,
    _SC_C_LANG_SUPPORT_R,
    _SC_CLOCK_SELECTION,
    _SC_CPUTIME,
    _SC_THREAD_CPUTIME,
    _SC_DEVICE_IO,
    _SC_DEVICE_SPECIFIC,
    _SC_DEVICE_SPECIFIC_R,
    _SC_FD_MGMT,
    _SC_FIFO,
    _SC_PIPE,
    _SC_FILE_ATTRIBUTES,
    _SC_FILE_LOCKING,
    _SC_FILE_SYSTEM,
    _SC_MONOTONIC_CLOCK,
    _SC_MULTI_PROCESS,
    _SC_SINGLE_PROCESS,
    _SC_NETWORKING,
    _SC_READER_WRITER_LOCKS,
    _SC_SPIN_LOCKS,
    _SC_REGEXP,
    _SC_REGEX_VERSION,
    _SC_SHELL,
    _SC_SIGNALS,
    _SC_SPAWN,
    _SC_SPORADIC_SERVER,
    _SC_THREAD_SPORADIC_SERVER,
    _SC_SYSTEM_DATABASE,
    _SC_SYSTEM_DATABASE_R,
    _SC_TIMEOUTS,
    _SC_TYPED_MEMORY_OBJECTS,
    _SC_USER_GROUPS,
    _SC_USER_GROUPS_R,
    _SC_2_PBS,
    _SC_2_PBS_ACCOUNTING,
    _SC_2_PBS_LOCATE,
    _SC_2_PBS_MESSAGE,
    _SC_2_PBS_TRACK,
    _SC_SYMLOOP_MAX,
    _SC_STREAMS,
    _SC_2_PBS_CHECKPOINT,
    _SC_V6_ILP32_OFF32,
    _SC_V6_ILP32_OFFBIG,
    _SC_V6_LP64_OFF64,
    _SC_V6_LPBIG_OFFBIG,
    _SC_HOST_NAME_MAX,
    _SC_TRACE,
    _SC_TRACE_EVENT_FILTER,
    _SC_TRACE_INHERIT,
    _SC_TRACE_LOG,
    _SC_LEVEL1_ICACHE_SIZE,
    _SC_LEVEL1_ICACHE_ASSOC,
    _SC_LEVEL1_ICACHE_LINESIZE,
    _SC_LEVEL1_DCACHE_SIZE,
    _SC_LEVEL1_DCACHE_ASSOC,
    _SC_LEVEL1_DCACHE_LINESIZE,
    _SC_LEVEL2_CACHE_SIZE,
    _SC_LEVEL2_CACHE_ASSOC,
    _SC_LEVEL2_CACHE_LINESIZE,
    _SC_LEVEL3_CACHE_SIZE,
    _SC_LEVEL3_CACHE_ASSOC,
    _SC_LEVEL3_CACHE_LINESIZE,
    _SC_LEVEL4_CACHE_SIZE,
    _SC_LEVEL4_CACHE_ASSOC,
    _SC_LEVEL4_CACHE_LINESIZE,
    _SC_IPV6 = _SC_LEVEL1_ICACHE_SIZE + 50,
    _SC_RAW_SOCKETS,
    _SC_V7_ILP32_OFF32,
    _SC_V7_ILP32_OFFBIG,
    _SC_V7_LP64_OFF64,
    _SC_V7_LPBIG_OFFBIG,
    _SC_SS_REPL_MAX,
    _SC_TRACE_EVENT_NAME_MAX,
    _SC_TRACE_NAME_MAX,
    _SC_TRACE_SYS_MAX,
    _SC_TRACE_USER_EVENT_MAX,
    _SC_XOPEN_STREAMS,
    _SC_THREAD_ROBUST_PRIO_INHERIT,
    _SC_THREAD_ROBUST_PRIO_PROTECT,
    _SC_MINSIGSTKSZ,
    _SC_SIGSTKSZ
  };
enum
  {
    _CS_PATH,
    _CS_V6_WIDTH_RESTRICTED_ENVS,
    _CS_GNU_LIBC_VERSION,
    _CS_GNU_LIBPTHREAD_VERSION,
    _CS_V5_WIDTH_RESTRICTED_ENVS,
    _CS_V7_WIDTH_RESTRICTED_ENVS,
    _CS_LFS_CFLAGS = 1000,
    _CS_LFS_LDFLAGS,
    _CS_LFS_LIBS,
    _CS_LFS_LINTFLAGS,
    _CS_LFS64_CFLAGS,
    _CS_LFS64_LDFLAGS,
    _CS_LFS64_LIBS,
    _CS_LFS64_LINTFLAGS,
    _CS_XBS5_ILP32_OFF32_CFLAGS = 1100,
    _CS_XBS5_ILP32_OFF32_LDFLAGS,
    _CS_XBS5_ILP32_OFF32_LIBS,
    _CS_XBS5_ILP32_OFF32_LINTFLAGS,
    _CS_XBS5_ILP32_OFFBIG_CFLAGS,
    _CS_XBS5_ILP32_OFFBIG_LDFLAGS,
    _CS_XBS5_ILP32_OFFBIG_LIBS,
    _CS_XBS5_ILP32_OFFBIG_LINTFLAGS,
    _CS_XBS5_LP64_OFF64_CFLAGS,
    _CS_XBS5_LP64_OFF64_LDFLAGS,
    _CS_XBS5_LP64_OFF64_LIBS,
    _CS_XBS5_LP64_OFF64_LINTFLAGS,
    _CS_XBS5_LPBIG_OFFBIG_CFLAGS,
    _CS_XBS5_LPBIG_OFFBIG_LDFLAGS,
    _CS_XBS5_LPBIG_OFFBIG_LIBS,
    _CS_XBS5_LPBIG_OFFBIG_LINTFLAGS,
    _CS_POSIX_V6_ILP32_OFF32_CFLAGS,
    _CS_POSIX_V6_ILP32_OFF32_LDFLAGS,
    _CS_POSIX_V6_ILP32_OFF32_LIBS,
    _CS_POSIX_V6_ILP32_OFF32_LINTFLAGS,
    _CS_POSIX_V6_ILP32_OFFBIG_CFLAGS,
    _CS_POSIX_V6_ILP32_OFFBIG_LDFLAGS,
    _CS_POSIX_V6_ILP32_OFFBIG_LIBS,
    _CS_POSIX_V6_ILP32_OFFBIG_LINTFLAGS,
    _CS_POSIX_V6_LP64_OFF64_CFLAGS,
    _CS_POSIX_V6_LP64_OFF64_LDFLAGS,
    _CS_POSIX_V6_LP64_OFF64_LIBS,
    _CS_POSIX_V6_LP64_OFF64_LINTFLAGS,
    _CS_POSIX_V6_LPBIG_OFFBIG_CFLAGS,
    _CS_POSIX_V6_LPBIG_OFFBIG_LDFLAGS,
    _CS_POSIX_V6_LPBIG_OFFBIG_LIBS,
    _CS_POSIX_V6_LPBIG_OFFBIG_LINTFLAGS,
    _CS_POSIX_V7_ILP32_OFF32_CFLAGS,
    _CS_POSIX_V7_ILP32_OFF32_LDFLAGS,
    _CS_POSIX_V7_ILP32_OFF32_LIBS,
    _CS_POSIX_V7_ILP32_OFF32_LINTFLAGS,
    _CS_POSIX_V7_ILP32_OFFBIG_CFLAGS,
    _CS_POSIX_V7_ILP32_OFFBIG_LDFLAGS,
    _CS_POSIX_V7_ILP32_OFFBIG_LIBS,
    _CS_POSIX_V7_ILP32_OFFBIG_LINTFLAGS,
    _CS_POSIX_V7_LP64_OFF64_CFLAGS,
    _CS_POSIX_V7_LP64_OFF64_LDFLAGS,
    _CS_POSIX_V7_LP64_OFF64_LIBS,
    _CS_POSIX_V7_LP64_OFF64_LINTFLAGS,
    _CS_POSIX_V7_LPBIG_OFFBIG_CFLAGS,
    _CS_POSIX_V7_LPBIG_OFFBIG_LDFLAGS,
    _CS_POSIX_V7_LPBIG_OFFBIG_LIBS,
    _CS_POSIX_V7_LPBIG_OFFBIG_LINTFLAGS,
    _CS_V6_ENV,
    _CS_V7_ENV
  };
extern long int pathconf (const char *__path, int __name)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern long int fpathconf (int __fd, int __name) __attribute__ ((__nothrow__ , __leaf__));
extern long int sysconf (int __name) __attribute__ ((__nothrow__ , __leaf__));
extern size_t confstr (int __name, char *__buf, size_t __len) __attribute__ ((__nothrow__ , __leaf__))
    __attribute__ ((__access__ (__write_only__, 2, 3)));
extern __pid_t getpid (void) __attribute__ ((__nothrow__ , __leaf__));
extern __pid_t getppid (void) __attribute__ ((__nothrow__ , __leaf__));
extern __pid_t getpgrp (void) __attribute__ ((__nothrow__ , __leaf__));
extern __pid_t __getpgid (__pid_t __pid) __attribute__ ((__nothrow__ , __leaf__));
extern __pid_t getpgid (__pid_t __pid) __attribute__ ((__nothrow__ , __leaf__));
extern int setpgid (__pid_t __pid, __pid_t __pgid) __attribute__ ((__nothrow__ , __leaf__));
extern int setpgrp (void) __attribute__ ((__nothrow__ , __leaf__));
extern __pid_t setsid (void) __attribute__ ((__nothrow__ , __leaf__));
extern __pid_t getsid (__pid_t __pid) __attribute__ ((__nothrow__ , __leaf__));
extern __uid_t getuid (void) __attribute__ ((__nothrow__ , __leaf__));
extern __uid_t geteuid (void) __attribute__ ((__nothrow__ , __leaf__));
extern __gid_t getgid (void) __attribute__ ((__nothrow__ , __leaf__));
extern __gid_t getegid (void) __attribute__ ((__nothrow__ , __leaf__));
extern int getgroups (int __size, __gid_t __list[]) __attribute__ ((__nothrow__ , __leaf__))
    __attribute__ ((__access__ (__write_only__, 2, 1)));
extern int group_member (__gid_t __gid) __attribute__ ((__nothrow__ , __leaf__));
extern int setuid (__uid_t __uid) __attribute__ ((__nothrow__ , __leaf__)) ;
extern int setreuid (__uid_t __ruid, __uid_t __euid) __attribute__ ((__nothrow__ , __leaf__)) ;
extern int seteuid (__uid_t __uid) __attribute__ ((__nothrow__ , __leaf__)) ;
extern int setgid (__gid_t __gid) __attribute__ ((__nothrow__ , __leaf__)) ;
extern int setregid (__gid_t __rgid, __gid_t __egid) __attribute__ ((__nothrow__ , __leaf__)) ;
extern int setegid (__gid_t __gid) __attribute__ ((__nothrow__ , __leaf__)) ;
extern int getresuid (__uid_t *__ruid, __uid_t *__euid, __uid_t *__suid)
     __attribute__ ((__nothrow__ , __leaf__));
extern int getresgid (__gid_t *__rgid, __gid_t *__egid, __gid_t *__sgid)
     __attribute__ ((__nothrow__ , __leaf__));
extern int setresuid (__uid_t __ruid, __uid_t __euid, __uid_t __suid)
     __attribute__ ((__nothrow__ , __leaf__)) ;
extern int setresgid (__gid_t __rgid, __gid_t __egid, __gid_t __sgid)
     __attribute__ ((__nothrow__ , __leaf__)) ;
extern __pid_t fork (void) __attribute__ ((__nothrow__));
extern __pid_t vfork (void) __attribute__ ((__nothrow__ , __leaf__));
extern __pid_t _Fork (void) __attribute__ ((__nothrow__ , __leaf__));
extern char *ttyname (int __fd) __attribute__ ((__nothrow__ , __leaf__));
extern int ttyname_r (int __fd, char *__buf, size_t __buflen)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)))
     __attribute__ ((__access__ (__write_only__, 2, 3)));
extern int isatty (int __fd) __attribute__ ((__nothrow__ , __leaf__));
extern int ttyslot (void) __attribute__ ((__nothrow__ , __leaf__));
extern int link (const char *__from, const char *__to)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2))) ;
extern int linkat (int __fromfd, const char *__from, int __tofd,
     const char *__to, int __flags)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2, 4))) ;
extern int symlink (const char *__from, const char *__to)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2))) ;
extern ssize_t readlink (const char *__restrict __path,
    char *__restrict __buf, size_t __len)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)))
     __attribute__ ((__access__ (__write_only__, 2, 3)));
extern int symlinkat (const char *__from, int __tofd,
        const char *__to) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 3))) ;
extern ssize_t readlinkat (int __fd, const char *__restrict __path,
      char *__restrict __buf, size_t __len)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2, 3)))
     __attribute__ ((__access__ (__write_only__, 3, 4)));
extern int unlink (const char *__name) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int unlinkat (int __fd, const char *__name, int __flag)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));
extern int rmdir (const char *__path) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern __pid_t tcgetpgrp (int __fd) __attribute__ ((__nothrow__ , __leaf__));
extern int tcsetpgrp (int __fd, __pid_t __pgrp_id) __attribute__ ((__nothrow__ , __leaf__));
extern char *getlogin (void);
extern int getlogin_r (char *__name, size_t __name_len) __attribute__ ((__nonnull__ (1)))
    __attribute__ ((__access__ (__write_only__, 1, 2)));
extern int setlogin (const char *__name) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));

extern char *optarg;
extern int optind;
extern int opterr;
extern int optopt;
extern int getopt (int ___argc, char *const *___argv, const char *__shortopts)
       __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2, 3)));



extern int gethostname (char *__name, size_t __len) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)))
    __attribute__ ((__access__ (__write_only__, 1, 2)));
extern int sethostname (const char *__name, size_t __len)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) __attribute__ ((__access__ (__read_only__, 1, 2)));
extern int sethostid (long int __id) __attribute__ ((__nothrow__ , __leaf__)) ;
extern int getdomainname (char *__name, size_t __len)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)))
     __attribute__ ((__access__ (__write_only__, 1, 2)));
extern int setdomainname (const char *__name, size_t __len)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) __attribute__ ((__access__ (__read_only__, 1, 2)));
extern int vhangup (void) __attribute__ ((__nothrow__ , __leaf__));
extern int revoke (const char *__file) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) ;
extern int profil (unsigned short int *__sample_buffer, size_t __size,
     size_t __offset, unsigned int __scale)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int acct (const char *__name) __attribute__ ((__nothrow__ , __leaf__));
extern char *getusershell (void) __attribute__ ((__nothrow__ , __leaf__));
extern void endusershell (void) __attribute__ ((__nothrow__ , __leaf__));
extern void setusershell (void) __attribute__ ((__nothrow__ , __leaf__));
extern int daemon (int __nochdir, int __noclose) __attribute__ ((__nothrow__ , __leaf__)) ;
extern int chroot (const char *__path) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) ;
extern char *getpass (const char *__prompt) __attribute__ ((__nonnull__ (1)));
extern int fsync (int __fd);
extern int syncfs (int __fd) __attribute__ ((__nothrow__ , __leaf__));
extern long int gethostid (void);
extern void sync (void) __attribute__ ((__nothrow__ , __leaf__));
extern int getpagesize (void) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern int getdtablesize (void) __attribute__ ((__nothrow__ , __leaf__));
extern int truncate (const char *__file, __off_t __length)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) ;
extern int truncate64 (const char *__file, __off64_t __length)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) ;
extern int ftruncate (int __fd, __off_t __length) __attribute__ ((__nothrow__ , __leaf__)) ;
extern int ftruncate64 (int __fd, __off64_t __length) __attribute__ ((__nothrow__ , __leaf__)) ;
extern int brk (void *__addr) __attribute__ ((__nothrow__ , __leaf__)) ;
extern void *sbrk (intptr_t __delta) __attribute__ ((__nothrow__ , __leaf__));
extern long int syscall (long int __sysno, ...) __attribute__ ((__nothrow__ , __leaf__));
ssize_t copy_file_range (int __infd, __off64_t *__pinoff,
    int __outfd, __off64_t *__poutoff,
    size_t __length, unsigned int __flags);
extern int fdatasync (int __fildes);
extern char *crypt (const char *__key, const char *__salt)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern void swab (const void *__restrict __from, void *__restrict __to,
    ssize_t __n) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)))
    __attribute__ ((__access__ (__read_only__, 1, 3)))
    __attribute__ ((__access__ (__write_only__, 2, 3)));
int getentropy (void *__buffer, size_t __length)
    __attribute__ ((__access__ (__write_only__, 1, 2)));
extern int close_range (unsigned int __fd, unsigned int __max_fd,
   int __flags) __attribute__ ((__nothrow__ , __leaf__));
extern __pid_t gettid (void) __attribute__ ((__nothrow__ , __leaf__));

enum
{
  SS_ONSTACK = 1,
  SS_DISABLE
};
extern int sigaltstack (const stack_t *__restrict __ss,
   stack_t *__restrict __oss) __attribute__ ((__nothrow__ , __leaf__));
struct sigstack
  {
    void *ss_sp;
    int ss_onstack;
  };
extern int sigstack (struct sigstack *__ss, struct sigstack *__oss)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__deprecated__));
extern int sighold (int __sig) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__deprecated__ ("Use the sigprocmask function instead")));
extern int sigrelse (int __sig) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__deprecated__ ("Use the sigprocmask function instead")));
extern int sigignore (int __sig) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__deprecated__ ("Use the signal function instead")));
extern __sighandler_t sigset (int __sig, __sighandler_t __disp) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__deprecated__ ("Use the signal and sigprocmask functions instead")));
extern int pthread_sigmask (int __how,
       const __sigset_t *__restrict __newmask,
       __sigset_t *__restrict __oldmask)__attribute__ ((__nothrow__ , __leaf__));
extern int pthread_kill (pthread_t __threadid, int __signo) __attribute__ ((__nothrow__ , __leaf__));
extern int pthread_sigqueue (pthread_t __threadid, int __signo,
        const union sigval __value) __attribute__ ((__nothrow__ , __leaf__));
extern int __libc_current_sigrtmin (void) __attribute__ ((__nothrow__ , __leaf__));
extern int __libc_current_sigrtmax (void) __attribute__ ((__nothrow__ , __leaf__));
extern int tgkill (__pid_t __tgid, __pid_t __tid, int __signal);

typedef __uint8_t uint8_t;
typedef __uint16_t uint16_t;
typedef __uint32_t uint32_t;
typedef __uint64_t uint64_t;
typedef __int_least8_t int_least8_t;
typedef __int_least16_t int_least16_t;
typedef __int_least32_t int_least32_t;
typedef __int_least64_t int_least64_t;
typedef __uint_least8_t uint_least8_t;
typedef __uint_least16_t uint_least16_t;
typedef __uint_least32_t uint_least32_t;
typedef __uint_least64_t uint_least64_t;
typedef signed char int_fast8_t;
typedef long int int_fast16_t;
typedef long int int_fast32_t;
typedef long int int_fast64_t;
typedef unsigned char uint_fast8_t;
typedef unsigned long int uint_fast16_t;
typedef unsigned long int uint_fast32_t;
typedef unsigned long int uint_fast64_t;
typedef unsigned long int uintptr_t;
typedef __intmax_t intmax_t;
typedef __uintmax_t uintmax_t;
typedef uint16_t ggml_half;
typedef uint32_t ggml_half2;
typedef struct {
    ggml_half d;
    uint8_t qs[32 / 2];
} block_q4_0;
_Static_assert(sizeof(block_q4_0) == sizeof(ggml_half) + 32 / 2, "wrong q4_0 block size/padding");
typedef struct {
    __extension__ union {
        struct {
            ggml_half d;
            ggml_half m;
        } ;
        ggml_half2 dm;
    } ;
    uint8_t qs[32 / 2];
} block_q4_1;
_Static_assert(sizeof(block_q4_1) == 2 * sizeof(ggml_half) + 32 / 2, "wrong q4_1 block size/padding");
typedef struct {
    uint8_t e;
    uint8_t qs[32/2];
} block_mxfp4;
_Static_assert(sizeof(block_mxfp4) == sizeof(uint8_t) + 32/2, "wrong mxfp4 block size/padding");
typedef struct {
    ggml_half d;
    uint8_t qh[4];
    uint8_t qs[32 / 2];
} block_q5_0;
_Static_assert(sizeof(block_q5_0) == sizeof(ggml_half) + sizeof(uint32_t) + 32 / 2, "wrong q5_0 block size/padding");
typedef struct {
    __extension__ union {
        struct {
            ggml_half d;
            ggml_half m;
        } ;
        ggml_half2 dm;
    } ;
    uint8_t qh[4];
    uint8_t qs[32 / 2];
} block_q5_1;
_Static_assert(sizeof(block_q5_1) == 2 * sizeof(ggml_half) + sizeof(uint32_t) + 32 / 2, "wrong q5_1 block size/padding");
typedef struct {
    ggml_half d;
    int8_t qs[32];
} block_q8_0;
_Static_assert(sizeof(block_q8_0) == sizeof(ggml_half) + 32, "wrong q8_0 block size/padding");
typedef struct {
    __extension__ union {
        struct {
            ggml_half d;
            ggml_half s;
        } ;
        ggml_half2 ds;
    } ;
    int8_t qs[32];
} block_q8_1;
_Static_assert(sizeof(block_q8_1) == 2*sizeof(ggml_half) + 32, "wrong q8_1 block size/padding");
typedef struct {
    uint8_t qs[(256 - 4 * 256 / 64) / 5];
    uint8_t qh[256/64];
    ggml_half d;
} block_tq1_0;
_Static_assert(sizeof(block_tq1_0) == sizeof(ggml_half) + 256 / 64 + (256 - 4 * 256 / 64) / 5, "wrong tq1_0 block size/padding");
typedef struct {
    uint8_t qs[256/4];
    ggml_half d;
} block_tq2_0;
_Static_assert(sizeof(block_tq2_0) == sizeof(ggml_half) + 256 / 4, "wrong tq2_0 block size/padding");
typedef struct {
    uint8_t scales[256/16];
    uint8_t qs[256/4];
    __extension__ union {
        struct {
            ggml_half d;
            ggml_half dmin;
        } ;
        ggml_half2 dm;
    } ;
} block_q2_K;
_Static_assert(sizeof(block_q2_K) == 2*sizeof(ggml_half) + 256/16 + 256/4, "wrong q2_K block size/padding");
typedef struct {
    uint8_t hmask[256/8];
    uint8_t qs[256/4];
    uint8_t scales[12];
    ggml_half d;
} block_q3_K;
_Static_assert(sizeof(block_q3_K) == sizeof(ggml_half) + 256 / 4 + 256 / 8 + 12, "wrong q3_K block size/padding");
typedef struct {
    __extension__ union {
        struct {
            ggml_half d;
            ggml_half dmin;
        } ;
        ggml_half2 dm;
    } ;
    uint8_t scales[12];
    uint8_t qs[256/2];
} block_q4_K;
_Static_assert(sizeof(block_q4_K) == 2*sizeof(ggml_half) + 12 + 256/2, "wrong q4_K block size/padding");
typedef struct {
    __extension__ union {
        struct {
            ggml_half d;
            ggml_half dmin;
        } ;
        ggml_half2 dm;
    } ;
    uint8_t scales[12];
    uint8_t qh[256/8];
    uint8_t qs[256/2];
} block_q5_K;
_Static_assert(sizeof(block_q5_K) == 2*sizeof(ggml_half) + 12 + 256/2 + 256/8, "wrong q5_K block size/padding");
typedef struct {
    uint8_t ql[256/2];
    uint8_t qh[256/4];
    int8_t scales[256/16];
    ggml_half d;
} block_q6_K;
_Static_assert(sizeof(block_q6_K) == sizeof(ggml_half) + 256 / 16 + 3*256/4, "wrong q6_K block size/padding");
typedef struct {
    float d;
    int8_t qs[256];
    int16_t bsums[256/16];
} block_q8_K;
_Static_assert(sizeof(block_q8_K) == sizeof(float) + 256 + 256/16*sizeof(int16_t), "wrong q8_K block size/padding");
typedef struct {
    ggml_half d;
    uint16_t qs[256/8];
} block_iq2_xxs;
_Static_assert(sizeof(block_iq2_xxs) == sizeof(ggml_half) + 256/8*sizeof(uint16_t), "wrong iq2_xxs block size/padding");
typedef struct {
    ggml_half d;
    uint16_t qs[256/8];
    uint8_t scales[256/32];
} block_iq2_xs;
_Static_assert(sizeof(block_iq2_xs) == sizeof(ggml_half) + 256/8*sizeof(uint16_t) + 256/32, "wrong iq2_xs block size/padding");
typedef struct {
    ggml_half d;
    uint8_t qs[256/4];
    uint8_t qh[256/32];
    uint8_t scales[256/32];
} block_iq2_s;
_Static_assert(sizeof(block_iq2_s) == sizeof(ggml_half) + 256/4 + 256/16, "wrong iq2_s block size/padding");
typedef struct {
    ggml_half d;
    uint8_t qs[3*256/8];
} block_iq3_xxs;
_Static_assert(sizeof(block_iq3_xxs) == sizeof(ggml_half) + 3*(256/8), "wrong iq3_xxs block size/padding");
typedef struct {
    ggml_half d;
    uint8_t qs[256/4];
    uint8_t qh[256/32];
    uint8_t signs[256/8];
    uint8_t scales[256/64];
} block_iq3_s;
_Static_assert(sizeof(block_iq3_s) == sizeof(ggml_half) + 13*(256/32) + 256/64, "wrong iq3_s block size/padding");
typedef struct {
    ggml_half d;
    uint8_t qs[256/8];
    uint16_t qh[256/32];
} block_iq1_s;
_Static_assert(sizeof(block_iq1_s) == sizeof(ggml_half) + 256/8 + 256/16, "wrong iq1_s block size/padding");
typedef struct {
    uint8_t qs[256/8];
    uint8_t qh[256/16];
    uint8_t scales[256/32];
} block_iq1_m;
_Static_assert(sizeof(block_iq1_m) == 256/8 + 256/16 + 256/32, "wrong iq1_m block size/padding");
typedef union {
    ggml_half f16;
    uint16_t u16;
} iq1m_scale_t;
typedef struct {
    ggml_half d;
    uint8_t qs[32/2];
} block_iq4_nl;
_Static_assert(sizeof(block_iq4_nl) == sizeof(ggml_half) + 32/2, "wrong iq4_nl block size/padding");
typedef struct {
    ggml_half d;
    uint16_t scales_h;
    uint8_t scales_l[256/64];
    uint8_t qs[256/2];
} block_iq4_xs;
_Static_assert(sizeof(block_iq4_xs) == sizeof(ggml_half) + sizeof(uint16_t) + 256/64 + 256/2, "wrong iq4_xs block size/padding");
       
typedef long int ptrdiff_t;
typedef struct {
  long long __max_align_ll __attribute__((__aligned__(__alignof__(long long))));
  long double __max_align_ld __attribute__((__aligned__(__alignof__(long double))));
} max_align_t;
    typedef void (*ggml_abort_callback_t)(const char * error_message);
    __attribute__ ((visibility ("default"))) extern ggml_abort_callback_t ggml_set_abort_callback(ggml_abort_callback_t callback);
    _Noreturn __attribute__((format(printf, 3, 4)))
    __attribute__ ((visibility ("default"))) extern void ggml_abort(const char * file, int line, const char * fmt, ...);
    enum ggml_status {
        GGML_STATUS_ALLOC_FAILED = -2,
        GGML_STATUS_FAILED = -1,
        GGML_STATUS_SUCCESS = 0,
        GGML_STATUS_ABORTED = 1,
    };
    __attribute__ ((visibility ("default"))) extern const char * ggml_status_to_string(enum ggml_status status);
    typedef uint16_t ggml_fp16_t;
    __attribute__ ((visibility ("default"))) extern float ggml_fp16_to_fp32(ggml_fp16_t);
    __attribute__ ((visibility ("default"))) extern ggml_fp16_t ggml_fp32_to_fp16(float);
    __attribute__ ((visibility ("default"))) extern void ggml_fp16_to_fp32_row(const ggml_fp16_t *, float *, int64_t);
    __attribute__ ((visibility ("default"))) extern void ggml_fp32_to_fp16_row(const float *, ggml_fp16_t *, int64_t);
    typedef struct { uint16_t bits; } ggml_bf16_t;
    __attribute__ ((visibility ("default"))) extern ggml_bf16_t ggml_fp32_to_bf16(float);
    __attribute__ ((visibility ("default"))) extern float ggml_bf16_to_fp32(ggml_bf16_t);
    __attribute__ ((visibility ("default"))) extern void ggml_bf16_to_fp32_row(const ggml_bf16_t *, float *, int64_t);
    __attribute__ ((visibility ("default"))) extern void ggml_fp32_to_bf16_row_ref(const float *, ggml_bf16_t *, int64_t);
    __attribute__ ((visibility ("default"))) extern void ggml_fp32_to_bf16_row(const float *, ggml_bf16_t *, int64_t);
    struct ggml_object;
    struct ggml_context;
    struct ggml_cgraph;
    enum ggml_type {
        GGML_TYPE_F32 = 0,
        GGML_TYPE_F16 = 1,
        GGML_TYPE_Q4_0 = 2,
        GGML_TYPE_Q4_1 = 3,
        GGML_TYPE_Q5_0 = 6,
        GGML_TYPE_Q5_1 = 7,
        GGML_TYPE_Q8_0 = 8,
        GGML_TYPE_Q8_1 = 9,
        GGML_TYPE_Q2_K = 10,
        GGML_TYPE_Q3_K = 11,
        GGML_TYPE_Q4_K = 12,
        GGML_TYPE_Q5_K = 13,
        GGML_TYPE_Q6_K = 14,
        GGML_TYPE_Q8_K = 15,
        GGML_TYPE_IQ2_XXS = 16,
        GGML_TYPE_IQ2_XS = 17,
        GGML_TYPE_IQ3_XXS = 18,
        GGML_TYPE_IQ1_S = 19,
        GGML_TYPE_IQ4_NL = 20,
        GGML_TYPE_IQ3_S = 21,
        GGML_TYPE_IQ2_S = 22,
        GGML_TYPE_IQ4_XS = 23,
        GGML_TYPE_I8 = 24,
        GGML_TYPE_I16 = 25,
        GGML_TYPE_I32 = 26,
        GGML_TYPE_I64 = 27,
        GGML_TYPE_F64 = 28,
        GGML_TYPE_IQ1_M = 29,
        GGML_TYPE_BF16 = 30,
        GGML_TYPE_TQ1_0 = 34,
        GGML_TYPE_TQ2_0 = 35,
        GGML_TYPE_MXFP4 = 39,
        GGML_TYPE_COUNT = 40,
    };
    enum ggml_prec {
        GGML_PREC_DEFAULT = 0,
        GGML_PREC_F32 = 10,
    };
    enum ggml_ftype {
        GGML_FTYPE_UNKNOWN = -1,
        GGML_FTYPE_ALL_F32 = 0,
        GGML_FTYPE_MOSTLY_F16 = 1,
        GGML_FTYPE_MOSTLY_Q4_0 = 2,
        GGML_FTYPE_MOSTLY_Q4_1 = 3,
        GGML_FTYPE_MOSTLY_Q4_1_SOME_F16 = 4,
        GGML_FTYPE_MOSTLY_Q8_0 = 7,
        GGML_FTYPE_MOSTLY_Q5_0 = 8,
        GGML_FTYPE_MOSTLY_Q5_1 = 9,
        GGML_FTYPE_MOSTLY_Q2_K = 10,
        GGML_FTYPE_MOSTLY_Q3_K = 11,
        GGML_FTYPE_MOSTLY_Q4_K = 12,
        GGML_FTYPE_MOSTLY_Q5_K = 13,
        GGML_FTYPE_MOSTLY_Q6_K = 14,
        GGML_FTYPE_MOSTLY_IQ2_XXS = 15,
        GGML_FTYPE_MOSTLY_IQ2_XS = 16,
        GGML_FTYPE_MOSTLY_IQ3_XXS = 17,
        GGML_FTYPE_MOSTLY_IQ1_S = 18,
        GGML_FTYPE_MOSTLY_IQ4_NL = 19,
        GGML_FTYPE_MOSTLY_IQ3_S = 20,
        GGML_FTYPE_MOSTLY_IQ2_S = 21,
        GGML_FTYPE_MOSTLY_IQ4_XS = 22,
        GGML_FTYPE_MOSTLY_IQ1_M = 23,
        GGML_FTYPE_MOSTLY_BF16 = 24,
        GGML_FTYPE_MOSTLY_MXFP4 = 25,
    };
    enum ggml_op {
        GGML_OP_NONE = 0,
        GGML_OP_DUP,
        GGML_OP_ADD,
        GGML_OP_ADD_ID,
        GGML_OP_ADD1,
        GGML_OP_ACC,
        GGML_OP_SUB,
        GGML_OP_MUL,
        GGML_OP_DIV,
        GGML_OP_SQR,
        GGML_OP_SQRT,
        GGML_OP_LOG,
        GGML_OP_SIN,
        GGML_OP_COS,
        GGML_OP_SUM,
        GGML_OP_SUM_ROWS,
        GGML_OP_MEAN,
        GGML_OP_ARGMAX,
        GGML_OP_COUNT_EQUAL,
        GGML_OP_REPEAT,
        GGML_OP_REPEAT_BACK,
        GGML_OP_CONCAT,
        GGML_OP_SILU_BACK,
        GGML_OP_NORM,
        GGML_OP_RMS_NORM,
        GGML_OP_RMS_NORM_BACK,
        GGML_OP_GROUP_NORM,
        GGML_OP_L2_NORM,
        GGML_OP_MUL_MAT,
        GGML_OP_MUL_MAT_ID,
        GGML_OP_OUT_PROD,
        GGML_OP_SCALE,
        GGML_OP_SET,
        GGML_OP_CPY,
        GGML_OP_CONT,
        GGML_OP_RESHAPE,
        GGML_OP_VIEW,
        GGML_OP_PERMUTE,
        GGML_OP_TRANSPOSE,
        GGML_OP_GET_ROWS,
        GGML_OP_GET_ROWS_BACK,
        GGML_OP_SET_ROWS,
        GGML_OP_DIAG,
        GGML_OP_DIAG_MASK_INF,
        GGML_OP_DIAG_MASK_ZERO,
        GGML_OP_SOFT_MAX,
        GGML_OP_SOFT_MAX_BACK,
        GGML_OP_ROPE,
        GGML_OP_ROPE_BACK,
        GGML_OP_CLAMP,
        GGML_OP_CONV_TRANSPOSE_1D,
        GGML_OP_IM2COL,
        GGML_OP_IM2COL_BACK,
        GGML_OP_IM2COL_3D,
        GGML_OP_CONV_2D,
        GGML_OP_CONV_3D,
        GGML_OP_CONV_2D_DW,
        GGML_OP_CONV_TRANSPOSE_2D,
        GGML_OP_POOL_1D,
        GGML_OP_POOL_2D,
        GGML_OP_POOL_2D_BACK,
        GGML_OP_UPSCALE,
        GGML_OP_PAD,
        GGML_OP_PAD_REFLECT_1D,
        GGML_OP_ROLL,
        GGML_OP_ARANGE,
        GGML_OP_TIMESTEP_EMBEDDING,
        GGML_OP_ARGSORT,
        GGML_OP_LEAKY_RELU,
        GGML_OP_FLASH_ATTN_EXT,
        GGML_OP_FLASH_ATTN_BACK,
        GGML_OP_SSM_CONV,
        GGML_OP_SSM_SCAN,
        GGML_OP_WIN_PART,
        GGML_OP_WIN_UNPART,
        GGML_OP_GET_REL_POS,
        GGML_OP_ADD_REL_POS,
        GGML_OP_RWKV_WKV6,
        GGML_OP_GATED_LINEAR_ATTN,
        GGML_OP_RWKV_WKV7,
        GGML_OP_UNARY,
        GGML_OP_MAP_CUSTOM1,
        GGML_OP_MAP_CUSTOM2,
        GGML_OP_MAP_CUSTOM3,
        GGML_OP_CUSTOM,
        GGML_OP_CROSS_ENTROPY_LOSS,
        GGML_OP_CROSS_ENTROPY_LOSS_BACK,
        GGML_OP_OPT_STEP_ADAMW,
        GGML_OP_OPT_STEP_SGD,
        GGML_OP_GLU,
        GGML_OP_COUNT,
    };
    enum ggml_unary_op {
        GGML_UNARY_OP_ABS,
        GGML_UNARY_OP_SGN,
        GGML_UNARY_OP_NEG,
        GGML_UNARY_OP_STEP,
        GGML_UNARY_OP_TANH,
        GGML_UNARY_OP_ELU,
        GGML_UNARY_OP_RELU,
        GGML_UNARY_OP_SIGMOID,
        GGML_UNARY_OP_GELU,
        GGML_UNARY_OP_GELU_QUICK,
        GGML_UNARY_OP_SILU,
        GGML_UNARY_OP_HARDSWISH,
        GGML_UNARY_OP_HARDSIGMOID,
        GGML_UNARY_OP_EXP,
        GGML_UNARY_OP_GELU_ERF,
        GGML_UNARY_OP_XIELU,
        GGML_UNARY_OP_COUNT,
    };
    enum ggml_glu_op {
        GGML_GLU_OP_REGLU,
        GGML_GLU_OP_GEGLU,
        GGML_GLU_OP_SWIGLU,
        GGML_GLU_OP_SWIGLU_OAI,
        GGML_GLU_OP_GEGLU_ERF,
        GGML_GLU_OP_GEGLU_QUICK,
        GGML_GLU_OP_COUNT,
    };
    enum ggml_object_type {
        GGML_OBJECT_TYPE_TENSOR,
        GGML_OBJECT_TYPE_GRAPH,
        GGML_OBJECT_TYPE_WORK_BUFFER
    };
    enum ggml_log_level {
        GGML_LOG_LEVEL_NONE = 0,
        GGML_LOG_LEVEL_DEBUG = 1,
        GGML_LOG_LEVEL_INFO = 2,
        GGML_LOG_LEVEL_WARN = 3,
        GGML_LOG_LEVEL_ERROR = 4,
        GGML_LOG_LEVEL_CONT = 5,
    };
    enum ggml_tensor_flag {
        GGML_TENSOR_FLAG_INPUT = 1,
        GGML_TENSOR_FLAG_OUTPUT = 2,
        GGML_TENSOR_FLAG_PARAM = 4,
        GGML_TENSOR_FLAG_LOSS = 8,
    };
    struct ggml_init_params {
        size_t mem_size;
        void * mem_buffer;
        _Bool no_alloc;
    };
    struct ggml_tensor {
        enum ggml_type type;
        struct ggml_backend_buffer * buffer;
        int64_t ne[4];
        size_t nb[4];
        enum ggml_op op;
        int32_t op_params[64 / sizeof(int32_t)];
        int32_t flags;
        struct ggml_tensor * src[10];
        struct ggml_tensor * view_src;
        size_t view_offs;
        void * data;
        char name[64];
        void * extra;
        char padding[8];
    };
    static const size_t GGML_TENSOR_SIZE = sizeof(struct ggml_tensor);
    typedef _Bool (*ggml_abort_callback)(void * data);
    typedef uint8_t ggml_guid[16];
    typedef ggml_guid * ggml_guid_t;
    __attribute__ ((visibility ("default"))) extern _Bool ggml_guid_matches(ggml_guid_t guid_a, ggml_guid_t guid_b);
    __attribute__ ((visibility ("default"))) extern const char * ggml_version(void);
    __attribute__ ((visibility ("default"))) extern const char * ggml_commit(void);
    __attribute__ ((visibility ("default"))) extern void ggml_time_init(void);
    __attribute__ ((visibility ("default"))) extern int64_t ggml_time_ms(void);
    __attribute__ ((visibility ("default"))) extern int64_t ggml_time_us(void);
    __attribute__ ((visibility ("default"))) extern int64_t ggml_cycles(void);
    __attribute__ ((visibility ("default"))) extern int64_t ggml_cycles_per_ms(void);
    __attribute__ ((visibility ("default"))) extern FILE * ggml_fopen(const char * fname, const char * mode);
    __attribute__ ((visibility ("default"))) extern void ggml_print_object (const struct ggml_object * obj);
    __attribute__ ((visibility ("default"))) extern void ggml_print_objects(const struct ggml_context * ctx);
    __attribute__ ((visibility ("default"))) extern int64_t ggml_nelements (const struct ggml_tensor * tensor);
    __attribute__ ((visibility ("default"))) extern int64_t ggml_nrows (const struct ggml_tensor * tensor);
    __attribute__ ((visibility ("default"))) extern size_t ggml_nbytes (const struct ggml_tensor * tensor);
    __attribute__ ((visibility ("default"))) extern size_t ggml_nbytes_pad(const struct ggml_tensor * tensor);
    __attribute__ ((visibility ("default"))) extern int64_t ggml_blck_size(enum ggml_type type);
    __attribute__ ((visibility ("default"))) extern size_t ggml_type_size(enum ggml_type type);
    __attribute__ ((visibility ("default"))) extern size_t ggml_row_size (enum ggml_type type, int64_t ne);
    __attribute__ ((visibility ("default"))) extern double ggml_type_sizef(enum ggml_type type) __attribute__((deprecated("use ggml_row_size() instead")));
    __attribute__ ((visibility ("default"))) extern const char * ggml_type_name(enum ggml_type type);
    __attribute__ ((visibility ("default"))) extern const char * ggml_op_name (enum ggml_op op);
    __attribute__ ((visibility ("default"))) extern const char * ggml_op_symbol(enum ggml_op op);
    __attribute__ ((visibility ("default"))) extern const char * ggml_unary_op_name(enum ggml_unary_op op);
    __attribute__ ((visibility ("default"))) extern const char * ggml_glu_op_name(enum ggml_glu_op op);
    __attribute__ ((visibility ("default"))) extern const char * ggml_op_desc(const struct ggml_tensor * t);
    __attribute__ ((visibility ("default"))) extern size_t ggml_element_size(const struct ggml_tensor * tensor);
    __attribute__ ((visibility ("default"))) extern _Bool ggml_is_quantized(enum ggml_type type);
    __attribute__ ((visibility ("default"))) extern enum ggml_type ggml_ftype_to_ggml_type(enum ggml_ftype ftype);
    __attribute__ ((visibility ("default"))) extern _Bool ggml_is_transposed(const struct ggml_tensor * tensor);
    __attribute__ ((visibility ("default"))) extern _Bool ggml_is_permuted (const struct ggml_tensor * tensor);
    __attribute__ ((visibility ("default"))) extern _Bool ggml_is_empty (const struct ggml_tensor * tensor);
    __attribute__ ((visibility ("default"))) extern _Bool ggml_is_scalar (const struct ggml_tensor * tensor);
    __attribute__ ((visibility ("default"))) extern _Bool ggml_is_vector (const struct ggml_tensor * tensor);
    __attribute__ ((visibility ("default"))) extern _Bool ggml_is_matrix (const struct ggml_tensor * tensor);
    __attribute__ ((visibility ("default"))) extern _Bool ggml_is_3d (const struct ggml_tensor * tensor);
    __attribute__ ((visibility ("default"))) extern int ggml_n_dims (const struct ggml_tensor * tensor);
    __attribute__ ((visibility ("default"))) extern _Bool ggml_is_contiguous (const struct ggml_tensor * tensor);
    __attribute__ ((visibility ("default"))) extern _Bool ggml_is_contiguous_0(const struct ggml_tensor * tensor);
    __attribute__ ((visibility ("default"))) extern _Bool ggml_is_contiguous_1(const struct ggml_tensor * tensor);
    __attribute__ ((visibility ("default"))) extern _Bool ggml_is_contiguous_2(const struct ggml_tensor * tensor);
    __attribute__ ((visibility ("default"))) extern _Bool ggml_is_contiguously_allocated(const struct ggml_tensor * tensor);
    __attribute__ ((visibility ("default"))) extern _Bool ggml_is_contiguous_channels(const struct ggml_tensor * tensor);
    __attribute__ ((visibility ("default"))) extern _Bool ggml_is_contiguous_rows(const struct ggml_tensor * tensor);
    __attribute__ ((visibility ("default"))) extern _Bool ggml_are_same_shape (const struct ggml_tensor * t0, const struct ggml_tensor * t1);
    __attribute__ ((visibility ("default"))) extern _Bool ggml_are_same_stride(const struct ggml_tensor * t0, const struct ggml_tensor * t1);
    __attribute__ ((visibility ("default"))) extern _Bool ggml_can_repeat(const struct ggml_tensor * t0, const struct ggml_tensor * t1);
    __attribute__ ((visibility ("default"))) extern size_t ggml_tensor_overhead(void);
    __attribute__ ((visibility ("default"))) extern _Bool ggml_validate_row_data(enum ggml_type type, const void * data, size_t nbytes);
    __attribute__ ((visibility ("default"))) extern struct ggml_context * ggml_init (struct ggml_init_params params);
    __attribute__ ((visibility ("default"))) extern void ggml_reset(struct ggml_context * ctx);
    __attribute__ ((visibility ("default"))) extern void ggml_free (struct ggml_context * ctx);
    __attribute__ ((visibility ("default"))) extern size_t ggml_used_mem(const struct ggml_context * ctx);
    __attribute__ ((visibility ("default"))) extern _Bool ggml_get_no_alloc(struct ggml_context * ctx);
    __attribute__ ((visibility ("default"))) extern void ggml_set_no_alloc(struct ggml_context * ctx, _Bool no_alloc);
    __attribute__ ((visibility ("default"))) extern void * ggml_get_mem_buffer (const struct ggml_context * ctx);
    __attribute__ ((visibility ("default"))) extern size_t ggml_get_mem_size (const struct ggml_context * ctx);
    __attribute__ ((visibility ("default"))) extern size_t ggml_get_max_tensor_size(const struct ggml_context * ctx);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_new_tensor(
            struct ggml_context * ctx,
            enum ggml_type type,
            int n_dims,
            const int64_t *ne);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_new_tensor_1d(
            struct ggml_context * ctx,
            enum ggml_type type,
            int64_t ne0);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_new_tensor_2d(
            struct ggml_context * ctx,
            enum ggml_type type,
            int64_t ne0,
            int64_t ne1);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_new_tensor_3d(
            struct ggml_context * ctx,
            enum ggml_type type,
            int64_t ne0,
            int64_t ne1,
            int64_t ne2);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_new_tensor_4d(
            struct ggml_context * ctx,
            enum ggml_type type,
            int64_t ne0,
            int64_t ne1,
            int64_t ne2,
            int64_t ne3);
    __attribute__ ((visibility ("default"))) extern void * ggml_new_buffer(struct ggml_context * ctx, size_t nbytes);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_dup_tensor (struct ggml_context * ctx, const struct ggml_tensor * src);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_view_tensor(struct ggml_context * ctx, struct ggml_tensor * src);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_get_first_tensor(const struct ggml_context * ctx);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_get_next_tensor (const struct ggml_context * ctx, struct ggml_tensor * tensor);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_get_tensor(struct ggml_context * ctx, const char * name);
    __attribute__ ((visibility ("default"))) extern void ggml_unravel_index(const struct ggml_tensor * tensor, int64_t i, int64_t * i0, int64_t * i1, int64_t * i2, int64_t * i3);
    __attribute__ ((visibility ("default"))) extern enum ggml_unary_op ggml_get_unary_op(const struct ggml_tensor * tensor);
    __attribute__ ((visibility ("default"))) extern enum ggml_glu_op ggml_get_glu_op(const struct ggml_tensor * tensor);
    __attribute__ ((visibility ("default"))) extern void * ggml_get_data (const struct ggml_tensor * tensor);
    __attribute__ ((visibility ("default"))) extern float * ggml_get_data_f32(const struct ggml_tensor * tensor);
    __attribute__ ((visibility ("default"))) extern const char * ggml_get_name (const struct ggml_tensor * tensor);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_set_name ( struct ggml_tensor * tensor, const char * name);
    __attribute__((format(printf, 2, 3)))
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_format_name( struct ggml_tensor * tensor, const char * fmt, ...);
    __attribute__ ((visibility ("default"))) extern void ggml_set_input(struct ggml_tensor * tensor);
    __attribute__ ((visibility ("default"))) extern void ggml_set_output(struct ggml_tensor * tensor);
    __attribute__ ((visibility ("default"))) extern void ggml_set_param(struct ggml_tensor * tensor);
    __attribute__ ((visibility ("default"))) extern void ggml_set_loss(struct ggml_tensor * tensor);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_dup(
            struct ggml_context * ctx,
            struct ggml_tensor * a);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_dup_inplace(
            struct ggml_context * ctx,
            struct ggml_tensor * a);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_add(
            struct ggml_context * ctx,
            struct ggml_tensor * a,
            struct ggml_tensor * b);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_add_inplace(
            struct ggml_context * ctx,
            struct ggml_tensor * a,
            struct ggml_tensor * b);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_add_cast(
            struct ggml_context * ctx,
            struct ggml_tensor * a,
            struct ggml_tensor * b,
            enum ggml_type type);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_add_id(
            struct ggml_context * ctx,
            struct ggml_tensor * a,
            struct ggml_tensor * b,
            struct ggml_tensor * ids);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_add1(
            struct ggml_context * ctx,
            struct ggml_tensor * a,
            struct ggml_tensor * b);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_add1_inplace(
            struct ggml_context * ctx,
            struct ggml_tensor * a,
            struct ggml_tensor * b);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_acc(
            struct ggml_context * ctx,
            struct ggml_tensor * a,
            struct ggml_tensor * b,
            size_t nb1,
            size_t nb2,
            size_t nb3,
            size_t offset);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_acc_inplace(
            struct ggml_context * ctx,
            struct ggml_tensor * a,
            struct ggml_tensor * b,
            size_t nb1,
            size_t nb2,
            size_t nb3,
            size_t offset);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_sub(
            struct ggml_context * ctx,
            struct ggml_tensor * a,
            struct ggml_tensor * b);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_sub_inplace(
            struct ggml_context * ctx,
            struct ggml_tensor * a,
            struct ggml_tensor * b);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_mul(
            struct ggml_context * ctx,
            struct ggml_tensor * a,
            struct ggml_tensor * b);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_mul_inplace(
            struct ggml_context * ctx,
            struct ggml_tensor * a,
            struct ggml_tensor * b);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_div(
            struct ggml_context * ctx,
            struct ggml_tensor * a,
            struct ggml_tensor * b);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_div_inplace(
            struct ggml_context * ctx,
            struct ggml_tensor * a,
            struct ggml_tensor * b);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_sqr(
            struct ggml_context * ctx,
            struct ggml_tensor * a);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_sqr_inplace(
            struct ggml_context * ctx,
            struct ggml_tensor * a);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_sqrt(
            struct ggml_context * ctx,
            struct ggml_tensor * a);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_sqrt_inplace(
            struct ggml_context * ctx,
            struct ggml_tensor * a);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_log(
            struct ggml_context * ctx,
            struct ggml_tensor * a);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_log_inplace(
            struct ggml_context * ctx,
            struct ggml_tensor * a);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_sin(
            struct ggml_context * ctx,
            struct ggml_tensor * a);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_sin_inplace(
            struct ggml_context * ctx,
            struct ggml_tensor * a);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_cos(
            struct ggml_context * ctx,
            struct ggml_tensor * a);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_cos_inplace(
            struct ggml_context * ctx,
            struct ggml_tensor * a);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_sum(
            struct ggml_context * ctx,
            struct ggml_tensor * a);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_sum_rows(
            struct ggml_context * ctx,
            struct ggml_tensor * a);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_mean(
            struct ggml_context * ctx,
            struct ggml_tensor * a);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_argmax(
            struct ggml_context * ctx,
            struct ggml_tensor * a);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_count_equal(
            struct ggml_context * ctx,
            struct ggml_tensor * a,
            struct ggml_tensor * b);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_repeat(
            struct ggml_context * ctx,
            struct ggml_tensor * a,
            struct ggml_tensor * b);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_repeat_4d(
            struct ggml_context * ctx,
            struct ggml_tensor * a,
                       int64_t ne0,
                       int64_t ne1,
                       int64_t ne2,
                       int64_t ne3);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_repeat_back(
            struct ggml_context * ctx,
            struct ggml_tensor * a,
            struct ggml_tensor * b);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_concat(
            struct ggml_context * ctx,
            struct ggml_tensor * a,
            struct ggml_tensor * b,
            int dim);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_abs(
            struct ggml_context * ctx,
            struct ggml_tensor * a);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_abs_inplace(
            struct ggml_context * ctx,
            struct ggml_tensor * a);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_sgn(
            struct ggml_context * ctx,
            struct ggml_tensor * a);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_sgn_inplace(
            struct ggml_context * ctx,
            struct ggml_tensor * a);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_neg(
            struct ggml_context * ctx,
            struct ggml_tensor * a);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_neg_inplace(
            struct ggml_context * ctx,
            struct ggml_tensor * a);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_step(
            struct ggml_context * ctx,
            struct ggml_tensor * a);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_step_inplace(
            struct ggml_context * ctx,
            struct ggml_tensor * a);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_tanh(
            struct ggml_context * ctx,
            struct ggml_tensor * a);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_tanh_inplace(
            struct ggml_context * ctx,
            struct ggml_tensor * a);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_elu(
            struct ggml_context * ctx,
            struct ggml_tensor * a);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_elu_inplace(
            struct ggml_context * ctx,
            struct ggml_tensor * a);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_relu(
            struct ggml_context * ctx,
            struct ggml_tensor * a);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_leaky_relu(
            struct ggml_context * ctx,
            struct ggml_tensor * a, float negative_slope, _Bool inplace);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_relu_inplace(
            struct ggml_context * ctx,
            struct ggml_tensor * a);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_sigmoid(
            struct ggml_context * ctx,
            struct ggml_tensor * a);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_sigmoid_inplace(
            struct ggml_context * ctx,
            struct ggml_tensor * a);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_gelu(
            struct ggml_context * ctx,
            struct ggml_tensor * a);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_gelu_inplace(
            struct ggml_context * ctx,
            struct ggml_tensor * a);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_gelu_erf(
            struct ggml_context * ctx,
            struct ggml_tensor * a);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_gelu_erf_inplace(
            struct ggml_context * ctx,
            struct ggml_tensor * a);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_gelu_quick(
            struct ggml_context * ctx,
            struct ggml_tensor * a);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_gelu_quick_inplace(
            struct ggml_context * ctx,
            struct ggml_tensor * a);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_silu(
            struct ggml_context * ctx,
            struct ggml_tensor * a);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_silu_inplace(
            struct ggml_context * ctx,
            struct ggml_tensor * a);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_silu_back(
            struct ggml_context * ctx,
            struct ggml_tensor * a,
            struct ggml_tensor * b);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_hardswish(
            struct ggml_context * ctx,
            struct ggml_tensor * a);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_hardsigmoid(
            struct ggml_context * ctx,
            struct ggml_tensor * a);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_exp(
            struct ggml_context * ctx,
            struct ggml_tensor * a);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_exp_inplace(
            struct ggml_context * ctx,
            struct ggml_tensor * a);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_xielu(
            struct ggml_context * ctx,
            struct ggml_tensor * a,
            float alpha_n,
            float alpha_p,
            float beta,
            float eps);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_glu(
            struct ggml_context * ctx,
             struct ggml_tensor * a,
             enum ggml_glu_op op,
             _Bool swapped);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_reglu(
            struct ggml_context * ctx,
            struct ggml_tensor * a);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_reglu_swapped(
            struct ggml_context * ctx,
            struct ggml_tensor * a);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_geglu(
            struct ggml_context * ctx,
            struct ggml_tensor * a);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_geglu_swapped(
            struct ggml_context * ctx,
            struct ggml_tensor * a);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_swiglu(
            struct ggml_context * ctx,
            struct ggml_tensor * a);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_swiglu_swapped(
            struct ggml_context * ctx,
            struct ggml_tensor * a);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_geglu_erf(
            struct ggml_context * ctx,
            struct ggml_tensor * a);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_geglu_erf_swapped(
            struct ggml_context * ctx,
            struct ggml_tensor * a);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_geglu_quick(
            struct ggml_context * ctx,
            struct ggml_tensor * a);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_geglu_quick_swapped(
            struct ggml_context * ctx,
            struct ggml_tensor * a);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_glu_split(
            struct ggml_context * ctx,
             struct ggml_tensor * a,
             struct ggml_tensor * b,
             enum ggml_glu_op op);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_reglu_split(
            struct ggml_context * ctx,
            struct ggml_tensor * a,
            struct ggml_tensor * b);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_geglu_split(
            struct ggml_context * ctx,
            struct ggml_tensor * a,
            struct ggml_tensor * b);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_swiglu_split(
            struct ggml_context * ctx,
            struct ggml_tensor * a,
            struct ggml_tensor * b);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_geglu_erf_split(
            struct ggml_context * ctx,
            struct ggml_tensor * a,
            struct ggml_tensor * b);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_geglu_quick_split(
            struct ggml_context * ctx,
            struct ggml_tensor * a,
            struct ggml_tensor * b);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_swiglu_oai(
            struct ggml_context * ctx,
            struct ggml_tensor * a,
            struct ggml_tensor * b,
            float alpha,
            float limit);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_norm(
            struct ggml_context * ctx,
            struct ggml_tensor * a,
            float eps);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_norm_inplace(
            struct ggml_context * ctx,
            struct ggml_tensor * a,
            float eps);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_rms_norm(
            struct ggml_context * ctx,
            struct ggml_tensor * a,
            float eps);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_rms_norm_inplace(
            struct ggml_context * ctx,
            struct ggml_tensor * a,
            float eps);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_group_norm(
            struct ggml_context * ctx,
            struct ggml_tensor * a,
            int n_groups,
            float eps);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_group_norm_inplace(
            struct ggml_context * ctx,
            struct ggml_tensor * a,
            int n_groups,
            float eps);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_l2_norm(
            struct ggml_context * ctx,
            struct ggml_tensor * a,
            float eps);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_l2_norm_inplace(
            struct ggml_context * ctx,
            struct ggml_tensor * a,
            float eps);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_rms_norm_back(
            struct ggml_context * ctx,
            struct ggml_tensor * a,
            struct ggml_tensor * b,
            float eps);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_mul_mat(
            struct ggml_context * ctx,
            struct ggml_tensor * a,
            struct ggml_tensor * b);
    __attribute__ ((visibility ("default"))) extern void ggml_mul_mat_set_prec(
            struct ggml_tensor * a,
            enum ggml_prec prec);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_mul_mat_id(
            struct ggml_context * ctx,
            struct ggml_tensor * as,
            struct ggml_tensor * b,
            struct ggml_tensor * ids);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_out_prod(
            struct ggml_context * ctx,
            struct ggml_tensor * a,
            struct ggml_tensor * b);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_scale(
            struct ggml_context * ctx,
            struct ggml_tensor * a,
            float s);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_scale_inplace(
            struct ggml_context * ctx,
            struct ggml_tensor * a,
            float s);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_scale_bias(
        struct ggml_context * ctx,
        struct ggml_tensor * a,
        float s,
        float b);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_scale_bias_inplace(
        struct ggml_context * ctx,
        struct ggml_tensor * a,
        float s,
        float b);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_set(
            struct ggml_context * ctx,
            struct ggml_tensor * a,
            struct ggml_tensor * b,
            size_t nb1,
            size_t nb2,
            size_t nb3,
            size_t offset);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_set_inplace(
            struct ggml_context * ctx,
            struct ggml_tensor * a,
            struct ggml_tensor * b,
            size_t nb1,
            size_t nb2,
            size_t nb3,
            size_t offset);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_set_1d(
            struct ggml_context * ctx,
            struct ggml_tensor * a,
            struct ggml_tensor * b,
            size_t offset);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_set_1d_inplace(
            struct ggml_context * ctx,
            struct ggml_tensor * a,
            struct ggml_tensor * b,
            size_t offset);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_set_2d(
            struct ggml_context * ctx,
            struct ggml_tensor * a,
            struct ggml_tensor * b,
            size_t nb1,
            size_t offset);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_set_2d_inplace(
            struct ggml_context * ctx,
            struct ggml_tensor * a,
            struct ggml_tensor * b,
            size_t nb1,
            size_t offset);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_cpy(
            struct ggml_context * ctx,
            struct ggml_tensor * a,
            struct ggml_tensor * b);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_cast(
            struct ggml_context * ctx,
            struct ggml_tensor * a,
            enum ggml_type type);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_cont(
            struct ggml_context * ctx,
            struct ggml_tensor * a);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_cont_1d(
            struct ggml_context * ctx,
            struct ggml_tensor * a,
            int64_t ne0);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_cont_2d(
            struct ggml_context * ctx,
            struct ggml_tensor * a,
            int64_t ne0,
            int64_t ne1);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_cont_3d(
            struct ggml_context * ctx,
            struct ggml_tensor * a,
            int64_t ne0,
            int64_t ne1,
            int64_t ne2);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_cont_4d(
            struct ggml_context * ctx,
            struct ggml_tensor * a,
            int64_t ne0,
            int64_t ne1,
            int64_t ne2,
            int64_t ne3);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_reshape(
            struct ggml_context * ctx,
            struct ggml_tensor * a,
            struct ggml_tensor * b);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_reshape_1d(
            struct ggml_context * ctx,
            struct ggml_tensor * a,
            int64_t ne0);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_reshape_2d(
            struct ggml_context * ctx,
            struct ggml_tensor * a,
            int64_t ne0,
            int64_t ne1);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_reshape_3d(
            struct ggml_context * ctx,
            struct ggml_tensor * a,
            int64_t ne0,
            int64_t ne1,
            int64_t ne2);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_reshape_4d(
            struct ggml_context * ctx,
            struct ggml_tensor * a,
            int64_t ne0,
            int64_t ne1,
            int64_t ne2,
            int64_t ne3);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_view_1d(
            struct ggml_context * ctx,
            struct ggml_tensor * a,
            int64_t ne0,
            size_t offset);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_view_2d(
            struct ggml_context * ctx,
            struct ggml_tensor * a,
            int64_t ne0,
            int64_t ne1,
            size_t nb1,
            size_t offset);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_view_3d(
            struct ggml_context * ctx,
            struct ggml_tensor * a,
            int64_t ne0,
            int64_t ne1,
            int64_t ne2,
            size_t nb1,
            size_t nb2,
            size_t offset);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_view_4d(
            struct ggml_context * ctx,
            struct ggml_tensor * a,
            int64_t ne0,
            int64_t ne1,
            int64_t ne2,
            int64_t ne3,
            size_t nb1,
            size_t nb2,
            size_t nb3,
            size_t offset);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_permute(
            struct ggml_context * ctx,
            struct ggml_tensor * a,
            int axis0,
            int axis1,
            int axis2,
            int axis3);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_transpose(
            struct ggml_context * ctx,
            struct ggml_tensor * a);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_get_rows(
            struct ggml_context * ctx,
            struct ggml_tensor * a,
            struct ggml_tensor * b);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_get_rows_back(
            struct ggml_context * ctx,
            struct ggml_tensor * a,
            struct ggml_tensor * b,
            struct ggml_tensor * c);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_set_rows(
            struct ggml_context * ctx,
            struct ggml_tensor * a,
            struct ggml_tensor * b,
            struct ggml_tensor * c);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_diag(
        struct ggml_context * ctx,
        struct ggml_tensor * a);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_diag_mask_inf(
            struct ggml_context * ctx,
            struct ggml_tensor * a,
            int n_past);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_diag_mask_inf_inplace(
            struct ggml_context * ctx,
            struct ggml_tensor * a,
            int n_past);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_diag_mask_zero(
            struct ggml_context * ctx,
            struct ggml_tensor * a,
            int n_past);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_diag_mask_zero_inplace(
            struct ggml_context * ctx,
            struct ggml_tensor * a,
            int n_past);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_soft_max(
            struct ggml_context * ctx,
            struct ggml_tensor * a);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_soft_max_inplace(
            struct ggml_context * ctx,
            struct ggml_tensor * a);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_soft_max_ext(
            struct ggml_context * ctx,
            struct ggml_tensor * a,
            struct ggml_tensor * mask,
            float scale,
            float max_bias);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_soft_max_ext_inplace(
            struct ggml_context * ctx,
            struct ggml_tensor * a,
            struct ggml_tensor * mask,
            float scale,
            float max_bias);
    __attribute__ ((visibility ("default"))) extern void ggml_soft_max_add_sinks(
            struct ggml_tensor * a,
            struct ggml_tensor * sinks);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_soft_max_ext_back(
            struct ggml_context * ctx,
            struct ggml_tensor * a,
            struct ggml_tensor * b,
            float scale,
            float max_bias);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_soft_max_ext_back_inplace(
            struct ggml_context * ctx,
            struct ggml_tensor * a,
            struct ggml_tensor * b,
            float scale,
            float max_bias);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_rope(
            struct ggml_context * ctx,
            struct ggml_tensor * a,
            struct ggml_tensor * b,
            int n_dims,
            int mode);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_rope_inplace(
            struct ggml_context * ctx,
            struct ggml_tensor * a,
            struct ggml_tensor * b,
            int n_dims,
            int mode);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_rope_ext(
            struct ggml_context * ctx,
            struct ggml_tensor * a,
            struct ggml_tensor * b,
            struct ggml_tensor * c,
            int n_dims,
            int mode,
            int n_ctx_orig,
            float freq_base,
            float freq_scale,
            float ext_factor,
            float attn_factor,
            float beta_fast,
            float beta_slow);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_rope_multi(
            struct ggml_context * ctx,
            struct ggml_tensor * a,
            struct ggml_tensor * b,
            struct ggml_tensor * c,
            int n_dims,
            int sections[4],
            int mode,
            int n_ctx_orig,
            float freq_base,
            float freq_scale,
            float ext_factor,
            float attn_factor,
            float beta_fast,
            float beta_slow);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_rope_ext_inplace(
            struct ggml_context * ctx,
            struct ggml_tensor * a,
            struct ggml_tensor * b,
            struct ggml_tensor * c,
            int n_dims,
            int mode,
            int n_ctx_orig,
            float freq_base,
            float freq_scale,
            float ext_factor,
            float attn_factor,
            float beta_fast,
            float beta_slow);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_rope_multi_inplace(
            struct ggml_context * ctx,
            struct ggml_tensor * a,
            struct ggml_tensor * b,
            struct ggml_tensor * c,
            int n_dims,
            int sections[4],
            int mode,
            int n_ctx_orig,
            float freq_base,
            float freq_scale,
            float ext_factor,
            float attn_factor,
            float beta_fast,
            float beta_slow);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_rope_custom( struct ggml_context * ctx, struct ggml_tensor * a, struct ggml_tensor * b, int n_dims, int mode, int n_ctx_orig, float freq_base, float freq_scale, float ext_factor, float attn_factor, float beta_fast, float beta_slow) __attribute__((deprecated("use ggml_rope_ext instead")));
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_rope_custom_inplace( struct ggml_context * ctx, struct ggml_tensor * a, struct ggml_tensor * b, int n_dims, int mode, int n_ctx_orig, float freq_base, float freq_scale, float ext_factor, float attn_factor, float beta_fast, float beta_slow) __attribute__((deprecated("use ggml_rope_ext_inplace instead")));
    __attribute__ ((visibility ("default"))) extern void ggml_rope_yarn_corr_dims(
        int n_dims, int n_ctx_orig, float freq_base, float beta_fast, float beta_slow, float dims[2]);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_rope_ext_back(
            struct ggml_context * ctx,
            struct ggml_tensor * a,
            struct ggml_tensor * b,
            struct ggml_tensor * c,
            int n_dims,
            int mode,
            int n_ctx_orig,
            float freq_base,
            float freq_scale,
            float ext_factor,
            float attn_factor,
            float beta_fast,
            float beta_slow);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_rope_multi_back(
            struct ggml_context * ctx,
            struct ggml_tensor * a,
            struct ggml_tensor * b,
            struct ggml_tensor * c,
            int n_dims,
            int sections[4],
            int mode,
            int n_ctx_orig,
            float freq_base,
            float freq_scale,
            float ext_factor,
            float attn_factor,
            float beta_fast,
            float beta_slow);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_clamp(
            struct ggml_context * ctx,
            struct ggml_tensor * a,
            float min,
            float max);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_im2col(
            struct ggml_context * ctx,
            struct ggml_tensor * a,
            struct ggml_tensor * b,
            int s0,
            int s1,
            int p0,
            int p1,
            int d0,
            int d1,
            _Bool is_2D,
            enum ggml_type dst_type);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_im2col_back(
        struct ggml_context * ctx,
        struct ggml_tensor * a,
        struct ggml_tensor * b,
        int64_t * ne,
        int s0,
        int s1,
        int p0,
        int p1,
        int d0,
        int d1,
        _Bool is_2D);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_conv_1d(
            struct ggml_context * ctx,
            struct ggml_tensor * a,
            struct ggml_tensor * b,
            int s0,
            int p0,
            int d0);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor* ggml_conv_1d_ph(
            struct ggml_context * ctx,
            struct ggml_tensor * a,
            struct ggml_tensor * b,
            int s,
            int d);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_conv_1d_dw(
            struct ggml_context * ctx,
            struct ggml_tensor * a,
            struct ggml_tensor * b,
            int s0,
            int p0,
            int d0);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_conv_1d_dw_ph(
            struct ggml_context * ctx,
            struct ggml_tensor * a,
            struct ggml_tensor * b,
            int s0,
            int d0);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_conv_transpose_1d(
            struct ggml_context * ctx,
            struct ggml_tensor * a,
            struct ggml_tensor * b,
            int s0,
            int p0,
            int d0);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_conv_2d(
            struct ggml_context * ctx,
            struct ggml_tensor * a,
            struct ggml_tensor * b,
            int s0,
            int s1,
            int p0,
            int p1,
            int d0,
            int d1);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_im2col_3d(
            struct ggml_context * ctx,
            struct ggml_tensor * a,
            struct ggml_tensor * b,
            int64_t IC,
            int s0,
            int s1,
            int s2,
            int p0,
            int p1,
            int p2,
            int d0,
            int d1,
            int d2,
            enum ggml_type dst_type);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_conv_3d(
                struct ggml_context * ctx,
                struct ggml_tensor * a,
                struct ggml_tensor * b,
                int64_t IC,
                int s0,
                int s1,
                int s2,
                int p0,
                int p1,
                int p2,
                int d0,
                int d1,
                int d2
        );
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_conv_2d_sk_p0(
            struct ggml_context * ctx,
            struct ggml_tensor * a,
            struct ggml_tensor * b);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_conv_2d_s1_ph(
            struct ggml_context * ctx,
            struct ggml_tensor * a,
            struct ggml_tensor * b);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_conv_2d_dw(
            struct ggml_context * ctx,
            struct ggml_tensor * a,
            struct ggml_tensor * b,
            int s0,
            int s1,
            int p0,
            int p1,
            int d0,
            int d1);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_conv_2d_dw_direct(
            struct ggml_context * ctx,
            struct ggml_tensor * a,
            struct ggml_tensor * b,
            int stride0,
            int stride1,
            int pad0,
            int pad1,
            int dilation0,
            int dilation1);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_conv_transpose_2d_p0(
            struct ggml_context * ctx,
            struct ggml_tensor * a,
            struct ggml_tensor * b,
            int stride);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_conv_2d_direct(
            struct ggml_context * ctx,
            struct ggml_tensor * a,
            struct ggml_tensor * b,
            int s0,
            int s1,
            int p0,
            int p1,
            int d0,
            int d1);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_conv_3d_direct(
            struct ggml_context * ctx,
            struct ggml_tensor * a,
            struct ggml_tensor * b,
            int s0,
            int s1,
            int s2,
            int p0,
            int p1,
            int p2,
            int d0,
            int d1,
            int d2,
            int n_channels,
            int n_batch,
            int n_channels_out);
    enum ggml_op_pool {
        GGML_OP_POOL_MAX,
        GGML_OP_POOL_AVG,
        GGML_OP_POOL_COUNT,
    };
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_pool_1d(
            struct ggml_context * ctx,
            struct ggml_tensor * a,
            enum ggml_op_pool op,
            int k0,
            int s0,
            int p0);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_pool_2d(
            struct ggml_context * ctx,
            struct ggml_tensor * a,
            enum ggml_op_pool op,
            int k0,
            int k1,
            int s0,
            int s1,
            float p0,
            float p1);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_pool_2d_back(
            struct ggml_context * ctx,
            struct ggml_tensor * a,
            struct ggml_tensor * af,
            enum ggml_op_pool op,
            int k0,
            int k1,
            int s0,
            int s1,
            float p0,
            float p1);
    enum ggml_scale_mode {
        GGML_SCALE_MODE_NEAREST = 0,
        GGML_SCALE_MODE_BILINEAR = 1,
        GGML_SCALE_MODE_COUNT
    };
    enum ggml_scale_flag {
        GGML_SCALE_FLAG_ALIGN_CORNERS = (1 << 8)
    };
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_upscale(
            struct ggml_context * ctx,
            struct ggml_tensor * a,
            int scale_factor,
            enum ggml_scale_mode mode);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_upscale_ext( struct ggml_context * ctx, struct ggml_tensor * a, int ne0, int ne1, int ne2, int ne3, enum ggml_scale_mode mode) __attribute__((deprecated("use ggml_interpolate instead")));
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_interpolate(
            struct ggml_context * ctx,
            struct ggml_tensor * a,
            int64_t ne0,
            int64_t ne1,
            int64_t ne2,
            int64_t ne3,
            uint32_t mode);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_pad(
            struct ggml_context * ctx,
            struct ggml_tensor * a,
            int p0,
            int p1,
            int p2,
            int p3);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_pad_ext(
            struct ggml_context * ctx,
            struct ggml_tensor * a,
            int lp0,
            int rp0,
            int lp1,
            int rp1,
            int lp2,
            int rp2,
            int lp3,
            int rp3
            );
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_pad_reflect_1d(
            struct ggml_context * ctx,
            struct ggml_tensor * a,
            int p0,
            int p1);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_roll(
            struct ggml_context * ctx,
            struct ggml_tensor * a,
            int shift0,
            int shift1,
            int shift2,
            int shift3);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_timestep_embedding(
            struct ggml_context * ctx,
            struct ggml_tensor * timesteps,
            int dim,
            int max_period);
    enum ggml_sort_order {
        GGML_SORT_ORDER_ASC,
        GGML_SORT_ORDER_DESC,
    };
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_argsort(
            struct ggml_context * ctx,
            struct ggml_tensor * a,
            enum ggml_sort_order order);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_arange(
            struct ggml_context * ctx,
            float start,
            float stop,
            float step);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_top_k(
            struct ggml_context * ctx,
            struct ggml_tensor * a,
            int k);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_flash_attn_ext(
            struct ggml_context * ctx,
            struct ggml_tensor * q,
            struct ggml_tensor * k,
            struct ggml_tensor * v,
            struct ggml_tensor * mask,
            float scale,
            float max_bias,
            float logit_softcap);
    __attribute__ ((visibility ("default"))) extern void ggml_flash_attn_ext_set_prec(
            struct ggml_tensor * a,
            enum ggml_prec prec);
    __attribute__ ((visibility ("default"))) extern enum ggml_prec ggml_flash_attn_ext_get_prec(
            const struct ggml_tensor * a);
    __attribute__ ((visibility ("default"))) extern void ggml_flash_attn_ext_add_sinks(
            struct ggml_tensor * a,
            struct ggml_tensor * sinks);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_flash_attn_back(
           struct ggml_context * ctx,
           struct ggml_tensor * q,
           struct ggml_tensor * k,
           struct ggml_tensor * v,
           struct ggml_tensor * d,
           _Bool masked);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_ssm_conv(
            struct ggml_context * ctx,
            struct ggml_tensor * sx,
            struct ggml_tensor * c);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_ssm_scan(
            struct ggml_context * ctx,
            struct ggml_tensor * s,
            struct ggml_tensor * x,
            struct ggml_tensor * dt,
            struct ggml_tensor * A,
            struct ggml_tensor * B,
            struct ggml_tensor * C,
            struct ggml_tensor * ids);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_win_part(
            struct ggml_context * ctx,
            struct ggml_tensor * a,
            int w);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_win_unpart(
            struct ggml_context * ctx,
            struct ggml_tensor * a,
            int w0,
            int h0,
            int w);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_unary(
            struct ggml_context * ctx,
             struct ggml_tensor * a,
             enum ggml_unary_op op);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_unary_inplace(
        struct ggml_context * ctx,
        struct ggml_tensor * a,
        enum ggml_unary_op op);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_get_rel_pos(
            struct ggml_context * ctx,
            struct ggml_tensor * a,
            int qh,
            int kh);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_add_rel_pos(
            struct ggml_context * ctx,
            struct ggml_tensor * a,
            struct ggml_tensor * pw,
            struct ggml_tensor * ph);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_add_rel_pos_inplace(
            struct ggml_context * ctx,
            struct ggml_tensor * a,
            struct ggml_tensor * pw,
            struct ggml_tensor * ph);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_rwkv_wkv6(
            struct ggml_context * ctx,
            struct ggml_tensor * k,
            struct ggml_tensor * v,
            struct ggml_tensor * r,
            struct ggml_tensor * tf,
            struct ggml_tensor * td,
            struct ggml_tensor * state);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_gated_linear_attn(
            struct ggml_context * ctx,
            struct ggml_tensor * k,
            struct ggml_tensor * v,
            struct ggml_tensor * q,
            struct ggml_tensor * g,
            struct ggml_tensor * state,
            float scale);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_rwkv_wkv7(
            struct ggml_context * ctx,
            struct ggml_tensor * r,
            struct ggml_tensor * w,
            struct ggml_tensor * k,
            struct ggml_tensor * v,
            struct ggml_tensor * a,
            struct ggml_tensor * b,
            struct ggml_tensor * state);
    typedef void (*ggml_custom1_op_t)(struct ggml_tensor * dst , const struct ggml_tensor * a, int ith, int nth, void * userdata);
    typedef void (*ggml_custom2_op_t)(struct ggml_tensor * dst , const struct ggml_tensor * a, const struct ggml_tensor * b, int ith, int nth, void * userdata);
    typedef void (*ggml_custom3_op_t)(struct ggml_tensor * dst , const struct ggml_tensor * a, const struct ggml_tensor * b, const struct ggml_tensor * c, int ith, int nth, void * userdata);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_map_custom1(
            struct ggml_context * ctx,
            struct ggml_tensor * a,
            ggml_custom1_op_t fun,
            int n_tasks,
            void * userdata);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_map_custom1_inplace(
            struct ggml_context * ctx,
            struct ggml_tensor * a,
            ggml_custom1_op_t fun,
            int n_tasks,
            void * userdata);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_map_custom2(
            struct ggml_context * ctx,
            struct ggml_tensor * a,
            struct ggml_tensor * b,
            ggml_custom2_op_t fun,
            int n_tasks,
            void * userdata);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_map_custom2_inplace(
            struct ggml_context * ctx,
            struct ggml_tensor * a,
            struct ggml_tensor * b,
            ggml_custom2_op_t fun,
            int n_tasks,
            void * userdata);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_map_custom3(
            struct ggml_context * ctx,
            struct ggml_tensor * a,
            struct ggml_tensor * b,
            struct ggml_tensor * c,
            ggml_custom3_op_t fun,
            int n_tasks,
            void * userdata);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_map_custom3_inplace(
            struct ggml_context * ctx,
            struct ggml_tensor * a,
            struct ggml_tensor * b,
            struct ggml_tensor * c,
            ggml_custom3_op_t fun,
            int n_tasks,
            void * userdata);
    typedef void (*ggml_custom_op_t)(struct ggml_tensor * dst , int ith, int nth, void * userdata);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_custom_4d(
            struct ggml_context * ctx,
            enum ggml_type type,
            int64_t ne0,
            int64_t ne1,
            int64_t ne2,
            int64_t ne3,
            struct ggml_tensor ** args,
            int n_args,
            ggml_custom_op_t fun,
            int n_tasks,
            void * userdata);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_custom_inplace(
            struct ggml_context * ctx,
            struct ggml_tensor * a,
            struct ggml_tensor ** args,
            int n_args,
            ggml_custom_op_t fun,
            int n_tasks,
            void * userdata);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_cross_entropy_loss(
            struct ggml_context * ctx,
            struct ggml_tensor * a,
            struct ggml_tensor * b);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_cross_entropy_loss_back(
            struct ggml_context * ctx,
            struct ggml_tensor * a,
            struct ggml_tensor * b,
            struct ggml_tensor * c);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_opt_step_adamw(
            struct ggml_context * ctx,
            struct ggml_tensor * a,
            struct ggml_tensor * grad,
            struct ggml_tensor * m,
            struct ggml_tensor * v,
            struct ggml_tensor * adamw_params);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_opt_step_sgd(
        struct ggml_context * ctx,
        struct ggml_tensor * a,
        struct ggml_tensor * grad,
        struct ggml_tensor * sgd_params);
    __attribute__ ((visibility ("default"))) extern void ggml_build_forward_expand(struct ggml_cgraph * cgraph, struct ggml_tensor * tensor);
    __attribute__ ((visibility ("default"))) extern void ggml_build_backward_expand(
        struct ggml_context * ctx,
        struct ggml_cgraph * cgraph,
        struct ggml_tensor ** grad_accs);
    __attribute__ ((visibility ("default"))) extern struct ggml_cgraph * ggml_new_graph (struct ggml_context * ctx);
    __attribute__ ((visibility ("default"))) extern struct ggml_cgraph * ggml_new_graph_custom(struct ggml_context * ctx, size_t size, _Bool grads);
    __attribute__ ((visibility ("default"))) extern struct ggml_cgraph * ggml_graph_dup (struct ggml_context * ctx, struct ggml_cgraph * cgraph, _Bool force_grads);
    __attribute__ ((visibility ("default"))) extern void ggml_graph_cpy (struct ggml_cgraph * src, struct ggml_cgraph * dst);
    __attribute__ ((visibility ("default"))) extern void ggml_graph_reset (struct ggml_cgraph * cgraph);
    __attribute__ ((visibility ("default"))) extern void ggml_graph_clear (struct ggml_cgraph * cgraph);
    __attribute__ ((visibility ("default"))) extern int ggml_graph_size (struct ggml_cgraph * cgraph);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_graph_node (struct ggml_cgraph * cgraph, int i);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor ** ggml_graph_nodes (struct ggml_cgraph * cgraph);
    __attribute__ ((visibility ("default"))) extern int ggml_graph_n_nodes(struct ggml_cgraph * cgraph);
    __attribute__ ((visibility ("default"))) extern void ggml_graph_add_node(struct ggml_cgraph * cgraph, struct ggml_tensor * tensor);
    __attribute__ ((visibility ("default"))) extern size_t ggml_graph_overhead(void);
    __attribute__ ((visibility ("default"))) extern size_t ggml_graph_overhead_custom(size_t size, _Bool grads);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_graph_get_tensor (const struct ggml_cgraph * cgraph, const char * name);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_graph_get_grad (const struct ggml_cgraph * cgraph, const struct ggml_tensor * node);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_graph_get_grad_acc(const struct ggml_cgraph * cgraph, const struct ggml_tensor * node);
    __attribute__ ((visibility ("default"))) extern void ggml_graph_print(const struct ggml_cgraph * cgraph);
    __attribute__ ((visibility ("default"))) extern void ggml_graph_dump_dot(const struct ggml_cgraph * gb, const struct ggml_cgraph * gf, const char * filename);
    typedef void (*ggml_log_callback)(enum ggml_log_level level, const char * text, void * user_data);
    __attribute__ ((visibility ("default"))) extern void ggml_log_set(ggml_log_callback log_callback, void * user_data);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_set_zero(struct ggml_tensor * tensor);
    __attribute__ ((visibility ("default"))) extern void ggml_quantize_init(enum ggml_type type);
    __attribute__ ((visibility ("default"))) extern void ggml_quantize_free(void);
    __attribute__ ((visibility ("default"))) extern _Bool ggml_quantize_requires_imatrix(enum ggml_type type);
    __attribute__ ((visibility ("default"))) extern size_t ggml_quantize_chunk(
            enum ggml_type type,
               const float * src,
                      void * dst,
                   int64_t start,
                   int64_t nrows,
                   int64_t n_per_row,
               const float * imatrix);
    typedef void (*ggml_to_float_t) (const void * restrict x, float * restrict y, int64_t k);
    typedef void (*ggml_from_float_t)(const float * restrict x, void * restrict y, int64_t k);
    struct ggml_type_traits {
        const char * type_name;
        int64_t blck_size;
        int64_t blck_size_interleave;
        size_t type_size;
        _Bool is_quantized;
        ggml_to_float_t to_float;
        ggml_from_float_t from_float_ref;
    };
    __attribute__ ((visibility ("default"))) extern const struct ggml_type_traits * ggml_get_type_traits(enum ggml_type type);
    enum ggml_sched_priority {
        GGML_SCHED_PRIO_LOW = -1,
        GGML_SCHED_PRIO_NORMAL,
        GGML_SCHED_PRIO_MEDIUM,
        GGML_SCHED_PRIO_HIGH,
        GGML_SCHED_PRIO_REALTIME
    };
    struct ggml_threadpool_params {
        _Bool cpumask[512];
        int n_threads;
        enum ggml_sched_priority prio;
        uint32_t poll;
        _Bool strict_cpu;
        _Bool paused;
    };
    struct ggml_threadpool;
    typedef struct ggml_threadpool * ggml_threadpool_t;
    __attribute__ ((visibility ("default"))) extern struct ggml_threadpool_params ggml_threadpool_params_default(int n_threads);
    __attribute__ ((visibility ("default"))) extern void ggml_threadpool_params_init (struct ggml_threadpool_params * p, int n_threads);
    __attribute__ ((visibility ("default"))) extern _Bool ggml_threadpool_params_match (const struct ggml_threadpool_params * p0, const struct ggml_threadpool_params * p1);
       
extern int NTHREAD;
extern volatile int IMAX_READY;
extern int IMAX_DMABUF_LAST;
extern int is_last_token;
struct imax_dmabuf_map {
    void * src_blk_top;
    Ull blk_size;
    Ull imax_blk_ofs;
    int dmabufmap;
};
struct th_inference_args {
    int thid;
    int dmy0[15];
    int stat;
    int dmy1[15];
    sigset_t sigset;
    int dmy2[15];
    int deq;
    int dmy3[15];
    int enq;
    int dmy4[15];
    void * dst;
    Ull num_rows_per_vec_dot;
    Ull ir0_start;
    Ull ir0_end;
    Ull ir1_start;
    Ull ir1_end;
    const void * src0;
    const void * src1;
    int type;
    int src1_cont;
    void * vec_dot;
    int vec_dot_type;
    const void * wdata;
    int row_size;
    Ull r2;
    Ull r3;
    Ull blck_0;
    Ull blck_1;
    size_t src1_col_stride;
};
extern volatile struct imax_dmabuf_map imax_dmabuf_map[16];
extern volatile struct th_inference_args th_inference_args[16];
extern volatile int th_inference_retv[16];
extern pthread_t th_inference_t[16];
extern volatile int th_inference_retv[16];
extern pthread_t th_inference_t[16];
       
       
       
typedef struct ggml_backend_buffer_type * ggml_backend_buffer_type_t;
typedef struct ggml_backend_buffer * ggml_backend_buffer_t;
typedef struct ggml_backend * ggml_backend_t;
struct ggml_tallocr {
    ggml_backend_buffer_t buffer;
    void * base;
    size_t alignment;
    size_t offset;
};
__attribute__ ((visibility ("default"))) extern struct ggml_tallocr ggml_tallocr_new(ggml_backend_buffer_t buffer);
__attribute__ ((visibility ("default"))) extern enum ggml_status ggml_tallocr_alloc(struct ggml_tallocr * talloc, struct ggml_tensor * tensor);
typedef struct ggml_gallocr * ggml_gallocr_t;
__attribute__ ((visibility ("default"))) extern ggml_gallocr_t ggml_gallocr_new(ggml_backend_buffer_type_t buft);
__attribute__ ((visibility ("default"))) extern ggml_gallocr_t ggml_gallocr_new_n(ggml_backend_buffer_type_t * bufts, int n_bufs);
__attribute__ ((visibility ("default"))) extern void ggml_gallocr_free(ggml_gallocr_t galloc);
__attribute__ ((visibility ("default"))) extern _Bool ggml_gallocr_reserve(ggml_gallocr_t galloc, struct ggml_cgraph * graph);
__attribute__ ((visibility ("default"))) extern _Bool ggml_gallocr_reserve_n(
    ggml_gallocr_t galloc,
    struct ggml_cgraph * graph,
    const int * node_buffer_ids,
    const int * leaf_buffer_ids);
__attribute__ ((visibility ("default"))) extern _Bool ggml_gallocr_alloc_graph(ggml_gallocr_t galloc, struct ggml_cgraph * graph);
__attribute__ ((visibility ("default"))) extern size_t ggml_gallocr_get_buffer_size(ggml_gallocr_t galloc, int buffer_id);
__attribute__ ((visibility ("default"))) extern struct ggml_backend_buffer * ggml_backend_alloc_ctx_tensors_from_buft(struct ggml_context * ctx, ggml_backend_buffer_type_t buft);
__attribute__ ((visibility ("default"))) extern struct ggml_backend_buffer * ggml_backend_alloc_ctx_tensors(struct ggml_context * ctx, ggml_backend_t backend);
    typedef struct ggml_backend_buffer_type * ggml_backend_buffer_type_t;
    typedef struct ggml_backend_buffer * ggml_backend_buffer_t;
    typedef struct ggml_backend_event * ggml_backend_event_t;
    typedef struct ggml_backend * ggml_backend_t;
    typedef void * ggml_backend_graph_plan_t;
    typedef struct ggml_backend_reg * ggml_backend_reg_t;
    typedef struct ggml_backend_device * ggml_backend_dev_t;
    __attribute__ ((visibility ("default"))) extern const char * ggml_backend_buft_name (ggml_backend_buffer_type_t buft);
    __attribute__ ((visibility ("default"))) extern ggml_backend_buffer_t ggml_backend_buft_alloc_buffer (ggml_backend_buffer_type_t buft, size_t size);
    __attribute__ ((visibility ("default"))) extern size_t ggml_backend_buft_get_alignment (ggml_backend_buffer_type_t buft);
    __attribute__ ((visibility ("default"))) extern size_t ggml_backend_buft_get_max_size (ggml_backend_buffer_type_t buft);
    __attribute__ ((visibility ("default"))) extern size_t ggml_backend_buft_get_alloc_size(ggml_backend_buffer_type_t buft, const struct ggml_tensor * tensor);
    __attribute__ ((visibility ("default"))) extern _Bool ggml_backend_buft_is_host (ggml_backend_buffer_type_t buft);
    __attribute__ ((visibility ("default"))) extern ggml_backend_dev_t ggml_backend_buft_get_device (ggml_backend_buffer_type_t buft);
    enum ggml_backend_buffer_usage {
        GGML_BACKEND_BUFFER_USAGE_ANY = 0,
        GGML_BACKEND_BUFFER_USAGE_WEIGHTS = 1,
        GGML_BACKEND_BUFFER_USAGE_COMPUTE = 2,
    };
    __attribute__ ((visibility ("default"))) extern const char * ggml_backend_buffer_name (ggml_backend_buffer_t buffer);
    __attribute__ ((visibility ("default"))) extern void ggml_backend_buffer_free (ggml_backend_buffer_t buffer);
    __attribute__ ((visibility ("default"))) extern void * ggml_backend_buffer_get_base (ggml_backend_buffer_t buffer);
    __attribute__ ((visibility ("default"))) extern size_t ggml_backend_buffer_get_size (ggml_backend_buffer_t buffer);
    __attribute__ ((visibility ("default"))) extern enum ggml_status ggml_backend_buffer_init_tensor (ggml_backend_buffer_t buffer, struct ggml_tensor * tensor);
    __attribute__ ((visibility ("default"))) extern size_t ggml_backend_buffer_get_alignment (ggml_backend_buffer_t buffer);
    __attribute__ ((visibility ("default"))) extern size_t ggml_backend_buffer_get_max_size (ggml_backend_buffer_t buffer);
    __attribute__ ((visibility ("default"))) extern size_t ggml_backend_buffer_get_alloc_size(ggml_backend_buffer_t buffer, const struct ggml_tensor * tensor);
    __attribute__ ((visibility ("default"))) extern void ggml_backend_buffer_clear (ggml_backend_buffer_t buffer, uint8_t value);
    __attribute__ ((visibility ("default"))) extern _Bool ggml_backend_buffer_is_host (ggml_backend_buffer_t buffer);
    __attribute__ ((visibility ("default"))) extern void ggml_backend_buffer_set_usage (ggml_backend_buffer_t buffer, enum ggml_backend_buffer_usage usage);
    __attribute__ ((visibility ("default"))) extern enum ggml_backend_buffer_usage ggml_backend_buffer_get_usage (ggml_backend_buffer_t buffer);
    __attribute__ ((visibility ("default"))) extern ggml_backend_buffer_type_t ggml_backend_buffer_get_type (ggml_backend_buffer_t buffer);
    __attribute__ ((visibility ("default"))) extern void ggml_backend_buffer_reset (ggml_backend_buffer_t buffer);
    __attribute__ ((visibility ("default"))) extern void ggml_backend_tensor_copy(struct ggml_tensor * src, struct ggml_tensor * dst);
    __attribute__ ((visibility ("default"))) extern ggml_guid_t ggml_backend_guid(ggml_backend_t backend);
    __attribute__ ((visibility ("default"))) extern const char * ggml_backend_name(ggml_backend_t backend);
    __attribute__ ((visibility ("default"))) extern void ggml_backend_free(ggml_backend_t backend);
    __attribute__ ((visibility ("default"))) extern ggml_backend_buffer_type_t ggml_backend_get_default_buffer_type(ggml_backend_t backend);
    __attribute__ ((visibility ("default"))) extern ggml_backend_buffer_t ggml_backend_alloc_buffer(ggml_backend_t backend, size_t size);
    __attribute__ ((visibility ("default"))) extern size_t ggml_backend_get_alignment(ggml_backend_t backend);
    __attribute__ ((visibility ("default"))) extern size_t ggml_backend_get_max_size(ggml_backend_t backend);
    __attribute__ ((visibility ("default"))) extern void ggml_backend_tensor_set_async(ggml_backend_t backend, struct ggml_tensor * tensor, const void * data, size_t offset, size_t size);
    __attribute__ ((visibility ("default"))) extern void ggml_backend_tensor_get_async(ggml_backend_t backend, const struct ggml_tensor * tensor, void * data, size_t offset, size_t size);
    __attribute__ ((visibility ("default"))) extern void ggml_backend_tensor_set( struct ggml_tensor * tensor, const void * data, size_t offset, size_t size);
    __attribute__ ((visibility ("default"))) extern void ggml_backend_tensor_get(const struct ggml_tensor * tensor, void * data, size_t offset, size_t size);
    __attribute__ ((visibility ("default"))) extern void ggml_backend_tensor_memset( struct ggml_tensor * tensor, uint8_t value, size_t offset, size_t size);
    __attribute__ ((visibility ("default"))) extern void ggml_backend_synchronize(ggml_backend_t backend);
    __attribute__ ((visibility ("default"))) extern ggml_backend_graph_plan_t ggml_backend_graph_plan_create(ggml_backend_t backend, struct ggml_cgraph * cgraph);
    __attribute__ ((visibility ("default"))) extern void ggml_backend_graph_plan_free (ggml_backend_t backend, ggml_backend_graph_plan_t plan);
    __attribute__ ((visibility ("default"))) extern enum ggml_status ggml_backend_graph_plan_compute (ggml_backend_t backend, ggml_backend_graph_plan_t plan);
    __attribute__ ((visibility ("default"))) extern enum ggml_status ggml_backend_graph_compute (ggml_backend_t backend, struct ggml_cgraph * cgraph);
    __attribute__ ((visibility ("default"))) extern enum ggml_status ggml_backend_graph_compute_async(ggml_backend_t backend, struct ggml_cgraph * cgraph);
    __attribute__ ((visibility ("default"))) extern _Bool ggml_backend_supports_op(ggml_backend_t backend, const struct ggml_tensor * op);
    __attribute__ ((visibility ("default"))) extern _Bool ggml_backend_supports_buft(ggml_backend_t backend, ggml_backend_buffer_type_t buft);
    __attribute__ ((visibility ("default"))) extern _Bool ggml_backend_offload_op(ggml_backend_t backend, const struct ggml_tensor * op);
    __attribute__ ((visibility ("default"))) extern void ggml_backend_tensor_copy_async(ggml_backend_t backend_src, ggml_backend_t backend_dst, struct ggml_tensor * src, struct ggml_tensor * dst);
    __attribute__ ((visibility ("default"))) extern ggml_backend_dev_t ggml_backend_get_device(ggml_backend_t backend);
    __attribute__ ((visibility ("default"))) extern ggml_backend_event_t ggml_backend_event_new(ggml_backend_dev_t device);
    __attribute__ ((visibility ("default"))) extern void ggml_backend_event_free(ggml_backend_event_t event);
    __attribute__ ((visibility ("default"))) extern void ggml_backend_event_record(ggml_backend_event_t event, ggml_backend_t backend);
    __attribute__ ((visibility ("default"))) extern void ggml_backend_event_synchronize(ggml_backend_event_t event);
    __attribute__ ((visibility ("default"))) extern void ggml_backend_event_wait(ggml_backend_t backend, ggml_backend_event_t event);
    enum ggml_backend_dev_type {
        GGML_BACKEND_DEVICE_TYPE_CPU,
        GGML_BACKEND_DEVICE_TYPE_GPU,
        GGML_BACKEND_DEVICE_TYPE_IGPU,
        GGML_BACKEND_DEVICE_TYPE_ACCEL
    };
    struct ggml_backend_dev_caps {
        _Bool async;
        _Bool host_buffer;
        _Bool buffer_from_host_ptr;
        _Bool events;
    };
    struct ggml_backend_dev_props {
        const char * name;
        const char * description;
        size_t memory_free;
        size_t memory_total;
        enum ggml_backend_dev_type type;
        const char * device_id;
        struct ggml_backend_dev_caps caps;
    };
    __attribute__ ((visibility ("default"))) extern const char * ggml_backend_dev_name(ggml_backend_dev_t device);
    __attribute__ ((visibility ("default"))) extern const char * ggml_backend_dev_description(ggml_backend_dev_t device);
    __attribute__ ((visibility ("default"))) extern void ggml_backend_dev_memory(ggml_backend_dev_t device, size_t * free, size_t * total);
    __attribute__ ((visibility ("default"))) extern enum ggml_backend_dev_type ggml_backend_dev_type(ggml_backend_dev_t device);
    __attribute__ ((visibility ("default"))) extern void ggml_backend_dev_get_props(ggml_backend_dev_t device, struct ggml_backend_dev_props * props);
    __attribute__ ((visibility ("default"))) extern ggml_backend_reg_t ggml_backend_dev_backend_reg(ggml_backend_dev_t device);
    __attribute__ ((visibility ("default"))) extern ggml_backend_t ggml_backend_dev_init(ggml_backend_dev_t device, const char * params);
    __attribute__ ((visibility ("default"))) extern ggml_backend_buffer_type_t ggml_backend_dev_buffer_type(ggml_backend_dev_t device);
    __attribute__ ((visibility ("default"))) extern ggml_backend_buffer_type_t ggml_backend_dev_host_buffer_type(ggml_backend_dev_t device);
    __attribute__ ((visibility ("default"))) extern ggml_backend_buffer_t ggml_backend_dev_buffer_from_host_ptr(ggml_backend_dev_t device, void * ptr, size_t size, size_t max_tensor_size);
    __attribute__ ((visibility ("default"))) extern _Bool ggml_backend_dev_supports_op(ggml_backend_dev_t device, const struct ggml_tensor * op);
    __attribute__ ((visibility ("default"))) extern _Bool ggml_backend_dev_supports_buft(ggml_backend_dev_t device, ggml_backend_buffer_type_t buft);
    __attribute__ ((visibility ("default"))) extern _Bool ggml_backend_dev_offload_op(ggml_backend_dev_t device, const struct ggml_tensor * op);
    __attribute__ ((visibility ("default"))) extern const char * ggml_backend_reg_name(ggml_backend_reg_t reg);
    __attribute__ ((visibility ("default"))) extern size_t ggml_backend_reg_dev_count(ggml_backend_reg_t reg);
    __attribute__ ((visibility ("default"))) extern ggml_backend_dev_t ggml_backend_reg_dev_get(ggml_backend_reg_t reg, size_t index);
    __attribute__ ((visibility ("default"))) extern void * ggml_backend_reg_get_proc_address(ggml_backend_reg_t reg, const char * name);
    typedef ggml_backend_buffer_type_t (*ggml_backend_split_buffer_type_t)(int main_device, const float * tensor_split);
    typedef void (*ggml_backend_set_n_threads_t)(ggml_backend_t backend, int n_threads);
    typedef ggml_backend_buffer_type_t * (*ggml_backend_dev_get_extra_bufts_t)(ggml_backend_dev_t device);
    typedef void (*ggml_backend_set_abort_callback_t)(ggml_backend_t backend, ggml_abort_callback abort_callback, void * abort_callback_data);
    struct ggml_backend_feature {
        const char * name;
        const char * value;
    };
    typedef struct ggml_backend_feature * (*ggml_backend_get_features_t)(ggml_backend_reg_t reg);
    __attribute__ ((visibility ("default"))) extern void ggml_backend_register(ggml_backend_reg_t reg);
    __attribute__ ((visibility ("default"))) extern void ggml_backend_device_register(ggml_backend_dev_t device);
    __attribute__ ((visibility ("default"))) extern size_t ggml_backend_reg_count(void);
    __attribute__ ((visibility ("default"))) extern ggml_backend_reg_t ggml_backend_reg_get(size_t index);
    __attribute__ ((visibility ("default"))) extern ggml_backend_reg_t ggml_backend_reg_by_name(const char * name);
    __attribute__ ((visibility ("default"))) extern size_t ggml_backend_dev_count(void);
    __attribute__ ((visibility ("default"))) extern ggml_backend_dev_t ggml_backend_dev_get(size_t index);
    __attribute__ ((visibility ("default"))) extern ggml_backend_dev_t ggml_backend_dev_by_name(const char * name);
    __attribute__ ((visibility ("default"))) extern ggml_backend_dev_t ggml_backend_dev_by_type(enum ggml_backend_dev_type type);
    __attribute__ ((visibility ("default"))) extern ggml_backend_t ggml_backend_init_by_name(const char * name, const char * params);
    __attribute__ ((visibility ("default"))) extern ggml_backend_t ggml_backend_init_by_type(enum ggml_backend_dev_type type, const char * params);
    __attribute__ ((visibility ("default"))) extern ggml_backend_t ggml_backend_init_best(void);
    __attribute__ ((visibility ("default"))) extern ggml_backend_reg_t ggml_backend_load(const char * path);
    __attribute__ ((visibility ("default"))) extern void ggml_backend_unload(ggml_backend_reg_t reg);
    __attribute__ ((visibility ("default"))) extern void ggml_backend_load_all(void);
    __attribute__ ((visibility ("default"))) extern void ggml_backend_load_all_from_path(const char * dir_path);
    typedef struct ggml_backend_sched * ggml_backend_sched_t;
    typedef _Bool (*ggml_backend_sched_eval_callback)(struct ggml_tensor * t, _Bool ask, void * user_data);
    __attribute__ ((visibility ("default"))) extern ggml_backend_sched_t ggml_backend_sched_new(ggml_backend_t * backends, ggml_backend_buffer_type_t * bufts, int n_backends, size_t graph_size, _Bool parallel, _Bool op_offload);
    __attribute__ ((visibility ("default"))) extern void ggml_backend_sched_free(ggml_backend_sched_t sched);
    __attribute__ ((visibility ("default"))) extern _Bool ggml_backend_sched_reserve(ggml_backend_sched_t sched, struct ggml_cgraph * measure_graph);
    __attribute__ ((visibility ("default"))) extern int ggml_backend_sched_get_n_backends(ggml_backend_sched_t sched);
    __attribute__ ((visibility ("default"))) extern ggml_backend_t ggml_backend_sched_get_backend(ggml_backend_sched_t sched, int i);
    __attribute__ ((visibility ("default"))) extern int ggml_backend_sched_get_n_splits(ggml_backend_sched_t sched);
    __attribute__ ((visibility ("default"))) extern int ggml_backend_sched_get_n_copies(ggml_backend_sched_t sched);
    __attribute__ ((visibility ("default"))) extern ggml_backend_buffer_type_t ggml_backend_sched_get_buffer_type(ggml_backend_sched_t sched, ggml_backend_t backend);
    __attribute__ ((visibility ("default"))) extern size_t ggml_backend_sched_get_buffer_size(ggml_backend_sched_t sched, ggml_backend_t backend);
    __attribute__ ((visibility ("default"))) extern void ggml_backend_sched_set_tensor_backend(ggml_backend_sched_t sched, struct ggml_tensor * node, ggml_backend_t backend);
    __attribute__ ((visibility ("default"))) extern ggml_backend_t ggml_backend_sched_get_tensor_backend(ggml_backend_sched_t sched, struct ggml_tensor * node);
    __attribute__ ((visibility ("default"))) extern void ggml_backend_sched_split_graph(ggml_backend_sched_t sched, struct ggml_cgraph * graph);
    __attribute__ ((visibility ("default"))) extern _Bool ggml_backend_sched_alloc_graph(ggml_backend_sched_t sched, struct ggml_cgraph * graph);
    __attribute__ ((visibility ("default"))) extern enum ggml_status ggml_backend_sched_graph_compute(ggml_backend_sched_t sched, struct ggml_cgraph * graph);
    __attribute__ ((visibility ("default"))) extern enum ggml_status ggml_backend_sched_graph_compute_async(ggml_backend_sched_t sched, struct ggml_cgraph * graph);
    __attribute__ ((visibility ("default"))) extern void ggml_backend_sched_synchronize(ggml_backend_sched_t sched);
    __attribute__ ((visibility ("default"))) extern void ggml_backend_sched_reset(ggml_backend_sched_t sched);
    __attribute__ ((visibility ("default"))) extern void ggml_backend_sched_set_eval_callback(ggml_backend_sched_t sched, ggml_backend_sched_eval_callback callback, void * user_data);
    struct ggml_backend_graph_copy {
        ggml_backend_buffer_t buffer;
        struct ggml_context * ctx_allocated;
        struct ggml_context * ctx_unallocated;
        struct ggml_cgraph * graph;
    };
    __attribute__ ((visibility ("default"))) extern struct ggml_backend_graph_copy ggml_backend_graph_copy(ggml_backend_t backend, struct ggml_cgraph * graph);
    __attribute__ ((visibility ("default"))) extern void ggml_backend_graph_copy_free(struct ggml_backend_graph_copy copy);
    typedef _Bool (*ggml_backend_eval_callback)(int node_index, struct ggml_tensor * t1, struct ggml_tensor * t2, void * user_data);
    __attribute__ ((visibility ("default"))) extern _Bool ggml_backend_compare_graph_backend(ggml_backend_t backend1, ggml_backend_t backend2, struct ggml_cgraph * graph, ggml_backend_eval_callback callback, void * user_data, struct ggml_tensor * test_node);
    __attribute__ ((visibility ("default"))) extern enum ggml_status ggml_backend_tensor_alloc(ggml_backend_buffer_t buffer, struct ggml_tensor * tensor, void * addr);
    __attribute__ ((visibility ("default"))) extern enum ggml_status ggml_backend_view_init(struct ggml_tensor * tensor);
    __attribute__ ((visibility ("default"))) extern ggml_backend_buffer_t ggml_backend_cpu_buffer_from_ptr(void * ptr, size_t size);
    __attribute__ ((visibility ("default"))) extern ggml_backend_buffer_type_t ggml_backend_cpu_buffer_type(void);
    struct ggml_cplan {
        size_t work_size;
        uint8_t * work_data;
        int n_threads;
        struct ggml_threadpool * threadpool;
        ggml_abort_callback abort_callback;
        void * abort_callback_data;
    };
    enum ggml_numa_strategy {
        GGML_NUMA_STRATEGY_DISABLED = 0,
        GGML_NUMA_STRATEGY_DISTRIBUTE = 1,
        GGML_NUMA_STRATEGY_ISOLATE = 2,
        GGML_NUMA_STRATEGY_NUMACTL = 3,
        GGML_NUMA_STRATEGY_MIRROR = 4,
        GGML_NUMA_STRATEGY_COUNT
    };
    __attribute__ ((visibility ("default"))) extern void ggml_numa_init(enum ggml_numa_strategy numa);
    __attribute__ ((visibility ("default"))) extern _Bool ggml_is_numa(void);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_new_i32(struct ggml_context * ctx, int32_t value);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_new_f32(struct ggml_context * ctx, float value);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_set_i32 (struct ggml_tensor * tensor, int32_t value);
    __attribute__ ((visibility ("default"))) extern struct ggml_tensor * ggml_set_f32 (struct ggml_tensor * tensor, float value);
    __attribute__ ((visibility ("default"))) extern int32_t ggml_get_i32_1d(const struct ggml_tensor * tensor, int i);
    __attribute__ ((visibility ("default"))) extern void ggml_set_i32_1d(const struct ggml_tensor * tensor, int i, int32_t value);
    __attribute__ ((visibility ("default"))) extern int32_t ggml_get_i32_nd(const struct ggml_tensor * tensor, int i0, int i1, int i2, int i3);
    __attribute__ ((visibility ("default"))) extern void ggml_set_i32_nd(const struct ggml_tensor * tensor, int i0, int i1, int i2, int i3, int32_t value);
    __attribute__ ((visibility ("default"))) extern float ggml_get_f32_1d(const struct ggml_tensor * tensor, int i);
    __attribute__ ((visibility ("default"))) extern void ggml_set_f32_1d(const struct ggml_tensor * tensor, int i, float value);
    __attribute__ ((visibility ("default"))) extern float ggml_get_f32_nd(const struct ggml_tensor * tensor, int i0, int i1, int i2, int i3);
    __attribute__ ((visibility ("default"))) extern void ggml_set_f32_nd(const struct ggml_tensor * tensor, int i0, int i1, int i2, int i3, float value);
    __attribute__ ((visibility ("default"))) extern struct ggml_threadpool * ggml_threadpool_new (struct ggml_threadpool_params * params);
    __attribute__ ((visibility ("default"))) extern void ggml_threadpool_free (struct ggml_threadpool * threadpool);
    __attribute__ ((visibility ("default"))) extern int ggml_threadpool_get_n_threads (struct ggml_threadpool * threadpool);
    __attribute__ ((visibility ("default"))) extern void ggml_threadpool_pause (struct ggml_threadpool * threadpool);
    __attribute__ ((visibility ("default"))) extern void ggml_threadpool_resume (struct ggml_threadpool * threadpool);
    __attribute__ ((visibility ("default"))) extern struct ggml_cplan ggml_graph_plan(
                  const struct ggml_cgraph * cgraph,
                                       int n_threads,
                    struct ggml_threadpool * threadpool );
    __attribute__ ((visibility ("default"))) extern enum ggml_status ggml_graph_compute(struct ggml_cgraph * cgraph, struct ggml_cplan * cplan);
    __attribute__ ((visibility ("default"))) extern enum ggml_status ggml_graph_compute_with_ctx(struct ggml_context * ctx, struct ggml_cgraph * cgraph, int n_threads);
    __attribute__ ((visibility ("default"))) extern int ggml_cpu_has_sse3 (void);
    __attribute__ ((visibility ("default"))) extern int ggml_cpu_has_ssse3 (void);
    __attribute__ ((visibility ("default"))) extern int ggml_cpu_has_avx (void);
    __attribute__ ((visibility ("default"))) extern int ggml_cpu_has_avx_vnni (void);
    __attribute__ ((visibility ("default"))) extern int ggml_cpu_has_avx2 (void);
    __attribute__ ((visibility ("default"))) extern int ggml_cpu_has_bmi2 (void);
    __attribute__ ((visibility ("default"))) extern int ggml_cpu_has_f16c (void);
    __attribute__ ((visibility ("default"))) extern int ggml_cpu_has_fma (void);
    __attribute__ ((visibility ("default"))) extern int ggml_cpu_has_avx512 (void);
    __attribute__ ((visibility ("default"))) extern int ggml_cpu_has_avx512_vbmi(void);
    __attribute__ ((visibility ("default"))) extern int ggml_cpu_has_avx512_vnni(void);
    __attribute__ ((visibility ("default"))) extern int ggml_cpu_has_avx512_bf16(void);
    __attribute__ ((visibility ("default"))) extern int ggml_cpu_has_amx_int8 (void);
    __attribute__ ((visibility ("default"))) extern int ggml_cpu_has_neon (void);
    __attribute__ ((visibility ("default"))) extern int ggml_cpu_has_arm_fma (void);
    __attribute__ ((visibility ("default"))) extern int ggml_cpu_has_fp16_va (void);
    __attribute__ ((visibility ("default"))) extern int ggml_cpu_has_dotprod (void);
    __attribute__ ((visibility ("default"))) extern int ggml_cpu_has_matmul_int8(void);
    __attribute__ ((visibility ("default"))) extern int ggml_cpu_has_sve (void);
    __attribute__ ((visibility ("default"))) extern int ggml_cpu_get_sve_cnt (void);
    __attribute__ ((visibility ("default"))) extern int ggml_cpu_has_sme (void);
    __attribute__ ((visibility ("default"))) extern int ggml_cpu_has_riscv_v (void);
    __attribute__ ((visibility ("default"))) extern int ggml_cpu_has_vsx (void);
    __attribute__ ((visibility ("default"))) extern int ggml_cpu_has_vxe (void);
    __attribute__ ((visibility ("default"))) extern int ggml_cpu_has_wasm_simd (void);
    __attribute__ ((visibility ("default"))) extern int ggml_cpu_has_llamafile (void);
    typedef void (*ggml_vec_dot_t) (int n, float * restrict s, size_t bs, const void * restrict x, size_t bx,
                                       const void * restrict y, size_t by, int nrc);
    struct ggml_type_traits_cpu {
        ggml_from_float_t from_float;
        ggml_vec_dot_t vec_dot;
        enum ggml_type vec_dot_type;
        int64_t nrows;
    };
    __attribute__ ((visibility ("default"))) extern const struct ggml_type_traits_cpu * ggml_get_type_traits_cpu(enum ggml_type type);
    __attribute__ ((visibility ("default"))) extern void ggml_cpu_init(void);
    __attribute__ ((visibility ("default"))) extern ggml_backend_t ggml_backend_cpu_init(void);
    __attribute__ ((visibility ("default"))) extern _Bool ggml_backend_is_cpu (ggml_backend_t backend);
    __attribute__ ((visibility ("default"))) extern void ggml_backend_cpu_set_n_threads (ggml_backend_t backend_cpu, int n_threads);
    __attribute__ ((visibility ("default"))) extern void ggml_backend_cpu_set_threadpool (ggml_backend_t backend_cpu, ggml_threadpool_t threadpool);
    __attribute__ ((visibility ("default"))) extern void ggml_backend_cpu_set_abort_callback(ggml_backend_t backend_cpu, ggml_abort_callback abort_callback, void * abort_callback_data);
    __attribute__ ((visibility ("default"))) extern ggml_backend_reg_t ggml_backend_cpu_reg(void);
    __attribute__ ((visibility ("default"))) extern void ggml_cpu_fp32_to_fp32(const float *, float *, int64_t);
    __attribute__ ((visibility ("default"))) extern void ggml_cpu_fp32_to_i32 (const float *, int32_t *, int64_t);
    __attribute__ ((visibility ("default"))) extern void ggml_cpu_fp32_to_fp16(const float *, ggml_fp16_t *, int64_t);
    __attribute__ ((visibility ("default"))) extern void ggml_cpu_fp16_to_fp32(const ggml_fp16_t *, float *, int64_t);
    __attribute__ ((visibility ("default"))) extern void ggml_cpu_fp32_to_bf16(const float *, ggml_bf16_t *, int64_t);
    __attribute__ ((visibility ("default"))) extern void ggml_cpu_bf16_to_fp32(const ggml_bf16_t *, float *, int64_t);
       
extern int final_token_number;
void reset_time();
void show_time();
void monitor_time_start(int, int);
void monitor_time_end(int, int);
void show_time_sep(void);
void monitor_increment_count(int id);
void reset_enum_counts(void);
void show_enum_counts(void);
void reset_cpyin_stats(void);
void count_cpyin_q3k(size_t size_bytes);
void count_cpyin_q80(size_t size_bytes);
void show_cpyin_stats(void);
typedef enum {
  T_MAIN,
  T_MAIN_WHILE,
  T_MAIN_GA_N_EQ1,
  T_MAIN_GA_N_NE1,
  T_MAIN_SESSION,
  T_MAIN_EMBD_SIZE,
  T_LLAMA_GRAPH_COMPUTE,
  T_GGML_BACKEND_SCHED_COMPUTE_SPLITS,
  T_GGML_GRAPH_COMPUTE,
  T_COMPUTE_FORWARD,
  T_COMPUTE_FORWARD_DUP,
  T_COMPUTE_FORWARD_ADD,
  T_COMPUTE_FORWARD_ADD_ID,
  T_COMPUTE_FORWARD_ADD1,
  T_COMPUTE_FORWARD_ACC,
  T_COMPUTE_FORWARD_SUB,
  T_COMPUTE_FORWARD_MUL,
  T_COMPUTE_FORWARD_DIV,
  T_COMPUTE_FORWARD_SQR,
  T_COMPUTE_FORWARD_SQRT,
  T_COMPUTE_FORWARD_LOG,
  T_COMPUTE_FORWARD_SUM,
  T_COMPUTE_FORWARD_SUM_ROWS,
  T_COMPUTE_FORWARD_MEAN,
  T_COMPUTE_FORWARD_ARGMAX,
  T_COMPUTE_FORWARD_REPEAT,
  T_COMPUTE_FORWARD_REPEAT_BACK,
  T_COMPUTE_FORWARD_CONCAT,
  T_COMPUTE_FORWARD_SILU_BACK,
  T_COMPUTE_FORWARD_NORM,
  T_COMPUTE_FORWARD_RMS_NORM,
  T_COMPUTE_FORWARD_RMS_NORM_BACK,
  T_COMPUTE_FORWARD_GROUP_NORM,
  T_COMPUTE_FORWARD_MUL_MAT,
  T_COMPUTE_FORWARD_MUL_MAT_NE_VEC_DOT,
  T_COMPUTE_FORWARD_MUL_MAT_NDIMS_EQ_2,
  T_COMPUTE_FORWARD_MUL_MAT_WHILE_CHUNK,
  T_COMPUTE_FORWARD_MUL_MAT_ONE_CHUNK,
  IMAX_COMPUTE_FORWARD_MUL_MAT_ONE_CHUNK_F32,
  IMAX_COMPUTE_FORWARD_MUL_MAT_ONE_CHUNK_F32_ARM,
  IMAX_COMPUTE_FORWARD_MUL_MAT_ONE_CHUNK_F16,
  IMAX_COMPUTE_FORWARD_MUL_MAT_ONE_CHUNK_F16_ARM,
  IMAX_COMPUTE_FORWARD_MUL_MAT_ONE_CHUNK_Q2K,
  IMAX_COMPUTE_FORWARD_MUL_MAT_ONE_CHUNK_Q2K_ARM,
  IMAX_COMPUTE_FORWARD_MUL_MAT_ONE_CHUNK_Q3K,
  IMAX_COMPUTE_FORWARD_MUL_MAT_ONE_CHUNK_Q3K_ARM,
  IMAX_COMPUTE_FORWARD_MUL_MAT_ONE_CHUNK_Q6K,
  IMAX_COMPUTE_FORWARD_MUL_MAT_ONE_CHUNK_Q6K_ARM,
  IMAX_COMPUTE_FORWARD_MUL_MAT_ONE_CHUNK_Q80,
  IMAX_COMPUTE_FORWARD_MUL_MAT_ONE_CHUNK_Q80_ARM,
  IMAX_COMPUTE_FORWARD_MUL_MAT_ONE_CHUNK_OTHER_ARM,
  VEC_DOT_OPERATION,
  ARM_MEMCPY,
  IMAX_CPYIN_PRELOAD,
  IMAX_CPYIN_A,
  IMAX_CPYIN_A_Q80,
  IMAX_CPYIN_B,
  IMAX_CPYIN_A_Q3K,
  IMAX_CPYIN_B_Q3K,
  IMAX_BZERO_Q3K,
  IMAX_CPYOUT_Q3K,
  IMAX_CPYIN_A_Q6K,
  IMAX_CPYIN_B_Q6K,
  IMAX_BZERO_Q6K,
  IMAX_CPYOUT_Q6K,
  IMAX_BZERO,
  IMAX_CPYOUT,
  IMAX_MEMCPY,
  IMAX_MEMCPY_A,
  IMAX_MEMCPY_B,
  IMAX_MEMCPY_C,
  IMAX_PIOCPY,
  IMAX_TERM_1,
  IMAX_TERM_2,
  IMAX_TERM_3,
  IMAX_TERM_4,
  IMAX_TERM_5,
  IMAX_TERM_6,
  IMAX_TERM_7,
  IMAX_TERM_8,
  T_COMPUTE_FORWARD_MUL_MAT_ID,
  T_COMPUTE_FORWARD_OUT_PROD,
  T_COMPUTE_FORWARD_SCALE,
  T_COMPUTE_FORWARD_SET,
  T_COMPUTE_FORWARD_CPY,
  T_COMPUTE_FORWARD_CONT,
  T_COMPUTE_FORWARD_RESHAPE,
  T_COMPUTE_FORWARD_VIEW,
  T_COMPUTE_FORWARD_PERMUTE,
  T_COMPUTE_FORWARD_TRANSPOSE,
  T_COMPUTE_FORWARD_GET_ROWS,
  T_COMPUTE_FORWARD_GET_ROWS_BACK,
  T_COMPUTE_FORWARD_DIAG,
  T_COMPUTE_FORWARD_DIAG_MASK_INF,
  T_COMPUTE_FORWARD_DIAG_MASK_ZERO,
  T_COMPUTE_FORWARD_SET_ROWS,
  T_COMPUTE_FORWARD_GLU,
  T_COMPUTE_FORWARD_SOFT_MAX,
  T_COMPUTE_FORWARD_SOFT_MAX_BACK,
  T_COMPUTE_FORWARD_ROPE,
  T_COMPUTE_FORWARD_ROPE_BACK,
  T_COMPUTE_FORWARD_ROLL,
  T_COMPUTE_FORWARD_CLAMP,
  T_COMPUTE_FORWARD_CONV_TRANSPOSE_1D,
  T_COMPUTE_FORWARD_IM2COL,
  T_COMPUTE_FORWARD_IM2COL_BACK,
  T_COMPUTE_FORWARD_IM2COL_3D,
  T_COMPUTE_FORWARD_CONV_2D,
  T_COMPUTE_FORWARD_CONV_3D,
  T_COMPUTE_FORWARD_CONV_2D_DW,
  T_COMPUTE_FORWARD_CONV_TRANSPOSE_2D,
  T_COMPUTE_FORWARD_POOL_1D,
  T_COMPUTE_FORWARD_POOL_2D,
  T_COMPUTE_FORWARD_POOL_2D_BACK,
  T_COMPUTE_FORWARD_UPSCALE,
  T_COMPUTE_FORWARD_PAD,
  T_COMPUTE_FORWARD_PAD_REFLECT_1D,
  T_COMPUTE_FORWARD_ARANGE,
  T_COMPUTE_FORWARD_TIMESTEP_EMBEDDING,
  T_COMPUTE_FORWARD_ARGSORT,
  T_COMPUTE_FORWARD_LEAKY_RELU,
  T_COMPUTE_FORWARD_FLASH_ATTN_EXT,
  T_COMPUTE_FORWARD_FLASH_ATTN_BACK,
  T_COMPUTE_FORWARD_SSM_CONV,
  T_COMPUTE_FORWARD_SSM_SCAN,
  T_COMPUTE_FORWARD_WIN_PART,
  T_COMPUTE_FORWARD_WIN_UNPART,
  T_COMPUTE_FORWARD_UNARY,
  T_COMPUTE_FORWARD_GET_REL_POS,
  T_COMPUTE_FORWARD_ADD_REL_POS,
  T_COMPUTE_FORWARD_MAP_UNARY,
  T_COMPUTE_FORWARD_MAP_BINARY,
  T_COMPUTE_FORWARD_MAP_CUSTOM1_F32,
  T_COMPUTE_FORWARD_MAP_CUSTOM2_F32,
  T_COMPUTE_FORWARD_MAP_CUSTOM3_F32,
  T_COMPUTE_FORWARD_MAP_CUSTOM1,
  T_COMPUTE_FORWARD_MAP_CUSTOM2,
  T_COMPUTE_FORWARD_MAP_CUSTOM3,
  T_COMPUTE_FORWARD_CROSS_ENTROPY_LOSS,
  T_COMPUTE_FORWARD_CROSS_ENTROPY_LOSS_BACK,
  T_COMPUTE_FORWARD_NONE,
  T_COMPUTE_FORWARD_COUNT,
  T_COMPUTE_FORWARD_SIN,
  T_COMPUTE_FORWARD_COS,
  T_COMPUTE_FORWARD_COUNT_EQUAL,
  T_COMPUTE_FORWARD_L2_NORM,
  T_COMPUTE_FORWARD_RWKV_WKV6,
  T_COMPUTE_FORWARD_GATED_LINEAR_ATTN,
  T_COMPUTE_FORWARD_RWKV_WKV7,
  T_COMPUTE_FORWARD_CUSTOM,
  T_COMPUTE_FORWARD_OPT_STEP_ADAMW,
  T_COMPUTE_FORWARD_OPT_STEP_SGD,
  MONITOREND} monitor_types;
void cex(Uint, Ull*, Ull, Ull, Ull, Ull, Ushort);
void ex4(Uint, Ull*, Ull*, Uint, Ull*, Uint, Ull*, Uint, Uint, Ull*, Uint, Ull*);
Ull exm(Ull, Uchar);
int exe(Uint, Ull*, Ull, Uint, Ull, Uint, Ull, Uint, Uint, Ull, Uint, Ull);
void mex(Uint, Uchar**, Uchar*, Ull, Uint, Uchar**, Uchar*, Ull, Ull, Ull, Ull);
void mo4(Uint, Ull, Ull*, Ull, Ull, Uchar, Ull, Uint, Uint, Uchar, Ull, Uint);
void mop(Uint, Ull, Ull*, Ull, Ull, Uchar, Ull, Uint, Uint, Uchar, Ull, Uint);
Ull eam(Ull, Uchar);
void eag(Ull*, Ull, Ull);
void mmp(Uint, Ull, Ull*, Ull, Ull, Uint, Uint);
int NLANE;
int EMAX_DEPTH;
int LMM_SIZE;
int current_prefix;
int current_mapdist;
int current_loop0h;
int current_loop1h;
int current_nchip;
int current_lmmwb;
int last_insn;
char forinit[2][4][1024];
char forinit_cidx[2];
struct cex {
  char op ;
  char bit0v ;
  int bit0h ;
  char bit1v ;
  int bit1h ;
  char bit2v ;
  int bit2h ;
  char bit3v ;
  int bit3h ;
  Ull table :16;
  char cexdv ;
  int cexdh ;
};
struct exe {
  char op1 ;
  char op2 ;
  char op3 ;
  Ull updt : 1;
  Ull init : 2;
  char src1v ;
  int src1h ;
  char src1s ;
  char src1e ;
  char src2v ;
  int src2h ;
  char src2s ;
  char src2e ;
  char src3v ;
  int src3h ;
  char src3s ;
  char src3e ;
  char src4v ;
  int src4h ;
  char src4s ;
  char src5v ;
  int src5h ;
  char src5s ;
  char exedv ;
  int exedh ;
  char exeds ;
};
struct mex {
  char op0 ;
  char op1 ;
  Ull init : 1;
  char adr1v ;
  int adr1h ;
  char adr1s ;
  char adr2v ;
  int adr2h ;
  char adr2s ;
  char dist1v ;
  int dist1h ;
  char adr3v ;
  int adr3h ;
  char adr3s ;
  char adr4v ;
  int adr4h ;
  char adr4s ;
  char dist2v ;
  int dist2h ;
  char limitv ;
  int limith ;
  char src1v ;
  int src1h ;
  char src1s ;
  char src2v ;
  int src2h ;
  char src2s ;
  char mexd0v ;
  int mexd0h ;
  char mexd0s ;
  char mexd1v ;
  int mexd1h ;
  char mexd1s ;
};
struct mop {
  char op ;
  char mtype ;
  Ull updt : 1;
  char exv ;
  int exh ;
  char mopdv ;
  int mopdh ;
  char mopds ;
  char basev ;
  int baseh ;
  char bases ;
  char offsv ;
  int offsh ;
  char offss ;
  char offsm ;
  char topv ;
  int toph ;
  int lenv ;
  int lenh ;
  char blk ;
  int forcev ;
  int forceh ;
  char ptopv ;
  int ptoph ;
  int plenv ;
  int plenh ;
};
struct insn {
  struct header {
    char type ;
    char row ;
    char col ;
    char rdep ;
    char fixed ;
  } iheader;
  struct cex icex;
  struct exe iexe;
  struct mex imex;
  struct mop imop;
} insn[(4*64*4)];
struct dec {
  struct cex dcex;
  struct exu {
    char op1 ;
    char op2 ;
    char op3 ;
    Ull updt : 1;
    Ull init : 2;
    Ull fold : 1;
    char ex1v ;
    int ex1h ;
    char ex1s ;
    char ex1e ;
    char ex2v ;
    int ex2h ;
    char ex2s ;
    char ex2e ;
    char ex3v ;
    int ex3h ;
    char ex3s ;
    char ex3e ;
    char e2iv ;
    int e2ih ;
    char e2is ;
    char e3iv ;
    int e3ih ;
    char e3is ;
    char exdv ;
    int exdh ;
    char exds ;
  } dexu;
  struct mex dmex;
  struct mop dmop0;
  struct mop dmop1;
} dec[64][4];
struct bus {
  char cexdv ;
  int cexdh ;
  char exdrv ;
  int exdrh ;
  char exdrs ;
  char ea0brv ;
  int ea0brh ;
  char ea0orv ;
  int ea0orh ;
  char ea0drv ;
  int ea0drh ;
  char ea0woofsv;
  int ea0woofsh;
  char ea1brv ;
  int ea1brh ;
  char ea1orv ;
  int ea1orh ;
  char ea1drv ;
  int ea1drh ;
  char ea1woofsv;
  int ea1woofsh;
  struct {
    char v ;
    int h ;
    char s ;
  } lmwd[4], lmrd[4];
  struct {
    char v ;
    int h ;
    char s ;
  } tr[4];
  struct {
    char v ;
    int h ;
    char s ;
  } mw[4];
  struct {
    char v ;
    int h ;
    char s ;
  } br[4];
} bus[64][4];
struct conf {
  struct cdw0 {
    Ull v : 1;
    Ull op1 : 6;
    Ull op2 : 3;
    Ull op3 : 3;
    Ull ex1brs : 4;
    Ull ex1s : 1;
    Ull ex1exp : 3;
    Ull ex2brs : 4;
    Ull ex2exp : 3;
    Ull ex3brs : 4;
    Ull ex3exp : 3;
    Ull e2is : 2;
    Ull e3imm : 6;
    Ull e3is : 1;
    Ull init : 2;
    Ull fold : 1;
    Ull mex0op : 2;
    Ull mex0init: 1;
    Ull mex0dist: 3;
    Ull mex1op : 2;
    Ull mex1init: 1;
    Ull mex1dist: 3;
    Ull mexlimit: 4;
    Ull dmy00 : 1;
  } cdw0;
  struct cdw1 {
    Ull cs0 : 4;
    Ull cs1 : 4;
    Ull cs2 : 4;
    Ull cs3 : 4;
    Ull cex_tab: 16;
    Ull ea0op : 5;
    Ull ea0bs : 2;
    Ull ea0os : 1;
    Ull ea0msk : 4;
    Ull ea1op : 5;
    Ull ea1bs : 2;
    Ull ea1os : 1;
    Ull ea1msk : 4;
    Ull eabbrs : 4;
    Ull eaobrs : 4;
  } cdw1;
  struct cdw2 {
    Ull ts0 : 4;
    Ull ts1 : 4;
    Ull ts2 : 4;
    Ull ts3 : 4;
    Ull trs0 : 2;
    Ull trs1 : 2;
    Ull trs2 : 2;
    Ull trs3 : 2;
    Ull mwsa : 1;
    Ull mws0 : 2;
    Ull mws1 : 2;
    Ull mws2 : 2;
    Ull mws3 : 2;
    Ull brs0 : 2;
    Ull brs1 : 2;
    Ull brs2 : 2;
    Ull brs3 : 2;
    Ull mapdist: 6;
    Ull lmm_mode: 2;
    Ull lmm_axiw: 1;
    Ull lmm_axir: 1;
    Ull dmy20 : 13;
  } cdw2;
  struct cdw3 {
    Ull e2imm : 64;
  } cdw3;
} conf[64][4];
struct lmmi {
  Ull v : 1;
  Ull rw : 1;
  Ull f : 1;
  Ull p : 1;
  Ull bcas : 4;
  Ull hcopy: 1;
  Ull vcopy: 1;
  Ull blk : 2;
  Ull cidx : 1;
  Ull len :19;
  Ull ofs :32;
  Ull top :64;
} lmmi[64][4];
int lmmi_first_loc;
Ull lmmi_bitmap[4];
Ull range_bitmap[4];
Uchar range_link[64][4];
struct lmmx {
  int forcev ;
  int forceh ;
  int lenv ;
  int lenh ;
} lmmx[64][4];
struct {
  struct {
    int v;
    int h;
    int s;
  } br[4];
  int ea0b_v;
  int ea0b_h;
  int ea0b_s;
  int ea0o_v;
  int ea0o_h;
  int ea0o_s;
  int ea1b_v;
  int ea1b_h;
  int ea1b_s;
  int ea1o_v;
  int ea1o_h;
  int ea1o_s;
} regv[64][4];
int trans_pc;
struct trans {
  Ull rw : 1;
  Ull base_type : 2;
  Ull base_num : 3;
  char *base_symbol;
  Ull offset_type : 1;
  Ull offset : 4;
  Ull offset_suffix : 3;
  Ull offset_sll : 3;
  Ull op_type : 3;
  Ull op_val_type : 2;
  Ull op_val_num;
  char *op_val_symbol;
  Ull t_action_type : 2;
  Ull t_action : 4;
  Ull f_action_type : 2;
  Ull f_action : 4;
  Ull reg_type : 1;
  Ull reg_num : 3;
  char *reg_symbol;
} trans[16];
struct tconf {
  Ull rw : 1;
  Ull base_type : 2;
  Ull offset_type : 1;
  Ull offset : 4;
  Ull offset_suffix : 3;
  Ull offset_sll : 3;
  Ull op_type : 3;
  Ull op_val_type : 1;
  Ull t_action_type : 2;
  Ull t_action : 4;
  Ull f_action_type : 2;
  Ull f_action : 4;
  Ull reg_type : 1;
  Ull dmy : 1;
  Ull base;
  Ull op_val;
  Ull reg;
} tconf[16];
enum { NANOS_ARM, NANOS_DRAIN, NANOS_CONF, NANOS_REGV, NANOS_RANGE, NANOS_REFILL, NANOS_LOAD, NANOS_EXEC, NANOS_TOTAL, NANOS_CLASS };
typedef struct {
  Uint f : 23;
  Uint e : 8;
  Uint s : 1;
} f32bit;
typedef struct {
  Uint e : 6;
  Uint b : 1;
  Uint s : 1;
  Uint dm : 24;
} wu7bit;
typedef struct {
  Uint e : 7;
  Uint s : 1;
  Uint dm : 24;
} wu8bit;
typedef struct {
  Uchar u[8];
} u64bit;
struct dma_ctrl {
  Uint MM2S_DMACR;
  Uint MM2S_DMASR;
  Uint reserved0[4];
  Uint MM2S_SA;
  Uint MM2S_SA_MSB;
  Uint reserved1[2];
  Uint MM2S_LENGTH;
  Uint reserved2[1];
  Uint S2MM_DMACR;
  Uint S2MM_DMASR;
  Uint reserves3[4];
  Uint S2MM_DA;
  Uint S2MM_DA_MSB;
  Uint reserved4[2];
  Uint S2MM_LENGTH;
};
enum { EXRING_IDLE, EXRING_BUSY};
enum { LMRING_IDLE, LMRING_BUSY};
enum { CMD_NOP, CMD_RESET, CMD_SCON, CMD_EXEC};
struct reg_ctrl {
  struct i0 {
    Uint stat;
    Uint dmy_;
    Uint mcid;
    Uint dmy0;
    Uint cmd;
    Uint dmy1;
    Ull dmy2;
    Ull adtr;
    Ull dmy3;
    Ull csel;
    Ull dmrp;
    Ull refi;
    Ull refs;
    Ull dmy4[1014];
    struct conf conf[64][4];
    struct {Ull br[4];} breg[64][4];
    struct {Uint ea0b ;
        Uint ea0o ;
        Uint ea1b ;
        Uint ea1o ;
        Uint top ;
        Uint bot ;
        Ull dmy6 ;} addr[64][4];
    struct {Ull reg[4];} lddmrw[64][4];
    Ull dmy5[3072];
  } i[4];
};
enum { STATUS_IDLE, STATUS_CONF, STATUS_SCON, STATUS_REGV, STATUS_RANGE, STATUS_DRAIN, STATUS_REFILL, STATUS_LOAD, STATUS_START, STATUS_EXEC, STATUS_TERM };
pthread_mutex_t axi_dma_mutex;
struct emax7 {
  volatile Ull dma_ctrl;
  volatile Ull reg_ctrl;
  Ull status : 4;
  Ull csel_save : 2;
  Ull last_conf ;
  Ull lmmic : 1;
  Ull lmmio : 1;
  Ull mapdist : 6;
  Ull lastdist : 6;
  Ull execloop ;
  struct lmmi lmmi[4][64][4][2];
  Ull lmmi_bitmap[4];
  Uchar lmmd[64][4];
  Ull plist ;
  Ull blkcount : 7;
  Ull blksize : 9;
  Ull lmmblktop ;
  Ull lmmblklen ;
  Ull rw ;
  Ull ddraddr ;
  Ull lmmaddr ;
  Ull dmalen ;
  Ull sigwait ;
  int *sigstat ;
  sigset_t *sigset ;
  Ull fsm_busy : 1;
  Ull lmwd_valid : 1;
  Ull tcureg_valid : 1;
  Ull tcureg_ready : 1;
  Ull tcureg_last : 1;
  Ull tcureg_term : 1;
  Ull tcureg[4] ;
} emax7[8];
volatile struct emax_info {
  Ull dma_phys;
  Ull dma_vadr;
  Ull dma_mmap;
  Ull reg_phys;
  Ull reg_vadr;
  Ull reg_mmap;
  Ull lmm_phys;
  Ull lmm_vadr;
  Ull lmm_mmap;
  Ull ddr_phys;
  Ull ddr_vadr;
  Ull ddr_mmap;
  int driver_use_1;
  int driver_use_2;
} emax_info[8];

int memfd_create (const char *__name, unsigned int __flags) __attribute__ ((__nothrow__ , __leaf__));
int mlock2 (const void *__addr, size_t __length, unsigned int __flags) __attribute__ ((__nothrow__ , __leaf__));
int pkey_alloc (unsigned int __flags, unsigned int __access_rights) __attribute__ ((__nothrow__ , __leaf__));
int pkey_set (int __key, unsigned int __access_rights) __attribute__ ((__nothrow__ , __leaf__));
int pkey_get (int __key) __attribute__ ((__nothrow__ , __leaf__));
int pkey_free (int __key) __attribute__ ((__nothrow__ , __leaf__));
int pkey_mprotect (void *__addr, size_t __len, int __prot, int __pkey) __attribute__ ((__nothrow__ , __leaf__));


extern void *mmap (void *__addr, size_t __len, int __prot,
     int __flags, int __fd, __off_t __offset) __attribute__ ((__nothrow__ , __leaf__));
extern void *mmap64 (void *__addr, size_t __len, int __prot,
       int __flags, int __fd, __off64_t __offset) __attribute__ ((__nothrow__ , __leaf__));
extern int munmap (void *__addr, size_t __len) __attribute__ ((__nothrow__ , __leaf__));
extern int mprotect (void *__addr, size_t __len, int __prot) __attribute__ ((__nothrow__ , __leaf__));
extern int msync (void *__addr, size_t __len, int __flags);
extern int madvise (void *__addr, size_t __len, int __advice) __attribute__ ((__nothrow__ , __leaf__));
extern int posix_madvise (void *__addr, size_t __len, int __advice) __attribute__ ((__nothrow__ , __leaf__));
extern int mlock (const void *__addr, size_t __len) __attribute__ ((__nothrow__ , __leaf__));
extern int munlock (const void *__addr, size_t __len) __attribute__ ((__nothrow__ , __leaf__));
extern int mlockall (int __flags) __attribute__ ((__nothrow__ , __leaf__));
extern int munlockall (void) __attribute__ ((__nothrow__ , __leaf__));
extern int mincore (void *__start, size_t __len, unsigned char *__vec)
     __attribute__ ((__nothrow__ , __leaf__));
extern void *mremap (void *__addr, size_t __old_len, size_t __new_len,
       int __flags, ...) __attribute__ ((__nothrow__ , __leaf__));
extern int remap_file_pages (void *__start, size_t __size, int __prot,
        size_t __pgoff, int __flags) __attribute__ ((__nothrow__ , __leaf__));
extern int shm_open (const char *__name, int __oflag, mode_t __mode);
extern int shm_unlink (const char *__name);
struct iovec;
extern __ssize_t process_madvise (int __pid_fd, const struct iovec *__iov,
      size_t __count, int __advice,
      unsigned __flags)
  __attribute__ ((__nothrow__ , __leaf__));
extern int process_mrelease (int pidfd, unsigned int flags) __attribute__ ((__nothrow__ , __leaf__));


extern int stat (const char *__restrict __file,
   struct stat *__restrict __buf) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int fstat (int __fd, struct stat *__buf) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));
extern int stat64 (const char *__restrict __file,
     struct stat64 *__restrict __buf) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int fstat64 (int __fd, struct stat64 *__buf) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));
extern int fstatat (int __fd, const char *__restrict __file,
      struct stat *__restrict __buf, int __flag)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2, 3)));
extern int fstatat64 (int __fd, const char *__restrict __file,
        struct stat64 *__restrict __buf, int __flag)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2, 3)));
extern int lstat (const char *__restrict __file,
    struct stat *__restrict __buf) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int lstat64 (const char *__restrict __file,
      struct stat64 *__restrict __buf)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int chmod (const char *__file, __mode_t __mode)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int lchmod (const char *__file, __mode_t __mode)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int fchmod (int __fd, __mode_t __mode) __attribute__ ((__nothrow__ , __leaf__));
extern int fchmodat (int __fd, const char *__file, __mode_t __mode,
       int __flag)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2))) ;
extern __mode_t umask (__mode_t __mask) __attribute__ ((__nothrow__ , __leaf__));
extern __mode_t getumask (void) __attribute__ ((__nothrow__ , __leaf__));
extern int mkdir (const char *__path, __mode_t __mode)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int mkdirat (int __fd, const char *__path, __mode_t __mode)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));
extern int mknod (const char *__path, __mode_t __mode, __dev_t __dev)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int mknodat (int __fd, const char *__path, __mode_t __mode,
      __dev_t __dev) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));
extern int mkfifo (const char *__path, __mode_t __mode)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int mkfifoat (int __fd, const char *__path, __mode_t __mode)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));
extern int utimensat (int __fd, const char *__path,
        const struct timespec __times[2],
        int __flags)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));
extern int futimens (int __fd, const struct timespec __times[2]) __attribute__ ((__nothrow__ , __leaf__));
struct statx_timestamp {
 __s64 tv_sec;
 __u32 tv_nsec;
 __s32 __reserved;
};
struct statx {
 __u32 stx_mask;
 __u32 stx_blksize;
 __u64 stx_attributes;
 __u32 stx_nlink;
 __u32 stx_uid;
 __u32 stx_gid;
 __u16 stx_mode;
 __u16 __spare0[1];
 __u64 stx_ino;
 __u64 stx_size;
 __u64 stx_blocks;
 __u64 stx_attributes_mask;
 struct statx_timestamp stx_atime;
 struct statx_timestamp stx_btime;
 struct statx_timestamp stx_ctime;
 struct statx_timestamp stx_mtime;
 __u32 stx_rdev_major;
 __u32 stx_rdev_minor;
 __u32 stx_dev_major;
 __u32 stx_dev_minor;
 __u64 stx_mnt_id;
 __u32 stx_dio_mem_align;
 __u32 stx_dio_offset_align;
 __u64 __spare3[12];
};

int statx (int __dirfd, const char *__restrict __path, int __flags,
           unsigned int __mask, struct statx *__restrict __buf)
  __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2, 5)));



struct dirent
  {
    __ino_t d_ino;
    __off_t d_off;
    unsigned short int d_reclen;
    unsigned char d_type;
    char d_name[256];
  };
struct dirent64
  {
    __ino64_t d_ino;
    __off64_t d_off;
    unsigned short int d_reclen;
    unsigned char d_type;
    char d_name[256];
  };
enum
  {
    DT_UNKNOWN = 0,
    DT_FIFO = 1,
    DT_CHR = 2,
    DT_DIR = 4,
    DT_BLK = 6,
    DT_REG = 8,
    DT_LNK = 10,
    DT_SOCK = 12,
    DT_WHT = 14
  };
typedef struct __dirstream DIR;
extern int closedir (DIR *__dirp) __attribute__ ((__nonnull__ (1)));
extern DIR *opendir (const char *__name) __attribute__ ((__nonnull__ (1)))
 __attribute__ ((__malloc__)) __attribute__ ((__malloc__ (closedir, 1)));
extern DIR *fdopendir (int __fd)
 __attribute__ ((__malloc__)) __attribute__ ((__malloc__ (closedir, 1)));
extern struct dirent *readdir (DIR *__dirp) __attribute__ ((__nonnull__ (1)));
extern struct dirent64 *readdir64 (DIR *__dirp) __attribute__ ((__nonnull__ (1)));
extern int readdir_r (DIR *__restrict __dirp,
        struct dirent *__restrict __entry,
        struct dirent **__restrict __result)
     __attribute__ ((__nonnull__ (1, 2, 3))) __attribute__ ((__deprecated__));
extern int readdir64_r (DIR *__restrict __dirp,
   struct dirent64 *__restrict __entry,
   struct dirent64 **__restrict __result)
  __attribute__ ((__nonnull__ (1, 2, 3))) __attribute__ ((__deprecated__));
extern void rewinddir (DIR *__dirp) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern void seekdir (DIR *__dirp, long int __pos) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern long int telldir (DIR *__dirp) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int dirfd (DIR *__dirp) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int scandir (const char *__restrict __dir,
      struct dirent ***__restrict __namelist,
      int (*__selector) (const struct dirent *),
      int (*__cmp) (const struct dirent **,
      const struct dirent **))
     __attribute__ ((__nonnull__ (1, 2)));
extern int scandir64 (const char *__restrict __dir,
        struct dirent64 ***__restrict __namelist,
        int (*__selector) (const struct dirent64 *),
        int (*__cmp) (const struct dirent64 **,
        const struct dirent64 **))
     __attribute__ ((__nonnull__ (1, 2)));
extern int scandirat (int __dfd, const char *__restrict __dir,
        struct dirent ***__restrict __namelist,
        int (*__selector) (const struct dirent *),
        int (*__cmp) (const struct dirent **,
        const struct dirent **))
     __attribute__ ((__nonnull__ (2, 3)));
extern int scandirat64 (int __dfd, const char *__restrict __dir,
   struct dirent64 ***__restrict __namelist,
   int (*__selector) (const struct dirent64 *),
   int (*__cmp) (const struct dirent64 **,
          const struct dirent64 **))
     __attribute__ ((__nonnull__ (2, 3)));
extern int alphasort (const struct dirent **__e1,
        const struct dirent **__e2)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
extern int alphasort64 (const struct dirent64 **__e1,
   const struct dirent64 **__e2)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
extern __ssize_t getdirentries (int __fd, char *__restrict __buf,
    size_t __nbytes,
    __off_t *__restrict __basep)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2, 4)));
extern __ssize_t getdirentries64 (int __fd, char *__restrict __buf,
      size_t __nbytes,
      __off64_t *__restrict __basep)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2, 4)));
extern int versionsort (const struct dirent **__e1,
   const struct dirent **__e2)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
extern int versionsort64 (const struct dirent64 **__e1,
     const struct dirent64 **__e2)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));


extern __ssize_t getdents64 (int __fd, void *__buffer, size_t __length)
  __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));


extern int *__errno_location (void) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern char *program_invocation_name;
extern char *program_invocation_short_name;
typedef int error_t;

static int filter(struct dirent *dir)
{
  return dir->d_name[0] == '.' ? 0 : 1;
}
static void trim(char *d_name)
{
  char *p = strchr(d_name, '\n');
  if (p != ((void *)0)) *p = '\0';
}
static int is_target_dev(char *d_name, char *target)
{
  char path[32];
  char name[32];
  FILE *fp;
  sprintf(path, "/sys/class/uio/%s/name", d_name);
  if ((fp = fopen(path, "r")) == ((void *)0)) return 0;
  if (fgets(name, sizeof(name), fp) == ((void *)0)) {
    fclose(fp);
    return 0;
  }
  fclose(fp);
  if (strncmp(name, target, strlen(target)-1) != 0) return 0;
  return 1;
}
static int get_reg_size(char *d_name)
{
  char path[32];
  char size[32];
  FILE *fp;
  sprintf(path, "/sys/class/uio/%s/maps/map0/size", d_name);
  if ((fp = fopen(path, "r")) == ((void *)0)) return 0;
  if (fgets(size, sizeof(size), fp) == ((void *)0)) {
    fclose(fp);
    return 0;
  }
  fclose(fp);
  return strtoull(size, ((void *)0), 16);
}
emax7_open(int NLANE)
{
  struct dirent **namelist;
  int num_dirs, dir, uiolen;
  int reg_size;
  char path[1024];
  int fd_dma;
  int fd_reg;
  int fd_ddr;
  char *UIO_AXI_C2C = "axi_chip2chip\n";
  char *UIO_AXI_MM2S = "axi_mm2s_mapper\n";
  char *UIO_DMA = "dma\n";
  char *UIO_AXI_EMAX6 = "emax6\n";
  char *UIO_DDR_HIGH = "ddr_high\n";
  int fd_dma_found = 0;
  int emax7_found = 0;
  int i;
  pthread_mutex_init(&axi_dma_mutex, ((void *)0));
  if ((num_dirs = scandir("/sys/class/uio", &namelist, filter, alphasort)) == -1)
    return (((void *)0));
  for (dir = 0; dir < num_dirs; ++dir)
    trim(namelist[dir]->d_name);
  for (uiolen=4; uiolen<6; uiolen++) {
    for (dir = 0; dir < num_dirs; ++dir) {
      if (strlen(namelist[dir]->d_name)!=uiolen)
 continue;
      if (is_target_dev(namelist[dir]->d_name, UIO_AXI_EMAX6)) {
 sprintf(path, "/dev/%s", namelist[dir]->d_name);
 if ((fd_reg = open(path, 02 | 04010000)) == -1) {
   printf("open failed. %s", UIO_AXI_EMAX6);
   return (((void *)0));
 }
 printf("%s: %s", path, UIO_AXI_EMAX6);
 if (emax7_found >= 8 || emax7_found >= NLANE) {
   printf("emax7_found > EMAX_NLANE || emax7_found >= given_NLANE (skip)\n");
   continue;
 }
 emax_info[emax7_found].reg_phys = 0x0000020800000000LL +0x0000000800000000LL*emax7_found;
 emax_info[emax7_found].reg_mmap = (Ull)mmap(((void *)0), 0x0000000200000000LL, 0x1|0x2, 0x01, fd_reg, 0);
 close(fd_reg);
 if (emax_info[emax7_found].reg_mmap == ((void *) -1)) {
   printf("fd_reg mmap() failed. errno=%d\n", (*__errno_location ()));
   return (((void *)0));
 }
 emax_info[emax7_found].lmm_phys = 0x0000020900000000LL +0x0000000800000000LL*emax7_found;
 emax_info[emax7_found].lmm_mmap = emax_info[emax7_found].reg_mmap + (0x0000020900000000LL - 0x0000020800000000LL);
 emax7_found++;
      }
    }
  }
  for (uiolen=4; uiolen<6; uiolen++) {
     for (dir = 0; dir < num_dirs; ++dir) {
      if (strlen(namelist[dir]->d_name)!=uiolen)
 continue;
      if (is_target_dev(namelist[dir]->d_name, UIO_DMA) && (reg_size = get_reg_size(namelist[dir]->d_name))) {
 sprintf(path, "/dev/%s", namelist[dir]->d_name);
 if ((fd_dma = open(path, 02 | 04010000)) == -1)
   continue;
 printf("%s: %s", path, UIO_DMA);
 if (fd_dma_found >= 8 || fd_dma_found >= NLANE) {
   printf("fd_dma_found > EMAX_NLANE || fd_dma_found > given_NLANE (skip)\n");
   continue;
 }
 emax_info[fd_dma_found].dma_phys = 0x00000000a4000000LL +0x0000000000010000LL*fd_dma_found;
 emax_info[fd_dma_found].dma_mmap = (Ull)mmap(((void *)0), reg_size, 0x1|0x2, 0x01, fd_dma, 0);
 close(fd_dma);
 if (emax_info[fd_dma_found].dma_mmap == ((void *) -1))
   continue;
 fd_dma_found++;
      }
      else if (is_target_dev(namelist[dir]->d_name, UIO_AXI_C2C)) {
 sprintf(path, "/dev/%s", namelist[dir]->d_name);
 if ((fd_reg = open(path, 02 | 04010000)) == -1) {
   printf("open failed. %s", UIO_AXI_C2C);
   return (((void *)0));
 }
 printf("%s: %s", path, UIO_AXI_C2C);
 if (emax7_found >= 8 || emax7_found >= NLANE) {
   printf("emax7_found > EMAX_NLANE || emax7_found > given_NLANE (skip)\n");
   continue;
 }
 emax_info[emax7_found].reg_phys = 0x0000020800000000LL +0x0000000800000000LL*emax7_found;
 emax_info[emax7_found].reg_mmap = (Ull)mmap(((void *)0), 0x0000000200000000LL, 0x1|0x2, 0x01, fd_reg, 0);
 close(fd_reg);
 if (emax_info[emax7_found].reg_mmap == ((void *) -1)) {
   printf("fd_reg mmap() failed. errno=%d\n", (*__errno_location ()));
   return (((void *)0));
 }
 emax_info[emax7_found].lmm_phys = 0x0000020900000000LL +0x0000000800000000LL*emax7_found;
 emax_info[emax7_found].lmm_mmap = emax_info[emax7_found].reg_mmap + (0x0000020900000000LL - 0x0000020800000000LL);
 emax7_found++;
      }
      else if (is_target_dev(namelist[dir]->d_name, UIO_AXI_MM2S)) {
 sprintf(path, "/dev/%s", namelist[dir]->d_name);
 if ((fd_reg = open(path, 02 | 04010000)) == -1) {
   printf("open failed. %s", UIO_AXI_MM2S);
   return (((void *)0));
 }
 printf("%s: %s", path, UIO_AXI_MM2S);
 if (emax7_found >= 8 || emax7_found >= NLANE) {
   printf("emax7_found > EMAX_NLANE || emax7_found > given_NLANE (skip)\n");
   continue;
 }
 emax_info[emax7_found].reg_phys = 0x0000020800000000LL +0x0000000800000000LL*emax7_found;
 emax_info[emax7_found].reg_mmap = (Ull)mmap(((void *)0), 0x0000000200000000LL, 0x1|0x2, 0x01, fd_reg, 0);
 close(fd_reg);
 if (emax_info[emax7_found].reg_mmap == ((void *) -1)) {
   printf("fd_reg mmap() failed. errno=%d\n", (*__errno_location ()));
   return (((void *)0));
 }
 emax_info[emax7_found].lmm_phys = 0x0000020900000000LL +0x0000000800000000LL*emax7_found;
 emax_info[emax7_found].lmm_mmap = emax_info[emax7_found].reg_mmap + (0x0000020900000000LL - 0x0000020800000000LL);
 emax7_found++;
      }
    }
  }
  if ((fd_ddr = open("/dev/mem", 02 )) == -1) {
    printf("open failed. %s",UIO_DDR_HIGH);
    return (((void *)0));
  }
  printf("/dev/mem\n");
  emax_info[0].ddr_phys = 0x0000050000000000LL;
  emax_info[0].ddr_mmap = (Ull)mmap(((void *)0), 0x0000000100000000LL*2, 0x1|0x2, 0x01, fd_ddr, 0x0000050000000000LL);
  munmap(emax_info[0].ddr_mmap, 0x0000000100000000LL*2);
  emax_info[0].ddr_mmap = (Ull)mmap((emax_info[0].ddr_mmap+(0x0000000100000000LL -1))&~(0x0000000100000000LL -1), 0x0000000100000000LL, 0x1|0x2, 0x01|0x10, fd_ddr, 0x0000050000000000LL);
  close(fd_ddr);
  if (emax_info[0].ddr_mmap == ((void *) -1)) {
    printf("fd_ddr mmap() failed. errno=%d\n", (*__errno_location ()));
    return (((void *)0));
  }
  for (dir = 0; dir < num_dirs; ++dir)
    free(namelist[dir]);
  free(namelist);
  if (!emax7_found) {
    printf("EMAX not found: %s", UIO_AXI_EMAX6);
    exit(1);
  }
  if (fd_dma_found != emax7_found) {
    printf("Warning: fd_dma_found(%d) != emax7_found(%d)\n", fd_dma_found, emax7_found);
    if (fd_dma_found < emax7_found)
      emax7_found = fd_dma_found;
    else
      fd_dma_found = emax7_found;
  }
  for (i=0; i<fd_dma_found; i++) {
    ((struct dma_ctrl*)emax_info[i].dma_mmap)->MM2S_DMACR = 0x00010004;
    ((struct dma_ctrl*)emax_info[i].dma_mmap)->MM2S_DMASR = 0x00017000;
    ((struct dma_ctrl*)emax_info[i].dma_mmap)->S2MM_DMACR = 0x00010004;
    ((struct dma_ctrl*)emax_info[i].dma_mmap)->S2MM_DMASR = 0x00017000;
  }
  for (i=1; i<emax7_found; i++) {
    emax_info[i].ddr_phys = emax_info[0].ddr_phys;
    emax_info[i].ddr_mmap = emax_info[0].ddr_mmap;
  }
  return (emax7_found);
}
Ull nanosec_sav[8];
Ull nanosec[8][NANOS_CLASS];
sleep_nanosec(int nano)
{
  struct timespec ts;
  ts.tv_sec = 0;
  ts.tv_nsec = nano;
  nanosleep(((void *)0), &ts);
}
reset_nanosec(int LANE)
{
  int i;
  for (i=0; i<NANOS_CLASS; i++)
    nanosec[LANE][i] = 0;
  struct timespec ts;
  clock_gettime(0, &ts);
  nanosec_sav[LANE] = 1000000000*ts.tv_sec + ts.tv_nsec;
}
get_nanosec(int LANE, int class)
{
  Ull nanosec_now;
  struct timespec ts;
  clock_gettime(0, &ts);
  nanosec_now = 1000000000*ts.tv_sec + ts.tv_nsec;
  nanosec[LANE][class] += nanosec_now - nanosec_sav[LANE];
  nanosec[LANE][NANOS_TOTAL] += nanosec_now - nanosec_sav[LANE];
  nanosec_sav[LANE] = nanosec_now;
}
show_nanosec(int LANE)
{
  printf("LANE%d usec: ARM:%d DRAIN:%d CONF:%d REGV:%d RANGE:%d REFILL:%d LOAD:%d EXEC:%d total:%d\n",
  LANE,
  (Uint)(nanosec[LANE][NANOS_ARM]/1000),
  (Uint)(nanosec[LANE][NANOS_DRAIN]/1000),
  (Uint)(nanosec[LANE][NANOS_CONF]/1000),
  (Uint)(nanosec[LANE][NANOS_REGV]/1000),
  (Uint)(nanosec[LANE][NANOS_RANGE]/1000),
  (Uint)(nanosec[LANE][NANOS_REFILL]/1000),
  (Uint)(nanosec[LANE][NANOS_LOAD]/1000),
  (Uint)(nanosec[LANE][NANOS_EXEC]/1000),
  (Uint)(nanosec[LANE][NANOS_TOTAL]/1000));
}
emax7_check_lmmi_and_dma(int LANE, int mode, int phase, int lastdist, int c, int i, int j)
{
  int k, m = (i+lastdist)%EMAX_DEPTH;
  int lmmc_topz;
  int lmmc_ofsz;
  int lmmo_stat;
  int lmmc_stat;
  int lmm_ready;
  int lmm_readz;
  int mark;
  struct lmmi *lmmiop = &emax7[LANE].lmmi[c][m][j][emax7[LANE].lmmio];
  struct lmmi *lmmicp = &emax7[LANE].lmmi[c][i][j][emax7[LANE].lmmic];
  struct lmmi *lmmiop1 = &emax7[LANE].lmmi[c][(m+1)%EMAX_DEPTH][j][emax7[LANE].lmmio];
  struct lmmi *lmmicp1 = &emax7[LANE].lmmi[c][(i+1)%EMAX_DEPTH][j][emax7[LANE].lmmic];
  Ull dmadr;
  int dmlen;
  Ull dmnxt;
  int dmrw;
  static Ull concat_adr[8][4];
  static int concat_len[8][4];
  if ((phase == 1 && mode == 0) || phase == 2 || phase == 3) {
    lmmc_topz = (lmmicp->top == 0);
    lmmc_ofsz = (lmmicp->ofs == 0);
    lmmo_stat = (lmmiop->v<<3)|(lmmiop->rw<<2)|(lmmiop->f<<1)|(lmmiop->p);
    lmmc_stat =((lmmicp->v & ~lmmicp->hcopy & ~lmmicp->vcopy & ((lmmicp->f&lmmicp->p) | !lmmc_topz))<<3)|(lmmicp->rw<<2)|(lmmicp->f<<1)|(lmmicp->p);
    lmm_ready = (lmmiop->v && lmmiop->blk == lmmicp->blk && lmmiop->len == lmmicp->len && lmmiop->top == lmmicp->top);
    lmm_readz = (lmmiop->v && lmmiop->blk == lmmicp->blk && lmmiop->len == lmmicp->len &&(lmmiop->top+(Sll)(int)lmmiop->ofs) == lmmicp->top);
  }
  if (phase == 1) {
    if (mode==0 && lmmo_stat==12 && !lmm_ready && lmmc_stat!=13 && (emax7[LANE].lmmd[m][j]&1<<c)) { mark=1;emax7[LANE].lmmd[m][j]&=~(1<<c);dmadr=lmmiop->top;dmlen=lmmiop->len;dmnxt=lmmiop1->top;dmrw=1;}
    else if (mode==0 && lmmo_stat==14 && (lastdist || lmmc_stat==14) && (emax7[LANE].lmmd[m][j]&1<<c)) { mark=1;emax7[LANE].lmmd[m][j]&=~(1<<c);dmadr=lmmiop->top;dmlen=lmmiop->len;dmnxt=lmmiop1->top;dmrw=1;}
    else if (mode==1 && (emax7[LANE].lmmd[i][j]&1<<c)) { mark=1;emax7[LANE].lmmd[i][j]&=~(1<<c);dmadr=lmmicp->top;dmlen=lmmicp->len;dmnxt=lmmicp1->top;dmrw=1;}
    else { mark=0; }
  }
  else if (phase == 2) {
    if ((lmmc_stat== 8 && !lmm_ready)
         || (lmmc_stat== 9 && !lmm_readz)
         || (lmmc_stat==10 )
         || (lmmc_stat==14 )) { mark=1; dmadr=lmmicp->top;dmlen=lmmicp->len;dmnxt=lmmicp1->top;dmrw=0;}
    else { mark=0; }
  }
  else if (phase == 3) {
    if (lmmc_stat== 9 && (lastdist||!lmmc_ofsz)) { mark=1; dmadr=lmmicp->top;dmlen=lmmicp->len; dmrw=0;}
    else if (lmmc_stat==12 || lmmc_stat==14 ) { mark=0; emax7[LANE].lmmd[i][j]|=(1<<c); }
    else if (lmmc_stat==13 ) { mark= emax7[LANE].lmmd[m][j]& (1<<c); emax7[LANE].lmmd[m][j]|=((!lastdist)<<c);dmadr=lmmicp->top;dmlen=lmmicp->len;dmrw=1;}
    else { mark=0; }
  }
  if (mark) {
    if (phase == 1) {
      if ((emax7[LANE].lmmd[(m+1)%EMAX_DEPTH][j]&(1<<c)) && (dmadr+(dmlen+1)*sizeof(Uint)) == dmnxt) {
 if (!concat_adr[LANE][c]) { concat_adr[LANE][c] = dmadr; concat_len[LANE][c] = dmlen; }
 else { concat_len[LANE][c] += dmlen+1; }
 if (concat_len[LANE][c] < 8192) mark = 0;
      }
      else {
 if (concat_adr[LANE][c]) { concat_len[LANE][c] += dmlen+1; }
      }
    }
    else if (phase == 2) {
      if (lmmicp1->v && (dmadr+(dmlen+1)*sizeof(Uint)) == dmnxt) {
 if (!concat_adr[LANE][c]) { concat_adr[LANE][c] = dmadr; concat_len[LANE][c] = dmlen; }
 else { concat_len[LANE][c] += dmlen+1; }
 if (concat_len[LANE][c] < 8192) mark = 0;
      }
      else {
 if (concat_adr[LANE][c]) { concat_len[LANE][c] += dmlen+1; }
      }
    }
  }
  if (mark) {
    emax7[LANE].rw = dmrw;
    if (phase == 1) {
      emax7[LANE].ddraddr = (concat_adr[LANE][c])?concat_adr[LANE][c]:dmadr;
      emax7[LANE].lmmaddr = emax7[LANE].ddraddr;
      emax7[LANE].dmalen = (concat_adr[LANE][c])?concat_len[LANE][c]:dmlen;
    }
    else if (phase == 3 && dmrw==1) {
      emax7[LANE].ddraddr = dmadr+(Sll)(int)lmmicp->ofs;
      emax7[LANE].lmmaddr = emax7[LANE].ddraddr;
      emax7[LANE].dmalen = dmlen;
    }
    else if (phase == 2
   ||(phase == 3 && dmrw==0)) {
      if (lmmicp->blk==0) {
 if (phase == 2) {
   emax7[LANE].ddraddr = (concat_adr[LANE][c])?concat_adr[LANE][c]:dmadr;
   emax7[LANE].lmmaddr = emax7[LANE].ddraddr;
   emax7[LANE].dmalen = (concat_adr[LANE][c])?concat_len[LANE][c]:dmlen;
 }
 else {
   emax7[LANE].ddraddr = dmadr+(Sll)(int)lmmicp->ofs;
   emax7[LANE].lmmaddr = emax7[LANE].ddraddr;
   emax7[LANE].dmalen = dmlen;
 }
 emax7[LANE].blksize = 0;
      }
      else {
 if (phase == 2)
   emax7[LANE].plist = dmadr+emax7[LANE].blkcount*8;
 else
   emax7[LANE].plist = dmadr+emax7[LANE].blkcount*8+(Sll)(int)lmmicp->ofs;
 emax7[LANE].blksize = 32<<lmmicp->blk;
 if (emax7[LANE].blkcount==0) {
   emax7[LANE].lmmblktop = 0;
   emax7[LANE].lmmblklen = dmlen;
 }
 emax7[LANE].ddraddr = emax7[LANE].plist;
 emax7[LANE].lmmaddr = emax7[LANE].lmmblktop;
 emax7[LANE].dmalen = (emax7[LANE].lmmblklen<emax7[LANE].blksize)?emax7[LANE].lmmblklen:emax7[LANE].blksize-1;
 emax7[LANE].lmmblktop += emax7[LANE].blksize*sizeof(Ull);
 emax7[LANE].lmmblklen = (emax7[LANE].lmmblklen<emax7[LANE].blksize)?0:(emax7[LANE].lmmblklen-emax7[LANE].blksize);
 if (emax7[LANE].lmmblklen==0)
   emax7[LANE].blkcount = 0;
 else
   emax7[LANE].blkcount++;
      }
    }
    concat_adr[LANE][c] = 0;
    emax7_kick_dma(LANE, j);
  }
}
emax7_sigwait(int LANE)
{
  int signo;
  if (emax7[LANE].sigwait) {
    *emax7[LANE].sigstat = 2;
    sigwait(emax7[LANE].sigset, &signo);
    *emax7[LANE].sigstat = 1;
  }
}
static inline Ull arm64_read_dcache_line_size(void)
{
    Ull ctr;
    Ull dcache_line_size;
    const Ull bytes_per_word = 4;
    asm volatile ("mrs %0, ctr_el0" : "=r"(ctr) : : );
    asm volatile ("nop" : : : );
    dcache_line_size = (ctr >> 16) & 0xF;
    return (bytes_per_word << dcache_line_size);
}
static inline void arm64_flush_dcache_area(void* start, size_t size)
{
    Ull vaddr = (Ull)start;
    Ull __end = (Ull)start + size;
    Ull cache_line_size = arm64_read_dcache_line_size();
    Ull cache_line_mask = cache_line_size - 1;
    vaddr &= ~cache_line_mask;
    while (vaddr < __end) {
        asm volatile ("dc cvac, %0" : : "r"(vaddr) : );
        vaddr += cache_line_size;
    }
    asm volatile ("dsb	sy" : : : );
}
static inline void arm64_flush_inv_dcache_area(void* start, size_t size)
{
    Ull vaddr = (Ull)start;
    Ull __end = (Ull)start + size;
    Ull cache_line_size = arm64_read_dcache_line_size();
    Ull cache_line_mask = cache_line_size - 1;
    vaddr &= ~cache_line_mask;
    while (vaddr < __end) {
        asm volatile ("dc civac, %0" : : "r"(vaddr) : );
        vaddr += cache_line_size;
    }
    asm volatile ("dsb	sy" : : : );
}
emax7_kick_dma(int LANE, int j)
{
  int status_mm2s, status_s2mm;
  Ull dst, src;
  Uint pio_words, pio_loop, pio_i, pio_b4, pio_b8, pio_b16, pio_e4, pio_e8, pio_e16;
  if (!emax7[LANE].ddraddr)
    return (0);
  if (j != emax7[LANE].csel_save) {
    ((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].csel = j;
    emax7[LANE].csel_save = j;
  }
  if (1 && emax7[LANE].dmalen > 1) {
    if (emax7[LANE].rw == 0) {
      ((struct dma_ctrl*)emax7[LANE].dma_ctrl)->MM2S_DMACR = 0x00010001;
      arm64_flush_dcache_area(emax7[LANE].ddraddr, (emax7[LANE].dmalen+1)*sizeof(Uint));
      *(Ull*)&(((struct dma_ctrl*)emax7[LANE].dma_ctrl)->MM2S_SA) = emax7[LANE].ddraddr-emax_info[LANE].ddr_mmap+emax_info[LANE].ddr_phys;
      ((struct dma_ctrl*)emax7[LANE].dma_ctrl)->MM2S_LENGTH = (emax7[LANE].dmalen+1)*sizeof(Uint);
      ((struct dma_ctrl*)emax7[LANE].dma_ctrl)->S2MM_DMACR = 0x00010001;
      *(Ull*)&(((struct dma_ctrl*)emax7[LANE].dma_ctrl)->S2MM_DA) = emax7[LANE].lmmaddr-emax_info[LANE].ddr_mmap+emax_info[LANE].lmm_phys;
      ((struct dma_ctrl*)emax7[LANE].dma_ctrl)->S2MM_LENGTH = (emax7[LANE].dmalen+1)*sizeof(Uint);
      if (emax7[LANE].dmalen/8/150 > 40) usleep(emax7[LANE].dmalen/8/150/2);
      do {
 status_mm2s = ((struct dma_ctrl*)emax7[LANE].dma_ctrl)->MM2S_DMASR;
 status_s2mm = ((struct dma_ctrl*)emax7[LANE].dma_ctrl)->S2MM_DMASR;
 if ((status_mm2s & 0x71) || (status_s2mm & 0x71)) {
   ((struct dma_ctrl*)emax7[LANE].dma_ctrl)->MM2S_DMACR = 0x00010004;
   printf("emax7_check_lmmi_and_dma(): mem->lmm status_mm2s=%08x, status_s2mm=%8.8x (malfunction)\n", status_mm2s, status_s2mm);
   printf("emax7_check_lmmi_and_dma(): emax7[%d].ddraddr=%16.16llx -> emax7[%d].lmmaddr=%16.16llx len=%16.16llx\n", LANE, emax7[LANE].ddraddr, LANE, emax7[LANE].lmmaddr, (emax7[LANE].dmalen+1)*sizeof(Uint));
   break;
 }
      } while (!(status_mm2s & 0x2) || !(status_s2mm & 0x2));
      ((struct dma_ctrl*)emax7[LANE].dma_ctrl)->MM2S_DMASR = 0x00001000;
    }
    else {
      while (((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].stat & 0xffff00f0);
      ((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].dmrp = (1LL<<63)|(emax7[LANE].dmalen*sizeof(Uint)<<40)|(emax7[LANE].lmmaddr-emax_info[LANE].ddr_mmap+emax_info[LANE].lmm_phys);
      arm64_flush_inv_dcache_area(emax7[LANE].ddraddr, (emax7[LANE].dmalen+1)*sizeof(Uint));
      ((struct dma_ctrl*)emax7[LANE].dma_ctrl)->MM2S_DMACR = 0x00010001;
      *(Ull*)&(((struct dma_ctrl*)emax7[LANE].dma_ctrl)->MM2S_SA) = emax7[LANE].lmmaddr-emax_info[LANE].ddr_mmap+emax_info[LANE].lmm_phys;
      ((struct dma_ctrl*)emax7[LANE].dma_ctrl)->MM2S_LENGTH = (emax7[LANE].dmalen+1)*sizeof(Uint);
      ((struct dma_ctrl*)emax7[LANE].dma_ctrl)->S2MM_DMACR = 0x00010001;
      *(Ull*)&(((struct dma_ctrl*)emax7[LANE].dma_ctrl)->S2MM_DA) = emax7[LANE].ddraddr-emax_info[LANE].ddr_mmap+emax_info[LANE].ddr_phys;
      ((struct dma_ctrl*)emax7[LANE].dma_ctrl)->S2MM_LENGTH = (emax7[LANE].dmalen+1)*sizeof(Uint);
      if (emax7[LANE].dmalen/8/150 > 40) usleep(emax7[LANE].dmalen/8/150/2);
      do {
 status_mm2s = ((struct dma_ctrl*)emax7[LANE].dma_ctrl)->MM2S_DMASR;
 status_s2mm = ((struct dma_ctrl*)emax7[LANE].dma_ctrl)->S2MM_DMASR;
 if ((status_mm2s & 0x71) || (status_s2mm & 0x71)) {
   ((struct dma_ctrl*)emax7[LANE].dma_ctrl)->MM2S_DMACR = 0x00010004;
   printf("emax7_check_lmmi_and_dma(): lmm->mem status_mm2s=%08x, status_s2mm=%8.8x (malfunction)\n", status_mm2s, status_s2mm);
   printf("emax7_check_lmmi_and_dma(): emax7[%d].lmmaddr=%16.16llx -> emax7[%d].ddraddr=%16.16llx len=%16.16llx\n", LANE, emax7[LANE].lmmaddr, LANE, emax7[LANE].ddraddr, (emax7[LANE].dmalen+1)*sizeof(Uint));
   break;
 }
      } while (!(status_mm2s & 0x2) || !(status_s2mm & 0x2));
      ((struct dma_ctrl*)emax7[LANE].dma_ctrl)->MM2S_DMASR = 0x00001000;
      ((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].dmrp = (0LL<<63);
    }
  }
  else {
    if (emax7[LANE].rw == 0) {
      dst = emax7[LANE].lmmaddr-emax_info[LANE].ddr_mmap+emax_info[LANE].lmm_mmap;
      src = emax7[LANE].ddraddr;
    }
    else {
      dst = emax7[LANE].ddraddr;
      src = emax7[LANE].lmmaddr-emax_info[LANE].ddr_mmap+emax_info[LANE].lmm_mmap;
    }
    pio_words = emax7[LANE].dmalen+1;
    if (src & (sizeof(Ull)-1) & sizeof(Uint)) {
      *(Uint*)dst = *(Uint*)src;
      src += sizeof(Uint);
      dst += sizeof(Uint);
      pio_words--;
    }
    if (pio_words >= 2) {
      if (src & (sizeof(Dll)-1) & sizeof(Ull)) {
 *(Ull*)dst = *(Ull*)src;
 src += sizeof(Ull);
 dst += sizeof(Ull);
 pio_words-=2;
      }
    }
    if (pio_words >= 4) {
      if (pio_loop = pio_words/(sizeof(Dll)/sizeof(Uint))) {
 for(pio_i=0; pio_i<pio_loop; pio_i++)
   *((Dll*)dst + pio_i) = *((Dll*)src + pio_i);
 pio_words -= pio_loop*(sizeof(Dll)/sizeof(Uint));
 src += pio_loop*sizeof(Dll);
 dst += pio_loop*sizeof(Dll);
      }
    }
    if (pio_words >= 2) {
      *(Ull*)dst = *(Ull*)src;
      src += sizeof(Ull);
      dst += sizeof(Ull);
      pio_words-=2;
    }
    if (pio_words >= 1) {
      *(Uint*)dst = *(Uint*)src;
      src += sizeof(Uint);
      dst += sizeof(Uint);
      pio_words--;
    }
  }
  return (0);
}
emax7_pre_with_keep_cache()
{
}
emax7_pre_with_drain_cache()
{
}
void
cex(Uint op_cx, Ull *ex, Ull c3, Ull c2, Ull c1, Ull c0, Ushort pattern)
{
  Uint index1, index0;
  switch (op_cx) {
  case 0x00:
    if (ex)
      *ex = 3;
    break;
  case 0x01:
    index1 = ((c3>>32&1)<<3)|((c2>>32&1)<<2)|((c1>>32&1)<<1)|(c0>>32&1);
    index0 = ((c3 &1)<<3)|((c2 &1)<<2)|((c1 &1)<<1)|(c0 &1);
    *ex = 0;
    if (pattern>>index1&1) *ex |= 2;
    if (pattern>>index0&1) *ex |= 1;
    break;
  default:
    printf("emax7lib: cex: undefined op_cx=%d\n", op_cx);
    break;
  }
}
void
ex4(Uint op_ex1, Ull *d, Ull *r1, Uint exp1, Ull *r2, Uint exp2, Ull *r3, Uint exp3, Uint op_ex2, Ull *r4, Uint op_ex3, Ull *r5)
{
  switch (op_ex1) {
  case 0x08:
    exe(op_ex1, (d+0), (Ull)r1, exp1, *(r2+0), exp2, *(r3+0), exp3, 0x00, (Ull)r4, 0x00, (Ull)r5);
    exe(op_ex1, (d+0), *(d+0), exp1, *(r2+1), exp2, *(r3+1), exp3, 0x00, (Ull)r4, 0x00, (Ull)r5);
    exe(op_ex1, (d+0), *(d+0), exp1, *(r2+2), exp2, *(r3+2), exp3, 0x00, (Ull)r4, 0x00, (Ull)r5);
    exe(op_ex1, (d+0), *(d+0), exp1, *(r2+3), exp2, *(r3+3), exp3, 0x00, (Ull)r4, 0x00, (Ull)r5);
    break;
  case 0x00:
  case 0x03:
  case 0x04:
  case 0x05:
  case 0x06:
  case 0x07:
  case 0x0a:
  case 0x10:
  case 0x11:
  case 0x12:
  case 0x13:
  case 0x14:
  case 0x15:
  case 0x16:
  case 0x17:
  case 0x18:
    exe(op_ex1, (d+0), *(r1+0), exp1, *(r2+0), exp2, *(r3+0), exp3, 0x00, 0LL, 0x00, 0LL);
    exe(op_ex1, (d+1), *(r1+1), exp1, *(r2+1), exp2, *(r3+1), exp3, 0x00, 0LL, 0x00, 0LL);
    exe(op_ex1, (d+2), *(r1+2), exp1, *(r2+2), exp2, *(r3+2), exp3, 0x00, 0LL, 0x00, 0LL);
    exe(op_ex1, (d+3), *(r1+3), exp1, *(r2+3), exp2, *(r3+3), exp3, 0x00, 0LL, 0x00, 0LL);
    break;
  default:
    printf("emax7lib: ex4: undefined op_ex1=%d\n", op_ex1);
    break;
  }
  switch (op_ex2) {
  case 0x00:
    break;
  default:
    printf("emax7lib: ex4: illegal op_ex2=%d\n", op_ex2);
    break;
  }
  switch (op_ex3) {
  case 0x00:
    break;
  default:
    printf("emax7lib: ex4: illegal op_ex3=%d\n", op_ex3);
    break;
  }
}
int convf32tou7(Uchar *out, float in)
{
  f32bit in_f32;
  wu7bit out_u7;
  *(float*)&in_f32 = in;
  out_u7.s = in_f32.s;
  out_u7.b = 0;
  in = ((in)> 0 ? (in) :-(in) );
  if (in >= 1.0) out_u7.e = 63;
  else out_u7.e = in*64;
  *out = *(Uchar*)&out_u7;
}
int convf32tou8(Uchar *out, float in)
{
  f32bit in_f32;
  wu8bit out_u8;
  *(float*)&in_f32 = in;
  out_u8.s = in_f32.s;
  in = ((in)> 0 ? (in) :-(in) );
  if (in >= 2.0) out_u8.e = 127;
  else out_u8.e = in*64;
  *out = *(Uchar*)&out_u8;
}
int convu8tof32(float *out, Uchar in)
{
  wu8bit in_u8;
  f32bit out_f32;
  *(Uchar*)&in_u8 = in;
  *(float*)&out_f32 = (float)in_u8.e/64;
  out_f32.s = in_u8.s;
  *out = *(float*)&out_f32;
}
Ull urand(int no)
{
  static Ull urand_seed[8]
    = {0xc3c3c3c3a5a5a5a5LL, 0x123456789abcdef0LL, 0xe1e1e1e1d4d4d4d4LL, 0x8888777766665555LL,
       0x8787878796969696LL, 0xfedcba9876543210LL, 0x5a5a5a5a3c3c3c3cLL, 0xbbbbccccddddeeeeLL};
  Ull retval = urand_seed[no];
  urand_seed[no] ^= (urand_seed[no]<<29);
  urand_seed[no] ^= (urand_seed[no]>>27);
  urand_seed[no] ^= (urand_seed[no]<<37);
  return (retval);
}
Ull shfl(Ull in, Ull r)
{
  int i;
  for (i=0; i<32; i++) {
    if (r&(1LL<<(i+16)))
      in = (in&~(1LL<<(i+32)|1LL<<i)) | (in>>i&1)<<(i+32) | (in>>(i+32)&1)<<i;
  }
  for (i=0; i<48; i++) {
    if (r&(1LL<<(i+8)))
      in = (in&~(1LL<<(i+16)|1LL<<i)) | (in>>i&1)<<(i+16) | (in>>(i+16)&1)<<i;
  }
  for (i=0; i<56; i++) {
    if (r&(1LL<<(i+4)))
      in = (in&~(1LL<<(i+ 8)|1LL<<i)) | (in>>i&1)<<(i+ 8) | (in>>(i+ 8)&1)<<i;
  }
  for (i=0; i<60; i++) {
    if (r&(1LL<<(i+2)))
      in = (in&~(1LL<<(i+ 4)|1LL<<i)) | (in>>i&1)<<(i+ 4) | (in>>(i+ 4)&1)<<i;
  }
  for (i=0; i<62; i++) {
    if (r&(1LL<<(i+1)))
      in = (in&~(1LL<<(i+ 2)|1LL<<i)) | (in>>i&1)<<(i+ 2) | (in>>(i+ 2)&1)<<i;
  }
  for (i=0; i<63; i++) {
    if (r&(1LL<<(i+0)))
      in = (in&~(1LL<<(i+ 1)|1LL<<i)) | (in>>i&1)<<(i+ 1) | (in>>(i+ 1)&1)<<i;
  }
  return(in);
}
int enable_x11;
void x11_softu64_dist(float, float);
int softu64(int stage, Ull *o1, Ull *o2, Ull *o3, Ull r1, Ull r2, Ull r3, Ull r4)
{
  int i, j;
  Ull u[8];
  Ull ss[8];
  Ull s2[8], s3[8];
  int pc, nc;
  int os, oc;
  switch (stage) {
  case 1:
    for (i=0; i<8; i++)
      u[i] = urand(i);
    for (i=0; i<8; i++) {
      ss[i] = (r2>>(i*8+7))&1 ^ (r3>>(i*8+7))&1;
  int s2e = (r2>>(i*8))&0x7f; s2e = s2e<15?s2e:15;
  int s3e = (r3>>(i*8))&0x7f; s3e = s3e<15?s3e:15;
      s2[i] = 0LL;
      s3[i] = 0LL;
      for (j=0; j<12; j++) {
 int k = j * 4;
 s2[i] |= ((u[(i+0)%8]>>k&15)<=s2e)<<j;
 s3[i] |= ((u[(i+1)%8]>>k&15)<=s3e)<<j;
      }
      o1[i] = s2[i] & s3[i];
      o1[i] = ss[i]<<63|(o1[i]&0x7fffffffffffffffLL);
    }
    break;
  case 2:
    pc = 0;
    nc = 0;
    for (j=0; j<12; j++) {
      for (i=0; i<8; i++) {
 if (!(o1[i]>>63)) pc += (o1[i] & (1LL<<j))!=0;
 else nc += (o1[i] & (1LL<<j))!=0;
      }
    }
    pc = pc>>r4;
    nc = nc>>r4;
    *o2 = (Ull)(pc&0xffff)<<32 | (Ull)(nc&0xffff);
    break;
  case 3:
    pc = *o2>>32&0xffff;
    nc = *o2 &0xffff;
    if (!(r1&0x80)) pc += (r1&0x7f);
    else nc += (r1&0x7f);
    if (pc >= nc) {
      os = 0x00;
      oc = pc-nc;
    }
    else {
      os = 0x80;
      oc = nc-pc;
    }
    if (oc >= 128) oc = 127;
    *o3 = os|oc;
    break;
  }
  return (0);
}
Ull
exm(Ull s, Uchar exp)
{
  switch (exp) {
  case 0: return ( s );
  case 1: return ((s<<32&0xffffffff00000000LL) | (s &0x00000000ffffffffLL));
  case 2: return ((s &0xffffffff00000000LL) | (s>>32&0x00000000ffffffffLL));
  case 4: return ((s>> 8&0x00ff000000ff0000LL) | (s>>16&0x000000ff000000ffLL));
  case 3: return ((s<< 8&0x00ff000000ff0000LL) | (s &0x000000ff000000ffLL));
  default: return ( s );
  }
}
int
exe(Uint op_ex1, Ull *d, Ull s1, Uint exp1, Ull s2, Uint exp2, Ull s3, Uint exp3, Uint op_ex2, Ull r4, Uint op_ex3, Ull r5)
{
  union { Uint i; float f; } f3, f2, f1, f0;
  Ull r1, r2, r3;
  Ull t3, t2, t1, t0;
  short h3, h2, h1, h0;
  int w3, w2, w1, w0;
  Ull ro00, ro01, ro02, ro10, ro11, ro12;
  Ull c1, c0;
  Ull ex1_outd;
  Ull ex1_outd_sfma[8];
  Ull ex2_outd;
  int retval = 0;
  float convi4f32[16] = {-8.0, -7.0, -6.0, -5.0, -4.0, -3.0, -2.0, -1.0, 0.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0};
  if (op_ex1 == 0x03) {
    r1 = s1;
    r2 = exm(s2, exp2)>>(exp1&3)*2;
    r3 = exm(s3, exp3)>>(exp1&2)*2;
  }
  else if (op_ex1 == 0x06) {
    r1 = s1>>(exp1&~1)&0x0000030000000300LL | s1>>(exp1&~3)&0x0000000f0000000fLL;
    r2 = s2>> exp1;
    r3 = s3>>(exp1&3)*2;
  }
  else {
    r1 = exm(s1, exp1);
    r2 = exm(s2, exp2);
    r3 = exm(s3, exp3);
  }
  switch (op_ex1) {
  case 0x00:
    ex1_outd = r1;
    break;
  case 0x01:
    t0 = (r1&0x00000000ffffffffLL)+(r2&0x00000000ffffffffLL);
    t0 &= 0x00000000ffffffffLL;
    ex1_outd = t0;
    if (t0==0) retval = 1;
    break;
  case 0x02:
    t0 = (r1&0x00000000ffffffffLL)+(r2&0x00000000ffffffffLL);
    t0 &= 0x00000000ffffffffLL;
    ex1_outd = t0;
    if (t0==0) retval = 1;
    break;
  case 0x03:
    t2 = ((Ull)((signed char)(r1>>32&0xff) * ((signed char)((r2>>44&0x30)|(r3>>48&0x0f)) - 32))&0xffff)<<16
       | ((Ull)((signed char)(r1>>32&0xff) * ((signed char)((r2>>28&0x30)|(r3>>32&0x0f)) - 32))&0xffff)<< 0;
    t0 = ((Ull)((signed char)(r1>> 0&0xff) * ((signed char)((r2>>12&0x30)|(r3>>16&0x0f)) - 32))&0xffff)<<16
       | ((Ull)((signed char)(r1>> 0&0xff) * ((signed char)((r2<< 4&0x30)|(r3>> 0&0x0f)) - 32))&0xffff)<< 0;
    ex1_outd = (t2<<32)|(t0);
    break;
  case 0x04:
    w3 = (signed short)(r1>>48&0x000000000000ffffLL)*(signed char)(r2>>48&0x00000000000000ffLL);
    w2 = (signed short)(r1>>32&0x000000000000ffffLL)*(signed char)(r2>>32&0x00000000000000ffLL);
    w1 = (signed short)(r1>>16&0x000000000000ffffLL)*(signed char)(r2>>16&0x00000000000000ffLL);
    w0 = (signed short)(r1 &0x000000000000ffffLL)*(signed char)(r2 &0x00000000000000ffLL);
    w2 = w3+w2;
    w0 = w1+w0;
    t2 = (Uint)w2;
    t0 = (Uint)w0;
    ex1_outd = (t2<<32)|(t0);
    break;
  case 0x05:
    f1.i = (Uint)(r2>>32&0x80000000) ? (Uint)(r1>>32^0x80000000) : 0;
    f2.i = (Uint)(r2>>32&0x80000000) ? (Uint)(r1>>32^0x80000000) : (Uint)(r1>>32);
    f3.i = (Uint)(r2>>32&0x80000000) ? ~(Uint)(r2>>32) : (Uint)(r2>>32);
    f0.f = f1.f + (f2.f * (float)f3.i);
    t2 = f0.i;
    f1.i = (Uint)(r2&0x80000000) ? (Uint)(r1^0x80000000) : 0;
    f2.i = (Uint)(r2&0x80000000) ? (Uint)(r1^0x80000000) : (Uint)(r1);
    f3.i = (Uint)(r2&0x80000000) ? ~(Uint)(r2) : (Uint)(r2);
    f0.f = f1.f + (f2.f * (float)f3.i);
    t0 = f0.i;
    ex1_outd = (t2<<32)|(t0);
    break;
  case 0x06:
    t2 = ((Ull)(((signed char)((r1>>36&0x30|r1>>32&0x0f)>>1) - 16) * ((signed char)(r3>>56&0x03)-(r2>>56&0x01?0:4)))&0xff)<<24
       | ((Ull)(((signed char)((r1>>36&0x30|r1>>32&0x0f)>>1) - 16) * ((signed char)(r3>>48&0x03)-(r2>>48&0x01?0:4)))&0xff)<<16
       | ((Ull)(((signed char)((r1>>36&0x30|r1>>32&0x0f)>>1) - 16) * ((signed char)(r3>>40&0x03)-(r2>>40&0x01?0:4)))&0xff)<< 8
       | ((Ull)(((signed char)((r1>>36&0x30|r1>>32&0x0f)>>1) - 16) * ((signed char)(r3>>32&0x03)-(r2>>32&0x01?0:4)))&0xff)<< 0;
    t0 = ((Ull)(((signed char)((r1>> 4&0x30|r1>> 0&0x0f)>>1) - 16) * ((signed char)(r3>>24&0x03)-(r2>>24&0x01?0:4)))&0xff)<<24
       | ((Ull)(((signed char)((r1>> 4&0x30|r1>> 0&0x0f)>>1) - 16) * ((signed char)(r3>>16&0x03)-(r2>>16&0x01?0:4)))&0xff)<<16
       | ((Ull)(((signed char)((r1>> 4&0x30|r1>> 0&0x0f)>>1) - 16) * ((signed char)(r3>> 8&0x03)-(r2>> 8&0x01?0:4)))&0xff)<< 8
       | ((Ull)(((signed char)((r1>> 4&0x30|r1>> 0&0x0f)>>1) - 16) * ((signed char)(r3>> 0&0x03)-(r2>> 0&0x01?0:4)))&0xff)<< 0;
    ex1_outd = (t2<<32)|(t0);
    break;
  case 0x07:
    h3 = (signed short)((signed char)(r1>>48&0x00000000000000ffLL)*(signed char)(r2>>48&0x00000000000000ffLL));
    h2 = (signed short)((signed char)(r1>>32&0x00000000000000ffLL)*(signed char)(r2>>32&0x00000000000000ffLL));
    h1 = (signed short)((signed char)(r1>>16&0x00000000000000ffLL)*(signed char)(r2>>16&0x00000000000000ffLL));
    h0 = (signed short)((signed char)(r1 &0x00000000000000ffLL)*(signed char)(r2 &0x00000000000000ffLL));
    w2 = (int)h3+(int)h2;
    w0 = (int)h1+(int)h0;
    t2 = (Uint)w2;
    t0 = (Uint)w0;
    ex1_outd = (t2<<32)|(t0);
    break;
  case 0x08:
    softu64(1, ex1_outd_sfma, ((void *)0), ((void *)0), r1, r2, r3, r4);
    break;
  case 0x0a:
    f1.i = (Uint)(r1);
    f2.i = (Uint)(r2>>32);
    f3.i = (Uint)(r3>>32);
    if (f2.i != -1 && f2.i == f3.i) {
      f2.i = (Uint)(r2);
      f3.i = (Uint)(r3);
      f0.f = f1.f + (f2.f * f3.f);
    }
    else {
      f0.f = f1.f;
    }
    t0 = f0.i;
    ex1_outd = t0;
    break;
  case 0x10:
  case 0x11:
    f1.i = (Uint)(r1>>32);
    f2.i = (Uint)(r2>>32)^(op_ex1==0x10?0:0x80000000);
    f3.i = (Uint)(r3>>32);
    f0.f = f1.f + (f2.f * f3.f);
    t2 = f0.i;
    f1.i = (Uint)(r1);
    f2.i = (Uint)(r2)^(op_ex1==0x10?0:0x80000000);
    f3.i = (Uint)(r3);
    f0.f = f1.f + (f2.f * f3.f);
    t0 = f0.i;
    ex1_outd = (t2<<32)|(t0);
    break;
  case 0x12:
    f1.i = (Uint)(r1>>32);
    f2.i = (Uint)(r2>>32);
    f0.f = f1.f * f2.f;
    t2 = f0.i;
    f1.i = (Uint)(r1);
    f2.i = (Uint)(r2);
    f0.f = f1.f * f2.f;
    t0 = f0.i;
    ex1_outd = (t2<<32)|(t0);
    break;
  case 0x13:
    f1.i = (Uint)(r1>>32);
    f2.i = (Uint)(r2>>32);
    f0.f = f1.f + f2.f;
    t2 = f0.i;
    f1.i = (Uint)(r1);
    f2.i = (Uint)(r2);
    f0.f = f1.f + f2.f;
    t0 = f0.i;
    ex1_outd = (t2<<32)|(t0);
    break;
  case 0x14:
    f1.i = (Uint)(r1>>32);
    f2.i = (Uint)(r2>>32);
    f3.i = (Uint)(r3>>32);
    f0.f = f1.f * convi4f32[(f2.i>>((f3.i&7)*4))&0xf];
    t2 = f0.i;
    f1.i = (Uint)(r1);
    f2.i = (Uint)(r2);
    f3.i = (Uint)(r3);
    f0.f = f1.f * convi4f32[(f2.i>>((f3.i&7)*4))&0xf];
    t0 = f0.i;
    ex1_outd = (t2<<32)|(t0);
    break;
  case 0x15:
    t2 = (r1>>32&0x00000000ffffffffLL)+((r2>>32&0x00000000ffffffffLL)+(r3>>32&0x00000000ffffffffLL));
    t2 &= 0x00000000ffffffffLL;
    t0 = (r1 &0x00000000ffffffffLL)+((r2 &0x00000000ffffffffLL)+(r3 &0x00000000ffffffffLL));
    t0 &= 0x00000000ffffffffLL;
    ex1_outd = (t2<<32)|(t0);
    break;
  case 0x16:
    t2 = (r1>>32&0x00000000ffffffffLL)-((r2>>32&0x00000000ffffffffLL)+(r3>>32&0x00000000ffffffffLL));
    t2 &= 0x00000000ffffffffLL;
    t0 = (r1 &0x00000000ffffffffLL)-((r2 &0x00000000ffffffffLL)+(r3 &0x00000000ffffffffLL));
    t0 &= 0x00000000ffffffffLL;
    ex1_outd = (t2<<32)|(t0);
    break;
  case 0x17:
    t2 = (r1>>32&0x00000000ffffffffLL)+(r2>>32&0x00000000ffffffffLL);
    t2 &= 0x00000000ffffffffLL;
    t0 = (r1 &0x00000000ffffffffLL)+(r2 &0x00000000ffffffffLL);
    t0 &= 0x00000000ffffffffLL;
    ex1_outd = (t2<<32)|(t0);
    break;
  case 0x18:
    t2 = (r1>>32&0x00000000ffffffffLL)-(r2>>32&0x00000000ffffffffLL);
    t2 &= 0x00000000ffffffffLL;
    t0 = (r1 &0x00000000ffffffffLL)-(r2 &0x00000000ffffffffLL);
    t0 &= 0x00000000ffffffffLL;
    ex1_outd = (t2<<32)|(t0);
    break;
  case 0x19:
    c1 = (r1>>32&0x00000000ffffffffLL) == (r2>>32&0x00000000ffffffffLL);
    c0 = (r1 &0x00000000ffffffffLL) == (r2 &0x00000000ffffffffLL);
    ex1_outd = (c1<<32)|c0;
    break;
  case 0x1a:
    c1 = (r1>>32&0x00000000ffffffffLL) != (r2>>32&0x00000000ffffffffLL);
    c0 = (r1 &0x00000000ffffffffLL) != (r2 &0x00000000ffffffffLL);
    ex1_outd = (c1<<32)|c0;
    break;
  case 0x1b:
    c1 = (r1>>32&0x00000000ffffffffLL) < (r2>>32&0x00000000ffffffffLL);
    c0 = (r1 &0x00000000ffffffffLL) < (r2 &0x00000000ffffffffLL);
    ex1_outd = (c1<<32)|c0;
    break;
  case 0x1c:
    c1 = (r1>>32&0x00000000ffffffffLL) <= (r2>>32&0x00000000ffffffffLL);
    c0 = (r1 &0x00000000ffffffffLL) <= (r2 &0x00000000ffffffffLL);
    ex1_outd = (c1<<32)|c0;
    break;
  case 0x1d:
    c1 = (r1>>32&0x00000000ffffffffLL) > (r2>>32&0x00000000ffffffffLL);
    c0 = (r1 &0x00000000ffffffffLL) > (r2 &0x00000000ffffffffLL);
    ex1_outd = (c1<<32)|c0;
    break;
  case 0x1e:
    c1 = (r1>>32&0x00000000ffffffffLL) >= (r2>>32&0x00000000ffffffffLL);
    c0 = (r1 &0x00000000ffffffffLL) >= (r2 &0x00000000ffffffffLL);
    ex1_outd = (c1<<32)|c0;
    break;
  case 0x1f:
    c1 = r1>>32&1;
    c0 = r1 &1;
    t2 = c1 ? (r2&0xffffffff00000000LL) : (r3&0xffffffff00000000LL);
    t0 = c0 ? (r2&0x00000000ffffffffLL) : (r3&0x00000000ffffffffLL);
    ex1_outd = t2 | t0;
    break;
  case 0x20:
    t3 = (r1>>48&0x000000000000ffffLL)+((r2>>48&0x000000000000ffffLL)+(r3>>48&0x000000000000ffffLL));
    if (t3 > 0x000000000000ffffLL) t3 = 0x000000000000ffffLL;
    t2 = (r1>>32&0x000000000000ffffLL)+((r2>>32&0x000000000000ffffLL)+(r3>>32&0x000000000000ffffLL));
    if (t2 > 0x000000000000ffffLL) t2 = 0x000000000000ffffLL;
    t1 = (r1>>16&0x000000000000ffffLL)+((r2>>16&0x000000000000ffffLL)+(r3>>16&0x000000000000ffffLL));
    if (t1 > 0x000000000000ffffLL) t1 = 0x000000000000ffffLL;
    t0 = (r1 &0x000000000000ffffLL)+((r2 &0x000000000000ffffLL)+(r3 &0x000000000000ffffLL));
    if (t0 > 0x000000000000ffffLL) t0 = 0x000000000000ffffLL;
    ex1_outd = (t3<<48)|(t2<<32)|(t1<<16)|(t0);
    break;
  case 0x21:
    t3 = (r1>>48&0x000000000000ffffLL)+(r2>>48&0x000000000000ffffLL);
    if (t3 > 0x000000000000ffffLL) t3 = 0x000000000000ffffLL;
    t2 = (r1>>32&0x000000000000ffffLL)+(r2>>32&0x000000000000ffffLL);
    if (t2 > 0x000000000000ffffLL) t2 = 0x000000000000ffffLL;
    t1 = (r1>>16&0x000000000000ffffLL)+(r2>>16&0x000000000000ffffLL);
    if (t1 > 0x000000000000ffffLL) t1 = 0x000000000000ffffLL;
    t0 = (r1 &0x000000000000ffffLL)+(r2 &0x000000000000ffffLL);
    if (t0 > 0x000000000000ffffLL) t0 = 0x000000000000ffffLL;
    ex1_outd = (t3<<48)|(t2<<32)|(t1<<16)|(t0);
    break;
  case 0x22:
    t3 = (r1>>48&0x000000000000ffffLL)-((r2>>48&0x000000000000ffffLL)+(r3>>48&0x000000000000ffffLL));
    if (t3 > 0x000000000000ffffLL) t3 = 0x0000000000000000LL;
    t2 = (r1>>32&0x000000000000ffffLL)-((r2>>32&0x000000000000ffffLL)+(r3>>32&0x000000000000ffffLL));
    if (t2 > 0x000000000000ffffLL) t2 = 0x0000000000000000LL;
    t1 = (r1>>16&0x000000000000ffffLL)-((r2>>16&0x000000000000ffffLL)+(r3>>16&0x000000000000ffffLL));
    if (t1 > 0x000000000000ffffLL) t1 = 0x0000000000000000LL;
    t0 = (r1 &0x000000000000ffffLL)-((r2 &0x000000000000ffffLL)+(r3 &0x000000000000ffffLL));
    if (t0 > 0x000000000000ffffLL) t0 = 0x0000000000000000LL;
    ex1_outd = (t3<<48)|(t2<<32)|(t1<<16)|(t0);
    break;
  case 0x23:
    t3 = (r1>>48&0x000000000000ffffLL)-(r2>>48&0x000000000000ffffLL);
    if (t3 > 0x000000000000ffffLL) t3 = 0x0000000000000000LL;
    t2 = (r1>>32&0x000000000000ffffLL)-(r2>>32&0x000000000000ffffLL);
    if (t2 > 0x000000000000ffffLL) t2 = 0x0000000000000000LL;
    t1 = (r1>>16&0x000000000000ffffLL)-(r2>>16&0x000000000000ffffLL);
    if (t1 > 0x000000000000ffffLL) t1 = 0x0000000000000000LL;
    t0 = (r1 &0x000000000000ffffLL)-(r2 &0x000000000000ffffLL);
    if (t0 > 0x000000000000ffffLL) t0 = 0x0000000000000000LL;
    ex1_outd = (t3<<48)|(t2<<32)|(t1<<16)|(t0);
    break;
  case 0x24:
    t3 = (r1>>48&0x00000000000007ffLL)*(r2>>32&0x00000000000001ffLL);
    if (t3 > 0x000000000000ffffLL) t3 = 0x000000000000ffffLL;
    t2 = (r1>>32&0x00000000000007ffLL)*(r2>>32&0x00000000000001ffLL);
    if (t2 > 0x000000000000ffffLL) t2 = 0x000000000000ffffLL;
    t1 = (r1>>16&0x00000000000007ffLL)*(r2 &0x00000000000001ffLL);
    if (t1 > 0x000000000000ffffLL) t1 = 0x000000000000ffffLL;
    t0 = (r1 &0x00000000000007ffLL)*(r2 &0x00000000000001ffLL);
    if (t0 > 0x000000000000ffffLL) t0 = 0x000000000000ffffLL;
    ex1_outd = (t3<<48)|(t2<<32)|(t1<<16)|(t0);
    break;
  case 0x25:
    ex1_outd = ((r1&0x000000ff00000000LL)<<24) | ((r2&0x000000ff00000000LL)<<16) | ((r3&0x000000ff00000000LL)<<8)
             | ((r1&0x00000000000000ffLL)<<24) | ((r2&0x00000000000000ffLL)<<16) | ((r3&0x00000000000000ffLL)<<8);
    break;
  case 0x26:
    t3 = (r1>>48&0x000000000000ffffLL) + ((r2>>56&0x00000000000000ffLL)<(r3>>56&0x00000000000000ffLL)?(r3>>56&0x00000000000000ffLL)-(r2>>56&0x00000000000000ffLL):(r2>>56&0x00000000000000ffLL)-(r3>>56&0x00000000000000ffLL)) + ((r2>>48&0x00000000000000ffLL)<(r3>>48&0x00000000000000ffLL)?(r3>>48&0x00000000000000ffLL)-(r2>>48&0x00000000000000ffLL):(r2>>48&0x00000000000000ffLL)-(r3>>48&0x00000000000000ffLL));
    if (t3 > 0x000000000000ffffLL) t3 = 0x000000000000ffffLL;
    t2 = (r1>>32&0x000000000000ffffLL) + ((r2>>40&0x00000000000000ffLL)<(r3>>40&0x00000000000000ffLL)?(r3>>40&0x00000000000000ffLL)-(r2>>40&0x00000000000000ffLL):(r2>>40&0x00000000000000ffLL)-(r3>>40&0x00000000000000ffLL)) + ((r2>>32&0x00000000000000ffLL)<(r3>>32&0x00000000000000ffLL)?(r3>>32&0x00000000000000ffLL)-(r2>>32&0x00000000000000ffLL):(r2>>32&0x00000000000000ffLL)-(r3>>32&0x00000000000000ffLL));
    if (t2 > 0x000000000000ffffLL) t2 = 0x000000000000ffffLL;
    t1 = (r1>>16&0x000000000000ffffLL) + ((r2>>24&0x00000000000000ffLL)<(r3>>24&0x00000000000000ffLL)?(r3>>24&0x00000000000000ffLL)-(r2>>24&0x00000000000000ffLL):(r2>>24&0x00000000000000ffLL)-(r3>>24&0x00000000000000ffLL)) + ((r2>>16&0x00000000000000ffLL)<(r3>>16&0x00000000000000ffLL)?(r3>>16&0x00000000000000ffLL)-(r2>>16&0x00000000000000ffLL):(r2>>16&0x00000000000000ffLL)-(r3>>16&0x00000000000000ffLL));
    if (t1 > 0x000000000000ffffLL) t1 = 0x000000000000ffffLL;
    t0 = (r1 &0x000000000000ffffLL) + ((r2>> 8&0x00000000000000ffLL)<(r3>> 8&0x00000000000000ffLL)?(r3>> 8&0x00000000000000ffLL)-(r2>> 8&0x00000000000000ffLL):(r2>> 8&0x00000000000000ffLL)-(r3>> 8&0x00000000000000ffLL)) + ((r2 &0x00000000000000ffLL)<(r3 &0x00000000000000ffLL)?(r3 &0x00000000000000ffLL)-(r2 &0x00000000000000ffLL):(r2 &0x00000000000000ffLL)-(r3 &0x00000000000000ffLL));
    if (t0 > 0x000000000000ffffLL) t0 = 0x000000000000ffffLL;
    ex1_outd = (t3<<48)|(t2<<32)|(t1<<16)|(t0);
    break;
  case 0x27:
    t3 = ((r1>>56&0x00000000000000ffLL)<(r2>>56&0x00000000000000ffLL)?(r2>>56&0x00000000000000ffLL)-(r1>>56&0x00000000000000ffLL):(r1>>56&0x00000000000000ffLL)-(r2>>56&0x00000000000000ffLL)) + ((r1>>48&0x00000000000000ffLL)<(r2>>48&0x00000000000000ffLL)?(r2>>48&0x00000000000000ffLL)-(r1>>48&0x00000000000000ffLL):(r1>>48&0x00000000000000ffLL)-(r2>>48&0x00000000000000ffLL));
    if (t3 > 0x000000000000ffffLL) t3 = 0x000000000000ffffLL;
    t2 = ((r1>>40&0x00000000000000ffLL)<(r2>>40&0x00000000000000ffLL)?(r2>>40&0x00000000000000ffLL)-(r1>>40&0x00000000000000ffLL):(r1>>40&0x00000000000000ffLL)-(r2>>40&0x00000000000000ffLL)) + ((r1>>32&0x00000000000000ffLL)<(r2>>32&0x00000000000000ffLL)?(r2>>32&0x00000000000000ffLL)-(r1>>32&0x00000000000000ffLL):(r1>>32&0x00000000000000ffLL)-(r2>>32&0x00000000000000ffLL));
    if (t2 > 0x000000000000ffffLL) t2 = 0x000000000000ffffLL;
    t1 = ((r1>>24&0x00000000000000ffLL)<(r2>>24&0x00000000000000ffLL)?(r2>>24&0x00000000000000ffLL)-(r1>>24&0x00000000000000ffLL):(r1>>24&0x00000000000000ffLL)-(r2>>24&0x00000000000000ffLL)) + ((r1>>16&0x00000000000000ffLL)<(r2>>16&0x00000000000000ffLL)?(r2>>16&0x00000000000000ffLL)-(r1>>16&0x00000000000000ffLL):(r1>>16&0x00000000000000ffLL)-(r2>>16&0x00000000000000ffLL));
    if (t1 > 0x000000000000ffffLL) t1 = 0x000000000000ffffLL;
    t0 = ((r1>> 8&0x00000000000000ffLL)<(r2>> 8&0x00000000000000ffLL)?(r2>> 8&0x00000000000000ffLL)-(r1>> 8&0x00000000000000ffLL):(r1>> 8&0x00000000000000ffLL)-(r2>> 8&0x00000000000000ffLL)) + ((r1 &0x00000000000000ffLL)<(r2 &0x00000000000000ffLL)?(r2 &0x00000000000000ffLL)-(r1 &0x00000000000000ffLL):(r1 &0x00000000000000ffLL)-(r2 &0x00000000000000ffLL));
    if (t0 > 0x000000000000ffffLL) t0 = 0x000000000000ffffLL;
    ex1_outd = (t3<<48)|(t2<<32)|(t1<<16)|(t0);
    break;
  case 0x28:
    t3 = r3>>48&0x000000000000ffffLL;
    t2 = r3>>32&0x000000000000ffffLL;
    t1 = r3>>16&0x000000000000ffffLL;
    t0 = r3 &0x000000000000ffffLL;
    if (t3<t2) t2 = (r1&0xffff000000000000LL)|(r3>>16&0x0000ffff00000000LL);
    else t2 = (r2&0xffff000000000000LL)|(r3 &0x0000ffff00000000LL);
    if (t1<t0) t0 = (r1&0x00000000ffff0000LL)|(r3>>16&0x000000000000ffffLL);
    else t0 = (r2&0x00000000ffff0000LL)|(r3 &0x000000000000ffffLL);
    ex1_outd = t2 | t0;
    break;
  case 0x29:
    if ((r1&0x0000ffff00000000LL)<(r2&0x0000ffff00000000LL)) t2 = r1&0xffffffff00000000LL;
    else t2 = r2&0xffffffff00000000LL;
    if ((r1&0x000000000000ffffLL)<(r2&0x000000000000ffffLL)) t0 = r1&0x00000000ffffffffLL;
    else t0 = r2&0x00000000ffffffffLL;
    ex1_outd = t2 | t0;
   break;
  case 0x2a:
    ex1_outd = (((r1>>48&0x000000000000ff00LL) ? 255 : (r1>>48&0x00000000000000ffLL))<<56)
             | (((r1>>32&0x000000000000ff00LL) ? 255 : (r1>>32&0x00000000000000ffLL))<<48)
             | (((r2>>48&0x000000000000ff00LL) ? 255 : (r2>>48&0x00000000000000ffLL))<<40)
             | (((r2>>32&0x000000000000ff00LL) ? 255 : (r2>>32&0x00000000000000ffLL))<<32)
             | (((r1>>16&0x000000000000ff00LL) ? 255 : (r1>>16&0x00000000000000ffLL))<<24)
             | (((r1 &0x000000000000ff00LL) ? 255 : (r1 &0x00000000000000ffLL))<<16)
             | (((r2>>16&0x000000000000ff00LL) ? 255 : (r2>>16&0x00000000000000ffLL))<< 8)
             | (((r2 &0x000000000000ff00LL) ? 255 : (r2 &0x00000000000000ffLL)) );
    break;
  case 0x2b:
    t2 = ((r1&0x0000ffff00000000LL)<(r2&0x0000ffff00000000LL))?0:0x000000ff00000000LL;
    t0 = ((r1&0x000000000000ffffLL)<(r2&0x000000000000ffffLL))?0:0x00000000000000ffLL;
    ex1_outd = t2 | t0;
    break;
  case 0x2c:
    t1 = ((r1&0xff00000000000000LL)<(r2&0xff00000000000000LL)?(r1&0xff00000000000000LL):(r2&0xff00000000000000LL))
       | ((r1&0x00ff000000000000LL)<(r2&0x00ff000000000000LL)?(r1&0x00ff000000000000LL):(r2&0x00ff000000000000LL))
       | ((r1&0x0000ff0000000000LL)<(r2&0x0000ff0000000000LL)?(r1&0x0000ff0000000000LL):(r2&0x0000ff0000000000LL))
       | ((r1&0x000000ff00000000LL)<(r2&0x000000ff00000000LL)?(r1&0x000000ff00000000LL):(r2&0x000000ff00000000LL))
       | ((r1&0x00000000ff000000LL)<(r2&0x00000000ff000000LL)?(r1&0x00000000ff000000LL):(r2&0x00000000ff000000LL))
       | ((r1&0x0000000000ff0000LL)<(r2&0x0000000000ff0000LL)?(r1&0x0000000000ff0000LL):(r2&0x0000000000ff0000LL))
       | ((r1&0x000000000000ff00LL)<(r2&0x000000000000ff00LL)?(r1&0x000000000000ff00LL):(r2&0x000000000000ff00LL))
       | ((r1&0x00000000000000ffLL)<(r2&0x00000000000000ffLL)?(r1&0x00000000000000ffLL):(r2&0x00000000000000ffLL));
    t2 = ((r1&0xff00000000000000LL)>(r2&0xff00000000000000LL)?(r1&0xff00000000000000LL):(r2&0xff00000000000000LL))
       | ((r1&0x00ff000000000000LL)>(r2&0x00ff000000000000LL)?(r1&0x00ff000000000000LL):(r2&0x00ff000000000000LL))
       | ((r1&0x0000ff0000000000LL)>(r2&0x0000ff0000000000LL)?(r1&0x0000ff0000000000LL):(r2&0x0000ff0000000000LL))
       | ((r1&0x000000ff00000000LL)>(r2&0x000000ff00000000LL)?(r1&0x000000ff00000000LL):(r2&0x000000ff00000000LL))
       | ((r1&0x00000000ff000000LL)>(r2&0x00000000ff000000LL)?(r1&0x00000000ff000000LL):(r2&0x00000000ff000000LL))
       | ((r1&0x0000000000ff0000LL)>(r2&0x0000000000ff0000LL)?(r1&0x0000000000ff0000LL):(r2&0x0000000000ff0000LL))
       | ((r1&0x000000000000ff00LL)>(r2&0x000000000000ff00LL)?(r1&0x000000000000ff00LL):(r2&0x000000000000ff00LL))
       | ((r1&0x00000000000000ffLL)>(r2&0x00000000000000ffLL)?(r1&0x00000000000000ffLL):(r2&0x00000000000000ffLL));
    ex1_outd = ((r3&0xff00000000000000LL)<(t1&0xff00000000000000LL)?(t1&0xff00000000000000LL):((r3&0xff00000000000000LL)<(t2&0xff00000000000000LL)?(r3&0xff00000000000000LL):(t2&0xff00000000000000LL)))
             | ((r3&0x00ff000000000000LL)<(t1&0x00ff000000000000LL)?(t1&0x00ff000000000000LL):((r3&0x00ff000000000000LL)<(t2&0x00ff000000000000LL)?(r3&0x00ff000000000000LL):(t2&0x00ff000000000000LL)))
             | ((r3&0x0000ff0000000000LL)<(t1&0x0000ff0000000000LL)?(t1&0x0000ff0000000000LL):((r3&0x0000ff0000000000LL)<(t2&0x0000ff0000000000LL)?(r3&0x0000ff0000000000LL):(t2&0x0000ff0000000000LL)))
             | ((r3&0x000000ff00000000LL)<(t1&0x000000ff00000000LL)?(t1&0x000000ff00000000LL):((r3&0x000000ff00000000LL)<(t2&0x000000ff00000000LL)?(r3&0x000000ff00000000LL):(t2&0x000000ff00000000LL)))
             | ((r3&0x00000000ff000000LL)<(t1&0x00000000ff000000LL)?(t1&0x00000000ff000000LL):((r3&0x00000000ff000000LL)<(t2&0x00000000ff000000LL)?(r3&0x00000000ff000000LL):(t2&0x00000000ff000000LL)))
             | ((r3&0x0000000000ff0000LL)<(t1&0x0000000000ff0000LL)?(t1&0x0000000000ff0000LL):((r3&0x0000000000ff0000LL)<(t2&0x0000000000ff0000LL)?(r3&0x0000000000ff0000LL):(t2&0x0000000000ff0000LL)))
             | ((r3&0x000000000000ff00LL)<(t1&0x000000000000ff00LL)?(t1&0x000000000000ff00LL):((r3&0x000000000000ff00LL)<(t2&0x000000000000ff00LL)?(r3&0x000000000000ff00LL):(t2&0x000000000000ff00LL)))
             | ((r3&0x00000000000000ffLL)<(t1&0x00000000000000ffLL)?(t1&0x00000000000000ffLL):((r3&0x00000000000000ffLL)<(t2&0x00000000000000ffLL)?(r3&0x00000000000000ffLL):(t2&0x00000000000000ffLL)));
    break;
  case 0x2d:
    t1 = ((r1&0xff00000000000000LL)>(r2&0xff00000000000000LL)?(r1&0xff00000000000000LL):(r2&0xff00000000000000LL))
       | ((r1&0x00ff000000000000LL)>(r2&0x00ff000000000000LL)?(r1&0x00ff000000000000LL):(r2&0x00ff000000000000LL))
       | ((r1&0x0000ff0000000000LL)>(r2&0x0000ff0000000000LL)?(r1&0x0000ff0000000000LL):(r2&0x0000ff0000000000LL))
       | ((r1&0x000000ff00000000LL)>(r2&0x000000ff00000000LL)?(r1&0x000000ff00000000LL):(r2&0x000000ff00000000LL))
       | ((r1&0x00000000ff000000LL)>(r2&0x00000000ff000000LL)?(r1&0x00000000ff000000LL):(r2&0x00000000ff000000LL))
       | ((r1&0x0000000000ff0000LL)>(r2&0x0000000000ff0000LL)?(r1&0x0000000000ff0000LL):(r2&0x0000000000ff0000LL))
       | ((r1&0x000000000000ff00LL)>(r2&0x000000000000ff00LL)?(r1&0x000000000000ff00LL):(r2&0x000000000000ff00LL))
       | ((r1&0x00000000000000ffLL)>(r2&0x00000000000000ffLL)?(r1&0x00000000000000ffLL):(r2&0x00000000000000ffLL));
    ex1_outd = ((t1&0xff00000000000000LL)>(r3&0xff00000000000000LL)?(t1&0xff00000000000000LL):(r3&0xff00000000000000LL))
             | ((t1&0x00ff000000000000LL)>(r3&0x00ff000000000000LL)?(t1&0x00ff000000000000LL):(r3&0x00ff000000000000LL))
             | ((t1&0x0000ff0000000000LL)>(r3&0x0000ff0000000000LL)?(t1&0x0000ff0000000000LL):(r3&0x0000ff0000000000LL))
             | ((t1&0x000000ff00000000LL)>(r3&0x000000ff00000000LL)?(t1&0x000000ff00000000LL):(r3&0x000000ff00000000LL))
             | ((t1&0x00000000ff000000LL)>(r3&0x00000000ff000000LL)?(t1&0x00000000ff000000LL):(r3&0x00000000ff000000LL))
             | ((t1&0x0000000000ff0000LL)>(r3&0x0000000000ff0000LL)?(t1&0x0000000000ff0000LL):(r3&0x0000000000ff0000LL))
             | ((t1&0x000000000000ff00LL)>(r3&0x000000000000ff00LL)?(t1&0x000000000000ff00LL):(r3&0x000000000000ff00LL))
             | ((t1&0x00000000000000ffLL)>(r3&0x00000000000000ffLL)?(t1&0x00000000000000ffLL):(r3&0x00000000000000ffLL));
    break;
  case 0x2e:
    t1 = ((r1&0xff00000000000000LL)<(r2&0xff00000000000000LL)?(r1&0xff00000000000000LL):(r2&0xff00000000000000LL))
       | ((r1&0x00ff000000000000LL)<(r2&0x00ff000000000000LL)?(r1&0x00ff000000000000LL):(r2&0x00ff000000000000LL))
       | ((r1&0x0000ff0000000000LL)<(r2&0x0000ff0000000000LL)?(r1&0x0000ff0000000000LL):(r2&0x0000ff0000000000LL))
       | ((r1&0x000000ff00000000LL)<(r2&0x000000ff00000000LL)?(r1&0x000000ff00000000LL):(r2&0x000000ff00000000LL))
       | ((r1&0x00000000ff000000LL)<(r2&0x00000000ff000000LL)?(r1&0x00000000ff000000LL):(r2&0x00000000ff000000LL))
       | ((r1&0x0000000000ff0000LL)<(r2&0x0000000000ff0000LL)?(r1&0x0000000000ff0000LL):(r2&0x0000000000ff0000LL))
       | ((r1&0x000000000000ff00LL)<(r2&0x000000000000ff00LL)?(r1&0x000000000000ff00LL):(r2&0x000000000000ff00LL))
       | ((r1&0x00000000000000ffLL)<(r2&0x00000000000000ffLL)?(r1&0x00000000000000ffLL):(r2&0x00000000000000ffLL));
    ex1_outd = ((t1&0xff00000000000000LL)<(r3&0xff00000000000000LL)?(t1&0xff00000000000000LL):(r3&0xff00000000000000LL))
             | ((t1&0x00ff000000000000LL)<(r3&0x00ff000000000000LL)?(t1&0x00ff000000000000LL):(r3&0x00ff000000000000LL))
             | ((t1&0x0000ff0000000000LL)<(r3&0x0000ff0000000000LL)?(t1&0x0000ff0000000000LL):(r3&0x0000ff0000000000LL))
             | ((t1&0x000000ff00000000LL)<(r3&0x000000ff00000000LL)?(t1&0x000000ff00000000LL):(r3&0x000000ff00000000LL))
             | ((t1&0x00000000ff000000LL)<(r3&0x00000000ff000000LL)?(t1&0x00000000ff000000LL):(r3&0x00000000ff000000LL))
             | ((t1&0x0000000000ff0000LL)<(r3&0x0000000000ff0000LL)?(t1&0x0000000000ff0000LL):(r3&0x0000000000ff0000LL))
             | ((t1&0x000000000000ff00LL)<(r3&0x000000000000ff00LL)?(t1&0x000000000000ff00LL):(r3&0x000000000000ff00LL))
             | ((t1&0x00000000000000ffLL)<(r3&0x00000000000000ffLL)?(t1&0x00000000000000ffLL):(r3&0x00000000000000ffLL));
    break;
  case 0x2f:
    ex1_outd = ((r1&0xff00000000000000LL)>(r2&0xff00000000000000LL)?(r1&0xff00000000000000LL):(r2&0xff00000000000000LL))
             | ((r1&0x00ff000000000000LL)>(r2&0x00ff000000000000LL)?(r1&0x00ff000000000000LL):(r2&0x00ff000000000000LL))
             | ((r1&0x0000ff0000000000LL)>(r2&0x0000ff0000000000LL)?(r1&0x0000ff0000000000LL):(r2&0x0000ff0000000000LL))
             | ((r1&0x000000ff00000000LL)>(r2&0x000000ff00000000LL)?(r1&0x000000ff00000000LL):(r2&0x000000ff00000000LL))
             | ((r1&0x00000000ff000000LL)>(r2&0x00000000ff000000LL)?(r1&0x00000000ff000000LL):(r2&0x00000000ff000000LL))
             | ((r1&0x0000000000ff0000LL)>(r2&0x0000000000ff0000LL)?(r1&0x0000000000ff0000LL):(r2&0x0000000000ff0000LL))
             | ((r1&0x000000000000ff00LL)>(r2&0x000000000000ff00LL)?(r1&0x000000000000ff00LL):(r2&0x000000000000ff00LL))
             | ((r1&0x00000000000000ffLL)>(r2&0x00000000000000ffLL)?(r1&0x00000000000000ffLL):(r2&0x00000000000000ffLL));
    break;
  case 0x30:
    ex1_outd = ((r1&0xff00000000000000LL)<(r2&0xff00000000000000LL)?(r1&0xff00000000000000LL):(r2&0xff00000000000000LL))
             | ((r1&0x00ff000000000000LL)<(r2&0x00ff000000000000LL)?(r1&0x00ff000000000000LL):(r2&0x00ff000000000000LL))
             | ((r1&0x0000ff0000000000LL)<(r2&0x0000ff0000000000LL)?(r1&0x0000ff0000000000LL):(r2&0x0000ff0000000000LL))
             | ((r1&0x000000ff00000000LL)<(r2&0x000000ff00000000LL)?(r1&0x000000ff00000000LL):(r2&0x000000ff00000000LL))
             | ((r1&0x00000000ff000000LL)<(r2&0x00000000ff000000LL)?(r1&0x00000000ff000000LL):(r2&0x00000000ff000000LL))
             | ((r1&0x0000000000ff0000LL)<(r2&0x0000000000ff0000LL)?(r1&0x0000000000ff0000LL):(r2&0x0000000000ff0000LL))
             | ((r1&0x000000000000ff00LL)<(r2&0x000000000000ff00LL)?(r1&0x000000000000ff00LL):(r2&0x000000000000ff00LL))
             | ((r1&0x00000000000000ffLL)<(r2&0x00000000000000ffLL)?(r1&0x00000000000000ffLL):(r2&0x00000000000000ffLL));
    break;
  case 0x31:
    ex1_outd = (r1&0xffffffff00000000LL) | (((r1 & r2)^(r1 & r3)^(r2 & r3))&0xffffffffLL);
    break;
  case 0x32:
    ex1_outd = (r1&0xffffffff00000000LL) | (((r1 & r2)^(~r1 & r3))&0xffffffffLL);
    break;
  default:
    printf("emax7lib: exe: undefined op_ex1=%d\n", op_ex1);
    break;
  }
  switch (op_ex2) {
  case 0x00:
    if (op_ex1 == 0x08)
      softu64(2, ex1_outd_sfma, &ex2_outd, ((void *)0), r1, r2, r3, r4);
    else
      ex2_outd = ex1_outd;
    break;
  case 0x01:
    ex2_outd = ex1_outd & r4;
    break;
  case 0x02:
    ex2_outd = ex1_outd | r4;
    break;
  case 0x03:
    ex2_outd = ex1_outd ^ r4;
    break;
  case 0x04:
    t3 = ex1_outd>>48&0x000000000000ffffLL;
    t2 = ex1_outd>>32&0x000000000000ffffLL;
    t1 = ex1_outd>>16&0x000000000000ffffLL;
    t0 = ex1_outd &0x000000000000ffffLL;
    t3 += t2;
    if (t3 > 0x000000000000ffffLL) t3 = 0x000000000000ffffLL;
    t1 += t0;
    if (t1 > 0x000000000000ffffLL) t1 = 0x000000000000ffffLL;
    ex2_outd = (t3<<48)|(t1<<16);
    break;
  case 0x05:
    t3 = ex1_outd>>48&0x000000000000ffffLL;
    t2 = ex1_outd>>32&0x000000000000ffffLL;
    t1 = ex1_outd>>16&0x000000000000ffffLL;
    t0 = ex1_outd &0x000000000000ffffLL;
    t2 += t3;
    if (t2 > 0x000000000000ffffLL) t2 = 0x000000000000ffffLL;
    t0 += t1;
    if (t0 > 0x000000000000ffffLL) t0 = 0x000000000000ffffLL;
    ex2_outd = (t2<<32)|(t0);
    break;
  case 0x06:
    w2 = (int)(ex1_outd>>32&0xffffffff)+(int)(r4>>32&0xffffffff);
    w0 = (int)(ex1_outd &0xffffffff)+(int)(r4 &0xffffffff);
    t2 = (Uint)w2;
    t0 = (Uint)w0;
    ex2_outd = (t2<<32)|(t0);
    break;
  case 0x07:
    t2 = ex1_outd & 0xffffffff00000000LL;
    ro10 = r4>>32 & 0xff;
    ro11 = r4>>40 & 0xff;
    ro12 = r4>>48 & 0xff;
    t0 = ex1_outd & 0x00000000ffffffffLL;
    ro00 = r4 & 0xff;
    ro01 = r4>> 8 & 0xff;
    ro02 = r4>>16 & 0xff;
    ex2_outd = (((t2>>ro12|t2<<(32-ro12))^(t2>>ro11|t2<<(32-ro11))^(t2>>ro10|t2<<(32-ro10)))&0xffffffff00000000LL)
              |(((t0>>ro02|t0<<(32-ro02))^(t0>>ro01|t0<<(32-ro01))^(t0>>ro00|t0<<(32-ro00)))&0x00000000ffffffffLL);
    break;
  default:
    printf("emax7lib: exe: undefined op_ex2=%d\n", op_ex2);
    break;
  }
  switch (op_ex3) {
  case 0x00:
    if (op_ex1 == 0x08)
      softu64(3, ((void *)0), &ex2_outd, d, r1, r2, r3, r4);
    else
      if (d) *d = ex2_outd;
    break;
  case 0x01:
    t1 = (Ull)(ex2_outd &0xffffffff00000000LL)<<r5;
    t0 = (Ull)(ex2_outd<<r5&0x00000000ffffffffLL);
    if (d) *d = t1 | t0;
    break;
  case 0x02:
    t1 = (Ull)(ex2_outd>>r5&0xffffffff00000000LL);
    t0 = (Ull)(ex2_outd &0x00000000ffffffffLL)>>r5;
    if (d) *d = t1 | t0;
    break;
  case 0x03:
    t1 = (Sll)(ex2_outd )>>r5&0xffffffff00000000LL;
    t0 = (Sll)(ex2_outd<<32)>>r5&0xffffffff00000000LL;
    if (d) *d = t1 | (t0>>32);
    break;
  case 0x04:
    t1 = (Sll)(ex2_outd<< 8)>>(r5+8)&0xffffffff00000000LL;
    t0 = (Sll)(ex2_outd<<40)>>(r5+8)&0xffffffff00000000LL;
    if (d) *d = t1 | (t0>>32);
    break;
  case 0x07:
    t3 = (Ull)(ex2_outd )>>r5&0xffff000000000000LL;
    t2 = (Ull)(ex2_outd<<16)>>r5&0xffff000000000000LL;
    t1 = (Ull)(ex2_outd<<32)>>r5&0xffff000000000000LL;
    t0 = (Ull)(ex2_outd<<48)>>r5&0xffff000000000000LL;
    if (d) *d = t3 | (t2>>16) | (t1>>32) | (t0>>48);
    break;
  default:
    printf("emax7lib: exe: undefined op_ex3=%d\n", op_ex3);
    break;
  }
  return (retval);
}
void
mex(Uint op_mex2, Uchar **d2, Uchar *base2, Ull ofs2, Uint op_mex1, Uchar **d1, Uchar *base1, Ull ofs1, Ull limit, Ull s2, Ull s1)
{
  Uint limit2 = limit*2;
  Uint ss2 = s2>>32;
  Uint ss1 = s1>>32;
  switch (op_mex1) {
  case 0x00:
    *d1 = base1;
    break;
  case 1:
    *d1 = base1 + ofs1;
    break;
  case 3:
    if (!limit)
      *d1 = base1 + ((ss1!=0xffffffff && ss2>=ss1) ? ofs1:0);
    else {
      if ((base2==limit && base1+ofs1==limit2)||(base2+ofs2==limit && base1==limit2))
 *d1 = limit;
      else
 *d1 = base1 + (base1!=limit2 && ((base2!=limit && ss2>=ss1)||base2==limit ) ? ofs1:0);
    }
    break;
  default:
    printf("emax7lib: mex: undefined op_mex1=%d\n", op_mex1);
    break;
  }
  switch (op_mex2) {
  case 0x00:
    *d2 = base2;
    break;
  case 1:
    *d2 = base2 + ofs2;
    break;
  case 2:
    if (!limit)
      *d2 = base2 + ((ss2!=0xffffffff && ss2<=ss1) ? ofs2:0);
    else {
      if ((base2==limit && base1+ofs1==limit2)||(base2+ofs2==limit && base1==limit2))
 *d2 = 0;
      else
 *d2 = base2 + (base2!=limit && ((base1!=limit2 && ss2<=ss1)||base1==limit2) ? ofs2:0);
    }
    break;
  default:
    printf("emax7lib: mex: undefined op_mex2=%d\n", op_mex2);
    break;
  }
}
Ull
eam(Ull ofs, Uchar msk)
{
  switch (msk) {
  case 14: return (ofs);
  case 13: return (ofs>>32);
  case 12: return (ofs&0x00000000ffffffffLL);
  case 11: return (ofs>>48&0x000000000000ffffLL);
  case 10: return (ofs>>32&0x000000000000ffffLL);
  case 9: return (ofs>>16&0x000000000000ffffLL);
  case 8: return (ofs&0x000000000000ffffLL);
  case 7: return (ofs>>56&0x00000000000000ffLL);
  case 6: return (ofs>>48&0x00000000000000ffLL);
  case 5: return (ofs>>40&0x00000000000000ffLL);
  case 4: return (ofs>>32&0x00000000000000ffLL);
  case 3: return (ofs>>24&0x00000000000000ffLL);
  case 2: return (ofs>>16&0x00000000000000ffLL);
  case 1: return (ofs>>8&0x00000000000000ffLL);
  case 0: return (ofs&0x00000000000000ffLL);
  default: printf("emax7lib: eag: undefined msk=%d\n", msk); return (0LL);;
  }
}
void
eag(Ull *adr, Ull base, Ull ofs)
{
  *adr = base + ofs;
}
void
mop(Uint op_mm, Ull ex, Ull *d, Ull base, Ull offset, Uchar msk, Ull top, Uint len, Uint blk, Uchar force, Ull ptop, Uint plen)
{
  Ull adr, ofs;
  eag(&adr, base, eam(offset, msk));
  mmp(op_mm, ex, d, adr, top, len, blk);
}
void
mo4(Uint op_mm, Ull ex, Ull *d, Ull base, Ull offset, Uchar msk, Ull top, Uint len, Uint blk, Uchar force, Ull ptop, Uint plen)
{
  Ull adr, ofs;
  eag(&adr, base, eam(offset, msk));
  mmp(op_mm, ex, d, adr, top, len, blk);
}
void
mmp(Uint op_mm, Ull ex, Ull *d, Ull adr, Ull top, Uint len, Uint blk)
{
  Ull c1, c0, load64;
  if (!((op_mm==0x08 && blk) || op_mm==0x19 || op_mm==0x1a) && (!adr || !top)) return;
  if (!((op_mm==0x08 && blk) || op_mm==0x19 || op_mm==0x1a) && ex && len && (adr < top || adr >= top+len*sizeof(Uint)+12)) {
    printf("mmp: adr=%08.8x_%08.8x out of range (top=%08.8x_%08.8x len=%dB)\n", (Uint)(adr>>32), (Uint)adr, (Uint)(top>>32), (Uint)top, len*sizeof(Uint));
    fflush(stdout);
  }
  c1 = ex>>1&1;
  c0 = ex &1;
  switch (op_mm) {
  case 0x00:
    break;
  case 0x01:
    load64 = *(Ull*)(adr&~7LL);
    if ((adr&7) == 0)
      *d = load64;
    else if (!ex)
      *d = load64;
    else
      *d = *(d+1) << (8-(adr&7))*8 | load64 >> (adr&7)*8;
    break;
  case 0x02:
    *d = (Ull)*(Uint*)(adr&~3LL);
    break;
  case 0x04:
    *d = (Ull)(Uint)*(Uchar*)adr;
    break;
  case 0x11:
    if (c1) *((Uint*)(adr&~7LL)+1) = *d>>32;
    if (c0) *((Uint*)(adr&~7LL) ) = *d;
    break;
  case 0x12:
    if (c0) *(Uint*)(adr&~3LL) = *d;
    break;
  case 0x14:
    if (c0) *(Uchar*)adr = *d;
    break;
  case 0x08:
    switch (blk) {
    case 0:
      *(d+0) = *((Ull*)(adr&~31LL)+0);
      *(d+1) = *((Ull*)(adr&~31LL)+1);
      *(d+2) = *((Ull*)(adr&~31LL)+2);
      *(d+3) = *((Ull*)(adr&~31LL)+3);
      break;
    case 1:
      *(d+0) = *(*(Ull**)(top + (adr/32/16*sizeof(Ull*))) + (adr/32&15)*4 + 0);
      *(d+1) = *(*(Ull**)(top + (adr/32/16*sizeof(Ull*))) + (adr/32&15)*4 + 1);
      *(d+2) = *(*(Ull**)(top + (adr/32/16*sizeof(Ull*))) + (adr/32&15)*4 + 2);
      *(d+3) = *(*(Ull**)(top + (adr/32/16*sizeof(Ull*))) + (adr/32&15)*4 + 3);
      break;
    case 2:
      *(d+0) = *(*(Ull**)(top + (adr/32/32*sizeof(Ull*))) + (adr/32&31)*4 + 0);
      *(d+1) = *(*(Ull**)(top + (adr/32/32*sizeof(Ull*))) + (adr/32&31)*4 + 1);
      *(d+2) = *(*(Ull**)(top + (adr/32/32*sizeof(Ull*))) + (adr/32&31)*4 + 2);
      *(d+3) = *(*(Ull**)(top + (adr/32/32*sizeof(Ull*))) + (adr/32&31)*4 + 3);
      break;
    default:
      *(d+0) = *(*(Ull**)(top + (adr/32/64*sizeof(Ull*))) + (adr/32&63)*4 + 0);
      *(d+1) = *(*(Ull**)(top + (adr/32/64*sizeof(Ull*))) + (adr/32&63)*4 + 1);
      *(d+2) = *(*(Ull**)(top + (adr/32/64*sizeof(Ull*))) + (adr/32&63)*4 + 2);
      *(d+3) = *(*(Ull**)(top + (adr/32/64*sizeof(Ull*))) + (adr/32&63)*4 + 3);
      break;
    }
    break;
  case 0x19:
    if (c0) {
      *(d+0) = *((Ull*)(adr&~31LL)+0);
      *(d+1) = *((Ull*)(adr&~31LL)+1);
      *(d+2) = *((Ull*)(adr&~31LL)+2);
      *(d+3) = *((Ull*)(adr&~31LL)+3);
    }
    break;
  case 0x18:
    *((Ull*)(adr&~31LL)+0) = *(d+0);
    *((Ull*)(adr&~31LL)+1) = *(d+1);
    *((Ull*)(adr&~31LL)+2) = *(d+2);
    *((Ull*)(adr&~31LL)+3) = *(d+3);
    break;
  case 0x1a:
    if (c0) {
      Ull (*trans)() = top;
      (trans)(*(d+0), *(d+1), *(d+2), *(d+3));
    }
    break;
  default:
    printf("emax7lib: mmp: undefined op_mm=%d\n", op_mm);
    break;
  }
}
    static Ull max_SRC0_ROW_LEN_COPY_BYTES = 0;
    static Ull max_SRC1_COL_LEN_COPY_BYTES = 0;
int cpyin_skip_count = 0;
void *memcpy();
pthread_barrier_t copy_barrier;
Uchar *membase;
Ull memsize_shared;
Ull memsize_local;
Ull memsize;
int memalign;
int src0_preloaded;
Ull SRC0_ROW_TOP_DIRECT;
void *i_i16[8];
void *i_f16[8];
void *i_m0A[8];
void *i_m0B[8];
void *i_m0C[8];
void *i_m0D[8];
Ull i_i16_max_size;
Ull i_f16_max_size;
Ull i_m0A_max_size;
Ull i_m0B_max_size;
Ull i_m0C_max_size;
Ull i_m0D_max_size;
int show_nanosec_count = 0;
Ull TOTAL_BUFFER_LOAD_SIZE = 0;
Ull TOTAL_BUFFER_DRAIN_SIZE = 0;
int counter_imax_operations = 0;
pthread_barrier_t g_params_wdata_ready_barrier;
int g_n_consumer_threads = 0;
extern float ggml_table_f32_f16[1 << 16];
inline static float ggml_lookup_fp16_to_fp32(ggml_fp16_t f) {
    return ggml_table_f32_f16[*(uint16_t*)&f];
}
extern float ggml_table_f32_i16[1 << 16];
inline static float ggml_lookup_int16_to_fp32(uint16_t i) {
    return ggml_table_f32_i16[i];
}
void init_xmax(int nth)
{
  int l;
  if ((NLANE = emax7_open(nth)) == ((void *)0))
    exit(1);
  if (NLANE < nth) {
    printf("NLANE(installed=%d) < nth(requested=%d) in init_xmax\n", NLANE, nth);
    exit(1);
  }
  { if (i_i16_max_size < (0x40000)) i_i16_max_size = (0x40000); };
  { if (i_f16_max_size < (0x40000)) i_f16_max_size = (0x40000); };
  { if (i_m0A_max_size < (0xEA000000)) i_m0A_max_size = (0xEA000000); };
  { if (i_m0B_max_size < (0x20000)) i_m0B_max_size = (0x20000); };
  { if (i_m0C_max_size < (0x20000)) i_m0C_max_size = (0x20000); };
  { if (memsize_shared < (i_i16_max_size+i_f16_max_size+i_m0A_max_size)) memsize_shared = (i_i16_max_size+i_f16_max_size+i_m0A_max_size); };
  { if (memsize_local < (i_m0B_max_size+i_m0C_max_size)) memsize_local = (i_m0B_max_size+i_m0C_max_size); };
  memsize = memsize_shared + memsize_local*NLANE;
  memalign = 32;
  if (memsize > 0x0000000100000000LL) {
    printf("memsize*NLANE: %08.8x+%08.8x exceeds DDR_MMAP_SIZE=%08.8x\n", (Uint)memsize_shared, (Uint)memsize_local*NLANE, (Uint)0x0000000100000000LL);
    exit(1);
  }
  membase = emax_info[0].ddr_mmap;
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
  for (l=0; l<IMAX_DMABUF_LAST; l++) {
    if (imax_dmabuf_map[l].dmabufmap == 2)
      break;
  }
  printf("imax_dmabuf_map[%d].blk_size=%16.16llx\n", l, imax_dmabuf_map[l].blk_size);
  printf("i_m0A_max_size=%16.16llx\n", i_m0A_max_size);
  if (l < IMAX_DMABUF_LAST && imax_dmabuf_map[l].blk_size < i_m0A_max_size) {
    printf("Found imax_dmabuf_map[%d] src_blk_top=%16.16llx blk_size=%16.16llx\n", l, imax_dmabuf_map[l].src_blk_top, imax_dmabuf_map[l].blk_size, imax_dmabuf_map[l].imax_blk_ofs);
    printf("Initializing i_m0A[0]/DMABUF from imax_dmabuf_map[%d].src_blk_top size=%16.16llx\n", l, imax_dmabuf_map[l].blk_size);
    monitor_time_start(0, IMAX_CPYIN_PRELOAD);
    xmax_cpyin(3, i_m0A[0], &ctmp, imax_dmabuf_map[l].src_blk_top, 1, 1, imax_dmabuf_map[l].blk_size/sizeof(int), 1, 1);
    monitor_time_end(0, IMAX_CPYIN_PRELOAD);
    printf("preload ok\n");
    src0_preloaded = 1;
    SRC0_ROW_TOP_DIRECT = imax_dmabuf_map[l].src_blk_top;
  }
if (NLANE > 0) {
    if (pthread_barrier_init(&g_params_wdata_ready_barrier, ((void *)0), NLANE) != 0) {
        perror("ERROR: pthread_barrier_init for g_params_wdata_ready_barrier failed");
    }
    printf("INFO: g_params_wdata_ready_barrier initialized for %d consumer threads.\n", NLANE);
} else {
    printf("WARN: NLANE is %d, g_params_wdata_ready_barrier not initialized.\n", NLANE);
}
  { int i;
    int stat;
    for (i=0; i<NLANE; i++) {
      emax7[i].dma_ctrl = emax_info[i].dma_mmap;
      emax7[i].reg_ctrl = emax_info[i].reg_mmap;
      ((struct reg_ctrl*)emax7[i].reg_ctrl)->i[0].cmd = CMD_RESET;
      usleep(1);
      ((struct reg_ctrl*)emax7[i].reg_ctrl)->i[0].adtr = emax_info[i].ddr_mmap - emax_info[i].lmm_phys;
      ((struct reg_ctrl*)emax7[i].reg_ctrl)->i[0].dmrp = 0LL;
      stat = ((struct reg_ctrl*)emax7[i].reg_ctrl)->i[0].stat>>8 & 0xf;
      switch (stat) {
      case 0:EMAX_DEPTH = 8;break;
      case 1:EMAX_DEPTH = 16;break;
      case 2:EMAX_DEPTH = 32;break;
      case 3:EMAX_DEPTH = 64;break;
      default:
        printf("init_xmax: illegal stat=%x for setting EMAX_DEPTH\n", stat);
        exit(1);
      }
      stat = ((struct reg_ctrl*)emax7[i].reg_ctrl)->i[0].stat>>12 & 0xf;
      switch (stat) {
      case 0:LMM_SIZE = 32768;break;
      case 1:LMM_SIZE = 65536;break;
      case 2:LMM_SIZE = 131072;break;
      case 3:LMM_SIZE = 262144;break;
      case 4:LMM_SIZE = 524288;break;
      default:
        printf("init_xmax: illegal stat=%x for setting LMM_SIZE\n", stat);
        exit(1);
      }
      printf("EMAX7[%d].DEPTH=%d LMM_SIZE=%d\n", i, EMAX_DEPTH, LMM_SIZE);
    }
  }
  printf("EMAX7: NLANE=%d DEPTH=%d LMM_SIZE=%d\n", NLANE, EMAX_DEPTH, LMM_SIZE);
}
void imemcpy_byte_by_byte2(volatile Uchar *dst, volatile Uchar *src, int bytes,int lane) {
  printf("LANE %d: imemcpy_byte_by_byte: dst=%16.16llx src=%16.16llx bytes=%d\n", lane, (Ull)dst, (Ull)src, bytes);
  for (int i = 0; i < bytes; i++) {
    dst[i] = src[i];
  }
}
void imemcpy_byte_by_byte(volatile Uchar *dst, volatile Uchar *src, int bytes) {
  for (int i = 0; i < bytes; i++) {
    dst[i] = src[i];
  }
}
void imemcpy(Uint *dst, Uint *src, int words)
{
  union {
    Uint i[4];
    Ull l[2];
    Dll d;
  } buf;
  Uint loop, i;
  if (words >= 1 && ((Ull)dst & sizeof(Uint))) {
    *dst++ = *src++;
    words--;
  }
  if (words >= 2 && ((Ull)dst & sizeof(Ull))) {
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
      }
    }
    else if ((Ull)src & sizeof(Ull)) {
      for(i=0; i<loop; i++) {
        buf.l[0] = *(Ull*)src;src += sizeof(Ull)/sizeof(Uint);
        buf.l[1] = *(Ull*)src;src += sizeof(Ull)/sizeof(Uint);
        *(Dll*)dst = buf.d;
        dst += sizeof(Dll)/sizeof(Uint);
      }
    }
    else {
      for(i=0; i<loop; i++) {
        *(Dll*)dst = *(Dll*)src;
        src += sizeof(Dll)/sizeof(Uint);
        dst += sizeof(Dll)/sizeof(Uint);
      }
    }
    words -= loop*(sizeof(Dll)/sizeof(Uint));
  }
  if (words >= 2) {
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
  }
  if (words >= 1) {
    *dst++ = *src++;
    words--;
  }
}
void __attribute__((optimize("O3"))) imemcpy_fast_aligned(Dll *dst_aligned, Dll *src_aligned, int words)
{
  int loop = words / (sizeof(Dll)/sizeof(Uint));
  if (loop >= 32) {
    int unrolled_loops = loop / 8;
    int remainder = loop % 8;
    for (int i = 0; i < unrolled_loops; i++) {
      __builtin_prefetch(&src_aligned[i*8+8], 0, 3);
      __builtin_prefetch(&dst_aligned[i*8+8], 1, 3);
      dst_aligned[i*8+0] = src_aligned[i*8+0];
      dst_aligned[i*8+1] = src_aligned[i*8+1];
      dst_aligned[i*8+2] = src_aligned[i*8+2];
      dst_aligned[i*8+3] = src_aligned[i*8+3];
      dst_aligned[i*8+4] = src_aligned[i*8+4];
      dst_aligned[i*8+5] = src_aligned[i*8+5];
      dst_aligned[i*8+6] = src_aligned[i*8+6];
      dst_aligned[i*8+7] = src_aligned[i*8+7];
    }
    Dll *dst_rem = &dst_aligned[unrolled_loops*8];
    Dll *src_rem = &src_aligned[unrolled_loops*8];
    for (int i = 0; i < remainder; i++) {
      dst_rem[i] = src_rem[i];
    }
  } else {
    for (int i = 0; i < loop; i++) {
      dst_aligned[i] = src_aligned[i];
    }
  }
}
void __attribute__((optimize("O3"))) xmax_bzero_fast_large(Uint *dst, int words)
{
  if (words >= 64) {
    memset(dst, 0, words * sizeof(Uint));
    return;
  }
  xmax_bzero(dst, words);
}
void __attribute__((optimize("O3"))) xmax_bzero(Uint *dst, int words)
{
  Uint loop, i;
  if (words >= 1 && ((Ull)dst & sizeof(Uint))) {
    *dst++ = 0;
    words--;
  }
  if (words >= 2 && ((Ull)dst & sizeof(Ull))) {
    *(Ull*)dst = 0;
    dst += sizeof(Ull)/sizeof(Uint);
    words-=2;
  }
  if (loop = words/(sizeof(Dll)/sizeof(Uint))) {
    for(i=0; i<loop; i++) {
      *((Dll*)dst) = 0;
      dst += sizeof(Dll)/sizeof(Uint);
    }
    words -= loop*(sizeof(Dll)/sizeof(Uint));
  }
  if (words >= 2) {
    *(Ull*)dst = 0;
    dst += sizeof(Ull)/sizeof(Uint);
      words-=2;
    }
  if (words >= 1) {
    *dst++ = 0;
    words--;
  }
}
void __attribute__((optimize("O3"))) xmax_cpyin(int order, Uint *dst, int *imo, Uint *src, int batch, int ic, int im, int m, int k)
{
  switch (order) {
  case 0:
    if (im == m && 1<k) {
      int n, i, w = im+k-1;
      for (n=0; n<batch*ic; n++,dst+=w*w,src+=im*im) {
        for (i=0; i<k/2; i++)
          xmax_bzero(dst+i*w, w);
        for (i=k/2; i<=im+k/2-1; i++) {
          xmax_bzero (dst+i*w, (k/2) );
          imemcpy(dst+i*w+(k/2), src+(i-k/2)*im, im);
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
  case 1:
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
    if (im == m && 1<k) {
      int n1, n0, i, w = im+k-1;
      for (n1=0; n1<batch; n1++) {
        for (n0=0; n0<ic; n0++,src+=im*im) {
          int ofs = (n0*w*batch+n1)*w;
          int dist = batch*w;
          for (i=0; i<k/2; i++)
            xmax_bzero(dst+ofs+i*dist, w);
          for (i=k/2; i<=im+k/2-1; i++) {
            xmax_bzero (dst+ofs+i*dist, (k/2) );
            imemcpy(dst+ofs+i*dist+(k/2), src+(i-k/2)*im, im);
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
      for (n1=0; n1<batch; n1++) {
        for (n0=0; n0<ic; n0++,src+=im*im) {
          int ofs = (n0*im*batch+n1)*im;
          int dist = batch*im;
          for (i=0; i<im; i++)
            imemcpy(dst+ofs+i*dist, src+i*im, im);
        }
      }
      *imo = im;
    }
    break;
 case 3:
    Ull byte_size = (Ull)(im*m) * sizeof(Uint);
    const Ull dst_aligned_16 = ((Ull)dst & 0xF) == 0;
    const Ull src_aligned_16 = ((Ull)src & 0xF) == 0;
    const int words_aligned_4 = (im*m % 4) == 0;
    if (dst_aligned_16 && src_aligned_16 && words_aligned_4 && im*m >= 32) {
      imemcpy_fast_aligned((Dll*)dst, (Dll*)src, im*m);
    } else {
      imemcpy(dst, src, im*m);
    }
    *imo = im;
    break;
  }
}
void __attribute__((optimize("O3"))) xmax_cpyout(int order, Uint *dst, int batch, int oc, Uint *src, int m, int n, int oc4)
{
  int k, k2, k1, k0;
  switch (order) {
  case 0:
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
    for (k1=0; k1<n; k1++) {
      for (k0=0; k0<m; k0++)
 dst[k1*batch+k0]=src[k1+k0*n];
    }
    break;
  case 4:
    for (k1=0; k1<m; k1++) {
      for (k0=0; k0<oc4; k0++) {
 imemcpy(dst+k1*oc+k0*n, src+k1*n+k0*m*n, n);
      }
    }
    break;
  }
}
void imax_compute_forward_mul_mat_one_chunk_f32(struct th_inference_args *args)
{
  int THREAD = args->thid;
  int LANE = args->thid;
  struct ggml_tensor * dst = args->dst;
  const int64_t num_rows_per_vec_dot = args->num_rows_per_vec_dot;
  const int64_t ir0_start = args->ir0_start;
  const int64_t ir0_end = args->ir0_end;
  const int64_t ir1_start = args->ir1_start;
  const int64_t ir1_end = args->ir1_end;
  const struct ggml_tensor * src0 = args->src0;
  const struct ggml_tensor * src1 = args->src1;
  const enum ggml_type type = args->type;
  const _Bool src1_cont = args->src1_cont;
  ggml_vec_dot_t const vec_dot = args->vec_dot;
  enum ggml_type const vec_dot_type = args->vec_dot_type;
  const void * wdata = args->wdata;
  const size_t row_size = args->row_size;
  const int64_t r2 = args->r2;
  const int64_t r3 = args->r3;
  const int64_t blck_0 = args->blck_0;
  const int64_t blck_1 = args->blck_1;
  const size_t src1_col_stride = args->src1_col_stride;
  int i;
  float tmp[32];
  const int64_t ne00 = (src0) ? (src0)->ne[0] : 0; (void)(ne00); const int64_t ne01 = (src0) ? (src0)->ne[1] : 0; (void)(ne01); const int64_t ne02 = (src0) ? (src0)->ne[2] : 0; (void)(ne02); const int64_t ne03 = (src0) ? (src0)->ne[3] : 0; (void)(ne03); const size_t nb00 = (src0) ? (src0)->nb[0] : 0; (void)(nb00); const size_t nb01 = (src0) ? (src0)->nb[1] : 0; (void)(nb01); const size_t nb02 = (src0) ? (src0)->nb[2] : 0; (void)(nb02); const size_t nb03 = (src0) ? (src0)->nb[3] : 0; (void)(nb03); const int64_t ne10 = (src1) ? (src1)->ne[0] : 0; (void)(ne10); const int64_t ne11 = (src1) ? (src1)->ne[1] : 0; (void)(ne11); const int64_t ne12 = (src1) ? (src1)->ne[2] : 0; (void)(ne12); const int64_t ne13 = (src1) ? (src1)->ne[3] : 0; (void)(ne13); const size_t nb10 = (src1) ? (src1)->nb[0] : 0; (void)(nb10); const size_t nb11 = (src1) ? (src1)->nb[1] : 0; (void)(nb11); const size_t nb12 = (src1) ? (src1)->nb[2] : 0; (void)(nb12); const size_t nb13 = (src1) ? (src1)->nb[3] : 0; (void)(nb13); const int64_t ne0 = (dst) ? (dst)->ne[0] : 0; (void)(ne0); const int64_t ne1 = (dst) ? (dst)->ne[1] : 0; (void)(ne1); const int64_t ne2 = (dst) ? (dst)->ne[2] : 0; (void)(ne2); const int64_t ne3 = (dst) ? (dst)->ne[3] : 0; (void)(ne3); const size_t nb0 = (dst) ? (dst)->nb[0] : 0; (void)(nb0); const size_t nb1 = (dst) ? (dst)->nb[1] : 0; (void)(nb1); const size_t nb2 = (dst) ? (dst)->nb[2] : 0; (void)(nb2); const size_t nb3 = (dst) ? (dst)->nb[3] : 0; (void)(nb3);
  int n = ne00;
  if (1) {
    monitor_time_start(THREAD, IMAX_COMPUTE_FORWARD_MUL_MAT_ONE_CHUNK_F32_ARM);
    for (int64_t iir1 = ir1_start; iir1 < ir1_end; iir1 += blck_1) {
      for (int64_t iir0 = ir0_start; iir0 < ir0_end; iir0 += blck_0) {
 for (int64_t ir1 = iir1; ir1 < iir1 + blck_1 && ir1 < ir1_end; ir1 += num_rows_per_vec_dot) {
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
   for (int64_t ir0 = iir0; ir0 < iir0 + blck_0 && ir0 < ir0_end; ir0 += num_rows_per_vec_dot) {
     vec_dot(ne00, &tmp[ir0 - iir0], (num_rows_per_vec_dot > 1 ? 16 : 0), src0_row + ir0 * nb01, (num_rows_per_vec_dot > 1 ? nb01 : 0), src1_col, (num_rows_per_vec_dot > 1 ? src1_col_stride : 0), num_rows_per_vec_dot);
   }
   monitor_time_start(THREAD, ARM_MEMCPY);
   for (int cn = 0; cn < num_rows_per_vec_dot; ++cn)
     memcpy(&dst_col[iir0 + cn * nb1 / nb0], tmp + (cn * 16), (((iir0 + blck_0) < (ir0_end) ? (iir0 + blck_0) : (ir0_end)) - iir0) * sizeof(float));
   monitor_time_end(THREAD, ARM_MEMCPY);
 }
      }
    }
    monitor_time_end(THREAD, IMAX_COMPUTE_FORWARD_MUL_MAT_ONE_CHUNK_F32_ARM);
  }
}
void imax_compute_forward_mul_mat_one_chunk_f16(struct th_inference_args *args)
{
  int THREAD = args->thid;
  int LANE = args->thid;
  struct ggml_tensor * dst = args->dst;
  const int64_t num_rows_per_vec_dot = args->num_rows_per_vec_dot;
  const int64_t ir0_start = args->ir0_start;
  const int64_t ir0_end = args->ir0_end;
  const int64_t ir1_start = args->ir1_start;
  const int64_t ir1_end = args->ir1_end;
  const struct ggml_tensor * src0 = args->src0;
  const struct ggml_tensor * src1 = args->src1;
  const enum ggml_type type = args->type;
  const _Bool src1_cont = args->src1_cont;
  ggml_vec_dot_t const vec_dot = args->vec_dot;
  enum ggml_type const vec_dot_type = args->vec_dot_type;
  const void * wdata = args->wdata;
  const size_t row_size = args->row_size;
  const int64_t r2 = args->r2;
  const int64_t r3 = args->r3;
  const int64_t blck_0 = args->blck_0;
  const int64_t blck_1 = args->blck_1;
  const size_t src1_col_stride = args->src1_col_stride;
  int i;
  float tmp[32];
  const int64_t ne00 = (src0) ? (src0)->ne[0] : 0; (void)(ne00); const int64_t ne01 = (src0) ? (src0)->ne[1] : 0; (void)(ne01); const int64_t ne02 = (src0) ? (src0)->ne[2] : 0; (void)(ne02); const int64_t ne03 = (src0) ? (src0)->ne[3] : 0; (void)(ne03); const size_t nb00 = (src0) ? (src0)->nb[0] : 0; (void)(nb00); const size_t nb01 = (src0) ? (src0)->nb[1] : 0; (void)(nb01); const size_t nb02 = (src0) ? (src0)->nb[2] : 0; (void)(nb02); const size_t nb03 = (src0) ? (src0)->nb[3] : 0; (void)(nb03); const int64_t ne10 = (src1) ? (src1)->ne[0] : 0; (void)(ne10); const int64_t ne11 = (src1) ? (src1)->ne[1] : 0; (void)(ne11); const int64_t ne12 = (src1) ? (src1)->ne[2] : 0; (void)(ne12); const int64_t ne13 = (src1) ? (src1)->ne[3] : 0; (void)(ne13); const size_t nb10 = (src1) ? (src1)->nb[0] : 0; (void)(nb10); const size_t nb11 = (src1) ? (src1)->nb[1] : 0; (void)(nb11); const size_t nb12 = (src1) ? (src1)->nb[2] : 0; (void)(nb12); const size_t nb13 = (src1) ? (src1)->nb[3] : 0; (void)(nb13); const int64_t ne0 = (dst) ? (dst)->ne[0] : 0; (void)(ne0); const int64_t ne1 = (dst) ? (dst)->ne[1] : 0; (void)(ne1); const int64_t ne2 = (dst) ? (dst)->ne[2] : 0; (void)(ne2); const int64_t ne3 = (dst) ? (dst)->ne[3] : 0; (void)(ne3); const size_t nb0 = (dst) ? (dst)->nb[0] : 0; (void)(nb0); const size_t nb1 = (dst) ? (dst)->nb[1] : 0; (void)(nb1); const size_t nb2 = (dst) ? (dst)->nb[2] : 0; (void)(nb2); const size_t nb3 = (dst) ? (dst)->nb[3] : 0; (void)(nb3);
  static int ne00_count[1000000] = {0};
  int n = ne00;
  const int nb = n / 1;
    ne00_count[ne00]++;
  Ull IIR1_LOOPS = (ir1_end-ir1_start)/blck_1;
  Ull IIR0_LOOPS = (ir0_end-ir0_start)/blck_0;
  Ull IR1_LOOPS = ((ir1_start+blck_1) < (ir1_end) ? (ir1_start+blck_1) : (ir1_end))-ir1_start;
  if (ir1_start+blck_1<ir1_end){
    IR1_LOOPS = ir1_end-ir1_start;
    }
  Ull SRC0_ROW_LEN = ne00 * blck_0 * IIR0_LOOPS;
  Ull SRC1_COL_LEN = ne00;
  Ull SRC1_COL_LEN_TOTAL = SRC1_COL_LEN*IR1_LOOPS;
  Ull DST_COL_LEN = blck_0*IIR0_LOOPS;
  Ull DST_COL_LEN_TOTAL = DST_COL_LEN*IR1_LOOPS;
counter_imax_operations++;
int imax_run_count = 10000;
const int64_t i13_start = ir1_start / (ne12 * ne1);
const int64_t i13_end = (ir1_end - 1) / (ne12 * ne1);
const int64_t i12_start = (ir1_start - i13_start * ne12 * ne1) / ne1;
const int64_t i12_end = ((ir1_end - 1) - i13_end * ne12 * ne1) / ne1;
const _Bool cross_boundary = ( i13_start != i13_end);
if (ne00 % 32 != 0) {
    printf("[IMAX_DEBUG] Warning: ne00 (%lld) is not a multiple of 32\n", (long long)ne00);
}
 Ull TOTAL_SIZE = SRC0_ROW_LEN*sizeof(ggml_fp16_t) + SRC1_COL_LEN_TOTAL*sizeof(ggml_fp16_t) + DST_COL_LEN_TOTAL*sizeof(float);
if(1){
    monitor_time_start(THREAD, IMAX_COMPUTE_FORWARD_MUL_MAT_ONE_CHUNK_F16_ARM);
    for (int64_t iir1 = ir1_start; iir1 < ir1_end; iir1 += blck_1) {
      for (int64_t iir0 = ir0_start; iir0 < ir0_end; iir0 += blck_0) {
 for (int64_t ir1 = iir1; ir1 < iir1 + blck_1 && ir1 < ir1_end; ir1 += num_rows_per_vec_dot) {
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
    for (int64_t ir0 = iir0; ir0 < iir0 + blck_0 && ir0 < ir0_end; ir0 += num_rows_per_vec_dot) {
      vec_dot(ne00, &tmp[ir0 - iir0], (num_rows_per_vec_dot > 1 ? 16 : 0), src0_row + ir0 * nb01, (num_rows_per_vec_dot > 1 ? nb01 : 0), src1_col, (num_rows_per_vec_dot > 1 ? src1_col_stride : 0), num_rows_per_vec_dot);
    }
   monitor_time_start(THREAD, ARM_MEMCPY);
   for (int cn = 0; cn < num_rows_per_vec_dot; ++cn)
     memcpy(&dst_col[iir0 + cn * nb1 / nb0], tmp + (cn * 16), (((iir0 + blck_0) < (ir0_end) ? (iir0 + blck_0) : (ir0_end)) - iir0) * sizeof(float));
    monitor_time_end(THREAD, ARM_MEMCPY);
 }
      }
    }
    monitor_time_end(THREAD, IMAX_COMPUTE_FORWARD_MUL_MAT_ONE_CHUNK_F16_ARM);
  }
else {
    int SIMD = 32;
    Ull CHIP, rofs, cofs, iofs, oofs, fp16_cofs;
    Ull LOOP1, LOOP0;
    Ull INIT1, INIT0;
    Ull AR[64][4];
    Ull BR[64][4][4];
    Ull r00, r01, r02, r03, r04, r05, r06, r07, r08, r09, r10, r11, r12, r13, r14, r15;
    Ull r16, r17, r18, r19, r20, r21, r22, r23, r24, r25, r26, r27, r28, r29, r30, r31;
    Ull cc0, cc1, cc2, cc3, ex0, ex1, out0, out1, out2, out10;
    Ull Force0, Force1, Force2;
    Ull MNB01_M4 = (0LL-ne00 * sizeof(ggml_fp16_t) )<<32|((0LL-sizeof(float) )&0xffffffffLL);
    Ull MBKF16_0000 = (0LL-(sizeof(ggml_fp16_t)*SIMD) )<<32|((0LL-sizeof(ggml_fp16_t))&0xffffffffLL);
    Ull NB01_4 = (0LL+ne00 * sizeof(ggml_fp16_t) )<<32|((0LL+sizeof(float) )&0xffffffffLL);
    Ull BKF16_0000 = (0LL+(sizeof(ggml_fp16_t)*SIMD) )<<32|((0LL+sizeof(ggml_fp16_t))&0xffffffffLL);
    const int64_t i13_top = (ir1_start / (ne12 * ne1));
    const int64_t i12_top = (ir1_start - i13_top * ne12 * ne1) / ne1;
    const int64_t i11_top = (ir1_start - i13_top * ne12 * ne1 - i12_top * ne1);
    const int64_t i03_top = i13_top / r3;
    const int64_t i02_top = i12_top / r2;
    Ull SRC0_ROW_TOP = (Ull)((const char*)src0->data + (0 + i02_top * nb02 + i03_top * nb03) + ir0_start * nb01);
    Ull SRC0_ROW_LENdIMAP = SRC0_ROW_LEN/1;
    Ull SRC1_COL_TOP = (const char*)wdata + (src1_cont || src1->type != vec_dot_type ? (i11_top + i12_top * ne11 + i13_top * ne12 * ne11) * row_size
                                                                                            : (i11_top * nb11 + i12_top * nb12 + i13_top * nb13));
    Ull DST_COL_TOP = (float*)((char*)dst->data + (i11_top * nb1 + i12_top * nb2 + i13_top * nb3)) + ir0_start;
    Ull DST_COL_LENdIMAP = DST_COL_LEN/1;
    Ull DST_COL_LEN_TOTdIMAP = DST_COL_LEN_TOTAL/1;
    Ull i_m0C_TOP_IMAP[1][8]; for (i=0; i<1; i++) i_m0C_TOP_IMAP[i][LANE] = (Ull)i_m0C[LANE] + i*sizeof(float)*DST_COL_LEN_TOTdIMAP;
    int ctmp;
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
    const int64_t dst_total_elements = (ir1_end - ir1_start) * (ir0_end - ir0_start);
    memset(i_m0C[LANE], 0, dst_total_elements * sizeof(float));
    monitor_time_end(THREAD, IMAX_BZERO);
    Force2 = 1;
    float sumf1,sumf2,sumf3;
    int n , m, k,j,r ;
 monitor_time_start(THREAD, IMAX_TERM_1);
  for (int64_t iir1 = ir1_start; iir1 < ir1_end; iir1 += blck_1) {
      for (int64_t ir1 = iir1; ir1 < iir1 + blck_1 && ir1 < ir1_end; ir1 += num_rows_per_vec_dot) {
          const int64_t i13 = (ir1 / (ne12 * ne1));
   const int64_t i12 = (ir1 - i13 * ne12 * ne1) / ne1;
   const int64_t i11 = (ir1 - i13 * ne12 * ne1 - i12 * ne1);
        const int64_t i03 = i13 / r3;
        const int64_t i02 = i12 / r2;
        const char* gm_a_base = (const char*)src0->data + (0 + i02 * nb02 + i03 * nb03);
           const int64_t blck_00 = blck_0*IIR0_LOOPS;
          const int64_t blck_00dIMAP = blck_00/1;
    const size_t src0_row_bytes = ne00 * sizeof(ggml_fp16_t);
    char* lm_a_ptr = (char*)i_m0A[LANE] + ir0_start * src0_row_bytes;
     Force0=1;
    monitor_time_start(THREAD, IMAX_CPYIN_A);
    for (int64_t ir0 = ir0_start; ir0 < ir0_end; ++ir0) {
        const char* gm_a_row = gm_a_base + ir0 * nb01;
        memcpy(lm_a_ptr, gm_a_row, src0_row_bytes);
        lm_a_ptr += src0_row_bytes;
    }
    monitor_time_end(THREAD, IMAX_CPYIN_A);
          ggml_fp16_t* src0_row = (ggml_fp16_t*)((char*)i_m0A[LANE] + ir0_start * src0_row_bytes);
          Ull src0_row_base_p0[16]; for (j=0; j<16; j++) src0_row_base_p0[j] = (Ull)src0_row+ 0+j*8;
          Ull src0_row_base_p8[16]; for (j=0; j<16; j++) src0_row_base_p8[j] = (Ull)src0_row+ 8+j*8;
          ggml_fp16_t* src1_col = (ggml_fp16_t*)i_m0B[LANE]+ (ir1 - ir1_start) * ne00;
          Ull src1_col_base_p0[16]; for (j=0; j<16; j++) src1_col_base_p0[j] = (Ull)src1_col+ 0+j*8;
         Ull src1_col_base_p8[16]; for (j=0; j<16; j++) src1_col_base_p8[j] = (Ull)src1_col+8+j*8;
          float* dst_col = (float*)i_m0C[LANE] + (ir1 - ir1_start) * (ir0_end - ir0_start);
/-EMAX5AB-/ mul_mat_one_chunk_fp16 0
/-EMAX5AS-/ for (CHIP = 0; CHIP < 1; CHIP++) {
/-EMAX5AS-/ for (INIT1 = 1, LOOP1 ="" blck_00dIMAP"", rofs ="" MNB01_M4""; LOOP1--; INIT1 = 0) {
/-EMAX5AS-/ for (INIT0 = 1, LOOP0 ="" ne00/SIMD"", cofs=""MBKF16_0000""; LOOP0--; INIT0 = 0) {
/-EMAX5AS-/ exe(0x17, &rofs, rofs, 0, INIT0?NB01_4:0, 0, 0LL, 0, 0x00, 0LL, 0x00, 0LL);
/-EMAX5AS-/ exe(0x17, &cofs, INIT0?cofs:cofs, 0, BKF16_0000, 0, 0LL, 0, 0x00, 0LL, 0x00, 0LL);
/-EMAX5AS-/ exe(0x17, &iofs, rofs, 0, cofs, 0, 0LL, 0, 0x01, 0xffffffff00000000LL, 0x00, 0LL);
/-EMAX5AS-/ exe(0x17, &oofs, rofs, 0, 0LL, 0, 0LL, 0, 0x01, 0x00000000ffffffffLL, 0x00, 0LL);
/-EMAX5AS-/
/-EMAX5AS-/
/-EMAX5AS-/
/-EMAX5AS-/
/-EMAX5AS-/
/-EMAX5AS-/
/-EMAX5AS-/ mop(0x01, 0, &BR[2][0][1], src0_row_base_p8[0], (Ull)iofs, 13, src0_row, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 3, &BR[2][0][0], src0_row_base_p0[0], (Ull)iofs, 13, src0_row, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); exe(0x00, &r10, BR[2][0][0], 0, 0LL, 0, 0LL, 0, 0x01, 0x0000ffff0000ffffLL, 0x01, 2LL); exe(0x00, &r11, BR[2][0][0], 0, 0LL, 0, 0LL, 0, 0x01, 0xffff0000ffff0000LL, 0x02,14LL); mop(0x01, 0, &BR[2 +1][0][1], src1_col_base_p8[0], (Ull)cofs, 13, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); mop(0x01, 3, &BR[2 +1][0][0], src1_col_base_p0[0], (Ull)cofs, 13, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); exe(0x00, &r12, BR[2 +1][0][0], 0, 0LL, 0, 0LL, 0, 0x01, 0x0000ffff0000ffffLL, 0x01, 2LL); exe(0x00, &r13, BR[2 +1][0][0], 0, 0LL, 0, 0LL, 0, 0x01, 0xffff0000ffff0000LL, 0x02,14LL); mop(0x02, 3, &BR[2 +3][0][1], (Ull)i_f16[LANE], (Ull)r10, 12, (Ull)i_f16[LANE], 65536, 0, 0, (Ull)((void *)0), 65536); mop(0x02, 3, &BR[2 +3][0][0], (Ull)i_f16[LANE], (Ull)r10, 13, (Ull)i_f16[LANE], 65536, 0, 0, (Ull)((void *)0), 65536); mop(0x02, 3, &BR[2 +3][1][1], (Ull)i_f16[LANE], (Ull)r11, 12, (Ull)i_f16[LANE], 65536, 0, 0, (Ull)((void *)0), 65536); mop(0x02, 3, &BR[2 +3][1][0], (Ull)i_f16[LANE], (Ull)r11, 13, (Ull)i_f16[LANE], 65536, 0, 0, (Ull)((void *)0), 65536); mop(0x02, 3, &BR[2 +3][2][1], (Ull)i_f16[LANE], (Ull)r12, 12, (Ull)i_f16[LANE], 65536, 0, 0, (Ull)((void *)0), 65536); mop(0x02, 3, &BR[2 +3][2][0], (Ull)i_f16[LANE], (Ull)r12, 13, (Ull)i_f16[LANE], 65536, 0, 0, (Ull)((void *)0), 65536); mop(0x02, 3, &BR[2 +3][3][1], (Ull)i_f16[LANE], (Ull)r13, 12, (Ull)i_f16[LANE], 65536, 0, 0, (Ull)((void *)0), 65536); mop(0x02, 3, &BR[2 +3][3][0], (Ull)i_f16[LANE], (Ull)r13, 13, (Ull)i_f16[LANE], 65536, 0, 0, (Ull)((void *)0), 65536); exe(0x10, &r20, 0LL, 0, BR[2 +3][0][1], 0, BR[2 +3][2][1], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &r21, 0LL, 0, BR[2 +3][0][0], 0, BR[2 +3][2][0], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &r22, 0LL, 0, BR[2 +3][1][1], 0, BR[2 +3][3][1], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &r23, 0LL, 0, BR[2 +3][1][0], 0, BR[2 +3][3][0], 0, 0x00, 0LL, 0x00, 0LL);
/-EMAX5AS-/ mop(0x01, 0, &BR[6][0][1], src0_row_base_p8[1], (Ull)iofs, 13, src0_row, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 3, &BR[6][0][0], src0_row_base_p0[1], (Ull)iofs, 13, src0_row, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); exe(0x00, &r10, BR[6][0][0], 0, 0LL, 0, 0LL, 0, 0x01, 0x0000ffff0000ffffLL, 0x01, 2LL); exe(0x00, &r11, BR[6][0][0], 0, 0LL, 0, 0LL, 0, 0x01, 0xffff0000ffff0000LL, 0x02,14LL); mop(0x01, 0, &BR[6 +1][0][1], src1_col_base_p8[1], (Ull)cofs, 13, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); mop(0x01, 3, &BR[6 +1][0][0], src1_col_base_p0[1], (Ull)cofs, 13, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); exe(0x00, &r12, BR[6 +1][0][0], 0, 0LL, 0, 0LL, 0, 0x01, 0x0000ffff0000ffffLL, 0x01, 2LL); exe(0x00, &r13, BR[6 +1][0][0], 0, 0LL, 0, 0LL, 0, 0x01, 0xffff0000ffff0000LL, 0x02,14LL); mop(0x02, 3, &BR[6 +3][0][1], (Ull)i_f16[LANE], (Ull)r10, 12, (Ull)i_f16[LANE], 65536, 0, 0, (Ull)((void *)0), 65536); mop(0x02, 3, &BR[6 +3][0][0], (Ull)i_f16[LANE], (Ull)r10, 13, (Ull)i_f16[LANE], 65536, 0, 0, (Ull)((void *)0), 65536); mop(0x02, 3, &BR[6 +3][1][1], (Ull)i_f16[LANE], (Ull)r11, 12, (Ull)i_f16[LANE], 65536, 0, 0, (Ull)((void *)0), 65536); mop(0x02, 3, &BR[6 +3][1][0], (Ull)i_f16[LANE], (Ull)r11, 13, (Ull)i_f16[LANE], 65536, 0, 0, (Ull)((void *)0), 65536); mop(0x02, 3, &BR[6 +3][2][1], (Ull)i_f16[LANE], (Ull)r12, 12, (Ull)i_f16[LANE], 65536, 0, 0, (Ull)((void *)0), 65536); mop(0x02, 3, &BR[6 +3][2][0], (Ull)i_f16[LANE], (Ull)r12, 13, (Ull)i_f16[LANE], 65536, 0, 0, (Ull)((void *)0), 65536); mop(0x02, 3, &BR[6 +3][3][1], (Ull)i_f16[LANE], (Ull)r13, 12, (Ull)i_f16[LANE], 65536, 0, 0, (Ull)((void *)0), 65536); mop(0x02, 3, &BR[6 +3][3][0], (Ull)i_f16[LANE], (Ull)r13, 13, (Ull)i_f16[LANE], 65536, 0, 0, (Ull)((void *)0), 65536); exe(0x10, &r24, r20, 0, BR[6 +3][0][1], 0, BR[6 +3][2][1], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &r25, r21, 0, BR[6 +3][0][0], 0, BR[6 +3][2][0], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &r26, r22, 0, BR[6 +3][1][1], 0, BR[6 +3][3][1], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &r27, r23, 0, BR[6 +3][1][0], 0, BR[6 +3][3][0], 0, 0x00, 0LL, 0x00, 0LL);
/-EMAX5AS-/ mop(0x01, 0, &BR[10][0][1], src0_row_base_p8[2], (Ull)iofs, 13, src0_row, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 3, &BR[10][0][0], src0_row_base_p0[2], (Ull)iofs, 13, src0_row, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); exe(0x00, &r10, BR[10][0][0], 0, 0LL, 0, 0LL, 0, 0x01, 0x0000ffff0000ffffLL, 0x01, 2LL); exe(0x00, &r11, BR[10][0][0], 0, 0LL, 0, 0LL, 0, 0x01, 0xffff0000ffff0000LL, 0x02,14LL); mop(0x01, 0, &BR[10 +1][0][1], src1_col_base_p8[2], (Ull)cofs, 13, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); mop(0x01, 3, &BR[10 +1][0][0], src1_col_base_p0[2], (Ull)cofs, 13, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); exe(0x00, &r12, BR[10 +1][0][0], 0, 0LL, 0, 0LL, 0, 0x01, 0x0000ffff0000ffffLL, 0x01, 2LL); exe(0x00, &r13, BR[10 +1][0][0], 0, 0LL, 0, 0LL, 0, 0x01, 0xffff0000ffff0000LL, 0x02,14LL); mop(0x02, 3, &BR[10 +3][0][1], (Ull)i_f16[LANE], (Ull)r10, 12, (Ull)i_f16[LANE], 65536, 0, 0, (Ull)((void *)0), 65536); mop(0x02, 3, &BR[10 +3][0][0], (Ull)i_f16[LANE], (Ull)r10, 13, (Ull)i_f16[LANE], 65536, 0, 0, (Ull)((void *)0), 65536); mop(0x02, 3, &BR[10 +3][1][1], (Ull)i_f16[LANE], (Ull)r11, 12, (Ull)i_f16[LANE], 65536, 0, 0, (Ull)((void *)0), 65536); mop(0x02, 3, &BR[10 +3][1][0], (Ull)i_f16[LANE], (Ull)r11, 13, (Ull)i_f16[LANE], 65536, 0, 0, (Ull)((void *)0), 65536); mop(0x02, 3, &BR[10 +3][2][1], (Ull)i_f16[LANE], (Ull)r12, 12, (Ull)i_f16[LANE], 65536, 0, 0, (Ull)((void *)0), 65536); mop(0x02, 3, &BR[10 +3][2][0], (Ull)i_f16[LANE], (Ull)r12, 13, (Ull)i_f16[LANE], 65536, 0, 0, (Ull)((void *)0), 65536); mop(0x02, 3, &BR[10 +3][3][1], (Ull)i_f16[LANE], (Ull)r13, 12, (Ull)i_f16[LANE], 65536, 0, 0, (Ull)((void *)0), 65536); mop(0x02, 3, &BR[10 +3][3][0], (Ull)i_f16[LANE], (Ull)r13, 13, (Ull)i_f16[LANE], 65536, 0, 0, (Ull)((void *)0), 65536); exe(0x10, &r20, r24, 0, BR[10 +3][0][1], 0, BR[10 +3][2][1], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &r21, r25, 0, BR[10 +3][0][0], 0, BR[10 +3][2][0], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &r22, r26, 0, BR[10 +3][1][1], 0, BR[10 +3][3][1], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &r23, r27, 0, BR[10 +3][1][0], 0, BR[10 +3][3][0], 0, 0x00, 0LL, 0x00, 0LL);
/-EMAX5AS-/ mop(0x01, 0, &BR[14][0][1], src0_row_base_p8[3], (Ull)iofs, 13, src0_row, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 3, &BR[14][0][0], src0_row_base_p0[3], (Ull)iofs, 13, src0_row, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); exe(0x00, &r10, BR[14][0][0], 0, 0LL, 0, 0LL, 0, 0x01, 0x0000ffff0000ffffLL, 0x01, 2LL); exe(0x00, &r11, BR[14][0][0], 0, 0LL, 0, 0LL, 0, 0x01, 0xffff0000ffff0000LL, 0x02,14LL); mop(0x01, 0, &BR[14 +1][0][1], src1_col_base_p8[3], (Ull)cofs, 13, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); mop(0x01, 3, &BR[14 +1][0][0], src1_col_base_p0[3], (Ull)cofs, 13, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); exe(0x00, &r12, BR[14 +1][0][0], 0, 0LL, 0, 0LL, 0, 0x01, 0x0000ffff0000ffffLL, 0x01, 2LL); exe(0x00, &r13, BR[14 +1][0][0], 0, 0LL, 0, 0LL, 0, 0x01, 0xffff0000ffff0000LL, 0x02,14LL); mop(0x02, 3, &BR[14 +3][0][1], (Ull)i_f16[LANE], (Ull)r10, 12, (Ull)i_f16[LANE], 65536, 0, 0, (Ull)((void *)0), 65536); mop(0x02, 3, &BR[14 +3][0][0], (Ull)i_f16[LANE], (Ull)r10, 13, (Ull)i_f16[LANE], 65536, 0, 0, (Ull)((void *)0), 65536); mop(0x02, 3, &BR[14 +3][1][1], (Ull)i_f16[LANE], (Ull)r11, 12, (Ull)i_f16[LANE], 65536, 0, 0, (Ull)((void *)0), 65536); mop(0x02, 3, &BR[14 +3][1][0], (Ull)i_f16[LANE], (Ull)r11, 13, (Ull)i_f16[LANE], 65536, 0, 0, (Ull)((void *)0), 65536); mop(0x02, 3, &BR[14 +3][2][1], (Ull)i_f16[LANE], (Ull)r12, 12, (Ull)i_f16[LANE], 65536, 0, 0, (Ull)((void *)0), 65536); mop(0x02, 3, &BR[14 +3][2][0], (Ull)i_f16[LANE], (Ull)r12, 13, (Ull)i_f16[LANE], 65536, 0, 0, (Ull)((void *)0), 65536); mop(0x02, 3, &BR[14 +3][3][1], (Ull)i_f16[LANE], (Ull)r13, 12, (Ull)i_f16[LANE], 65536, 0, 0, (Ull)((void *)0), 65536); mop(0x02, 3, &BR[14 +3][3][0], (Ull)i_f16[LANE], (Ull)r13, 13, (Ull)i_f16[LANE], 65536, 0, 0, (Ull)((void *)0), 65536); exe(0x10, &r24, r20, 0, BR[14 +3][0][1], 0, BR[14 +3][2][1], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &r25, r21, 0, BR[14 +3][0][0], 0, BR[14 +3][2][0], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &r26, r22, 0, BR[14 +3][1][1], 0, BR[14 +3][3][1], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &r27, r23, 0, BR[14 +3][1][0], 0, BR[14 +3][3][0], 0, 0x00, 0LL, 0x00, 0LL);
/-EMAX5AS-/ mop(0x01, 0, &BR[18][0][1], src0_row_base_p8[4], (Ull)iofs, 13, src0_row, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 3, &BR[18][0][0], src0_row_base_p0[4], (Ull)iofs, 13, src0_row, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); exe(0x00, &r10, BR[18][0][0], 0, 0LL, 0, 0LL, 0, 0x01, 0x0000ffff0000ffffLL, 0x01, 2LL); exe(0x00, &r11, BR[18][0][0], 0, 0LL, 0, 0LL, 0, 0x01, 0xffff0000ffff0000LL, 0x02,14LL); mop(0x01, 0, &BR[18 +1][0][1], src1_col_base_p8[4], (Ull)cofs, 13, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); mop(0x01, 3, &BR[18 +1][0][0], src1_col_base_p0[4], (Ull)cofs, 13, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); exe(0x00, &r12, BR[18 +1][0][0], 0, 0LL, 0, 0LL, 0, 0x01, 0x0000ffff0000ffffLL, 0x01, 2LL); exe(0x00, &r13, BR[18 +1][0][0], 0, 0LL, 0, 0LL, 0, 0x01, 0xffff0000ffff0000LL, 0x02,14LL); mop(0x02, 3, &BR[18 +3][0][1], (Ull)i_f16[LANE], (Ull)r10, 12, (Ull)i_f16[LANE], 65536, 0, 0, (Ull)((void *)0), 65536); mop(0x02, 3, &BR[18 +3][0][0], (Ull)i_f16[LANE], (Ull)r10, 13, (Ull)i_f16[LANE], 65536, 0, 0, (Ull)((void *)0), 65536); mop(0x02, 3, &BR[18 +3][1][1], (Ull)i_f16[LANE], (Ull)r11, 12, (Ull)i_f16[LANE], 65536, 0, 0, (Ull)((void *)0), 65536); mop(0x02, 3, &BR[18 +3][1][0], (Ull)i_f16[LANE], (Ull)r11, 13, (Ull)i_f16[LANE], 65536, 0, 0, (Ull)((void *)0), 65536); mop(0x02, 3, &BR[18 +3][2][1], (Ull)i_f16[LANE], (Ull)r12, 12, (Ull)i_f16[LANE], 65536, 0, 0, (Ull)((void *)0), 65536); mop(0x02, 3, &BR[18 +3][2][0], (Ull)i_f16[LANE], (Ull)r12, 13, (Ull)i_f16[LANE], 65536, 0, 0, (Ull)((void *)0), 65536); mop(0x02, 3, &BR[18 +3][3][1], (Ull)i_f16[LANE], (Ull)r13, 12, (Ull)i_f16[LANE], 65536, 0, 0, (Ull)((void *)0), 65536); mop(0x02, 3, &BR[18 +3][3][0], (Ull)i_f16[LANE], (Ull)r13, 13, (Ull)i_f16[LANE], 65536, 0, 0, (Ull)((void *)0), 65536); exe(0x10, &r20, r24, 0, BR[18 +3][0][1], 0, BR[18 +3][2][1], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &r21, r25, 0, BR[18 +3][0][0], 0, BR[18 +3][2][0], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &r22, r26, 0, BR[18 +3][1][1], 0, BR[18 +3][3][1], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &r23, r27, 0, BR[18 +3][1][0], 0, BR[18 +3][3][0], 0, 0x00, 0LL, 0x00, 0LL);
/-EMAX5AS-/ mop(0x01, 0, &BR[22][0][1], src0_row_base_p8[5], (Ull)iofs, 13, src0_row, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 3, &BR[22][0][0], src0_row_base_p0[5], (Ull)iofs, 13, src0_row, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); exe(0x00, &r10, BR[22][0][0], 0, 0LL, 0, 0LL, 0, 0x01, 0x0000ffff0000ffffLL, 0x01, 2LL); exe(0x00, &r11, BR[22][0][0], 0, 0LL, 0, 0LL, 0, 0x01, 0xffff0000ffff0000LL, 0x02,14LL); mop(0x01, 0, &BR[22 +1][0][1], src1_col_base_p8[5], (Ull)cofs, 13, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); mop(0x01, 3, &BR[22 +1][0][0], src1_col_base_p0[5], (Ull)cofs, 13, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); exe(0x00, &r12, BR[22 +1][0][0], 0, 0LL, 0, 0LL, 0, 0x01, 0x0000ffff0000ffffLL, 0x01, 2LL); exe(0x00, &r13, BR[22 +1][0][0], 0, 0LL, 0, 0LL, 0, 0x01, 0xffff0000ffff0000LL, 0x02,14LL); mop(0x02, 3, &BR[22 +3][0][1], (Ull)i_f16[LANE], (Ull)r10, 12, (Ull)i_f16[LANE], 65536, 0, 0, (Ull)((void *)0), 65536); mop(0x02, 3, &BR[22 +3][0][0], (Ull)i_f16[LANE], (Ull)r10, 13, (Ull)i_f16[LANE], 65536, 0, 0, (Ull)((void *)0), 65536); mop(0x02, 3, &BR[22 +3][1][1], (Ull)i_f16[LANE], (Ull)r11, 12, (Ull)i_f16[LANE], 65536, 0, 0, (Ull)((void *)0), 65536); mop(0x02, 3, &BR[22 +3][1][0], (Ull)i_f16[LANE], (Ull)r11, 13, (Ull)i_f16[LANE], 65536, 0, 0, (Ull)((void *)0), 65536); mop(0x02, 3, &BR[22 +3][2][1], (Ull)i_f16[LANE], (Ull)r12, 12, (Ull)i_f16[LANE], 65536, 0, 0, (Ull)((void *)0), 65536); mop(0x02, 3, &BR[22 +3][2][0], (Ull)i_f16[LANE], (Ull)r12, 13, (Ull)i_f16[LANE], 65536, 0, 0, (Ull)((void *)0), 65536); mop(0x02, 3, &BR[22 +3][3][1], (Ull)i_f16[LANE], (Ull)r13, 12, (Ull)i_f16[LANE], 65536, 0, 0, (Ull)((void *)0), 65536); mop(0x02, 3, &BR[22 +3][3][0], (Ull)i_f16[LANE], (Ull)r13, 13, (Ull)i_f16[LANE], 65536, 0, 0, (Ull)((void *)0), 65536); exe(0x10, &r24, r20, 0, BR[22 +3][0][1], 0, BR[22 +3][2][1], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &r25, r21, 0, BR[22 +3][0][0], 0, BR[22 +3][2][0], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &r26, r22, 0, BR[22 +3][1][1], 0, BR[22 +3][3][1], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &r27, r23, 0, BR[22 +3][1][0], 0, BR[22 +3][3][0], 0, 0x00, 0LL, 0x00, 0LL);
/-EMAX5AS-/ mop(0x01, 0, &BR[26][0][1], src0_row_base_p8[6], (Ull)iofs, 13, src0_row, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 3, &BR[26][0][0], src0_row_base_p0[6], (Ull)iofs, 13, src0_row, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); exe(0x00, &r10, BR[26][0][0], 0, 0LL, 0, 0LL, 0, 0x01, 0x0000ffff0000ffffLL, 0x01, 2LL); exe(0x00, &r11, BR[26][0][0], 0, 0LL, 0, 0LL, 0, 0x01, 0xffff0000ffff0000LL, 0x02,14LL); mop(0x01, 0, &BR[26 +1][0][1], src1_col_base_p8[6], (Ull)cofs, 13, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); mop(0x01, 3, &BR[26 +1][0][0], src1_col_base_p0[6], (Ull)cofs, 13, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); exe(0x00, &r12, BR[26 +1][0][0], 0, 0LL, 0, 0LL, 0, 0x01, 0x0000ffff0000ffffLL, 0x01, 2LL); exe(0x00, &r13, BR[26 +1][0][0], 0, 0LL, 0, 0LL, 0, 0x01, 0xffff0000ffff0000LL, 0x02,14LL); mop(0x02, 3, &BR[26 +3][0][1], (Ull)i_f16[LANE], (Ull)r10, 12, (Ull)i_f16[LANE], 65536, 0, 0, (Ull)((void *)0), 65536); mop(0x02, 3, &BR[26 +3][0][0], (Ull)i_f16[LANE], (Ull)r10, 13, (Ull)i_f16[LANE], 65536, 0, 0, (Ull)((void *)0), 65536); mop(0x02, 3, &BR[26 +3][1][1], (Ull)i_f16[LANE], (Ull)r11, 12, (Ull)i_f16[LANE], 65536, 0, 0, (Ull)((void *)0), 65536); mop(0x02, 3, &BR[26 +3][1][0], (Ull)i_f16[LANE], (Ull)r11, 13, (Ull)i_f16[LANE], 65536, 0, 0, (Ull)((void *)0), 65536); mop(0x02, 3, &BR[26 +3][2][1], (Ull)i_f16[LANE], (Ull)r12, 12, (Ull)i_f16[LANE], 65536, 0, 0, (Ull)((void *)0), 65536); mop(0x02, 3, &BR[26 +3][2][0], (Ull)i_f16[LANE], (Ull)r12, 13, (Ull)i_f16[LANE], 65536, 0, 0, (Ull)((void *)0), 65536); mop(0x02, 3, &BR[26 +3][3][1], (Ull)i_f16[LANE], (Ull)r13, 12, (Ull)i_f16[LANE], 65536, 0, 0, (Ull)((void *)0), 65536); mop(0x02, 3, &BR[26 +3][3][0], (Ull)i_f16[LANE], (Ull)r13, 13, (Ull)i_f16[LANE], 65536, 0, 0, (Ull)((void *)0), 65536); exe(0x10, &r20, r24, 0, BR[26 +3][0][1], 0, BR[26 +3][2][1], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &r21, r25, 0, BR[26 +3][0][0], 0, BR[26 +3][2][0], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &r22, r26, 0, BR[26 +3][1][1], 0, BR[26 +3][3][1], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &r23, r27, 0, BR[26 +3][1][0], 0, BR[26 +3][3][0], 0, 0x00, 0LL, 0x00, 0LL);
/-EMAX5AS-/ mop(0x01, 0, &BR[30][0][1], src0_row_base_p8[7], (Ull)iofs, 13, src0_row, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 3, &BR[30][0][0], src0_row_base_p0[7], (Ull)iofs, 13, src0_row, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); exe(0x00, &r10, BR[30][0][0], 0, 0LL, 0, 0LL, 0, 0x01, 0x0000ffff0000ffffLL, 0x01, 2LL); exe(0x00, &r11, BR[30][0][0], 0, 0LL, 0, 0LL, 0, 0x01, 0xffff0000ffff0000LL, 0x02,14LL); mop(0x01, 0, &BR[30 +1][0][1], src1_col_base_p8[7], (Ull)cofs, 13, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); mop(0x01, 3, &BR[30 +1][0][0], src1_col_base_p0[7], (Ull)cofs, 13, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); exe(0x00, &r12, BR[30 +1][0][0], 0, 0LL, 0, 0LL, 0, 0x01, 0x0000ffff0000ffffLL, 0x01, 2LL); exe(0x00, &r13, BR[30 +1][0][0], 0, 0LL, 0, 0LL, 0, 0x01, 0xffff0000ffff0000LL, 0x02,14LL); mop(0x02, 3, &BR[30 +3][0][1], (Ull)i_f16[LANE], (Ull)r10, 12, (Ull)i_f16[LANE], 65536, 0, 0, (Ull)((void *)0), 65536); mop(0x02, 3, &BR[30 +3][0][0], (Ull)i_f16[LANE], (Ull)r10, 13, (Ull)i_f16[LANE], 65536, 0, 0, (Ull)((void *)0), 65536); mop(0x02, 3, &BR[30 +3][1][1], (Ull)i_f16[LANE], (Ull)r11, 12, (Ull)i_f16[LANE], 65536, 0, 0, (Ull)((void *)0), 65536); mop(0x02, 3, &BR[30 +3][1][0], (Ull)i_f16[LANE], (Ull)r11, 13, (Ull)i_f16[LANE], 65536, 0, 0, (Ull)((void *)0), 65536); mop(0x02, 3, &BR[30 +3][2][1], (Ull)i_f16[LANE], (Ull)r12, 12, (Ull)i_f16[LANE], 65536, 0, 0, (Ull)((void *)0), 65536); mop(0x02, 3, &BR[30 +3][2][0], (Ull)i_f16[LANE], (Ull)r12, 13, (Ull)i_f16[LANE], 65536, 0, 0, (Ull)((void *)0), 65536); mop(0x02, 3, &BR[30 +3][3][1], (Ull)i_f16[LANE], (Ull)r13, 12, (Ull)i_f16[LANE], 65536, 0, 0, (Ull)((void *)0), 65536); mop(0x02, 3, &BR[30 +3][3][0], (Ull)i_f16[LANE], (Ull)r13, 13, (Ull)i_f16[LANE], 65536, 0, 0, (Ull)((void *)0), 65536); exe(0x10, &r24, r20, 0, BR[30 +3][0][1], 0, BR[30 +3][2][1], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &r25, r21, 0, BR[30 +3][0][0], 0, BR[30 +3][2][0], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &r26, r22, 0, BR[30 +3][1][1], 0, BR[30 +3][3][1], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &r27, r23, 0, BR[30 +3][1][0], 0, BR[30 +3][3][0], 0, 0x00, 0LL, 0x00, 0LL);
/-EMAX5AS-/
/-EMAX5AS-/
/-EMAX5AS-/
/-EMAX5AS-/
/-EMAX5AS-/
/-EMAX5AS-/
/-EMAX5AS-/
/-EMAX5AS-/
/-EMAX5AS-/
/-EMAX5AS-/
/-EMAX5AS-/
/-EMAX5AS-/ exe(0x13, &r25, r24, 0, r25, 0, 0LL, 0, 0x00, 0LL, 0x00, 0LL);
/-EMAX5AS-/ exe(0x13, &r27, r26, 0, r27, 0, 0LL, 0, 0x00, 0LL, 0x00, 0LL);
/-EMAX5AS-/ exe(0x13, &r31, r25, 0, r27, 0, 0LL, 0, 0x00, 0LL, 0x00, 0LL);
/-EMAX5AS-/
/-EMAX5AS-/
/-EMAX5AS-/
/-EMAX5AS-/
/-EMAX5AS-/
/-EMAX5AS-/
/-EMAX5AS-/
/-EMAX5AS-/
/-EMAX5AS-/
/-EMAX5AS-/
/-EMAX5AS-/
/-EMAX5AS-/
/-EMAX5AS-/
/-EMAX5AS-/
/-EMAX5AS-/
/-EMAX5AS-/
/-EMAX5AS-/ exe(0x00, &AR[40][0], 0LL, 0, 0LL, 0, 0LL, 0, 0x00, 0LL, 0x00, 0LL);
/-EMAX5AS-/
/-EMAX5AS-/ mop(0x02, 1, &r00, dst_col, oofs, 12, i_m0C_TOP_IMAP[0][LANE], dst_total_elements, 0, Force2, (Ull)((void *)0),dst_total_elements);
/-EMAX5AS-/ exe(0x13, &r00, INIT0 ? r00: r00, 0, r31, 0, 0LL, 0, 0x00, 0LL, 0x00, 0LL);
/-EMAX5AS-/ mop(0x12, 1, &r00, oofs, dst_col, 14, i_m0C_TOP_IMAP[0][LANE], dst_total_elements, 0, Force2, (Ull)((void *)0),dst_total_elements);
/-EMAX5AS-/
/-EMAX5AS-/ }
/-EMAX5AS-/ }
/-EMAX5AS-/ }
/-EMAX5AE-/
          if (Force0) Force0 = 0;
          if (Force1) Force1 = 0;
          if (Force2) Force2 = 0;
    }
  }
/-EMAX5AD-/
  monitor_time_end(THREAD, IMAX_TERM_1);
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
  int THREAD = args->thid;
  int LANE = args->thid;
  struct ggml_tensor * dst = args->dst;
  const int64_t num_rows_per_vec_dot = args->num_rows_per_vec_dot;
  const int64_t ir0_start = args->ir0_start;
  const int64_t ir0_end = args->ir0_end;
  const int64_t ir1_start = args->ir1_start;
  const int64_t ir1_end = args->ir1_end;
  const struct ggml_tensor * src0 = args->src0;
  const struct ggml_tensor * src1 = args->src1;
  const enum ggml_type type = args->type;
  const _Bool src1_cont = args->src1_cont;
  ggml_vec_dot_t const vec_dot = args->vec_dot;
  enum ggml_type const vec_dot_type = args->vec_dot_type;
  const void * wdata = args->wdata;
  const size_t row_size = args->row_size;
  const int64_t r2 = args->r2;
  const int64_t r3 = args->r3;
  const int64_t blck_0 = args->blck_0;
  const int64_t blck_1 = args->blck_1;
  const size_t src1_col_stride = args->src1_col_stride;
  int i;
  float tmp[32];
  const int64_t ne00 = (src0) ? (src0)->ne[0] : 0; (void)(ne00); const int64_t ne01 = (src0) ? (src0)->ne[1] : 0; (void)(ne01); const int64_t ne02 = (src0) ? (src0)->ne[2] : 0; (void)(ne02); const int64_t ne03 = (src0) ? (src0)->ne[3] : 0; (void)(ne03); const size_t nb00 = (src0) ? (src0)->nb[0] : 0; (void)(nb00); const size_t nb01 = (src0) ? (src0)->nb[1] : 0; (void)(nb01); const size_t nb02 = (src0) ? (src0)->nb[2] : 0; (void)(nb02); const size_t nb03 = (src0) ? (src0)->nb[3] : 0; (void)(nb03); const int64_t ne10 = (src1) ? (src1)->ne[0] : 0; (void)(ne10); const int64_t ne11 = (src1) ? (src1)->ne[1] : 0; (void)(ne11); const int64_t ne12 = (src1) ? (src1)->ne[2] : 0; (void)(ne12); const int64_t ne13 = (src1) ? (src1)->ne[3] : 0; (void)(ne13); const size_t nb10 = (src1) ? (src1)->nb[0] : 0; (void)(nb10); const size_t nb11 = (src1) ? (src1)->nb[1] : 0; (void)(nb11); const size_t nb12 = (src1) ? (src1)->nb[2] : 0; (void)(nb12); const size_t nb13 = (src1) ? (src1)->nb[3] : 0; (void)(nb13); const int64_t ne0 = (dst) ? (dst)->ne[0] : 0; (void)(ne0); const int64_t ne1 = (dst) ? (dst)->ne[1] : 0; (void)(ne1); const int64_t ne2 = (dst) ? (dst)->ne[2] : 0; (void)(ne2); const int64_t ne3 = (dst) ? (dst)->ne[3] : 0; (void)(ne3); const size_t nb0 = (dst) ? (dst)->nb[0] : 0; (void)(nb0); const size_t nb1 = (dst) ? (dst)->nb[1] : 0; (void)(nb1); const size_t nb2 = (dst) ? (dst)->nb[2] : 0; (void)(nb2); const size_t nb3 = (dst) ? (dst)->nb[3] : 0; (void)(nb3);
  int n = ne00;
  if (1) {
    monitor_time_start(THREAD, IMAX_COMPUTE_FORWARD_MUL_MAT_ONE_CHUNK_Q2K_ARM);
    for (int64_t iir1 = ir1_start; iir1 < ir1_end; iir1 += blck_1) {
      for (int64_t iir0 = ir0_start; iir0 < ir0_end; iir0 += blck_0) {
 for (int64_t ir1 = iir1; ir1 < iir1 + blck_1 && ir1 < ir1_end; ir1 += num_rows_per_vec_dot) {
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
   for (int64_t ir0 = iir0; ir0 < iir0 + blck_0 && ir0 < ir0_end; ir0 += num_rows_per_vec_dot) {
     vec_dot(ne00, &tmp[ir0 - iir0], (num_rows_per_vec_dot > 1 ? 16 : 0), src0_row + ir0 * nb01, (num_rows_per_vec_dot > 1 ? nb01 : 0), src1_col, (num_rows_per_vec_dot > 1 ? src1_col_stride : 0), num_rows_per_vec_dot);
   }
   monitor_time_start(THREAD, ARM_MEMCPY);
   for (int cn = 0; cn < num_rows_per_vec_dot; ++cn)
     memcpy(&dst_col[iir0 + cn * nb1 / nb0], tmp + (cn * 16), (((iir0 + blck_0) < (ir0_end) ? (iir0 + blck_0) : (ir0_end)) - iir0) * sizeof(float));
   monitor_time_end(THREAD, ARM_MEMCPY);
 }
      }
    }
    monitor_time_end(THREAD, IMAX_COMPUTE_FORWARD_MUL_MAT_ONE_CHUNK_Q2K_ARM);
  }
}
void imax_compute_forward_mul_mat_one_chunk_q3_k(struct th_inference_args *args)
{
  int THREAD = args->thid;
  int LANE = args->thid;
  struct ggml_tensor * dst = args->dst;
  const int64_t num_rows_per_vec_dot = args->num_rows_per_vec_dot;
  const int64_t ir0_start = args->ir0_start;
  const int64_t ir0_end = args->ir0_end;
  const int64_t ir1_start = args->ir1_start;
  const int64_t ir1_end = args->ir1_end;
  const struct ggml_tensor * src0 = args->src0;
  const struct ggml_tensor * src1 = args->src1;
  const enum ggml_type type = args->type;
  const _Bool src1_cont = args->src1_cont;
  ggml_vec_dot_t const vec_dot = args->vec_dot;
  enum ggml_type const vec_dot_type = args->vec_dot_type;
  const void * wdata = args->wdata;
  const size_t row_size = args->row_size;
  const int64_t r2 = args->r2;
  const int64_t r3 = args->r3;
  const int64_t blck_0 = args->blck_0;
  const int64_t blck_1 = args->blck_1;
  const size_t src1_col_stride = args->src1_col_stride;
  int i, j;
  float tmp[32];
  const int64_t ne00 = (src0) ? (src0)->ne[0] : 0; (void)(ne00); const int64_t ne01 = (src0) ? (src0)->ne[1] : 0; (void)(ne01); const int64_t ne02 = (src0) ? (src0)->ne[2] : 0; (void)(ne02); const int64_t ne03 = (src0) ? (src0)->ne[3] : 0; (void)(ne03); const size_t nb00 = (src0) ? (src0)->nb[0] : 0; (void)(nb00); const size_t nb01 = (src0) ? (src0)->nb[1] : 0; (void)(nb01); const size_t nb02 = (src0) ? (src0)->nb[2] : 0; (void)(nb02); const size_t nb03 = (src0) ? (src0)->nb[3] : 0; (void)(nb03); const int64_t ne10 = (src1) ? (src1)->ne[0] : 0; (void)(ne10); const int64_t ne11 = (src1) ? (src1)->ne[1] : 0; (void)(ne11); const int64_t ne12 = (src1) ? (src1)->ne[2] : 0; (void)(ne12); const int64_t ne13 = (src1) ? (src1)->ne[3] : 0; (void)(ne13); const size_t nb10 = (src1) ? (src1)->nb[0] : 0; (void)(nb10); const size_t nb11 = (src1) ? (src1)->nb[1] : 0; (void)(nb11); const size_t nb12 = (src1) ? (src1)->nb[2] : 0; (void)(nb12); const size_t nb13 = (src1) ? (src1)->nb[3] : 0; (void)(nb13); const int64_t ne0 = (dst) ? (dst)->ne[0] : 0; (void)(ne0); const int64_t ne1 = (dst) ? (dst)->ne[1] : 0; (void)(ne1); const int64_t ne2 = (dst) ? (dst)->ne[2] : 0; (void)(ne2); const int64_t ne3 = (dst) ? (dst)->ne[3] : 0; (void)(ne3); const size_t nb0 = (dst) ? (dst)->nb[0] : 0; (void)(nb0); const size_t nb1 = (dst) ? (dst)->nb[1] : 0; (void)(nb1); const size_t nb2 = (dst) ? (dst)->nb[2] : 0; (void)(nb2); const size_t nb3 = (dst) ? (dst)->nb[3] : 0; (void)(nb3);
  int n = ne00;
  const int nb = n / 256;
  Ull IIR1_LOOPS = (ir1_end-ir1_start)/blck_1;
  Ull IIR0_LOOPS = (ir0_end-ir0_start)/blck_0;
  Ull IR1_LOOPS = ((ir1_start+blck_1) < (ir1_end) ? (ir1_start+blck_1) : (ir1_end))-ir1_start;
  Ull SRC0_ROW_LEN = sizeof(block_q3_K)*nb*blck_0*IIR0_LOOPS/sizeof(int);
  Ull SRC1_COL_LEN = (sizeof(block_q8_K)*nb+3)/sizeof(int);
  Ull SRC1_COL_LEN_TOTAL = SRC1_COL_LEN*IR1_LOOPS;
  Ull DST_COL_LEN = blck_0*IIR0_LOOPS;
  Ull DST_COL_LEN_TOTAL = DST_COL_LEN*IR1_LOOPS;
  if (SRC0_ROW_LEN >512*1024/sizeof(int) || ((ir0_end - ir0_start) % blck_0) || num_rows_per_vec_dot != 1) {
      monitor_time_start(THREAD, IMAX_COMPUTE_FORWARD_MUL_MAT_ONE_CHUNK_Q3K_ARM);
    for (int64_t iir1 = ir1_start; iir1 < ir1_end; iir1 += blck_1) {
      for (int64_t iir0 = ir0_start; iir0 < ir0_end; iir0 += blck_0) {
 for (int64_t ir1 = iir1; ir1 < iir1 + blck_1 && ir1 < ir1_end; ir1 += num_rows_per_vec_dot) {
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
   for (int64_t ir0 = iir0; ir0 < iir0 + blck_0 && ir0 < ir0_end; ir0 += num_rows_per_vec_dot) {
     vec_dot(ne00, &tmp[ir0 - iir0], (num_rows_per_vec_dot > 1 ? 16 : 0), src0_row + ir0 * nb01, (num_rows_per_vec_dot > 1 ? nb01 : 0), src1_col, (num_rows_per_vec_dot > 1 ? src1_col_stride : 0), num_rows_per_vec_dot);
   }
   monitor_time_start(THREAD, ARM_MEMCPY);
   for (int cn = 0; cn < num_rows_per_vec_dot; ++cn)
     memcpy(&dst_col[iir0 + cn * nb1 / nb0], tmp + (cn * 16), (((iir0 + blck_0) < (ir0_end) ? (iir0 + blck_0) : (ir0_end)) - iir0) * sizeof(float));
   monitor_time_end(THREAD, ARM_MEMCPY);
 }
      }
    }
    monitor_time_end(THREAD, IMAX_COMPUTE_FORWARD_MUL_MAT_ONE_CHUNK_Q3K_ARM);
  }
  else {
    Ull CHIP, rofs, cofs, xofs, yofs, iofs, oofs;
    Ull LOOP1, LOOP0;
    Ull INIT1, INIT0;
    Ull AR[64][4];
    Ull BR[64][4][4];
    Ull r00, r01, r02, r03, r04, r05, r06, r07, r08, r09, r10, r11, r12, r13, r14, r15;
    Ull r16, r17, r18, r19, r20, r21, r22, r23, r24, r25, r26, r27, r28, r29, r30, r31;
    Ull cc0, cc1, cc2, cc3, ex0, ex1, out0, out1, out2, out10;
    Ull Force0, Force1, Force2;
    Ull MNB01_M4 = (0LL-nb01 )<<32|((0LL-sizeof(float)) &0xffffffffLL);
    Ull MBKQ3_MBKQ8 = (0LL-sizeof(block_q3_K))<<32|((0LL-sizeof(block_q8_K))&0xffffffffLL);
    Ull NB01_4 = (0LL+nb01 )<<32|((0LL+sizeof(float)) &0xffffffffLL);
    Ull BKQ3_BKQ8 = (0LL+sizeof(block_q3_K))<<32|((0LL+sizeof(block_q8_K))&0xffffffffLL);
    const int64_t i13_top = (ir1_start / (ne12 * ne1));
    const int64_t i12_top = (ir1_start - i13_top * ne12 * ne1) / ne1;
    const int64_t i11_top = (ir1_start - i13_top * ne12 * ne1 - i12_top * ne1);
    const int64_t i03_top = i13_top / r3;
    const int64_t i02_top = i12_top / r2;
    Ull SRC0_ROW_TOP = (const char*)src0->data + (0 + i02_top * nb02 + i03_top * nb03) + ir0_start*nb01;
    Ull SRC0_ROW_LENdIMAP = SRC0_ROW_LEN/1;
    Ull i_m0A_TOP = (const char*)i_m0A[LANE] + (0 + i02_top * nb02 + i03_top * nb03) + ir0_start*nb01;
    Ull SRC1_COL_TOP = (const char*)wdata + (src1_cont || src1->type != vec_dot_type ? (i11_top + i12_top * ne11 + i13_top * ne12 * ne11) * row_size
                                                                                            : (i11_top * nb11 + i12_top * nb12 + i13_top * nb13));
    Ull DST_COL_TOP = (float*)((char*)dst->data + (i11_top * nb1 + i12_top * nb2 + i13_top * nb3)) + ir0_start;
    Ull DST_COL_LENdIMAP = DST_COL_LEN/1;
    Ull DST_COL_LEN_TOTdIMAP = DST_COL_LEN_TOTAL/1;
    Ull i_m0C_TOP_IMAP[1][8]; for (i=0; i<1; i++) i_m0C_TOP_IMAP[i][LANE] = (Ull)i_m0C[LANE] + i*sizeof(float)*DST_COL_LEN_TOTdIMAP;
    int ctmp;
    if (src0_preloaded) {
      i_m0A_TOP = i_m0A[0] + (SRC0_ROW_TOP - SRC0_ROW_TOP_DIRECT);
      Force0=1;
    }
    else if (*(Ull*)i_m0A_TOP == *(Ull*)SRC0_ROW_TOP) {
      Force0=0;
    }
    else {
      monitor_time_start(THREAD, IMAX_CPYIN_A_Q3K);
      xmax_cpyin(3,i_m0A_TOP, &ctmp,SRC0_ROW_TOP,1,1,SRC0_ROW_LEN,1,1);
      Force0=1;
      monitor_time_end(THREAD, IMAX_CPYIN_A_Q3K);
      Force0=1;
    }
    if (*(Ull*)i_m0B[LANE] == *(Ull*)SRC1_COL_TOP) {
      Force1=0;
    }
    else {
      monitor_time_start(THREAD, IMAX_CPYIN_B_Q3K);
      xmax_cpyin(3,i_m0B[LANE],&ctmp,SRC1_COL_TOP,1,1,SRC1_COL_LEN_TOTAL,1,1);
      TOTAL_BUFFER_LOAD_SIZE += SRC1_COL_LEN_TOTAL*sizeof(int);
      Force1=1;
      monitor_time_end(THREAD, IMAX_CPYIN_B_Q3K);
    }
    monitor_time_start(THREAD, IMAX_BZERO_Q3K);
    xmax_bzero(i_m0C[LANE], DST_COL_LEN_TOTAL);
    TOTAL_BUFFER_DRAIN_SIZE += DST_COL_LEN_TOTAL*sizeof(int);
    Force2 = 1;
    monitor_time_end(THREAD, IMAX_BZERO_Q3K);
    for (int64_t iir1 = ir1_start; iir1 < ir1_end; iir1 += blck_1) {
      for (int64_t ir1 = iir1; ir1 < iir1 + blck_1 && ir1 < ir1_end; ir1 += num_rows_per_vec_dot) {
   const int64_t i13 = (ir1 / (ne12 * ne1));
   const int64_t i12 = (ir1 - i13 * ne12 * ne1) / ne1;
   const int64_t i11 = (ir1 - i13 * ne12 * ne1 - i12 * ne1);
          const int64_t i03 = i13 / r3;
          const int64_t i02 = i12 / r2;
   const int64_t i1 = i11;
   const int64_t i2 = i12;
   const int64_t i3 = i13;
   const int64_t blck_00 = blck_0*IIR0_LOOPS;
   const int64_t blck_00dIMAP = blck_00/1;
   const char * src0_row = (const char*)i_m0A_TOP;
   Ull src0_row_hmbase[5]; for (j=0; j<5; j++) src0_row_hmbase[j] = (Ull)src0_row+ 0+j*8;
   Ull src0_row_qsbase[2][5]; for (j=0; j<5; j++) src0_row_qsbase[0][j] = (Ull)src0_row+32+j*8;
                                        for (j=0; j<5; j++) src0_row_qsbase[1][j] = (Ull)src0_row+64+j*8;
   Ull src0_row_scbase[12]; for (j=0; j<12; j++) src0_row_scbase[j] = (Ull)src0_row+96+j;
   Ull src0_row_dbase_p0; src0_row_dbase_p0 = (Ull)src0_row+108;
   Ull src0_row_dbase_p8; src0_row_dbase_p8 = (Ull)src0_row+108+8;
   const char * src1_col = (const char*)i_m0B[LANE] + (ir1-ir1_start)*sizeof(int)*SRC1_COL_LEN;
   Ull src1_col_dbase_p0 = (Ull)src1_col;
   Ull src1_col_dbase_p8 = (Ull)src1_col+8;
   Ull src1_col_base[8][5]; for (i=0; i<8; i++) for (j=0; j<5; j++) src1_col_base[i][j] = (Ull)src1_col+4+i*32+j*8;
   float * dst_col = (float*)i_m0C[LANE] + (ir0_start-ir0_start) + (ir1-ir1_start)*DST_COL_LENdIMAP;
/-EMAX5AB-/ mul_mat_one_chunk_q3k 0
/-EMAX5AS-/ for (CHIP=0; CHIP<1; CHIP++) {
/-EMAX5AS-/ for (INIT1=1,LOOP1=""blck_00dIMAP"",rofs=""MNB01_M4""; LOOP1--; INIT1=0) {
/-EMAX5AS-/ for (INIT0=1,LOOP0=""nb"",cofs=""MBKQ3_MBKQ8""; LOOP0--; INIT0=0) {
/-EMAX5AS-/ exe(0x17, &rofs, rofs, 0, INIT0?NB01_4:0, 0, 0LL, 0, 0x00, 0LL, 0x00, 0LL);
/-EMAX5AS-/ exe(0x17, &cofs, INIT0?cofs:cofs, 0, BKQ3_BKQ8, 0, 0LL, 0, 0x00, 0LL, 0x00, 0LL);
/-EMAX5AS-/ exe(0x17, &xofs, rofs, 0, cofs, 0, 0LL, 0, 0x01, 0xffffffff00000000LL, 0x00, 0LL);
/-EMAX5AS-/ exe(0x17, &yofs, 0LL, 0, cofs, 0, 0LL, 0, 0x01, 0x00000000ffffffffLL, 0x00, 0LL);
/-EMAX5AS-/ exe(0x17, &oofs, rofs, 0, 0LL, 0, 0LL, 0, 0x01, 0x00000000ffffffffLL, 0x00, 0LL);
/-EMAX5AS-/ exe(0x00, &iofs, xofs, 0, 0LL, 0, 0LL, 0, 0x02, yofs, 0x00, 0LL);
/-EMAX5AS-/ exe(0x17, &r24, 0LL, 0, 0LL, 0, 0LL, 0, 0x00, 0LL, 0x00, 0LL);
/-EMAX5AS-/ exe(0x17, &r25, 0LL, 0, 0LL, 0, 0LL, 0, 0x00, 0LL, 0x00, 0LL);
/-EMAX5AS-/ exe(0x17, &r26, 0LL, 0, 0LL, 0, 0LL, 0, 0x00, 0LL, 0x00, 0LL);
/-EMAX5AS-/ exe(0x17, &r27, 0LL, 0, 0LL, 0, 0LL, 0, 0x00, 0LL, 0x00, 0LL);
/-EMAX5AS-/
/-EMAX5AS-/
/-EMAX5AS-/
/-EMAX5AS-/
/-EMAX5AS-/
/-EMAX5AS-/
/-EMAX5AS-/
/-EMAX5AS-/
/-EMAX5AS-/
/-EMAX5AS-/
/-EMAX5AS-/
/-EMAX5AS-/
/-EMAX5AS-/
/-EMAX5AS-/
/-EMAX5AS-/
/-EMAX5AS-/
/-EMAX5AS-/
/-EMAX5AS-/
/-EMAX5AS-/
/-EMAX5AS-/
/-EMAX5AS-/
/-EMAX5AS-/
/-EMAX5AS-/
/-EMAX5AS-/
/-EMAX5AS-/
/-EMAX5AS-/ mop(0x04, 3, &BR[3][0][1], src0_row_scbase[0], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x04, 3, &BR[3][1][1], src0_row_scbase[8], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x04, 3, &BR[3][2][1], src0_row_scbase[1], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x04, 3, &BR[3][3][1], src0_row_scbase[9], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); exe(0x25, &r00, 0LL, 1, BR[3][1][1], 1, BR[3][0][1], 1, 0x00, 0LL, 0x02, 8LL); exe(0x25, &r01, 0LL, 1, BR[3][3][1], 1, BR[3][2][1], 1, 0x00, 0LL, 0x02, 8LL); mop(0x01, 0, &BR[3 +1][0][1], src0_row_qsbase[0][1], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 3, &BR[3 +1][0][0], src0_row_qsbase[0][0], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 0, &BR[3 +1][1][1], src0_row_qsbase[0][2], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 3, &BR[3 +1][1][0], src0_row_qsbase[0][1], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 0, &BR[3 +1][2][1], src0_row_qsbase[0][3], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 3, &BR[3 +1][2][0], src0_row_qsbase[0][2], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 0, &BR[3 +1][3][1], src0_row_qsbase[0][4], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 3, &BR[3 +1][3][0], src0_row_qsbase[0][3], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 0, &BR[3 +2][0][1], src0_row_hmbase[1], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 3, &BR[3 +2][0][0], src0_row_hmbase[0], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 0, &BR[3 +2][1][1], src0_row_hmbase[2], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 3, &BR[3 +2][1][0], src0_row_hmbase[1], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 0, &BR[3 +2][2][1], src0_row_hmbase[3], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 3, &BR[3 +2][2][0], src0_row_hmbase[2], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 0, &BR[3 +2][3][1], src0_row_hmbase[4], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 3, &BR[3 +2][3][0], src0_row_hmbase[3], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); exe(0x06, &r04, r00, 0, BR[3 +2][0][0], 0, BR[3 +1][0][0], 0, 0x00, 0LL, 0x00, 8LL); exe(0x06, &r05, r00, 0, BR[3 +2][1][0], 0, BR[3 +1][1][0], 0, 0x00, 0LL, 0x00, 8LL); exe(0x06, &r06, r01, 0, BR[3 +2][2][0], 0, BR[3 +1][2][0], 0, 0x00, 0LL, 0x00, 8LL); exe(0x06, &r07, r01, 0, BR[3 +2][3][0], 0, BR[3 +1][3][0], 0, 0x00, 0LL, 0x00, 8LL); mop(0x01, 0, &BR[3 +3][0][1], src1_col_base[0][1], (Ull)iofs, 12, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); mop(0x01, 3, &BR[3 +3][0][0], src1_col_base[0][0], (Ull)iofs, 12, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); mop(0x01, 0, &BR[3 +3][1][1], src1_col_base[0][2], (Ull)iofs, 12, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); mop(0x01, 3, &BR[3 +3][1][0], src1_col_base[0][1], (Ull)iofs, 12, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); mop(0x01, 0, &BR[3 +3][2][1], src1_col_base[0][3], (Ull)iofs, 12, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); mop(0x01, 3, &BR[3 +3][2][0], src1_col_base[0][2], (Ull)iofs, 12, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); mop(0x01, 0, &BR[3 +3][3][1], src1_col_base[0][4], (Ull)iofs, 12, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); mop(0x01, 3, &BR[3 +3][3][0], src1_col_base[0][3], (Ull)iofs, 12, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); exe(0x07, &r20, r04, 3, BR[3 +3][0][0], 3, 0LL, 0, 0x06, r24, 0x00, 0LL); exe(0x07, &r21, r05, 3, BR[3 +3][1][0], 3, 0LL, 0, 0x06, r25, 0x00, 0LL); exe(0x07, &r22, r06, 3, BR[3 +3][2][0], 3, 0LL, 0, 0x06, r26, 0x00, 0LL); exe(0x07, &r23, r07, 3, BR[3 +3][3][0], 3, 0LL, 0, 0x06, r27, 0x00, 0LL); exe(0x07, &r24, r04, 4, BR[3 +3][0][0], 4, 0LL, 0, 0x06, r20, 0x00, 0LL); exe(0x07, &r25, r05, 4, BR[3 +3][1][0], 4, 0LL, 0, 0x06, r21, 0x00, 0LL); exe(0x07, &r26, r06, 4, BR[3 +3][2][0], 4, 0LL, 0, 0x06, r22, 0x00, 0LL); exe(0x07, &r27, r07, 4, BR[3 +3][3][0], 4, 0LL, 0, 0x06, r23, 0x00, 0LL);
/-EMAX5AS-/
/-EMAX5AS-/
/-EMAX5AS-/ mop(0x04, 3, &BR[8][0][1], src0_row_scbase[2], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x04, 3, &BR[8][1][1], src0_row_scbase[10], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x04, 3, &BR[8][2][1], src0_row_scbase[3], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x04, 3, &BR[8][3][1], src0_row_scbase[11], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); exe(0x25, &r00, 0LL, 1, BR[8][1][1], 1, BR[8][0][1], 1, 0x00, 0LL, 0x02, 8LL); exe(0x25, &r01, 0LL, 1, BR[8][3][1], 1, BR[8][2][1], 1, 0x00, 0LL, 0x02, 8LL); mop(0x01, 0, &BR[8 +1][0][1], src0_row_qsbase[0][1], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 3, &BR[8 +1][0][0], src0_row_qsbase[0][0], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 0, &BR[8 +1][1][1], src0_row_qsbase[0][2], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 3, &BR[8 +1][1][0], src0_row_qsbase[0][1], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 0, &BR[8 +1][2][1], src0_row_qsbase[0][3], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 3, &BR[8 +1][2][0], src0_row_qsbase[0][2], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 0, &BR[8 +1][3][1], src0_row_qsbase[0][4], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 3, &BR[8 +1][3][0], src0_row_qsbase[0][3], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 0, &BR[8 +2][0][1], src0_row_hmbase[1], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 3, &BR[8 +2][0][0], src0_row_hmbase[0], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 0, &BR[8 +2][1][1], src0_row_hmbase[2], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 3, &BR[8 +2][1][0], src0_row_hmbase[1], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 0, &BR[8 +2][2][1], src0_row_hmbase[3], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 3, &BR[8 +2][2][0], src0_row_hmbase[2], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 0, &BR[8 +2][3][1], src0_row_hmbase[4], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 3, &BR[8 +2][3][0], src0_row_hmbase[3], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); exe(0x06, &r04, r00, 1, BR[8 +2][0][0], 0, BR[8 +1][0][0], 0, 0x00, 0LL, 0x00, 8LL); exe(0x06, &r05, r00, 1, BR[8 +2][1][0], 0, BR[8 +1][1][0], 0, 0x00, 0LL, 0x00, 8LL); exe(0x06, &r06, r01, 1, BR[8 +2][2][0], 0, BR[8 +1][2][0], 0, 0x00, 0LL, 0x00, 8LL); exe(0x06, &r07, r01, 1, BR[8 +2][3][0], 0, BR[8 +1][3][0], 0, 0x00, 0LL, 0x00, 8LL); mop(0x01, 0, &BR[8 +3][0][1], src1_col_base[1][1], (Ull)iofs, 12, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); mop(0x01, 3, &BR[8 +3][0][0], src1_col_base[1][0], (Ull)iofs, 12, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); mop(0x01, 0, &BR[8 +3][1][1], src1_col_base[1][2], (Ull)iofs, 12, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); mop(0x01, 3, &BR[8 +3][1][0], src1_col_base[1][1], (Ull)iofs, 12, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); mop(0x01, 0, &BR[8 +3][2][1], src1_col_base[1][3], (Ull)iofs, 12, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); mop(0x01, 3, &BR[8 +3][2][0], src1_col_base[1][2], (Ull)iofs, 12, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); mop(0x01, 0, &BR[8 +3][3][1], src1_col_base[1][4], (Ull)iofs, 12, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); mop(0x01, 3, &BR[8 +3][3][0], src1_col_base[1][3], (Ull)iofs, 12, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); exe(0x07, &r20, r04, 3, BR[8 +3][0][0], 3, 0LL, 0, 0x06, r24, 0x00, 0LL); exe(0x07, &r21, r05, 3, BR[8 +3][1][0], 3, 0LL, 0, 0x06, r25, 0x00, 0LL); exe(0x07, &r22, r06, 3, BR[8 +3][2][0], 3, 0LL, 0, 0x06, r26, 0x00, 0LL); exe(0x07, &r23, r07, 3, BR[8 +3][3][0], 3, 0LL, 0, 0x06, r27, 0x00, 0LL); exe(0x07, &r24, r04, 4, BR[8 +3][0][0], 4, 0LL, 0, 0x06, r20, 0x00, 0LL); exe(0x07, &r25, r05, 4, BR[8 +3][1][0], 4, 0LL, 0, 0x06, r21, 0x00, 0LL); exe(0x07, &r26, r06, 4, BR[8 +3][2][0], 4, 0LL, 0, 0x06, r22, 0x00, 0LL); exe(0x07, &r27, r07, 4, BR[8 +3][3][0], 4, 0LL, 0, 0x06, r23, 0x00, 0LL);
/-EMAX5AS-/
/-EMAX5AS-/
/-EMAX5AS-/ mop(0x04, 3, &BR[13][0][1], src0_row_scbase[4], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x04, 3, &BR[13][1][1], src0_row_scbase[8], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x04, 3, &BR[13][2][1], src0_row_scbase[5], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x04, 3, &BR[13][3][1], src0_row_scbase[9], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); exe(0x25, &r00, 0LL, 1, BR[13][1][1], 1, BR[13][0][1], 1, 0x00, 0LL, 0x02, 8LL); exe(0x25, &r01, 0LL, 1, BR[13][3][1], 1, BR[13][2][1], 1, 0x00, 0LL, 0x02, 8LL); mop(0x01, 0, &BR[13 +1][0][1], src0_row_qsbase[0][1], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 3, &BR[13 +1][0][0], src0_row_qsbase[0][0], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 0, &BR[13 +1][1][1], src0_row_qsbase[0][2], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 3, &BR[13 +1][1][0], src0_row_qsbase[0][1], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 0, &BR[13 +1][2][1], src0_row_qsbase[0][3], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 3, &BR[13 +1][2][0], src0_row_qsbase[0][2], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 0, &BR[13 +1][3][1], src0_row_qsbase[0][4], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 3, &BR[13 +1][3][0], src0_row_qsbase[0][3], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 0, &BR[13 +2][0][1], src0_row_hmbase[1], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 3, &BR[13 +2][0][0], src0_row_hmbase[0], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 0, &BR[13 +2][1][1], src0_row_hmbase[2], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 3, &BR[13 +2][1][0], src0_row_hmbase[1], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 0, &BR[13 +2][2][1], src0_row_hmbase[3], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 3, &BR[13 +2][2][0], src0_row_hmbase[2], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 0, &BR[13 +2][3][1], src0_row_hmbase[4], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 3, &BR[13 +2][3][0], src0_row_hmbase[3], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); exe(0x06, &r04, r00, 2, BR[13 +2][0][0], 0, BR[13 +1][0][0], 0, 0x00, 0LL, 0x00, 8LL); exe(0x06, &r05, r00, 2, BR[13 +2][1][0], 0, BR[13 +1][1][0], 0, 0x00, 0LL, 0x00, 8LL); exe(0x06, &r06, r01, 2, BR[13 +2][2][0], 0, BR[13 +1][2][0], 0, 0x00, 0LL, 0x00, 8LL); exe(0x06, &r07, r01, 2, BR[13 +2][3][0], 0, BR[13 +1][3][0], 0, 0x00, 0LL, 0x00, 8LL); mop(0x01, 0, &BR[13 +3][0][1], src1_col_base[2][1], (Ull)iofs, 12, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); mop(0x01, 3, &BR[13 +3][0][0], src1_col_base[2][0], (Ull)iofs, 12, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); mop(0x01, 0, &BR[13 +3][1][1], src1_col_base[2][2], (Ull)iofs, 12, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); mop(0x01, 3, &BR[13 +3][1][0], src1_col_base[2][1], (Ull)iofs, 12, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); mop(0x01, 0, &BR[13 +3][2][1], src1_col_base[2][3], (Ull)iofs, 12, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); mop(0x01, 3, &BR[13 +3][2][0], src1_col_base[2][2], (Ull)iofs, 12, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); mop(0x01, 0, &BR[13 +3][3][1], src1_col_base[2][4], (Ull)iofs, 12, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); mop(0x01, 3, &BR[13 +3][3][0], src1_col_base[2][3], (Ull)iofs, 12, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); exe(0x07, &r20, r04, 3, BR[13 +3][0][0], 3, 0LL, 0, 0x06, r24, 0x00, 0LL); exe(0x07, &r21, r05, 3, BR[13 +3][1][0], 3, 0LL, 0, 0x06, r25, 0x00, 0LL); exe(0x07, &r22, r06, 3, BR[13 +3][2][0], 3, 0LL, 0, 0x06, r26, 0x00, 0LL); exe(0x07, &r23, r07, 3, BR[13 +3][3][0], 3, 0LL, 0, 0x06, r27, 0x00, 0LL); exe(0x07, &r24, r04, 4, BR[13 +3][0][0], 4, 0LL, 0, 0x06, r20, 0x00, 0LL); exe(0x07, &r25, r05, 4, BR[13 +3][1][0], 4, 0LL, 0, 0x06, r21, 0x00, 0LL); exe(0x07, &r26, r06, 4, BR[13 +3][2][0], 4, 0LL, 0, 0x06, r22, 0x00, 0LL); exe(0x07, &r27, r07, 4, BR[13 +3][3][0], 4, 0LL, 0, 0x06, r23, 0x00, 0LL);
/-EMAX5AS-/
/-EMAX5AS-/
/-EMAX5AS-/ mop(0x04, 3, &BR[18][0][1], src0_row_scbase[6], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x04, 3, &BR[18][1][1], src0_row_scbase[10], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x04, 3, &BR[18][2][1], src0_row_scbase[7], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x04, 3, &BR[18][3][1], src0_row_scbase[11], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); exe(0x25, &r00, 0LL, 1, BR[18][1][1], 1, BR[18][0][1], 1, 0x00, 0LL, 0x02, 8LL); exe(0x25, &r01, 0LL, 1, BR[18][3][1], 1, BR[18][2][1], 1, 0x00, 0LL, 0x02, 8LL); mop(0x01, 0, &BR[18 +1][0][1], src0_row_qsbase[0][1], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 3, &BR[18 +1][0][0], src0_row_qsbase[0][0], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 0, &BR[18 +1][1][1], src0_row_qsbase[0][2], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 3, &BR[18 +1][1][0], src0_row_qsbase[0][1], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 0, &BR[18 +1][2][1], src0_row_qsbase[0][3], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 3, &BR[18 +1][2][0], src0_row_qsbase[0][2], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 0, &BR[18 +1][3][1], src0_row_qsbase[0][4], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 3, &BR[18 +1][3][0], src0_row_qsbase[0][3], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 0, &BR[18 +2][0][1], src0_row_hmbase[1], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 3, &BR[18 +2][0][0], src0_row_hmbase[0], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 0, &BR[18 +2][1][1], src0_row_hmbase[2], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 3, &BR[18 +2][1][0], src0_row_hmbase[1], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 0, &BR[18 +2][2][1], src0_row_hmbase[3], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 3, &BR[18 +2][2][0], src0_row_hmbase[2], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 0, &BR[18 +2][3][1], src0_row_hmbase[4], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 3, &BR[18 +2][3][0], src0_row_hmbase[3], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); exe(0x06, &r04, r00, 3, BR[18 +2][0][0], 0, BR[18 +1][0][0], 0, 0x00, 0LL, 0x00, 8LL); exe(0x06, &r05, r00, 3, BR[18 +2][1][0], 0, BR[18 +1][1][0], 0, 0x00, 0LL, 0x00, 8LL); exe(0x06, &r06, r01, 3, BR[18 +2][2][0], 0, BR[18 +1][2][0], 0, 0x00, 0LL, 0x00, 8LL); exe(0x06, &r07, r01, 3, BR[18 +2][3][0], 0, BR[18 +1][3][0], 0, 0x00, 0LL, 0x00, 8LL); mop(0x01, 0, &BR[18 +3][0][1], src1_col_base[3][1], (Ull)iofs, 12, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); mop(0x01, 3, &BR[18 +3][0][0], src1_col_base[3][0], (Ull)iofs, 12, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); mop(0x01, 0, &BR[18 +3][1][1], src1_col_base[3][2], (Ull)iofs, 12, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); mop(0x01, 3, &BR[18 +3][1][0], src1_col_base[3][1], (Ull)iofs, 12, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); mop(0x01, 0, &BR[18 +3][2][1], src1_col_base[3][3], (Ull)iofs, 12, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); mop(0x01, 3, &BR[18 +3][2][0], src1_col_base[3][2], (Ull)iofs, 12, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); mop(0x01, 0, &BR[18 +3][3][1], src1_col_base[3][4], (Ull)iofs, 12, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); mop(0x01, 3, &BR[18 +3][3][0], src1_col_base[3][3], (Ull)iofs, 12, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); exe(0x07, &r20, r04, 3, BR[18 +3][0][0], 3, 0LL, 0, 0x06, r24, 0x00, 0LL); exe(0x07, &r21, r05, 3, BR[18 +3][1][0], 3, 0LL, 0, 0x06, r25, 0x00, 0LL); exe(0x07, &r22, r06, 3, BR[18 +3][2][0], 3, 0LL, 0, 0x06, r26, 0x00, 0LL); exe(0x07, &r23, r07, 3, BR[18 +3][3][0], 3, 0LL, 0, 0x06, r27, 0x00, 0LL); exe(0x07, &r24, r04, 4, BR[18 +3][0][0], 4, 0LL, 0, 0x06, r20, 0x00, 0LL); exe(0x07, &r25, r05, 4, BR[18 +3][1][0], 4, 0LL, 0, 0x06, r21, 0x00, 0LL); exe(0x07, &r26, r06, 4, BR[18 +3][2][0], 4, 0LL, 0, 0x06, r22, 0x00, 0LL); exe(0x07, &r27, r07, 4, BR[18 +3][3][0], 4, 0LL, 0, 0x06, r23, 0x00, 0LL);
/-EMAX5AS-/
/-EMAX5AS-/
/-EMAX5AS-/ mop(0x04, 3, &BR[23][0][1], src0_row_scbase[0], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x04, 3, &BR[23][1][1], src0_row_scbase[8], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x04, 3, &BR[23][2][1], src0_row_scbase[1], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x04, 3, &BR[23][3][1], src0_row_scbase[9], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); exe(0x25, &r00, 0LL, 1, BR[23][1][1], 1, BR[23][0][1], 1, 0x00, 0LL, 0x02, 8LL); exe(0x25, &r01, 0LL, 1, BR[23][3][1], 1, BR[23][2][1], 1, 0x00, 0LL, 0x02, 8LL); mop(0x01, 0, &BR[23 +1][0][1], src0_row_qsbase[1][1], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 3, &BR[23 +1][0][0], src0_row_qsbase[1][0], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 0, &BR[23 +1][1][1], src0_row_qsbase[1][2], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 3, &BR[23 +1][1][0], src0_row_qsbase[1][1], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 0, &BR[23 +1][2][1], src0_row_qsbase[1][3], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 3, &BR[23 +1][2][0], src0_row_qsbase[1][2], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 0, &BR[23 +1][3][1], src0_row_qsbase[1][4], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 3, &BR[23 +1][3][0], src0_row_qsbase[1][3], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 0, &BR[23 +2][0][1], src0_row_hmbase[1], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 3, &BR[23 +2][0][0], src0_row_hmbase[0], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 0, &BR[23 +2][1][1], src0_row_hmbase[2], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 3, &BR[23 +2][1][0], src0_row_hmbase[1], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 0, &BR[23 +2][2][1], src0_row_hmbase[3], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 3, &BR[23 +2][2][0], src0_row_hmbase[2], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 0, &BR[23 +2][3][1], src0_row_hmbase[4], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 3, &BR[23 +2][3][0], src0_row_hmbase[3], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); exe(0x06, &r04, r00, 4, BR[23 +2][0][0], 0, BR[23 +1][0][0], 0, 0x00, 0LL, 0x00, 8LL); exe(0x06, &r05, r00, 4, BR[23 +2][1][0], 0, BR[23 +1][1][0], 0, 0x00, 0LL, 0x00, 8LL); exe(0x06, &r06, r01, 4, BR[23 +2][2][0], 0, BR[23 +1][2][0], 0, 0x00, 0LL, 0x00, 8LL); exe(0x06, &r07, r01, 4, BR[23 +2][3][0], 0, BR[23 +1][3][0], 0, 0x00, 0LL, 0x00, 8LL); mop(0x01, 0, &BR[23 +3][0][1], src1_col_base[4][1], (Ull)iofs, 12, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); mop(0x01, 3, &BR[23 +3][0][0], src1_col_base[4][0], (Ull)iofs, 12, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); mop(0x01, 0, &BR[23 +3][1][1], src1_col_base[4][2], (Ull)iofs, 12, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); mop(0x01, 3, &BR[23 +3][1][0], src1_col_base[4][1], (Ull)iofs, 12, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); mop(0x01, 0, &BR[23 +3][2][1], src1_col_base[4][3], (Ull)iofs, 12, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); mop(0x01, 3, &BR[23 +3][2][0], src1_col_base[4][2], (Ull)iofs, 12, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); mop(0x01, 0, &BR[23 +3][3][1], src1_col_base[4][4], (Ull)iofs, 12, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); mop(0x01, 3, &BR[23 +3][3][0], src1_col_base[4][3], (Ull)iofs, 12, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); exe(0x07, &r20, r04, 3, BR[23 +3][0][0], 3, 0LL, 0, 0x06, r24, 0x00, 0LL); exe(0x07, &r21, r05, 3, BR[23 +3][1][0], 3, 0LL, 0, 0x06, r25, 0x00, 0LL); exe(0x07, &r22, r06, 3, BR[23 +3][2][0], 3, 0LL, 0, 0x06, r26, 0x00, 0LL); exe(0x07, &r23, r07, 3, BR[23 +3][3][0], 3, 0LL, 0, 0x06, r27, 0x00, 0LL); exe(0x07, &r24, r04, 4, BR[23 +3][0][0], 4, 0LL, 0, 0x06, r20, 0x00, 0LL); exe(0x07, &r25, r05, 4, BR[23 +3][1][0], 4, 0LL, 0, 0x06, r21, 0x00, 0LL); exe(0x07, &r26, r06, 4, BR[23 +3][2][0], 4, 0LL, 0, 0x06, r22, 0x00, 0LL); exe(0x07, &r27, r07, 4, BR[23 +3][3][0], 4, 0LL, 0, 0x06, r23, 0x00, 0LL);
/-EMAX5AS-/
/-EMAX5AS-/
/-EMAX5AS-/ mop(0x04, 3, &BR[28][0][1], src0_row_scbase[2], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x04, 3, &BR[28][1][1], src0_row_scbase[10], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x04, 3, &BR[28][2][1], src0_row_scbase[3], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x04, 3, &BR[28][3][1], src0_row_scbase[11], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); exe(0x25, &r00, 0LL, 1, BR[28][1][1], 1, BR[28][0][1], 1, 0x00, 0LL, 0x02, 8LL); exe(0x25, &r01, 0LL, 1, BR[28][3][1], 1, BR[28][2][1], 1, 0x00, 0LL, 0x02, 8LL); mop(0x01, 0, &BR[28 +1][0][1], src0_row_qsbase[1][1], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 3, &BR[28 +1][0][0], src0_row_qsbase[1][0], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 0, &BR[28 +1][1][1], src0_row_qsbase[1][2], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 3, &BR[28 +1][1][0], src0_row_qsbase[1][1], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 0, &BR[28 +1][2][1], src0_row_qsbase[1][3], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 3, &BR[28 +1][2][0], src0_row_qsbase[1][2], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 0, &BR[28 +1][3][1], src0_row_qsbase[1][4], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 3, &BR[28 +1][3][0], src0_row_qsbase[1][3], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 0, &BR[28 +2][0][1], src0_row_hmbase[1], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 3, &BR[28 +2][0][0], src0_row_hmbase[0], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 0, &BR[28 +2][1][1], src0_row_hmbase[2], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 3, &BR[28 +2][1][0], src0_row_hmbase[1], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 0, &BR[28 +2][2][1], src0_row_hmbase[3], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 3, &BR[28 +2][2][0], src0_row_hmbase[2], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 0, &BR[28 +2][3][1], src0_row_hmbase[4], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 3, &BR[28 +2][3][0], src0_row_hmbase[3], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); exe(0x06, &r04, r00, 5, BR[28 +2][0][0], 0, BR[28 +1][0][0], 0, 0x00, 0LL, 0x00, 8LL); exe(0x06, &r05, r00, 5, BR[28 +2][1][0], 0, BR[28 +1][1][0], 0, 0x00, 0LL, 0x00, 8LL); exe(0x06, &r06, r01, 5, BR[28 +2][2][0], 0, BR[28 +1][2][0], 0, 0x00, 0LL, 0x00, 8LL); exe(0x06, &r07, r01, 5, BR[28 +2][3][0], 0, BR[28 +1][3][0], 0, 0x00, 0LL, 0x00, 8LL); mop(0x01, 0, &BR[28 +3][0][1], src1_col_base[5][1], (Ull)iofs, 12, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); mop(0x01, 3, &BR[28 +3][0][0], src1_col_base[5][0], (Ull)iofs, 12, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); mop(0x01, 0, &BR[28 +3][1][1], src1_col_base[5][2], (Ull)iofs, 12, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); mop(0x01, 3, &BR[28 +3][1][0], src1_col_base[5][1], (Ull)iofs, 12, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); mop(0x01, 0, &BR[28 +3][2][1], src1_col_base[5][3], (Ull)iofs, 12, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); mop(0x01, 3, &BR[28 +3][2][0], src1_col_base[5][2], (Ull)iofs, 12, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); mop(0x01, 0, &BR[28 +3][3][1], src1_col_base[5][4], (Ull)iofs, 12, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); mop(0x01, 3, &BR[28 +3][3][0], src1_col_base[5][3], (Ull)iofs, 12, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); exe(0x07, &r20, r04, 3, BR[28 +3][0][0], 3, 0LL, 0, 0x06, r24, 0x00, 0LL); exe(0x07, &r21, r05, 3, BR[28 +3][1][0], 3, 0LL, 0, 0x06, r25, 0x00, 0LL); exe(0x07, &r22, r06, 3, BR[28 +3][2][0], 3, 0LL, 0, 0x06, r26, 0x00, 0LL); exe(0x07, &r23, r07, 3, BR[28 +3][3][0], 3, 0LL, 0, 0x06, r27, 0x00, 0LL); exe(0x07, &r24, r04, 4, BR[28 +3][0][0], 4, 0LL, 0, 0x06, r20, 0x00, 0LL); exe(0x07, &r25, r05, 4, BR[28 +3][1][0], 4, 0LL, 0, 0x06, r21, 0x00, 0LL); exe(0x07, &r26, r06, 4, BR[28 +3][2][0], 4, 0LL, 0, 0x06, r22, 0x00, 0LL); exe(0x07, &r27, r07, 4, BR[28 +3][3][0], 4, 0LL, 0, 0x06, r23, 0x00, 0LL);
/-EMAX5AS-/
/-EMAX5AS-/
/-EMAX5AS-/ mop(0x04, 3, &BR[33][0][1], src0_row_scbase[4], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x04, 3, &BR[33][1][1], src0_row_scbase[8], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x04, 3, &BR[33][2][1], src0_row_scbase[5], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x04, 3, &BR[33][3][1], src0_row_scbase[9], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); exe(0x25, &r00, 0LL, 1, BR[33][1][1], 1, BR[33][0][1], 1, 0x00, 0LL, 0x02, 8LL); exe(0x25, &r01, 0LL, 1, BR[33][3][1], 1, BR[33][2][1], 1, 0x00, 0LL, 0x02, 8LL); mop(0x01, 0, &BR[33 +1][0][1], src0_row_qsbase[1][1], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 3, &BR[33 +1][0][0], src0_row_qsbase[1][0], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 0, &BR[33 +1][1][1], src0_row_qsbase[1][2], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 3, &BR[33 +1][1][0], src0_row_qsbase[1][1], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 0, &BR[33 +1][2][1], src0_row_qsbase[1][3], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 3, &BR[33 +1][2][0], src0_row_qsbase[1][2], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 0, &BR[33 +1][3][1], src0_row_qsbase[1][4], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 3, &BR[33 +1][3][0], src0_row_qsbase[1][3], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 0, &BR[33 +2][0][1], src0_row_hmbase[1], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 3, &BR[33 +2][0][0], src0_row_hmbase[0], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 0, &BR[33 +2][1][1], src0_row_hmbase[2], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 3, &BR[33 +2][1][0], src0_row_hmbase[1], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 0, &BR[33 +2][2][1], src0_row_hmbase[3], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 3, &BR[33 +2][2][0], src0_row_hmbase[2], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 0, &BR[33 +2][3][1], src0_row_hmbase[4], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 3, &BR[33 +2][3][0], src0_row_hmbase[3], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); exe(0x06, &r04, r00, 6, BR[33 +2][0][0], 0, BR[33 +1][0][0], 0, 0x00, 0LL, 0x00, 8LL); exe(0x06, &r05, r00, 6, BR[33 +2][1][0], 0, BR[33 +1][1][0], 0, 0x00, 0LL, 0x00, 8LL); exe(0x06, &r06, r01, 6, BR[33 +2][2][0], 0, BR[33 +1][2][0], 0, 0x00, 0LL, 0x00, 8LL); exe(0x06, &r07, r01, 6, BR[33 +2][3][0], 0, BR[33 +1][3][0], 0, 0x00, 0LL, 0x00, 8LL); mop(0x01, 0, &BR[33 +3][0][1], src1_col_base[6][1], (Ull)iofs, 12, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); mop(0x01, 3, &BR[33 +3][0][0], src1_col_base[6][0], (Ull)iofs, 12, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); mop(0x01, 0, &BR[33 +3][1][1], src1_col_base[6][2], (Ull)iofs, 12, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); mop(0x01, 3, &BR[33 +3][1][0], src1_col_base[6][1], (Ull)iofs, 12, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); mop(0x01, 0, &BR[33 +3][2][1], src1_col_base[6][3], (Ull)iofs, 12, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); mop(0x01, 3, &BR[33 +3][2][0], src1_col_base[6][2], (Ull)iofs, 12, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); mop(0x01, 0, &BR[33 +3][3][1], src1_col_base[6][4], (Ull)iofs, 12, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); mop(0x01, 3, &BR[33 +3][3][0], src1_col_base[6][3], (Ull)iofs, 12, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); exe(0x07, &r20, r04, 3, BR[33 +3][0][0], 3, 0LL, 0, 0x06, r24, 0x00, 0LL); exe(0x07, &r21, r05, 3, BR[33 +3][1][0], 3, 0LL, 0, 0x06, r25, 0x00, 0LL); exe(0x07, &r22, r06, 3, BR[33 +3][2][0], 3, 0LL, 0, 0x06, r26, 0x00, 0LL); exe(0x07, &r23, r07, 3, BR[33 +3][3][0], 3, 0LL, 0, 0x06, r27, 0x00, 0LL); exe(0x07, &r24, r04, 4, BR[33 +3][0][0], 4, 0LL, 0, 0x06, r20, 0x00, 0LL); exe(0x07, &r25, r05, 4, BR[33 +3][1][0], 4, 0LL, 0, 0x06, r21, 0x00, 0LL); exe(0x07, &r26, r06, 4, BR[33 +3][2][0], 4, 0LL, 0, 0x06, r22, 0x00, 0LL); exe(0x07, &r27, r07, 4, BR[33 +3][3][0], 4, 0LL, 0, 0x06, r23, 0x00, 0LL);
/-EMAX5AS-/
/-EMAX5AS-/
/-EMAX5AS-/ mop(0x04, 3, &BR[38][0][1], src0_row_scbase[6], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x04, 3, &BR[38][1][1], src0_row_scbase[10], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x04, 3, &BR[38][2][1], src0_row_scbase[7], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x04, 3, &BR[38][3][1], src0_row_scbase[11], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); exe(0x25, &r00, 0LL, 1, BR[38][1][1], 1, BR[38][0][1], 1, 0x00, 0LL, 0x02, 8LL); exe(0x25, &r01, 0LL, 1, BR[38][3][1], 1, BR[38][2][1], 1, 0x00, 0LL, 0x02, 8LL); mop(0x01, 0, &BR[38 +1][0][1], src0_row_qsbase[1][1], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 3, &BR[38 +1][0][0], src0_row_qsbase[1][0], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 0, &BR[38 +1][1][1], src0_row_qsbase[1][2], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 3, &BR[38 +1][1][0], src0_row_qsbase[1][1], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 0, &BR[38 +1][2][1], src0_row_qsbase[1][3], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 3, &BR[38 +1][2][0], src0_row_qsbase[1][2], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 0, &BR[38 +1][3][1], src0_row_qsbase[1][4], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 3, &BR[38 +1][3][0], src0_row_qsbase[1][3], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 0, &BR[38 +2][0][1], src0_row_hmbase[1], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 3, &BR[38 +2][0][0], src0_row_hmbase[0], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 0, &BR[38 +2][1][1], src0_row_hmbase[2], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 3, &BR[38 +2][1][0], src0_row_hmbase[1], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 0, &BR[38 +2][2][1], src0_row_hmbase[3], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 3, &BR[38 +2][2][0], src0_row_hmbase[2], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 0, &BR[38 +2][3][1], src0_row_hmbase[4], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 3, &BR[38 +2][3][0], src0_row_hmbase[3], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); exe(0x06, &r04, r00, 7, BR[38 +2][0][0], 0, BR[38 +1][0][0], 0, 0x00, 0LL, 0x00, 8LL); exe(0x06, &r05, r00, 7, BR[38 +2][1][0], 0, BR[38 +1][1][0], 0, 0x00, 0LL, 0x00, 8LL); exe(0x06, &r06, r01, 7, BR[38 +2][2][0], 0, BR[38 +1][2][0], 0, 0x00, 0LL, 0x00, 8LL); exe(0x06, &r07, r01, 7, BR[38 +2][3][0], 0, BR[38 +1][3][0], 0, 0x00, 0LL, 0x00, 8LL); mop(0x01, 0, &BR[38 +3][0][1], src1_col_base[7][1], (Ull)iofs, 12, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); mop(0x01, 3, &BR[38 +3][0][0], src1_col_base[7][0], (Ull)iofs, 12, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); mop(0x01, 0, &BR[38 +3][1][1], src1_col_base[7][2], (Ull)iofs, 12, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); mop(0x01, 3, &BR[38 +3][1][0], src1_col_base[7][1], (Ull)iofs, 12, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); mop(0x01, 0, &BR[38 +3][2][1], src1_col_base[7][3], (Ull)iofs, 12, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); mop(0x01, 3, &BR[38 +3][2][0], src1_col_base[7][2], (Ull)iofs, 12, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); mop(0x01, 0, &BR[38 +3][3][1], src1_col_base[7][4], (Ull)iofs, 12, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); mop(0x01, 3, &BR[38 +3][3][0], src1_col_base[7][3], (Ull)iofs, 12, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); exe(0x07, &r20, r04, 3, BR[38 +3][0][0], 3, 0LL, 0, 0x06, r24, 0x00, 0LL); exe(0x07, &r21, r05, 3, BR[38 +3][1][0], 3, 0LL, 0, 0x06, r25, 0x00, 0LL); exe(0x07, &r22, r06, 3, BR[38 +3][2][0], 3, 0LL, 0, 0x06, r26, 0x00, 0LL); exe(0x07, &r23, r07, 3, BR[38 +3][3][0], 3, 0LL, 0, 0x06, r27, 0x00, 0LL); exe(0x07, &r24, r04, 4, BR[38 +3][0][0], 4, 0LL, 0, 0x06, r20, 0x00, 0LL); exe(0x07, &r25, r05, 4, BR[38 +3][1][0], 4, 0LL, 0, 0x06, r21, 0x00, 0LL); exe(0x07, &r26, r06, 4, BR[38 +3][2][0], 4, 0LL, 0, 0x06, r22, 0x00, 0LL); exe(0x07, &r27, r07, 4, BR[38 +3][3][0], 4, 0LL, 0, 0x06, r23, 0x00, 0LL);
/-EMAX5AS-/
/-EMAX5AS-/
/-EMAX5AS-/ exe(0x00, &r28, r24, 0, 0LL, 0, 0LL, 0, 0x06, r25, 0x00, 0LL);
/-EMAX5AS-/ exe(0x00, &r29, r26, 0, 0LL, 0, 0LL, 0, 0x06, r27, 0x00, 0LL);
/-EMAX5AS-/ mop(0x01, 0, &BR[44][0][1], src0_row_dbase_p8, (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN);
/-EMAX5AS-/ mop(0x01, 3, &BR[44][0][0], src0_row_dbase_p0, (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN);
/-EMAX5AS-/
/-EMAX5AS-/ exe(0x00, &r30, r28, 0, 0LL, 0, 0LL, 0, 0x06, r29, 0x00, 0LL);
/-EMAX5AS-/ mop(0x01, 0, &BR[45][0][1], src1_col_dbase_p8, (Ull)iofs, 12, i_m0B[LANE],SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL);
/-EMAX5AS-/ mop(0x01, 3, &BR[45][0][0], src1_col_dbase_p0, (Ull)iofs, 12, i_m0B[LANE],SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL);
/-EMAX5AS-/
/-EMAX5AS-/ exe(0x00, &r31, r30, 2, 0LL, 0, 0LL, 0, 0x06, r30, 0x04,8LL);
/-EMAX5AS-/
/-EMAX5AS-/
/-EMAX5AS-/
/-EMAX5AS-/ exe(0x00, &r12, r31, 0, 0LL, 0, 0LL, 0, 0x01, 0x000000000000ffffLL, 0x01, 2LL);
/-EMAX5AS-/ exe(0x00, &r13, BR[44][0][0], 0, 0LL, 0, 0LL, 0, 0x01, 0x000000000000ffffLL, 0x01, 2LL);
/-EMAX5AS-/
/-EMAX5AS-/ mop(0x02, 3, &BR[48][0][1], (Ull)i_i16[LANE], (Ull)r12, 12, (Ull)i_i16[LANE], 65536, 0, 0, (Ull)((void *)0), 65536);
/-EMAX5AS-/ mop(0x02, 3, &BR[48][2][1], (Ull)i_f16[LANE], (Ull)r13, 12, (Ull)i_f16[LANE], 65536, 0, 0, (Ull)((void *)0), 65536);
/-EMAX5AS-/
/-EMAX5AS-/ exe(0x12, &r03, BR[48][0][1], 0, 0x44000000LL, 0, 0LL, 0, 0x00, 0LL, 0x00, 0LL);
/-EMAX5AS-/ exe(0x12, &r02, BR[48][2][1], 0, BR[45][0][0], 0, 0LL, 0, 0x00, 0LL, 0x00, 0LL);
/-EMAX5AS-/
/-EMAX5AS-/ exe(0x00, &AR[50][0], 0LL, 0, 0LL, 0, 0LL, 0, 0x00, 0LL, 0x00, 0LL);
/-EMAX5AS-/ mop(0x02, 1, &r00, dst_col, oofs, 12, i_m0C_TOP_IMAP[0][LANE], DST_COL_LEN_TOTdIMAP, 0, Force2, (Ull)((void *)0), DST_COL_LEN_TOTdIMAP);
/-EMAX5AS-/ exe(0x10, &r00, INIT0?r00:r00, 0, r03, 0, r02, 0, 0x00, 0LL, 0x00, 0LL);
/-EMAX5AS-/ mop(0x12, 1, &r00, oofs, dst_col, 14, i_m0C_TOP_IMAP[0][LANE], DST_COL_LEN_TOTdIMAP, 0, Force2, (Ull)((void *)0), DST_COL_LEN_TOTdIMAP);
/-EMAX5AS-/ }
/-EMAX5AS-/ }
/-EMAX5AS-/ }
/-EMAX5AE-/
          if (Force0) Force0 = 0;
          if (Force1) Force1 = 0;
          if (Force2) Force2 = 0;
      }
    }
/-EMAX5AD-/
    monitor_time_start(THREAD, IMAX_CPYOUT_Q3K);
    if (!((Ull)DST_COL_TOP & 63) && !((Ull)i_m0C[LANE] & 63) && DST_COL_LENdIMAP == 16 && 1 == 1) {
      for (int i=0; i<IR1_LOOPS; i++) {
 Dll *dst = (int*)DST_COL_TOP+i*nb1/sizeof(int);
 Dll *src = (int*)i_m0C[LANE]+i*16;
 *dst++ = *src++;
 *dst++ = *src++;
 *dst++ = *src++;
 *dst++ = *src++;
      }
    }
    else
      xmax_cpyout(4, DST_COL_TOP, 1, nb1/sizeof(int), i_m0C[LANE], IR1_LOOPS, DST_COL_LENdIMAP, 1);
    monitor_time_end(THREAD, IMAX_CPYOUT_Q3K);
  }
}
void imax_compute_forward_mul_mat_one_chunk_q6_k(struct th_inference_args *args)
{
  int THREAD = args->thid;
  int LANE = args->thid;
  struct ggml_tensor * dst = args->dst;
  const int64_t num_rows_per_vec_dot = args->num_rows_per_vec_dot;
  const int64_t ir0_start = args->ir0_start;
  const int64_t ir0_end = args->ir0_end;
  const int64_t ir1_start = args->ir1_start;
  const int64_t ir1_end = args->ir1_end;
  const struct ggml_tensor * src0 = args->src0;
  const struct ggml_tensor * src1 = args->src1;
  const enum ggml_type type = args->type;
  const _Bool src1_cont = args->src1_cont;
  ggml_vec_dot_t const vec_dot = args->vec_dot;
  enum ggml_type const vec_dot_type = args->vec_dot_type;
  const void * wdata = args->wdata;
  const size_t row_size = args->row_size;
  const int64_t r2 = args->r2;
  const int64_t r3 = args->r3;
  const int64_t blck_0 = args->blck_0;
  const int64_t blck_1 = args->blck_1;
  const size_t src1_col_stride = args->src1_col_stride;
  int i, j;
  float tmp[32];
  const int64_t ne00 = (src0) ? (src0)->ne[0] : 0; (void)(ne00); const int64_t ne01 = (src0) ? (src0)->ne[1] : 0; (void)(ne01); const int64_t ne02 = (src0) ? (src0)->ne[2] : 0; (void)(ne02); const int64_t ne03 = (src0) ? (src0)->ne[3] : 0; (void)(ne03); const size_t nb00 = (src0) ? (src0)->nb[0] : 0; (void)(nb00); const size_t nb01 = (src0) ? (src0)->nb[1] : 0; (void)(nb01); const size_t nb02 = (src0) ? (src0)->nb[2] : 0; (void)(nb02); const size_t nb03 = (src0) ? (src0)->nb[3] : 0; (void)(nb03); const int64_t ne10 = (src1) ? (src1)->ne[0] : 0; (void)(ne10); const int64_t ne11 = (src1) ? (src1)->ne[1] : 0; (void)(ne11); const int64_t ne12 = (src1) ? (src1)->ne[2] : 0; (void)(ne12); const int64_t ne13 = (src1) ? (src1)->ne[3] : 0; (void)(ne13); const size_t nb10 = (src1) ? (src1)->nb[0] : 0; (void)(nb10); const size_t nb11 = (src1) ? (src1)->nb[1] : 0; (void)(nb11); const size_t nb12 = (src1) ? (src1)->nb[2] : 0; (void)(nb12); const size_t nb13 = (src1) ? (src1)->nb[3] : 0; (void)(nb13); const int64_t ne0 = (dst) ? (dst)->ne[0] : 0; (void)(ne0); const int64_t ne1 = (dst) ? (dst)->ne[1] : 0; (void)(ne1); const int64_t ne2 = (dst) ? (dst)->ne[2] : 0; (void)(ne2); const int64_t ne3 = (dst) ? (dst)->ne[3] : 0; (void)(ne3); const size_t nb0 = (dst) ? (dst)->nb[0] : 0; (void)(nb0); const size_t nb1 = (dst) ? (dst)->nb[1] : 0; (void)(nb1); const size_t nb2 = (dst) ? (dst)->nb[2] : 0; (void)(nb2); const size_t nb3 = (dst) ? (dst)->nb[3] : 0; (void)(nb3);
  int n = ne00;
  const int nb = n / 256;
  Ull IIR1_LOOPS = (ir1_end-ir1_start)/blck_1;
  Ull IIR0_LOOPS = (ir0_end-ir0_start)/blck_0;
  Ull IR1_LOOPS = ((ir1_start+blck_1) < (ir1_end) ? (ir1_start+blck_1) : (ir1_end))-ir1_start;
  Ull SRC0_ROW_LEN = sizeof(block_q6_K)*nb*blck_0*IIR0_LOOPS/sizeof(int);
  Ull SRC1_COL_LEN = (sizeof(block_q8_K)*nb+3)/sizeof(int);
  Ull SRC1_COL_LEN_TOTAL = SRC1_COL_LEN*IR1_LOOPS;
  Ull DST_COL_LEN = blck_0*IIR0_LOOPS;
  Ull DST_COL_LEN_TOTAL = DST_COL_LEN*IR1_LOOPS;
  if (SRC0_ROW_LEN >512*1024/sizeof(int) || ((ir0_end - ir0_start) % blck_0) || num_rows_per_vec_dot != 1) {
    monitor_time_start(THREAD, IMAX_COMPUTE_FORWARD_MUL_MAT_ONE_CHUNK_Q6K_ARM);
    for (int64_t iir1 = ir1_start; iir1 < ir1_end; iir1 += blck_1) {
      for (int64_t iir0 = ir0_start; iir0 < ir0_end; iir0 += blck_0) {
 for (int64_t ir1 = iir1; ir1 < iir1 + blck_1 && ir1 < ir1_end; ir1 += num_rows_per_vec_dot) {
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
   for (int64_t ir0 = iir0; ir0 < iir0 + blck_0 && ir0 < ir0_end; ir0 += num_rows_per_vec_dot) {
     vec_dot(ne00, &tmp[ir0 - iir0], (num_rows_per_vec_dot > 1 ? 16 : 0), src0_row + ir0 * nb01, (num_rows_per_vec_dot > 1 ? nb01 : 0), src1_col, (num_rows_per_vec_dot > 1 ? src1_col_stride : 0), num_rows_per_vec_dot);
   }
   monitor_time_start(THREAD, ARM_MEMCPY);
   for (int cn = 0; cn < num_rows_per_vec_dot; ++cn)
     memcpy(&dst_col[iir0 + cn * nb1 / nb0], tmp + (cn * 16), (((iir0 + blck_0) < (ir0_end) ? (iir0 + blck_0) : (ir0_end)) - iir0) * sizeof(float));
   monitor_time_end(THREAD, ARM_MEMCPY);
 }
      }
    }
    monitor_time_end(THREAD, IMAX_COMPUTE_FORWARD_MUL_MAT_ONE_CHUNK_Q6K_ARM);
  }
  else {
    Ull CHIP, rofs, cofs, xofs, yofs, iofs, oofs;
    Ull LOOP1, LOOP0;
    Ull INIT1, INIT0;
    Ull AR[64][4];
    Ull BR[64][4][4];
    Ull r00, r01, r02, r03, r04, r05, r06, r07, r08, r09, r10, r11, r12, r13, r14, r15;
    Ull r16, r17, r18, r19, r20, r21, r22, r23, r24, r25, r26, r27, r28, r29, r30, r31;
    Ull cc0, cc1, cc2, cc3, ex0, ex1, out0, out1, out2, out10;
    Ull Force0, Force1, Force2;
    Ull MNB01_M4 = (0LL-nb01 )<<32|((0LL-sizeof(float)) &0xffffffffLL);
    Ull MBKQ6_MBKQ8 = (0LL-sizeof(block_q6_K))<<32|((0LL-sizeof(block_q8_K))&0xffffffffLL);
    Ull NB01_4 = (0LL+nb01 )<<32|((0LL+sizeof(float)) &0xffffffffLL);
    Ull BKQ6_BKQ8 = (0LL+sizeof(block_q6_K))<<32|((0LL+sizeof(block_q8_K))&0xffffffffLL);
    const int64_t i13_top = (ir1_start / (ne12 * ne1));
    const int64_t i12_top = (ir1_start - i13_top * ne12 * ne1) / ne1;
    const int64_t i11_top = (ir1_start - i13_top * ne12 * ne1 - i12_top * ne1);
    const int64_t i03_top = i13_top / r3;
    const int64_t i02_top = i12_top / r2;
    Ull SRC0_ROW_TOP = (const char*)src0->data + (0 + i02_top * nb02 + i03_top * nb03) + ir0_start*nb01;
    Ull SRC0_ROW_LENdIMAP = SRC0_ROW_LEN/1;
    Ull i_m0A_TOP = (const char*)i_m0A[LANE] + (0 + i02_top * nb02 + i03_top * nb03) + ir0_start*nb01;
    Ull SRC1_COL_TOP = (const char*)wdata + (src1_cont || src1->type != vec_dot_type ? (i11_top + i12_top * ne11 + i13_top * ne12 * ne11) * row_size
                                                                                            : (i11_top * nb11 + i12_top * nb12 + i13_top * nb13));
    Ull DST_COL_TOP = (float*)((char*)dst->data + (i11_top * nb1 + i12_top * nb2 + i13_top * nb3)) + ir0_start;
    Ull DST_COL_LENdIMAP = DST_COL_LEN/1;
    Ull DST_COL_LEN_TOTdIMAP = DST_COL_LEN_TOTAL/1;
    Ull i_m0C_TOP_IMAP[1][8]; for (i=0; i<1; i++) i_m0C_TOP_IMAP[i][LANE] = (Ull)i_m0C[LANE] + i*sizeof(float)*DST_COL_LEN_TOTdIMAP;
    int ctmp;
    if (src0_preloaded) {
      i_m0A_TOP = i_m0A[0] + (SRC0_ROW_TOP - SRC0_ROW_TOP_DIRECT);
      Force0=1;
    }
    else if (*(Ull*)i_m0A_TOP == *(Ull*)SRC0_ROW_TOP) {
      Force0=0;
    }
    else {
      monitor_time_start(THREAD, IMAX_CPYIN_A_Q6K);
      xmax_cpyin(3,i_m0A_TOP,&ctmp,SRC0_ROW_TOP,1,1,SRC0_ROW_LEN,1,1);
      monitor_time_end(THREAD, IMAX_CPYIN_A_Q6K);
      Force0=1;
    }
    if (*(Ull*)i_m0B[LANE] == *(Ull*)SRC1_COL_TOP) {
      Force1=0;
    }
    else {
      monitor_time_start(THREAD, IMAX_CPYIN_B_Q6K);
      xmax_cpyin(3,i_m0B[LANE],&ctmp,SRC1_COL_TOP,1,1,SRC1_COL_LEN_TOTAL,1,1);
      monitor_time_end(THREAD, IMAX_CPYIN_B_Q6K);
      Force1=1;
    }
    monitor_time_start(THREAD, IMAX_BZERO_Q6K);
    xmax_bzero(i_m0C[LANE], (Ull)DST_COL_LEN_TOTAL);
    Force2 = 1;
    monitor_time_end(THREAD, IMAX_BZERO_Q6K);
    for (int64_t iir1 = ir1_start; iir1 < ir1_end; iir1 += blck_1) {
      for (int64_t ir1 = iir1; ir1 < iir1 + blck_1 && ir1 < ir1_end; ir1 += num_rows_per_vec_dot) {
   const int64_t i13 = (ir1 / (ne12 * ne1));
   const int64_t i12 = (ir1 - i13 * ne12 * ne1) / ne1;
   const int64_t i11 = (ir1 - i13 * ne12 * ne1 - i12 * ne1);
          const int64_t i03 = i13 / r3;
          const int64_t i02 = i12 / r2;
   const int64_t i1 = i11;
   const int64_t i2 = i12;
   const int64_t i3 = i13;
   const int64_t blck_00 = blck_0*IIR0_LOOPS;
   const int64_t blck_00dIMAP = blck_00/1;
   const char * src0_row = (const char*)i_m0A_TOP;
   Ull src0_row_qlbase[4][5]; for (j=0; j<5; j++) src0_row_qlbase[0][j] = (Ull)src0_row+ 0+j*8;
                                        for (j=0; j<5; j++) src0_row_qlbase[1][j] = (Ull)src0_row+ 32+j*8;
                                        for (j=0; j<5; j++) src0_row_qlbase[2][j] = (Ull)src0_row+ 64+j*8;
                                        for (j=0; j<5; j++) src0_row_qlbase[3][j] = (Ull)src0_row+ 96+j*8;
   Ull src0_row_qhbase[2][5]; for (j=0; j<5; j++) src0_row_qhbase[0][j] = (Ull)src0_row+128+j*8;
                                         for (j=0; j<5; j++) src0_row_qhbase[1][j] = (Ull)src0_row+160+j*8;
   Ull src0_row_scbase[16]; for (j=0; j<16; j++) src0_row_scbase[j] = (Ull)src0_row+192+j;
   Ull src0_row_dbase_p0; src0_row_dbase_p0 = (Ull)src0_row+208;
   Ull src0_row_dbase_p8; src0_row_dbase_p8 = (Ull)src0_row+208+8;
   const char * src1_col = (const char*)i_m0B[LANE] + (ir1-ir1_start)*sizeof(int)*SRC1_COL_LEN;
   Ull src1_col_dbase_p0 = (Ull)src1_col;
   Ull src1_col_dbase_p8 = (Ull)src1_col+8;
   Ull src1_col_base[8][5]; for (i=0; i<8; i++) for (j=0; j<5; j++) src1_col_base[i][j] = (Ull)src1_col+4+i*32+j*8;
   float * dst_col = (float*)i_m0C[LANE] + (ir0_start-ir0_start) + (ir1-ir1_start)*DST_COL_LENdIMAP;
/-EMAX5AB-/ mul_mat_one_chunk_q6k 0
/-EMAX5AS-/ for (CHIP=0; CHIP<1; CHIP++) {
/-EMAX5AS-/ for (INIT1=1,LOOP1=""blck_00dIMAP"",rofs=""MNB01_M4""; LOOP1--; INIT1=0) {
/-EMAX5AS-/ for (INIT0=1,LOOP0=""nb"",cofs=""MBKQ6_MBKQ8""; LOOP0--; INIT0=0) {
/-EMAX5AS-/ exe(0x17, &rofs, rofs, 0, INIT0?NB01_4:0, 0, 0LL, 0, 0x00, 0LL, 0x00, 0LL);
/-EMAX5AS-/ exe(0x17, &cofs, INIT0?cofs:cofs, 0, BKQ6_BKQ8, 0, 0LL, 0, 0x00, 0LL, 0x00, 0LL);
/-EMAX5AS-/ exe(0x17, &xofs, rofs, 0, cofs, 0, 0LL, 0, 0x01, 0xffffffff00000000LL, 0x00, 0LL);
/-EMAX5AS-/ exe(0x17, &yofs, 0LL, 0, cofs, 0, 0LL, 0, 0x01, 0x00000000ffffffffLL, 0x00, 0LL);
/-EMAX5AS-/ exe(0x17, &oofs, rofs, 0, 0LL, 0, 0LL, 0, 0x01, 0x00000000ffffffffLL, 0x00, 0LL);
/-EMAX5AS-/ exe(0x00, &iofs, xofs, 0, 0LL, 0, 0LL, 0, 0x02, yofs, 0x00, 0LL);
/-EMAX5AS-/
/-EMAX5AS-/
/-EMAX5AS-/
/-EMAX5AS-/
/-EMAX5AS-/
/-EMAX5AS-/
/-EMAX5AS-/
/-EMAX5AS-/
/-EMAX5AS-/
/-EMAX5AS-/
/-EMAX5AS-/
/-EMAX5AS-/
/-EMAX5AS-/
/-EMAX5AS-/
/-EMAX5AS-/
/-EMAX5AS-/
/-EMAX5AS-/
/-EMAX5AS-/
/-EMAX5AS-/
/-EMAX5AS-/
/-EMAX5AS-/
/-EMAX5AS-/
/-EMAX5AS-/
/-EMAX5AS-/ mop(0x04, 3, &BR[2][0][1], src0_row_scbase[0], (Ull)xofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x04, 3, &BR[2][2][1], src0_row_scbase[1], (Ull)xofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); exe(0x25, &r00, 0LL, 1, 0LL, 1, BR[2][0][1], 1, 0x00, 0LL, 0x02, 8LL); exe(0x25, &r01, 0LL, 1, 0LL, 1, BR[2][2][1], 1, 0x00, 0LL, 0x02, 8LL); mop(0x01, 0, &BR[2 +1][0][1], src0_row_qlbase[0][1], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 3, &BR[2 +1][0][0], src0_row_qlbase[0][0], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 0, &BR[2 +1][1][1], src0_row_qlbase[0][2], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 3, &BR[2 +1][1][0], src0_row_qlbase[0][1], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 0, &BR[2 +2][0][1], src0_row_qhbase[0][1], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 3, &BR[2 +2][0][0], src0_row_qhbase[0][0], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 0, &BR[2 +2][1][1], src0_row_qhbase[0][2], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 3, &BR[2 +2][1][0], src0_row_qhbase[0][1], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); exe(0x03, &r04, r00, 0, BR[2 +2][0][0], 3, BR[2 +1][0][0], 3, 0x00, 0LL, 0x00, 8LL); exe(0x03, &r05, r00, 0, BR[2 +2][0][0], 4, BR[2 +1][0][0], 4, 0x00, 0LL, 0x00, 8LL); exe(0x03, &r06, r00, 0, BR[2 +2][1][0], 3, BR[2 +1][1][0], 3, 0x00, 0LL, 0x00, 8LL); exe(0x03, &r07, r00, 0, BR[2 +2][1][0], 4, BR[2 +1][1][0], 4, 0x00, 0LL, 0x00, 8LL); mop(0x01, 0, &BR[2 +3][0][1], src1_col_base[0][1], (Ull)iofs, 12, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); mop(0x01, 3, &BR[2 +3][0][0], src1_col_base[0][0], (Ull)iofs, 12, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); mop(0x01, 0, &BR[2 +3][1][1], src1_col_base[0][2], (Ull)iofs, 12, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); mop(0x01, 3, &BR[2 +3][1][0], src1_col_base[0][1], (Ull)iofs, 12, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); exe(0x04, &r20, r04, 0, BR[2 +3][0][0], 3, 0LL, 0, 0x06, 0LL, 0x00, 0LL); exe(0x04, &r21, r05, 0, BR[2 +3][0][0], 4, 0LL, 0, 0x06, 0LL, 0x00, 0LL); exe(0x04, &r22, r06, 0, BR[2 +3][1][0], 3, 0LL, 0, 0x06, 0LL, 0x00, 0LL); exe(0x04, &r23, r07, 0, BR[2 +3][1][0], 4, 0LL, 0, 0x06, 0LL, 0x00, 0LL); mop(0x01, 0, &BR[2 +4][2][1], src0_row_qlbase[0][3], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 3, &BR[2 +4][2][0], src0_row_qlbase[0][2], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 0, &BR[2 +4][3][1], src0_row_qlbase[0][4], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 3, &BR[2 +4][3][0], src0_row_qlbase[0][3], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 0, &BR[2 +5][2][1], src0_row_qhbase[0][3], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 3, &BR[2 +5][2][0], src0_row_qhbase[0][2], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 0, &BR[2 +5][3][1], src0_row_qhbase[0][4], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 3, &BR[2 +5][3][0], src0_row_qhbase[0][3], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); exe(0x03, &r08, r01, 0, BR[2 +5][2][0], 3, BR[2 +4][2][0], 3, 0x00, 0LL, 0x00, 8LL); exe(0x03, &r09, r01, 0, BR[2 +5][2][0], 4, BR[2 +4][2][0], 4, 0x00, 0LL, 0x00, 8LL); exe(0x03, &r10, r01, 0, BR[2 +5][3][0], 3, BR[2 +4][3][0], 3, 0x00, 0LL, 0x00, 8LL); exe(0x03, &r11, r01, 0, BR[2 +5][3][0], 4, BR[2 +4][3][0], 4, 0x00, 0LL, 0x00, 8LL); mop(0x01, 0, &BR[2 +6][2][1], src1_col_base[0][3], (Ull)iofs, 12, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); mop(0x01, 3, &BR[2 +6][2][0], src1_col_base[0][2], (Ull)iofs, 12, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); mop(0x01, 0, &BR[2 +6][3][1], src1_col_base[0][4], (Ull)iofs, 12, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); mop(0x01, 3, &BR[2 +6][3][0], src1_col_base[0][3], (Ull)iofs, 12, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); exe(0x04, &r24, r08, 0, BR[2 +6][2][0], 3, 0LL, 0, 0x06, r20, 0x00, 0LL); exe(0x04, &r25, r09, 0, BR[2 +6][2][0], 4, 0LL, 0, 0x06, r21, 0x00, 0LL); exe(0x04, &r26, r10, 0, BR[2 +6][3][0], 3, 0LL, 0, 0x06, r22, 0x00, 0LL); exe(0x04, &r27, r11, 0, BR[2 +6][3][0], 4, 0LL, 0, 0x06, r23, 0x00, 0LL);
/-EMAX5AS-/
/-EMAX5AS-/
/-EMAX5AS-/ mop(0x04, 3, &BR[9][0][1], src0_row_scbase[2], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x04, 3, &BR[9][2][1], src0_row_scbase[3], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); exe(0x25, &r00, 0LL, 1, 0LL, 1, BR[9][0][1], 1, 0x00, 0LL, 0x02, 8LL); exe(0x25, &r01, 0LL, 1, 0LL, 1, BR[9][2][1], 1, 0x00, 0LL, 0x02, 8LL); mop(0x01, 0, &BR[9 +1][0][1], src0_row_qlbase[1][1], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 3, &BR[9 +1][0][0], src0_row_qlbase[1][0], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 0, &BR[9 +1][1][1], src0_row_qlbase[1][2], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 3, &BR[9 +1][1][0], src0_row_qlbase[1][1], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 0, &BR[9 +2][0][1], src0_row_qhbase[0][1], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 3, &BR[9 +2][0][0], src0_row_qhbase[0][0], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 0, &BR[9 +2][1][1], src0_row_qhbase[0][2], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 3, &BR[9 +2][1][0], src0_row_qhbase[0][1], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); exe(0x03, &r04, r00, 1, BR[9 +2][0][0], 3, BR[9 +1][0][0], 3, 0x00, 0LL, 0x00, 8LL); exe(0x03, &r05, r00, 1, BR[9 +2][0][0], 4, BR[9 +1][0][0], 4, 0x00, 0LL, 0x00, 8LL); exe(0x03, &r06, r00, 1, BR[9 +2][1][0], 3, BR[9 +1][1][0], 3, 0x00, 0LL, 0x00, 8LL); exe(0x03, &r07, r00, 1, BR[9 +2][1][0], 4, BR[9 +1][1][0], 4, 0x00, 0LL, 0x00, 8LL); mop(0x01, 0, &BR[9 +3][0][1], src1_col_base[1][1], (Ull)iofs, 12, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); mop(0x01, 3, &BR[9 +3][0][0], src1_col_base[1][0], (Ull)iofs, 12, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); mop(0x01, 0, &BR[9 +3][1][1], src1_col_base[1][2], (Ull)iofs, 12, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); mop(0x01, 3, &BR[9 +3][1][0], src1_col_base[1][1], (Ull)iofs, 12, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); exe(0x04, &r20, r04, 0, BR[9 +3][0][0], 3, 0LL, 0, 0x06, r24, 0x00, 0LL); exe(0x04, &r21, r05, 0, BR[9 +3][0][0], 4, 0LL, 0, 0x06, r25, 0x00, 0LL); exe(0x04, &r22, r06, 0, BR[9 +3][1][0], 3, 0LL, 0, 0x06, r26, 0x00, 0LL); exe(0x04, &r23, r07, 0, BR[9 +3][1][0], 4, 0LL, 0, 0x06, r27, 0x00, 0LL); mop(0x01, 0, &BR[9 +4][2][1], src0_row_qlbase[1][3], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 3, &BR[9 +4][2][0], src0_row_qlbase[1][2], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 0, &BR[9 +4][3][1], src0_row_qlbase[1][4], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 3, &BR[9 +4][3][0], src0_row_qlbase[1][3], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 0, &BR[9 +5][2][1], src0_row_qhbase[0][3], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 3, &BR[9 +5][2][0], src0_row_qhbase[0][2], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 0, &BR[9 +5][3][1], src0_row_qhbase[0][4], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 3, &BR[9 +5][3][0], src0_row_qhbase[0][3], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); exe(0x03, &r08, r01, 1, BR[9 +5][2][0], 3, BR[9 +4][2][0], 3, 0x00, 0LL, 0x00, 8LL); exe(0x03, &r09, r01, 1, BR[9 +5][2][0], 4, BR[9 +4][2][0], 4, 0x00, 0LL, 0x00, 8LL); exe(0x03, &r10, r01, 1, BR[9 +5][3][0], 3, BR[9 +4][3][0], 3, 0x00, 0LL, 0x00, 8LL); exe(0x03, &r11, r01, 1, BR[9 +5][3][0], 4, BR[9 +4][3][0], 4, 0x00, 0LL, 0x00, 8LL); mop(0x01, 0, &BR[9 +6][2][1], src1_col_base[1][3], (Ull)iofs, 12, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); mop(0x01, 3, &BR[9 +6][2][0], src1_col_base[1][2], (Ull)iofs, 12, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); mop(0x01, 0, &BR[9 +6][3][1], src1_col_base[1][4], (Ull)iofs, 12, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); mop(0x01, 3, &BR[9 +6][3][0], src1_col_base[1][3], (Ull)iofs, 12, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); exe(0x04, &r24, r08, 0, BR[9 +6][2][0], 3, 0LL, 0, 0x06, r20, 0x00, 0LL); exe(0x04, &r25, r09, 0, BR[9 +6][2][0], 4, 0LL, 0, 0x06, r21, 0x00, 0LL); exe(0x04, &r26, r10, 0, BR[9 +6][3][0], 3, 0LL, 0, 0x06, r22, 0x00, 0LL); exe(0x04, &r27, r11, 0, BR[9 +6][3][0], 4, 0LL, 0, 0x06, r23, 0x00, 0LL);
/-EMAX5AS-/
/-EMAX5AS-/
/-EMAX5AS-/ mop(0x04, 3, &BR[16][0][1], src0_row_scbase[4], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x04, 3, &BR[16][2][1], src0_row_scbase[5], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); exe(0x25, &r00, 0LL, 1, 0LL, 1, BR[16][0][1], 1, 0x00, 0LL, 0x02, 8LL); exe(0x25, &r01, 0LL, 1, 0LL, 1, BR[16][2][1], 1, 0x00, 0LL, 0x02, 8LL); mop(0x01, 0, &BR[16 +1][0][1], src0_row_qlbase[0][1], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 3, &BR[16 +1][0][0], src0_row_qlbase[0][0], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 0, &BR[16 +1][1][1], src0_row_qlbase[0][2], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 3, &BR[16 +1][1][0], src0_row_qlbase[0][1], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 0, &BR[16 +2][0][1], src0_row_qhbase[0][1], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 3, &BR[16 +2][0][0], src0_row_qhbase[0][0], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 0, &BR[16 +2][1][1], src0_row_qhbase[0][2], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 3, &BR[16 +2][1][0], src0_row_qhbase[0][1], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); exe(0x03, &r04, r00, 2, BR[16 +2][0][0], 3, BR[16 +1][0][0], 3, 0x00, 0LL, 0x00, 8LL); exe(0x03, &r05, r00, 2, BR[16 +2][0][0], 4, BR[16 +1][0][0], 4, 0x00, 0LL, 0x00, 8LL); exe(0x03, &r06, r00, 2, BR[16 +2][1][0], 3, BR[16 +1][1][0], 3, 0x00, 0LL, 0x00, 8LL); exe(0x03, &r07, r00, 2, BR[16 +2][1][0], 4, BR[16 +1][1][0], 4, 0x00, 0LL, 0x00, 8LL); mop(0x01, 0, &BR[16 +3][0][1], src1_col_base[2][1], (Ull)iofs, 12, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); mop(0x01, 3, &BR[16 +3][0][0], src1_col_base[2][0], (Ull)iofs, 12, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); mop(0x01, 0, &BR[16 +3][1][1], src1_col_base[2][2], (Ull)iofs, 12, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); mop(0x01, 3, &BR[16 +3][1][0], src1_col_base[2][1], (Ull)iofs, 12, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); exe(0x04, &r20, r04, 0, BR[16 +3][0][0], 3, 0LL, 0, 0x06, r24, 0x00, 0LL); exe(0x04, &r21, r05, 0, BR[16 +3][0][0], 4, 0LL, 0, 0x06, r25, 0x00, 0LL); exe(0x04, &r22, r06, 0, BR[16 +3][1][0], 3, 0LL, 0, 0x06, r26, 0x00, 0LL); exe(0x04, &r23, r07, 0, BR[16 +3][1][0], 4, 0LL, 0, 0x06, r27, 0x00, 0LL); mop(0x01, 0, &BR[16 +4][2][1], src0_row_qlbase[0][3], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 3, &BR[16 +4][2][0], src0_row_qlbase[0][2], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 0, &BR[16 +4][3][1], src0_row_qlbase[0][4], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 3, &BR[16 +4][3][0], src0_row_qlbase[0][3], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 0, &BR[16 +5][2][1], src0_row_qhbase[0][3], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 3, &BR[16 +5][2][0], src0_row_qhbase[0][2], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 0, &BR[16 +5][3][1], src0_row_qhbase[0][4], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 3, &BR[16 +5][3][0], src0_row_qhbase[0][3], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); exe(0x03, &r08, r01, 2, BR[16 +5][2][0], 3, BR[16 +4][2][0], 3, 0x00, 0LL, 0x00, 8LL); exe(0x03, &r09, r01, 2, BR[16 +5][2][0], 4, BR[16 +4][2][0], 4, 0x00, 0LL, 0x00, 8LL); exe(0x03, &r10, r01, 2, BR[16 +5][3][0], 3, BR[16 +4][3][0], 3, 0x00, 0LL, 0x00, 8LL); exe(0x03, &r11, r01, 2, BR[16 +5][3][0], 4, BR[16 +4][3][0], 4, 0x00, 0LL, 0x00, 8LL); mop(0x01, 0, &BR[16 +6][2][1], src1_col_base[2][3], (Ull)iofs, 12, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); mop(0x01, 3, &BR[16 +6][2][0], src1_col_base[2][2], (Ull)iofs, 12, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); mop(0x01, 0, &BR[16 +6][3][1], src1_col_base[2][4], (Ull)iofs, 12, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); mop(0x01, 3, &BR[16 +6][3][0], src1_col_base[2][3], (Ull)iofs, 12, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); exe(0x04, &r24, r08, 0, BR[16 +6][2][0], 3, 0LL, 0, 0x06, r20, 0x00, 0LL); exe(0x04, &r25, r09, 0, BR[16 +6][2][0], 4, 0LL, 0, 0x06, r21, 0x00, 0LL); exe(0x04, &r26, r10, 0, BR[16 +6][3][0], 3, 0LL, 0, 0x06, r22, 0x00, 0LL); exe(0x04, &r27, r11, 0, BR[16 +6][3][0], 4, 0LL, 0, 0x06, r23, 0x00, 0LL);
/-EMAX5AS-/
/-EMAX5AS-/
/-EMAX5AS-/ mop(0x04, 3, &BR[23][0][1], src0_row_scbase[6], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x04, 3, &BR[23][2][1], src0_row_scbase[7], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); exe(0x25, &r00, 0LL, 1, 0LL, 1, BR[23][0][1], 1, 0x00, 0LL, 0x02, 8LL); exe(0x25, &r01, 0LL, 1, 0LL, 1, BR[23][2][1], 1, 0x00, 0LL, 0x02, 8LL); mop(0x01, 0, &BR[23 +1][0][1], src0_row_qlbase[1][1], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 3, &BR[23 +1][0][0], src0_row_qlbase[1][0], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 0, &BR[23 +1][1][1], src0_row_qlbase[1][2], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 3, &BR[23 +1][1][0], src0_row_qlbase[1][1], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 0, &BR[23 +2][0][1], src0_row_qhbase[0][1], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 3, &BR[23 +2][0][0], src0_row_qhbase[0][0], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 0, &BR[23 +2][1][1], src0_row_qhbase[0][2], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 3, &BR[23 +2][1][0], src0_row_qhbase[0][1], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); exe(0x03, &r04, r00, 3, BR[23 +2][0][0], 3, BR[23 +1][0][0], 3, 0x00, 0LL, 0x00, 8LL); exe(0x03, &r05, r00, 3, BR[23 +2][0][0], 4, BR[23 +1][0][0], 4, 0x00, 0LL, 0x00, 8LL); exe(0x03, &r06, r00, 3, BR[23 +2][1][0], 3, BR[23 +1][1][0], 3, 0x00, 0LL, 0x00, 8LL); exe(0x03, &r07, r00, 3, BR[23 +2][1][0], 4, BR[23 +1][1][0], 4, 0x00, 0LL, 0x00, 8LL); mop(0x01, 0, &BR[23 +3][0][1], src1_col_base[3][1], (Ull)iofs, 12, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); mop(0x01, 3, &BR[23 +3][0][0], src1_col_base[3][0], (Ull)iofs, 12, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); mop(0x01, 0, &BR[23 +3][1][1], src1_col_base[3][2], (Ull)iofs, 12, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); mop(0x01, 3, &BR[23 +3][1][0], src1_col_base[3][1], (Ull)iofs, 12, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); exe(0x04, &r20, r04, 0, BR[23 +3][0][0], 3, 0LL, 0, 0x06, r24, 0x00, 0LL); exe(0x04, &r21, r05, 0, BR[23 +3][0][0], 4, 0LL, 0, 0x06, r25, 0x00, 0LL); exe(0x04, &r22, r06, 0, BR[23 +3][1][0], 3, 0LL, 0, 0x06, r26, 0x00, 0LL); exe(0x04, &r23, r07, 0, BR[23 +3][1][0], 4, 0LL, 0, 0x06, r27, 0x00, 0LL); mop(0x01, 0, &BR[23 +4][2][1], src0_row_qlbase[1][3], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 3, &BR[23 +4][2][0], src0_row_qlbase[1][2], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 0, &BR[23 +4][3][1], src0_row_qlbase[1][4], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 3, &BR[23 +4][3][0], src0_row_qlbase[1][3], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 0, &BR[23 +5][2][1], src0_row_qhbase[0][3], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 3, &BR[23 +5][2][0], src0_row_qhbase[0][2], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 0, &BR[23 +5][3][1], src0_row_qhbase[0][4], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 3, &BR[23 +5][3][0], src0_row_qhbase[0][3], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); exe(0x03, &r08, r01, 3, BR[23 +5][2][0], 3, BR[23 +4][2][0], 3, 0x00, 0LL, 0x00, 8LL); exe(0x03, &r09, r01, 3, BR[23 +5][2][0], 4, BR[23 +4][2][0], 4, 0x00, 0LL, 0x00, 8LL); exe(0x03, &r10, r01, 3, BR[23 +5][3][0], 3, BR[23 +4][3][0], 3, 0x00, 0LL, 0x00, 8LL); exe(0x03, &r11, r01, 3, BR[23 +5][3][0], 4, BR[23 +4][3][0], 4, 0x00, 0LL, 0x00, 8LL); mop(0x01, 0, &BR[23 +6][2][1], src1_col_base[3][3], (Ull)iofs, 12, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); mop(0x01, 3, &BR[23 +6][2][0], src1_col_base[3][2], (Ull)iofs, 12, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); mop(0x01, 0, &BR[23 +6][3][1], src1_col_base[3][4], (Ull)iofs, 12, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); mop(0x01, 3, &BR[23 +6][3][0], src1_col_base[3][3], (Ull)iofs, 12, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); exe(0x04, &r24, r08, 0, BR[23 +6][2][0], 3, 0LL, 0, 0x06, r20, 0x00, 0LL); exe(0x04, &r25, r09, 0, BR[23 +6][2][0], 4, 0LL, 0, 0x06, r21, 0x00, 0LL); exe(0x04, &r26, r10, 0, BR[23 +6][3][0], 3, 0LL, 0, 0x06, r22, 0x00, 0LL); exe(0x04, &r27, r11, 0, BR[23 +6][3][0], 4, 0LL, 0, 0x06, r23, 0x00, 0LL);
/-EMAX5AS-/
/-EMAX5AS-/
/-EMAX5AS-/ mop(0x04, 3, &BR[30][0][1], src0_row_scbase[8], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x04, 3, &BR[30][2][1], src0_row_scbase[9], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); exe(0x25, &r00, 0LL, 1, 0LL, 1, BR[30][0][1], 1, 0x00, 0LL, 0x02, 8LL); exe(0x25, &r01, 0LL, 1, 0LL, 1, BR[30][2][1], 1, 0x00, 0LL, 0x02, 8LL); mop(0x01, 0, &BR[30 +1][0][1], src0_row_qlbase[2][1], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 3, &BR[30 +1][0][0], src0_row_qlbase[2][0], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 0, &BR[30 +1][1][1], src0_row_qlbase[2][2], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 3, &BR[30 +1][1][0], src0_row_qlbase[2][1], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 0, &BR[30 +2][0][1], src0_row_qhbase[1][1], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 3, &BR[30 +2][0][0], src0_row_qhbase[1][0], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 0, &BR[30 +2][1][1], src0_row_qhbase[1][2], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 3, &BR[30 +2][1][0], src0_row_qhbase[1][1], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); exe(0x03, &r04, r00, 4, BR[30 +2][0][0], 3, BR[30 +1][0][0], 3, 0x00, 0LL, 0x00, 8LL); exe(0x03, &r05, r00, 4, BR[30 +2][0][0], 4, BR[30 +1][0][0], 4, 0x00, 0LL, 0x00, 8LL); exe(0x03, &r06, r00, 4, BR[30 +2][1][0], 3, BR[30 +1][1][0], 3, 0x00, 0LL, 0x00, 8LL); exe(0x03, &r07, r00, 4, BR[30 +2][1][0], 4, BR[30 +1][1][0], 4, 0x00, 0LL, 0x00, 8LL); mop(0x01, 0, &BR[30 +3][0][1], src1_col_base[4][1], (Ull)iofs, 12, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); mop(0x01, 3, &BR[30 +3][0][0], src1_col_base[4][0], (Ull)iofs, 12, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); mop(0x01, 0, &BR[30 +3][1][1], src1_col_base[4][2], (Ull)iofs, 12, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); mop(0x01, 3, &BR[30 +3][1][0], src1_col_base[4][1], (Ull)iofs, 12, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); exe(0x04, &r20, r04, 0, BR[30 +3][0][0], 3, 0LL, 0, 0x06, r24, 0x00, 0LL); exe(0x04, &r21, r05, 0, BR[30 +3][0][0], 4, 0LL, 0, 0x06, r25, 0x00, 0LL); exe(0x04, &r22, r06, 0, BR[30 +3][1][0], 3, 0LL, 0, 0x06, r26, 0x00, 0LL); exe(0x04, &r23, r07, 0, BR[30 +3][1][0], 4, 0LL, 0, 0x06, r27, 0x00, 0LL); mop(0x01, 0, &BR[30 +4][2][1], src0_row_qlbase[2][3], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 3, &BR[30 +4][2][0], src0_row_qlbase[2][2], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 0, &BR[30 +4][3][1], src0_row_qlbase[2][4], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 3, &BR[30 +4][3][0], src0_row_qlbase[2][3], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 0, &BR[30 +5][2][1], src0_row_qhbase[1][3], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 3, &BR[30 +5][2][0], src0_row_qhbase[1][2], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 0, &BR[30 +5][3][1], src0_row_qhbase[1][4], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 3, &BR[30 +5][3][0], src0_row_qhbase[1][3], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); exe(0x03, &r08, r01, 4, BR[30 +5][2][0], 3, BR[30 +4][2][0], 3, 0x00, 0LL, 0x00, 8LL); exe(0x03, &r09, r01, 4, BR[30 +5][2][0], 4, BR[30 +4][2][0], 4, 0x00, 0LL, 0x00, 8LL); exe(0x03, &r10, r01, 4, BR[30 +5][3][0], 3, BR[30 +4][3][0], 3, 0x00, 0LL, 0x00, 8LL); exe(0x03, &r11, r01, 4, BR[30 +5][3][0], 4, BR[30 +4][3][0], 4, 0x00, 0LL, 0x00, 8LL); mop(0x01, 0, &BR[30 +6][2][1], src1_col_base[4][3], (Ull)iofs, 12, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); mop(0x01, 3, &BR[30 +6][2][0], src1_col_base[4][2], (Ull)iofs, 12, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); mop(0x01, 0, &BR[30 +6][3][1], src1_col_base[4][4], (Ull)iofs, 12, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); mop(0x01, 3, &BR[30 +6][3][0], src1_col_base[4][3], (Ull)iofs, 12, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); exe(0x04, &r24, r08, 0, BR[30 +6][2][0], 3, 0LL, 0, 0x06, r20, 0x00, 0LL); exe(0x04, &r25, r09, 0, BR[30 +6][2][0], 4, 0LL, 0, 0x06, r21, 0x00, 0LL); exe(0x04, &r26, r10, 0, BR[30 +6][3][0], 3, 0LL, 0, 0x06, r22, 0x00, 0LL); exe(0x04, &r27, r11, 0, BR[30 +6][3][0], 4, 0LL, 0, 0x06, r23, 0x00, 0LL);
/-EMAX5AS-/
/-EMAX5AS-/
/-EMAX5AS-/ mop(0x04, 3, &BR[37][0][1], src0_row_scbase[10], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x04, 3, &BR[37][2][1], src0_row_scbase[11], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); exe(0x25, &r00, 0LL, 1, 0LL, 1, BR[37][0][1], 1, 0x00, 0LL, 0x02, 8LL); exe(0x25, &r01, 0LL, 1, 0LL, 1, BR[37][2][1], 1, 0x00, 0LL, 0x02, 8LL); mop(0x01, 0, &BR[37 +1][0][1], src0_row_qlbase[3][1], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 3, &BR[37 +1][0][0], src0_row_qlbase[3][0], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 0, &BR[37 +1][1][1], src0_row_qlbase[3][2], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 3, &BR[37 +1][1][0], src0_row_qlbase[3][1], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 0, &BR[37 +2][0][1], src0_row_qhbase[1][1], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 3, &BR[37 +2][0][0], src0_row_qhbase[1][0], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 0, &BR[37 +2][1][1], src0_row_qhbase[1][2], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 3, &BR[37 +2][1][0], src0_row_qhbase[1][1], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); exe(0x03, &r04, r00, 5, BR[37 +2][0][0], 3, BR[37 +1][0][0], 3, 0x00, 0LL, 0x00, 8LL); exe(0x03, &r05, r00, 5, BR[37 +2][0][0], 4, BR[37 +1][0][0], 4, 0x00, 0LL, 0x00, 8LL); exe(0x03, &r06, r00, 5, BR[37 +2][1][0], 3, BR[37 +1][1][0], 3, 0x00, 0LL, 0x00, 8LL); exe(0x03, &r07, r00, 5, BR[37 +2][1][0], 4, BR[37 +1][1][0], 4, 0x00, 0LL, 0x00, 8LL); mop(0x01, 0, &BR[37 +3][0][1], src1_col_base[5][1], (Ull)iofs, 12, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); mop(0x01, 3, &BR[37 +3][0][0], src1_col_base[5][0], (Ull)iofs, 12, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); mop(0x01, 0, &BR[37 +3][1][1], src1_col_base[5][2], (Ull)iofs, 12, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); mop(0x01, 3, &BR[37 +3][1][0], src1_col_base[5][1], (Ull)iofs, 12, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); exe(0x04, &r20, r04, 0, BR[37 +3][0][0], 3, 0LL, 0, 0x06, r24, 0x00, 0LL); exe(0x04, &r21, r05, 0, BR[37 +3][0][0], 4, 0LL, 0, 0x06, r25, 0x00, 0LL); exe(0x04, &r22, r06, 0, BR[37 +3][1][0], 3, 0LL, 0, 0x06, r26, 0x00, 0LL); exe(0x04, &r23, r07, 0, BR[37 +3][1][0], 4, 0LL, 0, 0x06, r27, 0x00, 0LL); mop(0x01, 0, &BR[37 +4][2][1], src0_row_qlbase[3][3], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 3, &BR[37 +4][2][0], src0_row_qlbase[3][2], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 0, &BR[37 +4][3][1], src0_row_qlbase[3][4], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 3, &BR[37 +4][3][0], src0_row_qlbase[3][3], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 0, &BR[37 +5][2][1], src0_row_qhbase[1][3], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 3, &BR[37 +5][2][0], src0_row_qhbase[1][2], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 0, &BR[37 +5][3][1], src0_row_qhbase[1][4], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 3, &BR[37 +5][3][0], src0_row_qhbase[1][3], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); exe(0x03, &r08, r01, 5, BR[37 +5][2][0], 3, BR[37 +4][2][0], 3, 0x00, 0LL, 0x00, 8LL); exe(0x03, &r09, r01, 5, BR[37 +5][2][0], 4, BR[37 +4][2][0], 4, 0x00, 0LL, 0x00, 8LL); exe(0x03, &r10, r01, 5, BR[37 +5][3][0], 3, BR[37 +4][3][0], 3, 0x00, 0LL, 0x00, 8LL); exe(0x03, &r11, r01, 5, BR[37 +5][3][0], 4, BR[37 +4][3][0], 4, 0x00, 0LL, 0x00, 8LL); mop(0x01, 0, &BR[37 +6][2][1], src1_col_base[5][3], (Ull)iofs, 12, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); mop(0x01, 3, &BR[37 +6][2][0], src1_col_base[5][2], (Ull)iofs, 12, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); mop(0x01, 0, &BR[37 +6][3][1], src1_col_base[5][4], (Ull)iofs, 12, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); mop(0x01, 3, &BR[37 +6][3][0], src1_col_base[5][3], (Ull)iofs, 12, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); exe(0x04, &r24, r08, 0, BR[37 +6][2][0], 3, 0LL, 0, 0x06, r20, 0x00, 0LL); exe(0x04, &r25, r09, 0, BR[37 +6][2][0], 4, 0LL, 0, 0x06, r21, 0x00, 0LL); exe(0x04, &r26, r10, 0, BR[37 +6][3][0], 3, 0LL, 0, 0x06, r22, 0x00, 0LL); exe(0x04, &r27, r11, 0, BR[37 +6][3][0], 4, 0LL, 0, 0x06, r23, 0x00, 0LL);
/-EMAX5AS-/
/-EMAX5AS-/
/-EMAX5AS-/ mop(0x04, 3, &BR[44][0][1], src0_row_scbase[12], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x04, 3, &BR[44][2][1], src0_row_scbase[13], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); exe(0x25, &r00, 0LL, 1, 0LL, 1, BR[44][0][1], 1, 0x00, 0LL, 0x02, 8LL); exe(0x25, &r01, 0LL, 1, 0LL, 1, BR[44][2][1], 1, 0x00, 0LL, 0x02, 8LL); mop(0x01, 0, &BR[44 +1][0][1], src0_row_qlbase[2][1], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 3, &BR[44 +1][0][0], src0_row_qlbase[2][0], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 0, &BR[44 +1][1][1], src0_row_qlbase[2][2], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 3, &BR[44 +1][1][0], src0_row_qlbase[2][1], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 0, &BR[44 +2][0][1], src0_row_qhbase[1][1], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 3, &BR[44 +2][0][0], src0_row_qhbase[1][0], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 0, &BR[44 +2][1][1], src0_row_qhbase[1][2], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 3, &BR[44 +2][1][0], src0_row_qhbase[1][1], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); exe(0x03, &r04, r00, 6, BR[44 +2][0][0], 3, BR[44 +1][0][0], 3, 0x00, 0LL, 0x00, 8LL); exe(0x03, &r05, r00, 6, BR[44 +2][0][0], 4, BR[44 +1][0][0], 4, 0x00, 0LL, 0x00, 8LL); exe(0x03, &r06, r00, 6, BR[44 +2][1][0], 3, BR[44 +1][1][0], 3, 0x00, 0LL, 0x00, 8LL); exe(0x03, &r07, r00, 6, BR[44 +2][1][0], 4, BR[44 +1][1][0], 4, 0x00, 0LL, 0x00, 8LL); mop(0x01, 0, &BR[44 +3][0][1], src1_col_base[6][1], (Ull)iofs, 12, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); mop(0x01, 3, &BR[44 +3][0][0], src1_col_base[6][0], (Ull)iofs, 12, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); mop(0x01, 0, &BR[44 +3][1][1], src1_col_base[6][2], (Ull)iofs, 12, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); mop(0x01, 3, &BR[44 +3][1][0], src1_col_base[6][1], (Ull)iofs, 12, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); exe(0x04, &r20, r04, 0, BR[44 +3][0][0], 3, 0LL, 0, 0x06, r24, 0x00, 0LL); exe(0x04, &r21, r05, 0, BR[44 +3][0][0], 4, 0LL, 0, 0x06, r25, 0x00, 0LL); exe(0x04, &r22, r06, 0, BR[44 +3][1][0], 3, 0LL, 0, 0x06, r26, 0x00, 0LL); exe(0x04, &r23, r07, 0, BR[44 +3][1][0], 4, 0LL, 0, 0x06, r27, 0x00, 0LL); mop(0x01, 0, &BR[44 +4][2][1], src0_row_qlbase[2][3], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 3, &BR[44 +4][2][0], src0_row_qlbase[2][2], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 0, &BR[44 +4][3][1], src0_row_qlbase[2][4], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 3, &BR[44 +4][3][0], src0_row_qlbase[2][3], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 0, &BR[44 +5][2][1], src0_row_qhbase[1][3], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 3, &BR[44 +5][2][0], src0_row_qhbase[1][2], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 0, &BR[44 +5][3][1], src0_row_qhbase[1][4], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 3, &BR[44 +5][3][0], src0_row_qhbase[1][3], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); exe(0x03, &r08, r01, 6, BR[44 +5][2][0], 3, BR[44 +4][2][0], 3, 0x00, 0LL, 0x00, 8LL); exe(0x03, &r09, r01, 6, BR[44 +5][2][0], 4, BR[44 +4][2][0], 4, 0x00, 0LL, 0x00, 8LL); exe(0x03, &r10, r01, 6, BR[44 +5][3][0], 3, BR[44 +4][3][0], 3, 0x00, 0LL, 0x00, 8LL); exe(0x03, &r11, r01, 6, BR[44 +5][3][0], 4, BR[44 +4][3][0], 4, 0x00, 0LL, 0x00, 8LL); mop(0x01, 0, &BR[44 +6][2][1], src1_col_base[6][3], (Ull)iofs, 12, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); mop(0x01, 3, &BR[44 +6][2][0], src1_col_base[6][2], (Ull)iofs, 12, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); mop(0x01, 0, &BR[44 +6][3][1], src1_col_base[6][4], (Ull)iofs, 12, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); mop(0x01, 3, &BR[44 +6][3][0], src1_col_base[6][3], (Ull)iofs, 12, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); exe(0x04, &r24, r08, 0, BR[44 +6][2][0], 3, 0LL, 0, 0x06, r20, 0x00, 0LL); exe(0x04, &r25, r09, 0, BR[44 +6][2][0], 4, 0LL, 0, 0x06, r21, 0x00, 0LL); exe(0x04, &r26, r10, 0, BR[44 +6][3][0], 3, 0LL, 0, 0x06, r22, 0x00, 0LL); exe(0x04, &r27, r11, 0, BR[44 +6][3][0], 4, 0LL, 0, 0x06, r23, 0x00, 0LL);
/-EMAX5AS-/
/-EMAX5AS-/
/-EMAX5AS-/ mop(0x04, 3, &BR[51][0][1], src0_row_scbase[14], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x04, 3, &BR[51][2][1], src0_row_scbase[15], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); exe(0x25, &r00, 0LL, 1, 0LL, 1, BR[51][0][1], 1, 0x00, 0LL, 0x02, 8LL); exe(0x25, &r01, 0LL, 1, 0LL, 1, BR[51][2][1], 1, 0x00, 0LL, 0x02, 8LL); mop(0x01, 0, &BR[51 +1][0][1], src0_row_qlbase[3][1], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 3, &BR[51 +1][0][0], src0_row_qlbase[3][0], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 0, &BR[51 +1][1][1], src0_row_qlbase[3][2], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 3, &BR[51 +1][1][0], src0_row_qlbase[3][1], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 0, &BR[51 +2][0][1], src0_row_qhbase[1][1], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 3, &BR[51 +2][0][0], src0_row_qhbase[1][0], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 0, &BR[51 +2][1][1], src0_row_qhbase[1][2], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 3, &BR[51 +2][1][0], src0_row_qhbase[1][1], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); exe(0x03, &r04, r00, 7, BR[51 +2][0][0], 3, BR[51 +1][0][0], 3, 0x00, 0LL, 0x00, 8LL); exe(0x03, &r05, r00, 7, BR[51 +2][0][0], 4, BR[51 +1][0][0], 4, 0x00, 0LL, 0x00, 8LL); exe(0x03, &r06, r00, 7, BR[51 +2][1][0], 3, BR[51 +1][1][0], 3, 0x00, 0LL, 0x00, 8LL); exe(0x03, &r07, r00, 7, BR[51 +2][1][0], 4, BR[51 +1][1][0], 4, 0x00, 0LL, 0x00, 8LL); mop(0x01, 0, &BR[51 +3][0][1], src1_col_base[7][1], (Ull)iofs, 12, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); mop(0x01, 3, &BR[51 +3][0][0], src1_col_base[7][0], (Ull)iofs, 12, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); mop(0x01, 0, &BR[51 +3][1][1], src1_col_base[7][2], (Ull)iofs, 12, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); mop(0x01, 3, &BR[51 +3][1][0], src1_col_base[7][1], (Ull)iofs, 12, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); exe(0x04, &r20, r04, 0, BR[51 +3][0][0], 3, 0LL, 0, 0x06, r24, 0x00, 0LL); exe(0x04, &r21, r05, 0, BR[51 +3][0][0], 4, 0LL, 0, 0x06, r25, 0x00, 0LL); exe(0x04, &r22, r06, 0, BR[51 +3][1][0], 3, 0LL, 0, 0x06, r26, 0x00, 0LL); exe(0x04, &r23, r07, 0, BR[51 +3][1][0], 4, 0LL, 0, 0x06, r27, 0x00, 0LL); mop(0x01, 0, &BR[51 +4][2][1], src0_row_qlbase[3][3], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 3, &BR[51 +4][2][0], src0_row_qlbase[3][2], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 0, &BR[51 +4][3][1], src0_row_qlbase[3][4], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 3, &BR[51 +4][3][0], src0_row_qlbase[3][3], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 0, &BR[51 +5][2][1], src0_row_qhbase[1][3], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 3, &BR[51 +5][2][0], src0_row_qhbase[1][2], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 0, &BR[51 +5][3][1], src0_row_qhbase[1][4], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 3, &BR[51 +5][3][0], src0_row_qhbase[1][3], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); exe(0x03, &r08, r01, 7, BR[51 +5][2][0], 3, BR[51 +4][2][0], 3, 0x00, 0LL, 0x00, 8LL); exe(0x03, &r09, r01, 7, BR[51 +5][2][0], 4, BR[51 +4][2][0], 4, 0x00, 0LL, 0x00, 8LL); exe(0x03, &r10, r01, 7, BR[51 +5][3][0], 3, BR[51 +4][3][0], 3, 0x00, 0LL, 0x00, 8LL); exe(0x03, &r11, r01, 7, BR[51 +5][3][0], 4, BR[51 +4][3][0], 4, 0x00, 0LL, 0x00, 8LL); mop(0x01, 0, &BR[51 +6][2][1], src1_col_base[7][3], (Ull)iofs, 12, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); mop(0x01, 3, &BR[51 +6][2][0], src1_col_base[7][2], (Ull)iofs, 12, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); mop(0x01, 0, &BR[51 +6][3][1], src1_col_base[7][4], (Ull)iofs, 12, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); mop(0x01, 3, &BR[51 +6][3][0], src1_col_base[7][3], (Ull)iofs, 12, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); exe(0x04, &r24, r08, 0, BR[51 +6][2][0], 3, 0LL, 0, 0x06, r20, 0x00, 0LL); exe(0x04, &r25, r09, 0, BR[51 +6][2][0], 4, 0LL, 0, 0x06, r21, 0x00, 0LL); exe(0x04, &r26, r10, 0, BR[51 +6][3][0], 3, 0LL, 0, 0x06, r22, 0x00, 0LL); exe(0x04, &r27, r11, 0, BR[51 +6][3][0], 4, 0LL, 0, 0x06, r23, 0x00, 0LL);
/-EMAX5AS-/
/-EMAX5AS-/
/-EMAX5AS-/ exe(0x00, &r28, r24, 0, 0LL, 0, 0LL, 0, 0x06, r25, 0x00, 0LL);
/-EMAX5AS-/ exe(0x00, &r29, r26, 0, 0LL, 0, 0LL, 0, 0x06, r27, 0x00, 0LL);
/-EMAX5AS-/ mop(0x01, 0, &BR[59][0][1], src0_row_dbase_p8, (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN);
/-EMAX5AS-/ mop(0x01, 3, &BR[59][0][0], src0_row_dbase_p0, (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN);
/-EMAX5AS-/
/-EMAX5AS-/ exe(0x00, &r30, r28, 0, 0LL, 0, 0LL, 0, 0x06, r29, 0x00, 0LL);
/-EMAX5AS-/ exe(0x00, &r13, BR[59][0][0], 0, 0LL, 0, 0LL, 0, 0x01, 0x000000000000ffffLL, 0x01, 2LL);
/-EMAX5AS-/ mop(0x01, 0, &BR[60][0][1], src1_col_dbase_p8, (Ull)iofs, 12, i_m0B[LANE],SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL);
/-EMAX5AS-/ mop(0x01, 3, &BR[60][0][0], src1_col_dbase_p0, (Ull)iofs, 12, i_m0B[LANE],SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL);
/-EMAX5AS-/
/-EMAX5AS-/ exe(0x00, &r31, r30, 2, 0LL, 0, 0LL, 0, 0x06, r30, 0x00, 0LL);
/-EMAX5AS-/ mop(0x02, 3, &BR[61][2][1], (Ull)i_f16[LANE], (Ull)r13, 12, (Ull)i_f16[LANE], 65536, 0, 0, (Ull)((void *)0), 65536);
/-EMAX5AS-/
/-EMAX5AS-/
/-EMAX5AS-/ exe(0x05, &r02, BR[60][0][0], 0, r31, 0, 0LL, 0, 0x00, 0LL, 0x00, 0LL);
/-EMAX5AS-/
/-EMAX5AS-/ exe(0x00, &AR[63][0], 0LL, 0, 0LL, 0, 0LL, 0, 0x00, 0LL, 0x00, 0LL);
/-EMAX5AS-/ mop(0x02, 1, &r00, dst_col, oofs, 12, i_m0C_TOP_IMAP[0][LANE], DST_COL_LEN_TOTdIMAP, 0, Force2, (Ull)((void *)0), DST_COL_LEN_TOTdIMAP);
/-EMAX5AS-/ exe(0x10, &r00, INIT0?r00:r00, 0, r02, 0, BR[61][2][1], 0, 0x00, 0LL, 0x00, 0LL);
/-EMAX5AS-/ mop(0x12, 1, &r00, oofs, dst_col, 14, i_m0C_TOP_IMAP[0][LANE], DST_COL_LEN_TOTdIMAP, 0, Force2, (Ull)((void *)0), DST_COL_LEN_TOTdIMAP);
/-EMAX5AS-/ }
/-EMAX5AS-/ }
/-EMAX5AS-/ }
/-EMAX5AE-/
          if (Force0) Force0 = 0;
          if (Force1) Force1 = 0;
          if (Force2) Force2 = 0;
      }
    }
/-EMAX5AD-/
    monitor_time_start(THREAD, IMAX_CPYOUT_Q6K);
    if (!((Ull)DST_COL_TOP & 63) && !((Ull)i_m0C[LANE] & 63) && DST_COL_LENdIMAP == 16 && 1 == 1) {
      for (int i=0; i<IR1_LOOPS; i++) {
 Dll *dst = (int*)DST_COL_TOP+i*nb1/sizeof(int);
 Dll *src = (int*)i_m0C[LANE]+i*16;
 *dst++ = *src++;
 *dst++ = *src++;
 *dst++ = *src++;
 *dst++ = *src++;
      }
    }
    else
      xmax_cpyout(4, DST_COL_TOP, 1, nb1/sizeof(int), i_m0C[LANE], (Ull)IR1_LOOPS, (Ull)DST_COL_LENdIMAP, 1);
    monitor_time_end(THREAD, IMAX_CPYOUT_Q6K);
  }
}
void imax_compute_forward_mul_mat_one_chunk_q8_0(struct th_inference_args *args)
{
  int THREAD = args->thid;
  int LANE = args->thid;
  struct ggml_tensor * dst = args->dst;
  const int64_t num_rows_per_vec_dot = args->num_rows_per_vec_dot;
  const int64_t ir0_start = args->ir0_start;
  const int64_t ir0_end = args->ir0_end;
  const int64_t ir1_start = args->ir1_start;
  const int64_t ir1_end = args->ir1_end;
  const struct ggml_tensor * src0 = args->src0;
  const struct ggml_tensor * src1 = args->src1;
  const enum ggml_type type = args->type;
  const _Bool src1_cont = args->src1_cont;
  ggml_vec_dot_t const vec_dot = args->vec_dot;
  enum ggml_type const vec_dot_type = args->vec_dot_type;
  const void * wdata = args->wdata;
  const size_t row_size = args->row_size;
  const int64_t r2 = args->r2;
  const int64_t r3 = args->r3;
  const int64_t blck_0 = args->blck_0;
  const int64_t blck_1 = args->blck_1;
  const size_t src1_col_stride = args->src1_col_stride;
  int i, j;
  float tmp[32];
  const int64_t ne00 = (src0) ? (src0)->ne[0] : 0; (void)(ne00); const int64_t ne01 = (src0) ? (src0)->ne[1] : 0; (void)(ne01); const int64_t ne02 = (src0) ? (src0)->ne[2] : 0; (void)(ne02); const int64_t ne03 = (src0) ? (src0)->ne[3] : 0; (void)(ne03); const size_t nb00 = (src0) ? (src0)->nb[0] : 0; (void)(nb00); const size_t nb01 = (src0) ? (src0)->nb[1] : 0; (void)(nb01); const size_t nb02 = (src0) ? (src0)->nb[2] : 0; (void)(nb02); const size_t nb03 = (src0) ? (src0)->nb[3] : 0; (void)(nb03); const int64_t ne10 = (src1) ? (src1)->ne[0] : 0; (void)(ne10); const int64_t ne11 = (src1) ? (src1)->ne[1] : 0; (void)(ne11); const int64_t ne12 = (src1) ? (src1)->ne[2] : 0; (void)(ne12); const int64_t ne13 = (src1) ? (src1)->ne[3] : 0; (void)(ne13); const size_t nb10 = (src1) ? (src1)->nb[0] : 0; (void)(nb10); const size_t nb11 = (src1) ? (src1)->nb[1] : 0; (void)(nb11); const size_t nb12 = (src1) ? (src1)->nb[2] : 0; (void)(nb12); const size_t nb13 = (src1) ? (src1)->nb[3] : 0; (void)(nb13); const int64_t ne0 = (dst) ? (dst)->ne[0] : 0; (void)(ne0); const int64_t ne1 = (dst) ? (dst)->ne[1] : 0; (void)(ne1); const int64_t ne2 = (dst) ? (dst)->ne[2] : 0; (void)(ne2); const int64_t ne3 = (dst) ? (dst)->ne[3] : 0; (void)(ne3); const size_t nb0 = (dst) ? (dst)->nb[0] : 0; (void)(nb0); const size_t nb1 = (dst) ? (dst)->nb[1] : 0; (void)(nb1); const size_t nb2 = (dst) ? (dst)->nb[2] : 0; (void)(nb2); const size_t nb3 = (dst) ? (dst)->nb[3] : 0; (void)(nb3);
  int n = ne00;
  const int nb = n / 32;
  Ull IIR1_LOOPS = (ir1_end-ir1_start)/blck_1;
  Ull IIR0_LOOPS = (ir0_end-ir0_start)/blck_0;
  Ull IR1_LOOPS = ((ir1_start+blck_1) < (ir1_end) ? (ir1_start+blck_1) : (ir1_end))-ir1_start;
  Ull SRC0_ROW_LEN = sizeof(block_q8_0)*nb*blck_0*IIR0_LOOPS/sizeof(int);
  Ull SRC1_COL_LEN = sizeof(block_q8_0)*nb/sizeof(int);
  Ull SRC1_COL_LEN_TOTAL = SRC1_COL_LEN*IR1_LOOPS;
  Ull DST_COL_LEN = blck_0*IIR0_LOOPS;
  Ull DST_COL_LEN_TOTAL = DST_COL_LEN*IR1_LOOPS;
  if (SRC0_ROW_LEN >512*1024/sizeof(int) || ((ir0_end - ir0_start) % blck_0) || num_rows_per_vec_dot != 1) {
    monitor_time_start(THREAD, IMAX_COMPUTE_FORWARD_MUL_MAT_ONE_CHUNK_Q80_ARM);
    for (int64_t iir1 = ir1_start; iir1 < ir1_end; iir1 += blck_1) {
      for (int64_t iir0 = ir0_start; iir0 < ir0_end; iir0 += blck_0) {
 for (int64_t ir1 = iir1; ir1 < iir1 + blck_1 && ir1 < ir1_end; ir1 += num_rows_per_vec_dot) {
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
   for (int64_t ir0 = iir0; ir0 < iir0 + blck_0 && ir0 < ir0_end; ir0 += num_rows_per_vec_dot)
     vec_dot(ne00, &tmp[ir0 - iir0], (num_rows_per_vec_dot > 1 ? 16 : 0), src0_row + ir0 * nb01, (num_rows_per_vec_dot > 1 ? nb01 : 0), src1_col, (num_rows_per_vec_dot > 1 ? src1_col_stride : 0), num_rows_per_vec_dot);
   monitor_time_start(THREAD, ARM_MEMCPY);
   for (int cn = 0; cn < num_rows_per_vec_dot; ++cn)
     memcpy(&dst_col[iir0 + cn * nb1 / nb0], tmp + (cn * 16), (((iir0 + blck_0) < (ir0_end) ? (iir0 + blck_0) : (ir0_end)) - iir0) * sizeof(float));
   monitor_time_end(THREAD, ARM_MEMCPY);
 }
      }
    }
    monitor_time_end(THREAD, IMAX_COMPUTE_FORWARD_MUL_MAT_ONE_CHUNK_Q80_ARM);
  }
  else {
    Ull CHIP, rofs, cofs, iofs, oofs;
    Ull LOOP1, LOOP0;
    Ull INIT1, INIT0;
    Ull AR[64][4];
    Ull BR[64][4][4];
    Ull r00, r01, r02, r03, r04, r05, r06, r07, r08, r09, r10, r11, r12, r13, r14, r15;
    Ull r16, r17, r18, r19, r20, r21, r22, r23, r24, r25, r26, r27, r28, r29, r30, r31;
    Ull cc0, cc1, cc2, cc3, ex0, ex1, out0, out1, out2, out10;
    Ull Force0, Force1, Force2;
    Ull MNB01_M4 = (0LL-nb01 )<<32|((0LL-sizeof(float))&0xffffffffLL);
    Ull MBKQ8_0000 = (0LL-sizeof(block_q8_0))<<32|((0LL-4LL )&0xffffffffLL);
    Ull NB01_4 = (0LL+nb01 )<<32|((0LL+sizeof(float))&0xffffffffLL);
    Ull BKQ8_0000 = (0LL+sizeof(block_q8_0))<<32|((0LL+4LL )&0xffffffffLL);
    const int64_t i13_top = (ir1_start / (ne12 * ne1));
    const int64_t i12_top = (ir1_start - i13_top * ne12 * ne1) / ne1;
    const int64_t i11_top = (ir1_start - i13_top * ne12 * ne1 - i12_top * ne1);
    const int64_t i03_top = i13_top / r3;
    const int64_t i02_top = i12_top / r2;
    Ull SRC0_ROW_TOP = (const char*)src0->data + (0 + i02_top * nb02 + i03_top * nb03) + ir0_start*nb01;
    Ull SRC0_ROW_LENdIMAP = SRC0_ROW_LEN/4;
    Ull i_m0A_TOP = (const char*)i_m0A[LANE] + (0 + i02_top * nb02 + i03_top * nb03) + ir0_start*nb01;
    Ull SRC1_COL_TOP = (const char*)wdata + (src1_cont || src1->type != vec_dot_type ? (i11_top + i12_top * ne11 + i13_top * ne12 * ne11) * row_size
                                                                                            : (i11_top * nb11 + i12_top * nb12 + i13_top * nb13));
    Ull DST_COL_TOP = (float*)((char*)dst->data + (i11_top * nb1 + i12_top * nb2 + i13_top * nb3)) + ir0_start;
    Ull DST_COL_LENdIMAP = DST_COL_LEN/4;
    Ull DST_COL_LEN_TOTdIMAP = DST_COL_LEN_TOTAL/4;
    Ull i_m0C_TOP_IMAP[4][8]; for (i=0; i<4; i++) i_m0C_TOP_IMAP[i][LANE] = (Ull)i_m0C[LANE] + i*sizeof(float)*DST_COL_LEN_TOTdIMAP;
    int ctmp;
    if (src0_preloaded) {
      i_m0A_TOP = i_m0A[0] + (SRC0_ROW_TOP - SRC0_ROW_TOP_DIRECT);
      Force0=1;
    }
    else if (*(Ull*)i_m0A_TOP == *(Ull*)SRC0_ROW_TOP) {
      Force0=0;
    }
    else {
      monitor_time_start(THREAD, IMAX_CPYIN_A_Q80);
      xmax_cpyin(3,i_m0A_TOP, &ctmp,SRC0_ROW_TOP,1,1,SRC0_ROW_LEN,1,1);
      Force0=1;
      monitor_time_end(THREAD, IMAX_CPYIN_A_Q80);
      Ull current_copy_size_bytes = SRC0_ROW_LEN * sizeof(int);
      if (max_SRC0_ROW_LEN_COPY_BYTES <= current_copy_size_bytes) {
        max_SRC0_ROW_LEN_COPY_BYTES = current_copy_size_bytes;
      }
    }
    if (*(Ull*)i_m0B[LANE] == *(Ull*)SRC1_COL_TOP) {
      Force1=0;
    }
    else {
      Force1=1;
      monitor_time_start(THREAD, IMAX_CPYIN_B);
      xmax_cpyin(3,i_m0B[LANE],&ctmp,SRC1_COL_TOP,1,1,SRC1_COL_LEN_TOTAL,1,1);
      monitor_time_end(THREAD, IMAX_CPYIN_B);
      Ull current_copy_size_bytes = SRC1_COL_LEN_TOTAL * sizeof(int);
      if (max_SRC1_COL_LEN_COPY_BYTES <= current_copy_size_bytes) {
        max_SRC1_COL_LEN_COPY_BYTES = current_copy_size_bytes;
      }
    }
    monitor_time_start(THREAD, IMAX_BZERO);
    xmax_bzero(i_m0C[LANE], DST_COL_LEN_TOTAL);
    Force2 = 1;
    monitor_time_end(THREAD, IMAX_BZERO);
    for (int64_t iir1 = ir1_start; iir1 < ir1_end; iir1 += blck_1) {
      for (int64_t ir1 = iir1; ir1 < iir1 + blck_1 && ir1 < ir1_end; ir1 += num_rows_per_vec_dot) {
   const int64_t i13 = (ir1 / (ne12 * ne1));
   const int64_t i12 = (ir1 - i13 * ne12 * ne1) / ne1;
   const int64_t i11 = (ir1 - i13 * ne12 * ne1 - i12 * ne1);
   const int64_t i03 = i13 / r3;
   const int64_t i02 = i12 / r2;
   const int64_t i1 = i11;
   const int64_t i2 = i12;
   const int64_t i3 = i13;
   const int64_t blck_00 = blck_0*IIR0_LOOPS;
   const int64_t blck_00dIMAP = blck_00/4;
   const char * src0_row = (const char*)i_m0A_TOP;
   Ull src0_row_p8[4]; for (i=0; i<4; i++) src0_row_p8[i] = (Ull)src0_row+8+i*sizeof(int)*SRC0_ROW_LENdIMAP;
   Ull src0_row_p0[4]; for (i=0; i<4; i++) src0_row_p0[i] = (Ull)src0_row+0+i*sizeof(int)*SRC0_ROW_LENdIMAP;
   Ull src0_row_base[4][5]; for (i=0; i<4; i++) for (j=0; j<5; j++) src0_row_base[i][j] = (Ull)src0_row+2+i*sizeof(int)*SRC0_ROW_LENdIMAP+j*8;
   const char * src1_col = (const char*)i_m0B[LANE] + (ir1-ir1_start)*sizeof(int)*SRC1_COL_LEN;
   Ull src1_col_p0 = (Ull)src1_col;
   Ull src1_col_p8 = (Ull)src1_col+8;
   Ull src1_col_base[5]; for (j=0; j<5; j++) src1_col_base[j] = (Ull)src1_col+2+j*8;
   float * dst_col = (float*)i_m0C[LANE] + (ir0_start-ir0_start) + (ir1-ir1_start)*DST_COL_LENdIMAP;
   float * dst_col_base[4]; for (i=0; i<4; i++) dst_col_base[i] = (Ull)dst_col+i*sizeof(float)*DST_COL_LEN_TOTdIMAP;
/-EMAX5AB-/ mul_mat_one_chunk_q80 0
/-EMAX5AS-/ for (CHIP=0; CHIP<1; CHIP++) {
/-EMAX5AS-/ for (INIT1=1,LOOP1=""blck_00dIMAP"",rofs=""MNB01_M4""; LOOP1--; INIT1=0) {
/-EMAX5AS-/ for (INIT0=1,LOOP0=""nb"",cofs=""MBKQ8_0000""; LOOP0--; INIT0=0) {
/-EMAX5AS-/ exe(0x17, &rofs, rofs, 0, INIT0?NB01_4:0, 0, 0LL, 0, 0x00, 0LL, 0x00, 0LL);
/-EMAX5AS-/ exe(0x17, &cofs, INIT0?cofs:cofs, 0, BKQ8_0000, 0, 0LL, 0, 0x00, 0LL, 0x00, 0LL);
/-EMAX5AS-/ exe(0x17, &iofs, rofs, 0, cofs, 0, 0LL, 0, 0x01, 0xffffffff00000000LL, 0x00, 0LL);
/-EMAX5AS-/ exe(0x17, &oofs, rofs, 0, 0LL, 0, 0LL, 0, 0x01, 0x00000000ffffffffLL, 0x00, 0LL);
/-EMAX5AS-/
/-EMAX5AS-/
/-EMAX5AS-/
/-EMAX5AS-/
/-EMAX5AS-/
/-EMAX5AS-/
/-EMAX5AS-/ mop(0x01, 0, &BR[2][0][1], src0_row_base[0][1], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 3, &BR[2][0][0], src0_row_base[0][0], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 0, &BR[2][1][1], src0_row_base[0][2], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 3, &BR[2][1][0], src0_row_base[0][1], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 0, &BR[2][2][1], src0_row_base[0][3], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 3, &BR[2][2][0], src0_row_base[0][2], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 0, &BR[2][3][1], src0_row_base[0][4], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 3, &BR[2][3][0], src0_row_base[0][3], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 0, &BR[2 +1][0][1], src1_col_base[1], (Ull)cofs, 13, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); mop(0x01, 3, &BR[2 +1][0][0], src1_col_base[0], (Ull)cofs, 13, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); mop(0x01, 0, &BR[2 +1][1][1], src1_col_base[2], (Ull)cofs, 13, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); mop(0x01, 3, &BR[2 +1][1][0], src1_col_base[1], (Ull)cofs, 13, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); mop(0x01, 0, &BR[2 +1][2][1], src1_col_base[3], (Ull)cofs, 13, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); mop(0x01, 3, &BR[2 +1][2][0], src1_col_base[2], (Ull)cofs, 13, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); mop(0x01, 0, &BR[2 +1][3][1], src1_col_base[4], (Ull)cofs, 13, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); mop(0x01, 3, &BR[2 +1][3][0], src1_col_base[3], (Ull)cofs, 13, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); exe(0x07, &r20, BR[2][0][0], 3, BR[2 +1][0][0], 3, 0LL, 0, 0x00, 0LL, 0x00, 0LL); exe(0x07, &r21, BR[2][1][0], 3, BR[2 +1][1][0], 3, 0LL, 0, 0x00, 0LL, 0x00, 0LL); exe(0x07, &r22, BR[2][2][0], 3, BR[2 +1][2][0], 3, 0LL, 0, 0x00, 0LL, 0x00, 0LL); exe(0x07, &r23, BR[2][3][0], 3, BR[2 +1][3][0], 3, 0LL, 0, 0x00, 0LL, 0x00, 0LL); exe(0x07, &r24, BR[2][0][0], 4, BR[2 +1][0][0], 4, 0LL, 0, 0x06, r20, 0x00, 0LL); exe(0x07, &r25, BR[2][1][0], 4, BR[2 +1][1][0], 4, 0LL, 0, 0x06, r21, 0x00, 0LL); exe(0x07, &r26, BR[2][2][0], 4, BR[2 +1][2][0], 4, 0LL, 0, 0x06, r22, 0x00, 0LL); exe(0x07, &r27, BR[2][3][0], 4, BR[2 +1][3][0], 4, 0LL, 0, 0x06, r23, 0x00, 0LL); exe(0x00, &r28, r24, 0, 0LL, 0, 0LL, 0, 0x06, r25, 0x00, 0LL); exe(0x00, &r29, r26, 0, 0LL, 0, 0LL, 0, 0x06, r27, 0x00, 0LL); mop(0x01, 0, &BR[2 +5][0][1], (Ull)src0_row_p8[0], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 3, &BR[2 +5][0][0], (Ull)src0_row_p0[0], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); exe(0x00, &r30, r28, 0, 0LL, 0, 0LL, 0, 0x06, r29, 0x00, 0LL); mop(0x01, 0, &BR[2 +6][0][1], (Ull)src1_col_p8, (Ull)cofs, 13, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); mop(0x01, 3, &BR[2 +6][0][0], (Ull)src1_col_p0, (Ull)cofs, 13, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); exe(0x00, &r31, r30, 2, 0LL, 0, 0LL, 0, 0x06, r30, 0x04, 5LL); exe(0x00, &r12, r31, 0, 0LL, 0, 0LL, 0, 0x01, 0x000000000000ffffLL, 0x01, 2LL); exe(0x00, &r13, BR[2 +5][0][0], 0, 0LL, 0, 0LL, 0, 0x01, 0x000000000000ffffLL, 0x01, 2LL); exe(0x00, &r14, BR[2 +6][0][0], 0, 0LL, 0, 0LL, 0, 0x01, 0x000000000000ffffLL, 0x01, 2LL); mop(0x02, 3, &BR[2 +8][0][1], (Ull)i_i16[LANE], (Ull)r12, 12, (Ull)i_i16[LANE], 65536, 0, 0, (Ull)((void *)0), 65536); mop(0x02, 3, &BR[2 +8][2][1], (Ull)i_f16[LANE], (Ull)r13, 12, (Ull)i_f16[LANE], 65536, 0, 0, (Ull)((void *)0), 65536); mop(0x02, 3, &BR[2 +8][3][1], (Ull)i_f16[LANE], (Ull)r14, 12, (Ull)i_f16[LANE], 65536, 0, 0, (Ull)((void *)0), 65536); exe(0x12, &r03, BR[2 +8][0][1], 0, 0x42000000LL, 0, 0LL, 0, 0x00, 0LL, 0x00, 0LL); exe(0x12, &r02, BR[2 +8][2][1], 0, BR[2 +8][3][1], 0, 0LL, 0, 0x00, 0LL, 0x00, 0LL); exe(0x00, &AR[2 +10][0], 0LL, 0, 0LL, 0, 0LL, 0, 0x00, 0LL, 0x00, 0LL); mop(0x02, 1, &r00, dst_col_base[0], oofs, 12, i_m0C_TOP_IMAP[0][LANE], DST_COL_LEN_TOTdIMAP, 0, Force2, (Ull)((void *)0), DST_COL_LEN_TOTdIMAP); exe(0x10, &r00, INIT0?r00:r00, 0, r03, 0, r02, 0, 0x00, 0LL, 0x00, 0LL); mop(0x12, 1, &r00, oofs, dst_col_base[0],14, i_m0C_TOP_IMAP[0][LANE], DST_COL_LEN_TOTdIMAP, 0, Force2, (Ull)((void *)0), DST_COL_LEN_TOTdIMAP);
/-EMAX5AS-/
/-EMAX5AS-/ mop(0x01, 0, &BR[13][0][1], src0_row_base[1][1], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 3, &BR[13][0][0], src0_row_base[1][0], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 0, &BR[13][1][1], src0_row_base[1][2], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 3, &BR[13][1][0], src0_row_base[1][1], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 0, &BR[13][2][1], src0_row_base[1][3], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 3, &BR[13][2][0], src0_row_base[1][2], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 0, &BR[13][3][1], src0_row_base[1][4], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 3, &BR[13][3][0], src0_row_base[1][3], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 0, &BR[13 +1][0][1], src1_col_base[1], (Ull)cofs, 13, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); mop(0x01, 3, &BR[13 +1][0][0], src1_col_base[0], (Ull)cofs, 13, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); mop(0x01, 0, &BR[13 +1][1][1], src1_col_base[2], (Ull)cofs, 13, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); mop(0x01, 3, &BR[13 +1][1][0], src1_col_base[1], (Ull)cofs, 13, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); mop(0x01, 0, &BR[13 +1][2][1], src1_col_base[3], (Ull)cofs, 13, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); mop(0x01, 3, &BR[13 +1][2][0], src1_col_base[2], (Ull)cofs, 13, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); mop(0x01, 0, &BR[13 +1][3][1], src1_col_base[4], (Ull)cofs, 13, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); mop(0x01, 3, &BR[13 +1][3][0], src1_col_base[3], (Ull)cofs, 13, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); exe(0x07, &r20, BR[13][0][0], 3, BR[13 +1][0][0], 3, 0LL, 0, 0x00, 0LL, 0x00, 0LL); exe(0x07, &r21, BR[13][1][0], 3, BR[13 +1][1][0], 3, 0LL, 0, 0x00, 0LL, 0x00, 0LL); exe(0x07, &r22, BR[13][2][0], 3, BR[13 +1][2][0], 3, 0LL, 0, 0x00, 0LL, 0x00, 0LL); exe(0x07, &r23, BR[13][3][0], 3, BR[13 +1][3][0], 3, 0LL, 0, 0x00, 0LL, 0x00, 0LL); exe(0x07, &r24, BR[13][0][0], 4, BR[13 +1][0][0], 4, 0LL, 0, 0x06, r20, 0x00, 0LL); exe(0x07, &r25, BR[13][1][0], 4, BR[13 +1][1][0], 4, 0LL, 0, 0x06, r21, 0x00, 0LL); exe(0x07, &r26, BR[13][2][0], 4, BR[13 +1][2][0], 4, 0LL, 0, 0x06, r22, 0x00, 0LL); exe(0x07, &r27, BR[13][3][0], 4, BR[13 +1][3][0], 4, 0LL, 0, 0x06, r23, 0x00, 0LL); exe(0x00, &r28, r24, 0, 0LL, 0, 0LL, 0, 0x06, r25, 0x00, 0LL); exe(0x00, &r29, r26, 0, 0LL, 0, 0LL, 0, 0x06, r27, 0x00, 0LL); mop(0x01, 0, &BR[13 +5][0][1], (Ull)src0_row_p8[1], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 3, &BR[13 +5][0][0], (Ull)src0_row_p0[1], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); exe(0x00, &r30, r28, 0, 0LL, 0, 0LL, 0, 0x06, r29, 0x00, 0LL); mop(0x01, 0, &BR[13 +6][0][1], (Ull)src1_col_p8, (Ull)cofs, 13, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); mop(0x01, 3, &BR[13 +6][0][0], (Ull)src1_col_p0, (Ull)cofs, 13, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); exe(0x00, &r31, r30, 2, 0LL, 0, 0LL, 0, 0x06, r30, 0x04, 5LL); exe(0x00, &r12, r31, 0, 0LL, 0, 0LL, 0, 0x01, 0x000000000000ffffLL, 0x01, 2LL); exe(0x00, &r13, BR[13 +5][0][0], 0, 0LL, 0, 0LL, 0, 0x01, 0x000000000000ffffLL, 0x01, 2LL); exe(0x00, &r14, BR[13 +6][0][0], 0, 0LL, 0, 0LL, 0, 0x01, 0x000000000000ffffLL, 0x01, 2LL); mop(0x02, 3, &BR[13 +8][0][1], (Ull)i_i16[LANE], (Ull)r12, 12, (Ull)i_i16[LANE], 65536, 0, 0, (Ull)((void *)0), 65536); mop(0x02, 3, &BR[13 +8][2][1], (Ull)i_f16[LANE], (Ull)r13, 12, (Ull)i_f16[LANE], 65536, 0, 0, (Ull)((void *)0), 65536); mop(0x02, 3, &BR[13 +8][3][1], (Ull)i_f16[LANE], (Ull)r14, 12, (Ull)i_f16[LANE], 65536, 0, 0, (Ull)((void *)0), 65536); exe(0x12, &r03, BR[13 +8][0][1], 0, 0x42000000LL, 0, 0LL, 0, 0x00, 0LL, 0x00, 0LL); exe(0x12, &r02, BR[13 +8][2][1], 0, BR[13 +8][3][1], 0, 0LL, 0, 0x00, 0LL, 0x00, 0LL); exe(0x00, &AR[13 +10][0], 0LL, 0, 0LL, 0, 0LL, 0, 0x00, 0LL, 0x00, 0LL); mop(0x02, 1, &r00, dst_col_base[1], oofs, 12, i_m0C_TOP_IMAP[1][LANE], DST_COL_LEN_TOTdIMAP, 0, Force2, (Ull)((void *)0), DST_COL_LEN_TOTdIMAP); exe(0x10, &r00, INIT0?r00:r00, 0, r03, 0, r02, 0, 0x00, 0LL, 0x00, 0LL); mop(0x12, 1, &r00, oofs, dst_col_base[1],14, i_m0C_TOP_IMAP[1][LANE], DST_COL_LEN_TOTdIMAP, 0, Force2, (Ull)((void *)0), DST_COL_LEN_TOTdIMAP);
/-EMAX5AS-/
/-EMAX5AS-/ mop(0x01, 0, &BR[24][0][1], src0_row_base[2][1], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 3, &BR[24][0][0], src0_row_base[2][0], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 0, &BR[24][1][1], src0_row_base[2][2], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 3, &BR[24][1][0], src0_row_base[2][1], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 0, &BR[24][2][1], src0_row_base[2][3], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 3, &BR[24][2][0], src0_row_base[2][2], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 0, &BR[24][3][1], src0_row_base[2][4], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 3, &BR[24][3][0], src0_row_base[2][3], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 0, &BR[24 +1][0][1], src1_col_base[1], (Ull)cofs, 13, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); mop(0x01, 3, &BR[24 +1][0][0], src1_col_base[0], (Ull)cofs, 13, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); mop(0x01, 0, &BR[24 +1][1][1], src1_col_base[2], (Ull)cofs, 13, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); mop(0x01, 3, &BR[24 +1][1][0], src1_col_base[1], (Ull)cofs, 13, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); mop(0x01, 0, &BR[24 +1][2][1], src1_col_base[3], (Ull)cofs, 13, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); mop(0x01, 3, &BR[24 +1][2][0], src1_col_base[2], (Ull)cofs, 13, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); mop(0x01, 0, &BR[24 +1][3][1], src1_col_base[4], (Ull)cofs, 13, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); mop(0x01, 3, &BR[24 +1][3][0], src1_col_base[3], (Ull)cofs, 13, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); exe(0x07, &r20, BR[24][0][0], 3, BR[24 +1][0][0], 3, 0LL, 0, 0x00, 0LL, 0x00, 0LL); exe(0x07, &r21, BR[24][1][0], 3, BR[24 +1][1][0], 3, 0LL, 0, 0x00, 0LL, 0x00, 0LL); exe(0x07, &r22, BR[24][2][0], 3, BR[24 +1][2][0], 3, 0LL, 0, 0x00, 0LL, 0x00, 0LL); exe(0x07, &r23, BR[24][3][0], 3, BR[24 +1][3][0], 3, 0LL, 0, 0x00, 0LL, 0x00, 0LL); exe(0x07, &r24, BR[24][0][0], 4, BR[24 +1][0][0], 4, 0LL, 0, 0x06, r20, 0x00, 0LL); exe(0x07, &r25, BR[24][1][0], 4, BR[24 +1][1][0], 4, 0LL, 0, 0x06, r21, 0x00, 0LL); exe(0x07, &r26, BR[24][2][0], 4, BR[24 +1][2][0], 4, 0LL, 0, 0x06, r22, 0x00, 0LL); exe(0x07, &r27, BR[24][3][0], 4, BR[24 +1][3][0], 4, 0LL, 0, 0x06, r23, 0x00, 0LL); exe(0x00, &r28, r24, 0, 0LL, 0, 0LL, 0, 0x06, r25, 0x00, 0LL); exe(0x00, &r29, r26, 0, 0LL, 0, 0LL, 0, 0x06, r27, 0x00, 0LL); mop(0x01, 0, &BR[24 +5][0][1], (Ull)src0_row_p8[2], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 3, &BR[24 +5][0][0], (Ull)src0_row_p0[2], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); exe(0x00, &r30, r28, 0, 0LL, 0, 0LL, 0, 0x06, r29, 0x00, 0LL); mop(0x01, 0, &BR[24 +6][0][1], (Ull)src1_col_p8, (Ull)cofs, 13, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); mop(0x01, 3, &BR[24 +6][0][0], (Ull)src1_col_p0, (Ull)cofs, 13, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); exe(0x00, &r31, r30, 2, 0LL, 0, 0LL, 0, 0x06, r30, 0x04, 5LL); exe(0x00, &r12, r31, 0, 0LL, 0, 0LL, 0, 0x01, 0x000000000000ffffLL, 0x01, 2LL); exe(0x00, &r13, BR[24 +5][0][0], 0, 0LL, 0, 0LL, 0, 0x01, 0x000000000000ffffLL, 0x01, 2LL); exe(0x00, &r14, BR[24 +6][0][0], 0, 0LL, 0, 0LL, 0, 0x01, 0x000000000000ffffLL, 0x01, 2LL); mop(0x02, 3, &BR[24 +8][0][1], (Ull)i_i16[LANE], (Ull)r12, 12, (Ull)i_i16[LANE], 65536, 0, 0, (Ull)((void *)0), 65536); mop(0x02, 3, &BR[24 +8][2][1], (Ull)i_f16[LANE], (Ull)r13, 12, (Ull)i_f16[LANE], 65536, 0, 0, (Ull)((void *)0), 65536); mop(0x02, 3, &BR[24 +8][3][1], (Ull)i_f16[LANE], (Ull)r14, 12, (Ull)i_f16[LANE], 65536, 0, 0, (Ull)((void *)0), 65536); exe(0x12, &r03, BR[24 +8][0][1], 0, 0x42000000LL, 0, 0LL, 0, 0x00, 0LL, 0x00, 0LL); exe(0x12, &r02, BR[24 +8][2][1], 0, BR[24 +8][3][1], 0, 0LL, 0, 0x00, 0LL, 0x00, 0LL); exe(0x00, &AR[24 +10][0], 0LL, 0, 0LL, 0, 0LL, 0, 0x00, 0LL, 0x00, 0LL); mop(0x02, 1, &r00, dst_col_base[2], oofs, 12, i_m0C_TOP_IMAP[2][LANE], DST_COL_LEN_TOTdIMAP, 0, Force2, (Ull)((void *)0), DST_COL_LEN_TOTdIMAP); exe(0x10, &r00, INIT0?r00:r00, 0, r03, 0, r02, 0, 0x00, 0LL, 0x00, 0LL); mop(0x12, 1, &r00, oofs, dst_col_base[2],14, i_m0C_TOP_IMAP[2][LANE], DST_COL_LEN_TOTdIMAP, 0, Force2, (Ull)((void *)0), DST_COL_LEN_TOTdIMAP);
/-EMAX5AS-/
/-EMAX5AS-/ mop(0x01, 0, &BR[35][0][1], src0_row_base[3][1], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 3, &BR[35][0][0], src0_row_base[3][0], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 0, &BR[35][1][1], src0_row_base[3][2], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 3, &BR[35][1][0], src0_row_base[3][1], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 0, &BR[35][2][1], src0_row_base[3][3], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 3, &BR[35][2][0], src0_row_base[3][2], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 0, &BR[35][3][1], src0_row_base[3][4], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 3, &BR[35][3][0], src0_row_base[3][3], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 0, &BR[35 +1][0][1], src1_col_base[1], (Ull)cofs, 13, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); mop(0x01, 3, &BR[35 +1][0][0], src1_col_base[0], (Ull)cofs, 13, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); mop(0x01, 0, &BR[35 +1][1][1], src1_col_base[2], (Ull)cofs, 13, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); mop(0x01, 3, &BR[35 +1][1][0], src1_col_base[1], (Ull)cofs, 13, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); mop(0x01, 0, &BR[35 +1][2][1], src1_col_base[3], (Ull)cofs, 13, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); mop(0x01, 3, &BR[35 +1][2][0], src1_col_base[2], (Ull)cofs, 13, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); mop(0x01, 0, &BR[35 +1][3][1], src1_col_base[4], (Ull)cofs, 13, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); mop(0x01, 3, &BR[35 +1][3][0], src1_col_base[3], (Ull)cofs, 13, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); exe(0x07, &r20, BR[35][0][0], 3, BR[35 +1][0][0], 3, 0LL, 0, 0x00, 0LL, 0x00, 0LL); exe(0x07, &r21, BR[35][1][0], 3, BR[35 +1][1][0], 3, 0LL, 0, 0x00, 0LL, 0x00, 0LL); exe(0x07, &r22, BR[35][2][0], 3, BR[35 +1][2][0], 3, 0LL, 0, 0x00, 0LL, 0x00, 0LL); exe(0x07, &r23, BR[35][3][0], 3, BR[35 +1][3][0], 3, 0LL, 0, 0x00, 0LL, 0x00, 0LL); exe(0x07, &r24, BR[35][0][0], 4, BR[35 +1][0][0], 4, 0LL, 0, 0x06, r20, 0x00, 0LL); exe(0x07, &r25, BR[35][1][0], 4, BR[35 +1][1][0], 4, 0LL, 0, 0x06, r21, 0x00, 0LL); exe(0x07, &r26, BR[35][2][0], 4, BR[35 +1][2][0], 4, 0LL, 0, 0x06, r22, 0x00, 0LL); exe(0x07, &r27, BR[35][3][0], 4, BR[35 +1][3][0], 4, 0LL, 0, 0x06, r23, 0x00, 0LL); exe(0x00, &r28, r24, 0, 0LL, 0, 0LL, 0, 0x06, r25, 0x00, 0LL); exe(0x00, &r29, r26, 0, 0LL, 0, 0LL, 0, 0x06, r27, 0x00, 0LL); mop(0x01, 0, &BR[35 +5][0][1], (Ull)src0_row_p8[3], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); mop(0x01, 3, &BR[35 +5][0][0], (Ull)src0_row_p0[3], (Ull)iofs, 13, i_m0A_TOP, SRC0_ROW_LEN, 0, Force0, (Ull)((void *)0), SRC0_ROW_LEN); exe(0x00, &r30, r28, 0, 0LL, 0, 0LL, 0, 0x06, r29, 0x00, 0LL); mop(0x01, 0, &BR[35 +6][0][1], (Ull)src1_col_p8, (Ull)cofs, 13, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); mop(0x01, 3, &BR[35 +6][0][0], (Ull)src1_col_p0, (Ull)cofs, 13, i_m0B[LANE], SRC1_COL_LEN_TOTAL, 0, Force1, (Ull)((void *)0), SRC1_COL_LEN_TOTAL); exe(0x00, &r31, r30, 2, 0LL, 0, 0LL, 0, 0x06, r30, 0x04, 5LL); exe(0x00, &r12, r31, 0, 0LL, 0, 0LL, 0, 0x01, 0x000000000000ffffLL, 0x01, 2LL); exe(0x00, &r13, BR[35 +5][0][0], 0, 0LL, 0, 0LL, 0, 0x01, 0x000000000000ffffLL, 0x01, 2LL); exe(0x00, &r14, BR[35 +6][0][0], 0, 0LL, 0, 0LL, 0, 0x01, 0x000000000000ffffLL, 0x01, 2LL); mop(0x02, 3, &BR[35 +8][0][1], (Ull)i_i16[LANE], (Ull)r12, 12, (Ull)i_i16[LANE], 65536, 0, 0, (Ull)((void *)0), 65536); mop(0x02, 3, &BR[35 +8][2][1], (Ull)i_f16[LANE], (Ull)r13, 12, (Ull)i_f16[LANE], 65536, 0, 0, (Ull)((void *)0), 65536); mop(0x02, 3, &BR[35 +8][3][1], (Ull)i_f16[LANE], (Ull)r14, 12, (Ull)i_f16[LANE], 65536, 0, 0, (Ull)((void *)0), 65536); exe(0x12, &r03, BR[35 +8][0][1], 0, 0x42000000LL, 0, 0LL, 0, 0x00, 0LL, 0x00, 0LL); exe(0x12, &r02, BR[35 +8][2][1], 0, BR[35 +8][3][1], 0, 0LL, 0, 0x00, 0LL, 0x00, 0LL); exe(0x00, &AR[35 +10][0], 0LL, 0, 0LL, 0, 0LL, 0, 0x00, 0LL, 0x00, 0LL); mop(0x02, 1, &r00, dst_col_base[3], oofs, 12, i_m0C_TOP_IMAP[3][LANE], DST_COL_LEN_TOTdIMAP, 0, Force2, (Ull)((void *)0), DST_COL_LEN_TOTdIMAP); exe(0x10, &r00, INIT0?r00:r00, 0, r03, 0, r02, 0, 0x00, 0LL, 0x00, 0LL); mop(0x12, 1, &r00, oofs, dst_col_base[3],14, i_m0C_TOP_IMAP[3][LANE], DST_COL_LEN_TOTdIMAP, 0, Force2, (Ull)((void *)0), DST_COL_LEN_TOTdIMAP);
/-EMAX5AS-/ }
/-EMAX5AS-/ }
/-EMAX5AS-/ }
/-EMAX5AS-/
/-EMAX5AE-/
          if (Force0) Force0 = 0;
          if (Force1) Force1 = 0;
          if (Force2) Force2 = 0;
      }
    }
/-EMAX5AD-/
    monitor_time_start(THREAD, IMAX_CPYOUT);
    xmax_cpyout(4, DST_COL_TOP, 1, nb1/sizeof(int), i_m0C[LANE], IR1_LOOPS, DST_COL_LENdIMAP, 4);
    monitor_time_end(THREAD, IMAX_CPYOUT);
    TOTAL_BUFFER_DRAIN_SIZE += DST_COL_LEN_TOTAL*sizeof(int);
  }
}
void get_show_nanosec(int LANE)
{
  printf("\n");
  show_nanosec(LANE);
}
void get_show_dma_size(void)
{
}
