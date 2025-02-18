#pragma once
#include <iostream>
#include <cmath>
#include <string>
#include <fstream>

using namespace std;


class Lab4
{
    struct AEROFLOT {
        int NUMR;       // Номер рейса
        float COST;     // Стоимость билета
        std::string NAZN; // Название пункта назначения
        std::string TIP;  // Тип самолета
    };

    void Task1() {
       /*
       Получить от пользователя строку текста и вставить вместо каждого пробела
        восклицательный знак. Повторять до тех пор, пока не встретится строка
        завершающаяся словом quit
       */
        string str;
        while (true) {
            cout << "Введите строку: ";
            getline(cin, str);

            for (char& ch : str) 
            {
                if (ch == ' ') 
                {
                    ch = '!';
                }
            }
            cout << "Результат: " << str << endl;

            if (str.size() >= 4 && str.compare(str.size() - 4, 4, "quit") == 0)
            {
                break;
            }
        }
    }

    int countWords(string& line) {
        int count = 0;
        bool inWord = false;

        for (char c : line) {
            if (c == ' ') {
                if (inWord) {
                    count++;
                    inWord = false;
                }
            }
            else {
                inWord = true;
            }
        }
       
        if (inWord) {
            count++;
        }

        return count;
    }

    void Task2() {
        string filePathRead = "D:\str.txt";
        ofstream outputFile(filePathRead);
        string filePathWrite = "D:\str2.txt";
        ofstream outputFile2(filePathWrite);
        ifstream inputFile(filePathRead);

        string lines[] = {
        "Это первая строка текста.",
        "Вторая строка с небольшим описанием.",
        "Третья строка, которая добавляет разнообразие.",
        "Четвертая строка с примером текста.",
        "Пятая строка, чтобы увеличить количество.",
        "Шестая строка для заполнения файла.",
        "Седьмая строка с дополнительной информацией.",
        "Восьмая строка, чтобы продолжить.",
        "Девятая строка с новыми данными.",
        "Десятая строка для разнообразия.",
        "Одиннадцатая строка с интересным текстом.",
        "Двенадцатая строка для увеличения объема.",
        "Тринадцатая строка с важной информацией.",
        "Четырнадцатая строка для заполнения.",
        "Пятнадцатая строка с дополнительными данными.",
        "Шестнадцатая строка, чтобы продолжить.",
        "Семнадцатая строка с новым текстом.",
        "Восемнадцатая строка для разнообразия.",
        "Девятнадцатая строка с интересными данными.",
        "Двадцатая строка для увеличения объема.",
        "Двадцать первая строка с важной информацией.",
        "Двадцать вторая строка для заполнения.",
        "Двадцать третья строка с дополнительными данными.",
        "Двадцать четвертая строка, чтобы продолжить.",
        "Двадцать пятая строка с новым текстом.",
        "Двадцать шестая строка для разнообразия.",
        "Двадцать седьмая строка с интересными данными.",
        "Двадцать восьмая строка для увеличения объема.",
        "Двадцать девятая строка с важной информацией.",
        "Тридцатая строка для завершения."
        };

        for (string& line : lines) {
            outputFile << line << endl;
        }
        outputFile.close();

        string line;
        while (getline(inputFile, line)) {
            int wordCount = countWords(line);
            outputFile2 << line << "(" << wordCount << ")" << endl;
        }
        cout << "Обработка завершена. Результат записан в файл str2.txt.";
        /*
      Открыть текстовый файл в необходимом режиме (на чтение, на чтение и запись, на
       добавление). (В файле должно быть не менее 30 строк). Подсчитать количество слов в
       каждой строке текста. Записать в новый файл все строки, закончив их полученным
       числом.
       Например: Это пример строки текста в старом файле (7)


       для удобства сразу в программе буде создавать файл со 30 строками
      */
    }

    void Task3() {
        const int SIZE = 7;
        AEROFLOT aeroflots[SIZE];
        int func = 0;
        bool isComplite = true;
        string searchNAZN;
        bool found;

        while (isComplite) {
            cout << "\n";
            cout << "1. Ввести данные о рейсах \n";
            cout << "2. Найти рейсы по пункту назначения \n";
            cout << "3. Завершить работу\n";
            cout << "Выберете нужную задачу: \n";
            cin >> func;
            cin.ignore(); // Игнорируем оставшийся символ новой строки после ввода числа
            cout << "\n";

            switch (func) {
            case 1:
                for (int i = 0; i < SIZE; ++i) {
                    cout << "Введите данные для рейса " << i + 1 << ":\n";
                    cout << "Номер рейса: ";
                    cin >> aeroflots[i].NUMR;
                    cout << "Стоимость билета: ";
                    cin >> aeroflots[i].COST;
                    cin.ignore(); // Игнорируем оставшийся символ новой строки
                    cout << "Пункт назначения: ";
                    getline(cin, aeroflots[i].NAZN);
                    cout << "Тип самолета: ";
                    getline(cin, aeroflots[i].TIP);
                }
                break;
            case 2:
                cout << "Введите название пункта назначения для поиска: ";
                getline(cin, searchNAZN);

                found = false;
                for (int i = 0; i < SIZE; ++i) {
                    if (aeroflots[i].NAZN == searchNAZN) {
                        cout << "Номер рейса: " << aeroflots[i].NUMR
                            << ", Тип самолета: " << aeroflots[i].TIP << endl;
                        found = true;
                    }
                }

                if (!found) {
                    cout << "Рейсов в пункт назначения \"" << searchNAZN << "\" не найдено." << endl;
                }
                break;
            case 3:
                isComplite = false;
                break;
            default:
                cout << "Неверный выбор. Пожалуйста, выберите снова.\n";
                break;
            }
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
            cout << "4. завершить работу\n";
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
                isComplite = !isComplite;
            default:
                break;
            }
        }
    }
};





