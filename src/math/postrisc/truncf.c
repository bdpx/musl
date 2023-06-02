#include "libm.h"

float truncf(float x)
{
	return __builtin_truncf(x);
}
