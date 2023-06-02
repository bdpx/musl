#include "libm.h"

double round(double x)
{
	return __builtin_round(x);
}
