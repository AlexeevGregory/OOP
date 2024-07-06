#include "rational.h"

Rational::Rational(){

}
Rational::Rational(const int& r)
{
    if(r != 0){
        numerator = r;
        denominator = r;
    }
    else{
        numerator = 0;
        denominator = 0;
    }

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
    t.numerator = numerator*R.denominator + R.numerator*denominator;
    t.denominator = denominator*R.denominator;
    divider(t);
    return t;
}
Rational Rational::operator- (Rational R){
    Rational t;
    t.numerator = numerator*R.denominator - R.numerator*denominator;
    t.denominator = denominator*R.denominator;
    divider(t);
    return t;
}
Rational Rational::operator- (){
    Rational t;
    t.numerator = numerator*(-1);
    t.denominator = denominator*(-1);
    return t;
}
Rational Rational::operator*(int R){
    Rational t;
    t.numerator = numerator*R;
    t.denominator = denominator*R;
    divider(t);
    return t;
}
Rational Rational::operator* (Rational R){
    Rational t;
    t.numerator = numerator*R.numerator;
    t.denominator = denominator*R.denominator;
    divider(t);
    return t;
}
Rational Rational::operator/ (Rational R){
    Rational t;
    t.numerator = numerator*R.denominator;
    t.denominator = denominator*R.numerator;
    divider(t);
    return t;
}

bool Rational::operator!=(Rational R){
    return (numerator!=R.numerator)&&(denominator!=R.denominator);
}
/*bool Rational::operator!=(int R){
    return (numerator!=R)&&(denominator!=R);
}
*/
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
    c = Rational(arr.left(p));
    arr = arr.right(arr.length()-p-1);
    return arr;
}
double Abs(Rational R){
    double val = (R.numerator*R.numerator)/(R.denominator*R.denominator);
    val = pow(val,0.5);
    return val;
}
