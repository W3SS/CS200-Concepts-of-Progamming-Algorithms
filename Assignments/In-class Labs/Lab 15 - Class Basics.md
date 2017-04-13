# CS 200 Lab 15: Class Basics

## Chrome!

Please read this in chrome so that the solutions are collapsed by default!

## Topics

* Classes
* File I/O

## Turn in

**You will need to upload your code both to the class D2L Dropbox, and to your CS 200 GitHub repository!**

Locate your source files for this project. They should have the extentions .cpp, .hpp, and/or .h. In Windows, they are labelled as "C++ source file" and/or "Header file". 


![Windows, you're annoying.](images/sourcefiles.png)

**These are the only files you need** - You do not need to upload any Visual Studio files.

Upload these source files to your GitHub repository and to the Dropbox.

See also: 
[TURNING IN SOURCE CODE instructions](https://github.com/Rachels-Courses/Course-Common-Files/blob/master/How-to/Turning%20in%20source%20code.md)

## Rules

* Finishing the lab after class:
   * If you are not able to complete the lab during the class period, please finish it up outside of class and turn it in as soon as you can. The lab dropbox will be open for 1 week after the class session.

* Group work:
   * You may work with other students on labs:
   * All people working together must turn in code in their own dropboxes, and upload the code to their own GitHub repositories.
   * All group work must be noted as such - either put a comment in the code file or in the dropbox upload.
   * If you turn in duplicate works without noting that you worked together, you may get a 0% grade.

---

# Starter Files

Make sure to download **lab15.cpp** to start with!

Or copy this code into your source file:

```c++
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Room
{
};

class Building
{
};



void RoomProgram()
{
    // This function works with the Room object

	/*
    Room room;
    room.SetDimensions( 5, 4 );

    cout << "Room area is: " << room.GetArea() << endl;

    room.SetTitle( "closet" );

    cout << "Room name is: " << room.GetTitle() << endl;
	*/
}

void BuildingProgram()
{
    // This function works with the Building object

	/*
    Building building( 5 );

    building.SetRoomTitle( 0, "Entryway" );
    building.SetRoomTitle( 1, "Living Room" );
    building.SetRoomTitle( 2, "Kitchen" );
    building.SetRoomTitle( 3, "Bedroom" );
    building.SetRoomTitle( 4, "Bathroom" );

    building.SetRoomDimensions( 0, 5, 10 );
    building.SetRoomDimensions( 1, 5, 10 );
    building.SetRoomDimensions( 2, 5, 10 );
    building.SetRoomDimensions( 3, 5, 10 );
    building.SetRoomDimensions( 4, 5, 10 );

    building.PrintBuildingInformation( "building.txt" );
    */
}

int main()
{
    RoomProgram();
    BuildingProgram();

    return 0;
}
```

---

# Program 

For this program, you will build two classes: **Room** and **Building**.

The Building will contain an array of Rooms, and let the user set up
those rooms. The building will also be able to output all the room information
to a text file.

All the code for **main()** is already written, but it won't build yet,
because Room and Building don't yet exist!

**Cout Note:** This project doesn't use couts... if your code contains
couts, you're probably implementing it wrong!

## Room class

The Room class will have the following **private member variables:**

* m_title, a string; the name of the room
* m_width, an integer
* m_length, an integer

And the Room class will have the following **public member functions:**

* int GetWidth()
* int GetLength()
* int GetArea()
* string GetTitle()
* void SetTitle( string newTitle )
* void SetDimensions( int newWidth, int newHeight );

Setter and Getter functions are useful ways to ensure that the data
coming into the class and going out of the class is valid and/or
formatted correctly.

Also, if you make the member variables of a class public, as your program
grows it will be difficult to make updates to your class, since *anything*
could be using these variables, making it hard to change out how your class works.

### int GetWidth()

This should only return the value of the *m_width* private member variable.

### int GetLength()

This should only return the value of the *m_length* private member variable.

### int GetArea()

This function should calculate the area of the room (width x length) and
return that value.

### string GetTitle()

This should only return the value of the *m_title* private member variable.

### void SetTitle( string newTitle )

This should set the private member variable *m_title*'s value to the
value of the parameter *newTitle*.

### void SetDimensions( int newWidth, int newLength )

This should check to make sure *newWidth* and *newLength* are positive
numbers. If either of them are 0 or negative, then don't update the
corresponding width or height value.

This function should set the private member variable *m_width*'s new
value to the *width* parameter, and *m_height* to *height*.

### Testing

Uncomment out the contents of the **RoomProgram** function and run
the program to see if the room is working.

```c++
void RoomProgram()
{
    // This function works with the Room object

    Room room;
    room.SetDimensions( 5, 4 );

    cout << "Room area is: " << room.GetArea() << endl;

    room.SetTitle( "closet" );

    cout << "Room name is: " << room.GetTitle() << endl;
}
```

## Building class

Below the **Room** class, you will create a **Building** class.

The Building class will have the following **private member variables:**

* m_rooms, a Room* pointer (dynamic array)
* m_roomCount, an integer

The Building class will have the following **public member functions:**

* Building constructor with integer parameter
* Building destructor
* void SetRoomTitle( int room, string title )
* void SetRoomDimensions( int room, int width, int length )
* int GetTotalArea()
* void PrintBuildingInformation( string filename )

### Building constructor

Your building constructor will look like this:

```c++    
Building( int roomCount )
{
}
```

The constructor is automatically called when a variable of the Building
data-type is instantiated. Likewise, the destructor is called automatically
when the variable is destroyed, such as when it loses scope.

This constructor has a parameter: *roomCount*. This means that,
when we create a new Building object, we can pass in a roomCount like this:

```c++
Building building( 5 );
```

We can overload constructors as well (write multiple constructors with
different parameter lists). If we only have one constructor, and it takes
a parameter, then it will be impossible to create a variable without
passing in this argument, like ```Building building;```

Within the constructor, do the following:

* Set the *m_rooms* pointer to *nullptr*.
* If the parameter *roomsCount* is positive...
	* Set the member variable *m_roomCount* equal to the parameter roomCount.
	* Initialize a dynamic array, using the *m_rooms* pointer, setting its size
	to the roomCount.


### Building destructor

Start out your destructor like this:

```c++
~Building()
{
}
```

You will need to do the following:

* Check if the *m_rooms* pointer is *nullptr*. If it is NOT nullptr...
	* Free up the memory allocated for the dynamic array using the **delete []** keyword.

### void SetRoomTitle( int room, string title )

First check to make sure that the *room* passed in is valid - this is
supposed to be an index to access an element of the *m_rooms* array.
If it is negative, or equal to or greater than the room count, then it is invalid.

If it is invalid, don't change anything.

Otherwise, use the **SetTitle** function of the Room class to set
*m_rooms[ room ]*'s title.


### void SetRoomDimensions( int room, int newWidth, int newLength )

First check to make sure that the *room* passed in is valid - this is
supposed to be an index to access an element of the *m_rooms* array.
If it is negative, or equal to or greater than the room count, then it is invalid.

If it is invalid, don't change anything.

Otherwise, use the **SetDimensions** function of the Room class to set
*m_rooms[ room ]*'s width and length.


### int GetTotalArea()

This function should sum all of the areas of the rooms that belong
to the building. Create a variable to store the sum of areas,
then iterate through all the elements of *m_rooms* and use the
*GetArea()* function to add on to your sum. Return the sum once finished.

### void PrintBuildingInformation( string filename )

Copy the following for this function:

```c++
void PrintBuildingInformation( string filename )
{
	ofstream output( filename );

	output << "BUILDING Dimensions: " << GetTotalArea() << " sqft" << endl << endl;

	for ( int i = 0; i < m_roomCount; i++ )
	{
		output << endl << "ROOM " << (i+1) << " ("
			<< m_rooms[i].GetTitle() << "):"
			<< "\n\t * Dimensions: " << m_rooms[i].GetWidth() << " x " << m_rooms[i].GetLength()
			<< "\n\t * Area:       " << m_rooms[i].GetArea() << " sqft" << endl;
	}

	output.close();
}
```

### Testing

Test the building by uncommenting out the BuildingProgram function:

```c++
void BuildingProgram()
{
    // This function works with the Building object

    Building building( 5 );

    building.SetRoomTitle( 0, "Entryway" );
    building.SetRoomTitle( 1, "Living Room" );
    building.SetRoomTitle( 2, "Kitchen" );
    building.SetRoomTitle( 3, "Bedroom" );
    building.SetRoomTitle( 4, "Bathroom" );

    building.SetRoomDimensions( 0, 5, 10 );
    building.SetRoomDimensions( 1, 5, 10 );
    building.SetRoomDimensions( 2, 5, 10 );
    building.SetRoomDimensions( 3, 5, 10 );
    building.SetRoomDimensions( 4, 5, 10 );

    building.PrintBuildingInformation( "building.txt" );
}
```

Run the program, and locate the output text file. It should have
information like this:

BUILDING Dimensions: 250 sqft


		ROOM 1 (Entryway):
			 * Dimensions: 5 x 10
			 * Area:       50 sqft

		ROOM 2 (Living Room):
			 * Dimensions: 5 x 10
			 * Area:       50 sqft

		ROOM 3 (Kitchen):
			 * Dimensions: 5 x 10
			 * Area:       50 sqft

		ROOM 4 (Bedroom):
			 * Dimensions: 5 x 10
			 * Area:       50 sqft

		ROOM 5 (Bathroom):
			 * Dimensions: 5 x 10
			 * Area:       50 sqft






