#include <bits/stdc++.h>
using namespace std;

/*
    constant data members in class
    - A constant data member cannot be changed even in a non-constant object. Therefore, it must be set at the time of initialization
      of the object
*/

class MyClass {
public:
    const int const_private_var;
    int private_var;
public:
    const int const_public_var;
    int public_var;
    //constructor
    MyClass(int cPri, int pri, int cPub, int pub):
        const_private_var(cPri),private_var(pri), const_public_var(cPub),public_var()pub  {}

    int getConstantPriVar() {
        return const_private_var;
    }

    void setConstantPriVar(int i) {
        const_private_var = i; //Error 1: Assignment to constant data member
    }

    int getPri() {
        return private_var;
    }

    void setPri(int i) {
        private_var = i;
    }
};

int main() {
    MyClass myObj(1, 2, 3, 4);

    cout << myObj.getConstantPriVar() << endl;
    myObj.setConstantPriVar();

    cout << myObj.const_public_var << endl;
    myObj.const_public_var = 3;                 //Error 2: Assignment to constant data member

    cout << myObj.private_var << endl;
    myObj.public_var = 3;

    return 0;

return 0;
}

