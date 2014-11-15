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
    unsigned LIST_SIZE;
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
    
    return 0;
}

template< typename T >
Queue<T>::Queue(): myFront(NULL), myBack(NULL), LIST_SIZE(0) {}
template< typename T >
Queue<T>::~Queue() {
    
}
template< typename T >
void Queue<T>::add( const T & x ) {
    
}
template< typename T >
T Queue<T>::remove() {
    
}
template< typename T >
unsigned Queue<T>::size() const {
    return LIST_SIZE;
}

bool die( const string & msg ) {
    cerr <<endl <<"Fatal error: " <<msg <<endl;
    exit( EXIT_FAILURE );
    
    // cout <<endl <<"Fatal error: " <<msg <<endl;
    // return true;
}

