#include <iostream>
#include <string>
using namespace std;
    
int main()
{
    int sum = 0;
    
    bool done = false;
    while ( !done )
    {
        cout << "Enter a number: ";
        int num;
        cin >> num;
        
        sum += num;
        
        cout << endl << "Type (Q) to quit, or (A) to enter another." << endl;
        cout << "Choice: ";
        char choice;
        cin >> choice;
        cout << endl;
        
        if ( choice == 'q' || choice == 'Q' )
        {
            done = true;
        }
    }
    
    cout << "The sum is " << sum << endl;
    
    return 0;
}
