#define ___SKINNY_LOOP
#define ___NUM_OF_ROUNDS_56
#if (defined(__riscv_xlen) && (__riscv_xlen == 64))
#define ___ENABLE_DWORD_CAST
#endif

#include <stdint.h>

typedef struct ___skinny_ctrl {
#ifdef ___NUM_OF_ROUNDS_56
    unsigned char roundKeys[960]; // number of rounds : 56
#else
    unsigned char roundKeys[704]; // number of rounds : 40
#endif
    void (*func_skinny_128_384_enc)(unsigned char*, struct ___skinny_ctrl*, unsigned char* CNT, unsigned char* T, const unsigned char* K);
} skinny_ctrl;

extern void skinny_128_384_enc123_12 (unsigned char* input, skinny_ctrl* pskinny_ctrl, unsigned char* CNT, unsigned char* T, const unsigned char* K);
extern void skinny_128_384_enc12_12 (unsigned char* input, skinny_ctrl* pskinny_ctrl, unsigned char* CNT, unsigned char* T, const unsigned char* K);
extern void skinny_128_384_enc1_1 (unsigned char* input, skinny_ctrl* pskinny_ctrl, unsigned char* CNT, unsigned char* T, const unsigned char* K);

#define pack_word(x0, x1, x2, x3, w)    \
  w  = ((x3) << 24) ^                   \
       ((x2) << 16) ^                   \
       ((x1) << 8) ^                    \
       (x0);

#define unpack_word(x0, x1, x2, x3, w)  \
  x0  = ((w) & 0xff);                   \
  x1  = (((w) >> 8) & 0xff);            \
  x2  = (((w) >> 16) & 0xff);           \
  x3  = ((w) >> 24);

#ifdef ___ENABLE_DWORD_CAST

#define PERMUTATION()                                                             \
/* permutation */                                                                 \
                                                                                  \
  /* 7 6 5 4 3 2 1 0 */                                                           \
  /* 5 7 2 3 6 0 4 1 */                                                           \
                                                                                  \
  /* dw (7 6 5 4 3 2 1 0) */                                                      \
                                                                                  \
  /* dw (5 7 2 3 6 0 4 1) */                                                      \
                                                                                  \
  dt0 = dw >> 24;                 /* - - - 7 6 5 4 3 */                           \
  dt0 = dt0 & 0x00000000ff00ff00; /* - - - - 6 - 4 - */                           \
                                                                                  \
  dt1 = dw << 16;                 /* 5 4 3 2 1 0 - - */                           \
  dt1 = dt1 & 0xff00000000ff0000; /* 5 - - - - 0 - - */                           \
  dt0 = dt0 ^ dt1;                /* 5 - - - 6 0 4 - */                           \
                                                                                  \
  dt1 = dw >> 8;                  /* - 7 6 5 4 3 2 1 */                           \
  dt1 = dt1 & 0x00ff0000000000ff; /* - 7 - - - - - 1 */                           \
  dt0 = dt0 ^ dt1;                /* 5 7 - - 6 0 4 1 */                           \
                                                                                  \
  dt1 = dw << 8;                  /* 6 5 4 3 2 1 0 - */                           \
  dt1 = dt1 & 0x000000ff00000000; /* - - - 3 - - - - */                           \
  dt0 = dt0 ^ dt1;                /* 5 7 - 3 6 0 4 1 */                           \
                                                                                  \
  dt1 = dw << 24;                 /* 4 3 2 1 0 - - - */                           \
  dw  = dt1 & 0x0000ff0000000000; /* - - 2 - - - - - */                           \
  dw  = dw  ^ dt0;                /* 5 7 2 3 6 0 4 1 */

#else

#define PERMUTATION()                                                             \
/* permutation */                                                                 \
                                                                                  \
  /* 7 6 5 4 3 2 1 0 */                                                           \
  /* 5 7 2 3 6 0 4 1 */                                                           \
                                                                                  \
  /* w0 (3 2 1 0) */                                                              \
  /* w1 (7 6 5 4) */                                                              \
                                                                                  \
  /* w0 (6 0 4 1) */                                                              \
  /* w1 (5 7 2 3) */                                                              \
                                                                                  \
  t0 = w1 << 8;         /* 6 5 4 - */                                             \
  t0 = t0 & 0xff00ff00; /* 6 - 4 - */                                             \
                                                                                  \
  t1 = w1 << 16;        /* 5 4 - - */                                             \
  t1 = t1 & 0xff000000; /* 5 - - - */                                             \
                                                                                  \
  t2 = w1 & 0xff000000; /* 7 - - - */                                             \
  t2 = t2 >> 8;         /* - 7 - - */                                             \
  t1 = t1 ^ t2;         /* 5 7 - - */                                             \
                                                                                  \
  t2 = w0 & 0xff000000; /* 3 - - - */                                             \
  t2 = t2 >> 24;        /* - - - 3 */                                             \
  t1 = t1 ^ t2;         /* 5 7 - 3 */                                             \
                                                                                  \
  w1 = w0 >> 8;         /* - 3 2 1 */                                             \
  w1 = w1 & 0x0000ff00; /* - - 2 - */                                             \
  w1 = w1 ^ t1;         /* 5 7 2 3 */                                             \
                                                                                  \
  t2 = w0 & 0x0000ff00; /* - - 1 - */                                             \
  t2 = t2 >> 8;         /* - - - 1 */                                             \
  t0 = t0 ^ t2;         /* 6 - 4 1 */                                             \
                                                                                  \
  w0 = w0 << 16;        /* 1 0 - - */                                             \
  w0 = w0 & 0x00ff0000; /* - 0 - - */                                             \
  w0 = w0 ^ t0;         /* 6 0 4 1 */ 

#endif

