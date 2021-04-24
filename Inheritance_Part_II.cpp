#include <iostream>
using namespace std;

/*
    Inheritance - II
    :Data Members
        -Deriver class inherits all data members of Base class
        -Derived class may add data members of its own

    :Object Layout
        -Derived class layout contains an instance of the Base class
        -Further, Derived class layout will have data members of its own
        -C++ does not guarantee the relative position of the Base class instance and Derived class members
*/

class B { //Base class
    int data1B_;
public:
    int data2B_;
    // ...
};

class D : public B { //Derived Class
    //Inherits B::data1B_;
    //Inherits B::data2B_;
    //(in same order as above)

    int infoD_;
public:
    // ...
};

int main() {
    B b;
    /*
        Object b layout
        _________
        |_data1B_|
        |_data2B_|
    */

    D d;

    /*
        Object d layout (It cannot access data1B_ even though data1B_ is a part of it because it's private)
                        (It can access data2B)
         ________________
        |   _________    |
        |   |_data1B_|   |
        |   |_data2B_|   |
        |   __________   |
        |   |_infoD___|  |
        |________________|
    */
return 0;
}
