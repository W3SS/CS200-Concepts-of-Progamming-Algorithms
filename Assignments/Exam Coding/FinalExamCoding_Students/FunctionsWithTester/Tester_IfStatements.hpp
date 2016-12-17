#ifndef TESTER_IFSTATEMENTS_HPP
#define TESTER_IFSTATEMENTS_HPP

#include "StudentFunctions.hpp"

#include <string>
#include <iostream>
using namespace std;

class IfStatementTester
{
public:
	static void Start()
	{
		GetMealTest();
		TicketPriceTest();
	}

private:
	static void GetMealTest()
	{
		bool passed = true;

		float inputsA[5] = { 5.00, 5.00, 2.00, 2.00, 3.99 };
		bool inputsB[5] = { true, false, true, false, true };
		string outputs[5] = { "fried rice", "hamburger", "salad", "taco", "nothing" };

		for (int i = 0; i < 5; i++)
		{
			string actualOutput = GetMeal(inputsA[i], inputsB[i]);

			if (actualOutput != outputs[i])
			{
				passed = false;
				cout << "x \t GetMeal \t Inputs: maxPrice = " << inputsA[i]
					<< ", isVegetarian = " << inputsB[i]
					<< ", expected output: " << outputs[i]
					<< ", but got " << actualOutput << " instead." << endl;
			}
		}

		if (passed)
		{
			cout << "o \t GetMeal function passed" << endl;
		}
	}

	static void TicketPriceTest()
	{
		bool passed = true;

		int inputsA[] = { 5, 10, 13, 18, 50, 60, 70,	// Not vets
			5, 10, 13, 18, 50, 60, 70 // Are vets
		};
		bool inputsB[] = { false, false, false, false, false, false, false,
			true, true, true, true, true, true, true };

		float outputs[] = { 7.99, 7.99, 8.99, 8.99, 8.99, 5.99, 5.99,
			7.99, 7.99, 8.99, 6.99, 6.99, 5.99, 5.99 };

		for (int i = 0; i < 14; i++)
		{
			float actualOutput = TicketPrice(inputsA[i], inputsB[i]);

			if (actualOutput != outputs[i])
			{
				passed = false;
				cout << "x \t TicketPrice \t Inputs: age = " << inputsA[i]
					<< ", isVet = " << inputsB[i]
					<< ", expected output: " << outputs[i]
					<< ", but got " << actualOutput << " instead." << endl;
			}
		}

		if (passed)
		{
			cout << "o \t TicketPrice function passed" << endl;
		}
	}


};

#endif