#ifndef MATRIX_H
#define MATRIX_H

#include"Qstring"

template <class number>
class matrix
{
    number** Matrix;
public:

    matrix();
    matrix(unsigned short, unsigned short);
    ~matrix();
    void transposition(int);
    number MatrDeterminant(int);
    int rankOfMatrix3x3();
    int findMatrixRank(int);
    void show(QString&, int);
    void input(number**, int);

private:

protected:

};


template <class number>
matrix<number>::matrix(){
    Matrix = new number*[3];
    for (int i = 0; i < 3; ++i) {
        Matrix[i] = new number[3];
    }
}

template <class number>
matrix<number>::matrix(unsigned short columns, unsigned short rows){
    Matrix = new number*[rows];
    for (int i = 0; i < rows; ++i) {
        Matrix[i] = new number[columns];
    }
}

template <class number>
int matrix<number>::findMatrixRank(int n) {
    number Swap;
    number** Arr= new number*[n];
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
        if (Arr[row][row] != 0) {
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
                if (Arr[i][row] != 0) {
                    for (int j = 0; j < rank; ++j) {
                        Swap = Arr[row][j];
                        Arr[row][j] = Arr[i][j];
                        Arr[i][j] = Swap;
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

template <class number>
void matrix<number>::transposition(int n) {
    number Swap;
    for (int i = 0; i < n; i++){
        for (int j = i; j < n; j++) {
            Swap = Matrix[i][j];
            Matrix[i][j] = Matrix[j][i];
            Matrix[j][i] = Swap;
        }
    }
}

template <class number>
void matrix<number>::show(QString& s, int n) {
    for (int i = 0; i < sqrt(n); i++) {
        for (int j=0; j < sqrt(n); j++) {
            s << Matrix[i][j];
            s += " ";
        }
        s += "\n";
    }
}

template <class number>
void matrix<number>::input(number** Arr, int n) {
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            Matrix[i][j] = Arr[i][j];
        }
    }
}

template <class number>
matrix<number>::~matrix(){
    delete[] Matrix;
}



#endif // MATRIX_H

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------
/*int matrix<number>::rankOfMatrix3x3() {
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
*/

