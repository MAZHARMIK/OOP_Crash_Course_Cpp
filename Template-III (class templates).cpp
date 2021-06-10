#include <bits/stdc++.h>
using namespace std;

/*
    Template - III
    Class templates

    We can have default parameters in templates as well
    template<class T1 = int, class T2 = string>
    class Student {
        //body
    };

    //All below are valid now
    Student<int> s1(5, "avc");
    Student<int, string> s2(5, "abc");
    Student<>  s3(5, "dfg");
    Student<string> s4("abc", "def");
    Student<int> s5(5, 4);
    Student<string, string> s5("dfd", "dfs");
    Student<int, int> s6(1, 2);

*/

template<class T>
class Stack {
private : 
    T data[100];
    int top_;

public:
    Stack() : top_(-1) {};
    ~Stack();

    void push(const T& item) {
        data[++top_] = item;
    }

    void pop() {
        --top_;
    }

    const T& top() const {
        if(top_ != -1)
            return data[top_];
        cout << "Empty stack" << endl;
        return -1;
    }

    bool empty() {
        return top_==-1;
    }
};

int main() {
    stack<int> st1;
    stack<char> st2;
return 0;
}
