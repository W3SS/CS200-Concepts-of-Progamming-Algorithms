# CS 200 Lab 9: Buildings (Structs)

Please read this document in Chrome. :)

## Topics

* Structs
* Arrays
* Functions

## Introduction

For this program, we are going to create a Building object and Room objects. Each building has an *array* of Rooms, though no specific amount is required.

After a building is set up, we can calculate the square footage and display information about the building to the user.

## Turn-in

Make sure to upload all source files (.cpp) to the Dropbox.

When you're uploading your source to the Dropbox, make sure to also leave a comment with the URL of your repository!

Add the name of all people in your team in the upload comments.

Turn in as one source file.

---

# Review: cin >> vs. getline

If your program is skipping over some lines of input, this is because of the
switching between **cin >> thing** and **getline( cin, thing )**.

Make sure after each **cin >>** command, you add:

	cin.ignore();
	
so that your getline statements don't skip.

---

# Step 1: Creating rooms

## Variables

First, we will create the **Room** object. Each Room will have its own attributes, such as:

* Width of the room		(float)
* Length of the room	(float)
* Name for the room		(string) -- example, "Bedroom", "Bathroom"

Create a struct and name it **Room**.  Its member variables are **width**, a float, **length**, a float, and **name**, a string.

## Functions

We will also have a function in this struct, which will calculate the room area and perimeter for us.

### GetArea

* Return type: float
* Parameters: none

For this function, it will calculate the room area using the **width** and **length** variables and return this value.

### GetPerimeter

* Return type: float
* Parameters: none

Calculate the perimeter of the room, which is the sum of all the walls of the room (2*length + 2*width). Return this value.

## Test and backup

Test your program by creating several Rooms in **main()**...

  Room roomA, roomB, roomC;
  
Assign some values to their variables, the make sure their GetPerimeter and GetArea functions are working:

  roomA.length = 5;
  roomA.width = 4;
  
  cout << "Area: " << roomA.GetArea() << ", Perimeter: " << roomA.GetPerimeter() << endl;

After you've tested this out to make sure it works, you will erase this code.

---

# Step 2: Creating a building

A building will be one object that contains an array of rooms within it.

Create a **Building** struct with the following member variables:

* address (string)
* rooms (Array of Rooms, size 10)
* totalRooms (integer)

## Functions

### Constructor

We will also need a function to set up the buliding with default values. There is a special function
that is called immediately once a *variable is declared of that class type*, and it is called a
**constructor method**. The special constructor method is a function whose name is the same as the class/struct itself:

	struct Building
	{
		string address;
		Room rooms[10];
		int totalRooms;
		
		Building()
		{
			// Constructor method
		}
	};
	
Notice that the constructor method has **no return type** - this is specific to constructors and destructors. All other methods
need a return type.

Within the constructor, we can initialize our values:

	Building()
	{
		address = "not set";
		totalRooms = 0;
	}
	
By initializing **totalRooms** to 0, we are specifying that a building starts out empty. The *array* still exists,
but we haven't created any rooms, so we are essentially ignoring it.

### AddRoom

Next, let's create a function that handles adding a room to the building.

This function will have the following **input**:

* What is the width of the new room?
* What is the height of the new room?
* What is the name of the new room?

This function will set up a new room in the array, and then add one to **totalRooms**, so we know
that a room has been added.

Start by creating a function **within the Building struct** that meets these specs:

* Return type: void
* Parameters:
	* newName, a string
	* newWidth, a float
	* newHeight, a float
	
Within the method, we will be working with a new room. There are a few ways we can do this.

1. Create a new Room variable named **newRoom**.
2. Assign **newRoom.width** the value of newWidth.
3. Assign **newRoom.height** the value of newHeight.
4. Assign **newRoom.name** the value of newName.

Note that this variable is only a **temporary variable** -- it will be destroyed
once the function ends. We've created this temporary variable to store information
into, but now we need to add it to the array of **rooms** that belongs to the Building struct.

