#include <bits/stdc++.h>
using namespace std;

/*
    When to use Mutable Data Members ?
    - Typically, when a class represents a constant concept, and
    - It computes a value first time and caches the result for future use.

    In the example below, MathObject is logically constant; but we use mutable members for computation
*/

class MathObject {
    mutable bool piCached_;
    mutable double pi_;
public:
    MathObject() : piCached_(false) {}
    double pi() const { //because it will be called by a const object, so this member function must be const to be able to be invoked
        if(!piCached_) {
            pi_ = 4; //mutable
            for(long step = 3; step < 100000000; step += 4) {
                pi_ += ((-4.0/(double)step) + (4.0/((double)step+2)));
            }
            piCached_ = true;
        }
        return pi_;
    }
};

int main() {
    //In the example below, MathObject is logically constant; but we use mutable members for computation above in class def.
    const MathObject mo;
    cout << mo.pi() << endl; //Access PI
    return 0;
}

