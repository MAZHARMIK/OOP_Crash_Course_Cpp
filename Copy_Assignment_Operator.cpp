#include <bits/stdc++.h>
using namespace std;

/*
    Copy Assignment Operator
    Read comments in the code for questions and answers asked form this topic
*/

class Complex {
public:
    double  re_;
    double  im_;
public:
    //constructor
    Complex(double re, double im): re_(re), im_(im) {
        cout << "ctor: ";
        print();
    }

    Complex(const Complex& c): re_(c.re_), im_(c.im_) {
        cout << "copy ctor: ";
        print();
    }

    ~Complex() {
        cout << "dtor: ";
        print();
    }

    Complex& operator=(const Complex& c) { //copy assignment operator
        //Why pass by reference  ?
        //Because we don't want an unnecessary copy constructor to be called
        //Why const ?
        //Because, I don't want c to change
        //Why returnin Complex& (object of same type ) ?
        //To support Copy Assignment Chain
        if(this != &c) { //we don't want a self copy by mistake
            re_ = c.re_;
            im_ = c.im_;
            cout << "Copy Assignment: ";
            print();
        }
        return *this;
    }

    double norm() {
        return sqrt(re_*re_ + im_*im_);
    }

    void print() {
        cout << "|" << re_ << "+j" << im_ << "| = " << norm() << endl;
    }
};

int main() {
    Complex c1(4.2, 5.3); //Constructor      - Complex(double, double)
    Complex c2(7.9, 8.5); //Constructor      - Complex(double, double)

    Complex c3(c2);       //Copy Constructor - Complex(const Complex&)
    //NOTE : c3 doesn't exist. While it's created, c2 is copied to it

    c1.print();
    c2.print();
    c3.print();

    c2 = c1; //Copy Assignment Operator (i.e. c2.operator=(c1))
    //NOTE : c2 already exists and I want to take c1 and make c2 a copy of c1
    c2.print();

    c1 = c2 = c3;  //Copy Assignment chain (c1 = (c2 = c3)), so, (c2 = c3) should be an expression and that
    //should be such an expression which can be assigned to c1. Hence, We return Complex& from copy assignemnt
    //operator above
    c1.print();
    c2.print();
    c3.print();

return 0;
}
