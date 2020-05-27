#include "Snake.h";
#include <iostream>
#include <Windows.h>
#include <stdlib.h>

void mainMenu(Snake& s)
{
    int choose = -1;
    system("cls");
    std::cout << "����: \n";
    std::cout << "1 - ������ ����\n";
    std::cout << "2 - ������� ����\n";
    std::cout << "3 - ����� �� ����\n> ";
    std::cin >> choose;
    switch (choose)
    {
    case 1:
        s.PLAY();
        s.~Snake();
        mainMenu(s);
        break;
    case 2:
        s.Rules();
        mainMenu(s);
        break;
    case 3:
        exit(true);
        break;
    default:
        system("cls");
        std::cout << "������� �� ����� ���-�� ����...";
        break;
    }
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    system("cls");

    Snake s1;
    mainMenu(s1);
}