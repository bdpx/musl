#include <math.h>

long lroundf(float x)
{
	return __builtin_lroundf(x);
}
