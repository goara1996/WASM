#include "Floats.cpp"
#include "Expression.cpp"
#include "Strlen.cpp"

#include "conio.h"
#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

void toBits(unsigned int x)
{
	unsigned int y;
	for (int i = 0; i < 32; i++)
	{
		y = x & 0x80000000;
		y = y >> 31;
		x = x << 1;
		if (i == 1 || i == 9 || i == 10) 
			printf(" ");
		printf("%i", y);
	}
	printf("\n");
}

void binaryFloat(float x, int base = 10)
{
#define WHOLE true
#define FRACT false

	char str[64];
	int i = 0, whole = (int)floor(x);
	float fract = x - whole;
	bool check = WHOLE;

	while (i < 31)
	{
		if (check == WHOLE)
		{
			if (whole == 0)
			{
				str[i] = '\0';
				char *p = str;
				char *q = p;
				while (q && *q) ++q;
				for (--q; p < q; ++p, --q)
					*p = *p ^ *q,
					*q = *p ^ *q,
					*p = *p ^ *q;

				str[i] = '.';
				check = FRACT;
			}
			else
			{
				str[i] = whole % base + '0';
				whole /= base;
			}
		}
		else
		{
			fract *= base;
			whole = (int)floor(fract);
			fract -= whole;
			str[i] = whole + '0';
		}
		i++;
	}
	str[i] = '\0';

	while (i > 0)
	{
		--i;
		if (str[i] != '0' || str[i] == '.')
			break;
		str[i] = '\0';
	}

	cout << str << endl;

#undef WHOLE
#undef FRACT
}

#define testM(val)								\
	x = (float)val;								\
	cout << setw(8) << "["###val##"]" << "\t: "; \
	y = (int *)&x;								\
	toBits(*y);
#define test2(val)	\
	testM(val);		\
	binaryFloat((float)val, 10);

int main()
{

	Strlen();

	//float x; int *y;	
	
	//test2(206.116);
	//test2(312.3125);

	//printf("a + b = %g\n", addFloats((float)12.0, (float)0.345));
	//printf("a + b = %g\n", addFloatsAsm((float)12.0, (float)0.345));
	
	_getch();
	return 0;
} 