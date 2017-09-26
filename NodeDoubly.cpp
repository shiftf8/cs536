#include "NodeDoubly.h"

NodeDoubly::NodeDoubly() : next(nullptr), previous(nullptr)
{
} // end default constructor

NodeDoubly::NodeDoubly(const ItemType& anItem) : item(anItem), next(nullptr), previous(nullptr)
{
} // end constructor

NodeDoubly::NodeDoubly(const ItemType& anItem, NodeDoubly* nextNodePtr) :
                item(anItem), next(nextNodePtr)
{
} // end constructor

void NodeDoubly::setItem(const ItemType& anItem)
{
   item = anItem;
} // end setItem

void NodeDoubly::setNext(NodeDoubly* nextNodePtr)
{
   next = nextNodePtr;
} // end setNext

ItemType NodeDoubly::getItem() const
{
   return item;
} // end getItem

NodeDoubly* NodeDoubly::getNext() const
{
   return next;
} // end getNext



void NodeDoubly::setPrevious(NodeDoubly* previousNodePtr)
{
   previous = previousNodePtr;
}
NodeDoubly* NodeDoubly::getPrevious() const
{
   return previous;
}
