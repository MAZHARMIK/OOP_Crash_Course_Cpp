#include <bits/stdc++.h>
using namespace std;

/*
    Template - II
    "typename" keyword in templates
    template<class T>
    C++ also allows 
    template<typename T>
    
    But there is just one difference 
    See example below
*/

template<class T>
f (T x) {
    T::name * p; //Multilication
    //Either T is some class which has a variable named "name", then this expression turns out to be a multiplication(*)

    //Or, if T is a typedef in some class T , then it becomes a declaration *p
}

/*
    So, C++ provides typename to tell compiler that it's a type, but not multiplication
    SO, typename tells compiler that an expression is a type expression
*/

template<class T>
f(T x) {
    typename T::name *p //Type
}

int main() {
    int arr[] = {1, 2, 3, 7, 6};

    cout << MAX<int,5>(arr) << endl;
}
