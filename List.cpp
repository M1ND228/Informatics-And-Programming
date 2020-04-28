#include "List.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

List::List() {
	count = 0;
	memory = 50;
	list = new Contacts[memory];
}

List::List(int count_, int memory_, Contacts* list_) {
	count = count_;
	memory = memory_;
	list = new Contacts[memory];
	for (int i = 0; i < count; i++)
	{
		list[i] = list_[i];
	}
}

List::List(const List& c) {
	count = c.count;
	memory = c.memory;
	list = new Contacts[memory];
	for (int i = 0; i < count; i++)
	{
		list[i] = c.list[i];
	}
}

List::~List() {
	count = 0;
	memory = 0;
	delete[] list;
}

int List::Get_count() { return this->count; }

string List::input_char() {
	string ch;
	cout << "Введите букву для поиска: \nВвод: ";
	cin >> ch;
	return ch;
}

string List::input_phone() {
	string phone;
	cout << "Введите номер телефона для поиска: \nВвод: ";
	cin >> phone;
	return phone;
}

string List::input_FIO() {
	string s1, n1, m1;
	cout << "Введите ФИО для поиска: ";
	cin >> s1;
	cin >> n1;
	cin >> m1;
	string str;
	str = s1 + "|" + n1 + "|" + m1;
	return str;
}

void List::newElement(int num) {

	for (int i = 0; i < num; i++)
	{
		if (count + 1 > memory)
		{
			Contacts* new_list = new Contacts[count + 1];
			for (int i = 0; i < count; i++)
			{
				new_list[i] = list[i];
			}
			delete[]list;
			list = new Contacts[count + 1];
			for (int i = 0; i < count; i++)
			{
				list[i] = new_list[i];
			}
			memory++;
			delete[] new_list;
		}
		list[count] = add();
		count++;
		system("cls");
	}
	sortContacts();
	cout << "Контактная база обнавлена\n\n";
	(void)getchar();

}

// ввод
void List::changeContact() {
	string str1, str2, str3;
	int day_, month_, year_;
	string phone;
	int choose;
	bool find = false;

	string* s1 = new string[5];
	string str = input_FIO();
	
	int j = 0;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == '|') { j++; }
		else { s1[j] += str[i]; }
	}

	for (int i = 0; i < count; i++)
	{
		if (s1[0] == list[i].Get_surname() && s1[1] == list[i].Get_name() && s1[2] == list[i].Get_midName())
		{
			find = true;
			cout << "Контакт был найден:\n";
			cout << "ФИО: " << list[i].Get_surname().c_str() << " " << list[i].Get_name().c_str() << " " << list[i].Get_midName().c_str() << "\n";
			cout << "День рождение: " << list[i].Get_day() << " " << list[i].Get_month() << " " << list[i].Get_year() << "\n";
			cout << "Телефон: " << list[i].Get_phone().c_str() << "\n";
			if (list[i].Get_favorit()) { cout << "Избранный: Да\n\n"; }
			else { cout << "Избранный: Нет\n\n"; }

			cout << "\nКакую информацию вы хотите заменить?\n";
			cout << "1 - ФИО\n";
			cout << "2 - Дату рождения\n";
			cout << "3 - Номер телефона\n";
			cout << "4 - Избранность\n";
			cout << "- - - - - - - - - - - - -\n";
			cout << "0 - Назад\n";
			cout << "Ввод: ";
			cin >> choose;
			switch (choose)
			{
			case 1:
				system("cls");
				cout << "Фамилия: ";
				cin >> str1;
				list[i].Set_surname(str1);
				cout << "\nИмя: ";
				cin >> str2;
				list[i].Set_name(str2);
				cout << "\nОтчество: ";
				cin >> str3;
				list[i].Set_midName(str3);
				cout << "Данные успешно изменены...\n";
				(void)getchar(); (void)getchar();
				break;
			case 2:
				system("cls");
				cout << "День: ";
				cin >> day_;
				list[i].Set_day(day_);
				cout << "\nМесяц: ";
				cin >> month_;
				list[i].Set_month(month_);
				cout << "\nГод: ";
				cin >> year_;
				list[i].Set_year(year_);
				cout << "Данные успешно изменены...\n";
				(void)getchar(); (void)getchar();
				break;
			case 3:
				system("cls");
				cout << "Введите телефон\n";
				cin >> phone;
				list[i].Set_phone(phone);
				cout << "Данные успешно изменены...\n";
				(void)getchar(); (void)getchar();
				break;
			case 4:
				system("cls");
				if (list[i].Get_favorit()) { list[i].Set_favorit(false); cout << "Контакт изменён на не избранный\n"; (void)getchar(); (void)getchar(); }
				else { list[i].Set_favorit(true);  cout << "Контакт изменён на избранный\n"; (void)getchar(); (void)getchar(); }
				break;
			case 0:
				break;
			default:
				system("cls");
				cout << "Кажется что-то пошло не так...\n";
				system("pause");
				break;
			}
		}
	}
	if (find == false) { cout << "Контакт не был найден.\n\n"; (void)getchar(); (void)getchar(); }
}

