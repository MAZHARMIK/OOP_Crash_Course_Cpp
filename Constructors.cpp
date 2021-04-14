#include <iostream>
#include <cmath>
using namespace std;

/*
    Constructors in C++
    Constructor is used for construction of an object(i.e. initialization). Hence, It doesn't have return type.
    We can do initialization using initializer list as well.
    - We can have parameterized constructor (default parameters can also be used)
    - We can have overloaded constructors as well

*/

class Complex {
private:
    double re_, im_;
public:
    Complex(double re, double im): re_(re), im_(im) {}
    Complex(double re): re_(re), im_(0.0) {}
    Complex(): re_(0.0), im_(0.0) {}

    double norm() {
        return sqrt(re_*re_ + im_*im_);
    }

    void print() {
        cout << "|" << re_ << "+j" << im_ << "| = " << norm() << endl;
    }

};

//Application
int main() {
    Complex c1(4.2, 5.3);
    Complex c2(4.2);
    Complex c3;

    c1.print();
    c2.print();
    c3.print();

return 0;
}
