#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include <cstdlib>  
#include <Windows.h>
#include "Dictionary.h"

int checkInput(int MIN, int MAX) {
	int num,res;
	num = 0;

	do {
		//cout << "������� ����� ��" << MIN << " �� " << MAX << ": ";
		
		if (!scanf_s("%d", &num))
		{
			do {
				res = scanf_s("%d", &num);
				while (getchar() != '\n');
				if (res == 1);
				else cout << "������ �����! ������� �����!\n����: ";
			} while (res != 1);
		}
	} while (num < MIN || num > MAX);

	return num;
}

void waitingInput()
{
	char point[3] = { '.','.','.' };
	int i = 0;
	cout << "\n������� ��� �����������";
	for (i = 0; i < 3; i++)
	{
		cout << point[i];
		Sleep(177);
	}
	while (!_kbhit()) {}
}

void mainMenu(Dictionary d1)
{
	system("cls");
	int choose = 0;
	cout << "����:\n";
	cout << "1 - ����������� �������\n";
	cout << "2 - �������� ����� � �������\n";
	cout << "3 - ������ ������� �����\n";
	cout << "4 - �������� ������� �����\n";
	cout << "5 - ��������� ������� ����� � �������\n";
	cout << "6 - ������ ��������� ���� � �������\n";
	cout << "7 - �������� ������� � ����\n";
	cout << "8 - ��������� ������� � �����\n";
	cout << "- - - - - - - - - - - - - - -\n";
	cout << "0 - ����� �� ����������\n\n";
	cout << "����: ";
	choose = checkInput(0, 8);
	
	switch (choose)
	{
	case 1:
		system("cls");
		d1.print();
		waitingInput();
		mainMenu(d1);
		break;
	case 2:
		system("cls");
		cout << "������� ���������� ����: ";
		int words;
		words = checkInput(0, 100);
		d1.add(words);
		cout << "������� �������";
		Sleep(800);
		mainMenu(d1);
		break;
	case 3:
		system("cls");
		d1.findTranslate();
		waitingInput();
		mainMenu(d1);
		break;
	case 4:
		system("cls");
		d1.changeTranslate();
		waitingInput();
		mainMenu(d1);
		break;
	case 5:
		system("cls");
		d1.findWord();
		waitingInput();
		system("cls");
		mainMenu(d1);
		break;
	case 6:
		system("cls");
		cout << "\n���������� ���� � �������: " << d1.Get_lastChange() << "\n";
		waitingInput();
		mainMenu(d1);
		break;
	case 7:
		system("cls");
		d1.outputFile();
		waitingInput();
		mainMenu(d1);
		break;
	case 8:
		system("cls");
		d1.inputFile();
		waitingInput();
		mainMenu(d1);
		break;
	case 0:
		system("cls");
		cout << "������� �� ������������� ����� ����������!\n";
		Sleep(1000);
		exit(EXIT_SUCCESS);
		break;
	default:
		system("cls");
		cout << "������� ���-�� ����� �� ���\n";
		mainMenu(d1);
		break;

	}
}



int main() {
	SetConsoleCP(1251);// ��������� ������� �������� win-cp 1251 � ����� �����
	SetConsoleOutputCP(1251); // ��������� ������� �������� win-cp 1251 � ����� ������
	
	system("cls");
	string* test;
	string* test2;
	int change = 0;
	test = new string[100];
	test2 = new string[100];
	for (int i = 0; i < 5; i++)
	{
		test[i] = "R";
		test2[i] = "�";
		change++;
	}

	Dictionary d1,d2,d3;

	cout << "���� �������������\n";
	cout << "����������� �� ���������: " << Dictionary();
	std::cout << "\n����������� � �����������: \n" << Dictionary(test,test2,50,change);
	Dictionary test3(test, test2, 50, change);
	Dictionary test4(test3);
	cout << "\n����������� �����������: \n" << test4;
	test4.~Dictionary();
	// Test4 can no Longer be accessed

	cout << "\n���� ����������\n";
	d1.add(1);
	cout << d1;
	d2.add(2);
	cout << "������ �������\n" << d1;
	cout << "\n������ �������\n" << d2;
	d1 = d1 + d2;
	cout << "��������� ����������� ���� ��������: \n";
	cout << d1;
	cout << "\n��������� ������������\n";
	d3 = d1;

	cout << d3;

	system("pause");
	
	mainMenu(d1);
		

}