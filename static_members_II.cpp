#include <bits/stdc++.h>
using namespace std;

/*
    static members-II
    A good example to show use of static data members

*/

class PrintJobs {
    int nPages_;
public:
    static int nTrayPages_;
    static int nJobs_;
    PrintJobs(int nP): nPages_(nP) {
        ++nJobs_;
        cout << "Printing " << nP << " pages " << endl;
        nTrayPages_ -= nP;
    }

    ~PrintJobs() {
        --nJobs_;
    }
};

int PrintJobs::nTrayPages_ = 500;
int PrintJobs::nJobs_      = 0;

int main() {
    cout << "Jobs = " << PrintJobs::nJobs_      << endl;
    cout << "Pages= " << PrintJobs::nTrayPages_ << endl;

    PrintJobs job1(10);

    cout << "Jobs = " << PrintJobs::nJobs_      << endl;
    cout << "Pages= " << PrintJobs::nTrayPages_ << endl;

    {
        PrintJobs job1(30), job2(20);
        cout << "Jobs = " << PrintJobs::nJobs_      << endl;
        cout << "Pages= " << PrintJobs::nTrayPages_ << endl;
        PrintJobs::nTrayPages_ += 100; //Load 100 more pages
    } //here job1 and job2 goes out of scope and destructed (--nJobs_);

    cout << "Jobs = " << PrintJobs::nJobs_      << endl;
    cout << "Pages= " << PrintJobs::nTrayPages_ << endl;

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

