#include "PlainBox.h"
#include <iostream>
using namespace std;

int main(){
    // Create a PlainBox object
    PlainBox box;
    // Set the item in the box
    box.setItem(22.5);
    // Get and print the item in the box
    cout << box.getItem() << endl;
    
    return 0;
}