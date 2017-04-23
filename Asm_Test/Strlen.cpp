#include "conio.h"
#include <iostream>

using namespace std;

static void Strlen()
{
	char buffer[32];	// ���������� ��� ������
	int len;			// ���������� ��� �����

	while (true)
	{
		cout << "Input string: ";	// "������� ������:"
		cin >> buffer;				// ���� ������

		_asm
		{
			lea esi, buffer			// esi <- ����� ������� �������
		compare:
			mov al, byte ptr [esi]	// al <- ������ �� esi
			cmp al, 0				// ���� � al ������ � ����� 0...
			je l_out				// ...�� ������� � l_out:
			inc esi					// ����� ��������� � ���������� �������
			jmp compare				// ������� � compare:
		l_out:
			lea eax, buffer			// eax <- ����� ������� �������
			sub esi, eax			// �������� ����� ������� ������� �� ������ ����������
			mov len, esi			// esi <- ���������� ����� � �����. ����������
		}

		cout << "Length is: " << len << endl;							// ����� �����

		cout << "Press [Enter] to exit, or any key to continue";		// "������� ����� ��� ������, ���� ����� ������� ��� �����������"
		if (_getch() == (char)13) break;								// �������� �������
		cout << "\r                                             \r";	// ������� ������� ������
	}
}