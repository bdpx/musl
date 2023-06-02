#include <math.h>

long lroundl(long double x)
{
	return __builtin_lroundl(x);
}
