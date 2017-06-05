# CS 200 Lab 8: Testing

## Topics

* Functions
* Testing

## Turn In

For this project, you won't turn in a .cpp file.

Open up a text editor and answer the questions as they're
outlined.

---

# Starter code

Start with a program that contains this code:

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

---

# Testing and debugging

In this program, there are several functions already
defined and implemented - but they aren't implemented
correctly.

There are also function stubs where tests should go.
You will be filling in the tests to make sure
the functions are running correctly, and after
the tests are written you will fix the functions.

## Average

This function takes the three inputs: a, b, and c.

The result should be the average of the three variables together.

* Q: On paper (or text document), come up with
three sample input values, and the expected output value.
For example, if you enter 1, 1, and 1, then the average should be 1.

* Implement Test_Average() using the inputs and outputs
that you listed above - basically, make a function
call with the inputs you mentioned and store the output
returned. Then, compare the returned value with
your expected output. If they match, the test succeeded.
If they didn't, then the test failed.

* Paste in your Test_Average() code into the text document

* Fix the Average(float, float, float) function.

* In the text file, document what was wrong with the Average function.

## Max

* In the text document, write an expected
set of inputs and an expected output.

* Implement your test in Test_Max().

* Paste your Test_Max() code into the text document.

* Fix Max(int, int, int)

* In the text file, document what was wrong with the function.


## Factorial

A factorial n! is 

	n! = n * (n-1) * (n-2) * ... * 3 * 2 * 1

* In the text document, write an expected
set of inputs and an expected output.

* Implement your test in Test_Factorial().

* Paste your Test_Factorial() code into the text document.

* Fix Factorial.

* In the text file, document what was wrong with the function.


## FormatName

For this function, if I enter the name "Guybrush" as the first name,
and "Threepwood" as the last name, then the resulting output 
should be "Threepwood, Guybrush".

* In the text document, write an expected
set of inputs and an expected output.

* Implement your test in Test_FormatName().

* Paste your Test_FormatName() code into the text document.

* Fix FormatName.

* In the text file, document what was wrong with the function.











