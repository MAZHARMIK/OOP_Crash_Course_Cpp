#include <bits/stdc++.h>
using namespace std;

/*
    static members-III (static member function)
    Now, as you must have noticed that static data members are in public visibility space, as my application is changing it,
    anyone can come and change it (encapsulation issues)
    So, we try to make them private.
    But, if static members are now private, how do we manipulate it ?
    So, we need a static member function which can change those static private data members for me.
    Because non-static member function will have this pointer and static data members do not belong to any object
    Static Member Function
    - Does not have this pointer - not associated with any object
    - cannot access non-static data members     (no this pointer)
    - cannot invoke non-static member functions (no this pointer)
    - can be accessed
        -- with the class-name followed by ::
        -- as a member of any object of the class
    - is needed to read/write static data members
        -- again, for encapsulation static data members should be private
        -- get()-set() idiom is built for access (static members functions in public)
    - may initialize static data members even before any object creation
    - cannot co-exist with a non-static version of the same function
    - cannot be declared as const (because it has not "this" to refer to, so no point in being const)
*/


class PrintJobs {
    int nPages_;
    static int nTrayPages_;
    static int nJobs_;
public:
    PrintJobs(int nP): nPages_(nP) {
        ++nJobs_;
        cout << "Printing " << nP << " pages " << endl;
        nTrayPages_ -= nP;
    }

    ~PrintJobs() {
        --nJobs_;
    }

    static int getJobs()    { return nJobs_; }
    static int checkPages() { return nTrayPages_; }
    static void loadPages(int nP) { nTrayPages_ += nP; }
};

int PrintJobs::nTrayPages_ = 500;
int PrintJobs::nJobs_      = 0;

int main() {
    cout << "Jobs = " << PrintJobs::getJobs()   << endl;
    cout << "Pages= " << PrintJobs::checkPages()<< endl;

    PrintJobs job1(10);

    cout << "Jobs = " << PrintJobs::getJobs()   << endl;
    cout << "Pages= " << PrintJobs::checkPages()<< endl;

    {
        PrintJobs job1(30), job2(20);
        cout << "Jobs = " << PrintJobs::getJobs()   << endl;
        cout << "Pages= " << PrintJobs::checkPages()<< endl;
        PrintJobs::loadPages(100); //Load 100 more pages
    } //here job1 and job2 goes out of scope and destructed (--nJobs_);

    cout << "Jobs = " << PrintJobs::getJobs()   << endl;
    cout << "Pages= " << PrintJobs::checkPages()<< endl;

    return 0;

    /*
    Output:
        Jobs = 0
        Pages= 500
        Printing 10 pages
        Jobs = 1
        Pages= 490
        Printing 30 pages
        Printing 20 pages
        Jobs = 3
        Pages= 440
        Jobs = 1
        Pages= 540
    */
}

