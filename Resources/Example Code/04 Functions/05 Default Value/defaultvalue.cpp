#include <iostream>
#include <string>
using namespace std;

void DisplayRecord( string fname, string lname, int age = 0, string location = "undefined" )
{
    cout << lname << ", " << fname << endl;
    cout << "Age:      " << age << endl;
    cout << "Location: " << location << endl;
    cout << endl;
}

int main()
{
    DisplayRecord( "Fordon", "Greeman", 30, "City 17" );
    DisplayRecord( "Stroud", "Clife", 18, "Gidmar" );
    DisplayRecord( "Tsusagi", "Ukino" );

    return 0;
}
