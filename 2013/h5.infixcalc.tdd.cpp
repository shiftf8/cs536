//Lamog, Robert
//Homework #5
//Hart
//10/13/14

#include <cmath>
#include <iostream>
#include <sstream>
using namespace std;

template< typename T >
class Stack{
public:
    static const unsigned MAX_SIZE = 40;
    Stack();
    Stack & push( const T & item );
    T pop();
    T top();
    unsigned size() const;
    T myData[ MAX_SIZE ];
private:
    // T myData[ MAX_SIZE ];
    unsigned mySize;
};

bool calculator( double & result, const string & line );
bool balanced( const string & line );

bool die( const string & msg );

int main() {
    cout <<"Input an expression. Leave a blank line to quit. I'll analyze the tokens:" <<endl;
    
    for (string line; getline(cin, line) && line.size() > 0; ) {
        double answer;
        
        if(calculator(answer, line)) cout <<" " <<answer <<endl;
        else cout <<"    bogus" <<endl;
    }
    
    cout <<"Thanks for playing. Goodbye." <<endl;

    return 0;
}

template< typename T >
Stack<T>::Stack(): mySize(0) {}

template< typename T >
Stack<T> & Stack<T>::push( const T & item ) {
    if (mySize == MAX_SIZE) die("Stack::push: overflow.");
    myData[mySize++] = item;
    return *this;
}
template< typename T >
T Stack<T>::pop() {
    if (mySize == 0) die("Stack::pop: underflow.");
    return myData[--mySize];
}
template< typename T >
T Stack<T>::top() {
    if (mySize == 0) return myData[mySize];
    return myData[mySize - 1];
}
template< typename T >
unsigned Stack<T>::size() const {
    return mySize;
}

bool calculator( double & result, const string & line ) {
    Stack<double> doubleStack;
    Stack<string> operationStack;
    bool isExpectingNum = true;

    if (balanced(line)) {
        istringstream sin(line);
        for(string token; sin >>token; ) {
            double a, b, value;
            unsigned int operationPrecedence = 0;
            
            istringstream wordin(token); //quick and dirty is number check.
            
            if (!isExpectingNum) {
                if (wordin >>value) return false;
                if (token == "^") {
                    operationStack.push(token);
                    operationPrecedence = 2;
                    isExpectingNum = true;
                }
            }
            if (isExpectingNum) {
                if (wordin >>value) {
                    doubleStack.push(value);
                    isExpectingNum = false;
                } else if (token == "(") operationStack.push(token);
                else return false;

                if (operationStack.top() == "^") {
                    b = doubleStack.pop();
                    a = doubleStack.pop();
                    if (a >= 0) return false;
                    operationStack.pop();
                    result = pow(a, b);
                    doubleStack.push(result);
                }
            }
        }
    } else return false;
    
    // if(doubleStack.size() != 1/* || operationStack.size() > 0*/ || isExpectingNum == true) return false;
    // result = doubleStack.top();
    
    cout <<"Double stack: " <<doubleStack.size() <<endl;
    cout <<"Operation stack: " <<operationStack.size() <<endl;
    
    cout <<"Operation stack [ ";
    for (unsigned i = 0; i < operationStack.size(); i++) cout <<operationStack.myData[i] <<" ";
    cout <<"]" <<endl;
    
    return true;
}
bool balanced( const string & line ) {
    Stack<string> stackToCheck;
    
    for (unsigned i = 0; i < line.length(); i++) {
        if (line[i] == '(') stackToCheck.push("(");
        if (line[i] == ')') {
            if (stackToCheck.top() == "(") stackToCheck.pop();
            else return false;
        }
    }
    if (stackToCheck.size() == 0) return true;
    return false;
}

bool die( const string & msg ) {
    // cerr <<endl <<"Fatal error: " <<msg <<endl;
    // exit( EXIT_FAILURE );

    cout <<endl <<"Fatal error: " <<msg <<endl;
    return true;
}