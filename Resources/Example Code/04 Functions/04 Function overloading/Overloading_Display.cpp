#include <iostream>
#include <string>
using namespace std;

void Display( string data )
{
    cout << "'" << data << "'" << endl;
}

void Display( float data )
{
    cout << "$" << data << endl;
}

void Display( int data )
{
    cout << "#" << data << endl;
}

int main()
{
    string productName = "Textbook";
    float price = 123.45;
    int quantity = 5;

    Display( productName );
    Display( price );
    Display( quantity );


    return 0;
}
