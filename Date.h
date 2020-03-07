#pragma once


class Date
{
public:
	Date();
	Date(int _d, int _m, int _y);
	Date(const Date& c);

	~Date();

	int  Get_D();
	int  Get_M();
	int  Get_Y();

	void Set_D(int value_d);
	void Set_M(int value_m);
	void Set_Y(int value_y);

	void print();
	void input();
	void inputStr();

	// Перегрузки

	Date& operator = (const Date& c);
	Date  operator + (const Date& c);
	Date  operator - (const Date& c);

	bool operator == (const Date& c);
	bool operator != (const Date& c);

	friend std::ostream& operator << (std::ostream& stream, const Date& c);
	friend std::istream& operator >> (std::istream& stream, Date& c);

private:
	int day;
	int month;
	int year;
	char date;
};
