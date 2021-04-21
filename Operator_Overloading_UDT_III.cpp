#include <bits/stdc++.h>
using namespace std;

/*
    Operator overloading continued:
    Extending operator+

    In Opearotr Overloadin UDT-II , we saw that Global operator function breaks encapsulation
    So, we will now use member operator function
*/

class Complex {
private:
    double re, im; //They can be private now
public:
    Complex(double r = 0, double i = 0): re(r), im(i) {}

    void display() {
        cout << re << " +j" << im << endl;
    }

    Complex operator+(const Complex& a, const Complex& b) { //overload 1
        return Complex(a.re + b.re, a.im + b.im);
    }

    Complex operator+(const Complex& a, double d) { //overload 2
        Complex b(d); //create temp object and user overload 1
        return a+b;
    }
};

int main() {

    /*Using member operator Function*/
    //Can't handle case like MyClass d2 = 2.3 + d2;
    Complex d1(2.5, 3.2);

    Complex d2(1.6, 3.3);

    Complex d3;

    d3 = d1 + d2; //left opearand d1 is an object and it will be called as d1.operator+(d2)
    d3.display();

    d3 = d1 + 6.2;//left opearand d1 is an object and it will be called as d1.operator+(6.2)
    d3.display();

    //d3 = 4.2 + d2; //Error!!!!! : Not possible - needs an object of left
    //d3.display();


return 0;
}

