#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void ReadFile( string filename )
{
	ifstream input;
	input.open( filename );
	
	string lineOfText;
	
	while ( getline( input, lineOfText ) )
	{
		cout << lineOfText << endl;
	}
	
	input.close();
}

int main()
{
	ReadFile( "fable.txt" );
	
	return 0;
}
