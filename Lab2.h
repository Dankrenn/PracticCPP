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
        double сomposit = 1;
        for (int i = 0; i < size; i++) {
            if (arr[i] != 0 && fmod(arr[i], 3) == 0) {
                сomposit *= arr[i];
            }
        }
        return сomposit;
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
        cout << "Отрицательные элементы массива в обратном порядке";
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
		16. Дан одномерный массив, состоящий из N вещественных элементов.
        1. Заполнить массив случайными числами.
        2. Найти минимальный отрицательный элемент.
        3. Вычислить произведение ненулевых элементов массива, кратных 3.
        4. Вывести отрицательные элементы на экран в обратном порядке.
		*/
        int size;
        cout << "Введите размерность массива ";
        cin >> size;
        if (size <= 0) {
            cout << "Размер массива должен быть положительным числом!" << std::endl;
            return;
        }
        double* arr = new double[size];
        fillArrayRand(arr, size, -100, 100);
        cout << "Заполненный массив: \n";
        printArray(arr, size);
        cout << "\n";
        cout << "Минимальный элемент массива равен: " << serchMinItemForArray(arr,size);
        cout << "\n";
        cout << "Произведение не нулевых членов кратных трем равно: " << compositNoZeroItemForArray(arr, size);
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
        В каждой строке, заполненной случайным образом, матрицы размером n m поменять
        местами первый элемент и максимальный по модулю.
        */
        int i,j;
        cout << "Введите длинну массива ";
        cin >> i;
        cout << "Введите ширину массива ";
        cin >> j;
        if (i <= 0 || j <=0) {
            cout << "Размер массива должен быть не меньше 1х1!" << std::endl;
            return;
        }
        int** arr = new int* [i];
        for (int k = 0; k < i; k++) {
            arr[k] = new int[j];
        }
        fillDoubleArrayRand(arr, i,j, -100, 100);

        cout << "Заполненный массив: \n";
        for (int index1 = 0; index1 < i; index1++) {
            for (int index2 = 0; index2 < j; index2++) {
                cout << arr[index1][index2] << " ";
            }
            cout << "\n";
        }
        
        rearrangItems(arr, i, j);

        cout << "После перестановки:\n";
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

    //функция для постройки дерева по правилам каждый родитель больше последующего
    void heapify(double arr[], int size, int i)
    {
        int largest = i; // индекс родителя
        int left = 2 * i + 1; // индекс левого элемента
        int right = left++; //индекс правого элемента

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
        for (int i = size / 2 - 1; i >= 0; i--)  // последний не листовой узел (родитель имеющий 2 потомков)
        {
            heapify(arr, size, i);
        }

        // Теперь извлекаем элементы из кучи по одному
        // Перемещаем корень кучи (самый большой элемент) в конец массива
        for (int i = size - 1; i > 0; i--) {
            double temp = arr[0];
            arr[0] = arr[i];
            arr[i] = temp;
            heapify(arr, i, 0);
        }
    }

    void Task3() {
        /*
        Выполнить сортировку элементов одномерного массива согласно варианту.
        Пирамидальная сортировка
        */
        int size;
        cout << "Введите размерность массива ";
        cin >> size;
        if (size <= 0) {
            cout << "Размер массива должен быть положительным числом!" << std::endl;
            return;
        }
        double* arr = new double[size];
        fillArrayRand(arr, size, -100, 100);
        cout << "Заполненный массив: \n";
        printArray(arr, size);
        
        heapSort(arr, size);

        cout << "Сортированный массив: \n";
        printArray(arr, size);

    }

	public:	void Show() 
	{     
        int func = 0;
        bool isComplite = true;
        while (isComplite)
        {
            cout << "\n";
            cout << "1. задание 1 \n";
            cout << "2. задание 2 \n";
            cout << "3. задание 3 \n";
            cout << "4. завершить работу \n";
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

