# CS 200 Lab 04b: Dynamic variables and arrays

---

[Information](#information) |
[Helper]() |
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
        Using the new command
</strong></summary>

```c++
int * myInt = new int;
```

Make sure to open the [helper doc]()
for help.

</details>

<details>
<summary><strong>
        Using the delete command
</strong></summary>

```c++
delete myInt;
```

Note that this is how you delete a dynamic variable, **not** a dynamic array.

</details>


---

## Program 2: 

Add the following struct to the top of your source file (it can go in the same file as
main()):

        struct Person
        {
            string name;
            Person* ptrFriend;
        };

The Person class has a name, and a pointer to their friend. Their friend must also be a
Person type.

Within main, do the following:

Create three Person pointers: personA, personB, and personC. Allocate memory for
each of them – you will need to create new Person for each.

Set up names for personA, personB, and personC. You can set the value of a class
member in one of two ways, when using pointers:

        (*personA).name = "Bob";        // Using the de-reference operator
        
        personA->name = "Bob";          // Using the member-of operator
        
Set up your person variables' names. For example:

<table>
<tr><td>PersonA</td><td>PersonB</td><td>PersonC</td></tr>

<tr>
<td>
Harry
</td>
<td>
Ron
</td>
<td>
Hermione
</td>
</tr>
</table>

Set each person's ptrFriend pointer to point to the address of another Person. You
won't need the address-of operator, since personA, B, and C are already pointers, so you
can set one pointer to another pointer!

        personA->ptrFriend = personB;
        
Set friendships as following:

* Person A's friend is Person B
* Person B's friend is Person C
* Person C's friend is Person A

Display each person's name and the name of their friend. You can access
members through the friend pointer:

        personA->ptrFriend->name
        
**Sample Output:**

        Person A: Joe, friend: Austin
        Person B: Austin, friend: Elly
        Person C: Elly, friend: Joe


---

## Exercise 3

You will use a random number generator for this program, so you will need the
following libraries:

        #include <cstdlib>      // to use rand()
        #include <ctime>        // to use time()
        
Seed the random number generator with:

        srand( time( NULL ) ); // (At the beginning of main())

Then, ask the user to enter the amount of lotto balls there will be. Store the value in a **size**
variable.

Create a dynamic array called **lottoNumbers**. It will be the size that the user
specified.

For each element of the array, from 0 to size, set the element's value to a random
number between 0 and 100.

Display the value of each lotto ball while generating.

At the end of the program, delete the dynamic array before the program ends. (Before the return 0;)

**Sample Output:**

        Lotto number count: 5
        57      11      74      91      35

---

## Exercise 4

Create the following structs at the top of the source file:

        struct Employee
        {
            string name;
        };
        struct Manager
        {
            string name;
            Employee* employees;
            int employeeCount;
        };

Create an array of strings, that contain a list of names. This can be a normal
static array with a set size. For example:

        string names[ 16 ] = { 
            "Koios", "Julianna", "Agata", "Arundhati",
            "Zemfira", "Fedya", "Kim", "Ashok",
            "Jouni", "Blandina", "Ampelio", "Rosmunda",
            "Breeshey", "Ferdinand", "Gertrude", "Sarit"
            };

Ask the user how many managers there should be. Store this value in an integer called **managerCount**.

Create a Manager pointer called **managers**, and dynamically allocate an array
of the size of **managerCount**.

Then, create a for-loop that will go from 0 to **managerCount**. For each manager...:

* Assign the manager a random name from the names list:

        managers[i].name = names[ rand() % 16 ];
        
* Randomly set this manager's **employeeCount** to a value between 0 and 3.

* Use the employees pointer in the Manager class to create a dynamic array of employees,
if employeeCount is above 0.

* Create a second for-loop that will set up each of the employees. Iterate from 0 to
        **managers[i].employeeCount**:
        * Assign the employee a random name from the names list:
        
        managers[i].employees[j].name = names[ rand() % 16 ];


After all the managers and employees are set up, display a list of managers and their
employees to the screen with another set of for-loops.

        for ( int m = 0; m < managerCount; m++ )
        {
            cout << endl;
            cout << "Manager:           " 
                << managers[m].name << endl;
            cout << "Underling Count:   " 
                << managers[m].employeeCount << endl;
            
            for ( int e = 0; e < managers[m].employeeCount; e++ )
            {
                cout << "\t" << e+1 << ". " 
                    << managers[m].employees[e].name << endl;
            }
        }


**Sample Output:**

        How many managers? 5
        Manager:           Ashok
        Underling Count:   1
                1. Blandina
        Manager:           Arundhati
        Underling Count:   2
                1. Sarit
                2. Ampelio
        Manager:           Breeshey
        Underling Count:   0
        Manager:           Ferdinand
        Underling Count:   2
                1. Rosmunda
                2. Agata
        Manager:           Rosmunda
        Underling Count:   2
                1. Kim
                2. Breeshey
