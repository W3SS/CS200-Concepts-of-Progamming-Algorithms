# Final Exam coding

Fall 2017

---

## Downloads

Make sure to download the **FinalExamCoding_Students.zip** file,
which contains the Visual Studio projects and files that you need.

## Tester information

In the Visual Studio project, several testers are included.

By default, your main.cpp file looks like this:

	#include <iostream>
	#include <string>
	using namespace std;

	//#include "Tester_IfStatements.hpp"
	//#include "Tester_ForLoops.hpp"
	//#include "Tester_Struct.hpp"
	//#include "Tester_Class.hpp"
	//#include "Tester_Inheritance.hpp"
	//#include "Tester_Pointers.hpp" 

	int main()
	{
		//IfStatementTester::Start();

		//ForLoopTester::Start();

		//StructTester::Start();

		//ClassTester::Start();

		//InheritanceTester::Start();

		//PointerTester::Start();


		cout << "End of program" << endl;
		while (true) {}

		return 0;
	}
	
As you implement your code, un-comment out the #include
and the Tester::Start() for whatever you just wrote.

This will help you check for build errors, and it will
also check your logic.

In order for the Tester objects to help you validate your code,
you will have to make sure that your class and function
names match the specification. Otherwise, your code
won't build.

Note that, just because the tester doesn't find a problem,
doesn't mean that your code is 100% correct. There are
multiple ways to implement solutions, so make sure
that you're following the spec in order to get full credit!

---

## Part 1: If Statements

**Code for this portion will go in the StudentFunctions.hpp file.**

You will implement two functions that utilize if statements.

To test these functions, uncomment out 

	#include "Tester_IfStatements.hpp" 

and 

	IfStatementTester::Start();

### GetMeal

