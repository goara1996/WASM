#include "stdio.h"

static float addFloats(float a, float b)
{
	float z;

	_asm {
		movss xmm0, a
		addss xmm0, b
		movss z, xmm0
	}

	return z;
}