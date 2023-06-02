#include "libm.h"

long double rintl(long double x)
{
	return __builtin_rint(x);
}
