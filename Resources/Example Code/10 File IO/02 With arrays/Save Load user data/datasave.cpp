#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void LoadUsernames( string usernames[], int& usernameCount );
void SaveUsernames( const string usernames[], int usernameCount );

int main()
{
    string usernames[10];
    int usernameCount = 0;

    LoadUsernames( usernames, usernameCount );

    bool done = false;
    while ( !done )
    {
        cout << endl << "USERNAMES:" << endl;
        for ( int i = 0; i < usernameCount; i++ )
        {
            cout << (i+1) << ". " << usernames[i] << endl;
        }

        cout << "Add username or type QUIT to quit: ";
        string name;
        cin >> name;
        if ( name == "QUIT" )
        {
            done = true;
        }
        else
        {
            usernames[ usernameCount ] = name;
            if ( usernameCount < 9 )
            {
                usernameCount++;
            }
        }
    }

    SaveUsernames( usernames, usernameCount );

    return 0;
}

void LoadUsernames( string usernames[], int& usernameCount )
{
    ifstream input( "save.txt" );
    if ( input.bad() )
    {
        return;
    }

    string buffer;

    input >> buffer;        // string
    input >> usernameCount; // integer

    int i = 0;
    while ( input >> buffer )
    {
        usernames[i] = buffer;
        i++;
    }

    input.close();
}

void SaveUsernames( const string usernames[], int usernameCount )
{
    ofstream output( "save.txt" );

    output << "USERNAME_COUNT: " << usernameCount << endl;

    for ( int i = 0; i < usernameCount; i++ )
    {
        output << usernames[i] << endl;
    }

    output.close();
}
