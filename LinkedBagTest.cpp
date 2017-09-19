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
   LinkedBag bag, bag1, bag2, bag3, bag4;

   // cout << "initial size = " << bag.getCurrentSize() << endl;

   // cout << "is empty should be true: " << bag.isEmpty() << endl;

   // bag.add("aa");
   // bag.add("bb");
   // bag.add("cc");
   // bag.add("dd");
   // bag.add("aa");

   // cout << "current size should be 5: " << bag.getCurrentSize() << endl;
   // cout << "is empty should be false: " << bag.isEmpty() << endl;
   // cout << "there should be 2 'aa' nodes: " << bag.getFrequencyOf("aa") << endl;
   
   // vector<string> v = bag.toVector();
   // printVector(v);
   
   // cout << "contains 'cc' should be true: " << bag.contains("cc") << endl;
   
   // bag.remove("aa");
   // bag.remove("cc");
   // cout << "removed 'aa' and 'cc' - current size should be 3: " << bag.getCurrentSize() << endl;
      
   // v = bag.toVector();
   // printVector(v);
   
   bag1.add("1"), bag1.add("2"), bag1.add("2"), bag1.add("3"), bag1.add("3"), bag1.add("3"), bag1.add("4"),
   bag1.add("4"), bag1.add("4"), bag1.add("4"), bag1.add("5"), bag1.add("5"), bag1.add("5"), bag1.add("5"), 
   bag1.add("5");
   
   bag2.add("6"), bag2.add("6"), bag2.add("7"), bag2.add("7"), bag2.add("7");
   
   bag3.add("2"), bag3.add("3"), bag3.add("4"), bag3.add("4"), bag3.add("5"), bag3.add("6"), bag3.add("7");
   
   bag4.add("2"), bag4.add("3"), bag4.add("3"), bag4.add("4"), bag4.add("4"), bag4.add("4"), bag4.add("4"),
   bag4.add("5");
   
   fprintf(stdout, "bag1: ");
   vector<string> v = bag1.toVector();
   printVector(v);
   
   fprintf(stdout, "bag1 union bag2: ");
   v = bag1.unionBag(bag2).toVector();
   printVector(v);
   
   fprintf(stdout, "bag1 inter bag3: ");
   v = bag1.intersection(bag3).toVector();
   printVector(v);

   fprintf(stdout, "bag1 diff bag4: ");
   v = bag1.difference(bag4).toVector();
   printVector(v);
} // end main