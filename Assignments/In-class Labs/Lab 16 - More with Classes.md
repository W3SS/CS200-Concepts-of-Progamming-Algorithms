# CS 200 Lab 16: More with Classes

## Topics

* Classes
* Constructors and Destructors
* Operator Overloading
* Static Members
* Const functions
* Multiple files
* Namespaces

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

All parts of this lab should be within one project - you will create
different files for each class.

# Starting Out

First, create a ```main.cpp``` file. This will be the file that contains
our main function...:

```c++
#include <iostream>
using namespace std;

int main()
{
    return 0;
}
```

As you add each class, you will have to ```#include``` your new file
into ```main.cpp```, to let it know that it can use your class.

Name your new files as specified in each *lab item*.


# Item 1: Constructors and Destructors

## Introduction

### Terminology - Objects, Instances, Instantiation

When you declare a class, you're essentially creating a new *data-type*.

```c++
class CoordPair
{
public:
	int x, y;
};
```

When you declare a variable whose data-type is a class, you're
**instantiating an object of that class-type**.

```c++
int main()
{
	CoordPair origin;	// An instance of the CoordPair class

	return 0;
}
```

### Constructors

When a new object is created, a **constructor function** is called.
If you don't define your own constructor, C++ will make one *implicitly*.
However, you can write your own constructor (or constructors) to add
some code that will be **automatically executed when a new object
is instantiated.**

In other words, the constructor is automatically run when we create a 
new object of that class' data-type.

The constructor MUST match the class' name:

```c++
class CoordPair()
{
public:
	CoordPair()
	{
		// The constructor is initializing
		// default values for x and y here.
		x = 0;
		y = 0;
	}

	int x, y;
}
```

### Constructor Overloading

You can also **overload** your constructors and have more than one.
To overload a constructor, each subsequent constructor must have a
unique parameter list...:

```c++
class CoordPair()
{
public:
	CoordPair()
	{
		// The constructor is initializing
		// default values for x and y here.
		x = 0;
		y = 0;
	}
	
	CoordPair( int newX, int newY )
	{
		// Initialize x and y with values
		// passed in when the object was created.
		x = newX;
		y = newY;
	}

	int x, y;
}
```

Now, if we were going to declare object variables that will call
both of these constructors, it would look like:

```c++
int main()
{
	CoordPair origin;			// Calls the constructor with no parameters
	
	CoordPair position( 2, 5 ); // Calls the constructor with two int parameters

	return 0;
}
```

If you only have one constructor, but that constructor has parameters,
then you **will not be able to declare an object without passing in parameters.**

```c++
class Cat
{
public:
	Cat( string name )
	{
		m_name = name;
	}
	
private:
	string m_name;
};
```

```c++
int main()
{
	Cat myCat( "Kabe" );		// OK
	
	Cat anonyCat;				// Will cause compile error
	
	return 0;
}
```

### Destructors


# Item 2: Static Members

# Item 3: Const Functions

# Item 4: Namespaces

# Item 5: Operator Overloading

