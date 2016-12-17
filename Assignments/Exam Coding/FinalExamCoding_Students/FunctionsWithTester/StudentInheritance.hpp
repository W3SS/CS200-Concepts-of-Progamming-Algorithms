#ifndef _STUDENT_INHERITANCE_HPP
#define _STUDENT_INHERITANCE_HPP

#include <iostream>
using namespace std;

const float PI = 3.14;

/*
* Base class: Shape
*
* Member methods:
* GetArea. No input, returns float. Is pure virtual.
* GetPerimeter. No input, returns float. Is pure virtual.
*/

/*
* Child class 1: Rectangle
* Inherits from Shape
*
* Private/protected member variables:
*	width, float
*	height, float
*
* Member methods:
*	SetDimensions
*		Return type: void
*		Inputs: a new width and height
*
*		Set the private member variables' values to the input values.
*
*	GetWidth
*		Return the value of width
*
*	GetHeight
*		Return the value of height
*
*	GetArea, inherited from Shape
*		Return the rectangle's area (width x height)
*
*	GetPerimeter, inherited from Shape
*		Return the rectangle's perimeter (2 x width + 2 x height)
*/

/*
* Child class 2: Circle
* Inherits from Shape
*
* Private/protected member variables:
*	radius, float
*
* Member methods:
*	SetRadius
*		Return type: void
*		Input: a new radius
*
*		Set the private member variable (radius) to the input value.
*
*	GetRadius
*		Return the value of radius
*
*	GetArea, inherited from Shape
*		Return the circle's area (PI x radius^2)
*
*	GetPerimeter, inherited from Shape
*		Return the circle's circumference (2 x PI x radius)
*/



#endif