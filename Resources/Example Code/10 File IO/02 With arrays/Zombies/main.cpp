#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

#include "Locations.hpp"
#include "People.hpp"
#include "Equipment.hpp"

void LoadPeople( Person people[], int arraySize, int& count );
void LoadLocations( Location locations[], int arraySize, int& count );
void RandomlyChooseParty( Person people[], int peopleCount, Person party[5] );
bool AtLeastOneSurvivor( Person party[5] );
void DisplayPartyStats( Person party[5], const Equipment& equipment );
void AdjustStats( Person party[5], Equipment& equipment );
void ScavengeRound( Location locations[], int locationSize, Equipment& equipment );

int main()
{
    srand( time( NULL ) );

    Person people[100];
    int peopleCount = 0;
    Location locations[100];
    int locationCount = 0;

    LoadPeople( people, 100, peopleCount );
    LoadLocations( locations, 100, locationCount );
    Equipment equipment;
    equipment.Init();

    int days = 0;

    bool done = false;
    while ( !done )
    {
        // Randomly choose party
        Person party[5];
        RandomlyChooseParty( people, peopleCount, party );
        DisplayPartyStats( party, equipment );

        // Simulation
        while ( AtLeastOneSurvivor( party ) )
        {
            cout << "----------------------------------------" << endl
                << "DAY " << days << endl;

            cout << endl;
            cout << "--------------" << endl;
            cout << "|| SCAVENGE ||" << endl;
            cout << "--------------" << endl;
            ScavengeRound( locations, locationCount, equipment );

            string choice = "";
            while ( choice != "y" && choice != "n" )
            {
                cout << "Continue? (y/n): ";
                cin >> choice;
            }

            cout << endl;
            cout << "-------------" << endl;
            cout << "|| SURVIVE ||" << endl;
            cout << "-------------" << endl;
            AdjustStats( party, equipment );
            DisplayPartyStats( party, equipment );

            choice = "n";
            while ( choice != "y" )
            {
                cout << "Ready for next day? (y/n): ";
                cin >> choice;
            }

            days++;
        }

        cout << "Your party has survived for " << days << " days!" << endl;
        string choice = "";
        while ( choice != "y" && choice != "n" )
        {
            cout << "Do you wish to restart? (y/n): ";
            cin >> choice;
        }

        if ( choice == "n" )
        {
            done = true;
        }
    }

    return 0;
}

void ScavengeRound( Location locations[], int locationSize, Equipment& equipment )
{
    // Scavenge
    cout << endl << "PHASE 1: SCAVENGE" << endl;
    cout << "Choose 3 of the following locations to search for equipment:" << endl << endl;
    for ( int l = 0; l < locationSize; l++ )
    {
        cout << (l+1) << ". " << locations[l].name << endl;
    }

    int loc1, loc2, loc3;
    cout << "Search regions #: ";
    cin >> loc1 >> loc2 >> loc3;
    loc1--;
    loc2--;
    loc3--;

    equipment.ammo += locations[loc1].ammoCount + locations[loc2].ammoCount + locations[loc3].ammoCount;
    equipment.food += locations[loc1].foodCount + locations[loc2].foodCount + locations[loc3].foodCount;
    equipment.entertainment += locations[loc1].entertainmentCount + locations[loc2].entertainmentCount + locations[loc3].entertainmentCount;

    cout << "Your party has scavenged: " << equipment.ammo << " AMMO, "
        << equipment.food << " FOOD, and "
        << equipment.entertainment << " ENTERTAINMENT" << endl;
}

