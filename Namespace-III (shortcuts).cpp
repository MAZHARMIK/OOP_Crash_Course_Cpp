#include <iostream>
using namespace std;

/*
    Namespace in C++ - III
    shortcuts for ease of use

*/

namespace name1 {
    int a = 1;
    int b = 2;
}

namespace name2 {
    int c = 3;
    int d = 4;
}

using namespace name1;
using name2::c;

int main() {
    cout << a << endl;          //Output : 1
    cout << name1::b << endl;   //Output : 2

    cout << c << endl;          //Output : 3
    cout << name2::d << endl;   //Output : 4

//    cout << d << endl;  Error!!! Because we are using name2::c only but not "using namespace name2";

return 0;
}

