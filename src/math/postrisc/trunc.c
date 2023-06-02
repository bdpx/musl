#include "libm.h"

double trunc(double x)
{
	return __builtin_trunc(x);
}
