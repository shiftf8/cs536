//Lamog, Robert
//Homework #4
//Hart
//10/6/14

bool die( const string & msg );

int main() {
    return 0;
} //main()

bool die( const string & msg ) {
    //cerr <<endl <<"Fatal error: " <<msg << endl;
    //exit( EXIT_FAILURE );

    cout << endl << "Fatal error: " << msg << endl;
    return true;
}