#include "libm.h"

double floor(double x)
{
	return __builtin_floor(x);
}
