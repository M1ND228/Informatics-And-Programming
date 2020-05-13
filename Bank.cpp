#include "ProcCenter.h"
#include "Bank.h"
#include <iostream>
#include <windows.h>
#include <omp.h>
#include <string>


using namespace std;

Bank::Bank() {
	count = 0;
	position = -1;
	memory = 250;
	list_credit = new Credit[memory];
	list_user = new ProcCenter[memory];
}

Bank::Bank(int memory_,int count_, int position_, Credit* list_credit_, ProcCenter* list_user_) {
	count = count_;
	position = position_;
	memory = memory_;
	list_credit = new Credit[memory];
	list_user = new ProcCenter[memory];
	for (int i = 0; i < count; i++)
	{
		list_credit[i] = list_credit_[i];
		list_user[i] = list_user_[i];
	}
}

Bank::Bank(const Bank& c) {
	count = c.count;
	position = c.position;
	memory = c.memory;
	list_credit = new Credit[memory];
	list_user = new ProcCenter[memory];
	for (int i = 0; i < count; i++) 
	{
		list_credit[i] = c.list_credit[i];
		list_user[i] = c.list_user[i];
	}
}

Bank::~Bank() {
	count = 0;
	position = 0;
	delete[] list_credit;
	delete[] list_user;
}

void Bank::timer() {
	int stop = 30;
	for(int i = 0; i < 30; i++)
	{
		system("cls");
		cout << "Ваша карта заблокированна: " << stop - i << " сек.";
		Sleep(950);
	}
	system("cls");
}

string Bank::controlInputPas(int i) {
	string pas;
	cout << "Пароль введён неверно\n";
	for (int j = 0; j < 3; j++)
	{
		if (j == 2) { timer(); return pas; }
		pas = signInPas();
		if (list_user[i].Get_password() == pas)
		{
			return pas;
		}
		else { cout << "Пароль введён неверно\n"; }
	}
	return pas;
}

string Bank::signInPas() {
	string pas;
	cout << "Пароль: ";
	cin >> pas;

	return pas;
}

int Bank::signInChet() {
	cout << "Вход в аккаунт: \n";
	int chet;
	do {
		cout << "Номер счёта: ";
		cin >> chet;
		if (chet < 0 || chet > 9999) { cout << "Вводите коректные данные\n"; }
	} while (chet < 0 || chet > 9999);
	return chet;
}


void Bank::registration() {
	if (count + 1 > memory)
	{
		ProcCenter* new_list_user = new ProcCenter[count + 1];
		for (int i = 0; i < count; i++)
		{
			new_list_user[i] = list_user[i];
		}
		delete[]list_user;
		list_user = new ProcCenter[count + 1];
		for (int i = 0; i < count; i++)
		{
			list_user[i] = new_list_user[i];
		}
		memory++;
		delete[] new_list_user;
	}
	ProcCenter a1;
	a1.createAccount();
	list_user[count] = a1;
	list_user[count].Set_code(count);
	a1.~ProcCenter();
	cout << "Ваши данные для входа в аккаунт\n";
	int num = list_user[count].Get_code();
	if (num < 9) { cout << "Номер счёта: 000" << num; }
	else {
		if (num < 99) { cout << "Номер счёта: 00" << num; }
		else {
			if (num < 999) { cout << "Номер счёта: 0" << num; }
			else { cout << "Номер счёта: " << num; }
		}
	}
	cout << "\nПароль: " << list_user[count].Get_password().c_str() << endl;
	count++;
}

void Bank::logAccount() {
	int schet = signInChet();
	string pas = signInPas();
	bool check = false;
	for (int i = 0; i < count; i++)
	{
		if (schet == list_user[i].Get_code() && list_user[i].Get_password() == pas)
		{
			position = i;
			check = true;
			cout << "Вход в аккаунт...\n";
			Sleep(700);
		}
		else
		{
			if (schet == list_user[i].Get_code() && list_user[i].Get_password() != pas)
			{
				pas = controlInputPas(i);
				if (list_user[i].Get_password() == pas)
				{
					position = i;
					check = true;
					cout << "Вход в аккаунт...\n";
					Sleep(700);
					break;
				}
			}
		}
		if (check == false) { cout << "Аккаунт не найден\n"; }
	}
}

