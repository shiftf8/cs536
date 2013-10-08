//Lamog, Rob
//Homework #3
//Hart
//09/16/13

#include <iostream>
#include <string>
using namespace std;

struct Stack{
    static const STACK_SIZE = 5;
    string data[ STACK_SIZE ];
	unsigned elements;
};	//	struct Stack

void initialize( Stack & stack );
string pop( Stack & stack );
string top( const Stack & stack );
void push( Stack & stack, const string & item );
unsigned elements( const Stack & stack );

bool balanced( const string & line );

bool die( const string & msg );

int main(){
    
    //system("pause");
    return 0;
} //main()

void initialize( Stack & stack ){
    stack.elements = 0;
}
string pop( Stack & stack ){
    if (stack.elements == 0) die("stack underflow");
    return stack.data[stack.elements--];
}
string top( const Stack & stack ){
    if (stack.elements == 0) die("stack underflow");
    return stack.data[stack.elements];
}
void push( Stack & stack, const string & item ){
    if (stack.elements == STACK_SIZE) die("stack overflow");
    stack.data[++stack.elements] = item;
}
unsigned elements( const Stack & stack ){
    return stack.elements;
}

bool balanced( const string & line ){
    
}

bool die( const string & msg ){
	//cerr <<endl <<"Fatal error: " <<msg << endl;
	//exit( EXIT_FAILURE );

	cout << endl << "Fatal error: " << msg << endl;
	return true;
}
