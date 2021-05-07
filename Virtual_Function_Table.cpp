#include <bits/stdc++.h>
using namespace std;

/*
    Virtual Function Table
    -Understanding Virtual Function Table for dynamic binding (Polymorphic dispatch)
    If a class is polymorphic (it has at least one polymorphic function),then for that class, there will be
    a virtual function table (VFT), which will have all the virtual functions listed one after the other in the order
    they have been defined.

    As class is specialized, the compiler checks if the derived class overrides the virtual function, if yes, then
    compiler changes the corresponding entry in its own VFT and replaces with the version it has overridden.

    -Whenever a class defines a virtual function, a hidden member variable is added to the class which points to an array
     of pointers to (virtual) functions call ed Virtual Function Table (VFT)

    -VFT pointers are used at run-time to invoke the appropriate function implementations, because at compile time it may
     not be known if the base function is to be called or a derived one, implemented by a class that inherits from base class.

    -VFT is class-specific -- all instances of the class has the same VFT

    -VFT carries the Run-Time Type Information (RTTI) of objects.




*/

class B {
    int i_;
public:
    B(int i) : i_(i) {}

    void f(int);         // B::f(B*const, int)
    virtual void g(int); // B::g(B*const, int)
};

class D : public B {
    int j_;
    D(int i, int j) : B(i), j_(j) {};

    void f(int); //D::f(D*const, int)
    void g(int); //D::g(D*const, int)
};

int main() {
    /*
    b Object layout                      VFT of B
        vft   ->              0th-index -> B::g(B*const, int)
        B::i  100
    */
    B b(100);

    B *p = &b;

    b.f(15);   //B::f(&b, 15);
    p->f(25);  //B::f(p, 25);

    b.g(35);   //B::g(&b, 35);

    p->g(45);  //p->vft[0](p, 45); //since g is a virtual function (vft is the hidden pointer to array)

    D d(200, 500);

    /*
    d Object layout                      VFT of D
        vft   ->              0th-index -> D::g(D*const, int) //because derived class has overridden virtual function of base class
        B::i  200
        D::j  500
    */

    p = &d;

    d.f(15);   //D::f(&d, 15)

    p->f(25);  //B::f(p, 25);

    d.g(35);   //D::g(&d, 35)

    p->g(45);  //p->vft[0](p, 45) , here the value of p is &d now

return 0;
}
