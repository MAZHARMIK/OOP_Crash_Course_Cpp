#include <iostream>
#include <cmath>
using namespace std;

/*
    Deconstructor in C++
    Deconstructor gives us a completely well defined structured way of managing the life time of every object in a clean manner.
    -It is implicitly called when a class object goes out of scope or by operator delete (later we will know this).
    -No parameter is allowed.
    -Can't be overloaded
    -Unique for the class (Since no parameter allowed -> Hence no overloading allowed -> Hence, Unique)
    -If user provided no destructor, default destructor is called by compiler (which has nothing in its body)
    -NOTE: Destructors are called in reverse order of construction of objects (They are LIFO in nature)
*/

class Stack {
private:
    char *data_;
    int top_;
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
