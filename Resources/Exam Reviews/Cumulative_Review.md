# C++ Basics

# Control Flow

# Functions

# Const

# Arrays

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
