#include "ProcCenter.h"
#include "Credit.h"
#include <iostream>
#include <string>

using namespace std;

ProcCenter::ProcCenter() {
	password = "";
	name = "";
	surname = "";
	midName = "";
	code = 1;
}

ProcCenter::ProcCenter(int code_,string password_, string name_, string surname_, string midName_) {
	password = password_;
	name = name_;
	surname = surname_;
	midName = midName_;
	code = code_;
}

ProcCenter::ProcCenter(const ProcCenter& c) {
	password = c.password;
	name = c.name;
	surname = c.surname;
	midName = c.midName;
	code = c.code;
} 

ProcCenter::~ProcCenter() {
	password = "";
	name = "";
	surname = "";
	midName = "";
	code = 0;
}

void ProcCenter::Set_password(string password_) { password = password_; }

void ProcCenter::Set_name(string name_) { name = name_; }

void ProcCenter::Set_surname(string surname_) { surname = surname_; }

void ProcCenter::Set_midName(string midName_) { midName = midName_; }

void ProcCenter::Set_code(int code_) { code = code_; }

int ProcCenter::Get_code() { return code; }

string ProcCenter::Get_surname() { return this->surname; }

string ProcCenter::Get_name() { return this->name; }

string ProcCenter::Get_midName() { return this->midName; }

string ProcCenter::Get_password() { return this->password; }

string ProcCenter::input_FIO() {
	string s1, n1, m1;
	cout << "Введите ФИО: ";
	cin >> s1;
	cin >> n1;
	cin >> m1;
	string str;
	str = s1 + "|" + n1 + "|" + m1;
	return str;
}

string ProcCenter::input_password() {
	string pas; 
	string tmp, tmp2;
	bool check = false;
	do {
		cout << "Введите пароль для входа в аккаунт: ";
		cin >> tmp;
		if (tmp.length() < 3) 
		{ 
			cout << "\nВведённый пароль слишком слабый, введите заново\n"; 
		}else 
		{ 
			cout << "Повторите введённый пароль: "; 
			cin >> tmp2; 
			if (tmp != tmp2) { cout << "Пароли не совпадают\n"; }
			else { cout << "Пароль успешно сохранён!\n"; pas = tmp; check = true; }
		}
	} while (check == false);
	return pas;
}

ProcCenter ProcCenter::createAccount() {
	cout << "Создание аккаунта:\n";
	ProcCenter res;
	string* s1 = new string[15];
	string fio = input_FIO();
	string pas = input_password();

	int j = 0;
	for (int i = 0; i < (int)fio.size(); i++)
	{
		if (fio[i] == '|') { j++; }
		else { s1[j] += fio[i]; }
	}
	surname = s1[0];
	name = s1[1];
	midName = s1[2];
	password = pas;
	
	res.surname = s1[0];
	res.name = s1[1];
	res.midName = s1[2];
	res.password = pas;
	delete[] s1;
	return res;
}