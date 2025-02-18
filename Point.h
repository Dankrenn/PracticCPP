#pragma once
#include <iostream>

using namespace std;

class Point {
    int x;
    int y;

    public:Point() : x(0), y(0) {
        cout << "������� ����� � ������������ (0, 0)\n";
    }
    public:Point(int x, int y) : x(x), y(y) {
        cout << "������� ����� � ������������ (" << x << ", " << y << ")\n";
    }


public:void PrintInfo() const {
        cout << "���������� �����: (" << x << ", " << y << ")\n";
    }

public:double Calculation() const {
        return std::sqrt(x * x + y * y);
    }

public:void move(int a, int b) {
        x += a;
        y += b;
        cout << "����� ���������� �� ������ (" << a << ", " << b << ")\n";
    }


public:int getX() const { return x; }
    void setX(int value) {
        x = value;
        cout << "���������� x ����������� �� " << value << "\n";
    }

public:int getY() const { return y; }
    void setY(int value) {
        y = value;
        cout << "���������� y ����������� �� " << value << "\n";
    }

public:void multiplyByScalar(int scalar) {
        x *= scalar;
        y *= scalar;
        cout << "���������� �������� �� ������ " << scalar << "\n";
    }


public:int operator[](int index) const {
        if (index == 0) return x;
        if (index == 1) return y;
        out_of_range("������ ������ ���� 0 ��� 1");
    }

public: int& operator[](int index) {
        if (index == 0) return x;
        if (index == 1) return y;
        out_of_range("������ ������ ���� 0 ��� 1");
    }

 
public:Point& operator++() {
        ++x;
        ++y;
        cout << "����� ��������� �� (1, 1) (���������� ���������)\n";
        return *this;
    }

public:Point operator++(int) {
        Point temp = *this;
        ++(*this);
        cout << "����� ��������� �� (1, 1) (����������� ���������)\n";
        return temp;
    }

public:Point& operator--() {
        --x;
        --y;
        cout << "����� ��������� �� (1, 1) (���������� ���������)\n";
        return *this;
    }

public:Point operator--(int) {
        Point temp = *this;
        --(*this);
        cout << "����� ��������� �� (1, 1) (����������� ���������)\n";
        return temp;
    }

public:operator bool() const {
        return x == y;
    }

public:Point operator+(int scalar) const {
        cout << "����� ��������� �� ������ " << scalar << "\n";
        return Point(x + scalar, y + scalar);
    }
};

