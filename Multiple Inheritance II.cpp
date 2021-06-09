#include <bits/stdc++.h>
using namespace std;

/*
    Multiple Inheritance Part - II
    -Diamond Problem
    -Virtual Inheritance - Virtual Base Class
    -Ambiguity

*/

///////////////////Diamond Problem/////////////////
class Person {
public:
    Person(int x) {
        cout << "Person::Preson(int)" << endl;
    }
};

class Faculty : public Person {
public:
    Faculty(int x) : Person(x) {
        cout << "Faculty::Faculty(int)" << endl;
    }
};

class Student : public Person { 
public:
    Student(int x) : Person(x) {
        cout << "Student::Student(int)" << endl;
    }
};

class TA : public Faculty, public Student {
public:
    TA(int x) : Student(x), Faculty(x) {
        cout << "TA::TA(int)" << endl;
    }
};


int main() {
    TA tx(20);
    /*
    output
        Person::Preson(int)
        Faculty::Faculty(int)
        Person::Preson(int)
        Student::Student(int)
        TA::Student(int)
    */

    /*
        Notice above, two instances of base class object (Person) in a TA object
        This is not desirable. How to solve this issue ?
        We now see example of Virtual inheritance below
    */

return 0;
}


///////////////////Virtual Inheritance - Virtual Base Class/////////////////
/*
    We virtually inherit Person in Faculty and Student.
    This will make Faculty and Person to not construct instance of Person inside them.
    And then only one instance of base class Person will be constructed which will be common for TA, Student, Person
    So, question arises, how will this happen ? No one is calling Person for instance construction, then how will the object
    be created for Person.
    Ans : We will have to write a defuault constructor for base class Person so that when TA inherits Student and Faculty
    , default constrcutor gets called one object of Person is created.
*/

class Person {
public:
    Person(int x) {
        cout << "Person::Preson(int)" << endl;
    }
    Person() {
        cout << "Default constr -> Person::Person()" << endl;
    }
};

class Faculty : virtual public Person { //virtual base class
public:
    Faculty(int x) : Person(x) {
        cout << "Faculty::Faculty(int)" << endl;
    }
};

class Student : virtual public Person { //virtual base class
public:
    Student(int x) : Person(x) {
        cout << "Student::Student(int)" << endl;
    }
};

class TA : public Faculty, public Student {
public:
    TA(int x) : Student(x), Faculty(x) {
        cout << "TA::TA(int)" << endl;
    }
};


int main() {
    TA tx(20);
    /*
    output
        Default constr -> Person::Person()
        Faculty::Faculty(int)
        Student::Student(int)
        TA::TA(int)
    */
   /*
    Note : See above that you can only call a default constructor of Base class. 
    What if we want to pass values to constructor ?
    Se next example below (Just call Base class constructor from TA)
   */
return 0;
}


///////////////////////Last example///////////////////

class Person {
public:
    Person(int x) {
        cout << "Person::Preson(int)" << endl;
    }
    Person() {
        cout << "Default constr -> Person::Person()" << endl;
    }
};

class Faculty : virtual public Person { //virtual base class
public:
    Faculty(int x) : Person(x) {
        cout << "Faculty::Faculty(int)" << endl;
    }
};

class Student : virtual public Person { //virtual base class
public:
    Student(int x) : Person(x) {
        cout << "Student::Student(int)" << endl;
    }
};

class TA : public Faculty, public Student {
public:
    TA(int x) : Student(x), Faculty(x), Person(x) { //call Base class constructor (Person(x)) from TA
        cout << "TA::TA(int)" << endl;
    }
};


int main() {
    TA tx(20);
    /*
    output
        Person::Person(int)
        Faculty::Faculty(int)
        Student::Student(int)
        TA::TA(int)
    */
   /*
    Note : See above that Person::Person(int) gets called this time.
   */
return 0;
}




///////////////////////Ambiguity///////////////////
/*
    In a diamond problem, if we have a pure virtual function in Base class, then
    it has to be implemented by the derived classes.
    But, once derived it becomes ambigous for the class which inherits the derived classes
    that which virtual function it inherits.

    So, to overcome that, we implement that pure virtual function in the class as well.
*/

class Person {
public:
    Person(int x) {
        cout << "Person::Preson(int)" << endl;
    }
    Person() {
        cout << "Default constr -> Person::Person()" << endl;
    }

    virtual void teach() = 0; //since it's pure virtual, Faculty and Student will have to implement it
};

class Faculty : virtual public Person { //virtual base class
public:
    Faculty(int x) : Person(x) {
        cout << "Faculty::Faculty(int)" << endl;
    }

    virtual void teach() {
        cout << "Faculty::teach()" << endl;
    }
};

class Student : virtual public Person { //virtual base class
public:
    Student(int x) : Person(x) {
        cout << "Student::Student(int)" << endl;
    }

    virtual void teach() {
        cout << "Student::teach()" << endl;
    }
};

class TA : public Faculty, public Student {
public:
    TA(int x) : Student(x), Faculty(x), Person(x) { //call Base class constructor (Person(x)) from TA
        cout << "TA::TA(int)" << endl;
    }

    //I have to do this because it will be ambigous for compiler that which teach() function it inherits (Faculty, or Student)
    virtual void teach() {
        cout << "TA::teach()" << endl;
    }
};


int main() {
    TA tx(20);
    
return 0;
}
