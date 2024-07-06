#include "matrix.h"
#include "number.h"
#include <string>
#include <iostream>
#include <iomanip>
#include "complex.h"
#include "complex.cpp"
using namespace std;

matrix::matrix(){
}

number matrix::determinant(number matrix[3][3]) {
    number det = matrix[0][0] * (matrix[1][1] * matrix[2][2] - matrix[1][2] * matrix[2][1])
                 - matrix[0][1] * (matrix[1][0] * matrix[2][2] - matrix[1][2] * matrix[2][0])
                 + matrix[0][2] * (matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][0]);

    return det;
}
int matrix::rankOfMatrix3x3(number matrix[3][3]) {
    number Arr[3][3];

    double value;
    for (int i = 0; i < 3; i++){
        for (int j = i; j < 3; j++) {
            Arr[i][j] = matrix[i][j];
        }
    }
    int rank = 3;
    for (int i = 0; i < 3; i++) {
        int firstNonZeroRow = -1;
        for (int j = i; j < 3; j++) {
            value = Abs(Arr[j][i]);
            if (value > 1e-9) {
                firstNonZeroRow = j;
                break;
            }
        }

        if (firstNonZeroRow == -1) {
            rank--;
        } else {
            swap(Arr[i], Arr[firstNonZeroRow]);
            for (int j = i + 1; j < 3; j++) {
                number factor = (Arr[j][i]* (-1)) / Arr[i][i];
                for (int k = i; k < 3; k++) {
                    Arr[j][k] = Arr[j][k]+( factor * Arr[i][k]);
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
            cout << setw(5) << matrix[i][j];
        }
        cout << endl;
    }
}
void matrix::input(number matrix[3][3]) {
    cout << setw(4) << "Re" << setw(3) << "Im" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j=0; j < 3; j++) {
            cout << (i*3+j+1) << ")";
            cin >> matrix[i][j];
        }
    }
}
