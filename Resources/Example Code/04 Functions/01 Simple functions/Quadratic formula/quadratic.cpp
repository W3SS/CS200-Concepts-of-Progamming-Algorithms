#include <iostream>
#include <cmath>
using namespace std;

// FUNCTION DECLARATIONS
float QuadraticX1( float a, float b, float c );
float QuadraticX2( float a, float b, float c );

int main()
{
    float a, b, c;
    cin >> a >> b >> c;
    float x1 = QuadraticX1( a, b, c );

    return 0;
}

// FUNCTION DEFINITIONS
float QuadraticX1( float a, float b, float c )
{
    return ( -b + sqrt( b * b - 4 * a * c ) ) / ( 2 * a );
}

float QuadraticX2( float a, float b, float c )
{
    return ( -b - sqrt( b * b - 4 * a * c ) ) / ( 2 * a );
}

// Using Overloaded
float Quadratic( float a, float b, float c, float & x1, float & x2 )
{
    x1 = ( -b + sqrt( b * b - 4 * a * c ) ) / ( 2 * a );
    x2 = ( -b - sqrt( b * b - 4 * a * c ) ) / ( 2 * a );
}
