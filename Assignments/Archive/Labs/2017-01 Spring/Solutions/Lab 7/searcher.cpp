#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void SearchFile( string filename, string searchFor )
{
	ifstream input;
	input.open( filename );
	
	string lineOfText;
	
	int lineCount = 0;
	while ( getline( input, lineOfText ) )
	{		
		if ( lineOfText.find( searchFor ) != string::npos )
		{
			cout << "FOUND AT LINE " << lineCount << ": " << lineOfText << endl << endl;
		}
		
		lineCount++;
	}
	
	input.close();
}

int main()
{
	string searchFor;
	cout << "Search for what? ";
	cin >> searchFor;
	
	SearchFile( "fable.txt", searchFor );
	
	return 0;
}
