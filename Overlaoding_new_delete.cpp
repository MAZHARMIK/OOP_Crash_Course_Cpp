#include <iostream>
#include <cstdlib>
using namespace std;

/*
    Overloading operator new and operator delete in C++
    Similarly you can overload new[] and delete[] in C++
*/

/*
    -The first parameter of overloaded operator new MUST be size_t. Compiler take help from this to determine the size
*/
void* operator new(size_t n) {
    cout << "overloaded new" << endl;
    void *ptr;
    ptr = malloc(n);
    return ptr;
}

/*
    -The first parameter of overloaded operator delete MUST be void*.
    -return type must be void
*/
void operator delete(void* p) {
    cout << "overloaded delete" << endl;
    free(p); //since it was internally assigned using malloc
}

//Dynamic Memory Management in C++
int main() {
    int *p = new int; //lets overload this
    *p = 5;
    cout << *p << endl;
    delete(p); //lets overload this as well

return 0;
}
