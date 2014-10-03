//Lamog, Robert
//Homework #4
//Hart
//10/6/14

#include <iostream>
#include <string>
using namespace std;

class Queue{
public:
		// public static constant gives the array size
	static const unsigned MAX_SIZE = 5;
		// ctor initializes Queue object to represent an empty queue
		// by setting first and used to 0.
	Queue();
		// If the queue already has MAX_SIZE elements, c&d
		// Otherwise, add string to array and increment used,
		//     wrapping around if needed
		// Return reference to invoking object
	Queue & add( const string & s );
		// If the queue is empty, c&d
		// Otherwise, return the string at the front of the queue,
		//     modifying first and used appropriately
		//     (remember about wrap-around)
	string remove();
		// return # of elements in the queue that this object represents
	unsigned size() const;
private:
		// holds the actual strings in the queue
	string data[MAX_SIZE];
		// the index, in the data array, of the logically first element in
		//     queue being represented
	unsigned first;
		// # of strings in the queue being represented
	unsigned used;
}; // Queue

bool die( const string & msg );

int main() {
    Queue x;
    x.add("George").add("Washington").add("was").add("here.");
    cout <<endl;

    // x.add("BREAK!");

    x.remove();
    x.add("NOT!");
    cout <<endl;
    x.remove();
    x.add("Just kidding.");
    cout <<endl;
    x.remove();
    x.add("But seriously.");
    cout <<endl;
    x.remove();

    x.remove();
    x.remove();
    x.add("Would a man joke?").add("Or would he choke?");
    x.remove();
    x.add("How crazy is Hollywood?");
    x.remove();
    x.remove();

    x.remove();

    return 0;
} //main()

Queue::Queue() {
    first = 0;
    used = 0;
}
Queue & Queue::add( const string & s ) {
    unsigned i = 0;
    
    if (size() == MAX_SIZE - 1) die("Queue is already full.");

    i = (first + used) % MAX_SIZE;
    data[i] = s;
    used++;
    // cout << "+ " <<data[i] <<" / " << used <<endl;
    // for (unsigned j = 0; j < MAX_SIZE; j++) cout <<"+ " <<data[j] << " @ " <<j << "    ";
    // cout <<endl;
    
    return *this;
}
string Queue::remove() {
    string str;
    
    if (size() == 0) die("Queue is already empty.");
    
    str = data[first];
    if (first == MAX_SIZE - 1) first = 0;
    else first++;
    used--;
    // cout << " - " <<str <<" / " <<used <<endl;

    return str;
}
unsigned Queue::size() const {
    return used;
}

bool die( const string & msg ) {
    // cerr <<endl <<"Fatal error: " <<msg << endl;
    // exit( EXIT_FAILURE );

    cout << endl << "Fatal error: " << msg << endl;
    return true;
}