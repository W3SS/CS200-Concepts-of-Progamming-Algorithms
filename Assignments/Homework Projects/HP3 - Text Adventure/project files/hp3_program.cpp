/*
MODIFY THIS FILE
*/

#include "hp3_program.hpp"

#include <iostream>
using namespace std;


/* Setup() - 	Create the list of locations
 *              Allocate needed memory
 * */
void Program::Setup()
{
    // This is called automatically when the program begins
}



/* Cleanup() - 	Clean up memory allocated
 * */
void Program::Cleanup()
{
    // This is called automatically when the program ends
}



/* Main() - Main program loop
 * */
void Program::Main()
{
}



/* DisplayCurrentLocation() - Use the current location
 *              pointer to display the location's name
 *              and description, as well as which
 *              directions the player can move next.
 * */
void Program::DisplayCurrentLocation()
{
}



/* GetUserInput() - Display the list of options to the
 *                  user, then get their input and return
 *                  their choice.
 * */
string Program::GetUserInput()
{
	return ""; // temp - replace me
}



/************************************/
/* Don't modify *********************/
/************************************/

Program::Program()
{
    locationList = nullptr;
    ptrCurrentLocation = nullptr;
    Setup();
}

Program::~Program()
{
    Cleanup();
}
