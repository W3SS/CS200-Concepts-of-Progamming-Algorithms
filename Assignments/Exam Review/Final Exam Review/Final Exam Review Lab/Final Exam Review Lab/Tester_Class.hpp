#ifndef TESTER_CLASS_HPP
#define TESTER_CLASS_HPP

#include "Class.hpp"

#include <string>
#include <iostream>
using namespace std;

class ClassTester
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
		cout << endl << "TEST: Course class" << endl;

		Course course;

		// Test A
		course.SetName("CS200");
		if (course.GetName() != "CS200")
		{
			passed = false;
			cout << endl
				<< "x FAILED TEST: " << endl
				<< "\t Set class name to \"CS200\" but GetName returns " 
				<< course.GetName() << endl;
		}

		// Test B
		if (course.GetStudentCount() != 0)
		{
			passed = false;
			cout << endl
				<< "x FAILED TEST: " << endl
				<< "\t Incorrect StudentCount. Expected 0 but got " 
				<< course.GetStudentCount() << endl;
		}

		// Test C
		course.AddStudent("Harry");
		if (course.GetStudentCount() != 1)
		{
			passed = false;
			cout << endl
				<< "x FAILED TEST: " << endl
				<< "\t Incorrect StudentCount. Expected 1 but got "
				<< course.GetStudentCount() << endl;
		}
		if (course.GetStudent(0) != "Harry")
		{
			passed = false;
			cout << endl
				<< "x FAILED TEST: " << endl
				<< "\t Added student \"Harry\". Student at position 0 is "
				<< course.GetStudent(0) << endl;
		}

		course.AddStudent("Ron");
		course.AddStudent("Hermione");
		if (course.GetStudentCount() != 3)
		{
			passed = false;
			cout << endl
				<< "x FAILED TEST: " << endl
				<< "\t Incorrect StudentCount. Expected 3 but got "
				<< course.GetStudentCount() << endl;
		}
		if (course.GetStudent(0) != "Harry" || 
			course.GetStudent(1) != "Ron" ||
			course.GetStudent(2) != "Hermione")
		{
			passed = false;
			cout << endl
				<< "x FAILED TEST: " << endl
				<< "\t Expected 0 = Harry, 1 = Ron, 2 = Hermione." << endl
				<< "\t Actual 0 = " << course.GetStudent(0) 
				<< ", 1 = " << course.GetStudent(1)
				<< ", 2 = " << course.GetStudent(2)
				<< endl;
		}

		course.AddStudent("Pusheen");
		course.AddStudent("Meow");
		if (course.GetStudentCount() != 5)
		{
			passed = false;
			cout << endl
				<< "x FAILED TEST: " << endl
				<< "\t Incorrect StudentCount. Expected 5 but got "
				<< course.GetStudentCount() << endl;
		}

		course.AddStudent("Crash?");
		if (course.GetStudentCount() != 5)
		{
			passed = false;
			cout << endl
				<< "x FAILED TEST: " << endl
				<< "\t Tried to add extra student. Should have been rejected. Expected course size of 5, but it is "
				<< course.GetStudentCount() << endl;
		}

		if (passed)
		{
			cout << "\t PASSED" << endl;
		}
	}
};

#endif