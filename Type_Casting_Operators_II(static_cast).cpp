#include<iostream>
using namespace std;

/*
    static cast : As the name signifies, it deals with casting which can be decided at compile time.
                  It performs all conversions allowed implicitly.
                  void* -> any pointer type
                  I also up-casts and down-casts (at risk) as well

*/

int main() {
    //Built-in types
    int i = 2;
    double d = 3.7;
    double *pd = &d;

    i = d;                      //implicit     -- warning
    i = static_cast<int>(d);    //static_cast  -- okay
    i = (int)d;                 //C-style      -- okay

    d = i;                      //implicit      -- okay
    d = static_cast<double>(i); //implicit      -- okay
    d = (double)i;              //implicit      -- okay

    //i = pd;                     //implicit    -- Error
    //i = static_cast<int>(pd);   //static_cast -- Error
    //i = (int)pd;                //C-style     -- okay (Risky) (Also error with latest C++)

    return 0;
}


class A { };
class B : public A { };

int main() {
    A a;
    B b;

    //UPCAST
    A *p = &b;                 //implicit    -- okay
    p = static_cast<A*>(&b);   //static_cast -- okay
    p = (A*)&b;                //C-style     -- okay

    //DOWNCAST
    //B *q = &a;               //implicit    -- Error
    q = static_cast<B*>(&a);   //static_cast -- okay (Risky)
    q = (B*)&a;                //C-style     -- okay

    return 0;
}

//conversion operator
class B;
class A {
    int i_;
public:
    A(int i = 0) : i_(i) {}
    //conversion operator : Means, you want to convert A to an int type
    operator int() {
        //just like operator +()
        //No return type because it's obvious
        return i_;
    }
};

class B {
public:
    //conversion operator : Means, you want to convert B to an A type
    operator A() {
        return A();
    }
};

int main() {
    A a;
    B b;
    int i = 5;

    //B --> A (Note, A and B are unrelated classes)
    a = b;                 //B::operator A()
    a = static_cast<A>(b); //B::operator A()
    a = (A)b;              //B::operator A()

    //A --> int (strange haan. Why would anyone do this :-|)
    i = a;                  //A::operator int()
    i = static_cast<int>(a);//A::operator int()
    i = (int)a;             //A::operator int()
}
