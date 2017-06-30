# CS 200 Lab 05: Structs

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

Start by creating a project. We will have separate source files for each struct,
and the main source file will contain functions for each lab.

Create five source files:

* main.cpp
* Student.hpp
* Fraction.hpp
* CoordinatePair.hpp
* Scholarship.hpp

Your **main.cpp** file should start out with the following:

```c++
#include <iostream>
#include <string>
using namespace std;

#include "Student.hpp"
#include "Fraction.hpp"
#include "CoordinatePair.hpp"
#include "Scholarship.hpp"

void Program1()
{
}

void Program2()
{
}

void Program3()
{
}

void Program4()
{
}

int main()
{
    while ( true )
    {
        cout << "1. Program 1" << endl;
        cout << "2. Program 2" << endl;
        cout << "3. Program 3" << endl;
        cout << "4. Program 4" << endl;
        cout << "Run which lab? ";
        int choice;
        cin >> choice;

        switch( choice )
        {
            case 1:     Program1();     break;
            case 2:     Program2();     break;
            case 3:     Program3();     break;
            case 4:     Program4();     break;
        }

        cout << endl << endl;
    }

    return 0;
}
```

---


# Program 1: Student struct - just member variables

Within **Student.hpp**, start with the following:

```c++
#ifndef _STUDENT_HPP
#define _STUDENT_HPP

#include <string>
using namespace std;

struct Student
{
};

#endif
```

Declare the following variables within this struct:

* name, a string
* degree, a string
* gpa, a double

Back in **main.cpp**, in the **Program1()** function, do the following:

**1.** Declare a new variable whose data type is ```Student``` named ```newStudent```.

**2.** The Student data-type has the name, degree, and gpa variables. Assign values to these variables.

Remember that to assign a value to a variable that *belongs to a class*, you need to use
the dot operator ```.```, for example:

```c++
myClassObject.variable = 123;
```

**3.** After assigning values to the variables, display the values of these variables with a ```cout``` statement. For example:

```c++
cout << myClassObject.variable << endl;
```






## Example output

        Student name:   Ashu
        Degree:         CS
        GPA:            3.0



## Hints

<details><summary><strong> Declaring a variable whose data type is a struct/class </strong></summary>

```c++
Student newStudent;
```

</details>

<details><summary><strong> Assign values to the struct/class' member variables </strong></summary>

```c++
newStudent.name = "Bob";
newStudent.degree = "English";
newStudent.gpa = 2.8;
```

</details>

<details><summary><strong> Display member variables </strong></summary>

```c++
cout << newStudent.name << "\n" << newStudent.degree << "\n" << newStudent.gpa << endl;
```

</details>







---

# Program 2: Fraction - A struct with member variables and fractions

In the **Fraction.hpp** file, begin with the following:

```c++
#ifndef _FRACTION_HPP
#define _FRACTION_HPP

struct Fraction
{
};

#endif
```

Create two member variables:

* numerator, an integer
* denominator, an integer

And create member functions:

1. Setup
    * return type: void
    * parameters: ```int n, int d```

1. Display
    * return type: void
    * parameters: none

1. Add
    * return type: Fraction
    * parameters: ```Fraction other```

1. Subtract 
    * return type: Fraction
    * parameters: ```Fraction other```

1. Multiply
    * return type: Fraction
    * parameters: ```Fraction other```

1. Divide
    * return type: Fraction
    * parameters: ```Fraction other```


These functions will be created *inside* the struct. Include your
opening and closing curly braces ```{``` and ```}```.

If you have trouble writing the struct, expand the following hint:

<details><summary><strong> Struct declaration </strong></summary>

```c++
#ifndef _FRACTION_HPP
#define _FRACTION_HPP

struct Fraction
{
    int numerator;
    int denominator;

    void Setup( int n, int d )
    {
    }

    void Display()
    {
    }

    Fraction Add( Fraction other )
    {
    }

    Fraction Subtract( Fraction other )
    {
    }

    Fraction Multiply( Fraction other )
    {
    }

    Fraction Divide( Fraction other )
    {
    }
};

#endif


```

</details>


Now it's time to define the functions.

### Setup

Here, the input parameter variables are ```n``` and ```d```.

Set your member variable ```numerator``` to the value of ```n```,
and set your member variable ```denominator``` to the value of ```d```.

### Display

Use ```cout``` to display the values of the two member variables
```numerator``` and ```denominator```.

For example, if numerator is 1 and denominator is 2:

        1/2



### Multiply

![How to multiply fractions](images/fractions_multiply.png)

To multiply two fractions, you multiply both numerators and denominators together.

### Divide

![How to divide fractions](images/fractions_divide.png)

### Add

![How to add fractions](images/fractions_add.png)

### Subtract

![How to subtract fractions](images/fractions_subtract.png)






![horizontal rule](images/hr.png)


# Questions

1. Can a struct contain variables?
1. Can a struct contain functions?
1. What does setting a member to private do?
1. What does setting a member to public do?
1. When declaring a variable whose data type is a class, you need to add what to the end?


