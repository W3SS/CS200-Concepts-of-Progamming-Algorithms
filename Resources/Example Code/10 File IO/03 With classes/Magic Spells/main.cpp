#include <iostream>
#include <fstream>
using namespace std;

#include "Spell.hpp"

void LoadSpells( const string& filename, Spell spells[], int size );
void SaveSpells( const string& filename, Spell spells[], int size );

int main()
{
    Spell spells[5];
    LoadSpells( "spellbook.txt", spells, 3 );

    for ( int s = 0; s < 3; s++ )
    {
        spells[s].Display();
    }

    cout << endl << "Add new spells" << endl << endl;
    for ( int s = 3; s < 5; s++ )
    {
        cout << "Spell name:    ";
        cin >> spells[s].name;
        cout << "Mana cost:     ";
        cin >> spells[s].manaCost;
        cout << "3 Ingredients: ";
        cin >> spells[s].ingredients[0]
            >> spells[s].ingredients[1]
            >> spells[s].ingredients[2];
        cout << "5 Words:       ";
        cin >> spells[s].incantation[0]
            >> spells[s].incantation[1]
            >> spells[s].incantation[2]
            >> spells[s].incantation[3]
            >> spells[s].incantation[4];
        cout << endl << endl;
    }

    SaveSpells( "spellbook.txt", spells, 5 );

    return 0;
}

void LoadSpells( const string& filename, Spell spells[], int size )
{
    ifstream input( filename.c_str() );

    for ( int s = 0; s < size; s++ )
    {
        input >> spells[s].name;
        input >> spells[s].manaCost;

        for ( int i = 0; i < 3; i++ )
        {
            input >> spells[s].ingredients[i];
        }
        for ( int i = 0; i < 5; i++ )
        {
            input >> spells[s].incantation[i];
        }
    }

    input.close();
}

void SaveSpells( const string& filename, Spell spells[], int size )
{
    ofstream output( filename.c_str() );

    for ( int s = 0; s < size; s++ )
    {
        output << spells[s].name;
        output << "\n\t" << spells[s].manaCost;

        for ( int i = 0; i < 3; i++ )
        {
            output << "\n\t" << spells[s].ingredients[i];
        }
        for ( int i = 0; i < 5; i++ )
        {
            output << spells[s].incantation[i] << " ";
        }
        output << endl << endl;
    }

    output.close();
}
