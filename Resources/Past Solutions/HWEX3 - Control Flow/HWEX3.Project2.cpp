#include <iostream>
#include <string>
using namespace std;
    
int main()
{
    while ( true )
    {
        int number;
        cout << "Enter a number between 1 and 5: ";
        cin >> number;
        
        string romanNumeral = "";
        
        switch( number )
        {
            case 1:
            romanNumeral = "I";
            break;
            
            case 2:
            romanNumeral = "II";
            break;
            
            case 3:
            romanNumeral = "III";
            break;
            
            case 4:
            romanNumeral = "IV";
            break;
            
            case 5:
            romanNumeral = "V";
            break;
        }
        
        cout << "Roman numeral is: " << romanNumeral << endl << endl;
    }
    
    return 0;
}
