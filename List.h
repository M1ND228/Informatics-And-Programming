#pragma once
#include "Contacts.h";

class List : public Contacts
{
public:
	List();
	List(int count_, int memory_, Contacts* list_);
	List(const List& c);

	~List();

	int Get_count();

	string input_char();								// Vvod 1 cimBola 
	string input_phone();								// Vvod dlya poiska po Telefony
	string input_FIO();									// Vvod dlya poiska po fio

	void sortContacts();								// Alphabetical sorting
	void newElement(int num);							// Add new Contact
	void changeContact();								// Changing contact information
	void print();										// Print FIO all
	void printFavorit();								// Print FIO only favorit
	void findSNM();										// Find FIO
	void findFirstChar();								// Find first char
	void findPhone();									// Search by phone number
	void addFavorit();									// Add contact in favorit
	void countContacts();								// Print count contacts 
	void delFavorit();									// Change favorit -> default
	void delContactPhone();								// Delete Contact
	

	int outputFile();										
	int inputFile();

private:
	int count;											// Kolichestvo contactov
	int memory;											// Ckolko Bideleno Pamyati
	Contacts *list;										
};