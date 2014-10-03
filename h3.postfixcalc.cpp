//Lamog, Robert
//Homework #3
//Hart
//09/29/14

#include <iostream>
#include <math.h>
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
    string a[] = {"1.1	2.2	+", "1.1	2.2	+	+", "4	3	0	/	*", "1	2	3	4	sqrt	+	*	/"};
    
    for (int i = 0; i < 4; i++) (calculate(result, a[i])) ? cout <<result <<endl : cout <<"bogus" <<endl;

    return 0;
} //main()

Stack::Stack() {
    myData[ STACK_SIZE ];
    myElements = 0;
}
double Stack::pop() {
    if (myElements == 0) die("Stack underflow.");
    return myData[--myElements];
}
double Stack::top() const {
    if (myElements == 0) die("Stack underflow.");
    return myData[myElements - 1];
}
Stack & Stack::push( double item ) {
    if (myElements == STACK_SIZE) die("Stack overflow.");
    myData[myElements++] = item;
    return *this;
}
unsigned Stack::elements() const {
    return myElements;
}

bool calculate( double & result, const string & expression ) {
    Stack st;
    istringstream strin(expression);
    
    for (string token; strin >> token;) {
        double a, b, val;
        istringstream wordin(token);
        
        if (wordin >> val) st.push(val);
        //cout << st.elements() << endl;
        if (token == "*") {
            if (st.elements() <= 1) return false;
            b = st.pop();
            a = st.pop();
            result = a * b;
            st.push(result);
        }
        if (token == "/") {
            if ((st.elements() <= 1) || (st.top() == 0)) return false;
            b = st.pop();
            a = st.pop();
            result = a / b;
            st.push(result);
        }
        if (token == "+") {
            if (st.elements() <= 1) return false;
            b = st.pop();
            a = st.pop();
            result = a + b;
            st.push(result);
        }
        if (token == "-") {
            if (st.elements() <= 1) return false;
            b = st.pop();
            a = st.pop();
            result = a - b;
            st.push(result);
        }
        if (token == "sqrt") {
            if ((st.elements() < 1) || (st.top() < 0)) return false;
            result = sqrt(st.pop());
            st.push(result);
        }
    }
    
    if (st.elements() == 1) return true;
    return false;
}

bool die( const string & msg ) {
    //cerr <<endl <<"Fatal error: " <<msg << endl;
    //exit( EXIT_FAILURE );

    cout << endl << "Fatal error: " << msg << endl;
    return true;
}
