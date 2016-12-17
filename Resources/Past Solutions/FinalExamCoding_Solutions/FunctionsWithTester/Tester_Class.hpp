#ifndef TESTER_CLASS_HPP
#define TESTER_CLASS_HPP

#include "StudentClass.hpp"

#include <string>
#include <iostream>
using namespace std;

class ClassTester
{
public:
	static void Start()
	{
		TestDictionary();
	}

private:
	static void TestDictionary()
	{
		bool passed = true;

		Dictionary dict;

		if (dict.GetSize() != 6)
		{
			passed = false;
			cout << "x \t Dictionary Fail \t Expected size to be 6."
				<< " Instead, it is " << dict.GetSize() << endl;
		}

		string inputsA[] = { "cat", "dog", "mouse", "rabbit", "frog", "sheep", "coffee" };
		string outputsA[] = { "billee", "kuttaa", "kuhaa", "khargosh", "mendak", "bhed", "" };

		string inputsB[] = { "billee", "kuttaa", "kuhaa", "khargosh", "mendak", "bhed", "kophee" };
		string outputsB[] = { "cat", "dog", "mouse", "rabbit", "frog", "sheep", "" };

		for (int i = 0; i < 6; i++)
		{
			string actualOutput = dict.EnglishToHindi(inputsA[i]);
			if (actualOutput != outputsA[i])
			{
				passed = false;
				cout << "x \t Dictionary Fail \t"
					<< "EnglishToHindi function call. Input: " << inputsA[i]
					<< ", expected output: " << outputsA[i]
					<< ", actual output: " << actualOutput << endl;
			}

			actualOutput = dict.HindiToEnglish(inputsB[i]);
			if (actualOutput != outputsB[i])
			{
				passed = false;
				cout << "x \t Dictionary Fail \t"
					<< "EnglishToHindi function call. Input: " << inputsB[i]
					<< ", expected output: " << outputsB[i]
					<< ", actual output: " << actualOutput << endl;
			}
		}

		if (passed)
		{
			cout << "o \t Dictionary class passed" << endl;
		}
	}
};

#endif