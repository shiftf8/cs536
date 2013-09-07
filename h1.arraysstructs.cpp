//Lamog, Rob
//h1.Arrays & Structs
//Hart
//08/26/13

#include <iostream>
#include <string>
using namespace std;

#define nArr 3
struct ABC{
    unsigned n;
    char c;
    double a[nArr]; // is this ok, to have an array inside a struct? Absolutely!!
};

void show( const ABC & x );
void show( const ABC arr[], unsigned elements );
double max( const ABC & x );
double max( const ABC arr[], unsigned elements );
void set( ABC & x, unsigned n, char c, const double a[nArr] );
void get( unsigned & n, char & c, double a[nArr], const ABC & x );
void set( ABC x[], const unsigned n[], const char c[], const double a[][nArr], unsigned elements );
void get( unsigned n[], char c[], double a[][nArr], const ABC x[], unsigned elements );

void show( const unsigned a[], unsigned elements );
bool isPermutation( const unsigned a[], unsigned elements );
void inverse( unsigned a[], const unsigned b[], unsigned elements );
bool sorted( const unsigned a[], unsigned elements );
void merge( unsigned combo[], const unsigned a[], unsigned aElements, const unsigned b[], unsigned bElements );
unsigned long long sum( const unsigned a[], unsigned elements, unsigned f( unsigned n ) );
unsigned cube( unsigned n );

bool die( const string & msg );

int main(){
/*	unsigned a[] = {2, 4, 6, 8};
	show( a, 4 );

	unsigned b[] = {3, 0, 2, 1};
	bool boo = isPermutation( b, 4 );
	cout << boo << endl;

	inverse(a, b, 4);
	show(a, 4);
	
	unsigned c[] = {1, 5, 5, 7};
	unsigned d[] = {1, 5, 3, 7};
	cout << sorted(c, 4) << endl;
	cout << sorted(d, 4) << endl;
	
	unsigned e[] = {3, 5, 7, 7, 9};
	unsigned f[] = {2, 5, 8, 1234};
	unsigned g[100];
	merge(g, e, 1, f, 4);
	cout << endl;

    unsigned h[] = {3, 5, 2, 1};
    cout << sum(h, 4, cube);
*/
    ABC struct1 = {18, 'W', {1.1, 2.2, 3.3}};
//    show(struct1);
    
    ABC struct2 = {123, 'A', {1.1, 2.2, 3.3}};
    ABC struct3 = {234, 'B', {2.1, 2.2, 2.3}};
    ABC struct4 = {345, 'C', {3.1, 3.2, 3.3}};
    ABC struct5 = {456, 'D', {4.1, 4.2, 4.3}};
    ABC arr1[4] = {struct2, struct3, struct4, struct5};
//    show(arr1, 4);

//    cout << max(struct1) << endl;
//    cout << max(arr1, 4) << endl;
    
    ABC struct6;
    double doubleArr[3] = {10.0, 20.0, 30.0};
    set(struct6, 1234, '?', doubleArr);
//    show(struct6);
    double doubleArr1[3];
    unsigned n;
    char c;
    get(n, c, doubleArr1, struct6);
    
    ABC arr2[4];
    unsigned e[4] = {111, 222, 333, 444};
    char f[4] = {'z', 'y', 'X', 'W'};
    double g[4][nArr] = {
        {1.1, 2.2, 3.3},
        {2.1, 2.2, 2.3},
        {3.1, 3.2, 3.3},
        {4.1, 4.2, 4.3}
    };
    set(arr2, e, f, g, 4);
    
    ABC struct10 = {45, '!', {4.1, 4.2, 4.3}};
    ABC struct7 = {34, '@', {3.1, 3.2, 3.3}};
    ABC struct8 = {23, '#', {2.1, 2.2, 2.3}};
    ABC struct9 = {12, '$', {1.1, 2.2, 3.3}};
    ABC arr3[4] = {struct10, struct7, struct8, struct9};
    unsigned h[4];
    char i[4];
    double j[4][nArr];
    get(h, i, j, arr3, 4);
    
	//system("pause");
	return 0;
} //main()

void show( const unsigned a[], unsigned elements ){
	cout << "[" << elements << "]: ";
	for (unsigned i = 0; i < elements; i++){
		cout << a[i];
		if (i == elements - 1) cout << endl;
		else cout << ", ";
	}
}
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
bool sorted( const unsigned a[], unsigned elements ){
	if (elements == 0) return true;
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
	comboSize = aElements + bElements; // prototype suggests main implements combo[] length. this could be problematic should a plus b elements be larger than combo[] size.
	
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
    double maxInABC = 0.0;
    
    for (unsigned i = 0; i < nArr; i++){
        if (x.a[i] > maxInABC) maxInABC = x.a[i];
    }
    return maxInABC;
}
double max( const ABC arr[], unsigned elements ){
    double maxInABCs = 0.0;
    
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
    
/*    //test code
    cout << "{" << n << ", \'" << c << "\', {";
    for (unsigned j = 0; j < nArr; j++){
        cout << x.a[j];
        if (j != nArr - 1) cout << ", ";
    }
    cout << "}}" << endl;
*/
}
void set ( ABC x[], const unsigned n[], const char c[], const double a[][nArr], unsigned elements ){
    for (unsigned i = 0; i < elements; i++){
        set(x[i], n[i], c[i], a[i]);

/*        //test code
        cout << "{" << x[i].n << ", \'" << x[i].c << "\', {";
        for (unsigned j = 0; j < nArr; j++){
            cout << x[i].a[j];
            if (j != nArr - 1) cout << ", ";
        }
        cout << "}}" << endl;
*/
    }
}
void get( unsigned n[], char c[], double a[][nArr], const ABC x[], unsigned elements ){
    for (unsigned i = 0; i < elements; i++){
        n[i] = x[i].n;
        c[i] = x[i].c;
        for (unsigned j = 0; j < nArr; j++){
            a[i][j] = x[i].a[j];
        }

        //test code
        cout << "{" << x[i].n << ", \'" << x[i].c << "\', {";
        for (unsigned j = 0; j < nArr; j++){
            cout << x[i].a[j];
            if (j != nArr - 1) cout << ", ";
        }
        cout << "}}" << endl;
/**/
    }
}

bool die( const string & msg ){
	//cerr <<endl <<"Fatal error: " <<msg << endl;
	//exit( EXIT_FAILURE );

	cout << endl << "Fatal error: " << msg << endl;
	return true;
}
