#ifndef TESTER_INHERITANCE_HPP
#define TESTER_INHERITANCE_HPP

#include "Inheritance.hpp"

#include <string>
#include <iostream>
using namespace std;

class InheritanceTester
{
public:
	static void Start()
	{
		Test();
	}

private:
	static void Test()
	{
		bool passed = true;
		cout << endl << "TEST: Cipher classes" << endl;

		CaesarCipher cc;

		int testCount = 4;
		string inputs1[] = { "ABC", "XYZ", "H", "HI THERE" };
		string outputs1[] = { "BCD", "YZA", "I", "IJ UIFSF" };

		for (int i = 0; i < testCount; i++)
		{
			string actualOutput = cc.Encrypt(inputs1[i]);
			if (actualOutput != outputs1[i])
			{
				passed = false;
				cout << endl
					<< "x FAILED TEST " << i << " (CaesarCiper Encrypt): " << endl
					<< "\t Input:           " << inputs1[i] << endl
					<< "\t Expected output: " << outputs1[i] << endl
					<< "\t Actual output:   " << actualOutput << endl;
			}
		}

		testCount = 4;
		string inputs2[] = { "BCD", "YZA", "I", "IJ UIFSF" };
		string outputs2[] = { "ABC", "XYZ", "H", "HI THERE" };

		for (int i = 0; i < testCount; i++)
		{
			string actualOutput = cc.Decrypt(inputs2[i]);
			if (actualOutput != outputs2[i])
			{
				passed = false;
				cout << endl
					<< "x FAILED TEST " << i << " (CaesarCiper Decrypt): " << endl
					<< "\t Input:           " << inputs2[i] << endl
					<< "\t Expected output: " << outputs2[i] << endl
					<< "\t Actual output:   " << actualOutput << endl;
			}
		}

		SubCipher sc;

		testCount = 4;
		string inputs3[] = { "ABC", "XYZ", "H", "HI THERE" };
		string outputs3[] = { "ZYX", "CBA", "S", "SR GSVIV" };

		for (int i = 0; i < testCount; i++)
		{
			string actualOutput = sc.Encrypt(inputs3[i]);
			if (actualOutput != outputs3[i])
			{
				passed = false;
				cout << endl
					<< "x FAILED TEST " << i << " (SubCipher Encrypt): " << endl
					<< "\t Input:           " << inputs3[i] << endl
					<< "\t Expected output: " << outputs3[i] << endl
					<< "\t Actual output:   " << actualOutput << endl;
			}
		}

		testCount = 4;
		string inputs4[] = { "ZYX", "CBA", "S", "SR GSVIV" };
		string outputs4[] = { "ABC", "XYZ", "H", "HI THERE" };

		for (int i = 0; i < testCount; i++)
		{
			string actualOutput = sc.Decrypt(inputs4[i]);
			if (actualOutput != outputs4[i])
			{
				passed = false;
				cout << endl
					<< "x FAILED TEST " << i << " (SubCipher Decrypt): " << endl
					<< "\t Input:           " << inputs4[i] << endl
					<< "\t Expected output: " << outputs4[i] << endl
					<< "\t Actual output:   " << actualOutput << endl;
			}
		}

		if (passed)
		{
			cout << "\t PASSED" << endl;
		}
	}
};

#endif