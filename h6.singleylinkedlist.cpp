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
    aList.addBack("xavier");
    // aList.show();
    // cout <<aList.size() <<endl;
    // cout <<endl;
    aList.addBack("lamog");
    // aList.show();
    // cout <<aList.size() <<endl;
    // cout <<endl;
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
    // aList.removeBack();
    // aList.show();
    

    return 0;
}

List1::List1() {
    head = NULL;
}
void List1::addFront( const string & item ) {
    try {
        Node * aNode = new Node();
        
        aNode->data = item;
        aNode->next = head;
        head = aNode;
        
        // cout <<head <<endl
        //      <<aNode->data <<endl
        //      <<aNode->next <<endl <<endl;
    } catch (const bad_alloc &) {
        die("addFront: Bad alloc.");
    }
}
void List1::addBack( const string & item ) {
    try {
        Node * tmpHead = head;
        
        if (head != NULL) {
            while (tmpHead->next != NULL) tmpHead = tmpHead->next;
        }
        tmpHead->next = new Node;
        tmpHead = tmpHead->next;
        tmpHead->data = item;
        tmpHead->next = NULL;
        
        // cout <<tmpHead <<endl
        //      <<tmpHead->data <<endl
        //      <<tmpHead->next <<endl
        //      <<aNode <<endl
        //      <<aNode->data <<endl
        //      <<aNode->next <<endl <<endl;
    } catch (const bad_alloc &) {
        die("addBack: Bad alloc.");
    }
}
string List1::removeFront() {
    if (empty()) die("List is empty.");
    
    Node * tmpHead = head->next;
    delete head;
    head = tmpHead;
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
    unsigned counter = 0;
    Node * tmpHead = head;
    
    while (tmpHead != NULL) {
        tmpHead = tmpHead->next;
        counter++;
    }
    
    return counter;
}
void List1::show() const {
    Node * tmpHead = head;
    
    while (tmpHead != NULL) {
        cout <<tmpHead <<endl
             <<tmpHead->data <<endl
             <<tmpHead->next <<endl;
        // cout <<tmpHead->data <<endl;
        tmpHead = tmpHead->next;
    }
}

bool die( const string & msg ) {
    // cerr <<endl <<"Fatal error: " <<msg <<endl;
    // exit( EXIT_FAILURE );

    cout <<endl <<"Fatal error: " <<msg <<endl;
    return true;
}