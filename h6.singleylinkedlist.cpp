//Lamog, Robert
//Homework #6
//Hart
//10/20/14

#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

class List1 {
public:
    List1();
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
        Node * next;
    };
    Node * head;
}; // class List1

bool die( const string & msg );

int main() {
    List1 aList;
    
    aList.addFront("george");
    aList.addFront("henry");
    aList.addFront("michael");
    aList.show();
    cout <<aList.size() <<endl;

    cout <<endl;
    aList.addBack("xavier");
    aList.show();
    cout <<aList.size() <<endl;
    cout <<endl;
    aList.addBack("lamog");
    aList.show();
    cout <<aList.size() <<endl;
    cout <<endl;
    aList.addBack("!!!!!");
    aList.show();
    cout <<aList.size() <<endl;
    
    cout <<endl;
    aList.removeFront();
    aList.show();
    cout <<aList.size() <<endl;
    aList.removeFront();
    aList.show();
    cout <<aList.size() <<endl;
    
    cout <<endl;
    aList.removeBack();
    aList.show();
    cout <<aList.size() <<endl;
    aList.removeBack();
    aList.show();
    cout <<aList.size() <<endl;
    aList.removeBack();
    aList.show();
    cout <<aList.size() <<endl;
    aList.removeBack();
    aList.show();
    cout <<aList.size() <<endl;
    // aList.removeBack();
    // aList.show();
    // cout <<aList.size() <<endl;
    

    return 0;
}

List1::List1(): head(NULL), LIST_SIZE(0) {}
void List1::addFront( const string & item ) {
    Node * newNode = NULL;
    
    try {
        newNode = new Node;
    } catch (const bad_alloc &) {
        die("addFront: Bad alloc.");
    }
    
    newNode->data = item;
    newNode->next = head;
    head = newNode;
    
    LIST_SIZE++;
}
void List1::addBack( const string & item ) {
    Node * newNode = NULL, * tempHead = head;
    
    try {
        newNode = new Node;
    } catch (const bad_alloc &) {
        die("addBack: Bad alloc.");
    }
    
    if (head == NULL) head = newNode;
    else {
        while (tempHead->next != NULL) tempHead = tempHead->next;
        tempHead->next = newNode;
    }
    newNode->data = item;
    newNode->next = NULL;
    
    LIST_SIZE++;
}
string List1::removeFront() {
    Node * tempHead = head->next;
    string ret = head->data;

    if (empty()) die("removeFront: List is empty.");

    delete head;
    head = tempHead;
    
    LIST_SIZE--;
    
    return ret;
}
string List1::removeBack() {
    Node * newLastNode = NULL, * currentLastNode = head;
    string ret = "";
    
    if (empty()) die("removeBack: List is empty.");
    
    while (currentLastNode->next != NULL) {
        if (currentLastNode->next->next == NULL) newLastNode = currentLastNode;
        currentLastNode = currentLastNode->next;
    }
    ret = currentLastNode->data;
    delete currentLastNode;
    if (newLastNode) newLastNode->next = NULL;
    else head = NULL;
    
    LIST_SIZE--;
    
    return ret;
}
bool List1::empty() const {
    if (head == NULL) return true;
    return false;
}
unsigned List1::size() const {
    return LIST_SIZE;
}
void List1::show() const {
    Node * current = head;

    while (current != NULL) {
        cout <<current <<endl
             <<current->data <<endl
             <<current->next <<endl;
        current = current->next;
    }
}

bool die( const string & msg ) {
    cerr <<endl <<"Fatal error: " <<msg <<endl;
    exit( EXIT_FAILURE );
    
    // cout <<endl <<"Fatal error: " <<msg <<endl;
    // return true;
}