#include <limits.h>
#include <fenv.h>
#include "libm.h"

long long llrintl(long double x)
{
	return __builtin_llrintl(x);
}
