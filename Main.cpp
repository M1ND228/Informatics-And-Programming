#include "Contacts.h"
#include "List.h"
#include <iostream>
#include <Windows.h>

void mainMenu(List& l1)
{
	system("cls");
	int choose = 0;
	cout << "\t\t      � � � �\n";
	cout << "|- - - - - - - - - - - - - - - - - - - - - - - -|\n";
	cout << "|1  - �������� �������			        |\n";
	cout << "|2  - �������� ������� � ���������	        |\n";
	cout << "|3  - �������� �������                          |\n";
	cout << "|4  - ������ ���������			        |\n";
	cout << "|5  - ������ ��������� ���������	        |\n";
	cout << "|6  - ������ ���������� ���������               |\n";
	cout << "|7  - ����� ��������	                        |\n";
	cout << "|8  - ����� ��������� �� ������ �����	        |\n";
	cout << "|9  - ����� �������� �� ������ ��������	        |\n";
	cout << "|10 - ������� ������� �� ���������	        |\n";
	cout << "|11 - ������� ������� ��������� �� ��������     |\n";
	cout << "|12 - ��������� �������� � �����	        |\n";
	cout << "|13 - ������� ������ ��������� � ����           |\n";
	cout << "|- - - - - - - - - - - - - - - - - - - - - - - -|\n";
	cout << "|0  - ����� �� ����������		        |\n";
	cout << "|- - - - - - - - - - - - - - - - - - - - - - - -|\n\n";
	cout << "����: ";
	cin >> choose;
	switch (choose)
	{
	case 1:
		system("cls");
		l1.newElement(1);
		system("pause");
		mainMenu(l1);
		break;
	
	case 2:
		system("cls");
		l1.addFavorit();
		system("pause");

		mainMenu(l1);
		break;
	case 3:
		system("cls");
		l1.changeContact();

		mainMenu(l1);
	case 4:
		system("cls");
		l1.print();
		system("pause");

		mainMenu(l1);
		break;
	case 5:
		system("cls");
		l1.printFavorit();
		system("pause"); 

		mainMenu(l1);
		break;
	case 6:
		system("cls");
		l1.countContacts();
		system("pause");

		mainMenu(l1);
		break;
	case 7:
		system("cls");
		l1.findSNM();
		system("pause");

		mainMenu(l1);
		break;
	case 8:
		system("cls");
		l1.findFirstChar();
		system("pause");

		mainMenu(l1);
		break;
	case 9:
		system("cls");
		l1.findPhone();
		system("pause"); 

		mainMenu(l1);
		break;	
	case 10:
		system("cls");
		l1.delFavorit();
		system("pause");

		mainMenu(l1);
		break;
	case 11:
		system("cls");
		l1.delContactPhone();
		system("pause");

		mainMenu(l1);
		break;
	case 12:
		system("cls");
		l1.inputFile();
		system("pause");

		mainMenu(l1);
		break;
	case 13:
		system("cls");
		l1.outputFile();
		system("pause");

		mainMenu(l1);
		break;
	case 0:
		system("cls");
		cout << "������� �� �c����������� ����� ����������!\n";
		Sleep(1000);
		exit(EXIT_SUCCESS);
		break;
	default:
		system("cls");
		cout << "������� ���-�� ����� �� ���...\n";
		system("pause");
		mainMenu(l1);
		break;

	}
}

int main() {
	SetConsoleCP(1251);				// ��������� ������� �������� win-cp 1251 � ����� �����
	SetConsoleOutputCP(1251);		// ��������� ������� �������� win-cp 1251 � ����� ������
	system("cls");

	List l1;
	mainMenu(l1);

	system("pause");
	return 0;
}