#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int MainMenu()
{
    cout << "-------------------" << endl;
    cout << "1. Add to list" << endl;
    cout << "2. Save and quit" << endl;

    int choice;
    cin >> choice;

    while ( choice != 1 && choice != 2 )
    {
        cout << "Invalid choice. Try again: ";
        cin >> choice;
    }
}

void AddItem( ofstream & output, int itemCounter )
{
    string item;
    cin.ignore();
    cout << "What do you want to do? ";
    getline( cin, item );

    output << itemCounter << ". " << item << endl;
}

int main()
{
    ofstream output( "todo.txt" );
    int itemCounter = 1;

    bool done = false;

    while ( !done )
    {
        int choice = MainMenu();

        if ( choice == 1 )
        {
            AddItem( output, itemCounter );
            itemCounter++;
        }
        else if ( choice == 2 )
        {
            done = true;
        }
    }

    output.close();

    return 0;
}
