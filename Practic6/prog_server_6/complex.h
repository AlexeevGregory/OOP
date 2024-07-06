#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>
#include <QString>

using namespace std;

class Complex
{
    double Re, Im;
public:
    Complex();
    Complex(const int&);
    Complex(const QByteArray& arr);
    Complex operator*(Complex);
    Complex operator*(int);
    Complex operator-(Complex);
    Complex operator-();
    bool operator!= (int);
    Complex operator+(Complex);
    Complex operator/(Complex);


    friend ostream& operator<<(ostream&, Complex);
    friend istream& operator<<(istream&, Complex);
    friend QString& operator<<(QString&, Complex);
    friend QByteArray& operator>>(QByteArray&,Complex&);
};
#endif // COMPLEX_H
