#ifndef _GROCERYMANAGER
#define _GROCERYMANAGER

#include <vector>
using namespace std;

#include "Grocery.hpp"

class GroceryManager
{
    public:
    GroceryManager();
    ~GroceryManager();

    void AddItem( Grocery& groc );
    void AddItem( const string& name, float price, int quantity );
    void RemoveItem( int index );
    int GetItemCount();

    void DisplayList();

    private:
    vector<Grocery> m_groceries;
};

#endif
