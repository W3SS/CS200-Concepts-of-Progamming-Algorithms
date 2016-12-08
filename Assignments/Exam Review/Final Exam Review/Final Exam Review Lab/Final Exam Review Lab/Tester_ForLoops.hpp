#ifndef TESTER_FORLOOPS_HPP
#define TESTER_FORLOOPS_HPP

#include "ForLoops.hpp"

#include <string>
#include <iostream>
using namespace std;

class ForLoopTester
{
public:
	static void Start()
	{
		DoubleElementsTest();
		CountLetterTest();
	}

private:
	static void DoubleElementsTest()
	{
		bool passed = true;
		cout << endl << "TEST: DoubleElements" << endl;

		// Test 1
		int array1[] = { 1, 1, 3, 5, 8, 13 };
		int length1 = 6;
		int output1[] = { 2, 2, 6, 10, 16, 26 };

		DoubleElements(array1, length1);
		bool same = true;
		for (int i = 0; i < length1; i++)
		{
			if (array1[i] != output1[i])
			{
				same = false;
				passed = false;
				break;
			}
		}
		if (!same)
		{
			cout << endl
				<< "x FAILED TEST: " << endl
				<< "\t Inputs:          { 1, 1, 3, 5, 8, 13 }" << endl
				<< "\t Expected output: { 2, 2, 6, 10, 16, 26 }" << endl
				<< "\t Actual output:   { ";

			for (int j = 0; j < length1; j++)
			{
				if (j != 0) { cout << ", "; }
				cout << array1[j];
			}
			cout << " }" << endl;
		}

		// Test 2
		int array2[] = { -10, -5, 0, 5, 10, 15, 20, 25 };
		int length2 = 8;
		int output2[] = { -20, -10, 0, 10, 20, 30, 40, 50 };

		DoubleElements(array2, length2);
		same = true;
		for (int i = 0; i < length1; i++)
		{
			if (array2[i] != output2[i])
			{
				same = false;
				passed = false;
				break;
			}
		}
		if (!same)
		{
			cout << endl
				<< "x FAILED TEST: " << endl
				<< "\t Inputs:          { -10, -5, 0, 5, 10, 15, 20, 25 }" << endl
				<< "\t Expected output: { -20, -10, 0, 10, 20, 30, 40, 50 }" << endl
				<< "\t Actual output:   { ";

			for (int j = 0; j < length1; j++)
			{
				if (j != 0) { cout << ", "; }
				cout << array2[j];
			}
			cout << " }" << endl;
		}


		if (passed)
		{
			cout << "\t PASSED" << endl;
		}
	}

	static void CountLetterTest()
	{
		/*bool passed = true;
		cout << endl << "TEST: CountLetter" << endl;

		int testCount = 6;
		float inputsA[] = { 100, 9, 89, 7.9, 69, 1, };
		float inputsB[] = { 100, 10, 100, 10, 100, 5 };
		string outputs[] = { "A", "A", "B", "C", "D", "F" };

		for (int i = 0; i < testCount; i++)
		{
			string actualOutput = CountLetter(inputsA[i], inputsB[i]);

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
		}*/
	}


};

#endif