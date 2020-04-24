#pragma once

#include <string>;
using namespace std;

class Contacts
{
public:
	Contacts();
	Contacts(string name_, string surname_, string midName_, int day_, int month_, int year_,string phone_,bool favorit_);
	Contacts(const Contacts& c);

	~Contacts();
	
	void Set_name(string name_);
	void Set_surname(string surname_);
	void Set_midName(string midName_);
	void Set_day(int day_);
	void Set_month(int day_);
	void Set_year(int day_);
	void Set_phone(string phone_);
	void Set_favorit(bool favorit_);

    string Get_name();
	string Get_surname();
	string Get_midName();
	int    Get_day();
	int	   Get_month();
	int	   Get_year();
	string Get_phone();
	bool   Get_favorit();

	Contacts add();

private:
	string name;			// Имя
	string surname;			// Фамилия
	string midName;			// Отчество
	int day;
	int month;
	int year;
	string phone;
	bool favorit;
};


