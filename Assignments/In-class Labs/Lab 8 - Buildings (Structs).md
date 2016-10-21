# CS 200 Lab 8: Buildings (Structs)

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

# Step 1: Creating rooms

## Variables

First, we will create the Room object. Each Room will have its own attributes, such as:

* Width of the room
* Length of the room
* Name for the room (e.g., "Bedroom", "Bathroom")

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

Test your program by creating several Rooms in main()...

  Room roomA, roomB, roomC;
  
Assign some values to their variables, the make sure their GetPerimeter and GetArea functions are working:

  roomA.length = 5;
  roomA.width = 4;
  
  cout << "Area: " << roomA.GetArea() << ", Perimeter: " << roomA.GetPerimeter() << endl;

After you've tested this out, 


