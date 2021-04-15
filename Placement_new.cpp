#include <bits/stdc++.h>
using namespace std;

//Dynamic Memory Management in C++
int main() {
    /*
        Placement new in C++
        -new() returns an address which may not be known to me (from Free memory i.e. Heap)
        -What if I want to allocate address where I want. How to do that ?
        -TO achieve this, we make use of placement new in C++

        Few important notes:
        Allocator       -> De-allocator
        -------------------------
        -malloc()       -> free()
        -operator new   -> operator delete
        -operator new[] -> operator delete[]
        -operator new() -> no delete (placement new)
    */

    unsigned char buf[sizeof(int)*2]; //buffer of size 4*2 = 8 (This is allocated in stack)

    //Now i want to store something in this buff only (i.e. using new operator only)

    //placement new in buffer buf
    int *num1 = new (buf) int(3);               //storing 3 in one half of buf (instead of using new int(3))
    int *num2 = new (buf + sizeof(int)) int(5); //storing 5 in second half of buf

    cout << num1 << ", " << (int *)(buf) << endl;               //0x61fe08, 0x61fe08
    cout << num2 << ", " << (int *)(buf + sizeof(int)) << endl; //0x61fe0c, 0x61fe0c

    cout << *num1 << ", " << *((int *)(buf)) << endl;               //3, 3
    cout << *num2 << ", " << *((int *)(buf + sizeof(int))) << endl; //5, 5

    //Look closely and patiently, it's really easy :-)

    int *p = new int(10); //This is heap allocation
    cout << *p << endl;

    delete(p);
    //No delete for placement new (Since, it was not dynamically allocated)
    //This is the only case when you'll have to explicitly call Destructor

return 0;
}