You will copy over the contents of newRoom to the rooms array like this:

	rooms[ roomCount ] = newRoom;
	roomCount++;
	
Remember that roomCount begins at 0, so the first room we're adding will be added to *rooms[0]*.
After that, we add 1 to roomCount, and the next room will be at *rooms[1]*, then *rooms[2]*, and so on.

## Testing

Within main(), test out your code:

	int main()
	{
		Building bldg; // New variable "bldg", whose data-type is Building.
		
		bldg.address = "12345 College Blvd"; // Setting the Building member variable "address"
		bldg.AddRoom( "C++ Classroom", 20, 30 ); // Function call
		
		cout << "My building:" << endl;
		cout << bldg.address << endl;
		cout << "Room information:" << endl;
		cout << "Name: 		" << bldg.rooms[0].name << endl;
		cout << "Area: 		" << bldg.rooms[0].GetArea() << endl;
		cout << "Perimeter: " << bldg.rooms[0].GetPerimeter() << endl;
	
		return 0;
	}

Build and run the program to make sure it works. Is all the information displaying correctly?

	My building:
	12345 College Blvd
	Room information:
	Name:		C++ Classroom
	Area:		600
	Perimeter:	100

In the testing code, we're accessing *member variables* of the bldg object through the
**dot operator**. We can also access members within members, chaining together dots.

* What are all the member variables of a **Building** object being directly accessed in the sample code? (Two answers!)
* What are all the member variables of a **Room** object being directly accessed in the sample code?
* What are the memebr functions being called? Which Struct do these functions belong to? (Two functions, one Struct!)

Once you're done with this test code, you will erase it.

---

# Step 3: Creating a program loop

Now, let's add a user interface so the user can add and remove rooms.
Start with a basic program loop:

	int main()
	{
		Building bldg;
	
		bool done = false;
		
		while ( !done )
		{
			cout << "1. Set building address" << endl;
			cout << "2. Add room" << endl;
			cout << "3. View all building information" << endl;
			cout << "4. Quit" << endl;
			
			int choice;
			cin >> choice;
			
			if ( choice == 1 )
			{
			}
			else if ( choice == 2 )
			{
			}
			else if ( choice == 3 )
			{
			}
			else if ( choice == 4 )
			{
				done = true;
			}
		}
		
		return 0;
	}

## Setting the building's name

For choice #1, ask the user what the address of the building is.
You will have to get the user's input, and store it in the **address** member variable of the Building object (the bldg variable).

Use **getline** to get the address, and then store it in **bldg.address**.

## Adding a room

For choice #2, you will be adding a new room to the building. You will need to ask the user for the name of the room, the width, and the length of the room.

Use **cin >>** for the width and the length, and **getline** for the room name.

Once the user has entered their information (into temporary variables!), you will call the
**AddRoom** function and pass in the data. Make sure you pass all the input in, in the correct order.

## Displaying the building's information

For choice #3, you are going to display the following:

* The building's address
* The amount of rooms the building has
* The width, length, and name of every room of the building.
* The area and perimeter of every room of the building.

The building's address is easy: **bldg.address**.

The amount of rooms that the building has is also stored in a simple variable: **bldg.roomCount**.

To display all the information about the rooms of the building, you will need a for-loop.

	for ( int i = 0; i < bldg.roomCount; i++ )
	{
	}
	
Within the for-loop, use the *i* variable to access one element of the **rooms** array at a time.

Display the room's name with **bldg.rooms[i].name**.

Also display the width and length of the room.

After those variables, display the area and perimeter by calling the GetArea and GetPerimeter functions...
**bldg.rooms[i].GetArea()**.

## Test

Test out the program by starting it, setting the building address, adding several rooms,
and then displaying all the rooms to make sure it works.

## Turn-in

Once it's working properly, turn in your program.












