#include "libm.h"

int __signbitl(long double x)
{
	return __builtin_signbitl(x);
}
