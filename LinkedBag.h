#ifndef LINKED_BAG_
#define LINKED_BAG_

#include <string>
#include <vector>
#include "Node.h"

using namespace std;

class LinkedBag 
{
private:
   Node* headPtr;    // Pointer to first node
   int   itemCount;  // Current count of bag items
   
   // Returns either a pointer to the node containing a given entry
   // or the null pointer if the entry is not in the bag.
   Node* getPointerTo(const ItemType& target) const;
   
public:
   LinkedBag();                           // Default constructor
   LinkedBag(const LinkedBag& aBag);      // Copy constructor
   ~LinkedBag();                          // Destructor 
   int getCurrentSize() const;
   bool isEmpty() const;
   bool add(const ItemType& newEntry);
   bool remove(const ItemType& anEntry);
   void clear();
   bool contains(const ItemType& anEntry) const;
   int getFrequencyOf(const ItemType& anEntry) const;
   vector<ItemType> toVector() const;
   
   LinkedBag union(const LinkedBag& otherBag);
   LinkedBag intersection(const LinkedBag& otherBag);
   LinkedBag difference(const LinkedBag& otherBag);
   
}; // end LinkedBag

#endif