void List::sortContacts() {
	for (int i = 0; i < count; i++)
	{
		for (int j = 1; j < count; j++)
		{
			if (list[i].Get_surname() < list[j - 1].Get_surname())
			{
				// Surname
				string tmp1 = list[i].Get_surname();
				list[i].Set_surname(list[j - 1].Get_surname());
				list[j - 1].Set_surname(tmp1);
				// Name
				string tmp2 = list[i].Get_name();
				list[i].Set_name(list[j - 1].Get_name());
				list[j - 1].Set_name(tmp2);
				// MidName
				string tmp3 = list[i].Get_midName();
				list[i].Set_midName(list[j - 1].Get_midName());
				list[j - 1].Set_midName(tmp3);
				// Day
				int tmp4 = list[i].Get_day();
				list[i].Set_day(list[j - 1].Get_day());
				list[j - 1].Set_day(tmp4);
				// Month
				int tmp5 = list[i].Get_month();
				list[i].Set_month(list[j - 1].Get_month());
				list[j - 1].Set_month(tmp5);
				// Year
				int tmp6 = list[i].Get_year();
				list[i].Set_year(list[j - 1].Get_year());
				list[j - 1].Set_year(tmp6);
				// Phone
				string tmp7 = list[i].Get_phone();
				list[i].Set_phone(list[j - 1].Get_phone());
				list[j - 1].Set_phone(tmp7);
				// Favoroit
				bool tmp8 = list[i].Get_favorit();
				list[i].Set_favorit(list[j - 1].Get_favorit());
				list[j - 1].Set_favorit(tmp8);
			}
		}
	}
}

void List::print() {
	if (count < 1) { cout << "База контактов пуста\n"; }
	else {
		cout << "Контактов: " << count << "\n";
		cout << "Список контактов:\n";
		sortContacts();
		for (int i = 0; i < count; i++)
		{
			cout << i + 1 << ") " << list[i].Get_surname() << " " << list[i].Get_name() << " " << list[i].Get_midName() << ".\n";
		}
	}
}

