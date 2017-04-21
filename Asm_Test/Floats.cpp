#include "stdio.h"

static void intBinaryOut(unsigned int x)
{
	unsigned int y;
	for (int i = 0; i < 32; i++)
	{
		y = (x & 1);
		//y = y >> 15;
		printf("%i", y);
		x = x >> 1;
	}
	printf("\n");
}

static void Floats()
{
	float x, y, z;
	x = (float)20.0;
	y = (float)0.42;

	int in = 16 + 32 + 127;
	intBinaryOut(in);

	_asm {
		movss xmm0, x
		movss xmm1, y
		addss xmm0, xmm1
		movss z, xmm0
	}

	printf("z = %g\n", z);
}