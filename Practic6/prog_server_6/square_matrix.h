#ifndef SQUARE_MATRIX_H
#define SQUARE_MATRIX_H

#include "matrix.h"

template <class number>
class square_matrix : public matrix<number> {
    number** Matrix;
public:
    square_matrix(unsigned short);
    number MatrDeterminant(number**, int);
};


template <class number>
square_matrix<number>::square_matrix(unsigned short n){
    Matrix = new number*[n];
    for (int i = 0; i < n; ++i) {
        Matrix[i] = new number[n];
    }
}

template <class number>
number square_matrix<number>::MatrDeterminant(number** arr,int n) {
    if (n == 1) {
        return arr[0][0];
    }
    else if (n == 2) {
        return (arr[0][0] * arr[1][1] - arr[0][1] * arr[1][0]);
    }
    else {
        number det;
        det = 0;
        int sign = 1;

        number** minor = new number* [n];
        for(int i = 0; i < pow(n,0.5); i++){
            minor[i] = new number[n];
        }
        for (int i = 0; i < n; ++i) {

            int minorRow = 0;
            for (int row = 1; row < n; ++row) {
                int minorCol = 0;
                for (int col = 0; col < n; ++col) {
                    if (col != i) {
                        minor[minorRow][minorCol] = arr[row][col];
                        minorCol++;
                    }
                }
                minorRow++;
            }
            det = det + (arr[0][i] * MatrDeterminant(minor,n-1) * sign) ;

            sign = -sign;
        }
        return det;
    }
}

#endif // SQUARE_MATRIX_H
