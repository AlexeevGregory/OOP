#ifndef RATIONAL_H
#define RATIONAL_H
#include <iostream>
#include <QString>

using namespace std;

class Rational
{
    int numerator, denominator;
public:
    Rational();
    Rational(int, int);
    Rational operator+ (Rational);
    Rational operator- (Rational);
    Rational operator- ();
    Rational operator* (Rational);
    Rational operator/ (Rational);
    int getNum();
    int getDenom();

    friend double Abs(Rational);
    friend ostream& operator<<(ostream&, Rational);
    friend istream& operator>>(istream&, Rational&);
    friend QString& operator<<(QString&, Rational);
};

#endif // RATIONAL_H
