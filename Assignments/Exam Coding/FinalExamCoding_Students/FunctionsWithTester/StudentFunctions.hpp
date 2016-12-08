#ifndef _STUDENT_FUNCTIONS_HPP
#define _STUDENT_FUNCTIONS_HPP

#include <string>
#include <iostream>
using namespace std;

/* ************************************************ If Statements */

/*
* Function: GetMeal
* Return Type: String
* Input:
*	(1) maxPrice, a float
*	(2) isVegetarian, a boolean
*
* Functionality:
*	Below is the food menu. Return the food type to
*	give to the user based on the price they want to pay,
*	and whether or not they're vegetarian.
*	If they're not vegetarian, default them to the
*	dish with meat (just for simplicity sake).
*	If they specify a different price, just return "nothing".
*	(Difficult people don't get to eat?)
*
*	Requirement: Use nested if statements
*
*	FOOD		PRICE		VEGETARIAN?		
*	hamburger	5.00		No				
*	taco		2.00		No				
*
*	fried rice	5.00		Yes				
*	salad		2.00		Yes				
*/



/*
* Function: TicketPrice
* Return Type: Float
* Input:
*	(1) age, an integer
*	(2) isVet, a boolean
*
* Functionality:
*	This function will return a ticket price
*	based on the perons's age, and whether they
*	are a vet.
*
*	Ticket prices:
*	$5.99	Seniors (60+)
*	$7.99	Kids under 13
*	$6.99	Vets (must be 18 or over)
*	$8.99	Regular
*
*	Make sure that you're checking the age if
*	the person claims to be a vet; an 8 year old
*	cannot be a vet! Give them the normal price.
*
*	If they are a senior and also a vet, give them
*	the cheaper senior price.
*/



/* ************************************************ For Loops */

/*
* Function: ReverseString
* Return Type: String
* Input: String
*
* Functionality:
*	This function will take in a string as its input
*	and return another string, which is the reversed
*	version of the input string.
*
*	For example, "asdf" would be the input, 
*	and "fdsa" would be the output.
*/



/*
* Function: SumArray
* Return Type: Integer
* Input:
*	(1) an array of integers
*	(2) the size of the array (as an integer)
*
* Functionality:
*	This function will sum all of the elements in the
*	array, and return the sum as the output.
*/



#endif