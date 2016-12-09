# Final Exam Review (coding portion)

Fall 2016

---

## Downloads

Download the **Final Exam Review Lab.zip** file to work from.

## Tester information

In the Visual Studio project, several testers are included.

By default, your main.cpp file looks like this:

	#include <iostream>
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
	
		cout << endl << "Tests done" << endl;
		while (true) { ; }
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

**Code for this portion will go in the IfStatements.hpp file.**

You will implement two functions that utilize if statements.

To test these functions, uncomment out 

	#include "Tester_IfStatements.hpp" 

and 

	IfStatementTester::Start();

### GetCalories

* Input: 
	* (1) foodName, a string
	* (2) isLowFat, a boolean
* Output: The amount of calories (int)

There are the following types of foods available:

<table>
	<tr>
		<th>Food</th><th>Normal calories</th><th>Low-fat calories</th>
	</tr>

	<tr>
		<td>mayo</td><td>57</td><td>15</td>
	</tr>

	<tr>
		<td>ice cream</td><td>300</td><td>200</td>
	</tr>
</table>

The user will pass in a food name ("mayo" or "ice cream") and whether it's the low-fat version.

Utilize nested if statements to return the appropriate calorie amount.

If an invalid food is entered, return 0.

### GetLetterGrade

* Input:
	* (1) studentPoints, a float
	* (2) totalPoints, a float
* Output: The letter grade (string)

Calculate the student's score by dividing
the student's points by the total points.

Use the following information to decide
what letter grade to return:

* 90 or above: A
* 80 to 89: B
* 70 to 79: C
* 60 to 69: D
* below 60: F

---

## Part 2: For Loops

**Code for this portion will go in the ForLoops.hpp file.**

You will implement two functions that utilize if statements.

To test these functions, uncomment out 

	#include "Tester_ForLoops.hpp" 

and 

	ForLoopTester::Start();

### DoubleElements

* Input:
	* (1) an array of integers
	* (2) an integer that specifies the array length
* Output: nothing

Use a for loop to iterate through every element
of the array, doubling the value of each element.

### CountLetter

* Input:
	* (1) text, a string
	* (2) letter, a char
* Output: the amount of that letter found in the text (int)

Use a for loop to iterate through every letter of the input *text*. If that letter is the same as the *letter* passed in as input, then add 1 to the tally of appearances of that letter.

---

## Part 3: Struct

**Code for this portion will go in the Struct.hpp file.**

You will implement two functions that utilize if statements.

To test these functions, uncomment out 

	#include "Tester_Struct.hpp" 

and 

	StructTester::Start();

### Fraction struct

Create a struct called Fraction.

#### Private member variables:

* num and denom, both integers

#### Methods:

##### SetNum

* Input: the new numerator, an integer
* Output: none

Set the private member variable num equal
to the value passed in.

##### SetDenom

* Input: the new denominator, an integer
* Output: none

Set the private member variable denom equal
to the value passed in.

Error checking: However, if the user has passed in 0,
do not change anything!

##### GetNum

* Input: none
* Output: the numerator (an integer)

Return the value of the private member variable
that corresponds with this function.

##### GetDenom

* Input: none
* Output: the denominator (an integer)

Return the value of the private member variable
that corresponds with this function.

##### Multiply

* Input: A Fraction object
* Output: The proudct - A Fraction object

You will multiply the current Fraction object
by the other Fraction that is passed in.

Return a new Fraction (the product) as the result.

* Product numerator is numerator1 x numerator2
* Product denomintor is denominator1 x denominator2

---

## Part 4: Class

**Code for this portion will go in the Class.hpp file.**

You will implement two functions that utilize if statements.

To test these functions, uncomment out 

	#include "Tester_Class.hpp" 

and 

	ClassTester::Start();

### Course class

#### Private member variables:

* m_students, an array of strings, size 5.
* m_studentCount, an integer - the amount of students in the array.
* m_name, a string - the name of the course.

#### Methods:

##### Course constructor

The Course constructor should initialize
the value of *m_studentCount* to 0.

##### SetName

* Input: A new course name (string)
* Output: none

This should set the corresponding private member variable
to the value that is passed in.

##### GetName

* Input: none
* Output: The course name (string)

This should return the corresponding private member variable.

##### GetStudentCount

* Input: none
* Output: The student count (int)

This should return the corresponding private member variable.

##### AddStudent

* Input: the name of a new student (string)
* Output: nothing

If the array of students is full (that is, if it is equal to 5), then this function will not do anything.

However, if the array is not full (student count is
less than 5), it will add the new student's name into the array at the next empty space, and increment the student count variable by 1.

##### GetStudent

* Input: the index of a student (an integer)
* Output: A student's name (string)

If the index is invalid (less than 0, or greater than or equal to 5), return an empty string.

Otherwise, return the student at that index.

---

## Part 5: Inheritance

**Code for this portion will go in the Inheritance.hpp file.**

You will implement two functions that utilize if statements.

To test these functions, uncomment out 

	#include "Tester_Inheritance.hpp" 

and 

	InheritanceTester::Start();

### Cipher class

This is the base class

#### Methods:

##### Encrypt

* Input: text, a string
* Output: The encrypted text, a string
* Other: Just have the function body be empty.

##### Decrypt

