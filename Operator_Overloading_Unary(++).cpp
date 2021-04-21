#include <bits/stdc++.h>
using namespace std;

/*
    Operator overloading of Unary operator : pre increment and post increment operator
    ++a
    The pre-operator should first perform the operation (increment/decrement/other) and then return the same object because
    the change is reflected in the current object. So, return type is MyType&  and we return *this

    a++
    The post-operator should first store the current object state(temporary) and perform the operation (increment/decrement/other) and then return the same object because
    the temporary state because the change is reflected post the operation. So, return type is MyType.

    Note: post-operator should have (int) parameter to help compiler differentiate between pre and post operator.
*/

//Example - 1  (Add two MyType class objects
class MyType {
    int data;
public:
    MyType(int d): data(d) {}
    //pre-increment
    MyType& operator++() {
        ++data;
        return *this;
    }

    //post-increment
    MyType operator++(int) { //adding int for compiler to differentiate between post and pre
        MyType temp(data); //temporary object
        ++data;
        return temp; //return by value (not by reference) because it's a copy
    }

    void display() {
        cout << data << endl;
    }
};


int main() {
    MyType obj1(1);
    obj1.display();

    MyType obj2 = obj1++;
    obj2.display();
    obj1.display();

    obj2 = ++obj1;
    obj2.display();
    obj1.display();

return 0;
}

