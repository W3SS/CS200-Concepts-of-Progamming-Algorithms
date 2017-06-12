#include "Grocery.hpp"


string Grocery::GetName()
{
    return m_name;
}

float Grocery::GetPrice()
{
    return m_price;
}

int Grocery::GetStock()
{
    return m_inStock;
}

void Grocery::SetName( const string& val )
{
    m_name = val;
}

void Grocery::SetPrice( float val )
{
    if ( val > 0 )
    {
        m_price = val;
    }
}

void Grocery::SetStock( int val )
{
    if ( val >= 0 )
    {
        m_inStock = val;
    }
}
