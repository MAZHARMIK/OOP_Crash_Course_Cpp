#include <bits/stdc++.h>
using namespace std;

/*
    Free Copy Constructor and Shallow Copy (Bit Copy):
    - If user doesn't provide a copy constructor, compiler provides one and does a bit copy

    Sometimes bit copy will be fine. But sometimes it will lead to unexpected results.
    See the example below

    What is Shallow Copy or Bit Copy ?
    Ans : With bit-copy, only the pointer is copied - not the pointed object. This may be risky.

    ALERT :  So, Bit-copy(Shallow Copy) is not same as Object Copy(Deep Copy)  !!!
*/

class String {
public:
    char*  str_;
    size_t len_;
public:
    //constructor
    String(char* s): str_(strdup(s)), len_(strlen(str_)) {}
    ~String() {
        cout << "String Destructor. Bye Bye !";
        free(str_);
    }
    void strToUpper(String a) {
        for(int i = 0; i<a.len_; i++) {
            a.str_[i] = toupper(a.str_[i]);
        }
        //here scope of 'a' ends and destructor of 'a' is called
    }
    void print() {
        cout << "(" << str_ << ": " << len_ << ")" << endl;
    }
};

int main() {
    String s = "batman"; //String s("batman");

    s.print();
    s.strToUpper(s);
    //Since I did not provide a copy constructor, so compiler does a bit-copy(Shallow Copy)
    //(copied str_ pointer bit by bit as well and len_ as it is), which means, here s.str_ and a.str_ both now point to the same memory.
    //One exit from strToUpper(), 'a' is destructed and a.str_ is deallocated. Hence, in main access
    //to s.str_ is corrupted. Program crashes.
    //to s.str_ is corrupted. Program crashes.

    s.print(); //crashes

return 0;
}
