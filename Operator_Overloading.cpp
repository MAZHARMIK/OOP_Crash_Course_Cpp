#include <bits/stdc++.h>
using namespace std;

/*
    Write a C++ program to show concatenation of strings using operator overloading

    Operator overloading rules :
    -For unary prefix  operators, use : MyType& operator++(MyType& obj)       example : ++a
    -For unary postfix operators, use : MyType& operator++(MyType& obj, int)  example : a++ (You don't pass any int, it's just for compiler)
    -The overload operator-> must either return a raw pointer or return an object (by reference or by value), for which
     operator-> is in turn overloaded. (Later will be explained)
*/

class String{
    public:
        string str;
        String operator + (const String& Obj0) {
            String obj;
            obj.str = this->str + Obj0.str;
            return obj;
        }
};


int main() {
    /*
        Operator Overloading
        a+b    -> operator+(a,b)
        a=b    -> operator=(a,b)
        c=a+b  -> operator=(a, operator+(a,b))
        - Operator function can have zero or one arguments
        - Atleast one of the arguments must e of user defined type
    */
    string fName    = "Tony ";
    string lName    = "Stark";

    string fullName = fName + lName;
    cout << fullName << endl;

    //Let's do this using operator overloading
    String fNameObj;
    fNameObj.str = "Tony ";

    String lNameObj;
    lNameObj.str = "Stark";

    String fullNameObj = (fNameObj+lNameObj); //Adding two objects of class String

    cout << fullNameObj.str << endl;

return 0;
}
