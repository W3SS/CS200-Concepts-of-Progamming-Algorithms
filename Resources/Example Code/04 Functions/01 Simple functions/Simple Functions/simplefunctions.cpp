#include <iostream>
#include <string>
using namespace std;

void SayHello()
{
    cout << "Hello!" << endl;
}

int FavoriteNumber()
{
    return 10;
}

float AddMe( float a, float b )
{
    return a + b;
}

string FormatName( string first, string last )
{
    return last + ", " + first;
}

int main()
{
    SayHello();

    int favorite = FavoriteNumber();
    cout << favorite << endl;

    float sum = AddMe( 2, 4 );
    cout << sum << endl;

    string formatted = FormatName( "Rachel", "Morris" );
    cout << formatted << endl;

    return 0;
}
