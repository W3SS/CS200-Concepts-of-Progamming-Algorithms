# Tools

* Debugger - A debugger generally contains a set of tools to help you debug your program. For example: Breakppoints, a *locals* window to view variable values, a *stack trace* to see functions called.
* Compiler - The compiler is the program that converts source code into a *binary executable*. On Windows, these are .exe files.
* Source control - A source control program will keep track of changes to your code made over time, as well as offer features to help you maintain the code, such as automatic merging.

---

# C++ Basics

## Declaring and initializing variables

Know that, without initializing a variable, it will contain garbage.

```c++
int number;
int count = 2;
float cost = 2.39;
char letter = 'A';
string word = "Hello!";
```

## Data types and values they can contain

* Integer
    * Whole numbers
* Float, Double
    * Numbers that may have a decimal point
* Boolean
    * ```true``` or ```false```.
    * Can be assigned int; 0 = false, any other number = true.
* String
    * Values are stored within double-quotes.
* Character
    * Single-character values are stored within single-quotes.

## Operators

### Arithmetic operators

Arithmetic operators are operators that allow us to perform math operations.

<table>
<tr>
<th> Addition </th> <th> Subtraction </th> <th> Multiplication </th> <th> Division </th><th> Modulus </th>
</tr>
<tr>
<td> <pre>+</pre> </td><td> <pre>-</pre></td> <td> <pre>*</pre> </td><td> <pre>/</pre> </td><td> <pre>%</pre> </td>
</tr>
</table>

### Relational operators

Relational operators allow us to compare values between two items, such as two variables or
a variable and a number.


<table>
<tr>
<th> Equivalent </th> <th> Not-equal </th> 
<th> Less-than </th> <th> Less-than-or-equal-to </th>
<th> Greater-than </th> <th> Greater-than-or-equal-to </th>
</tr>
<tr>
<td> <pre>==</pre> </td><td> <pre>!=</pre></td>
<td> <pre>&lt;</pre> </td><td> <pre>&lt;=</pre></td> 
<td> <pre>&gt;</pre> </td><td> <pre>&gt;=</pre></td>
</tr>
</table>

### Logic operators

Logic operators allow us to string together multiple expressions together.

<table>
<tr>
<th> And </th> <th> Or </th> <th> Not </th>
</tr>
<tr>
<td> <pre>&amp;&amp;</pre> </td><td> <pre>||</pre></td> <td> <pre>!</pre> </td>
</tr>
</table>

## Input and output

Remember that ```<<``` and ```>>``` are called **stream operators**. Remember which direction they point for each
item. Also note that you can chain together string literals (within double-quotes) and variable values.

```c++
cin >> amount;
cout << "Amount: " << amount << endl;
cout << "\n New Line" << endl;
cout << "\t Tab" << endl;
```

To get a full line of text (including spaces), you need to use the ```getline``` function:

```c++
string name;
getline( cin, name );
```

However, if you're mixing between ```cin >> ...``` and ```getline( cin, ... )```, you will need to put
a ```cin.ignore()``` after your ```cin >> ...``` commands, otherwise the program will skip over your getlines.

```c++
int time;
string todo;

cout << "Enter time: ";
cin >> time;
cin.ignore();

cout << "Enter to-do item: ";
getline( cin, todo );
```

## Types of errors

* Syntax error
    * Syntax errors are due to typos of misspellings, and violate the rules of the C++ language.
    * The compiler catches tehse.
* Runtime error
    * A runtime error is not caught by the compiler. The error occurs when a program hits bad code
    and will cause the program to crash.
* Logic error
    * A logic error won't necessarily cause a runtime error (it might, it might not).
    * Logic errors could be incorrect formulas, incorrect program flow, or general
    incorrect logic that can cause calculations to be off or functionality to behave
    in an unintended manner.

---

# File I/O

## fstream library

To use file input and output, you need to include the fstream library in your program:

```c++
#include <fstream>
```

## Creating, opening, and closing files.

To create an *input-stream object* (to read info from a file), you will declare an **ifstream** variable:

```c++
ifstream input;
input.open( "data.txt" );
// ...
input.close();
```

