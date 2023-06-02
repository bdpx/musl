#include "libm.h"

long double roundl(long double x)
{
	return __builtin_roundl(x);
}
