#ifndef DOUBLY_LINKED_LIST_
#define DOUBLY_LINKED_LIST_

#include "Node.h"
#include <string>
using namespace std;

typedef int ItemType;

class DoublyLinkedList
{
private:
    Node* headPtr; 	// Pointer to first node in the chain;
    int itemCount;   // Current count of list items
    // Locates a specified node in this linked list.
    Node* getNodeAt(int position) const;

    Node* tailPtr;
    
public:
    DoublyLinkedList();
    // Copy constructor and destructor are supplied by compiler
    
    bool isEmpty() const;
    int getLength() const;
    bool insert(int newPosition, const ItemType& newEntry);
    bool remove(int position);
    void clear();
    
    ItemType getEntry(int position) const;
    ItemType replace(int position, const ItemType& newEntry);
    
    virtual ~DoublyLinkedList();

    DoublyLinkedList(const DoublyLinkedList& aList);

}; // end ArrayList

#endif