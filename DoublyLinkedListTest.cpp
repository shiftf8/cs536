#include <iostream>
#include "DoublyLinkedList.h"
#include "LinkedList.h"

int main()
{
    LinkedList list, list2;
    
    for (int i = 1; i <= 10; i++)
    {
        list.insert(i, 100 + i);
    }
    
    cout << "length [10]: " << list.getLength() << endl;
    cout << "isEmpty [0]: " << list.isEmpty() << endl;
    list.remove(3);
    cout << "length [9]: " << list.getLength() << endl;
    
    int entry = list.getEntry(3);
    cout << "Entry [104]: " << entry << endl;
    
    list.replace(3, 999);
    entry = list.getEntry(3);
    cout << "Entry [999]: " << entry << endl;
    
    cout << "list: ";
    for (int i = 1; i <= list.getLength(); i++)
    {
        cout << list.getEntry(i) <<  " ";
    }
    cout << endl;
    
    list.clear();
    cout << "length [0]: " << list.getLength() << endl;
    cout << "isEmpty [1]: " << list.isEmpty() << endl;
    
    
    list2 = DoublyLinkedList(list);
    cout << "list2: ";
    for (int i = 1; i <= list.getLength(); i++)
    {
        cout << list.getEntry(i) <<  " ";
    }
    cout << endl;
}