#include <iostream>
using namespace std;

/*
    overloading IO Operators operator<<, operator>>
    Using global operator function :  It breaks encapsulation and member operator function has limitation
    //Read comments below

*/

class Complex {
public:
    double re, im; //They are made public because we are using global operator function
public:
    explicit Complex(double r = 0, double i = 0): re(r), im(i) {}
};

//global operator function
//We return ostream& to support chaining like : cout << d1 << d2;
std::ostream& operator<< (std::ostream& os, const Complex& a) { //overload 1
    os << a.re << " +j " << a.im << endl;
    return os;
}

//global operator function
//We return istream& to support chaining like : cout >> d1 >> d2;
std::istream& operator>> (istream& is, Complex& a) { //Don't use const Complex, because we are taking an input and it changes
    is >> a.re >> a.im;
    return is;
}

int main() {
    Complex d;

    cin >> d;

    cout << d;

return 0;
}

