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

const string TEST_DATA[] = {
    "Aardvark", "Albatross", "Alligator",
    "Bandicoot", "Bird", "Bison",
    "Cheetah", "Chipmunk", "Cow",
    "Elephant", "Emu", "Echidna",
    "Falcon", "Fox", "Fish",
    "Gecko", "Goat", "Goose",
    "Heron", "Horse", "Hyena",
    "Iguana", "Insect", "Impala",
    "Jackal", "Jellyfish", "Jaguar"
};

void DynamicArrayProgram()
{
}

int main()
{
    DynamicArrayProgram();

    return 0;
}

```

As you add each class, you will have to ```#include``` your new file
into ```main.cpp```, to let it know that it can use your class.

Name your new files as specified in each *lab item*.

# Multiple files

Once your programs are growing and containing multiple classes, it is
standard to put these classes in their own source files.

In C++, there are two types of source files: 

* Header Files
	* Saved as ```.h``` or ```.hpp```
	* Stores class and function **declarations** (prototypes)
* Source Files
	* Saved as ```.cpp```
	* Stores function **definitions**

So, say that we're going to create a ```Square``` class.
The class declaration and its function declarations would go in a .hpp file:

```c++
// Square.hpp
#ifndef _SQUARE_HPP
#define _SQUARE_HPP

class Square
{
	public:
	void SetWidth( float value );
	void SetLength( float value );
	float GetWidth();
	float GetLength();
	float GetArea();
	
	private:
	float m_width, m_length;
};

#endif
```

And then our function definitions would go in the .cpp file:

```c++
// Square.cpp
#include "Square.hpp"

void Square::SetWidth( float value )
{
	m_width = value;
}

void Square::SetLength( float value )
{
	m_length = value;
}

float Square::GetWidth()
{
	return m_width;
}

float Square::GetLength()
{
	return m_length;
}

float Square::GetArea()
{
	return m_width * m_length;
}
```

**Scope resolution operator ::**

When a member function is *defined* outside of the class declaration,
it must be prefixed with the class name and the *scope resolution operator*, 
like ```Square::```.

**ifndef preprocessors**

In our header files, we need to tell the compiler to not allow the file
to be included multiple times. 

If we didn't, then the compiler would get
confused if we have multiple source files including the same header file.
The compiler would complain about *multiple definitions* of the same
classes and functions, because it is essentially "copy-and-paste"ing
the source from the headers into each source file that ```#include```s it.

So, we put the following in every header:

```c++
#ifndef _UNIQUE_NAME
#define _UNIQUE_NAME

#endif
```

This prevents this duplication error.

# Constructors and Destructors Introduction

## Terminology - Objects, Instances, Instantiation

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

## Constructors

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

## Constructor Overloading

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

## Destructors

**Destructors** are also functions that are automatically called
given some circumstances. Whereas constructors are called when an
object is created, a destructor is called when **the object is destroyed.**

This can be when the **delete** command is used on a dynamic variable,
or when a local variable loses scope (e.g., function ends).

**You cannot overload destructors** - you can only have one, and it has
no parameters. Usually, destructors are used to clean up data.

```c++
class FileWriter
{
	FileWriter( string filename )
	{
		// Open file when the writer is created
		m_file.open( filename );
	}
	
	~FileWriter()
	{
		// Close the file when the writer is destroyed
		m_file.close();
	}
	
	void Write( string text )
	{
		m_file << text << endl;
	}
	
private:
	ofstream m_file;
};
```

# Item 1: Constructor/Destructor project

Create two new files: ```DynamicArray.hpp``` and ```DynamicArray.cpp```.

Start off the DynamicArray.hpp file with:

```c++
#ifndef _DYNAMIC_ARRAY_HPP
#define _DYNAMIC_ARRAY_HPP

#endif
```

and the DynamicArray.cpp with:

```c++
#include "DynamicArray.hpp"
```

Note: You will also need to make sure to ```#include "DynamicArray.hpp"```
in main.cpp as well!

Here is the **UML (Unified Modeling Language) Diagram** of the DynamicArray class.
Use this to create the class declaration in your .hpp file:

![DynamicArray diagram](images/201701_lab16_DynamicArray.png)

The top portion of the diagram are member variables, and the bottom portion
are member functions.

Items prefixed with - are private, and items prefixed with + are public.





![screenshot](images/201701_lab16_a.png)


# Item 2: Static Members

# Item 3: Const Functions

# Item 4: Namespaces

# Item 5: Operator Overloading

