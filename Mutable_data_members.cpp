#include <bits/stdc++.h>
using namespace std;

/*
    Mutable Data Members
    Since, constant data members cannot be changed even in non const object,
    a mutable data member, can be changed in a const object.
    It has been introduced to particularly model constant concept. Example : Class which returns value of pi

    Why mutable exists ?
    Ans : If I declare an object to be const, then nothing can be changed in it. It means whatever bit-pattern that particular object
    has got during inisialization, it will remain same. Sometimes it's difficult to work with it.

    Note:
    -mutable is applicable only on data members but not on any simple variable
    -reference data members, static data members and const data members can not be declared as mutable.
    -If a data member is declared mutable, then it's legal to assign a value to it from a const member function
*/

class MyClass {
    int mem_;
    mutable int mutableMem_;
public:
    MyClass(int m , int mm) : mem_(m), mutableMem_(mm) {}
    int getMem() const {
        return mem_;
    }
    void setMem(int i) {
        mem_ = i;
    }
    int getMutableMem() const {
        return mutableMem_;
    }
    void setMutableMem(int i) const { //okay to change mutable
        mutableMem_ = i;
    }
};

int main() {
    const MyClass myConstObj(1, 2);

    cout << myConstObj.getMem() << endl;
    myConstObj.setMem(3); //Error to invoke

    cout << myConstObj.getMutableMem() << endl;
    myConstObj.setMutableMem(4);

return 0;
}

