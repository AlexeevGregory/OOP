#include "rational.h"

Rational::Rational(){
    numerator = 0;
    denominator = 0;
}

Rational::Rational(int a, int b){
    numerator = a;
    denominator = b;
}

void Rational::divider(Rational& t){
    int m = t.denominator, i = 2;
    while (true) {
        if (((t.numerator % i == 0) && (t.denominator % i == 0)) || ((t.numerator % (-i) == 0) && (t.denominator % (-i) == 0)) || ((t.numerator % (-i) == 0) && (t.denominator % i == 0)) || ((t.numerator % i == 0) && (t.denominator % (-i) == 0))) {
            t.numerator /= i;
            t.denominator /= i;
            m = t.denominator;
            i = 2;
        }
        else i++;
        if ((i == m) || ((-i) == m)||(m == 0) || (m == 1)) break;
    }
}

Rational Rational::operator+ (Rational R){
    Rational t;
    t.numerator = this->numerator*R.denominator + R.numerator*this->denominator;
    t.denominator = this->denominator*R.denominator;
    divider(t);
    return t;
}
Rational Rational::operator- (Rational R){
    Rational t;
    t.numerator = this->numerator*R.denominator - R.numerator*this->denominator;
    t.denominator = this->denominator*R.denominator;
    divider(t);
    return t;
}
Rational Rational::operator- (){
    Rational t;
    t.numerator = this->numerator*(-1);
    t.denominator = this->denominator*(-1);
    return t;
}
Rational Rational::operator* (Rational R){
    Rational t;
    t.numerator = this->numerator*R.numerator;
    t.denominator = this->denominator*R.denominator;
    divider(t);
    return t;
}
Rational Rational::operator/ (Rational R){
    Rational t;
    t.numerator = this->numerator*R.denominator;
    t.denominator = this->denominator*R.numerator;
    divider(t);
    return t;
}

int Rational::getNum(){
    return numerator;
}
int Rational::getDenom(){
    return denominator;
}

ostream& operator<<(ostream& os, Rational R){
    os << R.numerator << "/" << R.denominator;
    return os;
}
istream& operator>>(istream& is, Rational& R){
    is >> R.numerator >> R.denominator;
    return is;
}
QString& operator<<(QString& s, Rational R){
    s+= "(";
    s+= QString().setNum(R.numerator);
    s+= "/";
    s+= QString().setNum(R.denominator);
    s+= ")";
    return s;
}
Rational::Rational(const QByteArray& arr)
{
    int p = arr.indexOf(";");
    numerator = arr.left(p).toDouble();
    denominator = arr.right(arr.length()-p-1).toDouble();
}

QByteArray& operator>>(QByteArray& arr, Rational& c)
{
    int p = arr.indexOf(";");
    p = arr.indexOf(";",p+1);
    if (p > 0)
    {
        c = Rational(arr.left(p));
        arr = arr.right(arr.length()-p-1);
    }
    return arr;
}
double Abs(Rational R){
    double val = (R.numerator*R.numerator)/(R.denominator*R.denominator);
    val = pow(val,0.5);
    return val;
}
