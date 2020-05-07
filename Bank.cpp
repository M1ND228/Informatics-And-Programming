#include "ProcCenter.h"
#include "Bank.h"
#include <iostream>
#include <windows.h>
#include <string>


using namespace std;

Bank::Bank() {
	count = 0;
	position = -1;
	list_credit = new Credit[100];
	list_user = new ProcCenter[100];
}

Bank::Bank(int count_, int position_, Credit* list_credit_, ProcCenter* list_user_) {
	count = count_;
	position = position_;
	list_credit = new Credit[100];
	list_user = new ProcCenter[100];
	for (int i = 0; i < count; i++)
	{
		list_credit[i] = list_credit_[i];
		list_user[i] = list_user_[i];
	}
}

Bank::Bank(const Bank& c) {
	count = c.count;
	position = c.position;
	list_credit = new Credit[100];
	list_user = new ProcCenter[100];
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

string Bank::makeLoan() {
	string str;

	return str;
}

string Bank::signInPas() {
	string pas;
	cout << "������: ";
	cin >> pas;

	return pas;
}

int Bank::signInChet() {
	cout << "���� � �������: \n";
	int chet;
	do {
		cout << "����� �����: ";
		cin >> chet;
		if (chet < 0 || chet > 9999) { cout << "������� ��������� ������\n"; }
	} while (chet < 0 || chet > 9999);
	return chet;
}


void Bank::registration() {
	ProcCenter a1;
	a1.createAccount();
	list_user[count] = a1;
	list_user[count].Set_code(count);
	a1.~ProcCenter();
	cout << "���� ������ ��� ����� � �������\n";
	int num = list_user[count].Get_code();
	if (num < 9) { cout << "����� �����: 000" << num; }
	else {
		if (num < 99) { cout << "����� �����: 00" << num; }
		else {
			if (num < 999) { cout << "����� �����: 0" << num; }
			else { cout << "����� �����: " << num; }
		}
	}
	cout << "\n������: " << list_user[count].Get_password().c_str() << endl;
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
			cout << "���� � �������...\n";
			Sleep(700);
		}
	}
	if (check == false) { cout << "������� �� ������\n"; }
}

void Bank::takeCredit() {
	if (position < 0) { cout << "������� � �������\n"; }
	else {
		if (list_credit[position].Get_amount() > 0) { cout << "������� ������ �� �������\n"; }
		else
		{
			Credit c1;
			c1.createCredit();
			list_credit[position] = c1;
			c1.~Credit();
		}
	}
}

void Bank::infoCredit() {
	if (position < 0 || list_credit[position].Get_amount() < 1) { cout << "��� ����������� ��������!\n"; return; }
	else {
		cout << "���������� �� �������:\n";
		cout << "���: " << list_user[position].Get_surname() << " " << list_user[position].Get_name() << " " << list_user[position].Get_midName() << endl;
		int num = list_user[position].Get_code();
		if (num < 9) { cout << "����� �����: 000" << num; }
		else {
			if (num < 99) { cout << "����� �����: 00" << num; }
			else {
				if (num < 999) { cout << "����� �����: 0" << num; }
				else { cout << "����� �����: " << num; }
			}
		}
		cout << "\n����� �������: " << list_credit[position].Get_amount() << " ��� " << list_credit[position].Get_percent() << "%\n";
		cout << "����� �� ���������� �����: " << list_credit[position].Get_salaryAccount() << "\n";
		cout << "������� � �����: " << list_credit[position].Get_payMonth() << "\n";
	}
}

void Bank::one_pay() {
	if (position < 0 || list_credit[position].Get_amount() < 1) { cout << "��� ����������� ��������!\n"; return; }
	else {
		int pay = list_credit[position].Get_payMonth();
		list_credit[position].Set_amount(list_credit[position].Get_amount() - pay);
		list_credit[position].Set_salaryAccount(list_credit[position].Get_salaryAccount() - pay);
		cout << "����� ��������\n";
		cout << "����� �������: " << pay << "\n";
	}
}

void Bank::payOff() {
	if (position < 0 || list_credit[position].Get_amount() < 1) { cout << "��� ����������� ��������!\n"; return; }
	else {
		int pay = list_credit[position].Get_amount();
		list_credit[position].Set_amount(list_credit[position].Get_amount() - pay);
		list_credit[position].Set_salaryAccount(list_credit[position].Get_salaryAccount() - pay);
		cout << "����� ��������\n";
		cout << "����� �������: " << pay << "\n";
	}
}

void Bank::inputCount() {
	cout << "������������������ ������������� � �����: " << count << "\n";
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