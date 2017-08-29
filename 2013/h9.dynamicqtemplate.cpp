// Lamog, Robert
// Homework #9
// Hart
// 11/20/14

#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

template< typename T >
class Queue{
public:
    Queue(); // construct empty queue
    ~Queue(); // do any necessary memory deallocation
    void add( const T & x );
    T remove();
    unsigned size() const;
private:
    unsigned QUEUE_SIZE;
    struct Node{
    // Node will have 2 fields: one to hold the data of type T,
    //     and the other to hold a pointer to another Node
        T data;
        Node * next;
    };
    Node * myFront; // NULL for empty queue, otherwise points to
        // first-person-in-line
    Node * myBack; // NULL for empty queue, otherwise points to
        // last-person-in-line
    // perhaps you'll have a data member that holds the number of items
    //     in the queue. perhaps not. Either way is fine.
}; // Queue<T>

bool die( const string & msg );

int main() {
    Queue<string> qString;
    Queue<int> qInt;
    Queue<float> qFloat;
    
    qString.add("Rob");
    qString.add("Inness");
    qString.add("Lamog");
    qString.add("Doiel");
    cout <<qString.size() <<endl;
    
    qInt.add(1);
    qInt.add(2);
    qInt.add(3);
    qInt.add(4);
    qInt.add(5);
    qInt.add(6);
    qInt.add(7);
    qInt.add(8);
    cout <<qInt.size() <<endl;
    
    qFloat.add(1.1);
    qFloat.add(2.2);
    qFloat.add(3.3);
    qFloat.add(4.4);
    qFloat.add(5.5);
    qFloat.add(6.6);
    qFloat.add(7.7);
    qFloat.add(8.8);
    qFloat.add(9.9);
    qFloat.add(1.1);
    qFloat.add(2.2);
    qFloat.add(3.3);
    qFloat.add(4.4);
    qFloat.add(5.5);
    qFloat.add(6.6);
    qFloat.add(7.7);
    qFloat.add(8.8);
    qFloat.add(9.9);
    cout <<qFloat.size() <<endl;    
    return 0;
}

template< typename T >
Queue<T>::Queue(): myFront(NULL), myBack(NULL), QUEUE_SIZE(0) {}
template< typename T >
Queue<T>::~Queue() {
    while (size() > 0) cout <<remove() <<endl;
}
template< typename T >
void Queue<T>::add( const T & x ) {
    Node * newNode = NULL;
    
    try {
        newNode = new Node;
    } catch (const bad_alloc &) {
        die("add: Bad alloc.");
    }
    
    newNode->data = x;
    newNode->next = NULL;
    if (size() == 0) {
        myFront = newNode;
        myBack = newNode;
    }
    if (size() > 0) {
        myBack->next = newNode;
        myBack = newNode;
    }
    
    QUEUE_SIZE++;
}
template< typename T >
T Queue<T>::remove() {
    Node * tempNextNode = NULL;
    T nodeData;
    
    tempNextNode = myFront->next;
    nodeData = myFront->data;
    delete myFront;
    myFront = tempNextNode;
    
    QUEUE_SIZE--;

    return nodeData;
}
template< typename T >
unsigned Queue<T>::size() const {
    return QUEUE_SIZE;
}

bool die( const string & msg ) {
    cerr <<endl <<"Fatal error: " <<msg <<endl;
    exit( EXIT_FAILURE );
    
    // cout <<endl <<"Fatal error: " <<msg <<endl;
    // return true;
}