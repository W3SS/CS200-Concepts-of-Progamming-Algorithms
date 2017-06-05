#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int LoadClasses( string classes[100] )
{
	ifstream input( "courses.txt" );
	
	int index = 0;
	string buffer;
	
	while ( input >> buffer )
	{
		classes[index] = buffer;
		index++;
	}
	
	input.close();
	
	return index;
}

void SaveClasses( string classes[100], int classCount )
{
	ofstream output( "courses.txt" );
	
	for ( int i = 0; i < classCount; i++ )
	{
		output << classes[i] << endl;
	}
	
	output.close();
}

int main()
{
	string classes[100];
	int classCount = LoadClasses( classes );
	
	for ( int i = 0; i < classCount; i++ )
	{
		cout << i << ". " << classes[i] << endl;
	}
	
	cout << "Edit which class? ";
	int edit;
	cin >> edit;
	
	cout << "New class name? ";
	cin >> classes[edit];
	
	SaveClasses( classes, classCount );
	
	return 0;
}
