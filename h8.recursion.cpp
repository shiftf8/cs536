//Lamog, Robert
//Homework #8
//Hart
//11/13/14

#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

unsigned triangle( unsigned n );
unsigned multiply( unsigned a, unsigned b );
unsigned add( unsigned a, unsigned b );
unsigned max( const unsigned a[], unsigned els );
unsigned fib( unsigned n );

bool die( const string & msg );

int main() {
    cout <<triangle(11) <<endl;
    cout <<multiply(5, 11) <<endl;
    cout <<add(21, 23) <<endl;
    unsigned a[5] = {1, 2, 3, 4, 5};
    unsigned b[3] = {6, 4, 2};
    unsigned c[1] = {0};
    unsigned e[11] = {11, 69, 26, 1, 2, 9, 6, 8, 3, 5, 6}; //I'm convinced my vm can't handle this recursion past arr[5]
    cout <<max(a, 5) <<endl;
    cout <<max(b, 3) <<endl;
    cout <<max(c, 1) <<endl;
    cout <<max(e, 3) <<endl;
    
    return 0;
}

unsigned triangle( unsigned n ) {
    if (n == 0) return 0;
    return n + triangle(n - 1);
}
unsigned multiply( unsigned a, unsigned b ) {
    if (b == 0) return 0;
    return a + multiply(a, --b);
}
unsigned add( unsigned a, unsigned b ) {
    if (b == 0) return a;
    return add(++a, --b);
}
unsigned max( const unsigned a[], unsigned els ) {
    if (els == 1) return a[0];
    
    unsigned largestElement = max(a, els - 1);
    return a[els - 1] > largestElement ? a[els - 1] : largestElement;
}
unsigned fib( unsigned n );

bool die( const string & msg ) {
    cerr <<endl <<"Fatal error: " <<msg <<endl;
    exit( EXIT_FAILURE );
    
    // cout <<endl <<"Fatal error: " <<msg <<endl;
    // return true;
}
