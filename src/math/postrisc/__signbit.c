#include "libm.h"

// FIXME: macro in math.h
int __signbit(double x)
{
	return __builtin_signbit(x);
}


