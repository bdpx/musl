#define _BSD_SOURCE
#include <string.h>

void explicit_bzero(void *d, size_t n)
{
	d = memset(d, 0, n);
#if defined(__POSTRISC__)
	__atomic_thread_fence(__ATOMIC_SEQ_CST);
#else
	__asm__ __volatile__ ("" : : "r"(d) : "memory");
#endif
}
