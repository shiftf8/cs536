#ifndef NODE_DOUBLY_
#define NODE_DOUBLY_

#include <string>

using namespace std;

typedef string ItemType;

class NodeDoubly
{
private:
   ItemType item;  // A data item
   NodeDoubly*    next;  // Pointer to next node
   
   NodeDoubly*    previous;
   
public:
   NodeDoubly();
   NodeDoubly(const ItemType& anItem);
   NodeDoubly(const ItemType& anItem, NodeDoubly* nextNodePtr, NodeDoubly* previousNodePtr);
   void setItem(const ItemType& anItem);
   void setNext(NodeDoubly* nextNodePtr);
   ItemType getItem() const ;
   NodeDoubly* getNext() const ;

   void setPrevious(NodeDoubly* previousNodePtr);
   NodeDoubly* getPrevious() const ;
}; // end NodeDoubly

#endif