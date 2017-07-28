#ifndef _PA // don't modify
#define _PA // don't modify

#include <string>       // don't modify
#include <iostream>     // don't modify
using namespace std;    // don't modify

/**
    Displays all the stats of the pet, with labels to make it user-friendly.
    @param <string> petName         The name of the pet
    @param <int> hungerPercent      The hunger amount, between 0 - 100%
    @param <int> happinessPercent   The happiness amount, between 0 - 100%
    @param <int> healthPercent      The health amount, between 0 - 100%
    @return <void>                  No return information
*/
void DisplayPetStats( string petName, int hungerPercent, int happinessPercent, int healthPercent )
{
}

/**
    Displays the main menu options:
        1. Feed pet, 2. Play with pet, 3. Heal pet, 4. Quit
    @return <void>                  No return information
*/
void DisplayMainMenu()
{
}

/**
    Draws different faces depending on the health of the pet
    @param <int> healthPercent      Current health of the pet, between 0 - 100%
    @return <void>                  No return information
*/
void DrawPet( int healthPercent )
{
}

/**
    This is responsible for getting the user's input via cin and validating the
    input. If the user's input is invalid, it will continuously ask the user to re-enter
    their selection until the user finally enters something valid.

    @param <int> min                The minimum integer value that is valid
    @param <int> max                The maximum integer value that is valid
    @return <int>                   Valid input, which is between the min and max values.
*/
int GetChoice( int min, int max )
{
}

/**
    This function is called every game-cycle. Each cycle, the pet's hunger goes up. Depending on
    how hungry the pet it, it also affects the health/happiness stats.

    * Each cycle: Hunger + 5
    * If Hunger is above 75:                Health - 10, Happines - 10
    * If Hunger is between 50 and 75:       Health - 5, Happines - 5
    * If Hunger is between 25 and 50:       Health - 2, Happines - 2

    Make sure to fix any percentages;
        If hunger is above 100, set it to 100.
        If happiness is below 0,then set it to 0.
        If health is below 0, then set it to 0.

    @param <int&> hungerPercent      The hunger amount, between 0 - 100%; this is a reference parameter
    @param <int&> happinessPercent   The happiness amount, between 0 - 100%; this is a reference parameter
    @param <int&> healthPercent      The health amount, between 0 - 100%; this is a reference parameter
    @return <void>                   No return information
*/
void UpdatePet( int& hungerPercent, int& happinessPercent, int& healthPercent )
{
}

/**
    This updates the hunger percent; subtract 8 units from hunger.
    If hunger is below 0 afterward, then set it to 0.

    @param <int&> hungerPercent      The hunger amount, between 0 - 100%; this is a reference parameter
    @return <void>                   No return information
*/
void Feed( int& hungerPercent )
{
}

/**
    This updates the happiness percent; adds 5 to happiness
    If happiness is above 100 afterward, then set it to 100.

    @param <int&> happinessPercent   The happiness amount, between 0 - 100%; this is a reference parameter
    @return <void>                   No return information
*/void Play( int& happinessPercent )
{
}

/**
    This updates the health percent; add 5 units to health
    If health is above 100 afterward, then set it to 100.

    @param <int&> healthPercent      The health amount, between 0 - 100%; this is a reference parameter
    @return <void>                   No return information
*/
void Heal( int& healthPercent )
{
}

#endif // don't modify
