#include <cstdio>
#include "LinkedBag.h"

LinkedBag::LinkedBag() : headPtr(nullptr), itemCount(0)
{
}  // end default constructor


bool LinkedBag::add(const ItemType& newEntry)
{
   // (headPtr is null if chain is empty)        
   Node* nextNodePtr = new Node();
   nextNodePtr->setItem(newEntry);
   nextNodePtr->setNext(headPtr);  // New node points to chain

// alternate code: Node* nextNodePtr = new Node(newEntry, headPtr); 
   
   headPtr = nextNodePtr;          // New node is now first node
   itemCount++;
   
   return true;                    // The method is always successful
}  // end add


int LinkedBag::getCurrentSize() const
{
   return itemCount;
}  // end getCurrentSize


bool LinkedBag::isEmpty() const
{
   return itemCount == 0;
}  // end isEmpty


int LinkedBag::getFrequencyOf(const ItemType& anEntry) const
{
   int frequency = 0;
   int counter = 0;
   Node* curPtr = headPtr;
   while ((curPtr != nullptr) && (counter < itemCount))
   {
      if (anEntry == curPtr->getItem())
      {
         frequency++;
      } // end if
      
      counter++;
      curPtr = curPtr->getNext();
   } // end while
   
   return frequency;
}  // end getFrequencyOf


// Returns either a pointer to the node containing a given entry
// or the null pointer if the entry is not in the bag.
Node* LinkedBag::getPointerTo(const ItemType& target) const
{
   bool found = false;
   Node* curPtr = headPtr;
   
   while (!found && (curPtr != nullptr))
   {
      if (target == curPtr->getItem())
         found = true;
      else
         curPtr = curPtr->getNext();
   } // end while
   
   return curPtr;
} // end getPointerTo

bool LinkedBag::contains(const ItemType& anEntry) const
{
   return (getPointerTo(anEntry) != nullptr);
}  // end contains


void LinkedBag::clear()
{
   Node* nodeToDeletePtr = headPtr;
   while (headPtr != nullptr)
   {
      headPtr = headPtr->getNext();
      
      // Return node to the system
      nodeToDeletePtr->setNext(nullptr);
      delete nodeToDeletePtr;
      nodeToDeletePtr = headPtr;
   }  // end while
   // headPtr is nullptr; nodeToDeletePtr is nullptr
   
   itemCount = 0;
}  // end clear


bool LinkedBag::remove(const ItemType& anEntry)
{
   Node* entryNodePtr = getPointerTo(anEntry);
   bool canRemoveItem = !isEmpty() && (entryNodePtr != nullptr);
   if (canRemoveItem)
   {
      // Copy data from first node to located node
      entryNodePtr->setItem(headPtr->getItem());
      
      // Delete first node
      Node* nodeToDeletePtr = headPtr;
      headPtr = headPtr->getNext();
      
      // Return node to the system
      nodeToDeletePtr->setNext(nullptr);
      delete nodeToDeletePtr;
      nodeToDeletePtr = nullptr;
      
      itemCount--;
   } // end if
   
   return canRemoveItem;
}  // end remove


vector<ItemType> LinkedBag::toVector() const
{
   std::vector<ItemType> bagContents;
   Node* curPtr = headPtr;
   int counter = 0;
   while ((curPtr != nullptr) && (counter < itemCount))
   {
      bagContents.push_back(curPtr->getItem());
      curPtr = curPtr->getNext();
      counter++;
   }  // end while
   
   return bagContents;

}  // end toVector


LinkedBag::~LinkedBag()
{
   clear();
}  // end destructor


LinkedBag::LinkedBag(const LinkedBag& aBag)
{
   itemCount = aBag.itemCount;
   Node* origChainPtr = aBag.headPtr; // Points to nodes in original chain
   
   if (origChainPtr == nullptr)
      headPtr = nullptr; // Original bag is empty
   else
   {
      // Copy first node
      headPtr = new Node();
      headPtr->setItem(origChainPtr->getItem());
      
      // Copy remaining nodes
      Node* newChainPtr = headPtr; // Points to last node in new chain
      origChainPtr = origChainPtr->getNext(); // Advance original-chain pointer
      
      while (origChainPtr != nullptr)
      {
         // Get next item from original chain
         ItemType nextItem = origChainPtr->getItem();
         
         // Create a new node containing the next item
         Node* newNodePtr = new Node(nextItem);
         
         // Link new node to end of new chain
         newChainPtr->setNext(newNodePtr);
         
         // Advance pointer to new last node
         newChainPtr = newChainPtr->getNext();
         
         // Advance original-chain pointer
         origChainPtr = origChainPtr->getNext();
      } // end while
      
      newChainPtr->setNext(nullptr); // Flag end of new chain
   } // end if
} // end copy constructor

LinkedBag LinkedBag::unionBag(const LinkedBag& otherBag) const
{
   LinkedBag retBag = LinkedBag(*this);
   Node* otherChainPtr = otherBag.headPtr;
   
   while (otherChainPtr != nullptr)
   {
      retBag.add(otherChainPtr->getItem());
      otherChainPtr = otherChainPtr->getNext();
   }
   
   return retBag;
}

LinkedBag LinkedBag::intersection(const LinkedBag& otherBag) const
{
   LinkedBag retBag;
   Node* otherChainPtr = otherBag.headPtr;
   
   while (otherChainPtr != nullptr)
   {
      if (this->contains(otherChainPtr->getItem())) retBag.add(otherChainPtr->getItem());
      otherChainPtr = otherChainPtr->getNext();
   }

   return retBag;
}

LinkedBag LinkedBag::difference(const LinkedBag& otherBag) const
{
   LinkedBag retBag = LinkedBag(*this);
   Node* otherChainPtr = otherBag.headPtr;
   
   while (otherChainPtr != nullptr)
   {
      if (retBag.contains(otherChainPtr->getItem())) retBag.remove(otherChainPtr->getItem());
      otherChainPtr = otherChainPtr->getNext();
   }
   
   return retBag;
}