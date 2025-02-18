#pragma once
#include <iostream>
#include <cmath>
#include <random>

using std::cin;
using std::cout;
using std::endl;
using std::random_device;
using std::mt19937;
using std::uniform_real_distribution;
using std::uniform_int_distribution;

class Lab2
{
    void fillArrayRand(double arr[], int size, int minVal, int maxVal) {
        random_device rd;
        mt19937 gen(rd());
        uniform_real_distribution<double> dist(minVal, maxVal);

        for (int i = 0; i < size; i++) {
            arr[i] = dist(gen);
        }
    }

    double serchMinItemForArray(double arr[], int size) {
        double minItem = arr[0];
        for (int i = 1; i < size; i++) {
            if (minItem > arr[i]) {
                minItem = arr[i];
            }
        }
        return minItem;
    }

    double compositNoZeroItemForArray(double arr[], int size)
    {
        double �omposit = 1;
        for (int i = 0; i < size; i++) {
            if (arr[i] != 0 && fmod(arr[i], 3) == 0) {
                �omposit *= arr[i];
            }
        }
        return �omposit;
    }

    void printOtrItemsForArray(double arr[], int size) {
        int count = 0;
        for (int i = 0; i < size; i++)
        {
            if (arr[i] < 0) {
                count++;
            }
        }
        double* arr2 = new double[count];
        int j = 0;
        for (int i = 0; i < size; i++)
        {
            if (arr[i] < 0) {
                arr2[j] = arr[i];
                j++;
            }
        }
        cout << "������������� �������� ������� � �������� �������";
        for (j = j - 1; j >= 0; j--) {
            cout << arr2[j] << " ";
        }
        delete[] arr2;
    }

    void printArray(double arr[], int n)
    {
        for (int i = 0; i < n; ++i)
            cout << arr[i] << " ";
        cout << "\n";
    }

	void Task1() {
		/*
		16. ��� ���������� ������, ��������� �� N ������������ ���������.
        1. ��������� ������ ���������� �������.
        2. ����� ����������� ������������� �������.
        3. ��������� ������������ ��������� ��������� �������, ������� 3.
        4. ������� ������������� �������� �� ����� � �������� �������.
		*/
        int size;
        cout << "������� ����������� ������� ";
        cin >> size;
        if (size <= 0) {
            cout << "������ ������� ������ ���� ������������� ������!" << std::endl;
            return;
        }
        double* arr = new double[size];
        fillArrayRand(arr, size, -100, 100);
        cout << "����������� ������: \n";
        printArray(arr, size);
        cout << "\n";
        cout << "����������� ������� ������� �����: " << serchMinItemForArray(arr,size);
        cout << "\n";
        cout << "������������ �� ������� ������ ������� ���� �����: " << compositNoZeroItemForArray(arr, size);
        cout << "\n";
        printOtrItemsForArray(arr, size);
        delete[] arr;
	}

    void fillDoubleArrayRand(int** arr, int i, int j, int minVal, int maxVal) {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<int> dist(minVal, maxVal);

        for (int index1 = 0 ; index1 < i; index1++) {
            for (int index2 = 0; index2 < j; index2++) {
                arr[index1][index2] = dist(gen);
            }
        }
    }

    void rearrangItems(int** arr, int i, int j) {
        int oneItems = arr[0][0];
        int maxIndex = 0, maxIndex2 = 0;
        int maxItems = abs(oneItems);
        for (int index1 = 0; index1 < i; index1++) {
            for (int index2 = 0; index2 < j; index2++) {
                if (abs(arr[index1][index2]) >= maxItems) {
                    maxItems = arr[index1][index2];
                    maxIndex = index1;
                    maxIndex2 = index2;
                }
            }
        }
        arr[0][0] = maxItems;
        arr[maxIndex][maxIndex2] = oneItems;
    }

    void Task2() 
    {
        /*
        � ������ ������, ����������� ��������� �������, ������� �������� n m ��������
        ������� ������ ������� � ������������ �� ������.
        */
        int i,j;
        cout << "������� ������ ������� ";
        cin >> i;
        cout << "������� ������ ������� ";
        cin >> j;
        if (i <= 0 || j <=0) {
            cout << "������ ������� ������ ���� �� ������ 1�1!" << std::endl;
            return;
        }
        int** arr = new int* [i];
        for (int k = 0; k < i; k++) {
            arr[k] = new int[j];
        }
        fillDoubleArrayRand(arr, i,j, -100, 100);

        cout << "����������� ������: \n";
        for (int index1 = 0; index1 < i; index1++) {
            for (int index2 = 0; index2 < j; index2++) {
                cout << arr[index1][index2] << " ";
            }
            cout << "\n";
        }
        
        rearrangItems(arr, i, j);

        cout << "����� ������������:\n";
        for (int index1 = 0; index1 < i; index1++) {
            for (int index2 = 0; index2 < j; index2++) {
                cout << arr[index1][index2] << " ";
            }
            cout << "\n";
        }

        for (int k = 0; k < i; k++) {
            delete[] arr[k];
        }
        delete[] arr;
    }

    //������� ��� ��������� ������ �� �������� ������ �������� ������ ������������
    void heapify(double arr[], int size, int i)
    {
        int largest = i; // ������ ��������
        int left = 2 * i + 1; // ������ ������ ��������
        int right = left++; //������ ������� ��������

        if (left < size && arr[left] > arr[largest]) {
            largest = left; 
        }
        if (right < size && arr[right] > arr[largest]) {
            largest = right;
        }
        if (largest != i) {
            double temp = arr[i];
            arr[i] = arr[largest];
            arr[largest] = temp;
            heapify(arr, size, largest); 
        }
    }

    void heapSort(double arr[], int size)
    {
        for (int i = size / 2 - 1; i >= 0; i--)  // ��������� �� �������� ���� (�������� ������� 2 ��������)
        {
            heapify(arr, size, i);
        }

        // ������ ��������� �������� �� ���� �� ������
        // ���������� ������ ���� (����� ������� �������) � ����� �������
        for (int i = size - 1; i > 0; i--) {
            double temp = arr[0];
            arr[0] = arr[i];
            arr[i] = temp;
            heapify(arr, i, 0);
        }
    }

    void Task3() {
        /*
        ��������� ���������� ��������� ����������� ������� �������� ��������.
        ������������� ����������
        */
        int size;
        cout << "������� ����������� ������� ";
        cin >> size;
        if (size <= 0) {
            cout << "������ ������� ������ ���� ������������� ������!" << std::endl;
            return;
        }
        double* arr = new double[size];
        fillArrayRand(arr, size, -100, 100);
        cout << "����������� ������: \n";
        printArray(arr, size);
        
        heapSort(arr, size);

        cout << "������������� ������: \n";
        printArray(arr, size);

    }

	public:	void Show() 
	{     
        int func = 0;
        bool isComplite = true;
        while (isComplite)
        {
            cout << "\n";
            cout << "1. ������� 1 \n";
            cout << "2. ������� 2 \n";
            cout << "3. ������� 3 \n";
            cout << "4. ��������� ������ \n";
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

