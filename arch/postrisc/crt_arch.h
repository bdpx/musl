
extern weak hidden const size_t _DYNAMIC[];

extern hidden void START_FUNC_C(size_t*, size_t const*);

void START_FUNC(void)
{
    START_FUNC_C((void*)__builtin_postrisc_stack_pointer(), &_DYNAMIC[0]);
}
