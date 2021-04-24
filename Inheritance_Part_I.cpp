#include <iostream>
using namespace std;

/*
    Inheritance
    -ISA Relationship
        A relationship of specialization that states that a concept "is a" particular kind of another concept
    -C++ models ISA relationship by inheritance of classes
    Examples:
    1) Rose ISA Flower (Rose = specialization   ; Flower = generalization)
        -Rose has properties of Flower
        -Rose has some extra properties - like rosy fragrance
    2) Red Rose ISA a rose (Red Rose = specialization   ; Rose = generalization)
        -Red Rose has properties of Rose
        -Red Rose has some extra propertied - like Red color

    UML Diagram : Red Rose ----> Rose ---> Flower

    3) Two wheeler ISA vehicle, three wheeler ISA vehicle
        -We usually refer vehicle as Base and Two/Three wheeler as Derived

    4) Manager ISA employee

    General Semantics in C++:
    class Base;
    class Derived : public Base;
*/

//Inheritance hierarchy
//Manager ISA employee (Single Inheritance)
class Employee;                     //Base class
class Manager : public Employee;    //Derived class

//Two wheeler ISA vehicle, three wheeler ISA vehicle (Hybrid Inheritance)
class Vehicle;                       //Base Class (Root)
class TwoWheeler : public Vehicle;   //Derived
class ThreeWheeler : public Vehicle; //Derived

//Red Rose ISA Rose ISA Flower (Multi-Level inheritance)
class Flower;                       //Base Class (root)
class Rose : public Flower;         //Derived Rose; Base Class Rose(for RedRose)
class RedRose : public Rose;        //Derived



/*
    Inheritance Semantics in C++:
    1) Derived ISA base
    2) Data members
        -Derived class inherits all data members of Base class
        -Derived class may add data members of its own
    3) Member Functions
        -Derived class inherits all member function of Base class
        -Derived class may "override" a member function of Base class by redefining it with the "same signature"
        -Derived class may "overload" a member function of Base class by redefining it with same name but "different signature"
    4) Access Specification
        -Derived class cannot access private members of Base class
        -Derived class can access protected members of Base class
    5) Construction-Deconstruction
        -A constructor of the Derived class must "first" call the constructor of Base class to construct the Base class instance of the Derived class
        -A Deconstructor of the Derived class must call the destructor of Base class to destruct the Base class instance of the Derived class
*/