To create an *output-stream object* (to write data from the program into a text file),
you will declare an **ofstream** variable:

```c++
ofstream output;
output.open( "savegame.txt" );
// ...
output.close();
```

File input and output work very similarly to your *cin* and *cout* statements, but you have to use
a variable instead of just the *cin* and *cout* commands...

```c++
outputFile << "Once upon a time..." << endl;

inputFile >> name1 >> name2 >> name3;

getline( inputFile, lineOfText );
```

---

# Control Flow

## Boolean expressions

Be familiar with types of boolean expressions. Realize that all of these are questions that return either
true or false, which can be used with if statements and loops.

<table>
<tr>
<th> Is equal to </th>
<td colspan="3"><pre> var1 == var2 </pre></td>
</tr>

<tr>
<th> Is equal to </th>
<td colspan="3"><pre> var1 == var2 </pre></td>
</tr>

<tr>
<th> Is not equal to </th>
<td colspan="3"><pre> var1 != var2 </pre></td>
</tr>

<tr>
<th> Less than </th>
<td colspan="3"><pre> var1 &lt; var2 </pre></td>
</tr>

<tr>
<th> Less than or equal to </th>
<td colspan="3"><pre> var1 &lt;= var2 </pre></td>
</tr>

<tr>
<th> Greater than </th>
<td colspan="3"><pre> var1 &gt; var2 </pre></td>
</tr>

<tr>
<th> Greater than or equal to </th>
<td colspan="3"><pre> var1 &gt;= var2 </pre></td>
</tr>

<tr>
<th> Is true </th>
<td><pre> var1 == true </pre></td>
<td><pre> var1 != false </pre></td>
<td><pre> var1 </pre></td>
</tr>
<tr>
<th> Is false </th>
<td><pre> var1 == false </pre></td>
<td><pre> var1 != true </pre></td>
<td><pre> !var1 </pre></td>
</tr>


</table>

Note that you can check if something is true or false with the shorthand:

```c++
if ( var1 ) // if true
if ( !var1 ) // if false
```

## And, or

You can chain together boolean expressions in a single If Statement or Loop to check for multiple
conditions.

```c++
if ( var1 < 0 || var1 > 10 ) // between 0 and 10
if ( var1 >= 0 && var1 <= 10 ) // between 0 and 10
if ( var1 >= 0 && var1 <= 10 )
```

## How to write if statments

The if statement will stop checking additional conditions (the other if / else ifs) once it finds a match.
The else statement is executed if all prior checks were all false.

```c++
if      ( choice == 'a' ) { /* ... */ }
else if ( choice == 'b' ) { /* ... */ }
else if ( choice == 'c' ) { /* ... */ }
else                      { /* ... */ }
if ( var1 < 0 ) { cout << "var less than 0"; }
else { cout << "var greater than or equal to 0"; }
```

## Break and continue

You can use a **break** statement to break out of a loop. You can use **continue** to skip the rest of the code
within a loop, but continue the loop, such as if there is an error.

```c++
while ( true )
{
    cin >> choice;
    if ( choice == 'q' ) { break; } // break out of the loop
}

while ( true )
{
    cin >> choice;
    if ( choice == 'a' ) { continue; } // skip "Hello" and start next cycle of loop
    cout << "Hello" << endl;
}
```

## Switch statements

You can use a switch statement to check the value of an integer or character variable. Be aware that
each case statement needs to end with a break; - if it does not, it the program will execute the case
statement directly afterwards as well. default: is used like the “else” statement.

If choice = 'b', the output will be BC , since the 'b' case does not have a break;

```c++
switch( choice )
{
    case 'a':
    cout << "A";
    break;
    
    case 'b':
    cout << "B";
    
    case 'c':
    cout << "C";
    break;
    
    default:
    cout << "D";
}
```

## How to write a while loop

Think of a while loop like an if statement, except it will keep looping until the condition is false. You
can also use && and || to add additional conditions.

```c++
int count = 0;
while ( count < 100 )
{
    count++;
}
```

## How to write a do-while loop

With do-while loops, the inner contents will always be run at least once. Then, if the condition is false,
the loop will stop. Otherwise, if the condition is true, it will keep looping.

