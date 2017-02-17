#include <iostream>
#include <string>
using namespace std;
    
int main()
{
    while ( true )
    {
        cout << "What is the item price? ";
        
        float price;
        cin >> price;
        
        cout << "What city? ";
        
        string city;
        cin >> city;
        
        float tax = 0.08;
        
        if ( city == "Olathe" )
        {
            tax = 0.065;
        }
        else if ( city == "OverlandPark" )
        {
            tax = 0.0935;
        }
        else if ( city == "Raytown" )
        {
            tax = 0.08225;
        }
        else if ( city == "Independence" )
        {
            tax = 0.07725;
        }
        
        float total = price + price * tax;
        
        cout << "Total price is: $" << total << endl;
        
        cout << endl << endl;
    }
    
    return 0;
}
