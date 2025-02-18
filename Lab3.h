#pragma once
#include <iostream>
#include <cmath>

using namespace std;

class Lab3
{

    double** fillSpiralMatrix(int size) {
        double** matrix = new double* [size];
        for (int k = 0; k < size; k++) {
            matrix[k] = new double[size];
        }
        int value = 1;
        int left = 0, right = size - 1, top = 0, bottom = size - 1;
        while (value <= size * size) {
            // Движение вниз
            for (int i = top; i <= bottom; i++) matrix[i][right] = value++;
            right--;

            // Движение влево
            for (int i = right; i >= left; i--) matrix[bottom][i] = value++;
            bottom--;

            // Движение вверх
            for (int i = bottom; i >= top; i--) matrix[i][left] = value++;
            left++;

            // Движение вправо
            for (int i = left; i <= right; i++) matrix[top][i] = value++;
            top++;
        }
        return matrix;
    }

    void printMatrix(double** matrix, int size) {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                cout << matrix[i][j] << "\t";
            }
            cout << endl;
        }
    }

    double** inverseMatrix(double** matrix, int size) {
        //создал массив для нахождения обратной матрицы
        double** matrix2 = new double* [size];
        for (int k = 0; k < size; k++) {
            matrix2[k] = new double[size * 2];
        }


        //добавил единичную матрицу
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size * 2; j++) {
                if (j < size) {
                    matrix2[i][j] = matrix[i][j];
                }
                else {
                    if (i == j - size) {
                        matrix2[i][j] = 1.0;
                    }
                    else
                    {
                        matrix2[i][j] = 0.0;
                    }
                }
            }
        }

        for (int i = 0; i < size; i++) {

            // Нормализуем ведущий элемент
            double diag = matrix2[i][i];
            for (int j = 0; j < size * 2; j++) {
                matrix2[i][j] /= diag;
            }

            // Обнуляем элементы в текущем столбце, кроме главной диагонали
            for (int k = 0; k < size; k++) {
                if (k != i) {
                    double factor = matrix2[k][i];
                    for (int j = 0; j < size * 2; j++) {
                        matrix2[k][j] -= factor * matrix2[i][j];
                    }
                }
            }
        }

        double** inverse = new double* [size];
        for (int i = 0; i < size; i++) {
            inverse[i] = new double[size];
            for (int j = 0; j < size; j++) {
                inverse[i][j] = matrix2[i][j + size];
            }
            delete[] matrix2[i];
        }
        delete[] matrix2;

        return inverse;

    }

    int** multiplyMatrices(double** A, double** B, int size) {
        int** result = new int* [size];
        for (int i = 0; i < size; i++) {
            result[i] = new int[size];
            for (int j = 0; j < size; j++) {
                result[i][j] = 0;
                for (int k = 0; k < size; k++) {
                    result[i][j] += A[i][k] * B[k][j];
                }
            }
        }
        return result;
    }


    public: void Show()
{
    const int n = 4;
    double** matrix = fillSpiralMatrix(n);
    double** matrix2 = inverseMatrix(matrix, n);
    int** matrix3 = multiplyMatrices(matrix, matrix2, n);
    setlocale(LC_ALL, "RUS");
    int func = 0;
    bool isComplite = true;
    while (isComplite)
    {

        cout << "\n";
        cout << "1. Заполнение матрицы по схеме\n";
        cout << "2. Нахождение обратной матрицы \n";
        cout << "3. Умножение матриц\n";
        cout << "4. завершить работу\n";
        cout << "Выберете нужную задачу: \n";
        cin >> func;
        cout << "\n";
        switch (func)
        {
        case 1:
            printMatrix(matrix, n);
            break;
        case 2:
            printMatrix(matrix2, n);
            break;
        case 3:
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    cout << matrix3[i][j] << "\t";
                }
                cout << endl;
            }
            break;
        case 4:
            isComplite = !isComplite;
        default:
            break;
        }
    }
}
};