```c++
do {
    cout << "Enter a #: ";
    cin >> choice;
} while ( choice < 0 || choice > 10 );
```

## How to write a for loop

For Loops are good for counting. Note that the first part is creating and/or initializing a variable, the
second part is the condition, and the third part is a command that will be done each time through the
loop.

```c++
for ( int i = 0; i < 10; i++ )
{
    cout << i;
}
for ( int j = 100; j > 0; j­­ )
{
    cout << j;
}
```

## Nested statements

Once inside a loop or an if statement, you can continue adding if statements and loops within.

A nested if statement can also be written with a single if statement and &&.

```c++
// This:
if ( var1 > 0 )
{
  if ( var < 10 )
  {
    cout << "0 < x < 10”;
  }
}

// and this are equivalent:
if ( var1 > 0 && var1 < 10 )
{
  cout << "0 < x < 10";
}
```

When nesting for-loops, the external loop will begin its first cycle,
the internal loop will complete all its cycles, then the external cycle will end
and it will begin its second cycle, then the internal loop will complete all its cycles again,
and so on...

```c++
for ( int y = 0; y < 5; y++ )
{
   for ( int x = 0; x < 3; x++ )
   {
      cout << x << ", " << y << endl;
   }
}
```

Will display:

      0, 0
      1, 0
      2, 0
      0, 1
      1, 1
      2, 1
      0, 2
      1, 2
      2, 2
      0, 3
      1, 3
      2, 3
      0, 4
      1, 4
      2, 4

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

Const can be used in several different ways throughout our programs.

## Named constants

It is bad programming practice to use "magic numbers"...

```c++
DoAThing( 5 ); // WHY 5? WHAT DOES THAT MEAN?!
```

Instead of hard-coding numeric values in our programs, we can give them "labels" by
creating named-constants instead.

Named constants are essentially variables but they can't be changed... therefore, they're called *named constants*.

```c++
const int MAX_STUDENT_COUNT = 18;
```

With a named constant, it is standard to give them ALL_UPPERCASE_NAMES, and you will also need to assign its value immediately.

```c++
int main()
{
   const int MAX_STUDENT_COUNT = 10;
   
   string studentList[ MAX_STUDENT_COUNT ];
   
   FailStudents( studentList, MAX_STUDENT_COUNT );
};
```

## Constant pass-by-reference

When an object (or an array) being passed to a function might be large and costly to copy over (with pass-by-value),
it is common to do a pass-by-const-reference instead of pass-by-value or pass-by-reference.

```c++
void Display( const string& name );
```

This way, we have the benefit of the efficiency of pass-by-reference, without the danger of the function
potentially changing the value of our parameter.

## Constant return types

Likewise, sometimes you want to return the reference to an object from your function, but you want to make sure
that the object isn't changed by whatever *called* the function. In this case, you can make the return-type const.

```c++
const string& GetStudentName( int index, const Database& db )
{
   // code goes here to get student name
   return studentName;
}
```

## Constant functions

With classes, you might want to write a function that will display some information,
but not change any of the member variables. In this case, you can declare the member function
as *const*.

```c++
class Vector
{
   private:
   float x, y;
   
   void Display() const
   {
      cout << x << ", " << y << endl;
   }
};
```

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

# Pointers

## Operators

When working with pointers, you will need to know these operators.

<table>
<tr>
<th> Address-of </th> <th> Dereference </th> 
<th> Arrow operator </th> 
</tr>
<tr>
<td> <pre>&amp;</pre> </td><td> <pre>*</pre></td>
<td> <pre>-&gt;</pre> </td>
</tr>
</table>

To get the address of a variable, you prepend the ```&``` operator to
the variable's name:

```c++
int myVar;

cout << &myVar << endl; // displays address
```

To dereference a pointer variable to get the value of the item that the pointer is pointing at,
prepend the ```*``` operator to the pointer name:

```c++
string myName = "Not-bob";

string * ptrName = &myName;

cout << *ptrName << endl; // Displays "Not-bob"
```

If you have a pointer to an object (a variable whose type is a class),
before you access its member variables you will have to de-reference the class-pointer
first. 

