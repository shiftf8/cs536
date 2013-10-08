//Lamog, Rob
//Lab Exercise #3
//Hart
//09/09/13

//#include<climits>
#include<iostream>
#include<string>
using namespace std;

const unsigned STACK_SIZE = 10;

struct Stack{
	double data[ STACK_SIZE ];
	unsigned used;
};

void initialize( Stack & s );
void assign( Stack & lhs, const Stack & rhs );
bool ok( const Stack & s );
double sum( const Stack & s );
void show( const Stack & s );
void push ( Stack & s, double value );
double pop( Stack & s );

bool die( const string & msg );

int main(){
    Stack a;
    initialize(a);
    
    Stack b = {{1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9, 10.10}, 3};
    Stack c;
    assign(c, b);
    
    //cout << ok(b) << endl;
    
    //cout << sum(b) << endl;
    
    //show(b);
    
    //push(b, -1234.4321);
    //show(b);
    
    cout << pop(b) << endl;

    //system("pause");
    return 0;
} //main()

void initialize( Stack & s ){
    s.used = 0;
    //cout << s.used << endl;
}
void assign( Stack & lhs, const Stack & rhs ){
/*    for (unsigned i = 0; i < STACK_SIZE; i++){
        lhs.data[i] = rhs.data[i];
        
        //cout << lhs.data[i];
        //if (i != STACK_SIZE - 1) cout << ", ";
    }
    //cout << endl;
    lhs.used = rhs.used;
    //cout << lhs.used << endl;
*/    
    lhs = rhs;    
}
bool ok( const Stack & s ){
/*    if (s.used <= STACK_SIZE) return true;
    return false;
*/
    return s.used <= STACK_SIZE;
}
double sum( const Stack & s ){
    double sumTotal;
    
    for (unsigned i = 0; i < s.used; i++) sumTotal += s.data[i];
    return sumTotal;
}
void show( const Stack & s ){
    for (unsigned i =0; i < s.used; i++){
        cout << s.data[i];
        if (i != s.used - 1) cout << ", ";
    }
    cout << endl;
}
void push ( Stack & s, double value ){
    if (s.used == STACK_SIZE) die("struct is already full. Not enough room to push element."); //push: overflow
    s.data[s.used++] = value;
}
double pop( Stack & s ){
    if (s.used == 0) die("struct has no elements to pop."); //pop: underflow
    return s.data[--s.used];
}

bool die( const string & msg ){
    //cerr << endl << "Fatal error: " << msg << endl;
    //exit( EXIT_FAILURE );
    
    cout << endl << "Fatal error: " << msg << endl;
    return true;
}