#ifndef _SPELL
#define _SPELL

#include <string>
using namespace std;

struct Spell
{
    string name;
    string ingredients[3];
    string incantation[5];
    float manaCost;

    void Display()
    {
        cout << endl;
        cout << name << " (" << manaCost << ")" << endl;

        cout << "INGREDIENTS: ";

        for ( int i = 0; i < 3; i++ )
        {
            cout << ingredients[i] << "\t";
        }

        cout << endl << "INCANTATION: ";
        for ( int i = 0; i < 5; i++ )
        {
            cout << incantation[i] << " ";
        }
        cout << endl;
    }
};

#endif
