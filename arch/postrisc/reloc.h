#define LDSO_ARCH "postrisc"

// sync with llvm/include/llvm/BinaryFormat/ELFRelocs/Postrisc.def
#define R_POSTRISC_64                           4
#define R_POSTRISC_COPY                         5
#define R_POSTRISC_JMP_SLOT                     6
#define R_POSTRISC_RELATIVE                     7
#define R_POSTRISC_DISP8                        8
#define R_POSTRISC_DISP16                       9
#define R_POSTRISC_DISP32                      10
#define R_POSTRISC_DISP64                      11
#define R_POSTRISC_GLOB_DAT                    12
#define R_POSTRISC_PLT64                       13
#define R_POSTRISC_R_DISP32                    14
#define R_POSTRISC_PC32                        15
#define R_POSTRISC_DTPMOD64                    16
#define R_POSTRISC_DTPOFF64                    17
#define R_POSTRISC_TPOFF64                     18
#define R_POSTRISC_TLSDESC                     19

#define REL_SYMBOLIC    R_POSTRISC_64
#define REL_OFFSET32    R_POSTRISC_PC32
#define REL_GOT         R_POSTRISC_GLOB_DAT
#define REL_PLT         R_POSTRISC_JMP_SLOT
#define REL_RELATIVE    R_POSTRISC_RELATIVE
#define REL_COPY        R_POSTRISC_COPY
#define REL_DTPMOD      R_POSTRISC_DTPMOD64
#define REL_DTPOFF      R_POSTRISC_DTPOFF64
#define REL_TPOFF       R_POSTRISC_TPOFF64
#define REL_TLSDESC     R_POSTRISC_TLSDESC

/* FIXME!
#define CRTJMP(pc,sp) __asm__ __volatile__( \
	"mov %1,%%rsp ; jmp *%0" : : "r"(pc), "r"(sp) : "memory" )
*/

#define CRTJMP(pc,sp)

/* FIXME!
#define GETFUNCSYM(fp, sym, got) __asm__ ( \
	".hidden " #sym "\n" \
	"	lea " #sym "(%%rip),%0\n" \
	: "=r"(*fp) : : "memory" )
*/

#define GETFUNCSYM(fp, sym, got) *fp = &sym
