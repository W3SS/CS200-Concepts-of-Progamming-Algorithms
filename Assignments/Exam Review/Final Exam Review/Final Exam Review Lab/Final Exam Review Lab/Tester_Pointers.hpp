#ifndef TESTER_POINTERS_HPP
#define TESTER_POINTERS_HPP

#include "Pointers.hpp"

#include <string>
#include <iostream>
using namespace std;

class PointerTester
{
public:
	static void Start()
	{
		GetAddressTest();
		GetValueTest();
		CheckIfNullTest();
		CompareAddressesTest();
		CompareValuesTest();
	}

private:
	static void GetAddressTest()
	{
		bool passed = true;
		cout << endl << "TEST: GetAddress" << endl;

		int* ptrNumPointer = nullptr;
		int variable = 20;

		ptrNumPointer = GetAddress(variable);

		if (ptrNumPointer != &variable)
		{
			passed = false;
			cout << endl
				<< "x FAILED TEST: " << endl
				<< "\t Expected the pointer to be given the address " << &variable << endl
				<< "\t pointer is pointing to " << ptrNumPointer << endl;
		}

		if (passed)
		{
			cout << "\t PASSED" << endl;
		}
	}

	static void GetValueTest()
	{
		bool passed = true;
		cout << endl << "TEST: GetValue" << endl;

		int variable = 20;
		int* ptrNumPointer = &variable;

		int value = GetValue(ptrNumPointer);

		if (value != variable)
		{
			passed = false;
			cout << endl
				<< "x FAILED TEST: " << endl
				<< "\t Expected to get value " << variable << endl
				<< "\t But instead " << value << " was returned." << endl;
		}

		if (passed)
		{
			cout << "\t PASSED" << endl;
		}
	}

	static void CheckIfNullTest()
	{
		bool passed = true;
		cout << endl << "TEST: CheckIfNull" << endl;

		int variable = 20;
		int* ptr1 = nullptr;
		int* ptr2 = &variable;

		bool result1 = CheckIfNull(ptr1);
		if (result1 != true)
		{
			passed = false;
			cout << endl
				<< "x FAILED TEST: " << endl
				<< "\t Expected to get value true" << endl
				<< "\t But instead false was returned." << endl;
		}

		bool result2 = CheckIfNull(ptr2);
		if (result2 != false)
		{
			passed = false;
			cout << endl
				<< "x FAILED TEST: " << endl
				<< "\t Expected to get value false" << endl
				<< "\t But instead true was returned." << endl;
		}

		if (passed)
		{
			cout << "\t PASSED" << endl;
		}
	}

	static void CompareAddressesTest()
	{
		bool passed = true;
		cout << endl << "TEST: CompareAddresses" << endl;

		int val1 = 10;
		int val2 = 100;
		int val3 = 10;

		int* p1 = &val1;
		int* p2 = &val1;
		int* p3 = &val2;
		int* p4 = &val3;

		bool same = CompareAddresses(p1, p2);
		if (same != true)
		{
			passed = false;
			cout << endl
				<< "x FAILED TEST: " << endl
				<< "\t p1 points at " << p1 << endl
				<< "\t p2 points at " << p2 << endl
				<< "\t But false was returned." << endl;
		}
		
		same = CompareAddresses(p1, p3);
		if (same != false)
		{
			passed = false;
			cout << endl
				<< "x FAILED TEST: " << endl
				<< "\t p1 points at " << p1 << endl
				<< "\t p3 points at " << p3 << endl
				<< "\t But true was returned." << endl;
		}

		same = CompareAddresses(p1, p4);
		if (same != false)
		{
			passed = false;
			cout << endl
				<< "x FAILED TEST: " << endl
				<< "\t p1 points at " << *p1 << endl
				<< "\t p4 points at " << *p4 << endl
				<< "\t But true was returned." << endl;
		}

		if (passed)
		{
			cout << "\t PASSED" << endl;
		}
	}

	static void CompareValuesTest()
	{
		bool passed = true;
		cout << endl << "TEST: CompareValues" << endl;

		int val1 = 10;
		int val2 = 100;
		int val3 = 10;

		int* p1 = &val1;
		int* p2 = &val1;
		int* p3 = &val2;
		int* p4 = &val3;

		bool same = CompareValues(p1, p2);
		if (same != true)
		{
			passed = false;
			cout << endl
				<< "x FAILED TEST: " << endl
				<< "\t p1 value is " << *p1 << endl
				<< "\t p2 value is " << *p2 << endl
				<< "\t But false was returned." << endl;
		}

		same = CompareValues(p1, p3);
		if (same != false)
		{
			passed = false;
			cout << endl
				<< "x FAILED TEST: " << endl
				<< "\t p1 value is " << *p1 << endl
				<< "\t p3 value is " << *p3 << endl
				<< "\t But true was returned." << endl;
		}

		same = CompareValues(p1, p4);
		if (same != true)
		{
			passed = false;
			cout << endl
				<< "x FAILED TEST: " << endl
				<< "\t p1 value is " << *p1 << endl
				<< "\t p4 value is " << *p4 << endl
				<< "\t But false was returned." << endl;
		}

		if (passed)
		{
			cout << "\t PASSED" << endl;
		}
	}

	static void CompareAddressesTestd()
	{
		bool passed = true;
		cout << endl << "TEST: CompareAddresses" << endl;


		if (passed)
		{
			cout << "\t PASSED" << endl;
		}
	}
};

#endif