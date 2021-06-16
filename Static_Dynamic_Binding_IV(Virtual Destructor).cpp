#include <bits/stdc++.h>
using namespace std;

/*
    static and dynamic binding IV
    These topics are important for Design Patterns concept
    Virtual Destructor ("DESTRUCTOR MUST BE DECLARED VIRTUAL IN THE BASE CLASS")

    Why destructor must be virtual in a class hierarchy ?
    -clean up consistency will not work. Like shown in the example below, destructor of derived class was not called
    because of which ptr_ is not freed. It only calls the Base class part of Derived object (i.e. slices)
    i.e. If the destructor is not virtual in polymorphic hierarchy, it leads to slicing.
    "DESTRUCTOR MUST BE DECLARED VIRTUAL IN THE BASE CLASS"


    By Rule of Polymorphism hierarchy:
    If destructor of Base is virtual, by inheritance the destructor of Derived is also virtual

    So So So, very important : If you have a hierarchy, then it doesn't make it non-polymorphic.
*/

class B {
    int data_;
public:
    B(int d) : data_(d) {
        cout << "B()" << endl;
    }

    ~B() {
        cout << "~B()" << endl;
    }

    virtual void Print() {
        cout << data_;
    }
};

class D : public B{
    int* ptr_;
public:
    D(int d1, int d2) : B(d1), ptr_(new int(d2)) {
        cout << "D()" << endl;
    }

    ~D() {
        cout << "~D()" << endl;
    }

    void Print() {
        B::Print(); //cout << data_; // ERROR! : data_ is private inside B
        cout << " " << *ptr_;
    }
};

int main() {
    B *p = new B(2);           //Output : B()
    B *q = new D(3, 5);        //Output : B(), D()

    p->Print(); cout << endl;  //Output : 2
    q->Print(); cout << endl;  //Output : 3 5

    //Since, new was used, you need to explicitly use delete

    delete p;                  //~B()

    delete q;                  //~B() Whhhhhhaaaat ????? (Destructor of d(type D) not called. Dayummmm

    //delete q calls the destrutor.
    //And during compile time, destructor in B is non-vritual. So, compiler only sees the type of q i.e. B*
    //And hence, ~B() got called.
    //So, we need to make virtual ~B() and it will fix things.

return 0;
}

////////////////////////////FIXED////////////////////////////////
class B {
    int data_;
public:
    B(int d) : data_(d) {
        cout << "B()" << endl;
    }

    virtual ~B() { //Destructor made virtual
        cout << "~B()" << endl;
    }

    virtual void Print() {
        cout << data_;
    }
};

class D : public B{
    int* ptr_;
public:
    D(int d1, int d2) : B(d1), ptr_(new int(d2)) {
        cout << "D()" << endl;
    }

    ~D() { //
        cout << "~D()" << endl;
    }

    void Print() {
        B::Print(); //cout << data_; // ERROR! : data_ is private inside B
        cout << " " << *ptr_;
    }
};

int main() {
    B *p = new B(2);           //Output : B()
    B *q = new D(3, 5);        //Output : B(), D()

    p->Print(); cout << endl;  //Output : 2
    q->Print(); cout << endl;  //Output : 3 5

    //Since, new was used, you need to explicitly use delete

    delete p;                  //~B()

    delete q;                  //~D() ~B() YESSSS, Fixed (NOTE : new D(3, 5) had a B object as well which is why you see ~B() as well


return 0;
}
