#include "square_matrix.h"

square_matrix::square_matrix(unsigned short n){
    Matrix = new number*[n];
    for (int i = 0; i < n; ++i) {
        Matrix[i] = new number[n];
    }
}


number square_matrix::MatrDeterminant(int n) {
    if (n == 1) {
        return Matrix[0][0];
    }
    else if (n == 2) {
        return (Matrix[0][0] * Matrix[1][1] - Matrix[0][1] * Matrix[1][0]);
    } else {
        number det(0,0);
        number sign(1,1);

        square_matrix minor(n-1);

        for (int i = 0; i < n; ++i) {

            int minorRow = 0;
            for (int row = 1; row < n; ++row) {
                int minorCol = 0;
                for (int col = 0; col < n; ++col) {
                    if (col != i) {
                        minor.Matrix[minorRow][minorCol] = Matrix[row][col];
                        minorCol++;
                    }
                }
                minorRow++;
            }

            number minorDet = minor.MatrDeterminant(n - 1);

            det = det + ( sign * Matrix[0][i] * minorDet);

            sign = -sign;
        }
        return det;
    }
}
