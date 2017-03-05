# CS 200 Lab 14: Dynamic variables and arrays

## Chrome!

Please read this in chrome so that the solutions are collapsed by default!

## Topics

* Pointers
* Memory management

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

# Dynamic Variables

We can create new variables and arrays dynamically. With arrays, we no longer need to
know the size of the array at compile-time, but we can decide that at run-time. For
example, we could ask the user for the amount of items, and then create an array of that
size.

To create dynamic variables and arrays, we need to use pointers. Remember that a
pointer points to a memory address. By using the **new** keyword, we can allocate memory
through a pointer – it will point to a new address, and have that memory address
prepared for whatever we've created.

But, unlike our normal variables, dynamic variables do not free their memory
automatically. This means, we have to manually free that memory with the delete
keyword. So, a good practice to start with is, any time we write a **new** keyword, we also
need a **delete** somewhere.

If you don't free your allocated memory, you will get a memory leak. If your program
allocates a lot of memory and never frees it, it will eat up RAM and cause system
problems – you can't get that memory back until the user resets their computer.

## Dynamic Variable Reference

Here are the steps to creating a new dynamic variable:

<table>
        <tr>
                <th>Code</th>
                <th>Description</th>
        </tr>
        
        <tr>
                <td><pre>
string* dynamicString;
                </pre></td>
                
                <td>
                Create a pointer variable.
                </td>
        </tr>
        
        <tr>
                <td><pre>
dynamicString = new string;
                </pre></td>
                
                <td>
                Create a new string with the pointer.
                </td>
        </tr>
        
        <tr>
                <td><pre>
*dynamicString = "Hello!";
                </pre></td>
                
                <td>
                        Assign a value to our new variable.
                        (must go through the pointer – use the
                        de-reference operator)
                </td>
        </tr>
        
        <tr>
                <td><pre>
cout << *dynamicString << endl;
                </pre></td>
                
                <td>
                        Display the value of the variable.
                </td>
        </tr>
        
        <tr>
                <td><pre>
delete dynamicString;
                </pre></td>
                
                <td>
                        Free up the memory when done.
                </td>
        </tr>
</table>

---

## Exercise 1

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

---

## Exercise 2

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

# Dynamic Arrays

The **new** and **delete** keywords can be used to make arrays, too. With dynamic arrays,
you don't need to estimate the size of an array – which wastes memory, and could have
problems if you run out of array space!

You also create dynamic arrays through pointers. Remember that you will still need to
delete whatever you create with new!

## Dynamic Array Reference


<table>
        <tr>
                <th>Code</th>
                <th>Description</th>
        </tr>
        
        <tr>
                <td><pre>
float* prices;
                </pre></td>
                
                <td>
                Create a pointer variable.
                </td>
        </tr>
        
        <tr>
                <td><pre>
prices = new float[ 5 ];
                </pre></td>
                
                <td>
                Allocate memory as an array.
                </td>
        </tr>
        
        <tr>
                <td><pre>
for ( int i = 0; i < 5; i++ )
{
        prices[i] = i * 2;
        cout << prices[i] << endl;
}
                </pre></td>
                
                <td>
                Assign values and display the values.
                </td>
        </tr>
        
        <tr>
                <td><pre>
delete [] prices;
                </pre></td>
                
                <td>
                Free the memory up afterward.
                </td>
        </tr>
</table>

Note that with dynamic arrays, you don't need to use the de-reference operator when
accessing elements of the array – just treat it like a normal array!

You can also set a dynamic array's size based on a variable value:

        int size;
        cout << "Size: ";
        cin >> size;
        
        float* prices;
        prices = new float[ size ];
        // ...
        
        delete [] prices;

So they are very useful for all sorts of applications!

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
