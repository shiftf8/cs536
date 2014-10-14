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
    static const unsigned MAX_SIZE = 4;
    Stack();
    Stack & push( const T & item );
    T pop();
    unsigned size() const;
private:
    T myData[ MAX_SIZE ];
    unsigned mySize;
};

bool calculate( double & result, const string & line );
bool parse( double & result, const string & token );

bool die( const string & msg );

int main() {
    cout <<"Input an expression. Leave a blank line to quit. I'll analyze the tokens:" <<endl;
    
    for (string line; getline(cin, line) && line.size() > 0; ) {
        double answer;
        
        if(calculate(answer, line)) cout <<" " <<answer <<endl;
        else cout <<"    bogus" <<endl;
    }
    
    cout <<"Thanks for playing. Goodbye.\n" <<endl;

    return 0;
}

template< typename T >
Stack<T>::Stack(): mySize(0) {}

template< typename T >
Stack<T> & Stack<T>::push( const T & item ) {
    if(mySize == MAX_SIZE) die("Stack::push: overflow.");
    myData[mySize++] = item;
    return *this;
}
template< typename T >
T Stack<T>::pop() {
    if(mySize == 0) die("Stack::pop: underflow.");
    return myData[--mySize];
}
template< typename T >
unsigned Stack<T>::size() const {
    return mySize;
}

bool calculate( double & result, const string & line ) {
    Stack<double> doubleStack;
    Stack<string> operationStack;
    bool isExpectingNum = true;

    istringstream sin(line);
    for(string token; sin >>token; ) {
        double value;
        
            if (parse(value, token)) {
                doubleStack.push(value); // this might c&d
                isExpectingNum = false;
            } else if (token == "(") operationStack.push(token);

            if (token == "^" || token == "*" || token == "/" || token == "+" || token == "-" || token == ")") {
                operationStack.push(token);
                isExpectingNum = true;
            }
    }
    
    // if(doubleStack.size() != 1) return false;
    result = doubleStack.pop();
    
    return true;
}
bool parse( double & result, const string & token ) {
    istringstream sin(token);
    
    double t;
    sin >>t; // we hope this input succeeds
    if(!sin) return false;
    char junk;
    sin >>junk; // we hope this input fails
    if(sin) return false;
    result = t;
    return true;
}

bool die( const string & msg ) {
    // cerr <<endl <<"Fatal error: " <<msg << endl;
    // exit( EXIT_FAILURE );

    cout << endl << "Fatal error: " << msg << endl;
    return true;
}