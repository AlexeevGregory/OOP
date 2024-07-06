#ifndef SQUARE_MATRIX_H
#define SQUARE_MATRIX_H

#include "number.h"
#include "matrix.h"

class square_matrix : public matrix {
public:
    square_matrix(unsigned short);
    number MatrDeterminant(int);
};

#endif // SQUARE_MATRIX_H
