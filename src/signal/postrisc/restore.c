#include <features.h>
#include "syscall.h"
#include "syscall_arch.h"

/* These functions will not work, but suffice for targets where the
 * kernel sigaction structure does not actually use sa_restorer. */

hidden void __restore()
{
    __syscall_postrisc(__NR_rt_sigreturn, 0, 0, 0, 0, 0, 0);
}

hidden void __restore_rt()
{
    __syscall_postrisc(__NR_rt_sigreturn, 0, 0, 0, 0, 0, 0);
}
