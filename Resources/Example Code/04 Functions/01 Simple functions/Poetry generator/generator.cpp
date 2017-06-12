// By the 12:30 class. :P

#include <iostream>		// i/o stream
#include <stdlib.h>		// rand()
#include <ctime>		// time()
#include <string>
using namespace std;

int GetRandomNumber(int minimum, int maximum)
{
	int diff = maximum - minimum;
	return rand() % diff + minimum;
}

string GetNoun()
{
	int random = rand() % 3;
	if (random == 0) { return "Apple"; }
	else if (random == 1) { return "Orange"; }
	else if (random == 2) { return "Ghandi"; }
}

string GetAdjective()
{
	int random = rand() % 3;
	if (random == 0) { return "pretty"; }
	else if (random == 1) { return "large"; }
	else if (random == 2) { return "shiny"; }
}

string GetVerb()
{
	int random = rand() % 3;
	if (random == 0) { return "flies"; }
	else if (random == 1) { return "dances"; }
	else if (random == 2) { return "gesticulates"; }
}

int main()
{
	srand(time(NULL));

	int sentenceCount = GetRandomNumber(5, 10);
	for (int i = 0; i < sentenceCount; i++)
	{
		cout << GetAdjective() << " "
			<< GetNoun() << " "
			<< GetVerb() << endl;
	}

	return 0;
}
