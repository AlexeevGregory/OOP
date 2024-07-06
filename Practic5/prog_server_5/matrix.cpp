#include "matrix.h"
#include "number.h"
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

matrix::matrix(){
    Matrix = new number*[3];
    for (int i = 0; i < 3; ++i) {
        Matrix[i] = new number[3];
    }
}

matrix::matrix(unsigned short columns, unsigned short rows){
    Matrix = new number*[rows];
    for (int i = 0; i < rows; ++i) {
        Matrix[i] = new number[columns];
    }
}

int matrix::findMatrixRank(int n) {

    number** Arr= new number*[n];
    number null(0,0);
    for (int i = 0; i < n; ++i) {
        Arr[i] = new number[n];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            Arr[i][j] = Matrix[i][j];
        }
    }
    int rank = n;

    for (int row = 0; row < rank; ++row) {
        if (Arr[row][row] != null) {
            for (int col = 0; col < n; ++col) {
                if (col != row) {
                    number multiplier = Arr[col][row] / Arr[row][row];

                    for (int i = 0; i < rank; ++i) {
                        Arr[col][i] = Arr[col][i] - (multiplier * Arr[row][i]);
                    }
                }
            }
        } else {
            bool reduceRank = true;

            for (int i = row + 1; i < n; ++i) {
                if (Arr[i][row] != null) {
                    for (int j = 0; j < rank; ++j) {
                        swap(Arr[row][j], Arr[i][j]);
                    }
                    reduceRank = false;
                    break;
                }
            }

            if (reduceRank) {
                rank--;
                for (int i = 0; i < n; ++i) {
                    Arr[i][row] = Arr[i][rank];
                }
            }
            row--;
        }
    }

    return rank;
}
void matrix::transposition(int n) {
    for (int i = 0; i < n; i++){
        for (int j = i; j < n; j++) {
            swap(Matrix[i][j], Matrix[j][i]);
        }
    }
}
void matrix::show(QString& s, int n) {
    for (int i = 0; i < sqrt(n); i++) {
        for (int j=0; j < sqrt(n); j++) {
            s << Matrix[i][j];
            s += " ";
        }
        s += "\n";
    }
}
void matrix::input(number** Arr, int n) {
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            Matrix[i][j] = Arr[i][j];
        }
    }
}

matrix::~matrix(){
    delete[] Matrix;
}

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------
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
