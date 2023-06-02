#include <float.h>
#include <math.h>
#include <stdint.h>

float rintf(float x)
{
	return __builtin_rintf(x);
}
