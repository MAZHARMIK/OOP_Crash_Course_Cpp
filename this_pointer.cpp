#include <iostream>
#include <cstdlib>
using namespace std;

/*
    Core OOPs concepts in C++
*/

//this pointer ?
//It specifies every object by its own address

//What is the type of "this" pointer ?
//Ans : Type of "this" pointer of class X is : X const* this;
class X{
    public:
        int x = 5;
        void print() {
            cout << this->x << endl;
        }
};

int main() {
    X obj;
    obj.print();
return 0;
}
