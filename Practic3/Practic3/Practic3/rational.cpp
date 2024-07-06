#include "rational.h"

Rational::Rational(){
    numerator = 0;
    denominator = 0;
}

Rational::Rational(int a, int b){
    numerator = a;
    denominator = b;
}

Rational Rational::operator+ (Rational R){
    Rational t;
    t.numerator = this->numerator*R.denominator + R.numerator*this->denominator;
    t.denominator = this->denominator*R.denominator;
    int n = t.denominator, i = 2;
    while(i < n){
        if((t.numerator % i == 0) && (t.denominator % i == 0)){
            t.denominator /= i;
            t.numerator /= i;
            i = 2;
            n = t.denominator;
        }
        else i++;
    }
    return t;
}
Rational Rational::operator- (Rational R){
    Rational t;
    t.numerator = this->numerator*R.denominator - R.numerator*this->denominator;
    t.denominator = this->denominator*R.denominator;
    int n = t.denominator, i = 2;
    while(i < n){
        if((t.numerator % i == 0) && (t.denominator % i == 0)){
            t.denominator /= i;
            t.numerator /= i;
            i = 2;
            n = t.denominator;
        }
        else i++;
    }
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
    int n = t.denominator, i = 2;
    while(i < n){
        if((t.numerator % i == 0) && (t.denominator % i == 0)){
            t.denominator /= i;
            t.numerator /= i;
            i = 2;
            n = t.denominator;
        }
        else i++;
    }
    return t;
}
Rational Rational::operator/ (Rational R){
    Rational t;
    t.numerator = this->numerator*R.denominator;
    t.denominator = this->denominator*R.numerator;
    int n = t.denominator, i = 2;
    while(i < n){
        if((t.numerator % i == 0) && (t.denominator % i == 0)){
            t.denominator /= i;
            t.numerator /= i;
            i = 2;
            n = t.denominator;
        }
        else i++;
    }
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
double Abs(Rational R){
    double val = (R.numerator*R.numerator)/(R.denominator*R.denominator);
    val = pow(val,0.5);
    return val;
}
