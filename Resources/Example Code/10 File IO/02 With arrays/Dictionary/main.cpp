#include <iostream>
#include <fstream>
#include <map>
#include <string>
using namespace std;

void LoadDictionaries( map<string, string>& en_to_eo, map<string, string>& eo_to_en );

int main()
{
    map<string, string> en_to_eo;
    map<string, string> eo_to_en;

    LoadDictionaries( en_to_eo, eo_to_en );

    bool done = false;
    while ( !done )
    {
        cout << endl << "--------------------" << endl;
        cout << "1. English to Esperanto" << endl;
        cout << "2. Esperanto to English" << endl;
        cout << "3. Quit" << endl;
        int choice;
        cin >> choice;

        if ( choice == 1 )
        {
            string word;
            cout << "English word: ";
            cin >> word;
            cout << "Translation: " << en_to_eo[ word ] << endl;
        }
        else if ( choice == 2 )
        {
            string word;
            cout << "Esperanto word: ";
            cin >> word;
            cout << "Translation: " << eo_to_en[ word ] << endl;
        }
        else if ( choice == 3 )
        {
            done = true;
        }
    }

    return 0;
}

void LoadDictionaries( map<string, string>& en_to_eo, map<string, string>& eo_to_en )
{
    string english, esperanto;
    ifstream infile( "wordlist.txt" );

    // Skip first two items
    infile >> english >> esperanto;

    while ( infile >> english >> esperanto )
    {
        en_to_eo[ english ] = esperanto;
        eo_to_en[ esperanto ] = english;
    }

    infile.close();
}
