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
		//cout << "Вводите число от" << MIN << " до " << MAX << ": ";
		
		if (!scanf_s("%d", &num))
		{
			do {
				res = scanf_s("%d", &num);
				while (getchar() != '\n');
				if (res == 1);
				else cout << "Ошибка ввода! Вводите числа!\nВвод: ";
			} while (res != 1);
		}
	} while (num < MIN || num > MAX);

	return num;
}

void waitingInput()
{
	char point[3] = { '.','.','.' };
	int i = 0;
	cout << "\nНажмите для продолжения";
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
	cout << "Меню:\n";
	cout << "1 - Просмотреть словарь\n";
	cout << "2 - Добавить слово в словарь\n";
	cout << "3 - Узнать перевод слова\n";
	cout << "4 - Изменить перевод слова\n";
	cout << "5 - Проверить наличие слова в словаре\n";
	cout << "6 - Узнать количство слов в словаре\n";
	cout << "7 - Записать словарь В файл\n";
	cout << "8 - Прочитать словарь С файла\n";
	cout << "- - - - - - - - - - - - - - -\n";
	cout << "0 - Выход из приложения\n\n";
	cout << "Ввод: ";
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
		cout << "Введите количество слов: ";
		int words;
		words = checkInput(0, 100);
		d1.add(words);
		cout << "Словарь обновлён";
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
		cout << "\nКоличество слов в словаре: " << d1.Get_lastChange() << "\n";
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
		cout << "Спасибо за использование этого приложения!\n";
		Sleep(1000);
		exit(EXIT_SUCCESS);
		break;
	default:
		system("cls");
		cout << "Кажется что-то пошло не так\n";
		mainMenu(d1);
		break;

	}
}



int main() {
	SetConsoleCP(1251);// установка кодовой страницы win-cp 1251 в поток ввода
	SetConsoleOutputCP(1251); // установка кодовой страницы win-cp 1251 в поток вывода
	
	system("cls");
	string* test;
	string* test2;
	int change = 0;
	test = new string[100];
	test2 = new string[100];
	for (int i = 0; i < 5; i++)
	{
		test[i] = "R";
		test2[i] = "П";
		change++;
	}

	Dictionary d1,d2,d3;

	cout << "Тест конструкторов\n";
	cout << "Конструктор по умолчанию: " << Dictionary();
	std::cout << "\nКонструктор с параметрами: \n" << Dictionary(test,test2,50,change);
	Dictionary test3(test, test2, 50, change);
	Dictionary test4(test3);
	cout << "\nКонструктор копирования: \n" << test4;
	test4.~Dictionary();
	// Test4 can no Longer be accessed

	cout << "\nТест перегрузок\n";
	d1.add(1);
	cout << d1;
	d2.add(2);
	cout << "Первый словарь\n" << d1;
	cout << "\nВторой словарь\n" << d2;
	d1 = d1 + d2;
	cout << "Результат объеденения двух словарей: \n";
	cout << d1;
	cout << "\nРезультат присваивания\n";
	d3 = d1;

	cout << d3;

	system("pause");
	
	mainMenu(d1);
		

}