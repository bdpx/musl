#include <math.h>

float fmaxf(float x, float y)
{
	return __builtin_fmaxf(x, y);
}
