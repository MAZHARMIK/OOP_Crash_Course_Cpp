//This is one of the most important concepts which will be used in understanding Design Patterns as well.
#include <bits/stdc++.h>
using namespace std;

/*
    static and dynamic binding V
    Pure Virtual Function and Abstract Base Class

    How will you Design a hierarchy of Shapes ?
    -We want to have a polymorphic draw() function for the hierarchy
    -draw() will be overridden in every class based on the drawing algorithms
    -What is the draw() function for the root SHapes class ? (Dayumm!!! That's something wierd) :-|
    -draw() must be a member of Shapes class for polymorphic dispatch to work (i.e. we'll have a pointer to Base class and we can
     use that pointer to call draw() of different shapes that inherit Shapes class.
    -But we cannot define the body of draw() function for the root Shapes class as we do not have an algorithm to draw an arbitrary shape.
     In fact, we cannot even have a representation for shapes in general !

    Pure Virtual Function comes to rescue (Yayyyyyy!!!)
    A pure virtual function has a signature but no body! :-)

    Abstract Base Class
    -A class containing at least one Pure Virtual Function is called an Abstract Base Class
    -Pure Virtual Functions may be inherited or defined in the class
    -No instance can be created for an Abstract Class (Because if we had an object, we would call those pure
     virtual function which doesn't have a body)
    -And hence, Naturally it does not have a constructor or the destructor
    -An Abstract Base Class, however, may have other virtual (non-pure) and non-virtual member functions as well as data members.
    -Data members in an Abstract Base Class should be protected. Of course, private and public are also allowed.
    -Member functions in an Abstract Base Class should be public. Of Course, private and protected are also allowed.
    -A Concrete Class must override and implement all Pure Virtual Functions so that it can be instantiated.
     Because derived class inherits those pure virtual function and we don't want them to be called and hence derived
     class must override them.
*/

class Shapes {               //Abstract Base Class
public:
    virtual void draw() = 0; //Pure virtual function
    //Even if you provide the body of this draw() function the nature of this class doesn't change.
    //So, pure virtual function may have a body
    //BUT BUT BUT
    //-> to have a body the pure virtual function must be defined outside the class
};

class Polygon: public Shapes { //Concrete Class
    void draw() {
        cout << "Polygon: Draw by Triangulation" << endl;
    }
};

class ClosedConics: public Shapes { //Abbstract Base Class
    //it doesn't override draw()
    // draw() inherited - Pure Virtual. Hence, this class is also now Abstract
};

class Triangle: public Polygon { //Concrete Class
public:
    void draw() {
        cout << "Triangle: Draw by Lines" << endl;
    }
};

class Quadrilateral: public Polygon { //Concrete Class
public:
    void draw() {
        cout << "Quadrilateral: Draw by Lines" << endl;
    }
};

class Circle: public ClosedConics { //Concrete Class
public:
    void draw() {
        cout << "Circle: Draw by Bresenham Algorithm" << endl;
    }
};

class Ellipse: public ClosedConics { //Concrete Class
public:
    void draw() {
        cout << "Ellipse: Draw by some Algorithm" << endl;
    }
};


int main() {
    //Shapes s;       //ERRORRRRR!!!! Told ya (It's an abstract class dude)

    //ClosedConics c; //ERRORRRRR!!!! Told ya (It's an abstract class dude)

    vector<Shapes*> vec{new Triangle, new Quadrilateral, new Circle, new Ellipse};

    for(int i = 0; i<vec.size(); i++) {
        vec[i]->draw();
    }
    //Note: Since, pointers of type Shapes* and compiler looks at the type of object but not type of pointer when dealing
    //with virtual function.

    /*
    Output:
        Triangle: Draw by Lines
        Quadrilateral: Draw by Lines
        Circle: Draw by Bresenham Algorithm
        Ellipse: Draw by some Algorithm
    */

    //Hey : Don't forget to delete those object created using new :-(

return 0;
}
