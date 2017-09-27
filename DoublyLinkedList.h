#ifndef DOUBLY_LINKED_LIST_
#define DOUBLY_LINKED_LIST_

#include <string>
#include "NodeDoubly.h"

using namespace std;

typedef int ItemType;

class DoublyLinkedList
{
private:
    NodeDoubly* headPtr; 	// Pointer to first node in the chain;
    int itemCount;   // Current count of list items
    // Locates a specified node in this linked list.
    NodeDoubly* getNodeAt(int position) const;

    NodeDoubly* tailPtr;
    
public:
    DoublyLinkedList();

    bool isEmpty() const;
    int getLength() const;
    bool insert(int newPosition, const ItemType& newEntry);
    bool remove(int position);
    void clear();
    
    ItemType getEntry(int position) const;
    ItemType replace(int position, const ItemType& newEntry);
    
    virtual ~DoublyLinkedList();

    DoublyLinkedList(const DoublyLinkedList& aList);
    DoublyLinkedList(const LinkedList& linkedList);
};

#endif