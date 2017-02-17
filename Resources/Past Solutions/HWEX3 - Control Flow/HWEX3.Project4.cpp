#include <iostream>
#include <string>
using namespace std;
    
int main()
{
    while ( true )
    {
        int feet;
        cout << "Enter the amount of feet: ";
        cin >> feet;
        
        for ( int in = 0; in <= feet * 12; in++ )
        {
            if ( in % 12 == 0 )
            {
                cout << "|";
            }
            else
            {
                cout << "-";
            }
        }
        
        cout << endl << endl;
        
    }
    
    return 0;
}
