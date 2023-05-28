#include <features.h>
#include "libc.h"

// defines for c-source crt_arch.h
#define START_FUNC _start
#define START_FUNC_C _start_c

// defines for inline-asm crt_arch.h
#define START "_start"

#include "crt_arch.h"

int main();
weak void _init();
weak void _fini();
int __libc_start_main(int (*)(), int, char **,
	void (*)(), void(*)(), void(*)());

hidden void _start_c(size_t *p, size_t const * /*dynamic*/) // should be identical to _dlstart_c by prototype
{
	int argc = p[0];
	char **argv = (void *)(p+1);
	__libc_start_main(main, argc, argv, _init, _fini, 0);
}
