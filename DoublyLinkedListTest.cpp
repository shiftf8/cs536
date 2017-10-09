#include <iostream>
#include "DoublyLinkedList.h"
#include "LinkedList.h"

using namespace std;

void printVector(vector<string>& v)
{
   for (vector<string>::iterator i = v.begin(); i != v.end(); ++i)
   {
      cout << *i << " " ;
   }   
   cout << endl;
}

int main()
{
    LinkedList slist;
    
    slist.insert(1, "aa"), slist.insert(2, "bb"), slist.insert(3, "cc"), slist.insert(4, "dd");
    
    DoublyLinkedList dlist(slist);
    
    vector<string> v = dlist.toVector(0);
    cout << "Step 3 dlist:\t";
    printVector(v);
    
    v = dlist.toVector(1);
    cout << "Step 4 dlist:\t";
    printVector(v);
    
    dlist.reverse();
    v = dlist.toVector(0);
    cout << "Step 6 dlist:\t";
    printVector(v);
    
    DoublyLinkedList dlist2(dlist);
    v = dlist2.toVector(0);
    cout << "Step 8 dlist:\t";
    printVector(v);

    dlist2.reverse();
    v = dlist2.toVector(0);
    cout << "Step 10 dlist:\t";
    printVector(v);
    
    v = dlist.toVector(0);
    cout << "Step 11 dlist:\t";
    printVector(v);
    
    return 0;
}