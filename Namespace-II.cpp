#include <iostream>
#include <cstdlib>

/*
    Namespace in C++ - II
    If you redefine a function which is already in cstdlib, then you can no longer use it that original function inside cstdlib
    or in any library.
    How to tackle this ?
    Namespace can help you in this.
*/

/*Commented for showing both usecase
int abs(int n) {
    if(n < -128 || n > 128)
        return 0;
    if(n < 0)
        return -n;
    return n;
}
*/

namespace myNs {
    int abs(int n) {
        if(n < -128 || n > 128)
            return 0;
        if(n < 0)
            return -n;
        return n;
    }
}

int main() {
    std::cout << abs(-203) << " " << abs(-6) << " " << abs(77) << " " << abs(179) << std::endl; //(commented above)
    /*
        Output : 0 6 77 0
    */

    //Once you add your abs, you cannot use the abs() from library! It is hidden and gone ! Dayummmmmmmm
    //So, I will wrap my abs() inside a namespace and then use it.

    std::cout << abs(-203) << " " << abs(-6) << " " << abs(77) << " " << abs(179) << std::endl; //(commented above)

    /*
        Output : 203 6 77 179
    */

return 0;
}
