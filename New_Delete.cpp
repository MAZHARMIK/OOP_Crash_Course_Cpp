#include <bits/stdc++.h>
using namespace std;

//Dynamic Memory Management in C++
int main() {
    /*
        -malloc() returns void* pointer, so we cast it to our desired type. Example : int* p = (int*)malloc(sizeof(int));
        -memory allocated by malloc() is released by free() call (Available in C\C++)
        -C++ offers new() and delete() for same purpose as well
        - malloc and new are functions
        - free and delete are operatrors
        
        NOTE:
        -malloc only allocates memory but new allocates memory but also calls constructor
        -free only deallocates memory but delete deallocates memory but also calls destructor
    */

    //(1)
    int *p = new int(5); //internally computes how much size required
    cout << *p << endl;  //output : 5
    delete(p);           //released


    //(2)
    p = (int *)malloc(sizeof(int));
    *p = 5;
    cout << *p << endl; //output : 5;
    free(p);            //released


    //(3) - C++ also allows something like shows below
    p = (int *)operator new(sizeof(int));
    *p = 5;
    cout << *p << endl;
    operator delete(p);
    //But please note that operator new and function operator new() are different. We will explore this later


    //(4) Allocating arrays
    int *arr = new int[3];
    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 3;

    for(int i = 0; i<3; i++)
        cout << arr[i] << " "; //outputs : 1 2 3
    cout << endl;

    delete []arr; //Important

return 0;
}
