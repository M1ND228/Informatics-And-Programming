#pragma once
#include "Credit.h"
#include "ProcCenter.h"
#include <string>

using namespace std;

class Bank 
{
public:
	Bank();
	Bank(int memory_,int count_, int position_, Credit* list_credit_, ProcCenter* list_user_);
	Bank(const Bank& c);

	~Bank();

	//		 INPUT			
	string signInPas();
	int signInChet();

	//		Function		
	void infoCredit();				// Information on the loan
	void registration();			// Registration of user
	void logAccount();				// Log in to your account
	void takeCredit();				// Credit registration
	void one_pay();					// Monthly payment
	void payOff();					// Pay off the entire amount
	void inputCount();				// Number of accounts
	string controlInputPas(int i);
	void timer();

	Bank& operator = (const Bank& c);

private:
	int memory;						// Memory monitoring	
	int count;						// Number of accounts
	int position;					// To log in to your account
	Credit* list_credit;			// List of loans taken
	ProcCenter* list_user;			// List of registered accounts
};
