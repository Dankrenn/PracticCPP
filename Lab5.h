#pragma once
#include "Point.h"
class Lab5
{
public:void Show() {
    Point p1; // Использование конструктора по умолчанию
    Point p2(3, 4); // Использование конструктора с параметрами

    p1.PrintInfo();
    p2.PrintInfo();

    std::cout << "Расстояние от начала координат до p2: " << p2.Calculation() << "\n";

    p2.move(2, 3);
    p2.PrintInfo();

    p2.setX(10);
    p2.setY(15);
    std::cout << "Координаты после установки: (" << p2.getX() << ", " << p2.getY() << ")\n";

    p2.multiplyByScalar(2);
    p2.PrintInfo();

    std::cout << "Координата x: " << p2[0] << ", Координата y: " << p2[1] << "\n";

    ++p2;
    p2.PrintInfo();

    p2++;
    p2.PrintInfo();

    if (p2) {
        std::cout << "Координаты x и y совпадают.\n";
    }
    else {
        std::cout << "Координаты x и y не совпадают.\n";
    }

    Point p3 = p2 + 5;
    p3.PrintInfo();

}
};



