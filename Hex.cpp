#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <time.h>
#include <locale.h>
#include "Hex.h"

Hex::Hex() {
    size = 4;
    num = new unsigned char[size + 1];
    for (int i = 0; i < size; i++) {
        num[i] = 0;
    }
}

Hex::Hex(unsigned char* _num, int _size) {
    size = _size;
    num = new unsigned char[size + 1];
    for (int i = 0; i < size; i++)
    {
        num[i] = _num[i];
    }
}

Hex::Hex(const Hex& c) {
    size = c.size;
    num = new unsigned char[size + 1];
    for (int i = 0; i < size; i++)
    {
        num[i] = c.num[i];
    }
}

Hex::Hex(int _size) {
    unsigned char* tmp = new unsigned char[_size];
    num = new unsigned char[_size];
    std::cout << "Введите 16-ную запись (строкой или по символу).\n";
    std::cout << "Символов заданно: " << _size; 
    std::cout << "\nВвод: ";
    for (int i = 0; i < _size; i++)
    {
        std::cin >> tmp[i];
        while (tmp[i] < '0' || tmp[i] > 'F') 
        { 
            std::cout << "Введено неверное значение\nПопробуйте снова\nВвод: "; 
            std::cin >> tmp[i];
        }
    }

    for (int i = 0; i < _size; i++)
    {
        num[i] = tmp[i];
    }
    size = _size;
    delete[]tmp;
}

Hex::~Hex() {
    size = 0;
    delete []num;
}

void Hex::randInit() {
    int choose;

    srand(time(NULL));
    for (int i = 0; i < size; i++)
    {
        choose = rand() % 2;
        if (choose == 1)
        {
            num[size - i - 1] = char('0' + rand() % ('9' - '0'));
        }
        else { num[size - i - 1] = char('A' + rand() % ('F' - 'A')); }
    }
}

void Hex::convert_16to10() {
    int* res = new int[size];
    unsigned long long int sum = 0;

    for (int i = 0; i < size; i++)
    {
        res[i] = static_cast<int>(num[i]) - 48;
        if (res[i] > 9) { res[i] = res[i] - 7; }
    }

    for (int i = 0; i < size; i++)
    {
        res[i] *= (int)pow(16, i);
        sum += res[i];
    }
    std::cout << std::endl << "Resault 16->10 = " << sum << " ";
    delete[]res;
}

void Hex::print_16() {
    for (int i = 0; i < size; i++)
    {
        std::cout << num[i];
    }
}

void Hex::print_inside() {
    for (int i = 0; i < size; i++)
    {
        std::cout << num[size - i - 1];
    }
}

int Hex::inputFile() {
    FILE* file = fopen("C:\\Users\\Dima-LP\\Desktop\\input.txt", "r");
    char* str = new char[32];
    *str = { 0 };
    if (file == NULL)
    {
        std::cout << "Не удалось прочитать данные с файла\n";
        return 0;
    }
    else {
        while (!feof(file))
        {
            fgets(str, 32, file);
        }
    }
    int size = 0;
    size = strlen(str);
    for (int i = 0; i < size; i++) { num[i] = str[i]; }
    fclose(file);
    this->size = size;
    delete[]str;
    return 1;
}

int Hex::outputFile() {
    FILE* file = fopen("C:\\Users\\Dima-LP\\Desktop\\output.txt", "w");
    if (file == NULL)
    {
        std::cout << "Не удалось открыть файл для записи\n";
        return 0;
    }
    for (int i = 0; i < size; i++) { fputc(num[i], file); }
    fclose(file);
    return 1;
}

Hex Hex::operator+(const Hex& c) {
    Hex res;
    int* a = new int[size + 1];
    int* b = new int[c.size + 1];
    int bigerSize = (size > c.size) ? size : c.size;
    for (int i = 0; i < bigerSize; i++) {                           // Инициализация массивов(для разной длинны чисел)
        a[i] = 0;
        b[i] = 0;
    }
    bool five = false;
    //std::cout << "\nНачало 2-ух циклов\n";
    for (int i = 0; i < size; i++)
    {
        a[i] = static_cast<int>(num[size - i - 1]) - 48;
        if (a[i] > 9) { a[i] = a[i] - 7; }
        //std::cout << a[size] << " ";
    }
    std::cout << "\n";
    for (int i = 0; i < c.size; i++)
    {
        b[i] = static_cast<int>(c.num[c.size - i - 1]) - 48;
        if (b[i] > 9) { b[i] = b[i] - 7; }
        //std::cout << b[size] << " ";
    }
    //std::cout <<  "\n";
    for (int i = 0; i < size; i++)
    {
        res.num[i] = a[i] + b[i];
        if (res.num[i] > 15) { res.num[i] = res.num[i] - 16; a[i + 1] += 1; }
    }
    for (int i = 0; i < size; i++) {
        if ((int)res.num[i] > 9) { res.num[i] = res.num[i] + 55; }
        else { res.num[i] = res.num[i] + 48; }
        //std::cout << res.num[i] << " ";
        if (i + 1 == size && (int)a[i] + (int)b[i] > 15)
        {
            //std::cout << "1" << " ";
            five = 1;
        }
    }
    std::cout << std::endl;
    if (five == 1) { std::cout << "";   res.size = res.size++; res.num[4] = '1'; five = false; }

    return res;
}

