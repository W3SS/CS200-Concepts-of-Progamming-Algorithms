#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void LoadFile( int& level, int& score, string& name )
{
    ifstream input( "data.txt" );

    if ( input.is_open() == false )
    {
        cout << "Save file doesn't exist - default values loaded" << endl;
        return;
    }

    // Load in data
    input >> level >> score >> name;

    input.close();
}

void SaveFile( int level, int score, string name )
{
    ofstream output( "data.txt" );

    output << level << " " << score << " " << name << endl;
    
    output.close();
}

int main()
{
    int level = 1;
    int score = 0;
    string name = "default";

    LoadFile( level, score, name );

    bool done = false;
    while ( !done )
    {
        cout << endl << endl;
        cout << "Level: " << level << endl
            << "Score: " << score << endl
            << "Name: " << name << endl << endl;

        cout << "1. Update level" << endl
            << "2. Update score" << endl
            << "3. Update name" << endl
            << "4. Save and quit" << endl;

        cout << ">> ";
        int choice;
        cin >> choice;

        switch( choice )
        {
            case 1:
            cout << "New level value: ";
            cin >> level;
            break;
            
            case 2:
            cout << "New score value: ";
            cin >> score;
            break;
            
            case 3:
            cout << "New name value: ";
            cin >> name;
            break;
            
            case 4:
            done = true;
            break;
        }
    }

    SaveFile( level, score, name );
    
    return 0;
}


