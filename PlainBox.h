#ifndef PLAIN_BOX_
#define PLAIN_BOX_
// Set the type of data stored in the box
typedef double ItemType;
// Declaration for the class PlainBox
class PlainBox
{
private:
    // Data field
    ItemType item;
public:
    // Default constructor
    PlainBox();
    // Parameterized constructor
    PlainBox(const ItemType& theItem);
    // Method to change the value of the data field
    void setItem(const ItemType& theItem);
    // Method to get the value of the data field
    ItemType getItem() const;
}; // end PlainBox
#endif