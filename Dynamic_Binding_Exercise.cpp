#include <bits/stdc++.h>
using namespace std;

/*
    Binding Exercise
    A <------- B  <------C
*/

class A {
public:
    virtual void f(int x) {
        cout << "A::f(int)" << endl;
    }

    virtual void g(double x) {
        cout << "A::g(double)" << endl;
    }

    int h(A* a_obj) {
        cout << "A::h(A*)" << endl;
    }
};

class B : public A {
public:
    void f(int x) {
        cout << "B::f(int)" << endl;
    }

    virtual int h(B* b_obj) {
        cout << "B::h(B*)" << endl;
    }
};

class C : public B {
public:
    void g(double x) {
        cout << "C::g(double)" << endl;
    }

    int h(B* b_obj) {
        cout << "C::h(B*)" << endl;
    }
};

int main() {
    A a;
    B b;
    C c;

    A *pA;
    B *pB;
    cout << "===============EXERCISE-1==============" << endl;
    pA = &a;
    cout << "pA = &a" << endl;
    pA->f(2);    //A::f
    pA->g(3.2);  //A::g
    pA->h(&a);   //A::h
    pA->h(&b);   //A::h //up cast possible
    cout << "--------------------" << endl;

    cout << "pA = &b" << endl;
    pA = &b;
    pA->f(2);    //B::f
    pA->g(3.2);  //A::g
    pA->h(&a);   //A::h
    pA->h(&b);   //A::h //up cast possible
    cout << "--------------------" << endl;

    cout << "pA = &c" << endl;
    pA = &c;
    pA->f(2);    //B::f  (Since f is virtual in A, so basically we should be invoking C::f  but since C has not overridden f and
                          //has inherited f from B, so B::f is called
    pA->g(3.2);  //A::g
    pA->h(&a);   //A::h
    pA->h(&b);   //A::h  //up cast possible
    cout << "--------------------" << endl;

    cout << "\n===============EXERCISE-2==============" << endl;
    /*
        ERRORRRRR!!! (Down cast from A to B type is not allowed)
        pB = &a;
    */

    cout << "pB = &b" << endl;
    pB = &b;
    pB->f(2);    //B::f
    pB->g(3.2);  //A::g Because B has not overridden A::g
    //pB->h(&a); //A::h ERROR!!! -> Down cast not possible
    pB->h(&b);   //B::h //up cast possible
    cout << "--------------------" << endl;

    cout << "pB = &c" << endl;
    pB = &c;
    pB->f(2);    //B::f  (Since f is virtual in A, so basically we should be invoking C::f  but since C has not overridden f and
                          //has inherited f from B, so B::f is called
    pB->g(3.2);  //C::g
    //pB->h(&a); //A::h  ERROR!!! -> Down cast not possible
    pB->h(&b);   //C::h  //up cast possible
    cout << "--------------------" << endl;

return 0;
}
