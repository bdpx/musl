#include <math.h>

float fminf(float x, float y)
{
	return __builtin_fminf(x, y);
}
