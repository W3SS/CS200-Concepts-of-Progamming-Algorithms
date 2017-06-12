#include <iostream>
#include <cmath>
using namespace std;

// FUNCTION DECLARATIONS
void Quadratic( float a, float b, float c, float & x1, float & x2 );

int main()
{
    float a, b, c, x1 = 0, x2 = 0;

    cout << "Enter a value for a, b, and c: ";
    cin >> a >> b >> c;

    cout << a << "x^2 + " << b << "x + " << c << endl;

    Quadratic( a, b, c, x1, x2 );

    cout << "x1 = " << x1 << ", x2 = " << x2 << endl;

    return 0;
}

// FUNCTION DEFINITIONS
void Quadratic( float a, float b, float c, float & x1, float & x2 )
{
    x1 = ( -b + sqrt( b * b - 4 * a * c ) ) / ( 2 * a );
    x2 = ( -b - sqrt( b * b - 4 * a * c ) ) / ( 2 * a );
}

