#include "conio.h"
#include <iostream>

using namespace std;

static void Strlen()
{
	char buffer[32];
	int length;

	while (true)
	{
		cout << "Input string: ";
		cin >> buffer;

		_asm
		{
			lea esi, buffer

		compare:
			mov eax, [esi]
			cmp eax, 0
			je l_out
			inc esi
			jmp compare
		l_out:
			lea eax, buffer
			sub esi, eax
			//mov length, esi
		}

		cout << "Length is: " << length << endl;
		_getch();
		if (_getch() == (char)10) break;
	}
}