#include <iostream>
using namespace std;

/*
    Dynamic Binding Part I
    Type Casting
    -(Implicit) Casting between unrelated classes is not possible
    -upcasting is allowed in inheritance
    -downcasting is not allowed in inheritance

*/

class A {
public:
    int dataA_;
};

class B : public A {
public:
    int dataB_;
};

int main() {
    A a;
    B b;

    A *pa    = NULL;
    B *pb    = NULL;
    void *pv = NULL;

    pa = pb; //pb casted to pa (UPCAST) allowed

    //pb = pa; //ERROR : downcast not allowed

    pv = pa; //Allowed : BUT, pa is converted to void* (So, pa loses the type)
    pv = pb; //Allowed : BUT, pb is converted to void* (So, pb loses the type)

   // pa = pv; //ERROR : Cannot convert void* to A*
  //  pb = pv; //ERROR : Cannot convert void* to B*


    a.dataA_ = 2;
    b.dataB_ = 3;
    b.dataA_ = 5;

    pa = &a;
    pb = &b;

    cout << pa->dataA_ << endl;                        //2
    cout << pb->dataA_ << " " << pb->dataB_ << endl;   //3 5

    pa = &b; //UP casting A* type to B* type. Allowed (Because Class B has object of A as well in its orientation)

    cout << pa->dataA_ << endl; //3

    //cout << pa->dataB_ << endl; //ERROR : class A has no member named dataB_
    //i.e. pa is a pointer of A* type and class A has no member called dataB_


return 0;
}
