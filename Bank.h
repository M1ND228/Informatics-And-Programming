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
	void infoCredit();				// ���������� �� �������
	void registration();			// �����������
	void logAccount();				// ���� � �������
	void takeCredit();				// Oformit credit
	void one_pay();					// ����������� �����
	void payOff();					// �������� ��� �����
	void inputCount();				// ���������� ���������

	Bank& operator = (const Bank& c);

private:
	int count;						// ���������� ���������
	int position;					// ��� ����� � �������
	Credit* list_credit;
	ProcCenter* list_user;
};
