#ifndef _GROCERY
#define _GROCERY

#include <string>
using namespace std;

class Grocery
{
    public:
    string GetName();
    float GetPrice();
    int GetStock();

    void SetName( const string& val );
    void SetPrice( float val );
    void SetStock( int val );

    private:
    int m_inStock;
    string m_name;
    float m_price;
};

#endif
