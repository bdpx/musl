#include <math.h>

double fmax(double x, double y)
{
	return __builtin_fmax(x, y);
}
