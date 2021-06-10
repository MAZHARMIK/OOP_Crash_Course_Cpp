#include <bits/stdc++.h>
using namespace std;

/*
    Template - I
    -It is used to make functions/classes generic. Example : stack<int>, stack<string> is implemented using templates
    -We can also now make "type" as a parameter using template

    Template specialization : Look for example below

*/


//Normal template
template<class T>
T MAX(T x, T y) {
    return x > y ? x : y;
}

//Template specialization : Just replace the type with T
template<>
char* MAX<char*>(char * x, char * y) { //return type is char* , Funtion name is MAX<char*>
    return strcmp(x, y) > 0 ? x : y;
}


int main() {
    int a = 1, b = 2;

    double c = 1.2, d = 2.5;

    cout << MAX<int>(a, b) << endl;     //MAX<int> is called as "instantiated MAX" with parameter int

    cout << MAX<double>(c, d) << endl;  //MAX<double> is called as "instantiated MAX" with parameter double

    char *s1 = new char[6];
    char *s2 = new char[6];
    strcpy(s1, "abc");
    strcpy(s2, "def");

    cout << MAX<char*>(s1, s2) << endl;
    //But need to specify the type (char*) is bothersome

    //so, we can also write like this
    cout << MAX(1, 4) << endl; //Because compiler detects the type from the paramater

    //cout << MAX(1, 7.6) << endl; //ERROR : deduced conflicting types for parameter 'T' ('int' and 'double')


return 0;
}

//////Important Example - (Templates with user defined class)///////
class Complex {
private:
    double real, imag;

public : 
    Complex(double re = 0.0, double im = 0.0) : real(re), imag(im) {
        cout << "Complex::Complex()" << endl;
    }

    double norm() const {
        return sqrt(real*real + imag*imag);
    }

    friend bool operator>(const Complex& c1, const Complex& c2) {
        return c1.norm() > c2.norm();
    }

    friend ostream& operator<<(ostream& os, const Complex& c1) {
        os << "( " << c1.real << ", " << c1.imag << " )" << endl;
        return os; //for chaining
    }
};

template<class T>
T MAX(T x, T y) {
    return x > y ? x : y;
}

/*
    if we call MAX(c1, c2), template function comes into picture and compiler generates
    Complex(Complex x, Complex y) {
        return x > y ? x : y;
    }
    Which n turn requires operator overloading of > for comparing user defined data type
*/

int main() {
    Complex c1(1, 2);
    Complex c2(3.1, 1);

    cout << MAX(c1, c2) << endl; //This works like a charm

return 0;
}


//////Important Example - (Templates with non type parameter: template overloading)///////
template<class T, int size>
T MAX(T x[size]) {
    T t = x[0];
    for(int i = 1; i<size; i++)
        t = max(t, x[i]);
    
    return t;
}

int main() {
    int arr[] = {1, 2, 3, 7, 6};

    cout << MAX<int,5>(arr) << endl;
}
