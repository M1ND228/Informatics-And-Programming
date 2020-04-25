#include "Contacts.h"
#include <iostream>
#include <string>

using namespace std;

Contacts::Contacts() {
	name = "1";
	surname = "1";
	midName = "1";
	day = 1;
	month = 1;
	year = 2000;
	phone = "+7";
	favorit = false;
}

Contacts::Contacts(string name_, string surname_, string midName_, int day_, int month_, int year_, string phone_, bool favorit_) {
	name = name_;
	surname = surname_;
	midName = midName_;
	day = day_;
	month = month_;
	year = year_;
	phone = phone_;
	favorit = favorit_;
}

Contacts::~Contacts() {
	name = "";
	surname = "";
	midName = "";
	day = 0;
	month = 0;
	year = 0;
	phone = "";
	favorit = false;
}

Contacts::Contacts(const Contacts& c) {
	name = c.name;
	surname = c.surname;
	midName = c.midName;
	day = c.day;
	month = c.month;
	year = c.year;
	phone = c.phone;
	favorit = c.favorit;
}

Contacts Contacts::add() {
	string choose;

		Contacts res;
		cout << "Введите ФИО: ";
		cin >> res.surname;
		cin >> res.name;
		cin >> res.midName;

		cout << "Дата рождения:  \n";
		cout << "День: ";
		cin >> res.day;
		cout << "\nМесяц: ";
		cin >> res.month;
		cout << "\nГод:";
		cin >> res.year;

		cout << "\nНомер телефона:";
		cin >> res.phone;

		cout << "\nИзбранный (да/нет): ";
		cin >> choose;

		if ((choose == "Да") || (choose == "да") || (choose == "1") || (choose == "yes") || (choose == "Yes") || (choose == "Y")) { res.favorit = true; }
		else  { res.favorit = false; }

		return res;
	
}

// SETTERI
void Contacts::Set_name(string name_) { name = name_; }

void Contacts::Set_surname(string surname_) { surname = surname_; }

void Contacts::Set_midName(string midName_) { midName = midName_; }

void Contacts::Set_day(int day_) { day = day_; }

void Contacts::Set_month(int month_) { month = month_; }

void Contacts::Set_year(int year_) { year = year_; }

void Contacts::Set_phone(string phone_) { phone = phone_; }

void Contacts::Set_favorit(bool favorit_) { favorit = favorit_; }

// GETTERI

string Contacts::Get_name() { return this->name; }

string Contacts::Get_surname() { return this->surname; }

string Contacts::Get_midName() { return this->midName; }

int Contacts::Get_day() { return this->day; }

int Contacts::Get_month() { return this->month; }

int Contacts::Get_year() { return this->year; }

string Contacts::Get_phone() { return this->phone; }

bool Contacts::Get_favorit() { return this->favorit; }