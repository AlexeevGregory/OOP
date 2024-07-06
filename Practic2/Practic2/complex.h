#ifndef TCOMPLEX_H
#define TCOMPLEX_H
#include <iostream>
using namespace std;

class Complex
{
    double Re, Im;
public:
    Complex();
    Complex(const int&);
    Complex operator*(Complex);
    Complex operator-(Complex);
    Complex operator-();
    Complex operator+(Complex);
    Complex operator/(Complex);
    bool operator== (Complex);

    friend double Abs(Complex);
    friend ostream& operator<<(ostream&, Complex);
    friend istream& operator>>(istream&, Complex&);
};

#endif // TCOMPLEX_H
