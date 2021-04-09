#include <iostream>
using namespace std;

int main() {
    //const int n;  (Error : constant must be initialized)

    const int n = 5;
    //n = 4;        (Error : constant can't be changed)

    int m = 3;
    int *p = &m;
    *p = 7;

    cout << m << endl; //Prints 7 : Since p stores the address of m, it can be used to change value of m

    //p = &n;       (Error : p can be used to change a constant value n, and it's not allowed)

    //NULL is a manifest constant in C/C++ set to 0

    //Draw a mental line on * and read
    const int * p       = &m ; //pointer to a constant integer
    int * const p       = &m ; //constant pointer to an integer
    const int * const p = &m ; //constant pointer to a constant integer

}

