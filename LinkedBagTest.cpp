#include "LinkedBag.h"
#include <iostream>
#include <string>
#include <vector>

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
   LinkedBag bag;

   cout << "initial size = " << bag.getCurrentSize() << endl;

   cout << "is empty should be true: " << bag.isEmpty() << endl;

   bag.add("aa");
   bag.add("bb");
   bag.add("cc");
   bag.add("dd");
   bag.add("aa");

   cout << "current size should be 5: " << bag.getCurrentSize() << endl;
   cout << "is empty should be false: " << bag.isEmpty() << endl;
   cout << "there should be 2 'aa' nodes: " << bag.getFrequencyOf("aa") << endl;
   
   vector<string> v = bag.toVector();
   printVector(v);
   
   cout << "contains 'cc' should be true: " << bag.contains("cc") << endl;
   
   bag.remove("aa");
   bag.remove("cc");
   cout << "removed 'aa' and 'cc' - current size should be 3: " << bag.getCurrentSize() << endl;
      
   v = bag.toVector();
   printVector(v);

} // end main