However, the order-of-operations in C++ will go to the dot operator ```.``` before
the dereference operator ```*```, so you would have to write it this way:

```c++
(*ptrPerson).GetName();
```

A shortcut is to use the arrow operator ```->``` instead of the dot operator:

```c++
ptrPerson->GetName();
```

## Declaring a pointer

To declare a pointer, you need to specify the data-type that your pointer will point to.
You also need to use the ```*``` symbol after this data-type to show that it is a pointer:

```c++
int* intPointer; // ok
string * stringPointer; // ok
float *floatPointer; // ok
```

The asterisk can be attached to the variable name, the data type, or to neither - doesn't matter.

It is **good programming practice** to set a pointer to ```nullptr``` when it is not in use.

```c++
string* ptrCurrent = nullptr;
```

## Assigning an address to a pointer

To assign an address to a pointer, you need the address-of operator:

```c++
string* ptrString;
string text = "BLAH";
ptrString = &text;
```

## Pointing multiple things to one place

You can have one item being pointed to by multiple pointers:

```c++
string student1 = "rjm";

string* ptrBestStudent = &student1;
string* ptrCoolestStudent = &student1;
```

If you use the assignment operator ```=``` between two pointers,
the left-hand pointer will be set to point to whatever the
right-hand pointer is pointing to.


```c++
string student1 = "rjm";

string* ptrBestStudent = &student1;
string* ptrCoolestStudent = ptrBestStudent;
```

## Getting the value that a pointer is pointing at

To get the *value* of the item that a pointer is pointing to,
you need to dereference your pointer.

```c++
string student1 = "rjm", student2 = "ram", student3 = "jam";
string* ptrCurrent = &student1;

cout << *ptrCurrent << endl;
```

---

# Dynamic variables and memory management

## Types of memory errors

### Invalid memory access

This usually happens when trying to access unallocated (or already freed) memory.

For example:

```c++
char* nothin; // not pointing to anything but garbage
cout << *nothin; // de-referencing a pointer pointing to garbage will crash your program.
```

Or:

```c++
cout << "List of numbers" << endl;
int* listOfNumbers = new int[5];

// (Doing stuff with number array here)

delete [] listOfNumbers;

listOfNumbers[3] = 300; // trying to assign a value to something that has already been freed.
```

### Memory leak

A memory leak occurs when new memory is *allocated* (via ```new```),
but it is never *deallocated* (via ```delete```).

```c++
int main()
{
   int studentSize;
   cin >> studentSize;
   string* studentList = new string[ studentSize ];
   
   // delete your dynamic variables! :(
   
   return 0;
}
```

Here the studentList is never deallocated so you lose that memory!

### Missing allocation

This occurs when you try to free memory that has already been freed.

```c++
int main()
{
   int* myArray = new int[50];
   delete [] myArray;
   
   // later...
   
   delete [] myArray;      // This will cause a problem!

   return 0;
}
```

### Uninitialized memory access

This happens when you try to read the value of an uninitialized variable.

```c++
int* ptrNumber;
cout << *ptrNumber << endl;
```

## The Stack and the Heap

* Non-dynamic variables declared within functions or as function parameters
are allocated *on the stack*.
* Dynamic variables declared and accessed via pointers are allocated
*on the heap*.
* Variables declared on the stack will automatically be freed.
* Memory on the heap doesn't get freed automatically.
* There is a size restriction on the stack.
* There is no size restriction on the heap.

## Dynamic variables

Dynamic variables must be created via pointers, and using the ```new``` and ```delete``` keywords.

These dynamic variables still must be dereferenced to access their values.

```c++
string* dynamicString = new string;

*dynamicString = "Hello";
cout << *dynamicString << endl;

delete dynamicString;
```

## Dynamic arrays

Dynamic arrays must be created via pointers, and using the ```new``` and ```delete``` keywords.

Dynamic arrays will be used like the static arrays you're used to; that is, you don't need to
dereference the array to access an element.

```c++
int* numberList = new int[ 100 ];

for ( int i = 0; i < 100; i++ )
{
   numberList[i] = i * 2;
   cout << numberList[i] << endl;
}

delete [] numberList;
```

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
