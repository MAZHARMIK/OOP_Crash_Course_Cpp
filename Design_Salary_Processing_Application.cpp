#include <bits/stdc++.h>
using namespace std;

/*
    Design Salary Processing Application
    Information and Requirements
    -An organization needs to develop a salary processing application for its staff.
    -At present it has an engineering division only where Engineers and Managers work.
    -Every Engineer reports to some Manager. Every manager can also work like and Engineer.
    -The logic for processing salary for Engineers and Managers are different as they have different salary heads.
    -In future, it may add Directors to the team. Then every Manager will report to some Director.
    -Every Director would also work like a Manager.
    -The logic for processing for Directors will also be distinct.
    -Further, in future it may open other divisions, like Sales division, and expand the workforce.
    -Make a suitable extensible design

    Director ----ISA-----> Manager -----ISA----> Engineer ----ISA----> Employee
                                         SalesExecutive  -------ISA---->^

    (1) To call the correct salary processing we make use of Polymorphic class hierarchy (Virtual Functions) : Dynamic Binding
    (2) Since, for an Employee, we can't have any salary processing logic, we will make it pure virtual function and hence
        Employee will be an Abstract Base Class.

*/

class Employee { //can't be instantiated (Abstract Base Class : Interface)
protected:
    string name_;
public:
    virtual void ProcessSalary(){};
};

class Engineer : public Employee {
public:
    //Why did we move name_ = name inside the body from initializer list ?
    /*
        Because when control reaches initializer list, at that point object has not been created and Engineer does not
        have name_ member. So, once it reaches inside constructor body, Engineer (inherited from Employee) is created which has
        inherited name_ from Employee
    */
    Engineer(const string& name) { name_= name ;}
    //since Process salary is pure virtual, derived class has to override it
    void ProcessSalary() {
        cout << name_ << ":Process Salary for Engineer" << endl;
    }
};

class Manager : public Engineer {
    Engineer *reports_[10];
public:
    Manager(const string& name) : Engineer(name) {}
    void ProcessSalary() {
        cout << name_ << ":Process Salary for Manager" << endl;
    }
};

class Director : public Manager {
    Manager *reports_[10];
public:
    Director(const string& name) : Manager(name) {}
    void ProcessSalary() {
        cout << name_ << ":Process Salary for Director" << endl;
    }
};

class SalesExecutive : public Employee {
public:
    SalesExecutive(const string& name) { name_ = name; }
    void ProcessSalary() {
        cout << name_ << ":Process Salary for SalesExecutive" << endl;
    }
};

int main() {
    Engineer e1("Rohit"),  e2("Kavita"), e3("Shambhu");
    Manager  m1("Kamala"), m2("Rajib");
    SalesExecutive s1("Hari"), s2("Bishnu");
    Director d("Ranjana");

    //Note : You cannot create an object of abstract base class but you can always
    //       have a pointer of that type because pointer does not need an object

    vector<Employee*> staff{&e1, &m1, &m2, &e2, &s1, &e3, &d, &s2};

    for(int i = 0; i<staff.size(); i++)
        staff[i]->ProcessSalary();


return 0;
}
