#ifndef MATRIX_H
#define MATRIX_H
#include "number.h"

class matrix
{
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
    number** Matrix;
};

#endif // MATRIX_H
