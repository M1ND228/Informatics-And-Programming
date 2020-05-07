#pragma once
#include "ProcCenter.h"
#include <string>

using namespace std;

class Credit 
{
public:
	Credit();
	Credit(int year_, int amount_, int percent_, int salaryAccount_, int payMonth_);
	Credit(const Credit& c);

	~Credit();


	void Set_year(int year_);
	void Set_amount(int amount_);
	void Set_percent(int percent_);
	void Set_salaryAccount(int salaryAccount_);
	void Set_payMonth(int payMonth_);

	int Get_year();
	int Get_amount();
	int Get_percent();
	int Get_salaryAccount();
	int Get_payMonth();

	Credit createCredit();
	int inputAmount(int year);
	int inputMoney();
	int inputYear();
	int corectInput(int min, int max);

private:
	int year;						// Срок кредита
	int amount;						// Общая сумма кредита
	int percent;					// процент кредита
	int salaryAccount;				// Зарплатный счёт
	int payMonth;					// Выплата в месяц
};