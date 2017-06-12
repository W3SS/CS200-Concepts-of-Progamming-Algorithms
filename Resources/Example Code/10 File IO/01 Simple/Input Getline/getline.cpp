#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    // Using getline with cin

    string userText;
    cout << "Enter a line of text: ";
    getline( cin, userText );

    // Using getline with an ifstream
    string fileText;

    ifstream infile( "mytext.txt" );
    getline( infile, fileText );
    infile.close();

    cout << "Your text: " << endl << userText << endl;
    cout << "File text: " << endl << fileText << endl;

    return 0;
}


