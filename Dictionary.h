#pragma once
#include <string>
using namespace std;
class Dictionary
{
public:
	Dictionary();
	Dictionary(string* ru_, string* en_,int size_,int lastChange_);
	Dictionary(const Dictionary& c);

	~Dictionary();

	int Get_lastChange();

	void add(int words);
	void print();
	void findWord();
	void findTranslate();
	void changeTranslate();

	int outputFile();
	int inputFile();

	// Overloads
	Dictionary& operator = (const Dictionary& c);
	Dictionary  operator + (const Dictionary& c);

	friend std::istream& operator >> (std::istream& stream,  Dictionary& c);
	friend std::ostream& operator << (std::ostream& stream, const Dictionary& c);

private:
	string* ru;
	string* en;
	int size;
	int lastChange;
};
