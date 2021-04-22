#include <bits/stdc++.h>
using namespace std;

/*
    Friend class of a class
    -(all members) has access to the private and protected members of the class(breaks encapsulation)
    -does not have its name qualified with the class scope (not a nested class)
    -can be declared friend in more than one class

    A friend class can be
    -class
    -class template

    In the Linked list example we saw before, if we had to create another function say delete() in List class.
    Then also, I need to make this displa() a friend of Node class as well. It's cumbersome.
    We can achieve this by using friend class easily.

    So, if a class has too many member functions to be made friend of, its better to go for friend class instead of friend
    function
    
    IMPORTANT POINTS:
    - If class A is a friend of class B, it doesn't mean class B is a friend of class A
    - If class A is a friend of class B and class B is a friend of class C, it doesn't mean class A is a friend of class C
    
    Now, we are aware of three kinds of visibilities:
    -public
    -private
    -friend : It breaks visibility structure and hence should be used judiciously in cases like :
        - A function needs to access the internals of two(or more) independent classes. Ex: Matrix-vector multiplication
        - A class is built on top of another class. Ex: List-Node access
        - Certain situations of operator overloading. Ex: streaming operators (Later we will study this too)
*/

class Node;

class List {
    Node* head; //Head of the list
    Node* tail; //Tail of the list
public:
    explicit List(Node* h = NULL) : head(h), tail(h) {}

    void display();
    void append(Node* p);
};

class Node {
    int val;
    Node* next;
public:
    explicit Node(int i) : val(i), next(NULL) {}

    //No need to add these anymore
    //friend void List::display();
    //friend void List::append(Node* p);

    friend class List; //List is a friend of Node. So, List can access Node's private members
};

void List::display() {
    Node* temp = head;
    while(temp) {
        cout << temp->val << " "; //Node val is private within class Node. To access it inside a member function of class List, we
                                  //need to make display() a friend function of class Node
        temp = temp->next;
    }
}

void List::append(Node* p) {
    if(!head)
        head = tail = p;
    else {
        tail->next = p;    //Node next is private within class Node. To access it inside a member function of class List, we
                            //need to make append() a friend function of class Node
        tail = tail->next;
    }
}



int main() {
    List ll;

    Node n1(1);
    Node n2(2);
    Node n3(3);

    ll.append(&n1);
    ll.append(&n2);
    ll.append(&n3);

    ll.display();

return 0;
}

