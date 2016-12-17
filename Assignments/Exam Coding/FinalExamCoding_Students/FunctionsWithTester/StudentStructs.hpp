#ifndef _STUDENT_STRUCTS_HPP
#define _STUDENT_STRUCTS_HPP

#include <cmath>

/*
* CoordinatePair Struct 
*
* Member variables:
*	x and y (floats, private)
*
* Member methods:
*	Setup
*		This function has no return value.
*		Its input is a new X and new Y coordinate.
*		It should set the private x, y member variables to
*		the input that was passed in.
*
*	SetX
*		This function has no output.
*		Its input is a new X value.
*		It should set the private member variable x to the
*		value passed in as input.
*
*	SetY
*		This function has no output.
*		Its input is a new Y value.
*		It should set the private member variable y to the
*		value passed in as input.
*
*	GetX
*		This function's output should match x's data type.
*		This function has no input.
*		This function only returns the value of the
*		private member variable x.
*
*	GetY
*		This function's output should match y's data type.
*		This function has no input.
*		This function only returns the value of the
*		private member variable y.
*
*	GetDistance
*		This function's output is of type float - the distance between two points.
*		This function's input is a second CoordinatePair object.
*		Within this function, use the distance formula to calculate
*		the distance between the 2nd point (passed in as input)
*		and the 1st point (which is this object itself)
*
*	Distance = sqrt( (x2 - x1)^2 + (y2 - y1)^2 )
*	Note that this isn't the exact code - you will have to adapt
*	it to work with your code.
*/

struct CoordinatePair
{
private:
	float x, y;

public:
	void Setup(float x, float y)
	{
	}

	void SetX(float x)
	{
	}

	void SetY(float y)
	{
	}

	float GetX()
	{
		return -100; // This is a temporary value - remove it and add your logic!
	}

	float GetY()
	{
		return -100; // This is a temporary value - remove it and add your logic!
	}

	float GetDistance(CoordinatePair coord2)
	{
		return -100; // This is a temporary value - remove it and add your logic!
	}
};

#endif