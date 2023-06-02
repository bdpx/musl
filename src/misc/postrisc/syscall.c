#define _BSD_SOURCE
#include <unistd.h>
#include <stdarg.h>
#include <features.h>
#include "syscall.h"
#include "syscall_arch.h"

#undef syscall

long __syscall_postrisc(long n, long a1, long a2, long a3, long a4, long a5, long a6) __attribute((noinline))
{
    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    // n in r1 will be replaced to result value
    __builtin_postrisc_syscall();
    return n;
}

long (syscall)(long n, ...)
{
    syscall_arg_t a,b,c,d,e,f;
    va_list ap;
    va_start(ap, n);
    a = va_arg(ap, syscall_arg_t);
    b = va_arg(ap, syscall_arg_t);
    c = va_arg(ap, syscall_arg_t);
    d = va_arg(ap, syscall_arg_t);
    e = va_arg(ap, syscall_arg_t);
    f = va_arg(ap, syscall_arg_t);
    va_end(ap);
    return __syscall_ret(__syscall_postrisc(n,a,b,c,d,e,f));
}
