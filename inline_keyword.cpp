#include <bits/stdc++.h>
using namespace std;

//Why inline ?
/*
Ans : The CPU when executes the function code, stores the function return value in a
      predefined memory location/register and returns control to the calling function.
      This can become overhead if the execution time of function is less than the switching
      time from the caller function to called function (callee). For functions that are large
      and/or perform complex tasks, the overhead of the function call is usually insignificant
      compared to the amount of time the function takes to run. However, for small, commonly-used
      functions, the time needed to make the function call is often a lot more than the time needed
      to actually execute the function’s code. This overhead occurs for small functions because
      execution time of small function is less than the switching time.
*/

class Foo {
    public:
      void method();  // Best practice: Don't put the inline keyword here
};

//assume it's a header file
inline void Foo::method()  {// Best practice: Put the inline keyword here
    cout << "Hello I am inline\n";
}

/*
    The reason you (almost always) put the definition (the {...} part)
    of an inline function in a header file is to avoid “unresolved external”
    errors from the linker. That error will occur if you put the inline function’s
    definition in a .cpp file and if that function is called from some other .cpp file.
*/


inline SQUARE(int x) {
    return x*x;
}

int main() {
    /*
        When the inline function is called whole code of the inline function
        gets inserted or substituted at the point of inline function call.
        This substitution is done by C++ compiler at compile time.
    */
    int a = 3;
    cout << SQUARE(a) << endl; //compiler inlined the body of SQUARE here only in the code

    Foo foo;
    foo.method();
}
