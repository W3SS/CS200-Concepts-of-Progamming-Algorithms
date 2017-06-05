#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

void LoadNouns( string nouns[100], int & nounCount )
{
	ifstream input( "nouns.txt" );
	
	nounCount = 0;
	
	string buffer;
	while ( input >> buffer )
	{
		nouns[ nounCount ] = buffer;
		nounCount++;
	}
	
	input.close();
}

void LoadAdjectives( string adjectives[100], int & adjectiveCount )
{
	ifstream input( "adjectives.txt" );
	
	adjectiveCount = 0;
	
	string buffer;
	while ( input >> buffer )
	{
		adjectives[ adjectiveCount ] = buffer;
		adjectiveCount++;
	}
	
	input.close();
}

string GeneratePoem( string nouns[100], int nounCount, string adjectives[100], int adjectiveCount )
{
	string poem = 	nouns[ rand() % nounCount ] + " are " +
					adjectives[ rand() % adjectiveCount ] + ", \n" +
					nouns[ rand() % nounCount ] + " are " +
					adjectives[ rand() % adjectiveCount ] + ", \n" +
					nouns[ rand() % nounCount ] + " are " +
					adjectives[ rand() % adjectiveCount ] + ", \n" +
					"and so are you!";
	return poem;
}


int main()
{
	srand( time( NULL ) );
	
	string nouns[100];
	int nounCount;
	string adjectives[100];
	int adjectiveCount;
	
	LoadNouns( nouns, nounCount );
	LoadAdjectives( adjectives, adjectiveCount );
	
	string poem = GeneratePoem( nouns, nounCount, adjectives, adjectiveCount );
	
	cout << "RANDOM POEM:" << endl;
	cout << poem << endl;
	
	return 0;
}
