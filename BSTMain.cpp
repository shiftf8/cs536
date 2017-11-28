#include <iostream>
#include "BTNode.cpp"
#include "EmployeeBST.cpp"

int main()
{
    Employee* alice = new Employee(100, "Alice");
    
    cout <<alice->getID() <<endl;
    
    return 0;
}