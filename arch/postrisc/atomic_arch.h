#define a_cas a_cas
static inline int a_cas(volatile int *p, int t, int s)
{
#if defined(__POSTRISC__)
	__atomic_compare_exchange_n(p, &t, s, 0, __ATOMIC_SEQ_CST, __ATOMIC_SEQ_CST);
	return t;
#else
	__asm__ __volatile__ (
		"lock ; cmpxchg %3, %1"
		: "=a"(t), "=m"(*p) : "a"(t), "r"(s) : "memory" );
	return t;
#endif
}

#define a_cas_p a_cas_p
static inline void *a_cas_p(volatile void *p, void *t, void *s)
{
#if defined(__POSTRISC__)
	__atomic_compare_exchange_n((void**)p, &t, s, 0, __ATOMIC_SEQ_CST, __ATOMIC_SEQ_CST);
	return t;
#else
	__asm__( "lock ; cmpxchg %3, %1"
		: "=a"(t), "=m"(*(void *volatile *)p)
		: "a"(t), "r"(s) : "memory" );
	return t;
#endif
}

#define a_swap a_swap
static inline int a_swap(volatile int *p, int v)
{
#if defined(__POSTRISC__)
	return __atomic_exchange_n(p, v, __ATOMIC_SEQ_CST);
#else
	__asm__ __volatile__(
		"xchg %0, %1"
		: "=r"(v), "=m"(*p) : "0"(v) : "memory" );
	return v;
#endif
}

#define a_fetch_add a_fetch_add
static inline int a_fetch_add(volatile int *p, int v)
{
#if defined(__POSTRISC__)
	return __atomic_fetch_add(p, v, __ATOMIC_SEQ_CST);
#else
	__asm__ __volatile__(
		"lock ; xadd %0, %1"
		: "=r"(v), "=m"(*p) : "0"(v) : "memory" );
	return v;
#endif
}

#define a_and a_and
static inline void a_and(volatile int *p, int v)
{
#if defined(__POSTRISC__)
	__atomic_fetch_and(p, v, __ATOMIC_SEQ_CST);
#else
	__asm__ __volatile__(
		"lock ; and %1, %0"
		: "=m"(*p) : "r"(v) : "memory" );
#endif
}

#define a_or a_or
static inline void a_or(volatile int *p, int v)
{
#if defined(__POSTRISC__)
	__atomic_fetch_or(p, v, __ATOMIC_SEQ_CST);
#else
	__asm__ __volatile__(
		"lock ; or %1, %0"
		: "=m"(*p) : "r"(v) : "memory" );
#endif
}

#define a_and_64 a_and_64
static inline void a_and_64(volatile uint64_t *p, uint64_t v)
{
#if defined(__POSTRISC__)
	__atomic_fetch_and(p, v, __ATOMIC_SEQ_CST);
#else
	__asm__ __volatile(
		"lock ; and %1, %0"
		 : "=m"(*p) : "r"(v) : "memory" );
#endif
}

#define a_or_64 a_or_64
static inline void a_or_64(volatile uint64_t *p, uint64_t v)
{
#if defined(__POSTRISC__)
    __atomic_fetch_or(p, v, __ATOMIC_SEQ_CST);
#else
	__asm__ __volatile__(
		"lock ; or %1, %0"
		 : "=m"(*p) : "r"(v) : "memory" );
#endif
}

#define a_inc a_inc
static inline void a_inc(volatile int *p)
{
#if defined(__POSTRISC__)
	__atomic_fetch_add(p, 1, __ATOMIC_SEQ_CST);
#else
	__asm__ __volatile__(
		"lock ; incl %0"
		: "=m"(*p) : "m"(*p) : "memory" );
#endif
}

#define a_dec a_dec
static inline void a_dec(volatile int *p)
{
#if defined(__POSTRISC__)
	__atomic_fetch_add(p, -1, __ATOMIC_SEQ_CST);
#else
	__asm__ __volatile__(
		"lock ; decl %0"
		: "=m"(*p) : "m"(*p) : "memory" );
#endif
}

#define a_store a_store
static inline void a_store(volatile int *p, int x)
{
#if defined(__POSTRISC__)
	__atomic_store_n(p, x, __ATOMIC_SEQ_CST);
#else
	__asm__ __volatile__(
		"mov %1, %0 ; lock ; orl $0,(%%rsp)"
		: "=m"(*p) : "r"(x) : "memory" );
#endif
}

#define a_barrier a_barrier
static inline void a_barrier()
{
#if defined(__POSTRISC__)
	__atomic_thread_fence(__ATOMIC_SEQ_CST);
#else
	__asm__ __volatile__( "" : : : "memory" );
#endif
}

#define a_spin a_spin
static inline void a_spin()
{
#if defined(__POSTRISC__)
	__atomic_thread_fence(__ATOMIC_SEQ_CST);
#else
	__asm__ __volatile__( "pause" : : : "memory" );
#endif
}

#define a_crash a_crash
static inline void a_crash()
{
#if defined(__POSTRISC__)
	__builtin_postrisc_halt();
#else
	__asm__ __volatile__( "hlt" : : : "memory" );
#endif
}

#define a_ctz_64 a_ctz_64
static inline int a_ctz_64(uint64_t x)
{
#if defined(__POSTRISC__)
	return __builtin_ctzll(x);
#else
	__asm__( "bsf %1,%0" : "=r"(x) : "r"(x) );
	return x;
#endif
}

#define a_clz_64 a_clz_64
static inline int a_clz_64(uint64_t x)
{
#if defined(__POSTRISC__)
	return __builtin_clzll(x);
#else
	__asm__( "bsr %1,%0 ; xor $63,%0" : "=r"(x) : "r"(x) );
	return x;
#endif
}
