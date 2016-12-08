#ifndef TESTER_IFSTATEMENTS_HPP
#define TESTER_IFSTATEMENTS_HPP

#include "IfStatements.hpp"

#include <string>
#include <iostream>
using namespace std;

class IfStatementTester
{
public:
	static void Start()
	{
		GetCaloriesTest();
		GetLetterGradeTest();
	}

private:
	static void GetCaloriesTest()
	{
		bool passed = true;
		cout << endl << "TEST: GetCalories" << endl;

		string inputsA[] = { "mayo", "mayo", "ice cream", "ice cream", "blarg" };
		bool inputsB[] = { true, false, true, false, true };
		int outputs[] = { 15, 57, 200, 300, 0 };

		for (int i = 0; i < 5; i++)
		{
			int actualOutput = GetCalories(inputsA[i], inputsB[i]);

			if (actualOutput != outputs[i])
			{
				passed = false;
				cout << endl
					<< "x FAILED TEST " << i << ": " << endl
					<< "\t Inputs:          \"" << inputsA[i] << "\", " << inputsB[i] << endl
					<< "\t Expected output:  " << outputs[i] << endl
					<< "\t Actual output:    " << actualOutput << endl;
			}
		}

		if (passed) 
		{
			cout << "\t PASSED" << endl;
		}
	}

	static void GetLetterGradeTest()
	{
		bool passed = true;
		cout << endl << "TEST: GetLetterGrade" << endl;

		int testCount = 6;
		float inputsA[] = { 100, 9, 89, 7.9, 69, 1, };
		float inputsB[] = { 100, 10, 100, 10, 100, 5 };
		string outputs[] = { "A", "A", "B", "C", "D", "F" };

		for (int i = 0; i < testCount; i++)
		{
			string actualOutput = GetLetterGrade(inputsA[i], inputsB[i]);

			if (actualOutput != outputs[i])
			{
				passed = false;
				cout << endl
					<< "x FAILED TEST " << i << ": " << endl
					<< "\t Inputs:          \"" << inputsA[i] << "\", " << inputsB[i] << endl
					<< "\t Expected output:  " << outputs[i] << endl
					<< "\t Actual output:    " << actualOutput << endl;
			}
		}

		if (passed)
		{
			cout << "\t PASSED" << endl;
		}
	}


};

#endif