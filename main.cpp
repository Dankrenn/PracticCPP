#include <iostream>
#include <cmath>
#include "Lab1.h"
#include "Lab2.h"
#include "Lab3.h"
#include "Lab4.h"
#include "Lab5.h"

int main() {
	setlocale(LC_ALL, "RUS");
	int func = 0;
	cout << "Введите номер лабораторной:";
	cin >> func;
	switch (func)
	{
	case 1:
		Lab1 lab1 = Lab1();
		lab1.Show();
		break;
	case 2:
		Lab2 lab2 = Lab2();
		lab2.Show();
		break;
	case 3:
		Lab3 lab3 = Lab3();
		lab3.Show();
		break;
	case 4:
		Lab4 lab4 = Lab4();
		lab4.Show();
		break;
	case 5:
		Lab5 lab5 = Lab5();
		lab5.Show();
		break;
	case 6:
		break;
	case 7:
		break;
	case 8:
		break;
	case 9:
		break;
	case 10:
		break;
	default:
		break;
	}
}
