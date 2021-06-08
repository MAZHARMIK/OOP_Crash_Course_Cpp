#include <bits/stdc++.h>
using namespace std;

/*
    Multiple Inheritance Part - I
    Few important points:
    - Derived class cannot access private members of any Base class
    - Derived class can access protected members of any Base class
    - constructor of Derived class must first call all constructors of the Base classes to construct
      Base class instances of the Derived class - Base class constructors are called in listing order
      If not called, then Base class must have default constructor (obvious)
    - Destructors of Derived class must first call all Destructors of the Base classes to destruct
      Base class instances of the Derived class 
    - Derived class objects will have instances of all its Base classes

    - If Base classes have function/s with same function name, then we will have to use the keyword "using" for
      name resolution if Base classes are in different namespaces
      OR,
      We can explicitly mention the class name from where we want to access
*/

class Base1 {
protected:
    int i_;
    int data_;

public:
    Base1(int a, int b) : i_(a), data_(b) {}
    ~Base1() {
        cout << "~Base1()" << endl;
    }
    void f(int x) {
        cout << "Base1::f(int)" << endl;
    }

    void g() {
        cout << "Base1::g()" << endl;
    }

    void same() {
        cout << "Base1::same()" << endl;
    }
};

class Base2 {
protected:
    int j_;
    int data_;

public:
    Base2(int a, int b) : j_(a), data_(b) {}

    ~Base2() {
        cout << "~Base2()" << endl;
    }

    void h(int a) {
        cout << "Base2::h()" << endl;
    }

    void same(int x) {
        cout << "Base2::same()" << endl;
    }
};

class Derived : public Base1, public Base2 {
    int k_;

public :
    Derived(int x, int y, int u, int v, int z) : Base1(x, y), Base2(u, v) {}

    ~Derived() {
        cout << "~Derived()" << endl;
    }

    void f(int a) {
        cout << "Derived::f(int)" << endl; //overridden Base1::f()
    }
    // -- Inherited Base1::g()

    void h(string s) {
        cout << "Derived::h(string)" << endl; //overload Base2::h()
    }

    void e(char ch) {
        cout << "Derived::e(ch)" << endl; //Added its own member function Derived::e(char)
    }

    using Base1::same; //For name resolution
};

int main() {
    Derived d(1, 2, 3, 4, 5);

    d.f(5);     //Derived::f(int)    -- overridden Base1::f()

    d.g();      //Base1::g()         -- Inherited Base1::g()

    d.h("MIK"); //Derived::h(string) -- Overloaded Base2::h(int)

    d.e('M');  //Derived::e(char)    -- //Added its own member function Derived::e(char)

    /*

    d.same();  //error: request for member 'same' is ambiguous

    d.same(5); //error: request for member 'same' is ambiguous

    So, we add -   using Base1::same;  inside Derived class definition
    */

   //Now, it will work
   d.same();         //Calls Base1::same()
   d.Base2::same(2); //This can be used too explicitly (Calls Base2::same(int))

    /*
        Outout : 
        Derived::f(int)
        Base1::g()
        Derived::h(string)
        Derived::e(ch)
        Base1::same()
        Base2::same()
        ~Derived()
        ~Base2()
        ~Base1()
    */

   //NOTE  : First construct Base, then derived. First destruct derived, then Base (reverse order)

return 0;
}
