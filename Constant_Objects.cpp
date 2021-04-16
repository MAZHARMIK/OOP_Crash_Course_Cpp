#include <bits/stdc++.h>
using namespace std;

/*
    const-ness in UDT (user defined data types)
    - If an object is a constant, non of its data members can be changed
    - A constant object cannot invoke a normal methods of the class because it can make changes in the data members
    - Constant objects can invoke (select) methods if they are constant member functions
    But, no data members can be changed inside constant member functions
*/

class MyClass {
public:
    int private_var;
public:
    int public_var;
    //constructor
    MyClass(int mPri, int mPub): private_var(mPri),public_var(mPub) {}

    int getVar() {
        return private_var;
    }

    void setVar(int i) {
        private_var = i;
    }

    void print() {
        cout << private_var << ", " << public_var << endl;
    }

    void constant_print() const {
        cout << private_var << ", " << public_var << endl;
    }

    void constant_setVar(int i) const {
        //private_var = i; //Error!!!!
    }
};

int main() {
    const MyClass myConstObj(5, 6); //constant object

    //cout << myConstObj.getVar() << endl; //Error-1 passing 'const MyClass' as 'this' argument discards qualifiers
    //myConstObj.setVar(7);                //Error-1 passing 'const MyClass' as 'this' argument discards qualifiers
    //myConstObj.print();                  //Error-1 passing 'const MyClass' as 'this' argument discards qualifiers

    //myConstObj.public_var = 3;           //assignment of member 'MyClass::public_var' in read-only object

    myConstObj.constant_print();           //Works fine because it's a constant member function

return 0;
}

