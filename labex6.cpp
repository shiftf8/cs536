//Lamog, Rob
//Lab Ex #6
//Hart
//09/30/13

#include <cmath>
#include <iostream>
#include <string>
using namespace std;

class StringStack{
public:
    static const unsigned STACK_SIZE = 5;
    StringStack();
    StringStack &push(string value);
    string pop();
    unsigned elements() const;
private:
    string data[STACK_SIZE];
    unsigned used;
};

class DoubleStack{
public:
    static const unsigned STACK_SIZE = 5;
    DoubleStack();
    DoubleStack &push(double value);
    double pop();
    unsigned elements() const;
private:
    double data[STACK_SIZE];
    unsigned used;
};

double evaluate();
bool die( const string & msg );

int main(){
    
    //system("pause");
    return 0;
} //main()

StringStack::StringStack(){
    used = 0;
}
StringStack &StringStack::push(string value){
    if (used == STACK_SIZE) die("Stack overflow.");
    data[used++] = value;
    return *this;
}
string StringStack::pop(){
    if (used == 0) die("Stack underflow.");
    return data[--used];
}
unsigned StringStack::elements() const{
    return used;
}

DoubleStack::DoubleStack(){
    used = 0;
}
DoubleStack &DoubleStack::push(double value){
    if (used == STACK_SIZE) die("Stack overflow.");
    data[used++] = value;
    return *this;
}
double DoubleStack::pop(){
    if (used == 0) die("Stack underflow.");
    return data[--used];
}
unsigned DoubleStack::elements() const{
    return used;
}

double evaluate(){
    DoubleStack oprnd;
    StringStack oprtr;
    string op;
    
    for(;;){
        char calcInput; // one of    #    !    .
        cin >> calcInput;
        switch(calcInput){
        case '#': // next token is a number
            cin >> a;
            oprnd.push(a);
            break;
        case '!': // next token is an operator
            cin >> op;
            if (op == "(") oprtr.push(op);
            if (op == "**") oprtr.push(op);
			if (op == "/"){
				b = oprnd.pop();
				a = oprnd.pop();
				oprnd.push(a/b);
				oprtr.push(op);
			}
			if (op == ")")
            break;                
        case '.':
            return oprnd.pop();
        } // switch
    } // for
} // evaluate

bool die( const string & msg ){
	//cerr <<endl <<"Fatal error: " <<msg << endl;
	//exit( EXIT_FAILURE );

	cout << endl << "Fatal error: " << msg << endl;
	return true;
}