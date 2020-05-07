#include "Credit.h"
#include <iostream>
#include <windows.h>
#include <string>

#define MEMORY 1000

#define PROCENT 20
#define ZERO 0
#define FIRST_SUM 100000
#define SECOND_SUM 500000
#define THIRD_SUM 1000000
#define FOURTH_SUM 3000000


using namespace std;

Credit::Credit() {
	year = 0;
	amount = 0;
	percent = 0;
	salaryAccount = 0;
	payMonth = 1;
}

Credit::Credit(int year_, int amount_,int percent_, int salaryAccount_,int payMonth_) {
	year = year_;
	amount = amount_;
	percent = percent_;
	salaryAccount = salaryAccount_;
	payMonth = payMonth_;
}

Credit::Credit(const Credit& c) {
	year = c.year;
	amount = c.amount;
	percent = c.percent;
	salaryAccount = c.salaryAccount;
	payMonth = c.payMonth;
}

Credit::~Credit() {
	year = 0;
	amount = 0;
	percent = 0;
	salaryAccount = 0;
}

int Credit::inputMoney() {
	int money = 0;
	unsigned long long int tmp;
	do {
		cout << "������� ����� �� ���������� �����: ";
		cin >> tmp;
		cout << "\n";
	} while (tmp < 0 || tmp > 2000000000);
	money = tmp;
	return money;
}

int Credit::inputYear() {
	int choose;
	int year = 0;
	cout << "�� ����� ���� �� ������ ����� ������?\n";
	cout << "1) 1 ���\n";
	cout << "2) 2 ����\n";
	cout << "3) 3 ����\n";
	cout << "4) 5 ���\n";
	cout << "5) 10 ���\n";
	cout << "6) 15 ���\n> ";
	cin >> choose;
	switch (choose)
	{
	case 1:
		year = 1;
		break;
	case 2:
		year = 2;
		break;
	case 3:
		year = 3;
		break;
	case 4:
		year = 5;
		break;
	case 5:
		year = 10;
		break;
	case 6:
		year = 15;
		break;
	default:
		cout << "������� �� ��������...\n";
		break;
	}
	cout << "\n";

	return year;
}

int Credit::corectInput(int min, int max) {
	int money;
	do {
		cout << "�����: ";
		cin >> money;
		cout << "\n";
	} while (money < min || money > max);

	return money;
}

int Credit::inputAmount(int year) {
	int choose;
	int amount = 0;

	cout << "�������� ����� �������\n";
	cout << "1) x < 100.000  -  " << PROCENT - int(year / 2) - 1 << "% �������\n";
	cout << "2) 100.000 < x < 500.000 -  " << PROCENT - int(year / 2) - 2 << "% �������\n";
	cout << "3) 500.000 < x < 1.000.000 -  " << PROCENT - int(year / 3) - 3 << "% �������\n";
	cout << "4) 1.000.000 < x < 3.000.000 - " << PROCENT - int(year / 3) - 4 << "% �������\n> ";
	cin >> choose;
	switch (choose)
	{
	case 1:
		amount = corectInput(ZERO, FIRST_SUM);
		percent = PROCENT - int(year / 2) - 1;
		break;
	case 2:
		amount = corectInput(FIRST_SUM, SECOND_SUM);
		percent = PROCENT - int(year / 2) - 2;
		break;
	case 3:
		amount = corectInput(SECOND_SUM, THIRD_SUM);
		percent = PROCENT - int(year / 3) - 3;
		break;
	case 4:
		amount = corectInput(THIRD_SUM, FOURTH_SUM);
		percent = PROCENT - int(year / 3) - 4;
		break;
	default:
		break;
	}

	return amount;
}

Credit Credit::createCredit() {
	Credit res;
	cout << "�������� ������\n";
	salaryAccount = inputMoney();
	year = inputYear();
	amount = inputAmount(year);
	amount = amount + ((amount / 100)*percent);
	percent = percent;
	payMonth = (amount + (percent * (amount / 100))) / ((12 * year));
	if (payMonth * 6 <= salaryAccount)
	{
		cout << "������ ������� ��������\n";
		salaryAccount += amount;
	}
	else
	{
		cout << "����� �� ���������� ����� �� ���������� ��� ������ �������\n";
		year = 0;
		amount = 0;
		percent = 0;
		(void)getchar(); (void)getchar();
	}
	
	return *this;
}


void Credit::Set_amount(int amount_) { amount = amount_; }

void Credit::Set_year(int year_) { year = year_; }

void Credit::Set_payMonth(int payMonth_) { payMonth = payMonth_; }

void Credit::Set_percent(int percent_) { percent = percent_; }

void Credit::Set_salaryAccount(int salaryAccount_) { salaryAccount = salaryAccount_; }


int Credit::Get_amount() {	return amount; }

int Credit::Get_year() { return year; }

int Credit::Get_percent() { return percent; }

int Credit::Get_salaryAccount() { return salaryAccount; }

int Credit::Get_payMonth() { return payMonth; }

