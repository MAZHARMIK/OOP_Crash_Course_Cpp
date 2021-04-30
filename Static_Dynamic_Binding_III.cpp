#include <bits/stdc++.h>
using namespace std;

/*
    static and dynamic binding III
    Polymorphism Rule

    -If a member in inheritance hierarchy has virtual function then, the hierarchy is of Polymorphic type
    -If a function is virtual in a class and if this class has been derived, then this function is a virtual function
    in derived class as well

    RULE TO REMEBER:
    -Once a virtual, continues to be virtual in any specialization (inheritance hierarchy)
    -But, non-virtual function can be made virtual at a point and from that point onwards it continues to be virtual down the hierarchy

*/

class A {
public:
    void f() {
        cout << "A::f()" << endl; //non-virtual
    }

    virtual void g() {
        cout << "A::g()" << endl; //virtual
    }

    void h() {
        cout << "A::h()" << endl; //non-virtual
    }
};

class B: public A {
public:
    //overriding functions
    void f() {
        cout << "B::f()" << endl; //non-virtual
    }

    void g() {
        cout << "B::g()" << endl; //virtual (still virtual because it's inheriting from A
    }

    virtual void h() {
        cout << "B::h()" << endl; //virtual (I made it virtual here)
    }
};

class C : public B {
public:
    void f() {
        cout << "C::f()" << endl; //non-virtual
    }

    void g() {
        cout << "C::g()" << endl; //virtual
    }

    void h() {
        cout << "C::h()" << endl; //virtual (becomes virtual as it inherits from B)
    }
};

int main() {
    B* q = new C; //upcast

    A *p = q; //upcast

    p->f(); //Since f() is non-virtual A(p is of type A), So compiler statically binds it to A::f() (type of pointer p was A*)

    p->g(); //Since g() is virtual function in A(p is of type A), so late binding (dynamic binding) is done to C::g() (p was pointing to object of C)

    p->h(); ////Since h() is non-virtual in A(p is of type A), So compiler statically binds it to A::h() (type of pointer p was A*)

    ///////

    q->f(); //Since f() is non-virtual in B(q is of type B), So compiler statically binds it to B::f() (type of pointer q was B*)

    q->g(); //Since g() is virtual in B(q is of type B), so late binding (dynamic binding) is done to C::g() (q was pointing to object of C)

    q->h(); ////Since h() is virtual in B(q is of type B), So compiler dynamically binds it to C::h() (q was pointing to object C)


return 0;
}
