#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    string alphabet[] = { "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z" };
    int key;

    ifstream input;
    input.open( "encode_me.txt" );

    ofstream output;
    output.open( "encrypted.txt" );

    cout << "Enter encryption key: ";
    cin >> key;
    output << "KEY " << key << endl;

    string word;
    // Read each word
    while ( input >> word )
    {
        // Read each letter
        for ( int i = 0; i < word.size(); i++)
        {
            int letterCode = int( word[i] ) - 26;
            letterCode += key;
            letterCode = letterCode % 26;
            output << alphabet[ letterCode ];
        }
        output << " ";
    }

    output.close();
    input.close();
}
