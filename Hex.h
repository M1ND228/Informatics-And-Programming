#pragma once
#include <iostream>
class Hex
{
public:
    // Конструкторы
    Hex();
    Hex(unsigned char* _num, int _size);
    Hex(const Hex& c);
    Hex(int size);

    ~Hex();

    // Функции
    void print_16();                // Вывод 16-ный код(справа на лево)
    void print_inside();            // Вывод инверсия(слева на право)
    void randInit();                // Случайный 16-ный код
    void convert_16to10();          // Преобразование из 16->10 СС и вывод на экран
    int  inputFile();               // Заполнение массива из .txt файла
    int  outputFile();              // Вывод массива в .txt файл

    // Перегрузки
    Hex& operator = (const Hex& c);
    Hex  operator + (const Hex& c);
    Hex  operator - (const Hex& c);

    bool operator == (const Hex& c);
    bool operator != (const Hex& c);

    friend std::ostream& operator << (std::ostream& stream, const Hex& c);
    friend std::istream& operator >> (std::istream& stream, Hex& c);

private:
    unsigned char* num;             // Массив для хранения 16-ных чисел
    int size;                       // Рамзер массива
};
