#include <float.h>
#include <math.h>
#include <stdint.h>

double rint(double x)
{
	return __builtin_rintf(x);
}
