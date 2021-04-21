#include <iostream>
using namespace std;

/*
    overloading IO Operators operator<<, operator>>
    Since, global operator function breaks encapsulation,
    We now try to overload it using member operator function
    //Read comments below

    Case : 1  operator<< is a member in ostream class:
    ostream& ostream::operator<<(const Complex &a);

    This is not possible as ostream is a class in C++ std library and we are not allowed to edit it to include the above signature

    Case : 2 operator<< is a member in Complex class:
    ostream& Complex::Complex<<(ostream& os);

    In this case, the invocation of streaming will change to
    d << cout; //left operand is the invoking object

    This spoils the natural syntax. So we can't overloaded them using member function

    Sooooooo,
    We finally come to friend function to solve our problems

*/

class Complex {
private:
    double re, im; //They can be private now
public:
    Complex(double r = 0, double i = 0): re(r), im(i) {}

    friend ostream& operator << (ostream& os, const Complex& a);

    friend istream& operator >> (istream& is, Complex& a); //Don't use const Complex, because we are taking an input and it changes
};

ostream& operator << (ostream& os, const Complex& a) {
    os << a.re;
    os << " +j " << a.im << endl;
    return os;
}

istream& operator >> (istream& is, Complex& a) { //Don't use const Complex, because we are taking an input and it changes
    is >> a.re;
    is >> a.im;
    return is;
}

int main() {
    Complex d;

    cin >> d;

    cout << d;

return 0;
}

