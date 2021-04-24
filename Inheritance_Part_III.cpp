#include <iostream>
using namespace std;

/*
    Inheritance - III
    :Member Functions
        -Derived class inherits all member function of Base class
        -Derived class may "override" a member function of Base class by redefining it with the "same signature"
        -Derived class may "overload" a member function of Base class by redefining it with same name but "different signature"
        -Derived class may add new member functions

    Important Points:
    -Static Member Functions : Derived class does not inherit the static member functions of Base class
    -Friend Functions        : Derived class does not inherit the friend functions of Base class

    Two examples mentioned below
*/

///*************Example-1*****************///
class B { //Base class
public:
    void f(int i);
    void g(int i);
};

class D : public B { //Derived Class
public:
    //Inherits B::f(int);
    //Inherits B::g(int);
};

int main() {
    B b;
    D d;

    b.f(1); // Calls B::f(int)
    b.g(2); // Calls B::g(int)

    d.f(1); // Calls B::f(int)
    d.g(2); // Calls B::g(int)

return 0;
}


///*************Example-2*****************///
class B { //Base class
public:
    void f(int i);
    void g(int i);
};

class D : public B { //Derived Class
public:
    //Inherits B::f(int);
    void f(int);        //Overrides B::f(int)
    void f(string&);    //Overloads B::f(int)

    //Inherits B::g(int);
    void h(int i);      //Add D::h(int)
};

int main() {
    B b;
    D d;

    b.f(1);     // Calls B::f(int)
    b.g(2);     // Calls B::g(int)

    d.f(1);     // Calls B::f(int)
    d.g(2);     // Calls B::g(int)

    d.f("red"); //Calls D::f(string&)
    d.h(5);     //Calls D::h(int)

    /*
        D::f(int)    overrides B::f(int)
        D::f(string) overloads B::f(int)
    */

return 0;
}
