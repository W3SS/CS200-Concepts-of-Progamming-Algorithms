#include "GroceryManager.hpp"

#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;

GroceryManager::GroceryManager()
{
    ifstream input( "grocery.txt" );

    string buffer;
    string name;
    float price;
    int stock;

    input >> buffer >> buffer >> buffer; // skip file header

    int count = 0;
    while ( input >> name >> price >> stock )
    {
        AddItem( name, price, stock );
        count++;
    }

    cout << count << " items loaded" << endl;

    input.close();
}

GroceryManager::~GroceryManager()
{
    ofstream output( "grocery.txt" );

    output << "Item \t Price \t Quantity" << endl;

    for ( int i = 0; i < m_groceries.size(); i++ )
    {
        output << m_groceries[i].GetName() << "\t"
            << m_groceries[i].GetPrice() << "\t"
            << m_groceries[i].GetStock() << endl;
    }

    output.close();
}

void GroceryManager::AddItem( Grocery& groc )
{
    m_groceries.push_back( groc );
}

void GroceryManager::AddItem( const string& name, float price, int quantity )
{
    Grocery item;
    item.SetName( name );
    item.SetPrice( price );
    item.SetStock( quantity );
    AddItem( item );
}

void GroceryManager::RemoveItem( int index )
{
    m_groceries.erase( m_groceries.begin() + index );
}

void GroceryManager::DisplayList()
{
    cout << endl;
    for ( int i = 0; i < m_groceries.size(); i++ )
    {
        cout << "ITEM #" << i << ":  " << m_groceries[i].GetName() << endl;
        cout << "PRICE:    $" << m_groceries[i].GetPrice() << endl;
        cout << "IN STOCK: " << m_groceries[i].GetStock() << endl << endl;
    }
}

int GroceryManager::GetItemCount()
{
    return m_groceries.size();
}
