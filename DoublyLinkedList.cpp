#include <cassert>
#include "DoublyLinkedList.h"

DoublyLinkedList::DoublyLinkedList() : headPtr(nullptr), itemCount(0), tailPtr(nullptr)
{
}  // end default constructor


void DoublyLinkedList::clear()
{
   while (!isEmpty())
      remove(1);
}  // end clear


int DoublyLinkedList::getLength() const
{
   return itemCount;
}  // end getLength

bool DoublyLinkedList::isEmpty() const
{
   return itemCount == 0;
}  // end isEmpty


ItemType DoublyLinkedList::getEntry(int position) const
{
   bool ableToGet = (position >= 1) && (position <= itemCount);
   if (ableToGet)
   {
      NodeDoubly* nodePtr = getNodeAt(position);
      return nodePtr->getItem();
   }
   else
   {
      std::string message = "getEntry() called with an empty list or ";
      message = message + "invalid position.";
      throw(message);
   }
}  // end getEntry


bool DoublyLinkedList::insert(int newPosition, const ItemType& newEntry)
{
   bool ableToInsert = (newPosition >= 1) && (newPosition <= itemCount + 1);
   
   if (ableToInsert)
   {
      // Create a new node containing the new entry
      NodeDoubly* newNodePtr = new NodeDoubly(newEntry);
      
      // Attach new node to chain
      if (newPosition == 1)
      {
         // Insert new node at beginning of chain
         newNodePtr->setNext(headPtr);
         if (itemCount > 1) headPtr->setPrevious(newNodePtr);
         headPtr = newNodePtr;
         headPtr->setPrevious(nullptr);
      }
      else if (newPosition == itemCount + 1)
      {
         // Find node that will be before new node
         NodeDoubly* prevPtr = getNodeAt(newPosition - 1);

         // Insert new node after node to which prevPtr points
         newNodePtr->setNext(nullptr);
         prevPtr->setNext(newNodePtr);
         newNodePtr->setPrevious(prevPtr);
         
         tailPtr = newNodePtr;
      }
      else
      {
         // Find node that will be before new node
         NodeDoubly* prevPtr = getNodeAt(newPosition - 1);
         NodeDoubly* nextPtr = getNodeAt(newPosition);
         
         // Insert new node after node to which prevPtr points
         newNodePtr->setNext(nextPtr);
         nextPtr->setPrevious(newNodePtr);
         prevPtr->setNext(newNodePtr);
         newNodePtr->setPrevious(prevPtr);
      }
      
      itemCount++; // Increase count of entries
   }
   
   return ableToInsert;
}  // end insert


bool DoublyLinkedList::remove(int position)
{
   bool ableToRemove = (position >= 1) && (position <= itemCount);
   if (ableToRemove)
   {
      NodeDoubly* curPtr = nullptr;
      if (position == 1)
      {
         // Remove the first node in the chain
         curPtr = headPtr; // Save pointer to node
         headPtr = headPtr->getNext();
      }
      else
      {
         // Find node that is before the one to remove
         NodeDoubly* prevPtr = getNodeAt(position - 1);
         NodeDoubly* nextPtr = getNodeAt(position + 1);

         // Point to node to remove
         curPtr = prevPtr->getNext();
         
         // Disconnect indicated node from chain by connecting the
         // prior node with the one after
         prevPtr->setNext(nextPtr);
         nextPtr->setPrevious(prevPtr);
      }
      
      // Return node to system
      curPtr->setNext(nullptr);
      curPtr->setPrevious(nullptr);
      delete curPtr;
      curPtr = nullptr;
      itemCount--; // Decrease count of entries
   }
   
   return ableToRemove;
}  // end remove


ItemType DoublyLinkedList::replace(int position, const ItemType& newEntry)
{
   bool ableToReplace = (position >= 1) && (position <= itemCount);
   if (ableToReplace)
   {
      NodeDoubly* entryPtr = getNodeAt(position);
      ItemType oldEntry = entryPtr->getItem();
      entryPtr->setItem(newEntry);
      
      return oldEntry;
   }
   else
   {
      std::string message = "replace() called with an empty list or ";
      message = message + "invalid position.";
      throw(message);
   }
}  // end replace


NodeDoubly* DoublyLinkedList::getNodeAt(int position) const
{
   // Debugging check of precondition
   assert( (position >= 1) && (position <= itemCount) );
   
   // Count from the beginning of the chain
   NodeDoubly* curPtr = headPtr;
   for (int skip = 1; skip < position; skip++)
      curPtr = curPtr->getNext();
      
   return curPtr;
}  // end getNodeAt


DoublyLinkedList::~DoublyLinkedList()
{
   clear();
} // end destructor


DoublyLinkedList::DoublyLinkedList(const DoublyLinkedList& aList)
{
   itemCount = aList.itemCount;
   NodeDoubly* origChainPtr = aList.headPtr; // Points to nodes in original chain

   if (origChainPtr == nullptr)
   {
      headPtr = nullptr; // Original list is empty
      tailPtr = nullptr;
   }
   else
   {
      // Copy first node
      headPtr = new NodeDoubly();
      headPtr->setItem(origChainPtr->getItem());
      headPtr->setPrevious(origChainPtr->getPrevious());

      // Copy remaining nodes
      NodeDoubly* newChainPtr = headPtr; // Points to last node in new chain
      origChainPtr = origChainPtr->getNext(); // Advance original-chain pointer
      
      while (origChainPtr != nullptr)
      {
         // Get next item from original chain
         ItemType nextItem = origChainPtr->getItem();
         
         // Create a new node containing the next item
         NodeDoubly* newNodePtr = new NodeDoubly(nextItem);
         
         // Link new node to end of new chain
         newChainPtr->setNext(newNodePtr);
         newNodePtr->setPrevious(newChainPtr);

         // Advance pointer to new last node
         newChainPtr = newChainPtr->getNext();
         
         // Advance original-chain pointer
         origChainPtr = origChainPtr->getNext();
      } // end while
      
      
      newChainPtr->setNext(nullptr); // Flag end of new chain
      tailPtr = newChainPtr;
   } // end if
} // end copy constructor

DoublyLinkedList::DoublyLinkedList(const LinkedList& linkedList) : headPtr(nullptr), itemCount(0), tailPtr(nullptr)
{
   for (int i = 1; i <= linkedList.getLength(); i++)
   {
      this->insert(i, linkedList.getEntry(i));
   }
}