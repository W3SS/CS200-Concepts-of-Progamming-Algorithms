#include <iostream>
#include <ctime>
#include <cstdlib>

int main()
{
	// Initialize random number generator
	srand( time( NULL ) );
	
	// Generate number between 0 and 9
	int rand1 = rand() % 10;
	
	// Generate a number between 0 and 99.
	int rand2 = rand() % 100;
	
	// Generate a number between 0 and 3.
	int rand3 = rand() % 3;
	
	return 0;
}
