
extern weak hidden const size_t _DYNAMIC[];

extern void START_FUNC_C(long*, size_t const*);

void START_FUNC(void)
{
    START_FUNC_C((void*)__builtin_postrisc_stack_pointer(), &_DYNAMIC[0]);
}
