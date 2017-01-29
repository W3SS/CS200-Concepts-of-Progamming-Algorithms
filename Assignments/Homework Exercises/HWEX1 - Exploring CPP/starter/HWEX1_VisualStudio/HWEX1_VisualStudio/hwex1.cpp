#include <iostream>     // input/output commands
using namespace std;    // standard library

int main()              // program entry function
{
	// Variable declarations
	float width;
	float length;
	float area;

	// Get user input:
	cout << "Enter the width: ";        // text output
	cin >> width;                       // input from the user

	cout << "Enter the length: ";
	cin >> length;

	area = width * length;              // assignment statement

										// Display results:
	cout << endl;                       // empty line
	cout << "Area: " << area << endl;

	while (true);
	return 0;           // end of program
}
