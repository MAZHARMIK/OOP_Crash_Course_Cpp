#include <bits/stdc++.h>
using namespace std;

/*
    Operator overloading for UDT - I
    Binary (two parameters)
    a+b   -  MyType operaror+(const MyType& a, const MyType& b)

    Unary (single parameter)
    a++  -   MyType operaror++(const MyType& a)

    Note :
    -The parameters may not be constant and may be passed by by value as well.
    -The reutrn type may also be reference or may be constant as well.
    -Operator function can be a non-member function as well
        --Global function
        --Friend function. Ex: friend MyType operaror++(const MyType& a)

    When operator function is a member function :
    -then binary operator function can have one parameter because second one can be this pointer
    -then unary operator function can have 0 arguments (with exception post increment operator a++) where we add "int"
    int parameter of the function. We don't pass anything, it's just for compiler

    Two examples below
*/

//Example - 1  (Add two Complex class objects
class Complex {
    double real;
    double imag;
public:
    Complex(double re, double im): real(re), imag(im) {}
    Complex operator+(const Complex& c) {
        Complex newC(this->real+c.real, this->imag+c.imag);
        return newC;
    }

    void display() {
        cout << "(" << real << " + i" << imag << ")" << endl;
    }
};

//Example - 2 (concat two String objects)
class String {
    string name;
public:
    String(string s): name(s) {}
    //Since, it is a member function, hence we are passing only one parameter
    String operator+(const String& s) {
        String newObj(this->name + "_" + s.name);
        return newObj;
    }

    void display() {
        cout << name << endl;
    }
};


int main() {
    cout << "\nExample - 1\n";
    Complex c1(1, 2);
    c1.display();

    Complex c2(3, 4);
    c2.display();

    Complex c3 = c1 + c2; //c1.operator+(c2) Binary operator
    c3.display();

    cout << "\nExample - 2\n";
    String s1("Mazhar");
    s1.display();

    String s2("MIK");
    s2.display();

    String s3 = s1 + s2;  //s1.operator+(s2) Binary operator
    s3.display();

return 0;
}

