#include <math.h>
#include <stdint.h>

float copysignf(float x, float y)
{
	return __builtin_copysignf(x, y);
}
