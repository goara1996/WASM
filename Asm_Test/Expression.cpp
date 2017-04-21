#include "stdio.h"

static void Expressions()
{
	int a, b, sum;
	printf("Example: a + 5 * b \n");
	while (true) {
		printf("Enter a: ");
		scanf_s("%d", &a);
		printf("Enter b: ");
		scanf_s("%d", &b);
	/*	_asm {
			mov eax, a
			mov ecx, 5
		m: 	add eax, b
			loop m
			mov sum, eax
		}*/
		printf("\n %d + 5 * %d = %d", a, b, sum);
		getchar();
		if (getchar() == (char)10) break;
	}
}