Hex Hex::operator-(const Hex& c) {
    Hex res;
    int* a = new int[size + 1];
    int* b = new int[c.size + 1];

    // Если второе число болье первого, выод из функции
    int bigerSize = (size > c.size) ? size : c.size;
    if (c.size > size)
    {
        std::cout << "\n\tОШИБКА\n";
        std::cout << "\t\n----Второе число больше первого----\n";
        return 0;
    }
    else {
        bool five = false;
        for (int i = 0; i < bigerSize; i++) {                           // Инициализация массивов(для разной длинны чисел)
            a[i] = 0;
            b[i] = 0;
        }

        for (int i = 0; i < size; i++)                                  // Копия первого числа с конца и преобразование в 10-ную СС
        {
            a[i] = static_cast<int>(num[size - i - 1]) - 48;
            if (a[i] > 9) { a[i] = a[i] - 7; }
        }
        std::cout << "\n";
        for (int i = 0; i < c.size; i++)                                // Копия второго числа с конца и преобразование в 10-ную СС
        {
            b[i] = static_cast<int>(c.num[c.size - i - 1]) - 48;
            if (b[i] > 9) { b[i] = b[i] - 7; }
        }
        std::cout << "\n";
        for (int i = 0; i < size; i++)
        {
            res.num[i] = a[i] - b[i];                                   // Вычитание в столбик                
            if (res.num[i] < 0)                                         // Проверка за выход за пределы
            {
                res.num[i] = (a[i] - b[i]) - 16;
                a[i + 1] -= 1;
            }
        }
        int sum = 0;
        for (int i = 0; i < size; i++) {                                // Проверка не равно ли число 0 после вычитания
            sum += res.num[i];
        }
        if (sum == 0) { res.num[0] = 0; res.size = 1; }
        for (int i = 0; i < size; i++)                                  // Преобразование из 10->16 СС и запись в главный массив
        {
            if ((int)res.num[i] > 9)
            {
                res.num[i] = res.num[i] + 55;
            }
            else { res.num[i] = res.num[i] + 48; }
        }
        std::cout << std::endl;
    }
    return res;
}

Hex& Hex::operator=(const Hex& c) {
    int bigSize;
    bigSize = (size > c.size) ? size : c.size;
    size = c.size;
    for (int i = 0; i < bigSize; i++)
    {
        num[i] = c.num[i];
    }
    return *this;
}

bool Hex::operator==(const Hex& c) {
    bool res = true;
    if (size != c.size) { res = false; return res; }
    else {
        for (int i = 0; i < size; i++)
        {
            if (num[i] != c.num[i])
            {
                res = false;
                return res;
            }
        }
    }
    return res;
}

bool Hex::operator!=(const Hex& c) {
    bool res = true;
    if (size != c.size) { res = false; return res; }
    else {
        for (int i = 0; i < size; i++)
        {
            if (num[i] != c.num[i])
            {
                res = false;
                return res;
            }
        }
    }
    return res;
}

std::ostream& operator << (std::ostream& stream, const Hex& c) {
    stream << "\nИщем файл для записи...\n";
    FILE* file = fopen("C:\\Users\\DIMA\\Desktop\\output.txt", "w");
    if (file == NULL)
    {
        std::cout << "Не удалось открыть файл для записи\n";
    }
    else {
        for (int i = 0; i < c.size; i++) { fputc(c.num[c.size - i - 1], file); }
    }
    if (file == NULL){}else{ fclose(file); }
    stream << "Данные успешно записанны в файл\n";
    return stream;
}

std::istream& operator >> (std::istream& stream, Hex& c) {
 
    std::cout << "Пытаемся прочесть данные с файла...\n";
    FILE * file = fopen("C:\\Users\\DIMA\\Desktop\\input.txt", "r+");
    char* str = new char[32];
    *str = { 0 };
    if (file == NULL)
    {
        std::cout << "Не удалось прочитать данные с файла\n";
        return stream;
    }
    else {
        while (!feof(file))
        {
            fgets(str, 32, file);
        }
    }
    int size = 0;
    size = strlen(str);
    for (int i = 0; i < size; i++) { c.num[i] = str[i]; }
    fclose(file);
    c.size = size;
    std::cout << "Данные успешно прочтены\n";
    delete[]str;
    return stream;
}