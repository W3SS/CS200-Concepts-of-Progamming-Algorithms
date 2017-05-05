# C++ Basics

---

# Control Flow

---

# Functions

## Terminology

### Function declaration

Ends with a semi-colon – no function body.

```c++
int Sum( int a, int b );
```

### Function definition

Defines the functionality – includes function body

```c++
int Sum( int a, int b )
{
    return a + b;
}
```

### Function body

The part of a function within the curly braces

### Function header (aka signature)

The part of a function above the curly braces – the
return type, name, and parameter list

### Function name

The name of the function. Should be descriptive.

```int Sum( int a, int b );``` (the "Sum" part)

### Return type

The data-type to be returned from the function.

```int Sum( int a, int b );``` (the "int" part)

### Parameter list

The list of variables that must be passed into the
function from the caller.

```int Sum( int a, int b );``` ( "int a, int b". )

### Function call

Where the function is being called from, and will
return to.

```int total = Sum( 1, 3 );``` ("1, 3".)

## Declaration (aka prototype) vs. definition

The declaration is the function header with a semi-colon at the end. Can be declared above main, so
that it can be defined below main.

The definition contains the actual inner code (the function body).

## Parameters vs. arguments

The parameters are the variables that the function expects to be passed in. These are in the function
header, in the parameter list.

The arguments are the variables that are passed into a function call. These are outside of the function
definition, and are whatever variables or values are passed in on call.

```c++
// parameters: a, b
int Sum( int a, int b );
```

```c++
// arguments: 1, 3
int total = Sum( 1, 3 );
```

## Return types

A function can return any data-type, but also void. The void return-type is used when the function does
not return any values.

## Pass by value vs. pass by reference

All variables, besides arrays, are passed by value by default. This means that the argument variable is
copied, and the function works with a copy. If any changes are made to the copy, it does not affect the
original argument variable after the function ends.

A variable can be passed by reference by adding on the & operator after the data-type. If a variable is
passed by reference, its value can change within the function. You can use this technique to return
multiple values, as you can only return one item via the return statement.

---

# Const

---

# Arrays

## Declaring a static array

To declare an array, you must specify the data-type of its elements, the array name, and its size.

```c++
string names[10]; // an array of strings
```

## Accessing elements of the array

For an array of size *5*, its valid indices are *0, 1, 2, 3, and 4*.
This is 5 total items, where index *5* would actually be the 6th item.
If you try to access an item outside the bounds of an array, your program will crash.

```c++
string months[3];
months[0] = "January";      // 1st item at index 0
months[1] = "February";     // 2nd item at index 1
months[2] = "March";        // 3rd item at index 2
```

## Initializer list

You can initialize an array with an initializer list.

```c++
string names[] = { "Yakko", "Wakko", "Dot" };
```

## Must know size at compile-time

For these types of arrays, the size of the array must be known at compile time. Therefore, you either
need to declare an array with a size (like in 24), or immediately initialize it with an initializer list (like
in 25).

## Track max size and current size

An array won't automatically track its maximum size or the current amount of objects it contains. You
will need to keep track of these yourself, usually with variables.

```c++
string students[30];
int maxStudents = 30;
int currentStudents = 0;
students[ currentStudents ] = "Bob";
currentStudents++;
```

## Passed by reference by default

Arrays, by default, are passed-by-reference in C++, because arrays may be large, and very costly to
copy over. You can make sure values do not change in the array by passing it as a const.

```c++
void DisplayList( const string names[], int size );
```

## COMMON ERROR: Going outside the bounds of an array

If you have an array of size 5...

        int myNumbers[5];
        
then the valid indices are 0, 1, 2, 3, and 4. **5 is not a valid index in C++ / Java**.

Your array has 5 items, so you still have 5 items between 0 and 4, and the item at index 5 would actually be the *6th* item.

In general terms, *if your array is of size n, then the valid indices for the array are [0] through [n-1].*

It is common to go outside the bounds of an array, especially when trying to iterate over everything in a for loop:

        for ( int i = 0; i <= arrSize; i++ )
        {
                // This is going to crash when i = arrSize!
                cout << arr[ i ] << endl;
        }
        
Make sure you're never accessing that *nth* element!

---

# Pointers, dynamic variables, and memory management

---

# Structs and Classes

## How to declare a struct and class, its member variables and functions

```c++
struct CoordPair
{
    float x, y;
};
class Student
{
    public:
    void Setup( const string& name, float gpa );
    
    private:
    string m_name;
    float m_gpa;
};
```

## Public, protected, and private accessibility

* Public members are accessible outside of the class. If a member variable or function is public, it
can be accessed directly through the instantiated object.
* Private members are only accessible to the class it belongs to. Private members are not available
to any children of the class.
* Protected is utilized for a class that will have children. Protected members are not available
outside of the family tree.

```c++
Student student;
student.name = "Bob"; // accessing public member variable
float gpa = student.GetGPA(); // accessing public member function
```

## Creating separate .cpp .hpp/.h files for class objects

It is standard to keep your class and function declarations within a header (.hpp or .h) file, with the
function definitions within a source (.cpp) file.
Within any header file, you need to wrap it with the following:

```c++
#ifndef _MYCLASS
#define _MYCLASS
// Code goes here
#endif
```

This ensures that the compiler does not try to “copy” the code from this file multiple times, which
causes a redeclaration error.

When defining functions in a .cpp file and outside of the class declaration, you need to specify what
class it belongs to with the scope resolution operator ```::```

```c++
void Student::SetGpa( float gpa )
{
    m_gpa = gpa;
}
```

## Constructors

Class constructors are a special type of function in a class. The constructor must have the same name as
the class. Constructors are called immediately upon instantiation of an object.

## Overloading constructors

Like with function overloading, you can declare multiple constructor functions that have different
parameter lists. This can come in handy if you want to initialize a class, but may have different
amounts of information available when the object is instantiated.

## Destructors

Destructors are called automatically once an instantiated object loses scope – when the object is
destroyed. You cannot overload a destructor. The destructor must share the name of the Class, but with
a tilde ~ at the beginning. No parameters.

## Struct vs. Class

Keep in mind that with members of Structs, they are public by default. With classes, members are
private by default. Structs and Classes can both have member variables and functions.

# Inheritance

## How to inherit

You can create a class that inherits any public and protected members from another class:

```c++
class Student : public Human
{
    // ...
};

class Teacher : public Human
{
    // ...
};
```

## Calling parent constructor and functions

Within a child class constructor, you can explicitly call the parent constructor through the initializer list.
You can pass in any arguments that are needed.

```c++
Student::Student() : Human()
{
    // ...
}
```

## Overriding / Redefining

Child classes can overwrite (aka redefine) functions that were originally declared in the parent class. If
the parameter list is the same, you are overwriting that original function. Within the new version of the
function, you can also call the parent version as needed.

```c++
void Student::AddZipcode( int zip )
{
    Human::AddZipcode( zip );
}
```
