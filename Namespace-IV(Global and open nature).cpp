#include <iostream>
using namespace std;

/*
    Namespace in C++ - IV
    Global namespace : It has no name and members can be accessed using scope resolution operator (::)
    Items in global namespace can be accessed using  ::

    Namespaces are open in the sense that new declarations can be added.

    Few more important points. Namespace vs class
    -Every namespace is not a class                                      : Every class defines a namespace
    -A namespace can be reopened and more declarations can be added      : A class cannot be reopened
    -No instance of a namespace can be created                           : A class has multiple instances
    -using-declarations can be used to short-cut namespace qualification : No using-like declaration for a class
    -A namespace may be unnamed                                          : An unnamed class is not allowed

*/

int data  = 0;

namespace name1 {
    int data = 1;
}

namespace open {
    int x = 30;
}

namespace open {
    int y = 30;
}

int main() {
    /*Global namespace*/
    using name1::data;

    cout << data << endl;          //Prints 1 :-(   because name::data hides global data
    cout << name1::data << endl;   //Prints 1 as expected

    cout << ::data << endl;        //Prints 0 (my global friend is alive. yayyyy!!!!)
    /*Global namespace*/


    /*Open namespace*/
    cout << open::x << ", " << open::y << endl;  //Noiceeeee!!!!
    /*Open namespace*/



return 0;
}

