#include "libm.h"

float roundf(float x)
{
	return __builtin_roundf(x);
}
