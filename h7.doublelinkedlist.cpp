//Lamog, Robert
//Homework #7
//Hart
//11/6/14

#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

class List2{
public:
    List2();
    void addFront( const string & item );
    void addBack( const string & item );
    string removeFront();
    string removeBack();
    bool empty() const;
    unsigned size() const;
    void show() const;
private:
    unsigned LIST_SIZE;
    struct Node{
        string data;
            // If this node is the last node in the list, next is NULL.
            // Otherwise, next points to the next Node in the list.
        Node * next;
            // If this node is the first node in the list, prev is NULL.
            // Otherwise, prev points to the previous Node in the list.
        Node * prev;
    };
        // If the list is empty, front is NULL.
        // Otherwise, front points to the first Node in the list
    Node * front;
        // If the list is empty, back is NULL.
        // Otherwise, back points to the last node in the list
    Node * back;
}; // class List2

bool die( const string & msg );

int main() {
    
    return 0;
}

List2::List2(): front(NULL), back(NULL), LIST_SIZE(0) {}
void List2::addFront( const string & item ) {
    Node * newNode = NULL;
    
    try {
        newNode = new Node;
    } catch (const bad_alloc &) {
        die("addFront: Bad alloc.");
    }
    
    newNode->data = item;
    if (empty()) {
        newNode->next = NULL;
        newNode->prev = NULL;
        front = newNode;
        back = newNode;
    } else {
        newNode->next = front;
        newNode->prev = NULL;
        front = newNode;
    }

    LIST_SIZE++;
}
void List2::addBack( const string & item ) {
    Node * newNode = NULL;
    
    try {
        newNode = new Node;
    } catch (const bad_alloc &) {
        die("addBack: Bad alloc.");
    }
    
    newNode->data = item;
    if (empty()) {
        newNode->next = NULL;
        newNode->prev = NULL;
        front = newNode;
        back = newNode;
    } else {
        newNode->next = NULL;
        newNode->prev = back;
        back = newNode;
    }
    
    LIST_SIZE++;
}
string List2::removeFront() {
    Node * newFront = front->next;
    string ret = front->data;
    
    if (empty()) die("removeFront: List is already empty.");
    
    delete front;
    front = newFront;
    
    LIST_SIZE--;
    
    return ret;
}
string List2::removeBack() {
    Node * newBack = back->prev;
    string ret = back->data;
    
    if (empty()) die("removeBack: List is already empty.");
    
    delete back;
    back = newBack;
    
    LIST_SIZE--;
    
    return ret;
}
bool List2::empty() const {
    if (front == NULL && back == NULL) return true;
    return false;
}
unsigned List2::size() const {
    return LIST_SIZE;
}
void List2::show() const {
    Node * current = front;
    
    while(current != NULL) {
        cout <<current <<endl
             <<current->data <<endl
             <<current->next <<endl
             <<current->prev <<endl;
        current = current->next;
    }
}

bool die( const string & msg ) {
    cerr <<endl <<"Fatal error: " <<msg <<endl;
    exit( EXIT_FAILURE );
    
    // cout <<endl <<"Fatal error: " <<msg <<endl;
    // return true;
}