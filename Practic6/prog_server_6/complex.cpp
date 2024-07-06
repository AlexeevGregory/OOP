#include "complex.h"

Complex::Complex()
{

}
Complex::Complex(const int& r)
{
    Re = r;
    Im = 0;
}

Complex Complex::operator*(int R){
    Complex t;
    t.Re = Re*R;
    t.Im = Im*R;
    return t;
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
    t.Re = this->Re * (-1);
    t.Im = this->Im * (-1);
    return t;
}
Complex Complex::operator+ (Complex c){
    Complex t;
    t.Re = Re + c.Re;
    t.Im = Im + c.Im;
    return t;
}
bool Complex::operator!= (int n){
    return ((Re!=n)&&(Im!=n));
}
Complex Complex::operator/ (Complex c){
    Complex t;
    t.Re = (Re*c.Re - Im*c.Im)/(c.Re*c.Re-c.Im*c.Im);
    t.Im = (Re*c.Im + Im*c.Re)/(c.Re*c.Re-c.Im*c.Im);
    return t;
}

ostream& operator<<(ostream& os, Complex c){
    os << c.Re << "+" << c.Im << "i";
    return os;
}

istream& operator<<(istream& is, Complex c){
    is >> c.Re >> c.Im;
    return is;
}


QString& operator<<(QString& s, Complex R){
    s+= "(";
    s+= QString().setNum(R.Re);
    if(R.Im >= 0) s+= "+";
    else s+= " ";
    s+= QString().setNum(R.Im);
    s+= "i)";
    return s;
}
Complex::Complex(const QByteArray& arr)
{
    int p = arr.indexOf(";");
    Re = arr.left(p).toDouble();
    Im = arr.right(arr.length()-p-1).toDouble();
}

QByteArray& operator>>(QByteArray& arr, Complex& c)
{
    int p = arr.indexOf(";");
    p = arr.indexOf(";",p+1);
    if (p > 0)
    {
        c = Complex(arr.left(p));
        arr = arr.right(arr.length()-p-1);
    }
    return arr;
}
