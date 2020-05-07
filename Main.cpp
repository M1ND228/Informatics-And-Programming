#include "Credit.h";
#include "ProcCenter.h"
#include "Bank.h"
#include <iostream>
#include <Windows.h>
#include <string>


using namespace std;

void mainMenu(Bank& c1) {
	cout << "Меню: \n";
	cout << "1 - Оформить кредит\n";
	cout << "2 - Информация о кредите\n";
	cout << "3 - Оплата кредита\n";
	cout << "4 - Погасить кредит досрочно\n";
	cout << "5 - Сменить аккаунт\n";
	cout << "6 - Зарегестрировать аккаунт\n";
	cout << "7 - Аккаунтов в базе\n";
	cout << "- - - - - - - - - - - - \n";
	cout << "0 - Выход из приложения\n> ";
	int choose;
	cin >> choose;
	switch (choose)
	{
	case 0 :
		cout << "Спасибо за использование нашего банка!\n";
		Sleep(1000);
		exit(EXIT_SUCCESS);
		break;
	case 1:
		system("cls");
		c1.takeCredit();
		mainMenu(c1);
		break;
	case 2:
		system("cls");
		c1.infoCredit();
		mainMenu(c1);
		break;
	case 3:
		system("cls");
		c1.one_pay();
		mainMenu(c1);
		break;
	case 4:
		system("cls");
		c1.payOff();
		mainMenu(c1);
		break;
	case 5:
		system("cls");
		c1.logAccount();
		mainMenu(c1);
		break;
	case 6:
		system("cls");
		c1.registration();
		mainMenu(c1);
		break;
	case 7:
		system("cls");
		c1.inputCount();
		mainMenu(c1);
		break;
	default:
		system("cls");
		cout << "Кажется вы ввели что-то не то...\n";
		Sleep(800);
		system("cls");
		mainMenu(c1);
		break;
	}
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	system("cls");

	Bank c1;
	mainMenu(c1);

	system("pause");
	return 0;
}