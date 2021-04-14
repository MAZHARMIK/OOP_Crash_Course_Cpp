/*
  What is Information Hiding OR Encapsulation or State Based Design ?
  
  The private part of a class (attributes and methods) forms its "implementation" because the class alone should be concerned with it and have the right to change it.
  
  The public part of a class  (attributes and methods) constitues its "interface" which is available to all others for using the class
  
  Customarily (a string design guideline), we put:
      attributes  ->  private (Access specifier)
      methods     ->  public  (Access specifier)
      Becasue :
      - The state of an object can be changed only through one of its methods (with the knowledge of the class)
      - The behaviour of an object is accessible to others through the methods.
*/

#include <iostream>
#include <vector>
using namespace std;

//Interface
//File: Stack.h
class Stack {
private:
    //(This private members will also go to a separate private section (because it's an interface) later when we learn inheritance. For now, keeping it here
    char *_data;
    int  _top;
public:
    Stack();
    ~Stack();
    int Empty();
    void push(char x);
    void pop();
    char top();

};

//Implementation : Which writes the body/definition of the functions available in interface above
//File : Stack.cpp
//The header file above should be included here
Stack::Stack():_data(new char[100]), _top(-1) {}

Stack::~Stack() {
    delete []_data;
}

int Stack::Empty() {
    return _top==-1;
}

void Stack::push(char x) {
    _data[++_top] = x;
}

void Stack::pop() {
    --_top;
}

char Stack::top() {
    return _data[_top];
}


//Application
//File: Separate application file (any other file)
//It will have to #include "Stack.h" to use it
int main() {
    Stack s;
    char str[10] = "ABC";
    for(int i = 0; i<3; i++) {
        s.push(str[i]);
    }

    while(!s.Empty()) {
        cout << s.top();
        s.pop();
    }
	return 0;
}
