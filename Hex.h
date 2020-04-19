#pragma once
#include <iostream>
class Hex
{
public:
    // ������������
    Hex();
    Hex(unsigned char* _num, int _size);
    Hex(const Hex& c);
    Hex(int size);

    ~Hex();

    // �������
    void print_16();                // ����� 16-��� ���(������ �� ����)
    void print_inside();            // ����� ��������(����� �� �����)
    void randInit();                // ��������� 16-��� ���
    void convert_16to10();          // �������������� �� 16->10 �� � ����� �� �����
    int  inputFile();               // ���������� ������� �� .txt �����
    int  outputFile();              // ����� ������� � .txt ����

    // ����������
    Hex& operator = (const Hex& c);
    Hex  operator + (const Hex& c);
    Hex  operator - (const Hex& c);

    bool operator == (const Hex& c);
    bool operator != (const Hex& c);

    friend std::ostream& operator << (std::ostream& stream, const Hex& c);
    friend std::istream& operator >> (std::istream& stream, Hex& c);

private:
    unsigned char* num;             // ������ ��� �������� 16-��� �����
    int size;                       // ������ �������
};
