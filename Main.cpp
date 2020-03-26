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

    std::cout << "\n |   � � � � � � � � � � � �   � � � � � � � � � � � � �     |\n";

    std::cout << "�� ���������(� ��������� ���������):\n";
    kon1.randInit();
    kon1.print_16();

    std::cout << "\n� �����������:\n";
    kon2.print_16();

    std::cout << "\n�����������:\n";
    kon3.print_16();

    std::cout << "\n�������������� ����:\n";
    kon4.print_16();

    std::cout << "\n |   � � � � � � � � � � � �   � � � � � � �                 |\n";

    fun.randInit();
    fun.print_16();

    fun.convert_16to10();
    std::cout << "\n�������������� �����:";
    fun.print_16();
    std::cout << std::endl;

    fun.inputFile();
    std::cout << std::endl;
    fun.outputFile();

    std::cout << "\n |   � � � � � � � � � � � �   � � � � � � � � � �           |\n";
    // =
    over1.randInit();
    over2 = over1;
    std::cout << "������ �����:";
    over1.print_16();
    std::cout << std::endl;
    std::cout << "������ ����� �����:";
    over2.print_16();
    // +
    std::cout << "\n�������� = ";
    over1 = over1 + over2;
    over1.print_inside();
    // -
    std::cout << "\n��������� = ";
    over1 = over3 - over4;
    over1.print_inside();
    // ==
    if (over3 == over4) { std::cout << "\n������ �����\n"; } else { std::cout << "\n������ �� �����\n"; }

    std::cout << "\n |   � � � � � � � � � � � �   ����/�����   �   � � � � �   |\n";
    
    os.randInit();
    std::cout << os;
    std::cout << std::endl;
    std::cin >> is;
    is.print_16();

  
    std::cout << std::endl;
    system("pause");
}
