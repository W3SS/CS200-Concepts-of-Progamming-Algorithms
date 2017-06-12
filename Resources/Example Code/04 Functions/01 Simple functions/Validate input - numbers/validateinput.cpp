#include <iostream>
using namespace std;

int GetChoice( int minVal, int maxVal )
{
    int choice;
    cout << "INPUT: ";
    cin >> choice;

    // Make sure that minVal <= choice <= maxVal
    while ( choice < minVal || choice > maxVal )
    {
        cout << "Invalid choice. Select an option between "
            << minVal << " and " << maxVal << endl;
        cout << "INPUT: ";
        cin >> choice;
    }

    // Return the user's input once we've validated it.
    return choice;
}

int main()
{
    bool done = false;

    while ( !done )
    {
        cout << endl << "------------------" << endl;
        cout << "1. Add numbers" << endl;
        cout << "2. Subtract numbers" << endl;
        cout << "3. Exit" << endl;
        cout << "What do you want to do? ";

        int choice = GetChoice( 1, 3 );

        if ( choice == 1 )
        {
            int a, b;
            cout << "Enter two numbers: ";
            cin >> a >> b;

            int sum = a + b;
            cout << a << " + " << b << " = " << sum << endl;
        }
        else if ( choice == 2 )
        {
            int a, b;
            cout << "Enter two numbers: ";
            cin >> a >> b;

            int difference = a - b;
            cout << a << " - " << b << " = " << difference << endl;
        }
        else if ( choice == 3 )
        {
            done = true;
        }
    }

    return 0;
}


