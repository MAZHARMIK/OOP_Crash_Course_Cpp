#include<iostream>
using namespace std;

/*
 dynamic_cast : -It's unique in the sense that it works during runtime.
                -Can only be used with pointers and references to classes.
                -It comes to picture when you have a polymorphic hirarchy (virtual function)
                -Valid down cast possible with this. If down cast is not valid,
                 dynamic cast will set the pointer to NULL.
*/

class A {
public:
    virtual ~A() {}
};

class B : public A {
};

class C {
public:
    virtual ~C() {}
};

int main() {
    A a;
    B b;
    C c;

    A* pA;
    B* pB;
    C* pC;
    void *pV;

    pB = &b; //Fine
    pA = dynamic_cast<A*>(pB);

    cout << pB << " casts to " << pA << " : Up-cast: Valid." << endl;

    pA = &b;
    pB = dynamic_cast<B*>(pA); //Because it's valid as pA was pointing to 'b' object (dynamic_cast is intelligent to understand this)
    cout << pA << " casts to " << pB << " : Down-cast: Valid." << endl;

    pA = &a;
    pB = dynamic_cast<B*>(pA); //Not valid : Because pA was pointing to 'a' object (dynamic_cast is intelligent to understand this)
    cout << pA << " casts to " << pB << " : Down-cast: Valid." << endl; //returns NULL for pB

    pA = (A*)&c;
    pC = dynamic_cast<C*>(pA); //Not valid : dynamic_cast will throw NULL for Unrelated class casting
    cout << pA << " casts to " << pC << " : unrelated-cast: Invalid" << endl; //returns NULL for pC

    pA = 0;
    pC = dynamic_cast<C*>(pA); //valid : dynamic_cast valid for NULL
    cout << pA << " casts to " << pC << " : unrelated-cast: Valid for NULL" << endl; //returns NULL for pC

    pA = &a;
    pV = dynamic_cast<void*>(pA); //pointer type to void is allowed
    cout << pA << " casts to " << pC << " : Cast to void: Valid." << endl; //cast to void valid

    //void type to pointer type not allowed
    //pA = dynamic_cast<A*>(pV);  //Error

    /*
        Question : How is dynamic_cast able to identify the cases mentioned above ?
        Ans      : It's because of the restriction in the argument that we provide to dynamic_cast<conversion_type>(argument)
                    i.e. argument must be a pointer to a polymorphic hierarchy
                    Plymorphic hierarchy -> has a virtual function -> has a virtual table
                    It looks for virtual function table and from that table it knows the type
                    That's why , pA = dynamic_cast<A*>(pV); is not allowed as pV is not polymorphic
                    Note that if we do dynami_cast on reference, it will throw error (bad_cast)
                    
                    A &aObj = a;
                    B &bObj = dynamic_cast<B&>(aObj); //ERROR
                    

    */

    //typeid operator : Used to know the type of the expression. Works only on polymorphic hierarchy
    cout << typeid(a).name() << endl; //class A (output is compiler depenedent)
    cout << typeid(&a).name() << endl; //class A* (output is compiler depenedent)

    //These are examples of RTTI  : Runtime Type Information
    return 0;
}