void List::printFavorit() {
	cout << "Избранные контакты: \n";
	int j = 0;
	bool find = false;
	sortContacts();
	for (int i = 0; i < count; i++)
	{
		if (list[i].Get_favorit() == true)
		{
			j++;
			cout << j << ") " << list[i].Get_surname() << " " << list[i].Get_name() << " " << list[i].Get_midName() << ".\n";
			find = true;
		}
	}
	if (find == false) { cout << "Список избранных контактов пуст\n"; (void)getchar(); (void)getchar(); }
}
// ввод
void List::findSNM() {
	bool find = false;
	string* s1 = new string[5];
	string str = input_FIO();

	int j = 0;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == '|') { j++; }
		else { s1[j] += str[i]; }
	}

	for (int i = 0; i < count; i++)
	{
		if (s1[0] == list[i].Get_surname() && s1[1] == list[i].Get_name() && s1[2] == list[i].Get_midName())
		{
			cout << "Контакт был найден:\n";
			cout << "ФИО: " << list[i].Get_surname().c_str() << " " << list[i].Get_name().c_str() << " " << list[i].Get_midName().c_str() << "\n";
			cout << "День рождение: " << list[i].Get_day() << " " << list[i].Get_month() << " " << list[i].Get_year() << "\n";
			cout << "Телефон: " << list[i].Get_phone().c_str() << "\n";
			if (list[i].Get_favorit()) { cout << "Избранный: Да\n\n"; }
			else { cout << "Избранный: Нет\n\n"; }
			bool find = false;
		}
	}
	if (find == false) { cout << "Совпадений не найдено\n"; (void)getchar(); (void)getchar(); }
}
// ввод
void List::findFirstChar() {
	string s1;
	string s2;
	bool find = false;
	s1 = input_char();
	cout << "\n";
	for (int i = 0; i < count; i++)
	{
		s2 = list[i].Get_surname();														
		if (s1[0] == s2[0])
		{
			cout << "ФИО: " << list[i].Get_surname().c_str() << " " << list[i].Get_name().c_str() << " " << list[i].Get_midName().c_str() << "\n";
			cout << "День рождение: " << list[i].Get_day() << " " << list[i].Get_month() << " " << list[i].Get_year() << "\n";
			cout << "Телефон: " << list[i].Get_phone().c_str() << "\n";
			if (list[i].Get_favorit()) { cout << "Избранный: Да\n\n"; }
			else { cout << "Избранный: Нет\n\n"; }
			bool find = true;
		}
	}
	if (find == false) { cout << "Контактов не найдено\n\n"; (void)getchar(); (void)getchar(); }
}
// ввод
void List::addFavorit() {
	bool find = false;
	string* s1 = new string[5];
	string str = input_FIO();

	int j = 0;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == '|') { j++; }
		else { s1[j] += str[i]; }
	}

	for (int i = 0; i < count; i++)
	{
		if (s1[0] == list[i].Get_surname() && s1[1] == list[i].Get_name() && s1[2] == list[i].Get_midName())
		{
			cout << "Контакт был найден:\n";
			cout << "ФИО: " << list[i].Get_surname().c_str() << " " << list[i].Get_name().c_str() << " " << list[i].Get_midName().c_str() << "\n";
			if (list[i].Get_favorit()) { cout << "Контакт находится в избранных\n\n"; }
			else { list[i].Set_favorit(true); cout << "Контакт был добавлен в избранные\n\n"; }
			find = true;
		}
	}
	if (find == false) { cout << "Контакт не был найден\n"; (void)getchar(); (void)getchar(); }
}

int List::outputFile() {
	FILE* file = fopen("C:\\Users\\Dima\\Desktop\\output.txt", "w");
	if (file == NULL)
	{
		std::cout << "Файл не удалось открыть\n";
		return 0;
	}
	else {
		sortContacts();
		for (int i = 0; i < count; i++)
		{
			fprintf(file, "Контакт № %d\n", i + 1);
			fprintf(file, "ФИО: %s %s %s.\n", list[i].Get_surname().c_str(), list[i].Get_name().c_str(), list[i].Get_midName().c_str());
			fprintf(file, "День рождение: %d.%d:%d\n", list[i].Get_day(), list[i].Get_month(), list[i].Get_year());
			fprintf(file, "Телефон: %s\n", list[i].Get_phone().c_str());
			if (list[i].Get_favorit()) { fprintf(file, "Избранный: Да\n\n"); }
			else { fprintf(file, "Избранный: Нет\n\n"); }
		}
		cout << "Данные успешно записанны в файл\n\n";
	}
	fclose(file);
	return 1;
}

