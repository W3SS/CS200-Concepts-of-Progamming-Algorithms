# CS 200 Lab 06b: Classes - Helper

---

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

---

# Constructors and Destructors introduction

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

# Constructors

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

---

# Constructor Overloading

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

---

# Destructors

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

---

# Static member introductions

We can use the keyword **static** with a member variable of a class
in order to create a variable that is shared by all *instantiations*
of that class.

So, let's say we have a class like *Student*, and we can make
many Students. Each Student will have names, grades, classes, etc.

But, we can also embed a *static* variable in the Student class,
which will be shared by *all students* - if the value changes
through StudentA, then that value is also the same for StudentB,
StudentC, and so on. With our normal variables, if we change
StudentA's name, it only updates StudentA and none of the others.

We can declare a static member like this:

```c++
class Counter
{
	public:
	static int sharedCounter;
	int individualCounter;
};
```

Within the corresponding .cpp file, we would have to also add
a *definition* for our static member, outside of any functions...

```c++
int Counter::sharedCounter = 0;
```

Elseware in the program, we can create some counters. We can
update the *sharedCounter* through an *instance* (a variable whose
data-type is *Counter*), or directly via the Counter class...

```c++
int main()
{
	Counter count_a;
	Counter count_b;
	
	count_a.sharedCounter++;	// sharedCounter is now 1
	count_b.sharedCounter++;	// sharedCounter is now 2
	Counter::sharedCounter++;	// sharedCounter is now 3
}
```

We can also write static member functions as well as static member variables,
and sometimes writing a class with static members can be useful if
we have one class that is going to only need *one instantiation*.

For example: An image manager in a program might be responsible for
loading and freeing images as they're loaded in to display. We wouldn't need
multiple versions of an image manager, because the one manager would
handle all that is relevant.

---

# Friend introduction

When we declare member variables and functions as **private** within a class,
only that class itself can access those members.

If we want something accessible to anything, we use **public**.

However, there are some design cases where you may want to give a certain
function or other class special access to the private member variables of
another class.

This is where **friends** come in handy. By declaring a class or function
as a *friend* within a class' definition, the other class will be able to access
private member variables...

```c++
class Book
{
public:
	friend class Librarian; // The librarian has special access to private members.

private:
	string m_title;
};

class Librarian
{
	// ... stuff goes here ...
};
```

---

# Operator Overloading introduction

An interesting feature of C++ is that we can **overload** operators such as

```+```, ```-```, ```*```, ```/```, ```=```, ```==```, ```!=```

and more!

For example, we can concatenate ```string``` objects with the + sign:

```c++
string last = "Morris";
string first = "Rachel";
string format = last + ", " + first;
```

In any of our classes we're writing, we can also overload these operators.
Some operators are stored **within the class**, and some operators are
**external to the class**.

When we're overloading these operators, it is **up to us** to decide
what the + operator (or any other) means for our object. Do we have
any private member variables to combine?

Use the following code snippets for reference on how to overload each...

## Operator Overloading reference

### Arithmetic operators

In the class declaration:

```c++
class MyClass
{
public:
	friend MyClass operator+( const MyClass& item1, const MyClass& item2 );
	friend MyClass operator­( const MyClass& item1, const MyClass& item2 );
	friend MyClass operator*( const MyClass& item1, const MyClass& item2 );
	friend MyClass operator/( const MyClass& item1, const MyClass& item2 );
};
```

Implementation:

```c++
MyClass operator+( const MyClass& item1, const MyClass& item2 )
{
	// ...
}
```

### Comparison operators

Class declaration:

```c++
class MyClass
{
public:
	friend bool operator==( MyClass& item1, MyClass& item2 );
	friend bool operator!=( MyClass& item1, MyClass& item2 );
	friend bool operator<( MyClass& item1, MyClass& item2 );
	friend bool operator>( MyClass& item1, MyClass& item2 );
	friend bool operator<=( MyClass& item1, MyClass& item2 );
	friend bool operator>=( MyClass& item1, MyClass& item2 );
};
```

Implementation:

```c++
bool operator==( MyClass& item1, MyClass& item2 )
{
	// ...
}
```

### Stream operators

Class declaration:

```c++
#include <fstream>
class MyClass
{
public:
	friend ostream& operator<<( ostream& out, MyClass& item );
	friend istream& operator>>( istream& in, MyClass& item );
};
```

Implementation:

```c++
ostream& operator<<( ostream& out, MyClass& item )
{
	out << item.textField << endl;
	return out;
}

istream& operator>>( istream& in, MyClass& item )
{
	in >> item.loadedField;
}
```

### Subscript operator

Class declaration:

```c++
class MyClass
{
public:
	int& operator[]( const int index );
	private:
	int m_data[];
};
```

Implementation:

```c++
int&  MyClass ::operator[]( const int index )
{
	return m_data[ index ];
}
```

### Assignment operator


Class declaration:

```c++
class MyClass
{
public:
	MyClass& operator=( const MyClass& rhs ); // "rhs" stands for "right-hand side", i.e., a = b, b is on rhs.
	private:
	int variable1;
	float variable2;
};
```

Implementation:

```c++
MyClass&  MyClass ::operator=( const MyClass& rhs )
{
	if ( this == &rhs )	// REQUIRED: Must check for self-assignment!
		return *this;
		
	variable1 = rhs.variable1;
	variable2 = rhs.variable2;
	return *this; 
}
```


---
