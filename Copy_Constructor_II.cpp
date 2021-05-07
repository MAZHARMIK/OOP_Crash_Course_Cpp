#include <iostream>
#include <cmath>
using namespace std;

/*
    Copy Constructor:
    - call by value calls copy constructor and for this copy destructor will be called as well.
    - If it had been passed by reference, then no copy constructor is called which means no new object is created and hence no destructor will be called.

    Why the parameter to a copy constructor must be passed as Call-by-Reference ?
    Ans: MyClass(MyClass other);
         The above is an infinite loop as the call to copy constructor itself needs to make a copy for the
         Call-by-Value mechanism.
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

    //copy constructor
    Complex(const Complex& c): re_(c.re_), im_(c.im_) {
        cout << "Complex copy Constructor: ";
        //print();
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

    void Display_Call_By_Value(Complex c_param) { //call by value
        cout << "Display: " ;
        c_param.print();
    }

    void Display_Call_By_Reference(Complex& c_param) { //call by reference
        cout << "Display: " ;
        c_param.print();
    }

};

//Application
int main() {
    Complex c(4.2, 5.3); //Constructor      - Complex(double, double)

    c.Display_Call_By_Value(c);           //Copy constructor called to copy c to c_param

    //since there is a copy of c that has been created while call to Display(),
    //Hence, destructor will be called for c_param as well

    /*Output :
        Complex Constructor: |4.2+j5.3| = 6.7624
        Complex copy Constructor: |4.2+j5.3| = 6.7624
        Display: |4.2+j5.3| = 6.7624
        Complex Destructor. Bye Bye !|4.2+j5.3| = 6.7624
        Complex Destructor. Bye Bye !|4.2+j5.3| = 6.7624
    */

    c.Display_Call_By_Reference(c);

    /*Output :
        Complex Constructor: |4.2+j5.3| = 6.7624
        Complex copy Constructor: Display: |4.2+j5.3| = 6.7624
        Complex Destructor. Bye Bye !|4.2+j5.3| = 6.7624
        Display: |4.2+j5.3| = 6.7624
        Complex Destructor. Bye Bye !|4.2+j5.3| = 6.7624
    */


return 0;
}
