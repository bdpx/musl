#define FE_INVALID    0x0100
#define FE_DENORM     0x0200
#define FE_DIVBYZERO  0x0400
#define FE_OVERFLOW   0x0800
#define FE_UNDERFLOW  0x1000
#define FE_INEXACT    0x2000

#define FE_ALL_EXCEPT 0x3f00

#define FE_TONEAREST          0
#define FE_TOWARDZERO         1
#define FE_DOWNWARD           2
#define FE_UPWARD             3
#define FE_TONEARESTFROMZERO  4

typedef unsigned fexcept_t;
typedef unsigned fenv_t;

#define FE_DFL_ENV      ((const fenv_t *) -1)
