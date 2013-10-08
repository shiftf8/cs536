//Lamog, Rob
//Lab Ex #7 Queue
//Hart
//10/07/13

#include <iostream>
#include <string>
using namespace std;

class Queue{
public:
    Queue();
    Queue & add( const string & s );
    string remove();
    unsigned getUsed() const;
private:
    string data[5];
    unsigned first;
    unsigned used;
}; // Queue

bool die( const string & msg );

int main(){
    Queue a = Queue();
    cout << a.getUsed() << endl;
    
    a.add("a");
    cout << a.remove() << endl;
    a.add("b");
    a.add("c");
    a.add("d");
    a.add("e");
    a.add("f");
    //a.add("break");
    cout << a.getUsed() << endl;
    cout << a.remove() << endl;
    
    //system("pause");
    return 0;
} //main()

Queue::Queue(){
    first = 0;
    used = 0;
}
Queue &Queue::add( const string & s ){
    if (used == 5) die("Queue overflow.");

    data[(first + 1) % 5] = s;
    used++;
    return *this;
}
string Queue::remove(){
    if (used == 0) die("Queue underflow.");

    string out = data[first];
    first = (first + 1) % 5;
    used--;
    return out;
}
unsigned Queue::getUsed() const{
    return used;
}

bool die( const string & msg ){
	//cerr <<endl <<"Fatal error: " <<msg << endl;
	//exit( EXIT_FAILURE );

	cout << endl << "Fatal error: " << msg << endl;
	return true;
}