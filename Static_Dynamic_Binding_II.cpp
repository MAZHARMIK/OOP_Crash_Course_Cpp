#include <bits/stdc++.h>
using namespace std;

/*
    static and dynamic binding II
    Polymorphism

    static type object  : It is the type declared for the object while writing the code. Compiler sees static type
    Dynamic type object : It is determined by the type of the object to which it currently refers. Compiler does not see dynamic type

    -Static Binding (early Binding) :
     When a function invocation binds to the function definition based on the static type of objects
     This is done at compile-time
     Normal function calls, overloaded function calls, and overloaded operators are example of static binding

    -Dynamic Binding (late Binding) :
     When a function invocation binds to the function definition based on the dynamic type of objects
     This is done at runtime
     Function pointers, Virtual functions are example of late binding
     Only possible for pointer and reference data types and for member functions that are declared as virtual in the base class
     These are called virtual functions
*/

///EXAMPLE-1///
class A {};
class B : public A {};
int main() {
    A a; //a is of type A

    A* p;
    p = new B; //static type of p is A
               //dynamic type of p is B

return 0;
}



///EXAMPLE-2///
//METHOD HIDING (avoid doing this)
class A {
public:
    void f() {
        cout << "A::f()" << endl;
    }
};

class B : public A {
public:
    //To overload, rather than hide the base class function f()
    //is introduced into scope of B with a using declaration
    using A::f;
    void f(int a) { //overloaded
        cout << "B::f(int)" << endl;
    }
};
int main() {
    B b;

    b.f(3); //output : B::f(int)

    b.f(); //ERROR : Since you have inherited and overloaded f() so f() will not work without parameter

    //If you still want this to work, you need to explicitly mention "using A::f" in deriver class (see above)

    //Now
    b.f(); //Works, output : A::f()

return 0;
}


///EXAMPLE-3///
///Static Binding and Dynamic Binding

class B {
public:
    void f() {
        cout << "B::f()" << endl;
    }
};

class D: public B {
public:
    void f(){
        cout << "D::f()" << endl;
    }
};

int main() {
    B b;
    D d;

    B *p;

    p = &b;
    p->f(); //B::f() will be called

    p = &d;
    p->f(); //B::f() will be called

    //Binding is decided by the type of the pointer
    //static binding
return 0;
}


///EXAMPLE-4///
///Static Binding and Dynamic Binding

class B {
public:
    virtual void f() {
        cout << "B::f()" << endl;
    }
};

class D: public B {
public:
    void f(){
        cout << "D::f()" << endl;
    }
};

int main() {
    B b;
    D d;

    B *p;

    p = &b;
    p->f(); //B::f() will be called

    p = &d;
    p->f(); //D::f() will be called

    //Binding is decided by the type of the object
    //dynamic binding
return 0;
}
