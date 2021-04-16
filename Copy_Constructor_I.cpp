#include <iostream>
#include <cmath>
using namespace std;

/*
    Copy Constructor:
    It takes an object of the same type and constructs a copy.

    Why do we need Copy Constructor ?
    Ans : For system defined data types, copy was easy (call-by-value OR return-by-value)
          but for UDT, we need Copy Constructor
          Also copy constructor is needed for initializing the data members of a UDT from an existing value.

    Why the parameter of copy constructor is Call-by-Reference ?
    Ans : Look for Copy_Constructor_II.cpp  (https://github.com/MAZHARMIK/OOP_Crash_Course_Cpp/blob/main/Copy_Constructor_II.cpp)
*/

class Complex {
private:
    double re_;
    double im_;
public:
    //constructor
    Complex(double re , double im): re_(re), im_(im) {
        cout << "Complex Constructor: ";
        print();
    }

    //copy constructor: Parameter should be passed as reference only
    Complex(const Complex& c): re_(c.re_), im_(c.im_) {
        cout << "Complex copy Constructor: ";
        print();
    }

    ~Complex() {
        cout << "Complex Destructor. Bye Bye !";
        print();
    }

    double norm() {
        return sqrt(re_*re_ + im_*im_);
    }

    void print() {
        cout << "|" << re_ << "+j" << im_ << "| = " << norm() << endl;
    }

};

//Application
int main() {
    Complex c1(4.2, 5.3); //Constructor      - Complex(double, double)
    Complex c2(c1);       //Copy Constructor - Complex(const Complex&)
    Complex c3 = c2;      //Copy Constructor - Complex(const Complex&)

    c1.print();
    c2.print();
    c3.print();

return 0;
}
