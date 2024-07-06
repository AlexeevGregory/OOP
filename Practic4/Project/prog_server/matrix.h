#ifndef MATRIX_H
#define MATRIX_H
#include "number.h"

class matrix
{
    number Matrix[3][3];
public:
    matrix();
    void transposition();
    number MatrDeterminant();
    int rankOfMatrix3x3();
    void show(QString&);
    void input(number,number,number,number,number,number,number,number,number);

private:

};

#endif // MATRIX_H
