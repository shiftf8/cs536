//Lamog, Robert
//Homework #3
//Hart
//09/29/14

#include <iostream>
#include <sstream>
using namespace std;

#define STACK_SIZE 8

class Stack{
public:
	Stack(); // ctor corresponds to last week's initialize function
	double pop(); // c&d (complain and die) on underflow
	double top() const; // c&d on underflow
	Stack & push( double item ); // return reference to self (*this)
	unsigned elements() const; // returns some # in the range [0, STACK_SIZE]
private:
	// data corresponds to last week's assignment, but now it's private
	double myData[ STACK_SIZE ];
	unsigned myElements;
}; // class Stack

bool calculate( double & result, const string & expression );

bool die( const string & msg );

int main() {
    double result = 0.0;
    string expression = "1.1 2.2 +";
    
    calculate(result, expression);
    
    return 0;
} //main()

Stack::Stack(){
    myData[ STACK_SIZE ];
    myElements = 0;
}
double Stack::pop(){
    if (myElements == 0) die("stack underflow.");
    return myData[--myElements];
}
double Stack::top() const {
    if (myElements == 0) die("stack underflow.");
    return myData[myElements - 1];
}
Stack & Stack::push( double item ) {
    if (myElements == STACK_SIZE) die("stack overflow.");
    myData[myElements++] = item;
}
unsigned Stack::elements() const {
    return myElements;
}

bool calculate( double & result, const string & expression ){
    Stack st;
    istringstream sin(expression);
    
    for (string token; sin >> token;) {
        double val;
        
        if (sin >> val) st.push(val);
        cout << st.elements() << endl;
    }
    
    return false;
}

bool die( const string & msg ) {
	//cerr <<endl <<"Fatal error: " <<msg << endl;
	//exit( EXIT_FAILURE );

	cout << endl << "Fatal error: " << msg << endl;
	return true;
}