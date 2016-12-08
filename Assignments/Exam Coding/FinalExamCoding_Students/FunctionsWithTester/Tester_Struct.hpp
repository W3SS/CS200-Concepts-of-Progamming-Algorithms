#ifndef TESTER_STRUCT_HPP
#define TESTER_STRUCT_HPP

#include "StudentStructs.hpp"

#include <string>
#include <iostream>
using namespace std;

class StructTester
{
public:
	static void Start()
	{
		TestCoordinatePair();
	}

private:
	static void TestCoordinatePair()
	{
		bool passed = true;

		CoordinatePair a, b, c, d;

		// Set X, Y tests:
		a.SetX(5);
		if (a.GetX() != 5)
		{
			passed = false;
			cout << "x \t CoordinatePair Fail \t"
				<< "Tried to set X coordinate, but didn't get value back.\t"
				<< "Check your SetX or GetX functions!" << endl;
		}

		a.SetY(10);
		if (a.GetY() != 10)
		{
			passed = false;
			cout << "x \t CoordinatePair Fail \t"
				<< "Tried to set Y coordinate, but didn't get value back.\t"
				<< "Check your SetY or GetY functions!" << endl;
		}

		a.Setup(2, 3);
		if (a.GetX() != 2 || a.GetY() != 3)
		{
			passed = false;
			cout << "x \t CoordinatePair Fail \t"
				<< "Tried to set X and Y coordinates, but didn't get value back.\t"
				<< "Check your Setup, GetX, or GetY functions!" << endl;
		}

		// Distance tests:
		a.Setup(0, 0);
		b.Setup(0, 5);
		c.Setup(-10, 2);
		d.Setup(10, 2);

		float distance = a.GetDistance(b);
		if (distance != 5.0)
		{
			passed = false;
			cout << "x \t CoordinatePair Fail \n\t"
				<< "Tried to check distance between points: "
				<< "(" << a.GetX() << ", " << a.GetY() << ") and "
				<< "(" << b.GetX() << ", " << b.GetY() << "). \n\tExpected result is 5, "
				<< "but the result was " << distance << "!" << endl;
		}

		distance = c.GetDistance(d);
		if (distance != 20.0)
		{
			passed = false;
			cout << "x \t CoordinatePair Fail \n\t"
				<< "Tried to check distance between points: "
				<< "(" << c.GetX() << ", " << c.GetY() << ") and "
				<< "(" << d.GetX() << ", " << d.GetY() << "). \n\tExpected result is 20, "
				<< "but the result was " << distance << "!" << endl;
		}

		distance = c.GetDistance(b);
		if (!(10.4402 <= distance && distance <= 10.4404)) // rounding probz
		{
			passed = false;
			cout << "x \t CoordinatePair Fail \n\t"
				<< "Tried to check distance between points: "
				<< "(" << c.GetX() << ", " << c.GetY() << ") and "
				<< "(" << b.GetX() << ", " << b.GetY() << "). \n\tExpected result is 10.4403, "
				<< "but the result was " << distance << "!" << endl;
		}

		if (passed)
		{
			cout << "o \t CoordinatePair struct passed" << endl;
		}
	}
};

#endif