#include "Snake.h"
#include <Windows.h>
#include <iostream>
#include <conio.h>
#include <time.h>

Snake::Snake() {
    gameOver = false;
    for (int i = 0; i < 100; i++)
    {
        tailX[i] = { 0 };
        tailY[i] = { 0 };
    }
    dir = eDir::STOP;
    width = 16;
    height = 8;
    x = width / 2 - 1;
    y = height / 2 - 1;
    fruitX = rand() % width - 2;
    fruitY = rand() % height - 1;
    score = 0;
    nTail = 0;
}

Snake::Snake(bool gameOver_, int x_, int y_, int fruitX_, int fruitY_, int tailX_[100], int tailY_[100], int nTail_, int width_, int height_, int score_, eDir dir_) {
    gameOver = gameOver_;
    x = x_;
    y = y_;
    fruitX = fruitX_;
    fruitY = fruitY_;
    for (int i = 0; i < 100; i++)
    {
        tailX[i] = 0;
        tailY[i] = 0;
        tailX[i] = tailX_[i];
        tailY[i] = tailY_[i];
    }
    nTail = nTail_;
    width = width_;
    height = height_;
    score = score_;
    dir = dir_;
}

Snake::Snake(const Snake& c) {
    gameOver = c.gameOver;
    x = c.x;
    y = c.y;
    fruitX = c.fruitX;
    fruitY = c.fruitY;
    for (int i = 0; i < 100; i++)
    {
        tailX[i] = 0;
        tailY[i] = 0;
        tailX[i] = c.tailX[i];
        tailY[i] = c.tailY[i];
    }
    nTail = c.nTail;
    width = c.width;
    height = c.height;
    score = c.score;
    dir = c.dir;
}

Snake::~Snake() {
    gameOver = false;
    for (int i = 0; i < 100; i++)
    {
        tailX[i] = 0;
        tailY[i] = 0;
    }
    width = 0;
    height = 0;
    x = 0;
    y = 0;
    fruitX = 0;
    fruitY = 0;
    score = 0;
    nTail = 0;
}

void Snake::draw() {
    system("cls");
    for (int i = 0; i < width + 1; i++)
        std::cout  << "*";
    std::cout  << std::endl;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (j == 0 || j == width - 1)
                std::cout  << "*";
            if (i == y && j == x) {
                if (dir == eDir::LEFT)
                {
                    std::cout  << "<";
                }
                else
                {
                    if (dir == eDir::RIGHT)
                    {
                        std::cout  << ">";
                    }
                    else {
                        if (dir == eDir::UP)
                        {
                            std::cout  << "A";
                        }
                        else {
                            std::cout  << "V";
                        }
                    }
                }
            }
            else if (i == fruitY && j == fruitX)
                std::cout  << "$";
            else {
                bool print = false;
                for (int k = 0; k < nTail; k++)
                {
                    if (tailX[k] == j && tailY[k] == i)
                    {
                        print = true;
                        std::cout  << "o";
                    }
                }
                if (!print)
                {
                    std::cout  << " ";
                }
            }
        }
        std::cout  << std::endl;
    }

    for (int i = 0; i < width + 1; i++)
    {
        std::cout << "*";
    }
    std::cout  << std::endl;
    Sleep(250);
    std::cout  << "СЧЁТ: " << score;
}

void Snake::input() {
    if (_kbhit()) {
        switch (_getch()) {
            // English raskladka keyboard
        case 'a':
            if (dir != eDir::RIGHT || nTail == 0)dir = eDir::LEFT;
            break;
        case 'd':
            if (dir != eDir::LEFT || nTail == 0) dir = eDir::RIGHT;
            break;
        case 'w':
            if (dir != eDir::DOWN || nTail == 0) dir = eDir::UP;
            break;
        case 's':
            if (dir != eDir::UP || nTail == 0) dir = eDir::DOWN;
            break;
        case 'q':
            dir = eDir::STOP; break;
            break;
        case 'x':
            std::cout << "\nПАУЗА\n";
            Sleep(500);
            getchar(); getchar();
            break;
        };
    }
}

void Snake::logic() {
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = x;
    tailY[0] = y;
    for (int i = 1; i < nTail; i++)                     // Logika XBOSTA
    {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }
    switch (dir) {                                      // Dvigenie snake
    case eDir::LEFT:
        x--;
        break;
    case eDir::RIGHT:
        x++;
        break;
    case eDir::UP:
        y--;
        break;
    case eDir::DOWN:
        y++;
        break;
    }

    for (int i = 0; i < nTail; i++)
    {
        if (tailX[i] == x && tailY[i] == y)                     // Esli celi XBOST - game over
        {
            gameOver = true;
        }
    }

    if (x > width - 2)
        x = 0;
    if (x < 0)
        x = width - 2;
    if (y > height - 1)
        y = 0;
    if (y < 0)
        y = height - 1;                     //ZERKALO DLY STENY
    // SPAWN NEW FRUKT & +10 score & +1 tail
    if (x == fruitX && y == fruitY) 
    {
        srand(time(NULL));
        score += 10;
        fruitX = 1 + rand() % width - 2;
        fruitY = 1 + rand() % height - 1;
        if (fruitX < 0 || fruitY < 0)
        {
            fruitX = 1 + rand() % width - 2;
            fruitY = 1 + rand() % height - 1;
        }
        nTail++;
    }
}

void Snake::Restart() {
    gameOver = false;
    for (int i = 0; i < 100; i++)
    {
        tailX[i] = { 0 };
        tailY[i] = { 0 };
    }
    dir = eDir::STOP;
    width = 16;
    height = 8;
    x = width / 2 - 1;
    y = height / 2 - 1;
    fruitX = rand() % width - 2;
    fruitY = rand() % height - 1;
    score = 0;
    nTail = 0;
}

void Snake::Rules() {
    system("cls");
    std::cout << " Управление: \n";
    std::cout << "  a - Влево\n  w - Вверх\n  d - Вправо\n  s - Вниз\n";
    std::cout << "  x - Пауза\n\n";
    std::cout << "Выиграть можно набрав 100 очков, 1 яблоко = 10 очков!\n";
    std::cout << "Проиграть можно в том случае, если голова змеи коснётся хвоста змеи...\n\n";
    system("pause");
}

void Snake::PLAY() {
    Restart();
    while (!gameOver) {
        input();
        logic();
        draw();
        if (score == 100) {                     // !!! 100 score == WIN !!!
            system("cls");
            std::cout << "СЧЁТ: " << score;
            std::cout << "\nВы выиграли!!!\n";
            Sleep(1200);
            system("pause");
            return;
        }
    }
    if (gameOver) {
        std::cout << "\nВЫ СЪЕЛИ САМИ СЕБЯ!\n";
    }
   
    system("pause");
}