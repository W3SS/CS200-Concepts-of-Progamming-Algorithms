# CS 200 Lab 06b: Classes

---

[Information](#information) |
[Helper](https://github.com/Rachels-Courses/CS200-Concepts-of-Progamming-Algorithms/blob/2017-06-Summer/Assignments/In-class%20Labs/Lab%2005%20-%20Structs%20-%20Helper.md) |
[Lab](#lab) | [
Questions](#questions)

---

# Information

## Lab topics

* Pointers
* Dynamic variables
* Dynamic arrays

## Rules

* For **in-class labs**, collaboration is allowed.
    * If you work with another student on an assignment, make sure that you both
    turn in a copy of the work, and also mention in the D2L comments who you worked with.
    * You can also ask classmates questions if you're unsure on something.
    * You can ask the instructor for help at any time.

## Reference

* [How to use Visual Studio](https://github.com/Rachels-Courses/Course-Common-Files/blob/organized/STUDENT_REFERENCE/HOW_TO/Visual_Studio.md)
* [How to use Code::Blocks](https://github.com/Rachels-Courses/Course-Common-Files/blob/organized/STUDENT_REFERENCE/HOW_TO/Code_Blocks.md)
* [How to turn in code](https://github.com/Rachels-Courses/Course-Common-Files/blob/organized/STUDENT_REFERENCE/HOW_TO/Turning_in_code.md)


## Turn in

Once you are finished with a project, zip up the entire folder that contains
all source files and project/solution files. Turn in this zip file to **Desire2Learn**.

Also make sure to turn in a text file with your answers to the [question](#questions) section.




![horizontal rule](images/hr.png)

---

# Lab

For this lab, each program should go **in its own solution, and have its own files.**

Make sure to turn in each solution set on its own.

---

# Program 1: A Dynamic Array wrapper

For this lab, we will *wrap* a dynamic array within a class. Using special
class methods like **constructors** and **destructors**
(see: [the helper docs]()), we can automatically allocate and deallocate memory.

Create the following files:

* lab06b_program1.cpp
* DynamicArray.hpp
* DynamicArray.cpp

Use the following starter code:

**DynamicArray.hpp**

```c++
#ifndef _DYNAMIC_ARRAY_HPP
#define _DYNAMIC_ARRAY_HPP

#include <string>
#include <iostream>
using namespace std;

class DynamicArray
{
    public:
    DynamicArray( int size );
    ~DynamicArray();

    void Set( int index, string value );
    string Get( int index );
    int GetSize();

    void Display();

    private:
    string* m_arr;
    int m_size;
};

#endif
```

**DynamicArray.cpp**

```c++
#include "DynamicArray.hpp"

DynamicArray::DynamicArray( int size )
{
    cout << "DynamicArray constructor" << endl;
    // TODO: Initialize dynamic array
}

DynamicArray::~DynamicArray()
{
    cout << "DynamicArray destructor" << endl;
    // TODO: Free dynamic array
}

void DynamicArray::Set( int index, string value )
{
    // Set item at position *index* to the value *value*.
}

string DynamicArray::Get( int index )
{
    // Return the item at position *index*
    return ""; // temp
}

int DynamicArray::GetSize()
{
    // Return the size of the array
    return -1; // temp
}

void DynamicArray::Display()
{
    // Display all elements of the array
}
```

**main.cpp**

```c++
#include <iostream>
#include <string>
using namespace std;

#include "DynamicArray.hpp"

int GetValidInput( int min, int max )
{
    return -1; // temp
}

int GetArraySize()
{
    return -1; // temp
}

int MainMenu()
{
    return -1; // temp
}

void InitializeArray( DynamicArray& arr )
{
}

void GetNewArrayValue( DynamicArray& arr )
{
}

int main()
{
    int arraySize = GetArraySize();

    DynamicArray arr( arraySize );

    InitializeArray( arr );

    while ( true )
    {
        arr.Display();

        int choice = MainMenu();

        if ( choice == 1 )
        {
            GetNewArrayValue( arr );
        }
        else if ( choice == 2 )
        {
            break;
        }
    }

    return 0;
}
```










![horizontal rule](images/hr.png)


# Questions

1. Can a struct contain variables?
1. Can a struct contain functions?
1. What does setting a member to private do?
1. What does setting a member to public do?



