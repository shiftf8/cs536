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
    
    aList.addFront("michael");
    aList.addFront("george");
    aList.addFront("henry");
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
    // aList.addFront("!!!!!");
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
        Node * tmpHead = head;
        
        if (tmpHead != NULL) {
            Node * aNode = new Node;
            
            aNode->data = item;
            aNode->next = head;
            head = aNode;
        } else {
            head = new Node;
        }
    } catch (exception& e) {
        cout <<"Standard exception: " <<e.what() <<endl;
    }
}
void List1::addBack( const string & item ) {
    try {
        Node * aNode = new Node;
        Node * tmpHead = head;

        aNode->data = item;
        aNode->next = NULL;
        
        if (tmpHead != NULL) {
            while (tmpHead->next != NULL) tmpHead = tmpHead->next;
            tmpHead->next = aNode;
        } else head = aNode;
        
        // cout <<tmpHead <<endl
        //      <<tmpHead->data <<endl
        //      <<tmpHead->next <<endl
        //      <<aNode <<endl
        //      <<aNode->data <<endl
        //      <<aNode->next <<endl <<endl;
    } catch (exception& e) {
        cout <<"Standard exception: " <<e.what() <<endl;
    }
}
string List1::removeFront() {
    if (empty()) die("List is empty.");
    
    Node * tmpHead = head;
    
    if (tmpHead->next == NULL) {
        delete tmpHead;
        head = NULL;
    }
}
string List1::removeBack() {
    if (empty()) die("List is empty.");
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
        tmpHead = tmpHead->next;
    }
}

bool die( const string & msg ) {
    // cerr <<endl <<"Fatal error: " <<msg <<endl;
    // exit( EXIT_FAILURE );

    cout <<endl <<"Fatal error: " <<msg <<endl;
    return true;
}