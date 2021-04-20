#include <bits/stdc++.h>
using namespace std;

/*
    Friend function Example-II to show why it's required
    -When a function needs to access private data members of two or more different/independent classes and do some operation,
    and at the same time the function can't be a member function of any one class because it won't be able to access private
    members of other class, then friend function comes to rescue in this situation.
    So, using friend function, a member function of one class can access private members of another class.
*/
class Node;

class List {
    Node* head; //Head of the list
    Node* tail; //Tail of the list
public:
    List(Node* h = NULL) : head(h), tail(h) {}

    void display();
    void append(Node* p);
};

class Node {
    int val;
    Node* next;
public:
    Node(int i) : val(i), next(NULL) {}
    friend void List::display();
    friend void List::append(Node* p);
};

//Member function
void List::display() {
    Node* temp = head;
    while(temp) {
        cout << temp->val << " "; //Node val is private within class Node. To access it inside a member function of class List, we
                                  //need to make display() a friend function of class Node
        temp = temp->next;
    }
}

//Member function
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

