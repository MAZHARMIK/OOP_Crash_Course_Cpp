#include <iostream>
using namespace std;

/*
    Order Of Initialization :
    Order of initialization does not depend on the order in the initialization list. It depends on the order of data members in the
    definition.
*/

int init_a(int x) {
    cout << "Initializing a" << endl;
    return x;
}

int init_b(int y) {
    cout << "Initializing b" << endl;
    return y;
}

class X {
private:
    int _a; //it will be initialized first in initialization list
    int _b; //then this will be initialized
public:
    X(int x, int y): _b(init_b(y)), _a(init_a(x)) { //even if you write _b first here in the initialization list
        cout << "Constructor. Hi !" << endl;
    }

    ~X() {
        cout << "Destructor. Bye Bye !" << endl;
    }

};

//Application
int main() {
    X a(2, 3);
    /*
        Output
        Initializing a
        Initializing b
        Constructor. Hi !
        Destructor. Bye Bye !
    */

return 0;
}
