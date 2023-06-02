#include <math.h>

long long llroundl(long double x)
{
	return __builtin_llroundl(x);
}
