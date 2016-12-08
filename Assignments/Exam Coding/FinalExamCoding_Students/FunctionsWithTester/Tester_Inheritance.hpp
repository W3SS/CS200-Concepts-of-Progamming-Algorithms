#ifndef TESTER_INHERITANCE_HPP
#define TESTER_INHERITANCE_HPP

#include "StudentInheritance.hpp"

#include <string>
#include <iostream>
using namespace std;

class InheritanceTester
{
public:
	static void Start()
	{
		TestShapes();
	}

private:
	static void TestShapes()
	{
		bool passed = true;

		Rectangle r;
		Circle c;

		r.SetDimensions(3, 7);

		if (r.GetWidth() != 3)
		{
			passed = false;
			cout << "x Rectangle Fail \t"
				<< "Tried to set width to 3, but GetWidth returns "
				<< r.GetWidth() << endl;
		}
		if (r.GetHeight() != 7)
		{
			passed = false;
			cout << "x Rectangle Fail \t"
				<< "Tried to set height to 7, but GetWidth returns "
				<< r.GetHeight() << endl;
		}

		r.SetDimensions(-5, -5);

		if (r.GetWidth() == -5)
		{
			passed = false;
			cout << "x Rectangle Fail \t"
				<< "Tried to set width to a negative number, and it was allowed." << endl;
		}
		if (r.GetHeight() == -5)
		{
			passed = false;
			cout << "x Rectangle Fail \t"
				<< "Tried to set height to a negative number, and it was allowed." << endl;
		}

		c.SetRadius(3);
		if (c.GetRadius() != 3)
		{
			passed = false;
			cout << "x Circle Fail \t"
				<< "Tried to set radius to 3, but GetRadius returns " << c.GetRadius() << endl;
		}

		c.SetRadius(-5);
		if (c.GetRadius() == -5)
		{
			passed = false;
			cout << "x Circle Fail \t"
				<< "Tried to set radius to a negative number, and it was allowed." << endl;
		}


		r.SetDimensions(3, 7);
		float area = r.GetArea();
		float perimeter = r.GetPerimeter();

		if (area != 21)
		{
			passed = false;
			cout << "x Rectangle Fail \t"
				<< "Rectangle should be 3x7, area should be 21,"
				<< " but the area returned was " << area << endl;
		}

		if (perimeter != 20)
		{
			passed = false;
			cout << "x Rectangle Fail \t"
				<< "Rectangle should be 3x7, perimeter should be 20,"
				<< " but the perimeter returned was " << perimeter << endl;
		}

		c.SetRadius(3);
		area = c.GetArea();
		perimeter = c.GetPerimeter();

		if (!(28.25 <= area && area <= 28.27)) // rounding probz
		{
			passed = false;
			cout << "x Circle Fail \t"
				<< "Circle radius should be 3, area should be 28.26,"
				<< " but the area returned was " << area << endl;
		}

		if (!(18.83 <= perimeter && perimeter <= 18.85)) // rounding probz
		{
			passed = false;
			cout << "x Circle Fail \t"
				<< "Circle radius should be 3, perimeter should be 18.84,"
				<< " but the perimeter (circumference) returned was " << perimeter << endl;
		}

		if (passed)
		{
			cout << "o \t Shapes classes passed" << endl;
		}
	}
};

#endif