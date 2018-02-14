#include <iostream>
#include "BTNode.h"
#include "EmployeeBST.h"

int main()
{
    Employee* alice = new Employee(100, "Alice");
    
    cout <<alice->getID() <<endl;
    
    return 0;
}