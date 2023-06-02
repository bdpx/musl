#include <math.h>
#include <float.h>

long double fminl(long double x, long double y)
{
	return __builtin_fminl(x, y);
}