* Input: text, a string
* Output: The decrypted text, a string
* Other: Just have the function body be empty.

### CaesarCipher class

CaesarCipher inherits from **Cipher**.

#### Methods:

##### StepForward

Use the following function as part of this class:

	char SwapForward(char letter)
	{
		if (letter == 'A') { return 'B'; }
		if (letter == 'B') { return 'C'; }
		if (letter == 'C') { return 'D'; }
		if (letter == 'D') { return 'E'; }
		if (letter == 'E') { return 'F'; }
		if (letter == 'F') { return 'G'; }
		if (letter == 'G') { return 'H'; }
		if (letter == 'H') { return 'I'; }
		if (letter == 'I') { return 'J'; }
		if (letter == 'J') { return 'K'; }
		if (letter == 'K') { return 'L'; }
		if (letter == 'L') { return 'M'; }
		if (letter == 'M') { return 'N'; }
		if (letter == 'N') { return 'O'; }
		if (letter == 'O') { return 'P'; }
		if (letter == 'P') { return 'Q'; }
		if (letter == 'Q') { return 'R'; }
		if (letter == 'R') { return 'S'; }
		if (letter == 'S') { return 'T'; }
		if (letter == 'T') { return 'U'; }
		if (letter == 'U') { return 'V'; }
		if (letter == 'V') { return 'W'; }
		if (letter == 'W') { return 'X'; }
		if (letter == 'X') { return 'Y'; }
		if (letter == 'Y') { return 'Z'; }
		if (letter == 'Z') { return 'A'; }
	}

##### StepBackward

Use the following function as part of this class:

	char SwapBackward(char letter)
	{
		if (letter == 'A') { return 'Z'; }
		if (letter == 'B') { return 'A'; }
		if (letter == 'C') { return 'B'; }
		if (letter == 'D') { return 'C'; }
		if (letter == 'E') { return 'D'; }
		if (letter == 'F') { return 'E'; }
		if (letter == 'G') { return 'F'; }
		if (letter == 'H') { return 'G'; }
		if (letter == 'I') { return 'H'; }
		if (letter == 'J') { return 'I'; }
		if (letter == 'K') { return 'J'; }
		if (letter == 'L') { return 'K'; }
		if (letter == 'M') { return 'L'; }
		if (letter == 'N') { return 'M'; }
		if (letter == 'O') { return 'N'; }
		if (letter == 'P') { return 'O'; }
		if (letter == 'Q') { return 'P'; }
		if (letter == 'R') { return 'Q'; }
		if (letter == 'S') { return 'R'; }
		if (letter == 'T') { return 'S'; }
		if (letter == 'U') { return 'T'; }
		if (letter == 'V') { return 'U'; }
		if (letter == 'W') { return 'V'; }
		if (letter == 'X') { return 'W'; }
		if (letter == 'Y') { return 'X'; }
		if (letter == 'Z') { return 'Y'; }
	}

##### Encrypt (Inherited from Cipher)

Build a new string, which is the encrypted text.

Iterate through every letter of the *text* string
using a for-loop. For every letter,
the encrypted version is that letter plus 1.

For example, A -> B, D -> E, and Z -> A.

Use the StepForward function.


##### Decrypt (Inherited from Cipher)

Build a new string, which is the decrypted text.

Iterate through every letter of the *text* string
using a for-loop. For every letter,
the decrypted version is that letter minus 1.

For example, B -> A, E -> D, A -> Z.

Use the StepBackward function.


### SubCipher class

SubCipher inherits from **Cipher**.

#### Private member variables:

* m_alphabetOriginal, an array of 26 chars.
* m_alphabetSwap, an array of 26 chars.

#### Methods:

##### SubCipher constructor

Use this constructor:

	SubCipher()
	{
		for (int i = 0; i <= 25; i++)
		{
			m_alphabetOriginal[i] = char(65 + i);
			m_alphabetSwap[i] = char(90 - i);
		}
	}

##### FindLetterPosition

Use the following function:

	int FindLetterPosition(char letter, string whichList)
	{
		if (whichList == "original")
		{
			for (int i = 0; i < 26; i++)
			{
				if (m_alphabetOriginal[i] == letter)
				{
					return i;
				}
			}
		}
		else if (whichList == "swap")
		{
			for (int i = 0; i < 26; i++)
			{
				if (m_alphabetSwap[i] == letter)
				{
					return i;
				}
			}
		}
		return -1;
	}

##### Encrypt (Inherited from Cipher)

Use the following code within the function:

	string encrypted = "";
	for (int i = 0; i < text.size(); i++)
	{
		int letterIndex = FindLetterPosition(text[i], "original");
		if (letterIndex == -1) { encrypted += " "; }
		else
		{
			encrypted += m_alphabetSwap[letterIndex];
		}
	}

	return encrypted;

##### Decrypt (Inherited from Cipher)

Use the following code within the function:

	string decrypted = "";
	for (int i = 0; i < text.size(); i++)
	{
		int letterIndex = FindLetterPosition(text[i], "swap");
		if (letterIndex == -1) { decrypted += " "; }
		else
		{
			decrypted += m_alphabetOriginal[letterIndex];
		}
	}

	return decrypted;

---

## Part 6: Pointers

**Code for this portion will go in the Pointers.hpp file.**

You will implement two functions that utilize if statements.

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



### CheckIfNull

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
