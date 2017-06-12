#include <iostream>
using namespace std;

float MAX_PRICE = 99.99;

float AddTax( float price );

int main()
{
    float price = MAX_PRICE;
    price = AddTax( price );
    cout << "Price: " << price << endl;

    return 0;
}

float AddTax( float price )
{
    float fee = 0.05; // local variable, to AddTax

    if ( price < 10 )
    {
        float tax = 0.10; // local variable, to if
        price += price * tax;
    }
    else
    {
        float tax = 0.15; // local variable, to else
        price += price * tax;
    }

    price += fee;

    // cout << "Tax: " << tax << endl; // <-- Causes a build error
    return price;
}
