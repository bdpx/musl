#include <limits.h>
#include <fenv.h>
#include "libm.h"

long lrintl(long double x)
{
	return __builtin_lrintl(x);
}
