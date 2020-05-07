#pragma once
#include "Credit.h"
#include "ProcCenter.h"
#include <string>

using namespace std;

class Bank 
{
public:
	Bank();
	Bank(int count_, int position_, Credit* list_credit_, ProcCenter* list_user_);
	Bank(const Bank& c);

	~Bank();

	//		 INPUT			
	string makeLoan();
	string signInPas();
	int signInChet();

	//		Function		
	void infoCredit();				// Информация по кредиту
	void registration();			// Регестрация
	void logAccount();				// Вход в аккаунт
	void takeCredit();				// Oformit credit
	void one_pay();					// Ежемесячный платёж
	void payOff();					// Погасить всю сумму
	void inputCount();				// Количество аккаунтов

	Bank& operator = (const Bank& c);

private:
	int count;						// количество аккаунтов
	int position;					// для входа в аккаунт
	Credit* list_credit;
	ProcCenter* list_user;
};
