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
//bool sorted( const unsigned a[], unsigned elements );

bool die( const string & msg );

int main(){
	unsigned a[] = {2, 4, 6, 8};
	show( a, 4 );

	unsigned b[] = {3, 0, 2, 1};
	bool boo = isPermutation( b, 4 );
	cout << boo << endl;

	inverse(a, b, 4);

	system("pause");
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
	bool foo = false;
	unsigned bar = 0;
	for (unsigned i = 0; i < elements; i++){
		for (unsigned j = 0; j < elements; j++){
			if (a[j] == i){
				foo = true;
				bar++;
			}
		}
		if ((foo = false) || (bar > 1)) return false;
	}
	return true;
}
void inverse( unsigned a[], const unsigned b[], unsigned elements ){
	if (!isPermutation(b, elements)) die("array b[] is not a permutation.");

}

bool die( const string & msg ){
	//cerr <<endl <<"Fatal error: " <<msg << endl;
	//exit( EXIT_FAILURE );

	cout << endl << "Fatal error: " << msg << endl;
	return true;
}
