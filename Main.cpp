#include "Snake.h";
#include <iostream>
#include <Windows.h>
#include <stdlib.h>

void mainMenu(Snake& s)
{
    int choose = -1;
    system("cls");
    std::cout << "Меню: \n";
    std::cout << "1 - Начать игру\n";
    std::cout << "2 - Правила игры\n";
    std::cout << "3 - Выйти из игры\n> ";
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
        std::cout << "Кажется вы ввели что-то нето...";
        break;
    }
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    system("cls");
    int mass1[100], mass2[100];
    eDir dir1 = eDir::STOP;
    Snake s1;
    Snake s3(false, 2, 2, 0, 0, mass1, mass2, 0, 16, 10, 0, dir1);
    Snake s2(s3);
    mainMenu(s2);
}