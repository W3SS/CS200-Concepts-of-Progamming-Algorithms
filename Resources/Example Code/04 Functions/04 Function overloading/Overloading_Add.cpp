#include <iostream>
using namespace std;

int Add( int a, int b )
{
    return a + b;
}

float Add( float a, float b )
{
    return a + b;
}

int main()
{
    float num1 = 2.3;
    float num2 = 3.4;

    float result = Add( num1, num2 );

    cout << result << endl;

    int num3 = 2;
    int num4 = 5;

    float result2 = Add( num3, num4 );

    cout << result2 << endl;

    return 0;
}
