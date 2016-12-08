#ifndef TESTER_STRUCT_HPP
#define TESTER_STRUCT_HPP

#include "Struct.hpp"

#include <string>
#include <iostream>
using namespace std;

class StructTester
{
public:
	static void Start()
	{
		Test();
	}

private:
	static void Test()
	{
		bool passed = true;
		cout << endl << "TEST: Fraction struct" << endl;

		Fraction a, b, c;

		// Test 1 - Setters/Getters
		a.SetNum(1);
		if (a.GetNum() != 1)
		{
			passed = false;
			cout << endl
				<< "x FAILED TEST: " << endl
				<< "\t Set fraction numerator to 1, but GetNum returns " << a.GetNum() << endl;
		}

		a.SetDenom(2);
		if (a.GetDenom() != 2)
		{
			passed = false;
			cout << endl
				<< "x FAILED TEST: " << endl
				<< "\t Set fraction denominator to 2, but GetDenom returns " << a.GetDenom() << endl;
		}

		a.SetDenom(0);
		if (a.GetDenom() == 0)
		{
			passed = false;
			cout << endl
				<< "x FAILED TEST: " << endl
				<< "\t Set fraction denominator to 0, which is invalid, but it was allowed" << endl;
		}

		// Test 2
		a.SetNum(1);
		a.SetDenom(2);

		b.SetNum(1);
		b.SetDenom(2);

		c = a.Multiply(b);

		if (c.GetNum() != 1 || c.GetDenom() != 4)
		{
			passed = false;
			cout << endl
				<< "x FAILED TEST: " << endl
				<< "\t Fraction multiplication failed." << endl
				<< "\t Fraction 1: " << a.GetNum() << "/" << a.GetDenom() << endl
				<< "\t Fraction 2: " << b.GetNum() << "/" << b.GetDenom() << endl
				<< "\t Expected result: 1/4" << endl
				<< "\t Actual result: " << c.GetNum() << "/" << c.GetDenom() << endl;
		}

		// Test 3
		a.SetNum(3);
		a.SetDenom(7);

		b.SetNum(11);
		b.SetDenom(13);

		c = a.Multiply(b);

		if (c.GetNum() != 33 || c.GetDenom() != 91)
		{
			passed = false;
			cout << endl
				<< "x FAILED TEST: " << endl
				<< "\t Fraction multiplication failed." << endl
				<< "\t Fraction 1: " << a.GetNum() << "/" << a.GetDenom() << endl
				<< "\t Fraction 2: " << b.GetNum() << "/" << b.GetDenom() << endl
				<< "\t Expected result: 33/91" << endl
				<< "\t Actual result: " << c.GetNum() << "/" << c.GetDenom() << endl;
		}

		c = b.Multiply(a);

		if (c.GetNum() != 33 || c.GetDenom() != 91)
		{
			passed = false;
			cout << endl
				<< "x FAILED TEST: " << endl
				<< "\t Fraction multiplication failed." << endl
				<< "\t Fraction 1: " << b.GetNum() << "/" << b.GetDenom() << endl
				<< "\t Fraction 2: " << a.GetNum() << "/" << a.GetDenom() << endl
				<< "\t Expected result: 33/91" << endl
				<< "\t Actual result: " << c.GetNum() << "/" << c.GetDenom() << endl;
		}

		if (passed)
		{
			cout << "\t PASSED" << endl;
		}
	}
};

#endif