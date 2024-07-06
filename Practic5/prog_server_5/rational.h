#ifndef RATIONAL_H
#define RATIONAL_H
#include <iostream>
#include <QString>

using namespace std;

class Rational
{
    static QChar SEPARATOR;

    int numerator, denominator;
public:
    Rational();
    Rational(int, int);
    Rational(const QByteArray& arr);
    void divider(Rational&);
    Rational operator+ (Rational);
    Rational operator- (Rational);
    Rational operator- ();
    Rational operator* (Rational);
    Rational operator/ (Rational);
    bool operator==(Rational);
    bool operator!=(Rational);
    int getNum();
    int getDenom();

    static void setSeparator(QChar);

    friend double Abs(Rational);
    friend ostream& operator<<(ostream&, Rational);
    friend istream& operator>>(istream&, Rational&);

    friend QString& operator<<(QString&, Rational);
    friend QByteArray& operator>>(QByteArray&,Rational&);
    operator QString ();
};

#endif // RATIONAL_H
