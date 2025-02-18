#pragma once
#include <iostream>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;

#define PI 3.14
#define E 0.001
class Lab1
{
    void Task1() {
        /*
    Найти значение алгебраического выражения, соответствующего варианту
    задания. Вывести результаты на печать. Все результаты выводить в развернутом
    виде (например: «Сумма чисел А и B равна 3.7854»).
        */
        double a = 0, b = 0, rezult, rez1, rez2, rez3;
        cout << "Введите значение переменной а\n";
        cin >> a;
        cout << "Введите значение переменной b\n";
        cin >> b;

        rez1 = cos(a - pow(b, 2) + 2 * a * b);
        rez2 = pow(b, 2) * (cos(pow(b - a, 2)) + pow(PI, 2) * sin(7.4));

        double arg = cos(pow(a - b, 3)) / sin(pow(a + b, 3));
        if (arg <= 0) {
            cout << "Ошибка: аргумент логарифма неположительный." << endl;
            return;
        }
        rez3 = log(arg);

        double sqrt_arg = rez1 / rez2;
        if (sqrt_arg < 0) {
            cout << "Ошибка: выражение под корнем отрицательное." << endl;
            return;
        }
        rezult = sqrt(sqrt_arg) * rez3;

        cout << "При числе a равном " << a << " и числе b равном " << b << " выражение равно " << rezult << endl;
    }

    void Task2() {
        //Решить задачу для различных значений х.
        double x = 0;
        const double x1 = PI / 3, x2 = 2, x3 = PI / 4, a = 12;
        int func = 0;
        cout << "1. x = PI / 3 \n";
        cout << "2. x = 2 \n";
        cout << "3. x = PI / 4 \n";
        cout << "4. свой вариант\n";
        cout << "Выберете нужную функцию: \n";
        cin >> func;
        switch (func)
        {
        case 1:
            x = x1;
            break;
        case 2:
            x = x2;
            break;
        case 3:
            x = x3;
            break;
        case 4:
            cout << "Введите значение переменной x\n";
            cin >> x;
            if (x <= 0 || x > PI)
            {
                cout << "Ошибка: x должен соответствовать следующим условиям : 0 < x >= pi." << endl;
                return;
            }
            break;

        default:
            cout << "Неверный формат выбора функции" << endl;
            break;
        }

        double sum = 0;
        double prev_term = 0;
        double current_term = 0;

        for (int n = 1;; n++) {
            prev_term = current_term;
            current_term = sin((2 * n - 1) * x) / (2 * n - 1);
            sum += current_term;
            if (fabs(current_term - prev_term) <= E) {
                break;
            }
        }
        double result = (4 * a / PI) * sum;
        cout << "При x = " << x << " значение функции F(x) равно " << result << endl;
    }

    void Task3() {
        //используя средства отладчика среды, 
        //обнаружить все ошибки и сделать программу работоспособной
        int func = 0;
        cout << "Введите номер задания: ";
        cin >> func;
        switch (func)
        {
            case 1:
                One();
                break;
            case 2:
                Two();
                break;
            case 3:
                Three();
                break;
            case 4:
                Four();
                break;
            case 5:
                Five();
                break;
            case 6:
                Six();
                break;
            case 7:
                Seven();
                break;         
        default:
            break;
        }
    }

    void One() {
        cout << "Все натуральные делители числа введенного пользователем\n";
        int n;
        cout << "введите число n :";
        cin >> n;
        for (int i = 1; n / 2; i++) {
            if (n % i == 0) {
                cout << i << "\n";
            }
        }
    }

    void Two() {
        cout << "Вычислить величину y равную (n!!)";
        int n, fn = 1, y = 0;
        cout << "Введите значение n: ";
        cin >> n;
        if (n % 2 == 0) {
            for (int i = 1; i <= n; i += 2) {
                fn = 1;
                for (int j = 1; j <= i; j++) {
                    fn *= j;
                }
                y += fn;
            }
        }
        else {
            for (int i = 2; i <= n; i += 2) {
                fn = 1;
                for (int j = 1; j <= i; j++) {
                    fn *= j; 
                }
                y += fn;
            }
        }
        cout << "Результат: " << y << endl;
    }

    void Three() {
        cout << "Вычислить произведение первых n сомножителей. n введено пользователем\n";
        int n;
        double p = 1;
        cout << "Введите число n\n";
        cin >> n;
        for (int i = 1; i <= n; i++) {
            if (i % 2 == 1) {
                p *= (double)(i + 1) / i;
            }
            else {
                p *= (double)i / (i + 1);
            }
        }
        cout << "Произведение первых " << n << " сомножителей: " << p << endl;
    }

    void Four() {
        cout << "Вычисление двойной суммы\n";
        int n;
        double x;
        double res = 0;

        cout << "Введите значение n: ";
        cin >> n;
        cout << "Введите значение x: ";
        cin >> x;

        for (int k = 1; k <= n; k++) {
            for (int m = k; m <= n; m++) {
                res += (x + k) / m;
            }
        }
        cout << "Результат: " << res << endl;
    }

    void Five() {
        cout << "Вычисление двойной суммы\n";
        int i, j, n;
        float sum1, sum2;
        cout << "Введите значение n: ";
        cin >> n;

        sum1 = 0;
        sum2 = 0;

        for (i = 1; i <= n; i++) {  
            for (j = 1; j <= i; j++) {  
                sum1 = sum1 + (1.0 / (i + 2 * j)); 
            }
        }
        sum2 = sum1;

        cout << sum2; 
    }
   
    void Six()
    {
        double b, c, a;
        int n = 0;
        cout << "a1= ";
        cin >> b;

        cout << "a2= ";
        cin >> c;

        for (int i = 1; i <= 10; i++) {  
            cout << "a" << i + 2 << "= ";
            cin >> a;
            if (b < a && a > c) { 
                n++;
            }
            b = c;
            c = a;
        }

        cout << n;

    }

    void Seven()
    {
        int i = 1, j = 1;
        double P = 1.0; 
        for (i; i <= 20; i++) {
            for (j; j <= 20; j++) {
                P *= 1.0 / (i + pow(j, 2)); 
            }
        }
        cout << P;

    }

    void Task4() {
        //Написать программу определения знака введенного числа
        double x;
        cout << "Введите значение x: \n";
        cin >> x;
        if (x < 0) {
            cout << "Знак введенного числа отрицательный" << endl;
        }
        else {
            cout << "Знак введенного числа положительный" << endl;
        }
    }

    public: void Show()
    {
        setlocale(LC_ALL, "RUS");
        int func = 0;
        bool isComplite = true;
        while (isComplite)
        {
            cout << "\n";
            cout << "1. задание 1 \n";
            cout << "2. задание 2 \n";
            cout << "3. задание 3\n";
            cout << "4. задание 4\n";
            cout << "5. завершить работу\n";
            cout << "Выберете нужную задачу: \n";
            cin >> func;
            cout << "\n";
            switch (func)
            {
            case 1:
                Task1();
                break;
            case 2:
                Task2();
                break;
            case 3:
                Task3();
                break;
            case 4:
                Task4();
                break;
            case 5:
                isComplite = !isComplite;
            default:
                break;
            }
        }
    }
};




