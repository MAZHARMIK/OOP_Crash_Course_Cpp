#include <iostream>
using namespace std;

/*
    Inheritance - IIV
    Constructor-Destructor
        -Derived class inherits the Constructors and Destructor of Base class (but in different semantics)
        -Derived class cannot override or overload a Constructor or the Destructor of Base class.
    Construction-Deconstruction
        -A constructor of the Derived class must "first" call the constructor of Base class to construct the Base class instance of the Derived class
        -A Deconstructor of the Derived class must call the destructor of Base class to destruct the Base class instance of the Derived class

*/

class B { //Base class
protected:
    int data_;
public:
    B(int d = 0) : data_(d) {
        cout << "B::B(int): " << data_ << endl;
    }
    ~B() {
        cout << "B::~B(): " << data_ << endl;
    }
};

class D : public B { //Derived Class
    int info_;
public:
    D(int d, int i) : B(d), info_(i) { //Explicit construction of Base (B(d))
        cout << "D::D(int, int): " << data_ << ", " << info_ << endl;
    }
    explicit D(int i) : info_(i) { //Implicit construction of Base by compiler (Possible only because Base has default constructor which is similar to no parameter constructor
                          //else compiler error
        cout << "D::D(int): " << data_ <<  ", " << info_ << endl;
    }
    ~D() {
        cout << "D::~D(): " << data_ << ", " << info_ << endl;
    }
};

int main() {
    B b(0);
    D d1(1, 2);
    D d2(3);
/*
Output:
B::B(int): 0                //Obj. b
B::B(int): 1                //Obj. d1
D::D(int, int): 1, 2        //Obj. d1
B::B(int): 0                //Obj. d2
D::D(int): 0, 3             //Obj. d2
D::~D(): 0, 3               //Obj. d2
B::~B(): 0                  //Obj. d2
D::~D(): 1, 2               //Obj. d1
B::~B(): 1                  //Obj. d1
B::~B(): 0                  //Obj. b
*/

//Note :
//1) First construct base class object and then derived class object
//2) First destruct derived class object and then base class object

return 0;
}
