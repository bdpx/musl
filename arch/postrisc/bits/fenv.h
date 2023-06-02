#define FE_INVALID    0x0100
#define FE_DENORM     0x0200
#define FE_DIVBYZERO  0x0400
#define FE_OVERFLOW   0x0800
#define FE_UNDERFLOW  0x1000
#define FE_INEXACT    0x2000

#define FE_ALL_EXCEPT 0x3f00

#define FE_TONEAREST          __POSTRISC_RM_RNE
#define FE_TOWARDZERO         __POSTRISC_RM_RTZ
#define FE_DOWNWARD           __POSTRISC_RM_RDN
#define FE_UPWARD             __POSTRISC_RM_RUP
#define FE_TONEARESTFROMZERO  __POSTRISC_RM_RMM

typedef unsigned fexcept_t;
typedef unsigned fenv_t;

#define FE_DFL_ENV      ((const fenv_t *) -1)
