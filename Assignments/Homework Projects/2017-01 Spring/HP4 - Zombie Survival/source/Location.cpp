#include "Location.hpp"

//! Sets up private member variables m_name, m_ammo, and m_food, based on parameters passed in.
/**
    @param name <const string&>     The value to assign to the m_name variable
    @param ammo <int>               The value to assign to the m_ammo variable
    @param food <int>               The value to assign to the m_food variable
    @return <void>
*/
void Location::Setup( const string& name, int ammo, int food )
{
}

//! Returns the value of the private member variable m_name.
/**
    @return <string>    The locations's name, from m_name.
*/
string Location::GetName()
{
    return ""; // temp
}

//! Returns the value of the private member variable m_ammo.
/**
    @return <string>    The amount of food at this location, from m_ammo.
*/
int Location::GetAmmo()
{
    return -1; // temp
}

//! Returns the value of the private member variable m_food.
/**
    @return <string>    The amount of food at this location, from m_food.
*/
int Location::GetFood()
{
    return -1; // temp
}