void Bank::takeCredit() {
	string pas,tru;
	if (count + 1 > memory)
	{
		Credit* new_list_credit = new Credit[count + 1];
		for (int i = 0; i < count; i++)
		{
			new_list_credit[i] = list_credit[i];
		}
		delete[]list_credit;
		list_credit = new Credit[count + 1];
		for (int i = 0; i < count; i++)
		{
			list_credit[i] = new_list_credit[i];
		}
		memory++;
		delete[] new_list_credit;
	}
	if (position < 0) { cout << "Войдите в аккаунт\n"; }
	else {
		if (list_credit[position].Get_amount() > 0) { cout << "Прошлый кредит не погашен\n"; }
		else
		{
			Credit c1;
			c1.createCredit();
			if (c1.Get_amount() > 1)
			{
				pas = signInPas();
				tru = list_user[position].Get_password();
				if (pas != tru)
				{
					pas = controlInputPas(position);
					if (pas == tru)
					{
						cout << "Кредит успешно оформлен\n";
						int tmp = c1.Get_salaryAccount() + c1.Get_amount();
						c1.Set_salaryAccount(tmp);
					}
				}else 
				{
					cout << "Кредит успешно оформлен\n";
					int tmp = c1.Get_salaryAccount() + c1.Get_amount();
					c1.Set_salaryAccount(tmp);
				}
			}
			list_credit[position] = c1;
			c1.~Credit();
		}
	}
}

void Bank::infoCredit() {
	if (position < 0 || list_credit[position].Get_amount() < 1) { cout << "Нет оформленных кредитов!\n"; return; }
	else {
		cout << "Информация по кредиту:\n";
		cout << "ФИО: " << list_user[position].Get_surname() << " " << list_user[position].Get_name() << " " << list_user[position].Get_midName() << endl;
		int num = list_user[position].Get_code();
		if (num < 9) { cout << "Номер счёта: 000" << num; }
		else {
			if (num < 99) { cout << "Номер счёта: 00" << num; }
			else {
				if (num < 999) { cout << "Номер счёта: 0" << num; }
				else { cout << "Номер счёта: " << num; }
			}
		}
		cout << "\nСумма кредита: " << list_credit[position].Get_amount() << " под " << list_credit[position].Get_percent() << "%\n";
		cout << "Сумма на зарплатном счёте: " << list_credit[position].Get_salaryAccount() << "\n";
		cout << "Выплата в месяц: " << list_credit[position].Get_payMonth() << "\n";
	}
}

void Bank::one_pay() {
	if (position < 0 || list_credit[position].Get_amount() < 1) { cout << "Нет оформленных кредитов!\n"; return; }
	else {
		int pay = list_credit[position].Get_payMonth();
		list_credit[position].Set_amount(list_credit[position].Get_amount() - pay);
		list_credit[position].Set_salaryAccount(list_credit[position].Get_salaryAccount() - pay);
		cout << "Платёж выплачен\n";
		cout << "Сумма платежа: " << pay << "\n";
	}
}

void Bank::payOff() {
	if (position < 0 || list_credit[position].Get_amount() < 1) { cout << "Нет оформленных кредитов!\n"; return; }
	else {
		int pay = list_credit[position].Get_amount();
		list_credit[position].Set_amount(list_credit[position].Get_amount() - pay);
		list_credit[position].Set_salaryAccount(list_credit[position].Get_salaryAccount() - pay);
		cout << "Платёж выплачен\n";
		cout << "Сумма платежа: " << pay << "\n";
	}
}

void Bank::inputCount() {
	cout << "Зарегестрированных пользователей в банке: " << count << "\n";
}

Bank& Bank::operator=(const Bank& c) {
	count = c.count;
	position = c.position;
	for (int i = 0; i < count; i++)
	{
		list_credit[i] = c.list_credit[i];
		list_user[i] = c.list_user[i];
	}
	return *this;
}