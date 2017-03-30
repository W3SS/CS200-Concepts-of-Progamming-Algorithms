# Homework Exercise 5: Pointers and Dynamic Arrays

## Topics

* Pointers
* Memory management
* Dynamic arrays

## Rules

* Team size: **1 person**
    * You can brainstorm with others - that is, you can verbally discuss the problem.
    * You cannot copy another person's work. 
    Code will be checked against other submissions with a diff tool.
    If a copy is found, both people will receive a 0 on the assignment.
* Open book / open note - do research as-needed.

## Turn in

**You will need to upload your code both to the class D2L Dropbox, and to your CS 200 GitHub repository!**

Locate your source files for this project. They should have the extentions .cpp, .hpp, and/or .h. In Windows, they are labelled as "C++ source file" and/or "Header file". 

![Windows, you're annoying.](https://github.com/Rachels-Courses/Course-Common-Files/raw/master/How-to/images/sourcefiles.png)

**These are the only files you need** - You do not need to upload any Visual Studio files.

Upload these source files to your GitHub repository and to the Dropbox.

## Reference Information

* [How to turn in your source code](https://github.com/Rachels-Courses/Course-Common-Files/blob/master/How-to/Turning%20in%20source%20code.md)
* [Visual Studio - How to create a new project](https://github.com/Rachels-Courses/Course-Common-Files/blob/master/How-to/New%20project%20-%20Visual%20Studio.md)
* [Common programming errors](https://github.com/Rachels-Courses/Course-Common-Files/blob/master/Review/Common-errors.md)


---

## Template program

You can use this code as your starting point:

	#include <iostream>
	#include <string>
	using namespace std;

	// A person struct - by making a struct, we can then
	// declare a variable whose data-type is Person.
	// The Person data-type contains two internal variables:
	// name, a string	&	home, a string pointer
	struct Person
	{
		string name;
		string* home;
	};

	void SetupLocations( string* locationList );
	void SetupPeople( Person* personList, int personCount, string* locationList, int locationCount );

	int main()
	{
		string* locationList;							// Create a string* pointer
		locationList = new string[5];					// Use the pointer to create a dynamic array
		SetupLocations( locationList );					// Call function to set up data
		
		
		Person* personList;								// Create a Person* pointer
		personList = new Person[4];						// Use the pointer to create a dynamic array
		SetupPeople( personList, 4, locationList, 5 );	// Call function to set up data
		
		
		// Display all people info
		for ( int p = 0; p < 4; p++ )
		{
			// Display each person's name and their home location's name.
			// Note that Person.home is a POINTER. You have to dereference
			// the pointer to get its value, otherwise it will just
			// give you a memory address.
			
			cout << personList[p].name << "\t" << *personList[p].home << endl;
		}
		
		
		// Make sure to free up the memory afterward!
		delete [] locationList;
		delete [] personList;
		
		return 0;
	}

	void SetupLocations( string* locationList )
	{
		locationList[0] = "Raytown";
		locationList[1] = "Grandview";
		locationList[2] = "Independence";
		locationList[3] = "Liberty";
		locationList[4] = "Belton";
	}

	void SetupPeople( Person* personList, int personCount, string* locationList, int locationCount )
	{
		for ( int p = 0; p < personCount; p++ )
		{
			cout << "Person " << p << "'s name: ";
			
			cin >> personList[p].name;
			
			cout << endl << "Locations:" << endl;
			for ( int c = 0; c < locationCount; c++ )
			{
				cout << c << ". " << locationList[c] << endl;
			}
			cout << personList[p].name << "'s home: ";
			
			int index;
			cin >> index;
			
			personList[p].home = &locationList[index];
		}
	}




---

# Assignment

You will be using the code above and making modifications according
to the instructions.

## Location struct

Change around the program so that *location* isn't just a string anymore.
Create a struct called **Location**, and within the struct store:

* city (string)
* state (string)
* zip (int)

Use the Person struct for reference!

After you create the struct, you will have to update several locations:

### SetupLocations function

Update the parameter list in the prototype on line 15, as well
as the actual function definition that is below main().
Set up each locations' city, state, and zip.

```c++
void SetupLocations( Location locArr[] )
{
	// Set each location's city, state, and zip.
	// Locations 0 through 5
}
```

Note: To access a *member variable* of a struct, you will use the
dot operator: . Pay attention to how we access items from the personList:

	cout << personList[p].name // ...

### SetupPeople function

You will also have to update the parameter list in this function and
its prototype.

Within this function, make sure that the locationList only displays
the *city* and *state*; you don't need to display the zip code here.

After the person enters the *INDEX* of the location they want,
you're going to update the person's **home** pointer to the location.

```c++
personList[p].home = (Put the address of the element of the locationList array)
```

### main() function

Here, once we are displaying all the people info, update the *cout*
statement so that it displays the location's city, state, and zip code.

However, you will need to note that your location variable is a pointer,
and you cannot just display like this anymore:

	*personList[p].home

once that variable is an *object* (i.e., a variable whose data-type is
a struct or a class), then you need to access it via its member
variables and/or functions. (Our struct doesn't have functions here.)

To access the location's *city* via the home pointer, it will look something
like this:

	cout << personList[p].home->city;



## Questions & answers

Write out your answers to these questions in a text document,
word document, or libreoffice document, and turn into the dropbox
along with your code.

1. What does the & operator do?
1. What does the * operator do?
1. What does the **new** and **delete** keywords do?
1. Why do you think it could be an advantage to store the city
as a string pointer (as it is originally in the program), instead
of just storing a string variable and each Person having their
own independent strings for the city?
1. Did you have any trouble completing this exercise? What did you get stuck on?



