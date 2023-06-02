#include <fenv.h>
#include <math.h>
#include <stdint.h>

float fmaf(float x, float y, float z)
{
	return __builtin_fmaf(x, y, z);
}
