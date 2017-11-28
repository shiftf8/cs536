#include "Employee.h"

Employee::Employee(int the_id, string the_name) : id(the_id), name(the_name)
{
}
void Employee::setID(int the_id)
{
    id = the_id;
}