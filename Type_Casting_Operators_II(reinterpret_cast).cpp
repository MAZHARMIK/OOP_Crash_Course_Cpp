#include<iostream>
using namespace std;

/*
 reinterpret cast : Converts a pointer type to any pointer type. Even unrelated class as well.
                    It actually does a binary copy
                    Rarely used
                    It exists because there are certain C-casts which can be done using this casting only
                    Example : pointer -> int

                    Recommendation : Don't use it :-)

*/

class A {};
class B {};

int main() {
    int i = 2;
    double d = 3.6;
    double *pd = &d;

    i = pd; //implicit -- Error
    i = reinterpret_cast<int>(pd); //reinterpret_cast -- okay
    i = (int)pd;    //C-style cast - okay

    A *pA;
    B *pB;

    pA = pB; //implicit -- Error
    pA = reinterpret_cast<A*>(pB); //reinterpret_cast -- okay
    pA = (A*)pB; //C-style -- okay

    return 0;
}
