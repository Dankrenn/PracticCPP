#pragma once
#include "Point.h"
class Lab5
{
public:void Show() {
    Point p1; // ������������� ������������ �� ���������
    Point p2(3, 4); // ������������� ������������ � �����������

    p1.PrintInfo();
    p2.PrintInfo();

    std::cout << "���������� �� ������ ��������� �� p2: " << p2.Calculation() << "\n";

    p2.move(2, 3);
    p2.PrintInfo();

    p2.setX(10);
    p2.setY(15);
    std::cout << "���������� ����� ���������: (" << p2.getX() << ", " << p2.getY() << ")\n";

    p2.multiplyByScalar(2);
    p2.PrintInfo();

    std::cout << "���������� x: " << p2[0] << ", ���������� y: " << p2[1] << "\n";

    ++p2;
    p2.PrintInfo();

    p2++;
    p2.PrintInfo();

    if (p2) {
        std::cout << "���������� x � y ���������.\n";
    }
    else {
        std::cout << "���������� x � y �� ���������.\n";
    }

    Point p3 = p2 + 5;
    p3.PrintInfo();

}
};



