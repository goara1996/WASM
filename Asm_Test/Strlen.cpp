#include "conio.h"
#include <iostream>

using namespace std;

static void Strlen()
{
	char buffer[32];	// Переменная для строки
	int len;			// Переменная для длины

	while (true)
	{
		cout << "Input string: ";	// "Введите строку:"
		cin >> buffer;				// Ввод строки

		_asm
		{
			lea esi, buffer			// esi <- адрес первого символа
		compare:
			mov al, byte ptr [esi]	// al <- символ из esi
			cmp al, 0				// если в al символ с кодом 0...
			je l_out				// ...то прыгаем к l_out:
			inc esi					// иначе переходим к следующему символу
			jmp compare				// прыгаем к compare:
		l_out:
			lea eax, buffer			// eax <- адрес первого символа
			sub esi, eax			// вычитаем адрес первого символа из адреса последнего
			mov len, esi			// esi <- записываем длину в соотв. переменную
		}

		cout << "Length is: " << len << endl;							// Вывод длины

		cout << "Press [Enter] to exit, or any key to continue";		// "Нажмите ентер для выхода, либо любую клавишу для продолжения"
		if (_getch() == (char)13) break;								// Проверка клавиши
		cout << "\r                                             \r";	// Ленивая очистка строки
	}
}