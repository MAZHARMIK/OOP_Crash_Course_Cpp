#include <iostream>
using namespace std;

/*
    Inheritance - IIV
    -Protected accesss specifier

    Access Specification
        -Derived class cannot access private members of Base class
        -Derived class can access public members of Base class
        -Protected Access Specification
            -A new protected access specification is introduced for Base class.
            -Derived class can access protected members of Base class.
            -No other class or global function can access protected members of Base class
            -A protected member in Base class is like public for Derived class
            -A protected member in Base class is like private in other classes or global functions.


    Three important examples below:
*/

///************EXAMPLE-1***************///
class B { //Base class
private:
    //Inaccessible to child
    //Inaccessible to others
    int data_ = 1;
public:
    // ...
    void print() {
        cout << "B Object: " << data_ << endl;
    }
};

class D : public B { //Derived Class
private:
    int info_ = 2;
public:
    // ...
    void print() {
        cout << "D Object: " << data_ << endl; //Inaccessible (Error!!!!)
        //In order to fix this, make change access specifier of data_ from private to protected
        cout << info_ << endl;
    }
};

int main() {
    B b;
    D d;

    //b.data_ = 5; //Inaccessible to all (Error!!! even if access specifer is protected (as it works for derived class only)

    b.print();
    d.print();

return 0;
}

///************EXAMPLE-2***************///
class B { //Base class
protected:
    int data_ = 1;
public:
    friend ostream& operator<<(ostream& os, const B& b) {
        os << "B Object : " << b.data_ << endl;
        return os;
    }
};

class D : public B { //Derived Class
private:
    int info_ = 2;
public:
//    friend ostream& operator<<(ostream& os, const D& d) {
//        os << "B Object : " << d.data_ << endl;
//        os << "D Object : " << d.info_ << endl; //accessible because "protected"
//        return os;
//    }
};

int main() {
    B b;
    D d;

    cout << b;
    cout << d; //calls base's operator function even if base's function accepts B's object (Implicit casting) (Note that Object d has class B's members as well in object layout)
    /*
        Output:
            B Object : 1
            B Object : 1
    */

return 0;
}

///************EXAMPLE-3***************///
class B { //Base class
protected:
    int data_ = 1;
public:
    friend ostream& operator<<(ostream& os, const B& b) {
        os << "B Object : " << b.data_ << endl;
        return os;
    }
};

class D : public B { //Derived Class
private:
    int info_ = 2;
public:
    friend ostream& operator<<(ostream& os, const D& d) {
        os << "B Object : " << d.data_ << endl;
        os << "D Object : " << d.info_ << endl; //accessible because "protected"
        return os;
    }
};

int main() {
    B b;
    D d;

    cout << b;
    cout << d;
    /*
        Output:
            B Object : 1
            B Object : 1
            D Object : 2
    */

return 0;
}
