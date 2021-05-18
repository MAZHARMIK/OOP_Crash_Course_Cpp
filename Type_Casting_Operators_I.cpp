#include <bits/stdc++.h>
using namespace std;

/*
    Type Casting and Casting Operators in C++ - I
    A cast operator takes an expression of source type (implicit from the expression) and convert it to an expression of target type
    (explicit in the operator) following the semantics of the operator.
    Example :
        i1 : T1   -> T2  (source type : T1 , target type = T2)
        cast<T2>(i)

    Types :
    1) const_cast<type>(expr)
        -Explicitly overrides const and/or volatile in a cast
        -Usually doesn't perform computation or change value
        -i.e. It can take away from a constant expression, or it can add constness to an expression

    2) static_cast<type>(expr)
        -Performs a non-polymorphic cast (Since, it's static, hence non-polymorphic)
        -Usually performs computation to change value - implicit or user defined

    3) reinterpret_cast<type>(expr)
        -Casts between unrelated pointer types or pointer & interger (should not be used much)

    4) dynamic_cast<type>(expr)  (IMPORANT)
        -Perform a run-time case that verifies the validity of the cast
        -Performs pre-defined computation, sets null or throws exception
*/

/////////////////////////////////const_cast Operator/////////////////////////////////////
//Example-1
class A {
    int i_;
public:
    A(int i) : i_(i) {}

    int get() const { return i_; }

    void set(int j) { i_ = j ; }
};

void print(char* str) {
    cout << str << endl;
}

int main() {
    const char *c = "sample text";

//    print(c); //ERROR : Cannot convert const char* to char*

    print(const_cast<char *>(c)); //You removed constness from c

    /*
        The type of this depends upon function declaration. If the member function of a class X is declared const,
        the type of this is const X* , if the member function is declared volatile, the type of this is volatile X*
        , and if the member function is declared const volatile, the type of this is const volatile X* 
    */
    const A a(1); //'this' pointer points to a constant object a

    cout << a.get() << endl; //I am able to call const member function get() only because a is const

//    a.set(5); ERROR : set() is a non const function, so type of this pointer it expects is 'this*'. But a is a const object
                        //So, converting from const A to A& gives error.

    const_cast<A&>(a).set(5); //Resultant is an object which has a 'this' pointer which points to a non-const object

    //Please note that 'this' is a constant pointer
    //const_cast<A>(a).set(5); So, this is not allowed. You cannot remove constness of 'this' pointer

return 0;
}

/////////////////////////Example-2/////////////////////
#include <bits/stdc++.h>
using namespace std;

int main() {
    const int a   = 10; //constant integer

    const int* p1 = &a; //p1 is a pointer to a constant integer

    //*p1 = 5; //Not allowed . Since, p1 points to a constant integer

    int* p2 = const_cast<int*>(p1); //we changed const int* to int*

    *p2 = 5;
    // we expect to have changed the value of a

    //lets's see
    cout << a << endl;   //still we get 10
    cout << *p2 << endl; //we get 5

    //We can't modify a value which is initially declared as const
    //compiler shows undefined behaviour


return 0;
}
