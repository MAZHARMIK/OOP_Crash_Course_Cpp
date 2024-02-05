#include <bits/stdc++.h>
using namespace std;

/*
    Friend function example-1 to show why it's required
    -When a function needs to access private data members of two or more different/independent classes and do some operation,
    and at the same time the function can't be a member function of any one class because it won't be able to access private
    members of other class, then friend function comes to rescue in this situation.
    Using friend function, a global function can access private members of some class.
*/
#include <iostream>

// Forward declaration of ClassB
class ClassB;

class ClassA {
private:
    int privateDataA;

public:
    ClassA(int dataA) : privateDataA(dataA) {}

    // Declare friend function that needs access to privateDataA and privateDataB
    friend void performOperation(const ClassA& objA, const ClassB& objB);
};

class ClassB {
private:
    int privateDataB;

public:
    ClassB(int dataB) : privateDataB(dataB) {}

    // Declare friend function that needs access to privateDataA and privateDataB
    friend void performOperation(const ClassA& objA, const ClassB& objB);
};

// Definition of the friend function
void performOperation(const ClassA& objA, const ClassB& objB) {
    // Access private members of both ClassA and ClassB
    std::cout << "Performing operation with private data from ClassA: " << objA.privateDataA
              << " and ClassB: " << objB.privateDataB << std::endl;

    // Perform some operation with private data from both classes
    // For simplicity, let's just display the sum of the private data
    int result = objA.privateDataA + objB.privateDataB;
    std::cout << "Result of the operation: " << result << std::endl;
}

int main() {
    ClassA objA(10);
    ClassB objB(20);

    // Call the friend function to perform the operation
    performOperation(objA, objB);

    return 0;
}
