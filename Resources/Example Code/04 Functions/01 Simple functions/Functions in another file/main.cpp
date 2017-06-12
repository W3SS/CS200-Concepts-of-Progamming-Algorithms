#include <iostream>
using namespace std;

#include "Maths.hpp"

int main()
{
    float num1 = 50, num2 = 10;

    float s = Sum( num1, num2 );

    float d = Difference( num1, num2 );

    cout << num1 << " + " << num2 << " = " << s << endl;
    cout << num1 << " - " << num2 << " = " << d << endl;

    return 0;
}
