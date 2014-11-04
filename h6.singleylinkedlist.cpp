//Lamog, Robert
//Homework #6
//Hart
//10/20/14

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
    // aList.show();
    // cout <<aList.size() <<endl;
    // cout <<endl;
    // aList.addBack("xavier");
    // aList.show();
    // cout <<aList.size() <<endl;
    // cout <<endl;
    // aList.addBack("lamog");
    // aList.show();
    // cout <<aList.size() <<endl;
    // cout <<endl;
    // aList.addBack("!!!!!");
    aList.show();
    cout <<aList.size() <<endl;
    
    cout <<endl;
    aList.removeFront();
    aList.show();
    cout <<aList.size() <<endl;

    // aList.removeFront();
    // aList.show();
    // cout <<aList.size() <<endl;
    // aList.removeBack();
    // aList.show();
    

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
    try {
        Node * aNode = head;
        
        while (aNode != NULL) aNode = aNode->next;
        
        aNode->next = new Node;
        aNode = aNode->next;
        aNode->data = item;
        aNode->next = NULL;
        
        LIST_SIZE++;
    } catch (const bad_alloc &) {
        die("addBack: Bad alloc.");
    }
}
string List1::removeFront() {
    if (empty()) die("removeFront: List is empty.");
    
    Node * temp = head;
    head = head->next;
    delete temp;

    LIST_SIZE--;
}
string List1::removeBack() {
    if (empty()) die("List is empty.");
    Node * tmpHead = head;
    
    while (tmpHead->next != NULL) tmpHead = tmpHead->next;
    tmpHead = NULL;
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
        // cout <<current <<endl
        //      <<current->data <<endl
        //      <<current->next <<endl;
        cout <<current->data <<endl;
        current = current->next;
    }
}

bool die( const string & msg ) {
    // cerr <<endl <<"Fatal error: " <<msg <<endl;
    // exit( EXIT_FAILURE );

    cout <<endl <<"Fatal error: " <<msg <<endl;
    return true;
}