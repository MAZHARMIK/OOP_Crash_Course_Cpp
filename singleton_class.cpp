#include <bits/stdc++.h>
using namespace std;

/*
    singleton class in C++
    -It's a kind of design pattern which says that a class is called single if it can have only one instance at a time.
    -Many classes are singleton:
        --President of India
        --PM of India
        --Director of IIEST, Shibpur
        ....
    --How to implement a singleton class ? How to restrict that user can only create one instance ?
    Ans : It's easy to design a class which doesn't have an instance. You just have to make the constructor private.
          But, only one object ?  How to do this ?
          It can be done easily using static data members and static member functions.

          See example below
*/


class Printer {
private:
    Printer() {
        cout << "Printer constructed" << endl;//Private Printer cannot be constructed!!
    }

    static Printer* myPrinter_;//Instance of the singleton Printer (Pointer to object)
    //static means this belongs to class but not to any object
public:
    ~Printer() {
        cout << "Destructor called" << endl;
    }
    static const Printer& printer() { //Why reference ? We don't want a copy
        if(!myPrinter_) {
            myPrinter_ = new Printer(); //Since printer() is a member function, hence it can access private constructor
        }
        return *myPrinter_;
    }

    void print(int np) const { //Why const ? Because my object(myPrinter_) is returned as const Printer& (const reference)
        cout << "printing " << np << " pages" <<  endl;
    }
};

Printer* Printer::myPrinter_ = NULL;

int main() {
    Printer::printer().print(10);
    Printer::printer().print(20);

    Printer::printer().~Printer();


return 0;
}

