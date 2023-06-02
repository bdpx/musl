#include <limits.h>
#include <fenv.h>
#include <math.h>
#include "libm.h"

long lrint(double x)
{
	return __builtin_lrint(x);
}