* Output: A string (the meal's name)
* Input:
	* maxPrice, a float
	* isVegetarian, a boolean
	
Below is the food menu. Return the food type to
give to the user based on the price they want to pay,
and whether or not they're vegetarian.
If they're not vegetarian, default them to the
dish with meat (just for simplicity sake).
If they specify a different price, just return "nothing".
(Difficult people don't get to eat?)

<table>
<tr>
	<th>FOOD</th><th>PRICE</th><th>VEGETARIAN DISH?</th>
</tr>

<tr>
	<td>hamburger</td><td>5.00</td><td>No</td>
</tr>
<tr>
	<td>taco</td><td>2.00</td><td>No</td>
</tr>

<tr>
	<td>fried rice</td><td>5.00</td><td>Yes</td>
</tr>
<tr>
	<td>salad</td><td>2.00</td><td>Yes</td>
</tr>
</table>

### TicketPrice

* Output: A float (the price of a ticket)
* Input:
	* age, an integer
	* isVet, a boolean
	
This function will return a ticket price
based on the perons's age, and whether they
are a vet.

Ticket prices:

* $5.99	- Seniors (60+)
* $7.99	- Kids under 13
* $6.99	- Vets (must be 18 or over)
* $8.99	- Regular

Make sure that you're checking the age if
the person claims to be a vet; an 8 year old
cannot be a vet! Give them the normal price.

If they are a senior and also a vet, give them
the cheaper senior price.

---

## Part 2: For Loops

**Code for this portion will go in the StudentFunctions.hpp file.**

To test these functions, uncomment out

	#include "Tester_ForLoops.hpp" 

and 

	ForLoopTester::Start();

### ReverseString

* Input: A string
* Output: The input string, only reversed

This function will take in a string as its input
and return another string, which is the reversed
version of the input string.

For example, "asdf" would be the input, 
and "fdsa" would be the output.

### SumArray

* Input: 
	* an array of integers
	* an integer, which specifies the size of the array
* Output: The sum of integers from the array

This function will sum all of the elements in the
array, and return the sum as the output.

---

## Part 3: Struct

**Code for this portion will go in the StudentStructs.hpp file.**

To test these functions, uncomment out

	#include "Tester_Struct.hpp" 

and 

	StructTester::Start();

### CoordinatePair

Create a struct called CoordinatePair.

#### Private member variables:

* x and y, both integers

#### Member methods:

##### Setup

This function has no return value.

Its input is a new X and new Y coordinate.

It should set the private x, y member variables to
the input that was passed in.

##### SetX

This function has no output.

Its input is a new X value.

It should set the private member variable x to the
value passed in as input.

##### SetY

This function has no output.

Its input is a new Y value.

It should set the private member variable y to the
value passed in as input.

##### GetX

This function's output should match x's data type.

This function has no input.

This function only returns the value of the
private member variable x.

##### GetY

This function's output should match y's data type.

This function has no input.

This function only returns the value of the
private member variable y.

##### GetDistance

This function's output is of type float - the distance between two points.

This function's input is a second CoordinatePair object.

Within this function, use the distance formula to calculate
the distance between the 2nd point (passed in as input)
and the 1st point (which is this object itself)

**Distance = sqrt( (x2 - x1)^2 + (y2 - y1)^2 )**

Note that this isn't the exact code - you will have to adapt
it to work with your code.

You might need to include the <cmath> library.

---

## Part 4: Class

**Code for this portion will go in the StudentClass.hpp file.**

To test these functions, uncomment out

	#include "Tester_Class.hpp" 

and 

	ClassTester::Start();

### DictionaryEntry

A DictionaryEntry struct is already implemented.
You will use this in the Dictionary object.

### Dictionary

#### Private member variables:

* entries, an array of DictionaryEntry objects. Its size is 6.
* size, an integer.

#### Member methods:

##### Dictionary Constructor

Initializes the following items in the dictionary.
Also sets the size to 6.

<table>
<tr><th>ENGLISH</th><th>HINDI</th></tr>

<tr>
<td>cat</td><td>billee</td>
</tr><tr>
<td>dog</td><td>kuttaa</td>
</tr><tr>
<td>mouse</td><td>kuhaa</td>
</tr><tr>
<td>rabbit</td><td>khargosh</td>
</tr><tr>
<td>frog</td><td>mendak</td>
</tr><tr>
<td>sheep</td><td>bhed</td>
</tr>
</table>

##### GetSize

Returns the size of the array, which should be stored
in the private member variable "size".

##### EnglishToHindi

Input: an English string

Output: a Hindi string

Search the entries array. If you can find an entry
whose english string is the same as the input,
then return that entry's hindi string as the output.


##### HindiToEnglish

Input: a Hindi string

Output: an English string

Search the entries array. If you can find an entry
whose hindi string is the same as the input,
then return that entry's english string as the output.

---

## Part 5: Inheritance

**Code for this portion will go in the StudentInheritance.hpp file.**

To test these functions, uncomment out

	#include "Tester_Inheritance.hpp" 

and 

	InheritanceTester::Start();

### Shape class

This is the base class. It is an abstract base class.

#### Member methods:

##### GetArea

* Output: A float (the area)
* Input: None
* Other: Is pure virtual (no definition)

##### GetPerimeter

* Output: A float (the perimeter)
* Input: None
* Other: Is pure virtual (no definition)


### Rectangle class

Rectangle class inherits from **Shape**.

#### Private member variables:

* width, a float
* height, a float

#### Member methods:

##### SetDimensions

* Input: A new width and height
* Output: none

Sets the private member variables' values to the corresponding input given.

Error checking: If the width is less than 0, then **don't** update the width at all!

Error checking: If the height is less than 0, then **don't** update the height at all!

##### GetWidth

Returns the value of width.

##### GetHeight

Returns the value of height.

##### GetArea

This function inherits from Shape and should match its input/output.

This should return the rectangle's area. (width x height)

##### GetPerimeter

This function inherits from Shape and should match its input/output.

Returns the rectangle's perimeter. (2 x width + 2 x height )


### Circle class

#### Private member variables:

* radius, a float

#### Member methods:


##### SetRadius

* Input: A new radius
* Output: nothing

Sets the private member variable for radius to the input that was passed in.

Error checking: If the radius is less than 0, then **don't** update the radius at all!

##### GetRadius

Returns the value of radius.

##### GetArea

This function inherits from Shape and should match its input/output.

Return the circle's area. (PI x radius^2)

##### GetPerimeter

This function inherits from Shape and should match its input/output.

Returns the circle's circumference (2 x PI x radius)

---

## Part 6: Pointers

**Code for this portion will go in the StudentPointers.hpp file.**

To test these functions, uncomment out

	#include "Tester_Pointers.hpp" 

and 

	PointerTester::Start();

### GetAddress

* Input: An integer reference
* Output: An integer pointer

Return the address of the input variable.



### GetValue

* Input: An integer pointer
* Output: An integer

Return the value that the pointer is pointing at.



### CheckifNull

* Input: An integer pointer
* Output: boolean (if it is null)

If the pointer is null, return true.
Otherwise, return false.



### CompareAddresses

* Input: Two integer pointers
* Output: boolean (if it is null)

If the two pointers are pointing to the same
address, return true. Otherwise, return false.



### CompareValues

* Input: Two integer pointers
* Output: boolean (if it is null)

For both pointers, look at their values
that they are pointing to. If the values
are equal, return true. Otherwise,
return false.



