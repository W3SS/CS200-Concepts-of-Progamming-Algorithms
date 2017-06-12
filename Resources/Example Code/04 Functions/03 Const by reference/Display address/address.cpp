#include <iostream>
using namespace std;

/*
Write a function called DisplayAddress. Its return type is void, and it takes the following parameters:

    to, a const string reference
    address1, a const string reference
    city, a const string reference,
    state, a const string reference.
    zip, an integer
*/

void DisplayAddress( const string& to, const string& address1, const string& city, const string& state, int zip )
{
    cout << to << endl;
    cout << address1 << endl;
    cout << city << ", " << state << " " << zip << endl;
}

int main()
{
    DisplayAddress( "JCCC", "12345 College Blvd", "Overland Park", "KS", 66210 );

    return 0;
}
