#pragma once

#include "bits/syscall.h"

#define __SYSCALL_LL_E(x) (x)
#define __SYSCALL_LL_O(x) (x)

long __syscall_postrisc(long n, long a1, long a2, long a3, long a4, long a5, long a6);

static inline long __syscall0(long n)
{
    return __syscall_postrisc(n, 0, 0, 0, 0, 0, 0);
}

static inline long __syscall1(long n, long a1)
{
    return __syscall_postrisc(n, a1, 0, 0, 0, 0, 0);
}

static inline long __syscall2(long n, long a1, long a2)
{
    return __syscall_postrisc(n, a1, a2, 0, 0, 0, 0);
}

static inline long __syscall3(long n, long a1, long a2, long a3)
{
    return __syscall_postrisc(n, a1, a2, a3, 0, 0, 0);
}

static inline long __syscall4(long n, long a1, long a2, long a3, long a4)
{
    return __syscall_postrisc(n, a1, a2, a3, a4, 0, 0);
}

static inline long __syscall5(long n, long a1, long a2, long a3, long a4, long a5)
{
    return __syscall_postrisc(n, a1, a2, a3, a4, a5, 0);
}

static inline long __syscall6(long n, long a1, long a2, long a3, long a4, long a5, long a6)
{
    return __syscall_postrisc(n, a1, a2, a3, a4, a5, a6);
}

#define VDSO_USEFUL
#define VDSO_CGT_SYM "__vdso_clock_gettime"
#define VDSO_CGT_VER "LINUX_2.6"
#define VDSO_GETCPU_SYM "__vdso_getcpu"
#define VDSO_GETCPU_VER "LINUX_2.6"

#define IPC_64 0

static inline void postrisc_dump_value(long line, char const *file, char const *func, long value)
{
    __syscall_postrisc(SYS_dump_value, line, (long)file, (long)func, value, 0, 0);
}

static inline void postrisc_dump_memory(long line, char const *file, char const *func, void *memory, unsigned long size)
{
    __syscall_postrisc(SYS_dump_memory, line, (long)file, (long)func, (long)memory, (long)size, 0);
}

#define POSTRISC_DUMP_VALUE(VALUE) postrisc_dump_value(__LINE__, __FILE__, __FUNCTION__, (long)(VALUE))
#define POSTRISC_DUMP_MEMORY(MEMORY, MEMSIZE) postrisc_dump_memory(__LINE__, __FILE__, __FUNCTION__, (MEMORY), (MEMSIZE))

/*
usage:
#include "syscall.h"
#include "syscall_arch.h"

POSTRISC_DUMP_MEMORY(s, k);
*/
