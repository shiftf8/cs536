#include "PlainBox.Tmpl.h"
#include <iostream>
using namespace std;

int main(){
    // Create a PlainBox object
    PlainBox<double> box;
    // Set the item in the box
    box.setItem(3.14159);
    // Get and print the item in the box
    cout << box.getItem() << endl;
    
    return 0;
}