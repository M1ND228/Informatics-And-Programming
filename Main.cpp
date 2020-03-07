#include <iostream>
#include <windows.h>
#include <clocale>
#include "Date.h";

void mainMenu(Date& t1) {
	std::cout << "\n����:\n" << "1 - ������ ���� �������\n" << "2 - ������ ���� ���������� ����������\n����: ";
	int menu = 0;
	std::cin >> menu;
	switch (menu)
	{
	case 1:
		system("cls");
		t1.inputStr();
		std::cout << "����: ";
		t1.print();
		break;
	case 2:
		system("cls");
		t1.input();
		system("cls");
		std::cout << "����: ";
		t1.print();
		break;
	default:
		std::cout << "������� �������� ��������\n";
		Sleep(850);
		mainMenu(t1);
		break;
	}
}

void chooseMenu(Date& t1, Date& t2, Date& t3, int d, int m, int y) {
	std::cout <<
		"\n�������� � �����:\n" <<
		"1 - ������� ��� ����\n" <<
		"2 - ������� ��� ����\n" <<
		"3 - �������� ��� ����\n" <<
		"4 - �������� �� �������������\n" <<
		"5 - ������ ������ ����\n" <<
		"����: ";
	int menu2 = 0;
	std::cin >> menu2;
	switch (menu2)
	{
	case 1:
		system("cls");
		std::cout << "������ ����: ";
		t1.print();
		std::cout << "������� ������ ����\n";
		t2.input();
		t3 = t1 + t2;
		y = t3.Get_Y();
		t3.Set_Y(y);
		m = t3.Get_M();
		t3.Set_M(m);
		d = t3.Get_D();
		t3.Set_D(d);
		std::cout << "�������� ����� = " << t3;
		break;
	case 2:
		system("cls");
		std::cout << "������ ����: ";
		t1.print();
		std::cout << "������ ����: ";
		t2.input();
		t3 = t1 - t2;
		std::cout << "\n��������� ����� = " << t3 << std::endl;
		break;
	case 3:
		system("cls");
		std::cout << "������ ����: ";
		t1.print();
		std::cout << "������� ������ ����\n";
		t2.input();
		if (t1 == t2) { std::cout << "���� �����\n"; }
		else { if (t1 != t2) { std::cout << "���� �� �����\n"; } }
		break;
	case 4:
		system("cls");
		int year;
		std::cout << "������ ����: ";
		t1.print();
		year = t1.Get_Y();
		if ((year % 4) || (year % 100 == 0 && year % 400))
		{
			std::cout << "��� �������� ������������\n";
		}
		else { std::cout << "��� �������� ����������\n"; }
		break;
	case 5:
		system("cls");
		mainMenu(t1);
		chooseMenu(t1, t2, t3, d, m, y);
		break;
	default:
		std::cout << "������� �������� ��������\n";
		Sleep(850);
		chooseMenu(t1, t2, t3, d, m, y);
		break;
	}
}

int main() {
	setlocale(LC_ALL, "rus");
	system("cls");

	int d = 9, m = 11, y = 2001;

	Date t1;
	Date t2;
	Date t3;

	Date present;
	std::cout << "���� �������������" << std::endl;
	std::cout << "����������� �� ���������: " << Date();
	std::cout << "\n����������� � �����������: " << Date(d, m, y);
	Date t4(11, 11, 2112);
	std::cout << "\n����������� �����������: " << Date(t4);
	std::cout << "\n����������: ";
	present.~Date();
	present.print();

	std::cout << "\n���� �����������" << std::endl;
	Date c1(1, 1, 2000), c2(9, 9, 2005);
	std::cout << "������ ���� - " << c1 << std::endl;
	std::cout << "������ ���� - " << c2 << std::endl;
	std::cout << "�������� ���� ��� " << c1 + c2;
	std::cout << "\n��������� ���� �� ���� " << c2 - c1;
	std::cout << "\n��������� ���� ��� ";
	if (c1 == c2) {
		std::cout << "\n���� ����� " << c1 << " = " << c2;
	}
	else { std::cout << "\n���� �� ����� " << c1 << " != " << c2; }

	mainMenu(t1);
	chooseMenu(t1, t2, t3, d, m, y);


	std::cout << "\n";
	system("pause");
}