void AdjustStats( Person party[5], Equipment& equipment )
{
    for ( int p = 0; p < 5; p++ )
    {
        if ( party[p].isAlive )
        {
            int foodNeeded = rand() % 3 + 1;
            int entertainmentNeeded = rand() % 3 + 1;

            party[p].hunger += rand() % 10;
            party[p].sanity -= rand() % 10;

            if ( equipment.food - foodNeeded <= 0 )
            {
                foodNeeded = equipment.food;
            }

            if ( equipment.entertainment - entertainmentNeeded <= 0 )
            {
                entertainmentNeeded = equipment.entertainment;
            }

            cout << party[p].name << " consumed " << entertainmentNeeded
                << " units of entertainment and " << foodNeeded << " units of food" << endl;
            equipment.entertainment -= entertainmentNeeded;
            equipment.food -= foodNeeded;

            if ( party[p].hunger >= 100 )
            {
                cout << party[p].name << " has starved to death!" << endl;
                party[p].isAlive = false;
            }

            if ( party[p].sanity <= 0 )
            {
                cout << party[p].sanity << " has broken down and died!" << endl;
                party[p].isAlive = false;
            }
        }
    }

    string choice = "n";
    while ( choice != "y" )
    {
        cout << "Ready for next event? (y/n): ";
        cin >> choice;
    }

    int zombieAttacks = rand() % 5;

    if ( zombieAttacks > 0 )
    {
        for ( int z = 0; z < zombieAttacks; z++ )
        {
            cout << endl << "A zombie attacked!" << endl;
            int ammoUsed = rand() % 5 + 1;

            if ( equipment.ammo - ammoUsed < 0 )
            {
                ammoUsed = equipment.ammo;
            }

            if ( ammoUsed == 0 )
            {
                // Kill one person
                int person = rand() % 5;
                if ( party[person].isAlive )
                {
                    cout << "There was no ammo left, so zombie killed " << party[person].name << "!" << endl;
                    party[person].isAlive = false;
                }
                else
                {
                    cout << "Zombie took a bite out of the body of " << party[person].name << endl;
                }
            }
            else
            {
                cout << ammoUsed << " ammo used fighting it off!" << endl;
                equipment.ammo -= ammoUsed;
            }
        }
    }
    else
    {
        cout << endl << "No zombies attacked the base today :)" << endl;
    }
}

void DisplayPartyStats( Person party[5], const Equipment& equipment )
{
    cout << endl << "PARTY STATUS" << endl;
    for ( int p = 0; p < 5; p++ )
    {
        cout << p+1 << setw( 30 ) << party[p].name << setw( 10 );

        if ( party[p].isAlive )
        {
            cout << "ALIVE";
        }
        else
        {
            cout << "DEAD";
        }

        cout << setw( 20 ) << " Hunger: " << party[p].hunger
            << setw( 10 ) << "Sanity:" << party[p].sanity << endl;
    }

    cout << endl << "EQUIPMENT" << endl;
    cout    << "Ammo:           " << equipment.ammo << endl
            << "Food:           " << equipment.food << endl
            << "Entertainment:  " << equipment.entertainment << endl << endl;
}

bool AtLeastOneSurvivor( Person party[5] )
{
    bool allDead = true;
    for ( int p = 0; p < 5; p++ )
    {
        if ( party[p].isAlive )
        {
            allDead = false;
        }
    }
    return !allDead;
}

void RandomlyChooseParty( Person people[], int peopleCount, Person party[5] )
{
    for ( int p = 0; p < 5; p++ )
    {
        party[p] = people[ rand() % peopleCount ];
    }
}

void LoadPeople( Person people[], int arraySize, int& count )
{
    count = 0;
    ifstream input( "People.txt" );

    string first, last;
    while ( input >> first >> last )
    {
        people[ count ].name = first + " " + last;
        people[ count ].hunger = 0;
        people[ count ].sanity = 100;
        people[ count ].isAlive = true;
        count++;
    }

    input.close();

    cout << count << " total people" << endl;
}

void LoadLocations( Location locations[], int arraySize, int& count )
{
    count = 0;
    ifstream input( "Locations.txt" );

    string first, last;
    while ( input >> first >> last )
    {
        locations[ count ].name = first + " " + last;
        input >> locations[ count ].ammoCount;
        input >> locations[ count ].foodCount;
        input >> locations[ count ].entertainmentCount;
        count++;
    }

    input.close();

    cout << count << " total locations" << endl;
}

