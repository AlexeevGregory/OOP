#include "matrix.h"
#include "number.h"
#include <string>
#include <cmath>
#include <iostream>
using namespace std;

number matrix::determinant(number matrix[3][3]) {
    number det = matrix[0][0] * (matrix[1][1] * matrix[2][2] - matrix[1][2] * matrix[2][1])
                 - matrix[0][1] * (matrix[1][0] * matrix[2][2] - matrix[1][2] * matrix[2][0])
                 + matrix[0][2] * (matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][0]);

    return det;

}
int matrix::rankOfMatrix3x3(number matrix[3][3]) {
    number Arr[3][3];
    for (int i = 0; i < 3; i++){
        for (int j = i; j < 3; j++) {
            Arr[i][j] = matrix[i][j];
        }
    }
    int rank = 3;  // Начальное предположение о ранге матрицы

    // Применение метода Гаусса для преобразования матрицы к ступенчатому виду
    for (int i = 0; i < 3; i++) {
        // Поиск первой ненулевой строки в текущем столбце
        int firstNonZeroRow = -1;
        for (int j = i; j < 3; j++) {
            if (fabs(Arr[j][i]) > 1e-9) {
                firstNonZeroRow = j;
                break;
            }
        }

        if (firstNonZeroRow == -1) {
            // Если нет ненулевых элементов в текущем столбце, уменьшаем предполагаемый ранг
            rank--;
        } else {
            // Обмен текущей строкой с первой ненулевой строкой
            swap(Arr[i], Arr[firstNonZeroRow]);

            // Обнуление всех элементов ниже текущей строки в текущем столбце
            for (int j = i + 1; j < 3; j++) {
                double factor = -Arr[j][i] / Arr[i][i];
                for (int k = i; k < 3; k++) {
                    Arr[j][k] += factor * Arr[i][k];
                }
            }
        }
    }
    return rank;
}
void matrix::transposition(number matrix[3][3]) {
    for (int i = 0; i < 3; i++){
        for (int j = i; j < 3; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    cout << "The matrix is transposed" << endl;
}
void matrix::show(number matrix[3][3]) {
    cout << "The matrix:" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j=0; j < 3; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}
void matrix::input(number matrix[3][3]) {
    cout << "values: ";
    for (int i = 0; i < 3; i++) {
        for (int j=0; j < 3; j++) {
            cin >> matrix[i][j];
        }
    }
}
