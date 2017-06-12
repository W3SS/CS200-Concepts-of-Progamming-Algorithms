#include <iostream>
#include <string>
using namespace std;

void DisplayItem( int number, string itemName, float price )
{
    cout << number << ". " << itemName << "\t $" << price << endl;
}

void DisplayItem( int number, string itemName )
{
    cout << number << ". " << itemName << endl;
}

int GetChoice( int minimum, int maximum )
{
    int choice;

    do
    {
        cout << ">> ";
        cin >> choice;

        if ( choice < minimum || choice > maximum )
        {
            cout << "Invalid option, try again." << endl;
        }
    } while ( choice < minimum || choice > maximum );

    return choice;
}

float GetPriceOf( string foodName )
{
    if ( foodName == "Bagel" )
    {
        return 5.99;
    }
    else if ( foodName == "Coffee" )
    {
        return 6.45;
    }
    else if ( foodName == "Cookie" )
    {
        return 2.01;
    }
    else
    {
        return 0;
    }
}

float AddTax( float balance, float taxRate )
{
    return balance + ( balance * taxRate );
}

int main()
{
    bool done = false;

    float balance = 0;

    while ( !done )
    {
        cout << endl;
        DisplayItem( 1, "Bagel",  GetPriceOf( "Bagel" ) );
        DisplayItem( 2, "Coffee", GetPriceOf( "Coffee" ) );
        DisplayItem( 3, "Cookie", GetPriceOf( "Cookie" ) );
        DisplayItem( 4, "Checkout" );
        cout << "Current total: $" << balance << endl;

        cout << "What do you want? ";
        int choice = GetChoice( 1, 4 );

        if ( choice == 4 )
        {
            cout << endl << "Are you done ordering?" << endl;
            DisplayItem( 1, "Yes" );
            DisplayItem( 2, "No" );
            int choice = GetChoice( 1, 2 );

            if ( choice == 1 )
            {
                done = true;
            }
        }
        else if ( choice == 1 )
        {
            balance += GetPriceOf( "Bagel" );
        }
        else if ( choice == 2 )
        {
            balance += GetPriceOf( "Coffee" );
        }
        else if ( choice == 3 )
        {
            balance += GetPriceOf( "Cookie" );
        }
    }

    cout << "Your total is $" << balance << endl;
    float withTax = AddTax( balance, 0.10 );
    cout << "With tax $" << withTax << endl;

    return 0;
}
