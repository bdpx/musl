#include <math.h>
#include <stdint.h>

float fabsf(float x)
{
	return __builtin_fabsf(x);
}
