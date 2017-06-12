#include <iostream>
#include <fstream>
using namespace std;

#include "Utils.hpp"
#include "GroceryManager.hpp"

void AddItem( GroceryManager& grocMan );
void RemoveItem( GroceryManager& grocMan );
void ViewItems( GroceryManager& grocMan );

int main()
{
    GroceryManager grocMan;

    string options[] = {
        "1. Add Item",
        "2. Remove Item",
        "3. View Items",
        "4. Quit"
    };

    while ( true )
    {
        ClearScreen();
        DisplayMainMenu( options, 4 );
        int choice = GetNumberInput( 1, 4 );

        if      ( choice == 1 ) { AddItem( grocMan ); }
        else if ( choice == 2 ) { RemoveItem( grocMan ); }
        else if ( choice == 3 ) { ViewItems( grocMan ); }
        else                    { break; }
    }

    return 0;
}

void AddItem( GroceryManager& grocMan )
{
    ClearScreen();

    cout << "--------" << endl;
    cout << "ADD ITEM" << endl;
    cout << "--------" << endl;
    cout << endl;

    Grocery item;
    cout << "Item name:  ";
    string name;
    cin >> name;
    cout << "Item price: $";
    float price;
    cin >> price;
    cout << "Quantity:   ";
    int quantity;
    cin >> quantity;

    item.SetName( name );
    item.SetPrice( price );
    item.SetStock( quantity );

    grocMan.AddItem( item );
}

void RemoveItem( GroceryManager& grocMan )
{
    ClearScreen();

    cout << "-----------" << endl;
    cout << "REMOVE ITEM" << endl;
    cout << "-----------" << endl;

    grocMan.DisplayList();
    cout << "Remove item at which index? ";
    int choice = GetNumberInput( 0, grocMan.GetItemCount() - 1 );
    grocMan.RemoveItem( choice );
}

void ViewItems( GroceryManager& grocMan )
{
    ClearScreen();

    cout << "---------" << endl;
    cout << "INVENTORY" << endl;
    cout << "---------" << endl;

    grocMan.DisplayList();

    cout << "Continue? (y):";
    char choice;
    cin >> choice;
}
