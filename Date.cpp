#include <iostream>
#include "Date.h"


Date::Date() {
	day = 1;
	month = 1;
	year = 1;
}

Date::Date(int _d, int _m, int _y) {
	day = _d;
	month = _m;
	year = _y;
}

Date::Date(const Date& c) {
	day = c.day;
	month = c.month;
	year = c.year;
}

Date::~Date() {
	day = 0;
	month = 0;
	year = 0;
}

int Date::Get_D () { return this->day; }
int Date::Get_M () { return this->month; }
int Date::Get_Y () { return this->year; }

void Date::Set_D (int value_d) { 
	int i = 0;
	bool leap_year;
	int leap_0[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if ((year % 4) || (year % 100 == 0 && year % 400)) { leap_year = false; }			// Проверка на высокостность
	else leap_year = true;

	if (value_d < 1) {
		throw std::invalid_argument("Days less than one");
	}

	if (leap_year == false) {} else { leap_0[1] = 29; };
	switch (month)
	{
	case 1:
		if (value_d > leap_0[0]) {
			i = 0;
			while (day > value_d % leap_0[i]) {
				day = value_d % leap_0[i];
				i++;
			}
			if (day == 0) { day = 1; }
			month += (value_d / leap_0[0]) % 12;
			year += (month / 12) + value_d / 365;
		}
		else { day = value_d; }
		break;
	case 2:
			if (value_d > leap_0[1]) {
				i = 1;
				while (day > value_d% leap_0[i]) {
					day = value_d % leap_0[i];
					i++;
				}
				if (day == 0) { day = 1; }
				month += (value_d / leap_0[1]) % 12;
				year += (month / 12) + value_d / 365;
			}
			else { day = value_d; }
		break;
	case 3:
			if (value_d > leap_0[2]) {
				i = 2;
				while (day > value_d% leap_0[i]) {
					day = value_d % leap_0[i];
					i++;
				}
				if (day == 0) { day = 1; }
				month += (value_d / leap_0[2]) % 12;
				year += (month / 12) + value_d / 365;
			}
			else { day = value_d; }
		break;
	case 4:
			if (value_d > leap_0[3]) {
				i = 3;
				while (day > value_d% leap_0[i]) {
					day = value_d % leap_0[i];
					i++;
				}
				if (day == 0) { day = 1; }
				month += (value_d / leap_0[3]) % 12;
				year += (month / 12) + value_d / 365;
			}
			else { day = value_d; }
		break;
	case 5:
			if (value_d > leap_0[4]) {
				i = 4;
				while (day > value_d% leap_0[i]) {
					day = value_d % leap_0[i];
					i++;
				}
				if (day == 0) { day = 1; }
				month += (value_d / leap_0[4]) % 12;
				year += (month / 12) + value_d / 365;
			}
			else { day = value_d; }
		break;
	case 6:
			if (value_d > leap_0[5]) {
				i = 5;
				while (day > value_d% leap_0[i]) {
					day = value_d % leap_0[i];
					i++;
				}
				if (day == 0) { day = 1; }
				month += (value_d / leap_0[5]) % 12;
				year += (month / 12) + value_d / 365;
			}
			else { day = value_d; }
		break;
	case 7:
			if (value_d > leap_0[6]) {
				i = 6;
				while (day > value_d% leap_0[i]) {
					day = value_d % leap_0[i];
					i++;
				}
				if (day == 0) { day = 1; }
				month += (value_d / leap_0[6]) % 12;
				year += (month / 12) + value_d / 365;
			}
			else { day = value_d; }
		break;
	case 8:
			if (value_d > leap_0[7]) {
				i = 7;
				while (day > value_d% leap_0[i]) {
					day = value_d % leap_0[i];
					i++;
				}
				if (day == 0) { day = 1; }
				month += (value_d / leap_0[7]) % 12;
				year += (month / 12) + value_d / 365;
			}
			else { day = value_d; }
		break;
	case 9:
			if (value_d > leap_0[8]) {
				i = 8;
				while (day > value_d% leap_0[i]) {
					day = value_d % leap_0[i];
					i++;
				}
				if (day == 0) { day = 1; }
				month += (value_d / leap_0[8]) % 12;
				year += (month / 12) + value_d / 365;
			}
			else { day = value_d; }
		break;
	case 10:
			if (value_d > leap_0[9]) {
				i = 9;
				while (day > value_d% leap_0[i]) {
					day = value_d % leap_0[i];
					i++;
				}
				if (day == 0) { day = 1; }
				month += (value_d / leap_0[9]) % 12;
				year += (month / 12) + value_d / 365;
			}
			else { day = value_d; }
		break;
	case 11:
			if (value_d > leap_0[10]) {
				i = 10;
				while (day > value_d% leap_0[i]) {
					day = value_d % leap_0[i];
					i++;
				}
				if (day == 0) { day = 1; }
				month += (value_d / leap_0[10]) % 12;
				year += (month / 12) + value_d / 365;
			}
			else { day = value_d; }
		break;
	case 12:
			if (value_d > leap_0[11]) {
				i = 11;
				while (day > value_d% leap_0[i]) {
					day = value_d % leap_0[i];
					i++;
				}
				if (day == 0) { day = 1; }
				month += (value_d / leap_0[11]) % 12;
				year += (month / 12) + value_d / 365;
			}
			else { day = value_d; }
		break;
	default:
		std::cout << "Кажется что-то пошло не так";
		break;
	}
		
}
void Date::Set_M (int value_m) { 
	
		if (value_m > 12) {
			month = value_m % 12;
			year += value_m / 12;
		}
		else {
			month = value_m;
		}
	
}
void Date::Set_Y(int value_y) {
	if (year < 1) {
		throw std::invalid_argument("Year less than one");
	}
	else {
		year = value_y;
	}
}

void Date::print() {
	std::cout << Get_D() << "." << Get_M() << ":" << Get_Y() << std::endl;
}

void Date::input() {
	int d, m, y;
	std::cout << "Введите день - ";
	std::cin >> d;
	std::cout << "Введите месяц - ";
	std::cin >> m;
	std::cout << "Введите год - ";
	std::cin >> y;

	Set_Y(y);
	Set_M(m);
	Set_D(d);

	std::cout << "Полученная дата: ";
	print();

}


void Date::inputStr() {
	int  i = 0, j = 0,da,mo,ye;
	int zer = (int)'0';
	char str[100];
	char d[3],m[3],y[5];
	
	std::cout << "Введите дату в формате dd.mm:yyyy" << std::endl;
	std::cin >> str;

	while (str[i] != '.' && str[i] != ',' && str[i] != ' ')
	{
		d[j] = str[i];
		i++; j++;
	}
	if (j == 1) { 
		std::cout << "Введён неверный формат времени\n";
	}
	i++; j = 0;
	da = (((int)d[0] - zer) * 10) + ((int)d[1] - zer);
	
	while (str[i] != ':' && str[i] != ',' && str[i] != ' ' && str[i] != '.') {
		m[j] = str[i];
		i++; j++;
	}
	j = 0; i++;
	mo = (((int)m[0] - zer) * 10) + ((int)m[1] - zer);
	
	while (i < 10) {
		y[j] = str[i];
		i++; j++;
	}

	ye = (((int)y[0] - zer) * 1000) + (((int)y[1] - zer) * 100) + (((int)y[2] - zer) * 10) + ((int)y[3] - zer);
	
	Set_Y(ye);
	Set_M(mo);
	Set_D(da);
}

Date& Date::operator=(const Date& c) {
	day = c.day;
	month = c.month;
	year = c.year;
	return *this;
}

Date Date::operator-(const Date& c) {
	Date res;
	res.day = this->day - c.day;
	res.month = this->month - c.month;
	res.year = this->year - c.year;
	return res;
}

Date Date::operator+(const Date& c) {
	Date res;
	res.day = this->day + c.day;
	res.month = this->month + c.month;
	res.year = this->year+(c.year - year);
	return res;
}

bool Date::operator==(const Date& c) {
	bool res;
	res = (day == c.day) && (month == c.month) && (year == c.year);
	return res;
}

bool Date::operator!=(const Date& c) {
	bool res;
	res = (day != c.day) || (month != c.month) || (year != c.year);
	return res;
}

std::ostream& operator << (std::ostream& stream, const Date& c) {
	stream << c.day << ".";
	stream << c.month << ":";
	stream << c.year;
	return stream;
}

std::istream& operator >> (std::istream& stream, Date& c) {
	stream >> c.day >> c.month >> c.year;
	return stream;
}
