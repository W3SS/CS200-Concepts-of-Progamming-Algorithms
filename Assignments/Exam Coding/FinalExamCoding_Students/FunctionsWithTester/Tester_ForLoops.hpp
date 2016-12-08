#ifndef TESTER_FORLOOPS_HPP
#define TESTER_FORLOOPS_HPP

#include "StudentFunctions.hpp"

#include <string>
#include <iostream>
using namespace std;

class ForLoopTester
{
public:
	static void Start()
	{
		ReverseStringTest();
		SumArrayTest();
	}

private:
	static void ReverseStringTest()
	{
		bool passed = true;

		string inputs[] = { "qwerty", "cats", "12345", "a", "ABxz" };
		string outputs[] = { "ytrewq", "stac", "54321", "a", "zxBA" };

		for (int i = 0; i < 5; i++)
		{
			string actualOutput = ReverseString(inputs[i]);

			if (actualOutput != outputs[i])
			{
				passed = false;
				cout << "x \t ReverseString Fail \t Input: " << inputs[i]
					<< ", expected output: " << outputs[i]
					<< ", but got " << actualOutput << " instead." << endl;
			}

		}

		if (passed)
		{
			cout << "o \t ReverseString function passed" << endl;
		}
	}

	static void SumArrayTest()
	{
		bool passed = true;

		int output;
		int expected;

		// Test 1
		int array1[] = { 1, 2, 3 };
		output = SumArray(array1, 3);
		expected = 6;

		if (output != expected)
		{
			passed = false;
			cout << "x \t SumArray Fail \t Input:";
			for (int i = 0; i < 3; i++) {
				cout << " " << array1[i];
			}
			cout << ", expected output: " << expected
				<< ", but got " << output << " instead." << endl;
		}

		// Test 2
		int array2[] = { 2, 4, 6, 8, 10 };
		output = SumArray(array2, 5);
		expected = 30;

		if (output != expected)
		{
			passed = false;
			cout << "x \t SumArray Fail \t Input:";
			for (int i = 0; i < 5; i++) {
				cout << " " << array2[i];
			}
			cout << ", expected output: " << expected
				<< ", but got " << output << " instead." << endl;
		}

		// Test 3
		int array3[] = { 100 };
		output = SumArray(array3, 1);
		expected = 100;

		if (output != expected)
		{
			passed = false;
			cout << "x \t SumArray Fail \t Input:";
			for (int i = 0; i < 1; i++) {
				cout << " " << array3[i];
			}
			cout << ", expected output: " << expected
				<< ", but got " << output << " instead." << endl;
		}

		if (passed)
		{
			cout << "o \t SumArray function passed" << endl;
		}
	}
};

#endif