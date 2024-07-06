#ifndef MATRIX_H
#define MATRIX_H
#include "number.h"

class matrix
{
public:
    matrix(){
    };
    void transposition(number matrix[3][3]);
    number determinant(number matrix[3][3]);
    int rankOfMatrix3x3(number matrix[3][3]);
    void show(number matrix[3][3]);
    void input(number matrix[3][3]);
private:

};

#endif // MATRIX_H
