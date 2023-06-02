#include "libm.h"

// FIXME: macro in math.h
int __signbitf(float x)
{
	return __builtin_signbitf(x);
}
