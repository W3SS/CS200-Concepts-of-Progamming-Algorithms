# CS 200 Lab 8: Strings and Vectors

## Chrome!

Please read this in chrome so that the solutions are collapsed by default!

## Topics

* Strings
* Vectors
* For-loops

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

# About Vectors

[Reference docs](http://www.cplusplus.com/reference/vector/vector/)

## What is a Vector?

A vector is a type of structure that stores a list of items. Perhaps you've used Lists in previous courses - they are like that.

You can store a list of multiple variables, though they all have to be the same data-type.

## Declaring Vectors

To declare a vector, you must use the **vector** type and a second type - the type of item it is storing:

	vector<string> myStringList;
	vector<int> myIntList;
	vector<float> myFloatList;

## Adding items to a Vector

To add items to the vector, we use the **push_back** function, and pass in the new item for the list:

	vector<string> students;
	students.push_back( "Ron" );		// Student #0
	students.push_back( "Harry" );		// Student #1
	students.push_back( "Hermione" );	// Student #2

## Accessing items in a Vector

If we want to access a specific student, we use their **index** number. The index is essentially the item's **position within the list**, but it starts at 0 instead of 1.

	// Displays "Ron"
	cout << students[0] << endl;

	// Displays "Harry"
	cout << students[1] << endl;

	// Displays "Hermione"
	cout << students[2] << endl;

## Iterating through a Vector

You can also use a **for-loop** to access every item of the Vector. The Vector has a special function called **size()** which will return how many items are in the list. 

Note that, for our **students** vector, there are **3 items**, which range from indices 0 through 2.

To display a list of all students, we can do the following:

	for ( unsigned int i = 0; i < students.size(); i++ )
	{
		cout << "Student " << i << ": " << students[i] << endl;
	}

Note the **unsigned int**... this is just an integer, but it means that the integer cannot be negative. This is because "size()" cannot be a negative value!

## User input to add to Vector

Let's say we want to get the user's input and add it to the vector. 

First, we need a temporary variable to store the user's input into.

Second, we use the **push_back** function to add that value to the list.

	string newName;
	cout << "Enter a student name: ";
	cin >> newName;
	students.push_back( newName );

Now our students Vector's size is 4.

---

# About Strings

[Reference docs](www.cplusplus.com/reference/string/string/)

Strings are also technically an array type! Strings hold **arrays of chars**. So, behind the scenes, the string "Ron" might look like...

	{ 'R', 'o', 'n', '\n' }

The "\n" here just marks the end of the string; computers use it to know where one string ends and another begins. **WE** don't have to worry about the technical implementation of a string, however!

Creating a string and assigning it is pretty easy...

	string name = "Zamenhof";

And displaying it is easy...

	cout << "Saluton, mi nomigxas " << name << endl;

## Letters of a string

And since strings are technically arrays of **chars**, we can also access one char at a time:

	cout 	<< name[0] << endl 
			<< name[1] << endl 
			<< name[2] << endl 
			<< name[3] << endl;

This will display...:

	Z
	a
	m
	e

Like vector, strings also have a **size()** function, so if you wanted to display all letters separately:

	for ( unsigned int i = 0; i < name.size(); i++ )
	{
		// Display each letter on a separate line
		cout << name[i] << endl;
	}

You can also display the size of your string:

	cout << "Your name is " << name.size() << " characters long" << endl;

## Concatenating strings

You can use the + operator to put strings together. In this context, + is called "concatenation". For example:

	string name1, name2, name3;
	cout << "Enter your name (3 names): ";
	cin >> name1 >> name2 >> name3;
	string fullname = name1 + " " + name2 + " " + name3;

You can keep combining string variables and **string literals** (any strings contained within double-quotes) as much as you want, with a + sign in-between.

---

# Assignments

For these assignments, the test functions are already implemented and being called from main(). You just need to implement the functions listed.

## GetNameLength

Use the size() function to get the length of each name, and return
the sum of all sizes together.

## Translate

Use the TranslateWord function (above) to translate the subject, verb, and object,
and build it into one sentence.

For example, if you pass in:
	TranslateWord( "the cat" );
the result will be
	"la kato"

The word order will be the same, HOWEVER, make sure you append "n" after the object's translation.

## FindItem

Search through the list of names.
If any of the names match the "findMe" parameter,
return the current index of that item.
Otherwise, return -1 if not found.


## GetInitials (bonus)

A vector of names is passed in, such as "Homer", "J", "Simpson".
The output for this should be "HJS" - the first letter of each name.
This will require dealing with the initials as a 2D array.

Hint:	names[0] is "Homer", and names[0][0] is "H".
		names[1] is "J", and names[1][0] is "J".
		names[2] is "Simpson", and names[2][0] is "S".

Use a for-loop to iterate through all the names in the vector, and append letter #0 to the initials.


