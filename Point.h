#pragma once
#include <iostream>

using namespace std;

class Point {
    int x;
    int y;

    public:Point() : x(0), y(0) {
        cout << "Создана точка с координатами (0, 0)\n";
    }
    public:Point(int x, int y) : x(x), y(y) {
        cout << "Создана точка с координатами (" << x << ", " << y << ")\n";
    }


public:void PrintInfo() const {
        cout << "Координаты точки: (" << x << ", " << y << ")\n";
    }

public:double Calculation() const {
        return std::sqrt(x * x + y * y);
    }

public:void move(int a, int b) {
        x += a;
        y += b;
        cout << "Точка перемещена на вектор (" << a << ", " << b << ")\n";
    }


public:int getX() const { return x; }
    void setX(int value) {
        x = value;
        cout << "Координата x установлена на " << value << "\n";
    }

public:int getY() const { return y; }
    void setY(int value) {
        y = value;
        cout << "Координата y установлена на " << value << "\n";
    }

public:void multiplyByScalar(int scalar) {
        x *= scalar;
        y *= scalar;
        cout << "Координаты умножены на скаляр " << scalar << "\n";
    }


public:int operator[](int index) const {
        if (index == 0) return x;
        if (index == 1) return y;
        out_of_range("Индекс должен быть 0 или 1");
    }

public: int& operator[](int index) {
        if (index == 0) return x;
        if (index == 1) return y;
        out_of_range("Индекс должен быть 0 или 1");
    }

 
public:Point& operator++() {
        ++x;
        ++y;
        cout << "Точка увеличена на (1, 1) (префиксный инкремент)\n";
        return *this;
    }

public:Point operator++(int) {
        Point temp = *this;
        ++(*this);
        cout << "Точка увеличена на (1, 1) (постфиксный инкремент)\n";
        return temp;
    }

public:Point& operator--() {
        --x;
        --y;
        cout << "Точка уменьшена на (1, 1) (префиксный декремент)\n";
        return *this;
    }

public:Point operator--(int) {
        Point temp = *this;
        --(*this);
        cout << "Точка уменьшена на (1, 1) (постфиксный декремент)\n";
        return temp;
    }

public:operator bool() const {
        return x == y;
    }

public:Point operator+(int scalar) const {
        cout << "Точка увеличена на скаляр " << scalar << "\n";
        return Point(x + scalar, y + scalar);
    }
};

