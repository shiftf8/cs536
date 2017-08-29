#include "PlainBox.h"
PlainBox::PlainBox()
{
} // end default constructor
PlainBox::PlainBox(const ItemType& theItem)
{
item = theItem;
} // end constructor
void PlainBox::setItem(const ItemType& theItem)
{
item = theItem;
} // end setItem
ItemType PlainBox::getItem() const
{
return item;
} // end getItem