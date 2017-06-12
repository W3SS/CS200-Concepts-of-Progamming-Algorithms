#include <iostream>
#include <cmath>
using namespace std;

// FUNCTION DECLARATION
float Pythagorean( float a, float b );

int main()
{
    float num1, num2;

    cout << "What is a? ";
    cin >> num1;

    cout << "What is b? ";
    cin >> num2;

    float c = Pythagorean( num1, num2 ); // Arguments

    cout << "c = " << c << endl;

    return 0;
}

// FUNCTION DEFINITION
float Pythagorean( float a, float b ) // Parameters
{
    float cSquared = (a*a) + (b*b);
    float c = sqrt( cSquared );
    return c;
}
