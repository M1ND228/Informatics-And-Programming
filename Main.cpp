#include "Hex.h"
#include <iostream>
#include <clocale>

int main() {
    setlocale(LC_ALL, "RUS");
    
    unsigned char* tmp = new unsigned char[4];
    int size_ = 4;
    for (int i = 0; i < size_; i++) { tmp[i] = '4'; }
    Hex kon1;
    Hex kon2(tmp, size_);
    Hex kon3(kon2); 
    Hex kon4(4);
    
    Hex fun;

    Hex over1,over2,over3(4),over4(4);

    Hex os, is;

    std::cout << "\n |   Т Е С Т И Р О В А Н И Е   К О Н С Т Р У К Т О Р О В     |\n";

    std::cout << "По умолчанию(с рандомным значением):\n";
    kon1.randInit();
    kon1.print_16();

    std::cout << "\nС параметрами:\n";
    kon2.print_16();

    std::cout << "\nКопирования:\n";
    kon3.print_16();

    std::cout << "\nПреобразования типа:\n";
    kon4.print_16();

    std::cout << "\n |   Т Е С Т И Р О В А Н И Е   Ф У Н К Ц И Й                 |\n";

    fun.randInit();
    fun.print_16();

    fun.convert_16to10();
    std::cout << "\nПервоначальное число:";
    fun.print_16();
    std::cout << std::endl;

    fun.inputFile();
    std::cout << std::endl;
    fun.outputFile();

    std::cout << "\n |   Т Е С Т И Р О В А Н И Е   П Е Р Е Г Р У З О К           |\n";
    // =
    over1.randInit();
    over2 = over1;
    std::cout << "Первое число:";
    over1.print_16();
    std::cout << std::endl;
    std::cout << "Второе число число:";
    over2.print_16();
    // +
    std::cout << "\nСложение = ";
    over1 = over1 + over2;
    over1.print_inside();
    // -
    std::cout << "\nВычитание = ";
    over1 = over3 - over4;
    over1.print_inside();
    // ==
    if (over3 == over4) { std::cout << "\nЗаписи равны\n"; } else { std::cout << "\nЗаписи не равны\n"; }

    std::cout << "\n |   Т Е С Т И Р О В А Н И Е   ВВОД/ВЫВОД   В   П О Т О К   |\n";
    
    os.randInit();
    std::cout << os;
    std::cout << std::endl;
    std::cin >> is;
    is.print_16();

  
    std::cout << std::endl;
    system("pause");
}
