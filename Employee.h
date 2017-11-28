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
        
        void setID(int the_id);
};