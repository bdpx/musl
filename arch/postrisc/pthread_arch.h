static inline uintptr_t __get_tp()
{
    return (uintptr_t)__builtin_thread_pointer();
}

#define MC_PC gregs[REG_RIP]
