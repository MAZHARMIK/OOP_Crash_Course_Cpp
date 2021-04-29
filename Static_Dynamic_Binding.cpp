#include <iostream>
using namespace std;

/*
    Dynamic Binding Part I
    Static and Dynamic Binding
    -Binding         : Given an expression, you decide which function will be called.
    -STatic Binding  : Which function will be called depends on type of pointer
    -Dynamic Binding : Which function will be called depends on type of object the pointer points to (virtual functions)

*/

class B {
public:
    void f() {
        cout << "B::f()" << endl;
    }
    virtual void g() {
        cout << "B::g()" << endl;
    }
};

class D: public B {
public:
    void f() {
        cout << "D::f()" << endl;
    }
    virtual void g() {
        cout << "D::g()" << endl;
    }
};

    /*
            B
            ^
            |
            |
            |
            D
    */
int main() {
    B b;
    D d;

    B *pb = &b;
    B *pd = &d;  //UPCAST

    B &rb = b;
    B &rd = d; //UPCAST

    //calling functions using object (simple case)
    b.f(); //B::f()
    b.g(); //B::g()
    d.f(); //D::f()
    d.g(); //D::g()

    //calling functions using pointer
    pb->f(); //B::f() //static binding
    pb->g(); //B::g() //Dynamic Binding

    pd->f(); //B::f() //Static Binding
    pd->g(); //D::g() //Dynamic Binding

    //Binding of f() is static i.e. which function it calls depends on the type of the pointer
    //Something that is statically known by the compiler in the start.

    //Binding of g() is dynamic i.e. which function it calls depends on the type of the object it is
    //pointing to during runtime. It happens because we have used virtual keyword (g() is a virtual function)

    //Same goes like this below
    rb.f(); //B::f() //static binding
    rb.g(); //B::g() //dynamic binding
    rd.f(); //B::f() //static binding
    rd.g(); //D::g() //dynamic binding

return 0;
}
