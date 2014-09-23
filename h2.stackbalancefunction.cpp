//Lamog, Robert
//Homework #2
//Hart
//09/22/14

#include <iostream>
#include <string>
using namespace std;

#define STACK_SIZE 8

struct Stack{
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

int main() {
    string a[] = {"(sldkj[slkdfjk{slkdfjsl(sldkjf(lkjsd)slkdfj)sldkfj}slkdjf]sldkfj)", "(((([[[[]]]]{{{{}}}}))))", "([)]", ""};
    
    for (int i = 0; i < 4; i++) cout << ((balanced(a[i])) ? "Balanced" : "NOT Balanced") << endl;

    //system("pause");
    return 0;
} //main()

void initialize( Stack & stack ) {
    stack.elements = 0;
}
string pop( Stack & stack ) {
    if (stack.elements == 0) die("stack underflow");
    return stack.data[--stack.elements];
}
string top( const Stack & stack ) {
    if (stack.elements == 0) die("stack underflow");
    return stack.data[stack.elements - 1];
}
void push( Stack & stack, const string & item ) {
    if (stack.elements == STACK_SIZE) die("stack overflow");
    stack.data[stack.elements++] = item;
}
unsigned elements( const Stack & stack ) {
    return stack.elements;
}

bool balanced( const string & line ) {
    Stack stackToCheck;
    
    initialize(stackToCheck);
    for (unsigned i = 0; i < line.length(); i++) {
        if (line[i] == '(') push(stackToCheck, "(");
        if (line[i] == '[') push(stackToCheck, "[");
        if (line[i] == '{') push(stackToCheck, "{");
        if (line[i] == ')') {
            if (top(stackToCheck) == "(") pop(stackToCheck);
            else return false;
        }
        if (line[i] == ']') {
            if (top(stackToCheck) == "[") pop(stackToCheck);
            else return false;
        }
        if (line[i] == '}') {
            if (top(stackToCheck) == "{") pop(stackToCheck);
            else return false;
        }
    }
    if (elements(stackToCheck) == 0) return true;
    return false;
}

bool die( const string & msg ) {
	//cerr <<endl <<"Fatal error: " <<msg << endl;
	//exit( EXIT_FAILURE );

	cout << endl << "Fatal error: " << msg << endl;
	return true;
}
