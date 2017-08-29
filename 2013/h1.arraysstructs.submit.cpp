//Lamog, Robert
//Arrays & Structs
//Hart
//09/14/14

#include<iostream>
#include<string>
using namespace std;

//I defined struct ABC arr length to nArr to better test how robust my functions are
#define nArr 3

struct ABC{
    unsigned n;
    char c;
    double a[nArr]; // is this ok, to have an array inside a struct? Absolutely!!
};

void show( const unsigned a[], unsigned elements );
bool isPermutation( const unsigned a[], unsigned elements );
void inverse( unsigned a[], const unsigned b[], unsigned elements );
bool sorted( const unsigned a[], unsigned elements );
void merge( unsigned combo[], const unsigned a[], unsigned aElements, const unsigned b[], unsigned bElements );
unsigned long long sum( const unsigned a[], unsigned elements, unsigned f( unsigned n ) );
unsigned cube( unsigned n );

void show( const ABC & x );
void show( const ABC arr[], unsigned elements );
double max( const ABC & x );
double max( const ABC arr[], unsigned elements );
void set( ABC & x, unsigned n, char c, const double a[nArr] );
void get( unsigned & n, char & c, double a[nArr], const ABC & x );
void set( ABC x[], const unsigned n[], const char c[], const double a[][nArr], unsigned elements );
void get( unsigned n[], char c[], double a[][nArr], const ABC x[], unsigned elements );

bool die( const string & msg );

int main(){

    //system("pause");
    return 0;
} //main()

void show( const unsigned a[], unsigned elements ){
    cout << "[" << elements << "]: ";
    for (unsigned i = 0; i < elements; i++){
        cout << a[i];
        if (i != elements - 1) cout << ", ";
    }
    cout << endl;
}
//isPermutation will only return false the first instant there is no longer a valid permutation.
bool isPermutation( const unsigned a[], unsigned elements ){
    bool isPerm = false;
    unsigned isDup = 0;
    for (unsigned i = 0; i < elements; i++){
        for (unsigned j = 0; j < elements; j++){
            if (a[i] == j) isPerm = true;
            if (a[i] == a[j]) isDup++;
        }
        if ((!isPerm) || (isDup > 1)) return false;
        isPerm = false;
        isDup = 0;
    }
    return true;
}
void inverse( unsigned a[], const unsigned b[], unsigned elements ){
    if (!isPermutation(b, elements)) die("array b[] is not a permutation.");
    for (unsigned i = 0; i < elements; i++){
        for (unsigned j = 0; j < elements; j++){
            if (b[i] == j) a[j] = i;
        }
    }
}
//sorted only returns true once all elements are determined to be sorted.
bool sorted( const unsigned a[], unsigned elements ){
    if (elements == 0) return true; //an array 0 elements is still an array
    for (unsigned i = 0; i < elements; i++){
        if (i == elements - 1) return true;
        if (a[i] > a[i + 1]) return false;
    }
    return false;
}
void merge( unsigned combo[], const unsigned a[], unsigned aElements, const unsigned b[], unsigned bElements ){
    unsigned aCount = 0;
    unsigned bCount = 0;
    bool endOfArr = false;
    unsigned comboSize = 0;

    if (!sorted(a, aElements)) die("array a[] is not sorted.");
    if (!sorted(b, bElements)) die("array b[] is not sorted.");

    if (aElements == 0 || bElements == 0) endOfArr = true;
    comboSize = aElements + bElements; // prototype suggests main implements combo[] length. this could be problematic should a plus b elements create overflow.

    for (unsigned i = 0; i < comboSize; i++){
        if ((aCount < aElements) && (bCount < bElements)){
            if (a[aCount] > b[bCount]){
                combo[i] = b[bCount];
                //cout << ", b" << combo[i];
                bCount++;
                if (bCount == bElements) endOfArr = true;
            } else {
                combo[i] = a[aCount];
                //cout << ", a" << combo[i];
                aCount++;
                if (aCount == aElements) endOfArr = true;
            }
        }
        if (endOfArr){
            if (aCount < aElements){
                combo[i] = a[aCount];
                //cout << ", eor: a" << combo[i];
                aCount++;
                continue;
            }
            if (bCount < bElements){
                combo[i] = b[bCount];
                //cout << ", eor: b" << combo[i];
                bCount++;
                continue;
            }
        }
    }
}
unsigned long long sum( const unsigned a[], unsigned elements, unsigned f( unsigned n ) ){
    unsigned long long total = 0;

    for (unsigned i = 0; i < elements; i++){
        total += f(a[i]);
    }
    return total;
}
unsigned cube( unsigned n ){
    return n * n * n;
}

void show( const ABC & x ){
    cout << "{" << x.n << ", \'" << x.c << "\', {";
    for (unsigned i = 0; i < nArr; i++){
        cout << x.a[i];
        if (i != nArr - 1) cout << ", ";
    }
    cout << "}}" << endl;
}
void show( const ABC arr[], unsigned elements ){
    for (unsigned i = 0; i < elements; i++) show(arr[i]);
}
double max( const ABC & x ){
    double maxInABC;
    maxInABC = x.a[0]; // I failed to notice lowest value could be negative. /*solved*/

    for (unsigned i = 0; i < nArr; i++){
        if (x.a[i] > maxInABC) maxInABC = x.a[i];
    }
    return maxInABC;
}
double max( const ABC arr[], unsigned elements ){
    double maxInABCs;
    maxInABCs = max(arr[0]); // I failed to notice lowest value could be negative. /*solved*/

    for (unsigned i = 0; i < elements; i++){
        if (max(arr[i]) > maxInABCs) maxInABCs = max(arr[i]);
    }
    return maxInABCs;
}
void set( ABC & x, unsigned n, char c, const double a[nArr] ){
    x.n = n;
    x.c = c;
    for (unsigned i = 0; i < nArr; i++) x.a[i] = a[i];
}
void get( unsigned & n, char & c, double a[nArr], const ABC & x ){
    n = x.n;
    c = x.c;
    for (unsigned i = 0; i < nArr; i++) a[i] = x.a[i];
}
void set( ABC x[], const unsigned n[], const char c[], const double a[][nArr], unsigned elements ){
    for (unsigned i = 0; i < elements; i++){
        set(x[i], n[i], c[i], a[i]);
    }
}
void get( unsigned n[], char c[], double a[][nArr], const ABC x[], unsigned elements ){
    for (unsigned i = 0; i < elements; i++){
        n[i] = x[i].n;
        c[i] = x[i].c;
        for (unsigned j = 0; j < nArr; j++){
            a[i][j] = x[i].a[j];
        }
    }
}

bool die( const string & msg ){
    cerr <<endl <<"Fatal error: " <<msg << endl;
    exit( EXIT_FAILURE );

    //cout << endl << "Fatal error: " << msg << endl;
    //return true;
}
