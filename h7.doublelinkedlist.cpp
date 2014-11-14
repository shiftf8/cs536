//Lamog, Robert
//Homework #6
//Hart
//11/6/14

#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

class List2{
public:
    List2();
    void addFront( const string & item );
    void addBack( const string & item );
    string removeFront();
    string removeBack();
    bool empty() const;
    unsigned size() const;
    void show() const;
private:
    struct Node{
        string data;
            // If this node is the last node in the list, next is NULL.
            // Otherwise, next points to the next Node in the list.
        Node * next;
            // If this node is the first node in the list, prev is NULL.
            // Otherwise, prev points to the previous Node in the list.
        Node * prev;
    };
        // If the list is empty, front is NULL.
        // Otherwise, front points to the first Node in the list
    Node * front;
        // If the list is empty, back is NULL.
        // Otherwise, back points to the last node in the list
    Node * back;
}; // class List2

int main() {
    return 0;
    }