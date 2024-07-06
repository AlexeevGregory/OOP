#include "matrix.h"
#include "number.h"
#include <string>
#include <iostream>
#include <iomanip>
#include <interface.h>
#include <interface.cpp>
using namespace std;

matrix::matrix(){
}


number matrix::MatrDeterminant() {
    number det;
    det = Matrix[0][0] * (Matrix[1][1] * Matrix[2][2] - Matrix[1][2] * Matrix[2][1])
          - Matrix[0][1] * (Matrix[1][0] * Matrix[2][2] - Matrix[1][2] * Matrix[2][0])
          + Matrix[0][2] * (Matrix[1][0] * Matrix[2][1] - Matrix[1][1] * Matrix[2][0]);
    return det;
}
int matrix::rankOfMatrix3x3() {
    number c;
    double value;
    int rank = 3;
    for (int i = 0; i < 3; i++) {
        int firstNonZeroRow = -1;
        for (int j = i; j < 3; j++) {
            c = Matrix[j][i];
            value = Abs(Matrix[j][i]);
            if (value > 1e-9) {
                firstNonZeroRow = j;
                break;
            }
        }

        if (firstNonZeroRow == -1) {
            rank--;
        } else {
            swap(Matrix[i], Matrix[firstNonZeroRow]);
            for (int j = i + 1; j < 3; j++) {
                number factor = -(Matrix[j][i]) / Matrix[i][i];
                for (int k = i; k < 3; k++) {
                    Matrix[j][k] = Matrix[j][k]+( factor * Matrix[i][k]);
                }
            }
        }
    }
    return rank;
}
void matrix::transposition() {
    for (int i = 0; i < 3; i++){
        for (int j = i; j < 3; j++) {
            swap(Matrix[i][j], Matrix[j][i]);
        }
    }
}
void matrix::show(matrix Obj, QString& s) {
    for (int i = 0; i < 3; i++) {
        for (int j=0; j < 3; j++) {
            s << Obj.Matrix[i][j];
            s += " ";
        }
        s += "\n";
    }
}
void matrix::input(number val1,number val2,number val3,number val4,number val5,number val6,number val7,number val8,number val9) {
    Matrix[0][0] = val1;  Matrix[0][1] = val2;  Matrix[0][2] = val3;
    Matrix[1][0] = val4;  Matrix[1][1] = val5;  Matrix[1][2] = val6;
    Matrix[2][0] = val7;  Matrix[2][1] = val8;  Matrix[2][2] = val9;
}
