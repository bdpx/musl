#include "libm.h"

float floorf(float x)
{
	return __builtin_floorf(x);
}
