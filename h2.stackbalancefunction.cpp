//Lamog, Robert
//Homework #2
//Hart
//09/22/14

#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

#define STACK_SIZE 5

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
bool isLeftParenChecker( const char & c);

bool die( const string & msg );

int main() {
    string something = "((((((((((((((((((((((";
    
    balanced(something);
    //system("pause");
    return 0;
} //main()

void initialize( Stack & stack ) {
    stack.elements = 0;
}
string pop( Stack & stack ) {
    if (stack.elements == 0) die("stack underflow");
    return stack.data[stack.elements--];
}
string top( const Stack & stack ) {
    if (stack.elements == 0) die("stack underflow");
    return stack.data[stack.elements];
}
void push( Stack & stack, const string & item ) {
    if (stack.elements == STACK_SIZE) die("stack overflow");
    stack.data[++stack.elements] = item;
}
unsigned elements( const Stack & stack ) {
    return stack.elements;
}

bool balanced( const string & line ) {
    Stack stackToCheck;
    bool leftFlag = false;
    int i = 0;
    char c;
    string leftSide;

    while (c != EOF) {
        c = line[i];
        if (isLeftParenChecker(c)) {
            leftSide = c;
            push(stackToCheck, leftSide);
        }
        i++;
    }
}

bool isLeftParenChecker( const char & c) {
    char leftParens[3] = {'(', '[', '{'};
    
    for (unsigned i = 0; i < 3; i++) if (leftParens[i] == c) return c;
    return false;
}

bool die( const string & msg ) {
	//cerr <<endl <<"Fatal error: " <<msg << endl;
	//exit( EXIT_FAILURE );

	cout << endl << "Fatal error: " << msg << endl;
	return true;
}
