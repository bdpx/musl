#include <stdint.h>
#include <float.h>
#include <math.h>

double fma(double x, double y, double z)
{
	return __builtin_fma(x, y, z);
}
