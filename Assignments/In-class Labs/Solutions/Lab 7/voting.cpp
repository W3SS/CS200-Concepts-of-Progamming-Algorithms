#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	int votes[3] = { 0, 0, 0 };
    string options[3] = { "cats", "dogs", "ferrets" };

    while ( true )
    {
		cout << endl << endl;
		cout << "Vote: " << endl;
        for ( int i = 0; i < 3; i++ )
        {
            cout << i << ". " << options[i] << endl;
        }
		cout << "3. Quit" << endl;

        cout << "Choice? ";
        int choice;
        cin >> choice;

        if ( choice == 3 )
        {
			break;
        }
        else
        {
            votes[ choice ]++;
        }
    }
    
    ofstream output( "poll-results.txt" );
    
    for ( int i = 0; i < 3; i++ )
    {
		output << options[i] << ": " << votes[i] << endl;
	}
    
    output.close();
	
	return 0;
}
