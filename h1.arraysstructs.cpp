//Lamog, Rob
//h1.Arrays & Structs
//Hart
//08/26/13

#include <iostream>
#include <string>
using namespace std;

void show( const unsigned a[], unsigned elements );
bool isPermutation( const unsigned a[], unsigned elements );
void inverse( unsigned a[], const unsigned b[], unsigned elements );
bool sorted( const unsigned a[], unsigned elements );
void merge( unsigned combo[], const unsigned a[], unsigned aElements, const unsigned b[], unsigned bElements );

bool die( const string & msg );

int main(){
	unsigned a[] = {2, 4, 6, 8};
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
	unsigned g[9];
	merge(g, e, 5, f, 4);
	cout << endl;

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
	unsigned comboSize = 0; // not sure how to handle this exactly. prototype suggests main implements combo[] length.
	
	if (!sorted(a, aElements)) die("array a[] is not sorted or has no elements.");
	if (!sorted(b, bElements)) die("array b[] is not sorted or has no elements.");
	
	comboSize = aElements + bElements; // not sure how to handle this exactly. prototype suggests main implements combo[] length.
	
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
    			//cout << ", eoa: a" << combo[i];
    		    aCount++;
    		    continue;
    		}
    		if (bCount < bElements){
    		    combo[i] = b[bCount];
    			//cout << ", eoa: b" << combo[i];
    		    bCount++;
    		    continue;
    		}
		}
	}
}

bool die( const string & msg ){
	//cerr <<endl <<"Fatal error: " <<msg << endl;
	//exit( EXIT_FAILURE );

	cout << endl << "Fatal error: " << msg << endl;
	return true;
}
