#include <iostream>
using namespace std;

float Slope( float x1, float y1, float x2, float y2 )
{
    return ( y2 - y1 ) / ( x2 - x1 );
}

int main()
{
    float slope = Slope( 1, 2, 0.5, 1 );
    cout << "Slope: " << slope << endl;

    slope = Slope( 5, 4, 0.3, 0.2 );
    cout << "Slope: " << slope << endl;

    slope = Slope( 0, 0, 100, 0 );
    cout << "Slope: " << slope << endl;

    float x1, y1, x2, y2;
    cout << "Enter x and y: ";
    cin >> x1 >> y1;
    cout << "Enter 2nd x and y: ";
    cin >> x2 >> y2;

    slope = Slope( x1, y1, x2, y2 );
    cout << "Slope: " << slope << endl;


    return 0;
}
