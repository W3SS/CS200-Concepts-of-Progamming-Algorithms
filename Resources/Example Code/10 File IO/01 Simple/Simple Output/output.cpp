#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    string word;
    ofstream output( "Hello.txt" );

    while ( true )
    {
        cout << "Enter a word: ";
        cin >> word;

        cout << word << endl;
        output << word << endl;
    }

    output.close();

    return 0;
}
