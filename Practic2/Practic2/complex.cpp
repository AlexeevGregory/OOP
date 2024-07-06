#include "complex.h"
#include <math.h>

Complex::Complex()
{

}
Complex::Complex(const int& r)
{
    Re = r;
    Im = 0;
}

Complex Complex::operator* (Complex c){
    Complex t;
    t.Re = Re*c.Re - Im*c.Im;
    t.Im = Re*c.Im + Im*c.Re;
    return t;
}
Complex Complex::operator- (Complex c){
    Complex t;
    t.Re = Re - c.Re;
    t.Im = Im - c.Im;
    return t;
}
Complex Complex::operator- (){
    Complex t;
    t.Re = t.Re * (-1);
    t.Im = t.Im * (-1);
    return t;
}
Complex Complex::operator+ (Complex c){
    Complex t;
    t.Re = Re + c.Re;
    t.Im = Im + c.Im;
    return t;
}
Complex Complex::operator/ (Complex c){
    Complex t;
    t.Re = (Re*c.Re - Im*c.Im)/(c.Re*c.Re-c.Im*c.Im);
    t.Im = (Re*c.Im + Im*c.Re)/(c.Re*c.Re-c.Im*c.Im);
    return t;
}
bool Complex::operator== (Complex c){
    return (Re == c.Re)&&(Im == c.Im);
}

double Abs(Complex c){
    double val = (c.Re*c.Re + c.Im*c.Im);
    val = pow(val,0.5);
    return val;
}

ostream& operator<<(ostream& os, Complex c){
    if(c.Im > 0) os << c.Re << "+" << c.Im << "i";
    else if(c.Im < 0) os << c.Re  << c.Im << "i";
    else os << c.Re << "+" << c.Im << "i";
    return os;
}

istream& operator>>(istream& is, Complex& c){
    is >> c.Re >> c.Im;
    return is;
}
