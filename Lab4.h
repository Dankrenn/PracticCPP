#pragma once
#include <iostream>
#include <cmath>
#include <string>
#include <fstream>

using namespace std;


class Lab4
{
    struct AEROFLOT {
        int NUMR;       // ����� �����
        float COST;     // ��������� ������
        std::string NAZN; // �������� ������ ����������
        std::string TIP;  // ��� ��������
    };

    void Task1() {
       /*
       �������� �� ������������ ������ ������ � �������� ������ ������� �������
        ��������������� ����. ��������� �� ��� ���, ���� �� ���������� ������
        ������������� ������ quit
       */
        string str;
        while (true) {
            cout << "������� ������: ";
            getline(cin, str);

            for (char& ch : str) 
            {
                if (ch == ' ') 
                {
                    ch = '!';
                }
            }
            cout << "���������: " << str << endl;

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
        "��� ������ ������ ������.",
        "������ ������ � ��������� ���������.",
        "������ ������, ������� ��������� ������������.",
        "��������� ������ � �������� ������.",
        "����� ������, ����� ��������� ����������.",
        "������ ������ ��� ���������� �����.",
        "������� ������ � �������������� �����������.",
        "������� ������, ����� ����������.",
        "������� ������ � ������ �������.",
        "������� ������ ��� ������������.",
        "������������ ������ � ���������� �������.",
        "����������� ������ ��� ���������� ������.",
        "����������� ������ � ������ �����������.",
        "������������� ������ ��� ����������.",
        "����������� ������ � ��������������� �������.",
        "������������ ������, ����� ����������.",
        "����������� ������ � ����� �������.",
        "������������� ������ ��� ������������.",
        "������������� ������ � ����������� �������.",
        "��������� ������ ��� ���������� ������.",
        "�������� ������ ������ � ������ �����������.",
        "�������� ������ ������ ��� ����������.",
        "�������� ������ ������ � ��������������� �������.",
        "�������� ��������� ������, ����� ����������.",
        "�������� ����� ������ � ����� �������.",
        "�������� ������ ������ ��� ������������.",
        "�������� ������� ������ � ����������� �������.",
        "�������� ������� ������ ��� ���������� ������.",
        "�������� ������� ������ � ������ �����������.",
        "��������� ������ ��� ����������."
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
        cout << "��������� ���������. ��������� ������� � ���� str2.txt.";
        /*
      ������� ��������� ���� � ����������� ������ (�� ������, �� ������ � ������, ��
       ����������). (� ����� ������ ���� �� ����� 30 �����). ���������� ���������� ���� �
       ������ ������ ������. �������� � ����� ���� ��� ������, �������� �� ����������
       ������.
       ��������: ��� ������ ������ ������ � ������ ����� (7)


       ��� �������� ����� � ��������� ���� ��������� ���� �� 30 ��������
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
            cout << "1. ������ ������ � ������ \n";
            cout << "2. ����� ����� �� ������ ���������� \n";
            cout << "3. ��������� ������\n";
            cout << "�������� ������ ������: \n";
            cin >> func;
            cin.ignore(); // ���������� ���������� ������ ����� ������ ����� ����� �����
            cout << "\n";

            switch (func) {
            case 1:
                for (int i = 0; i < SIZE; ++i) {
                    cout << "������� ������ ��� ����� " << i + 1 << ":\n";
                    cout << "����� �����: ";
                    cin >> aeroflots[i].NUMR;
                    cout << "��������� ������: ";
                    cin >> aeroflots[i].COST;
                    cin.ignore(); // ���������� ���������� ������ ����� ������
                    cout << "����� ����������: ";
                    getline(cin, aeroflots[i].NAZN);
                    cout << "��� ��������: ";
                    getline(cin, aeroflots[i].TIP);
                }
                break;
            case 2:
                cout << "������� �������� ������ ���������� ��� ������: ";
                getline(cin, searchNAZN);

                found = false;
                for (int i = 0; i < SIZE; ++i) {
                    if (aeroflots[i].NAZN == searchNAZN) {
                        cout << "����� �����: " << aeroflots[i].NUMR
                            << ", ��� ��������: " << aeroflots[i].TIP << endl;
                        found = true;
                    }
                }

                if (!found) {
                    cout << "������ � ����� ���������� \"" << searchNAZN << "\" �� �������." << endl;
                }
                break;
            case 3:
                isComplite = false;
                break;
            default:
                cout << "�������� �����. ����������, �������� �����.\n";
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
            cout << "1. ������� 1 \n";
            cout << "2. ������� 2 \n";
            cout << "3. ������� 3\n";
            cout << "4. ��������� ������\n";
            cout << "�������� ������ ������: \n";
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





