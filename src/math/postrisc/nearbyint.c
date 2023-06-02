#include <fenv.h>
#include <math.h>

/* nearbyint is the same as rint, but it must not raise the inexact exception */

double nearbyint(double x)
{
	return __builtin_nearbyint(x);
}
