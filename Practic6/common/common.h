#ifndef COMMON_H
#define COMMON_H

#include <QString>

enum messages
{
    SHOWMATRIX = 1,
    TRANSPOSEDMATRIX,
    RANKOFMATRIX,
    DETERMINANT,
};

enum modes{
    D_MODE = 1,
    R_MODE,
    C_MODE,
};

extern const QChar separator;
QString& operator<< (QString&,const QString&);

#endif // COMMON_H
