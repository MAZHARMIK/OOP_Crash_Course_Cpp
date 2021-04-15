#include <iostream>
#include <cmath>
using namespace std;

/*
    Why do we need an initialization list in constructors in C++ ?
    Ans:
         (1) The life time of an object start exactly at the starting point of the body of constructor.
         So, the moment the control reaches this point, the object construction is considered complete.
         If we put the value inside the body, then at the time the life time of object starts, the data members
         will have inconsistent value.
         It will not matter in examples as shown below, but there are examples where it does really matter whether you have
         properly initialized members or not when the object life time starts.

         (2) There can be n data members that can be initialized. If we initialize them inside constructor body,
             compiler can initialize them in n! ways (there can be a case when initialization of one member depends on some other
             member. But when we do initialization using initializer list, compiler initializes them in one unique way
             which depend on which member comes first in definition of class.
*/

class Stack {
private:
    char *data_; //it will be initialized first in initialization list
    int top_;    //then this will be initialized
public:
    Stack(): data_(new char[10]), top_(-1) {}

    ~Stack();

};

Stack::~Stack() {
    cout << "Destructor called\n";
    delete data_;
}

//Application
int main() {
    Stack s;


return 0;
}
