# CS 200 Lab 04a: Pointers

---

[Information](#information) |
[Helper](https://github.com/Rachels-Courses/CS200-Concepts-of-Progamming-Algorithms/blob/2017-06-Summer/Assignments/In-class%20Labs/Lab%2004a%20-%20Pointers%20-%20Helper.md) |
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

Make sure to open up the [helper](https://github.com/Rachels-Courses/CS200-Concepts-of-Progamming-Algorithms/blob/2017-06-Summer/Assignments/In-class%20Labs/Lab%2004a%20-%20Pointers%20-%20Helper.md)
document


Begin with the following code:

```c++
#include <iostream>
#include <string>
using namespace std;

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

void Program5()
{
}

void Program6()
{
}

int main()
{
    bool done = false;
    while ( !done )
    {
        cout << "1. Run Program1" << endl;
        cout << "2. Run Program2" << endl;
        cout << "3. Run Program3" << endl;
        cout << "4. Run Program4" << endl;
        cout << "5. Run Program5" << endl;
        cout << "6. Run Program6" << endl;
        cout << "7. Exit" << endl;

        int choice;
        cin >> choice;

        switch( choice )
        {
            case 1:     Program1();     break;
            case 2:     Program2();     break;
            case 3:     Program3();     break;
            case 4:     Program4();     break;
            case 5:     Program5();     break;
            case 6:     Program6();     break;
            case 7:     done = true;     break;
        }
    }
    
    return 0;
}
```

# Program 1: Accessing addresses

Write a small program where you will create a series of variables, assign them values, 
then output the address of that variable *and* its value.

Variables to declare:

* An integer	```myInt```
* A float	```myFloat```
* A String	```myString```

<details>
<summary><strong>
	Outputting a variable's address
</strong></summary>

For any given variable, to output its address, use:

```c++
cout << &myVariable;
```

Make sure to open the [helper doc](https://github.com/Rachels-Courses/CS200-Concepts-of-Progamming-Algorithms/blob/2017-06-Summer/Assignments/In-class%20Labs/Lab%2004a%20-%20Pointers%20-%20Helper.md)
for help.

</details>

## Example output:

        Address 0x69fee8 = 20
        Address 0x69fee4 = 9.99
        Address 0x69fee0 = Bob

(Your memory addresses will be different)



---

# Program 2: Display addresses of array elements

Write a small program that will declare an array, initialize values for each element of the array, and then
displays the address of the array and the address of each element of the array.

Remember that, to output the address of an array, you do not use the address-of operator, you just cout
the array’s name.

For an element of the array, it is treated like a variable – so if you want to output the address of
element #0, you would have to add the & before the array and subscript.

Notice that the address of the array is the same address as the first element. This is not a coincidence!

## Steps

1. Declare an array of strings named ```schools```. Its size should be ```4```.

2. For each element of ```schools```, set values:
    * 0: JCCC
    * 1: UMKC
    * 2: KU
    * 3: MS&T

3. Display the address of ```schools``:
    * ```cout << schools << endl;``` - if you output an array's name, it will just give you the address of the array.

3. Create a **for loop** from ```i = 0``` to ```3```. Each time through the for loop:
    * Output the current value of ```i```
    * Output the address of element ```schools[i]``` using the address-of operator ```&```
    * Output the value of element ```schools[i]```

## Example output

        Array address: 0x69fec8
        Item 0 address: 0x69fec8        value: JCCC
        Item 1 address: 0x69fecc        value: UMKC
        Item 2 address: 0x69fed0        value: KU
        Item 3 address: 0x69fed4        value: MS&T

## Hints

<details>
<summary><strong>
	Declaring an array and outputting its address
</strong></summary>

```c++
string schools[4];

cout << "Array address: " << schools << endl;
```

</details>

<details>
<summary><strong>
	Displaying the address of an array element
</strong></summary>

```c++
cout << "Item 0 address: " << &schools[0] << endl;
```

</details></details>

<details>
<summary><strong>
	Displaying the value of an array element
</strong></summary>

```c++
cout << "Item 0 value: " << schools[0] << endl;
```

</details>

        
---

# Program 3: Using pointers

Update Exercise 1 (but save this as a separate function). Continue creating the int, string, 
and float variables, but also make
corresponding **pointer variables** that will point to each of their addresses. 
Then, cout the pointers, rather
than the addresses of the variables.

## Steps

**1.** Create the three variables:

* An integer	```myInt```
* A float	```myFloat```
* A string	```myString```

**2.** Create three pointers:

* An integer pointer ```ptrInt```
* A float pointer ```ptrFloat```
* A string pointer ```ptrString```

<details>
<summary><strong>
	Creating a pointer
</strong></summary>

```c++
int * ptrNumber;
```

</details>

**3.** Assign each pointer to the address of the corresponding variable

Use the address-of operator to assign the address from ```myInt``` to the ```ptrInt``` pointer,
and the same for ptrFloat and ptrString.

<details>
<summary><strong>
	Pointing to a variable's address
</strong></summary>

```c++
int number;
int * ptrNumber = &number;
```

</details>

**4.** Output the pointers to get the addresses

Using ```cout```, you can get the addresses via the pointers:

```c++
cout << ptrInt << endl;	// outputs address
```

<details>
<summary><strong>
	Displaying address and value
</strong></summary>

```c++
int number;
int * ptrNumber = &number;
cout << ptrNumber << endl;	// display address
cout << *ptrNumber << endl;	// display value
```

</details>


## Example output

        0x69fee8 = 20
        0x69fee4 = 9.99
        0x69fee0 = Bob









---

# Program 4: Sizes of data types

Write a program that will ask the user whether they want to see information about integers, floats,
booleans, or doubles.

In order to get the amount of bytes that a data type uses, use the ```sizeof()``` function.


## Steps

**1.** Ask the user if they want to see the size of integers, floats, booleans, or doubles.
Display a menu and get their selection. For example:

        [i]nt, [f]loat, [b]oolean, or [d]ouble?

**2.** Based on the user's response, use the ```sizeof``` function to display the size of that data type:


```c++
cout << sizeof( int ) << " bytes" << endl;
```

## Example output

        How many bytes is it?

        Choose one of the following data types:
        
        [i]nt, [f]loat, [b]oolean, or [d]ouble?

        >> i
        
        An integer size is: 4 bytes

---

# Program 5: Food

Write a program that will use a pointer to store the price of the current item

**1.** Create four float variables and give them initial values:

* priceHamburger
* priceFries
* priceSalad
* priceDefault = 0


**2. Create a pointer for the price of the current item**

Create a **float pointer** named ```ptrPrice```. Initialize it to ```nullptr```.

It is good programming practice to use **nullptr* as the value for pointers not currently being
used. Otherwise, like any other variable, their initial value is garbage.


**3.** Ask the user if they want a hamburger, fries, or salad.

For example:

	Do you want [h]amburger, [f]ries, or [s]alad?

Get their choice and store it in a string variable named ```choice```.

**4.** Use an if statement to check their selection. Based on their selection,
assign ```ptrPrice``` to the corresponding price.

If the user selects an invalid option, set ```ptrPrice``` to the address of ```priceDefault```.


**5.** Calculate the price plus tax

AFTER the if statement, create a float variable called ```taxRate``` and assign it to ```0.065```.

Also declare another float called ```taxAmount```, and a final one called ```pricePlusTax```.

Set ```taxAmount``` equal to the ```taxRate``` times the value pointed to by ```ptrPrice```.
You will need to de-reference ```ptrPrice``` to get its value.

<details><summary><strong> De-referencing a pointer </strong></summary>

```c++
*ptrPrice
```

</details>

Finally, assign ```pricePlusTax``` the value of ```ptrPrice``` plus the ```taxAmount```.


**6.** Display the results of the calculations

Display the **original price** (via ```ptrPrice```), **tax amount**, and **price plus tax** to the user.


## Example output

        [h]amburger, [f]ries, or [s]alad? h
        Original price: $3.99
	Tax amount: $0.25935
        With tax price: $4.24935


---

# Program 6: Students

**1.** Declare an array of **strings** named ```students```. The array should be of size 3.
Initialize this array with values for each element.

**2.** Create a string pointer named ```ptrStudent```. Initialize it to ```nullptr```.

**3.** Ask the user to enter a student ID: 0, 1, or 2. Store it in an integer named ```id```.

**4.** Assign ptrStudent the address of the student at this index (e.g., ```student[id]``` ’s address).

<details><summary><strong> Assigning a pointer to the address of an array element </strong></summary>

```c++
ptrStudent = &student[id];
```

</details>

**5.** Ask the user to enter a new name for the student.

Use the ```cin``` command, and store their selection directly to the appropriate element via the pointer.
(You will have to de-reference the pointer).

<details><summary><strong> Overwriting a value via a pointer </strong></summary>

```c++
cin >> *ptrStudent;
```

</details>

**6.** Display all the students with a for loop. Just display the elements of the array directly; you don't need to use a pointer here.


## Example output

        Enter 0, 1, or 2: 2
        New name: Wrex
        
        student 0 = Ashley
        student 1 = Kaidan
        student 2 = Wrex






![horizontal rule](images/hr.png)


# Questions

1. What is the "address-of" operator?
2. What is the "de-reference" operator?
3. How do you declare an integer-pointer variable?
4. How do you get the address of a variable whose name is ```myvar```?
5. How do you assign a pointer ```ptrVariable``` to the address of ```myvar```?
6. What requires more bytes, a float or a double?


