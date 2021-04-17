#include <bits/stdc++.h>
using namespace std;

/*
    static members
    -static data member :
       --Associated with class not with object
       --shared by all objects of a class
       --Needs to be defined outside the class scope (in addition to the declaration within the class scope) to avoid linker error.
       --Must be initialized in a source file
       --is constructed before main() starts and destructed after main() ends
       --can be private/public type
       --can be accessed (a) with the class-name followed by the scope resolution operator(::)
                         (b) as a member of any object of the class
       -- virtually eliminates any need for global variables in OOPs environment

*/

class MyClass {
    int x;        //non static
    static int y; //static : Belongs to class
public:
    static int z;
    void get() {
        x = 15;
        y = 15;
    }

    void print() {
        x += 10;
        y += 10;
        cout << "x = " << x << endl;
        cout << "y = " << y << endl;
    }
};

int MyClass::y = 0; //Defined static data member (must be defined in global scope)
int MyClass::z = 0;
//static data members are initialized during program setup

int main() {
    MyClass obj1;
    MyClass obj2;

    cout << MyClass::z << endl;

    obj1.get();
    obj2.get();

    obj1.print();
    obj2.print();

    /*
        Output:
        x = 25
        y = 25
        x = 25
        y = 35
    */

    return 0;
}

