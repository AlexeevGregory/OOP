#ifndef DOUBLE_H
#define DOUBLE_H

#include <QString>

inline QString& operator<<(QString& s, double R){
    s+= QString().setNum(R);
    return s;
}

inline QByteArray& operator>>(QByteArray& arr, double& c)
{
    int p = arr.indexOf(";");
    c = arr.left(p).toDouble();
    arr = arr.right(arr.length()-p-1);
    return arr;
}


#endif // DOUBLE_H
