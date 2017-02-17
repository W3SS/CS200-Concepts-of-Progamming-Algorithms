#include <iostream>
#include <string>
using namespace std;
    
int main()
{
	bool isTallEnoughToRide;
	int feet;
	
	cout << "What is your height (in feet)? ";
	cin >> feet;
	
	isTallEnoughToRide = (feet > 3);
	
	if ( isTallEnoughToRide )
	{
		cout << "Permitted to ride roller coaster" << endl;
	}
	else
	{
		cout << "Too short to ride roller coaster" << endl;
	}
	
	while ( true ) {} // don't quit    
    return 0;
}
