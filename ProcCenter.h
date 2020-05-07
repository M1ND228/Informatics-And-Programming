#pragma once
#include <string>

using namespace std;

class ProcCenter
{
public:
	ProcCenter();
	ProcCenter(int code_,string password_, string name_, string surname_, string midName_);
	ProcCenter(const ProcCenter& c);

	~ProcCenter();

	void Set_code(int code_);
	int Get_code();
	
	void Set_password(string password_);
	void Set_name(string name_);
	void Set_surname(string surname_);
	void Set_midName(string midName_);

	string Get_password();
	string Get_name();
	string Get_surname();
	string Get_midName();

	string input_FIO();
	string input_password();

	ProcCenter createAccount();

private:
	int code;
	string password;
	string name;					// Name
	string surname;					// Surname
	string midName;					// Middle name 
};
