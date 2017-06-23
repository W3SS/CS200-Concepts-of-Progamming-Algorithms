# CS 200 Lab 04b: Dynamic variables and arrays

---

[Information](#information) |
[Helper](https://github.com/Rachels-Courses/CS200-Concepts-of-Progamming-Algorithms/blob/2017-06-Summer/Assignments/In-class%20Labs/Lab%2004b%20-%20Dynamic%20arrays%20-%20Helper.md) |
[Lab](#lab) | [
Questions](#questions)

---

# Information

## Lab topics

* Pointers

## Rules

* For **in-class labs**, collaboration is allowed.
    * If you work with another student on an assignment, make sure that you both
    turn in a copy of the work, and also mention in the D2L comments who you worked with.
    * You can also ask classmates questions if you're unsure on something.
    * You can ask the instructor for help at any time.

## Reference

* [Creating a new project in Visual Studio](https://github.com/Rachels-Courses/Course-Common-Files/blob/master/Visual-Studio/New%20project%20howto.md)

## Turn in

Once you are finished with a project, zip up the entire folder that contains
all source files and project/solution files. Turn in this zip file to **Desire2Learn**.

Also make sure to turn in a text file with your answers to the [question](#questions) section.







![horizontal rule](images/hr.png)

---

# Lab

## Program 1: Dynamic variables

In your program, create three pointers:

* myInt, an integer pointer.
* myStr, a string pointer.
* myFloat, a float pointer.

Afterward, you will allocate memory for each of these variables with the **new**
keyword. Note that the data-type that goes after new must match the pointer type. (See
the reference for sample code).

Then, assign values to each of the variables. Make sure to use the de-reference
operator!

* myInt = 20
* myStr = (your name)
* myFloat = 199.99

Display the value of each of the variables. You will also need a de-reference operator
here.

Finally, free the memory for each pointer using the delete keyword.

**Sample Output:**

        20        yourname      199.99


### Hints

<details>
<summary><strong>
        Using the new command for a dynamic variable
</strong></summary>

```c++
int * myInt = new int;
```

Make sure to open the [helper doc](https://github.com/Rachels-Courses/CS200-Concepts-of-Progamming-Algorithms/blob/2017-06-Summer/Assignments/In-class%20Labs/Lab%2004b%20-%20Dynamic%20arrays%20-%20Helper.md)
for help.

</details>

<details>
<summary><strong>
        Using the delete command for a dynamic variable
</strong></summary>

```c++
delete myInt;
```

Note that this is how you delete a dynamic variable, **not** a dynamic array.

</details>


---

## Program 2:  Lotto numbers

You will use a random number generator for this program, so you will need the
following libraries:

```c++
#include <cstdlib>      // to use rand()
#include <ctime>        // to use time()
```
        
Seed the random number generator with:

```c++
srand( time( NULL ) ); // (At the beginning of main())
```

You only need to seed the generator **once** -- at the beginning of the program.

Then, ask the user to enter the amount of lotto balls there will be.
Store the value in an integer variable.

Create a dynamic array called **lottoNumbers**. It will be the size that the user specified.

For each element of the array, from 0 to size, set the element's value to a random
number between 0 and 100.

Display the value of each lotto ball while generating.

At the end of the program, delete the dynamic array before the program ends. (Before the return 0;)

**Sample Output:**

        Lotto number count: 5
        57      11      74      91      35



### Hints

<details>
<summary><strong>
        Using the new command for a dynamic array
</strong></summary>

```c++
int numberCount = 10;
int* numberList = new int[ numberCount ];
```

</details>

<details>
<summary><strong>
        Using the delete command for a dynamic array
</strong></summary>

```c++
delete [] numberList;
```

</details>

<details>
<summary><strong>
        Iterating through each element of the dynamic array
</strong></summary>

Use your variable that stores the size of the array to use in your for loop.

```c++
for ( int i = 0; i < numberCount; i++ )
{
        cout << numberList[i] << "\t";
}
```

</details>


---

## Program 3:

---

## Program 4:

---

## Program 5: Array of pointers

An array can also store pointers. Just like we can have a single
pointer variable that points to the address of another variable,
we can also have an array of pointers which each point to different
(or the same) addresses.

For this program, start with the following code:

```c++
#include <iostream>
#include <string>
#include <cstdlib>      // for srand and rand
#include <ctime>        // for time
using namespace std;

const int MANAGER_COUNT = 2;
const int EMPLOYEE_COUNT = 5;

void AssignManagers( string managerNames[ MANAGER_COUNT ], string * employeeManagers[ EMPLOYEE_COUNT ] )
{
}

void DisplayEmployees( string employeeNames[ EMPLOYEE_COUNT ], string * employeeManagers[ EMPLOYEE_COUNT ] )
{
}

int main()
{
    srand( time( NULL ) );




    while ( true );
    return 0;
}

```

#### main()

We will have three arrays in this program:

* managerNames, a string array of managers' names
* employeeNames, a string array of employees' names
* employeeManagers, a string-pointer array, one for each employee, that is meant to point to a manager.

Declare the ```managerNames``` string array - its size should be the ```MANAGER_COUNT```. Then initialize the two manager names in this array.

Declare the ```employeeNames``` string array - its size should be the ```EMPLOYEE_COUNT```. Initialize five employee names in this array.

Declare the ```employeeManagers``` string-pointer array - its size should be ```EMPLOYEE_COUNT```. Do not initialize this array.

Afterward, call the two functions:

* AssignManagers - pass in ```managerNames``` and ```meployeeManagers```.
* DisplayEmployees - pass in ```employeeNames``` and ```meployeeManagers```.



***Example output:***

        Employee 0	Serena	 Manager: Artemis
        Employee 1	Amy	 Manager: Artemis
        Employee 2	Raye	 Manager: Luna
        Employee 3	Lita	 Manager: Artemis
        Employee 4	Mina	 Manager: Artemis


#### AssignManagers()

We will use a random number generator to randomly select managers for each employee.

To get a number between 0 and 9, we would do ```int number = rand() % 10```.

Create a for-loop to iterate from 0 to ```EMPLOYEE_COUNT```:

* Create a variable called ```index```. Assign it the value of ```rand() % MANAGER_COUNT```.
* Get the **address** of ```managerNames[ index ]``` and assign it to the ```employeeManagers[i]``` item (if *i* is your for-loop counter.)

#### DisplayEmployees()

Use another for-loop, going over all the employees (use ```EMPLOYEE_COUNT``` again).

Each cycle of the loop, you will display:

* The value of the counter
* The employee name at this index (via ```employeeNames```)
* The manager for this employee (via ```employeeManagers```)

Note that you have to **de-reference** the employeeManagers element in order
to get the actual manager's name instead of the address of that variable.

### Hints

<details>
<summary><strong>
        Creating non-pointer arrays and initializing them
</strong></summary>

```c++
string managerNames[ MANAGER_COUNT ] = { "Artemis", "Luna" };
string employeeNames[ EMPLOYEE_COUNT ] = { "Serena", "Amy", "Raye", "Lita", "Mina" };
```

</details>

<details>
<summary><strong>
        Creating an array of pointers
</strong></summary>

```c++
string * employeeManagers[ EMPLOYEE_COUNT ];
```

</details>


<details>
<summary><strong>
        AssignManagers
</strong></summary>

```c++
void AssignManagers( string managerNames[ MANAGER_COUNT ], string * employeeManagers[ EMPLOYEE_COUNT ] )
{
    for ( int i = 0; i < EMPLOYEE_COUNT; i++ )
    {
        int index = rand() % MANAGER_COUNT;
        employeeManagers[i] = &managerNames[ index ];
    }
}
```

</details>


<details>
<summary><strong>
        DisplayEmployees
</strong></summary>

```c++
void DisplayEmployees( string employeeNames[ EMPLOYEE_COUNT ], string * employeeManagers[ EMPLOYEE_COUNT ] )
{
    for ( int i = 0; i < EMPLOYEE_COUNT; i++ )
    {
        cout << "Employee " << i << "\t" << employeeNames[i] << "\t Manager: " << *employeeManagers[i] << endl;
    }
}
```

</details>





![horizontal rule](images/hr.png)


# Questions

1. Using a pointer, how do you allocate memory for a new dynamic variable?
1. Using a pointer, how do you allocate memory for a new dynamic array?
1. How do you deallocate memory for a dynamic variable?
1. How do you deallocate memory for a dynamic array?

