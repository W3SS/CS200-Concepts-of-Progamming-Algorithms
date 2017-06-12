#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <iomanip>
using namespace std;

string CleanString( const string& value );

int main()
{
    ifstream input( "frankenstein.txt" );
    string buffer;
    map<string, int> wordCounter;

    int wordCount = 0;
    while ( input >> buffer )
    {
        buffer = CleanString( buffer );
        if ( buffer == "" ) { continue; }

        if ( wordCounter.find( buffer ) == wordCounter.end() )
        {
            wordCounter[ buffer ] = 1;
        }
        else
        {
            wordCounter[ buffer ] += 1;
        }

        wordCount++;
    }

    cout << wordCount << " total words" << endl;
    cout << wordCounter.size() << " unique words" << endl;

    input.close();

    ofstream output( "analyze.txt" );

    for ( map<string, int>::iterator it = wordCounter.begin();
            it != wordCounter.end(); it++ )
    {
        output << setw( 20 ) << it->first << setw( 20 ) << it->second << endl;
    }

    output.close();

    return 0;
}

string CleanString( const string& value )
{
    string cleanWord = "";
    for ( int i = 0; i < value.size(); i++ )
    {
        char character = toupper( value[i] );
        int code = int( character );

        if ( code >= 65 && code <= 90 )
        {
            cleanWord += character;
        }
    }
    return cleanWord;
}


