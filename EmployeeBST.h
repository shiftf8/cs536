#include <string>
#include <vector>

using namespace std;

class Employee
{
    private:
        int id;
        string name;
    
    public:
        Employee(int the_id, string the_name);
        
        int getID();
};

class BST
{
    private:
        
    public:
        Employee find(int id);
        // void insert(Employee emp);
        // void deleteEmployee(int key);
        // int size();
        // int height();
        // vector<Employee> inOrder();
};