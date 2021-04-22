#include <iostream>
using namespace std;

/*
    Namespace in C++ - I
    -It's a scope for the identifiers(functions, variables etc)
    -It's use to organise the code into logical groups
    -Prevent name collisions that can occur especially when your code base includes multiple libraries.
*/

namespace MyNameSpace {
    int myData;
    void myFunction() {
        cout << "MyNamSpace myFunction" << endl;
    }
    class MyClass {
        int data;
    public:
        explicit MyClass(int d) : data(d) {}
        void display() {
            cout << "MyClass data = " << data << endl;
        }
    };
}

int main() {
    MyNameSpace::myData = 10;
    cout << "MyNameSpace::myData = " << MyNameSpace::myData << endl;

    myFunction(); //Error!!!!!!!!!!
    MyNameSpace::myFunction();

    MyNameSpace::MyClass obj(25);
    obj.display();

return 0;
}

