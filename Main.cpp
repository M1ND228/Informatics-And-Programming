#include <iostream>
#include <windows.h>
#include <clocale>
#include "Date.h";

void mainMenu(Date& t1) {
	std::cout << "\nМеню:\n" << "1 - Ввести дату строкой\n" << "2 - Ввести дату отдельными значениями\nВвод: ";
	int menu = 0;
	std::cin >> menu;
	switch (menu)
	{
	case 1:
		system("cls");
		t1.inputStr();
		std::cout << "Дата: ";
		t1.print();
		break;
	case 2:
		system("cls");
		t1.input();
		system("cls");
		std::cout << "Дата: ";
		t1.print();
		break;
	default:
		std::cout << "Введено неверное значение\n";
		Sleep(850);
		mainMenu(t1);
		break;
	}
}

void chooseMenu(Date& t1, Date& t2, Date& t3, int d, int m, int y) {
	std::cout <<
		"\nДействия с датой:\n" <<
		"1 - Сложить две даты\n" <<
		"2 - Вычесть две даты\n" <<
		"3 - Сравнить две даты\n" <<
		"4 - Проверка на высокостность\n" <<
		"5 - Ввести другую дату\n" <<
		"Ввод: ";
	int menu2 = 0;
	std::cin >> menu2;
	switch (menu2)
	{
	case 1:
		system("cls");
		std::cout << "Первая дата: ";
		t1.print();
		std::cout << "Введите вторую дату\n";
		t2.input();
		t3 = t1 + t2;
		y = t3.Get_Y();
		t3.Set_Y(y);
		m = t3.Get_M();
		t3.Set_M(m);
		d = t3.Get_D();
		t3.Set_D(d);
		std::cout << "Сложение равно = " << t3;
		break;
	case 2:
		system("cls");
		std::cout << "Первая дата: ";
		t1.print();
		std::cout << "Вторая дата: ";
		t2.input();
		t3 = t1 - t2;
		std::cout << "\nВычитание равно = " << t3 << std::endl;
		break;
	case 3:
		system("cls");
		std::cout << "Первая дата: ";
		t1.print();
		std::cout << "Введите вторую дату\n";
		t2.input();
		if (t1 == t2) { std::cout << "Даты равны\n"; }
		else { if (t1 != t2) { std::cout << "Даты не равны\n"; } }
		break;
	case 4:
		system("cls");
		int year;
		std::cout << "Первая дата: ";
		t1.print();
		year = t1.Get_Y();
		if ((year % 4) || (year % 100 == 0 && year % 400))
		{
			std::cout << "Год является невысокосным\n";
		}
		else { std::cout << "Год является высокосным\n"; }
		break;
	case 5:
		system("cls");
		mainMenu(t1);
		chooseMenu(t1, t2, t3, d, m, y);
		break;
	default:
		std::cout << "Введено неверное значение\n";
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
	std::cout << "Тест конструкторов" << std::endl;
	std::cout << "Конструктор по умолчанию: " << Date();
	std::cout << "\nКонструктор с параметрами: " << Date(d, m, y);
	Date t4(11, 11, 2112);
	std::cout << "\nКонструктор копирования: " << Date(t4);
	std::cout << "\nДиструктор: ";
	present.~Date();
	present.print();

	std::cout << "\nТест функционала" << std::endl;
	Date c1(1, 1, 2000), c2(9, 9, 2005);
	std::cout << "Первая дата - " << c1 << std::endl;
	std::cout << "Вторая дата - " << c2 << std::endl;
	std::cout << "Сложение двух дат " << c1 + c2;
	std::cout << "\nВычитание даты из даты " << c2 - c1;
	std::cout << "\nСравнение двух дат ";
	if (c1 == c2) {
		std::cout << "\nДаты ровны " << c1 << " = " << c2;
	}
	else { std::cout << "\nДаты не ровны " << c1 << " != " << c2; }

	mainMenu(t1);
	chooseMenu(t1, t2, t3, d, m, y);


	std::cout << "\n";
	system("pause");
}