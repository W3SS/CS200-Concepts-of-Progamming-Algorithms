#include <iostream>
#include <string>
using namespace std;
    
int main()
{
	char letter1, letter2;
	
	cout << "Enter two letters: ";
	cin >> letter1 >> letter2;
	
	if ( letter1 < letter2 )
	{
		cout << "The first letter comes first" << endl;
	}
	else
	{
		cout << "The second letter comes first" << endl;
	}

	while ( true ) {} // don't quit    
    return 0;
}
