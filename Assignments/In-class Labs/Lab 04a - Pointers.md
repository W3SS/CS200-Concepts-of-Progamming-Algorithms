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

* [Creating a new project in Visual Studio](https://github.com/Rachels-Courses/Course-Common-Files/blob/master/Visual-Studio/New%20project%20howto.md)

## Turn in

Once you are finished with a project, zip up the entire folder that contains
all source files and project/solution files. Turn in this zip file to **Desire2Learn**.

Also make sure to turn in a text file with your answers to the [question](#questions) section.







![horizontal rule](images/hr.png)

---

# Lab

Make sure to open up the [helper](https://github.com/Rachels-Courses/CS200-Concepts-of-Progamming-Algorithms/blob/2017-06-Summer/Assignments/In-class%20Labs/Lab%2004a%20-%20Pointers%20-%20Helper.md)
document

## Program 1: Accessing addresses

Write a small program where you will create a series of variables, assign them values, 
then output the address of that variable *and* its value.

Variables to declare:

* An integer
* A float
* A String

**Sample Output:**

        Address 0x69fee8 = 20
        Address 0x69fee4 = 9.99
        Address 0x69fee0 = Bob

(Your memory addresses will be different)



### Hints

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

---

## Program 2: Display addresses of array elements

Write a small program that will declare an array, initialize values for each element of the array, and then
displays the address of the array and the address of each element of the array.

Remember that, to output the address of an array, you do not use the address-of operator, you just cout
the array’s name.

For an element of the array, it is treated like a variable – so if you want to output the address of
element #0, you would have to add the & before the array and subscript.

Notice that the address of the array is the same address as the first element. This is not a coincidence!

**Sample Output:**

        Array address: 0x69fec8
        Item 0 address: 0x69fec8        value: JCCC
        Item 1 address: 0x69fecc        value: UMKC
        Item 2 address: 0x69fed0        value: KU
        Item 3 address: 0x69fed4        value: MS&T

### Hints

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

</details>

        
---

## Program 3: Using pointers

Update Exercise 1 (but save this as a separate file or function). Continue creating the int, string, 
and float variables, but also make
corresponding **pointer variables** that will point to each of their addresses. 
Then, cout the pointers, rather
than the addresses of the variables.

**Sample Output:**

        0x69fee8 = 20
        0x69fee4 = 9.99
        0x69fee0 = Bob

<details>
<summary><strong>
	Creating a pointer
</strong></summary>

```c++
int * ptrNumber;
```

</details>


<details>
<summary><strong>
	Pointing to a variable's address
</strong></summary>

```c++
int number;
int * ptrNumber = &number;
```

</details>


<details>
<summary><strong>
	Displaying an address via a pointer
</strong></summary>

```c++
int number;
int * ptrNumber = &number;
cout << ptrNumber << endl;
```

</details>

---

## Program 4: Sizes of data types

Write a program that will ask the user whether they want to see information about integers, floats,
booleans, or doubles.

In order to get the amount of bytes that a data type uses, use the ```sizeof()``` function.
For example:

```c++
cout << sizeof( int ) << " bytes" << endl;
```


**Sample Output:**

        How many bytes is it?

        Choose one of the following data types:
        
        [i]nt, [f]loat, [b]oolean, or [d]ouble?

        >> i
        
        An integer size is: 4 bytes

---

## Program 5: Food

Write a program that has 3 float variables:

* priceHamburger
* priceFries
* priceSalad

Assign some prices to each of these variables.

Create a variable that is a float pointer, called ptrPrice. Start by assigning it to **nullptr**.



It is good programming practice to use **nullptr* as the value for pointers not currently being
used. Otherwise, like any other variable, their initial value is garbage.



Ask the user whether they want a hamburger, fries, or a salad. Based on what their answer is, assign
ptrPrice the address of the corresponding price variable (priceHamburger, priceFries, or priceSalad).

Create another float called taxAmt. Figure out the tax by multiplying the value of ptrPrice by 0.065.
Then, increase the price by the tax amount by adding the taxAmt to the value of ptrPrice.

Finally, output the price-plus-tax, by outputting the value of ptrPrice.

**Sample Output:**

        [h]amburger, [f]ries, or [s]alad? h
        Original price: $3.99
        With tax price: $4.24935

### hints

<details>
<summary><strong>
	Declare a pointer and set it to nullptr
</strong></summary>

```c++
float * ptrPrice = nullptr;
```

</details>

<details>
<summary><strong>
	Assign the pointer to point at a price
</strong></summary>

```c++
ptrPrice = &priceHamburger;
```

</details>

<details>
<summary><strong>
	Calculate price plus tax using the pointer
</strong></summary>

```c++
float taxAmt = ( *ptrPrice * 0.065 ) + *ptrPrice;
```

</details>

<details>
<summary><strong>
	Display the price of the current item via the pointer
</strong></summary>

```c++
cout << *ptrPrice << endl;
```

</details>

---

## Program 6: Students

Write a program that has an array of strings, called students. The array should be of size 3. Assign
some values to these array elements.

Then, create a variable that is a string pointer, called ptrStudent.

Ask the user to enter an index: 0, 1, or 2. Assign ptrStudent the address of the student at this index
(e.g., ```student[1]``` ’s address).

Then, ask the user to enter a new name for the student. Use cin and store the result to the appropriate
element through the ptrStudent pointer – use the de-reference operator to assign a value to this item.

Finally, display the name of all students with a for-loop.


**Sample Output:**

        Enter 0, 1, or 2: 2
        New name: Wrex
        
        student 0 = Ashley
        student 1 = Kaidan
        student 2 = Wrex

### Hints

<details>
<summary><strong>
	Creating the array
</strong></summary>

```c++
string students[3] = { "Harry", "Ron", "Hermione" };
```

or

```c++
string students[3];
students[0] = "Harry";
students[1] = "Ron";
students[2] = "Hermione";
```

</details>


<details>
<summary><strong>
	Assign a pointer to an element of the array
</strong></summary>

```c++
string * ptrStudent = &students[0];
```

</details>


<details>
<summary><strong>
	Using cin with a pointer
</strong></summary>

```c++
cin >> *ptrStudent;
```

</details>


<details>
<summary><strong>
	Displaying all elements of the array
</strong></summary>

```c++
for ( int i = 0; i < 3; i++ )
{
        cout << "student " << i << " = " << students[i] << endl;
}
```

</details>







![horizontal rule](images/hr.png)


# Questions

1. What is the "address-of" operator?
2. What is the "de-reference" operator?
3. How do you declare an integer-pointer variable?
4. How do you get the address of a variable whose name is ```myvar```?
5. How do you assign a pointer ```ptrVariable``` to the address of ```myvar```?
6. What requires more bytes, a float or a double?


