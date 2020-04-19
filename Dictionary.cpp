#define _CRT_SECURE_NO_WARNINGS
#include "Dictionary.h"
#include <windows.h>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

Dictionary::Dictionary() {
	size = 80000;				// Up to 80 000 words
	lastChange = 0;
    en = new string[size];
	ru = new string[size];
};


Dictionary::Dictionary(string* ru_, string* en_, int size_,int lastChange_) {
	size = size_;
	lastChange = lastChange_;
	en = new string[size];
	ru = new string[size];
	for (int i = 0; i < size_; i++) {
		en[i] = en_[i];
		ru[i] = ru_[i];
	}
}

Dictionary::Dictionary(const Dictionary& c) {
	size = c.size;
	lastChange = c.lastChange;
	en = new string[size];
	ru = new string[size];
	for (int i = 0; i < size; i++) {
		en[i] = c.en[i];
		ru[i] = c.ru[i];
	}
}

Dictionary::~Dictionary() {
	size = 0;
	lastChange = 0;
	delete[] en;
	delete[] ru;
}	

int Dictionary::Get_lastChange() { return lastChange; }

void Dictionary::add(int words) {
	bool sys = true;
	for (int i = 0; i < words; i++) {
		if (lastChange >= size) { cout << "Словарь переполнен.\n"; Sleep(1000); sys = false; break; }
		cout << "Введите слово на Английском\nВвод:";
		cin >> en[lastChange];
		system("cls");
		cout << "Введите перевод слова " << en[lastChange] << "\t";
		cin >> ru[lastChange]; 
		lastChange++;
	}
	system("cls");
	if(sys){ cout << "Словарь обновлён"; }
}

void Dictionary::print() {
	if (lastChange == 0) { cout << "Словарь пуст.\n"; }
	else {
		cout << "   Английский" << "\t\tРусский\n";
		for (int i = 0; i < lastChange; i++) {
			cout << i + 1 << ") ";
			cout << en[i] << "\t\t";
			cout << ru[i] << "\n";
		}
	}
}

void Dictionary::findWord(){
	string check;
	cout << "Введите слово для нахождения\nВвод: ";
	cin  >> check;
	bool flag = 0;
	for (int i = 0; i < lastChange; i++) {
		if (ru[i] == check || en[i] == check) {
			cout << "Слово находится в словаре на " << i + 1 << " строчке.";
			flag = 1;
			break;
		}
	}
	if (flag == 0) { cout << "К сожалению совпадений не найдено.\n"; }
}

void Dictionary::findTranslate() {
	string translate;
	cout << "Введите слово для поиска в словаре\nВвод: ";
	cin >> translate;
	bool flag = 0;
	for (int i = 0; i < lastChange; i++) {
		if (en[i] == translate) {
			cout << "\n" << en[i] << "   " << ru[i];
			flag = 1;
			break;
		}
	}
	if (flag == 0) { cout << "К сожалению слова нет в словаре, но вы можете его добавить.\n"; }
}


void Dictionary::changeTranslate() {
	string change;
	cout << "Введите слово для замены перевода\nВвод: ";
	cin >> change;
	bool flag = 0;
	for (int i = 0; i < lastChange; i++) {
		if (en[i] == change) {
			cout << "Изменить перевод: \n";
			cout << en[i] << "     ";
			cin >> ru[i];
			flag = 1;
			system("cls");
			cout << "Словарь успешно обновлён.\n";
			Sleep(900);
			flag = 1;
			break;
		}
	}
	if (flag == 0) { cout << "К сожалению слова нет в словаре, но вы можете его добавить.\n"; }
}

int Dictionary::outputFile() {
	FILE* file = fopen("C:\\Users\\DIMA\\Desktop\\output.txt", "w");
	if (file == NULL)
	{
		std::cout << "Не удалось открыть файл для записи\n";
		return 0;
	}else {
	fprintf(file, " _______________________________\n");
	fprintf(file, "| Английский\t"  "\tРусский |\n");
	for (int i = 0; i < lastChange; i++)
	{
		fprintf(file, "|%12s ", en[i].c_str());
		fprintf(file, "%17s | ", ru[i].c_str());
		fprintf(file, "\n");
	}
	fprintf(file, "|_______________________________|\n");
	std::cout << "Данные успешно записаны в файл!\n";
	}
	fclose(file);
	return 1;
}

int Dictionary::inputFile() {
	ifstream F;
	F.open("C:\\Users\\DIMA\\Desktop\\input.txt", ios::in);
	int i = lastChange;
	bool sys = true;
	while (!F.eof())
	{
		if (lastChange >= size) { cout << "Словарь переполнен.\n"; Sleep(1000); sys = false; break; }
		F >> en[i] >> ru[i];
		lastChange++;
		i++;
	}
	F.close();
	if (sys) { cout << "Данные успешно прочтены\n"; }
	
	
	return 1;
}

Dictionary& Dictionary::operator=(const Dictionary& c) {
	size = c.size;
	lastChange = c.lastChange;
	for (int i = 0; i < lastChange; i++) {
		en[i] = c.en[i];
		ru[i] = c.ru[i];
	}
	
	return *this;
}

Dictionary  Dictionary::operator+(const Dictionary& c) {
	Dictionary res;
	int allLength = lastChange + c.lastChange;
	for (int i = 0; i < lastChange; i++)
	{
		res.en[i] = en[i];
		res.ru[i] = ru[i];
	}
	for (int i = 0; i < c.lastChange; i++)
	{
		res.en[i+lastChange] = c.en[i];
		res.ru[i+lastChange] = c.ru[i];
	}
	res.lastChange = allLength;
	return res;
}

std::ostream& operator << (std::ostream& stream, const Dictionary& c) {
	if (c.lastChange == 0) { stream << "Словарь пуст.\n"; }
	else {
		for (int i = 0; i < c.lastChange; i++) {
			stream << i + 1 << ") ";
			stream << c.en[i] << "\t\t";
			stream << c.ru[i] << "\n";
		}
	}
	return stream;
}

std::istream& operator >> (std::istream& stream, Dictionary& c) {
		cout << "Введите слово на Английском\nВвод:";
		cin >> c.en[c.lastChange];
		cout << "Введите перевод слова " << c.en[c.lastChange] << "\t";
		cin >> c.ru[c.lastChange];
		c.lastChange++;
	
	return stream;
}
