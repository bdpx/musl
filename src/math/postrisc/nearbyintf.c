#include <fenv.h>
#include <math.h>

float nearbyintf(float x)
{
	return __builtin_nearbyintf(x);
}
