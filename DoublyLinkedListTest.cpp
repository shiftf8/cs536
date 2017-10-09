#include <iostream>
#include "DoublyLinkedList.h"
#include "LinkedList.h"

using namespace std;

int main()
{
    LinkedList list;
    
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
    
    // list.clear();
    // cout << "length [0]: " << list.getLength() << endl;
    // cout << "isEmpty [1]: " << list.isEmpty() << endl;
    

    cout << endl;
    // DoublyLinkedList doubleList;
    // for (int i = 1; i <= list.getLength(); i++)
    // {
    //     doubleList.insert(i, list.getEntry(i));
    // }
    
    DoublyLinkedList doubleList(list);
    cout << "length [9]: " << doubleList.getLength() << endl;
    cout << "isEmpty [0]: " << doubleList.isEmpty() << endl;
    doubleList.remove(3);
    cout << "length [8]: " << doubleList.getLength() << endl;
    
    entry = doubleList.getEntry(3);
    cout << "Entry [105]: " << entry << endl;
    
    doubleList.replace(3, 999);
    entry = doubleList.getEntry(3);
    cout << "Entry [999]: " << entry << endl;
    
    cout << "doubleList: ";
    for (int i = 1; i <= doubleList.getLength(); i++)
    {
        cout << doubleList.getEntry(i) <<  " ";
    }
    cout << endl;
    
    doubleList.clear();
    cout << "length [0]: " << doubleList.getLength() << endl;
    cout << "isEmpty [1]: " << doubleList.isEmpty() << endl;
    
    return 0;
}