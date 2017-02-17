#include <iostream>
#include <string>
using namespace std;

float Average( float a, float b, float c )
{
	return a + b + c / 3;
}

void Test_Average()
{
}

int Max( int a, int b, int c )
{
	if ( a < b )
	{
		return b;
	}
	else
	{
		return c;
	}
	return a;
}

void Test_Max()
{
}

int Factorial( int n )
{
	int fac = n;
	for ( int i = n; i >= 0; i-- )
	{
		fac = fac * i;
	}
	return fac;
}

void Test_Factorial()
{
}

string FormatName( string first, string last )
{
	return last + "," + first;
}

void Test_FormatName()
{
}

int main()
{
	Test_Average();
	Test_Max();
	Test_Factorial();
	Test_FormatName();
	
	return 0;
}