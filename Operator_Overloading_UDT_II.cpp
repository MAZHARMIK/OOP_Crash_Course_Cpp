#include <bits/stdc++.h>
using namespace std;

/*
    Operator overloading continued:
    Extending operator+

    Issues in operator overloading :
    -What if user wants to achieve something like this :
    obj2 = obj1 + 3.4;

    -What if we want to overload streaming operators in order to achieve something like this :
    Complex obj;
    cin  >> obj;
    cout << obj;
    Note :
        cout is an ostream object
        cin  is an istream object

    We will come to know in the examples below that to achieve above mentioned scenarios :
    -How global operator function is not good for this  (shhhaaaahhhhh!!!)
    -Why member operator function cannot do this        (shhhaaaahhhhh!!!)  - Operator_Overloading_UDT_III.cpp
    -How friend function achieves this                  (Wowwwww!!!!)       - Operator_Overloading_UDT_IV.cpp
*/

class Complex {
public:
    double re, im;
public:
    Complex(double r = 0, double i = 0): re(r), im(i) {}

    void display() {
        cout << re << " +j" << im << endl;
    }
};

//Global operator function
Complex operator+(const Complex& a, const Complex& b) { //overload 1
    return Complex(a.re + b.re, a.im + b.im);
}

//Global operator function
Complex operator+(const Complex& a, double d) { //overload 2
     Complex b(d); //create temp object and user overload 1
     return a+b;
}

//Global operator function
Complex operator+(double d, const Complex& b) { //overload 3
    Complex a(d); //create temp object and user overload 1
    return a+b;
}



int main() {

    /*Using Global operator Function*/
    //This breaks encapsulation. Access to data members of class.
    Complex d1(2.5, 3.2);

    Complex d2(1.6, 3.3);

    Complex d3;

    d3 = d1 + d2;
    d3.display();

    d3 = d1 + 6.2;
    d3.display();

    d3 = 4.2 + d2;
    d3.display();


return 0;
}