int List::inputFile() {
	string name_;
	string surname_;
	string midName_;
	int day_; 
	int month_; 
	int year_; 
	string phone_; 
	string favorit_;
	ifstream F;
	F.open("C:\\Users\\DIMA\\Desktop\\input.txt", ios::in);
	int i = count;
	bool sys = true;
	while (!F.eof())
	{
		if (count + 1 > memory)
		{
			Contacts* new_list = new Contacts[count + 1];
			for (int i = 0; i < count; i++)
			{
				new_list[i] = list[i];
			}
			delete[]list;
			list = new Contacts[count + 1];
			for (int i = 0; i < count; i++)
			{
				list[i] = new_list[i];
			}
			memory++;
			delete[] new_list;
		}
		F >> surname_ >> name_ >> midName_;
		F >> day_ >> month_ >> year_;
		F >> phone_ >> favorit_;
		list[i].Set_surname(surname_);
		list[i].Set_name(name_);
		list[i].Set_midName(midName_);
		list[i].Set_day(day_);
		list[i].Set_month(month_);
		list[i].Set_year(year_);
		list[i].Set_phone(phone_);
		if (favorit_ == "true" || favorit_ == "1" || favorit_ == "Да" || favorit_ == "да") { list[i].Set_favorit(true); }
		else { list[i].Set_favorit(false); }
		count++;
		i++;
	}
	F.close();
	sortContacts();
	cout << "Даннные успешно прочтены\n";
	(void)getchar(); (void)getchar();
	return 1;
}

void List::countContacts() {
	
	cout << "Контактов в базе: " << Get_count()  << "\n";
}
// ввод
void List::delFavorit() {
	bool search = false;
	string* s1 = new string[5];
	string str = input_FIO();

	int j = 0;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == '|') { j++; }
		else { s1[j] += str[i]; }
	}

	for (int i = 0; i < count; i++)
	{
		if (s1[0] == list[i].Get_surname() && s1[1] == list[i].Get_name() && s1[2] == list[i].Get_midName())
		{
			if (list[i].Get_favorit() == true)
			{
				search = true;
				cout << "Контакт: " << list[i].Get_surname() << " " << list[i].Get_name() << " " << list[i].Get_midName() << " - был удалён из избранных.\n";
				list[i].Set_favorit(false);
			}
			else { cout << "Контакт был найден,но он находится не в избранных.\n"; }
		}
	}
	if (search == false) { cout << "Контакт не был найден.\n"; (void)getchar(); (void)getchar(); }
}
// ввод
void List::findPhone() {
	string phone;
	phone = input_phone();
	for (int i = 0; i < count; i++)
	{
		if (phone == list[i].Get_phone())
		{
			cout << "ФИО: " << list[i].Get_surname().c_str() << " " << list[i].Get_name().c_str() << " " << list[i].Get_midName().c_str() << "\n";
			cout << "День рождение: " << list[i].Get_day() << " " << list[i].Get_month() << " " << list[i].Get_year() << "\n";
			cout << "Телефон: " << list[i].Get_phone().c_str() << "\n";
			if (list[i].Get_favorit()) { cout << "Избранный: Да\n"; }
			else { cout << "Избранный: Нет\n\n"; }
		}
	}
}
// ввод
void List::delContactPhone() {
	string phone;
	phone = input_phone();
	int chain;
	bool search = false;
	for (int i = 0; i < count; i++)
	{
		if (phone == list[i].Get_phone())
		{
			chain = i;
			cout << "Данный контакт был удалён:\n";
			cout << "ФИО: " << list[i].Get_surname().c_str() << " " << list[i].Get_name().c_str() << " " << list[i].Get_midName().c_str() << "\n";
			search = true;
			break;
		}
	}
	if (search == true)
	{
		Contacts* new_list = new Contacts[memory - 1];
		for (int i = 0, j = 0; i < count; i++)
		{
			if (i == chain) {}
			else
			{
				new_list[j] = list[i];
				j++;
			}
		}
		delete[]list;
		count--;
		list = new Contacts[memory - 1];
		for (int i = 0; i < count; i++)
		{
			list[i] = new_list[i];
		}
		memory--;
		delete[] new_list;
	}
	if (search == false) { cout << "Контакт не был найден\n"; }
}