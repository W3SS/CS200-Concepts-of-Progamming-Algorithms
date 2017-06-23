# CS 200 Lab 04a: Pointers

---

[Information](#information) |
[Helper]() |
[Lab](#lab) | [
Questions](#questions)

---

# Information

## Lab topics

* Functions

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





![horizontal rule](images/hr.png)

---

# Lab

## Program 1: Accessing addresses

Write a small program where you will create a series of variables, assign them values, 
then output the address of that variable *and* its value. Use the address-of operator &.

Variables to declare:

* An integer
* A float
* A String

**Sample Output:**

        0x69fee8 = 20
        0x69fee4 = 9.99
        0x69fee0 = Bob

(Your memory addresses will be different)


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


        
---

## Program 3: Using pointers

Update Exercise 1 (but save this as a separate file or function). Continue creating the int, string, 
and float variables, but also make
corresponding pointer variables that will point to each of their addresses. 
Then, cout the pointers, rather
than the addresses of the variables.

**Sample Output:**

        0x69fee8 = 20
        0x69fee4 = 9.99
        0x69fee0 = Bob

---

## Program 4: Sizes of data types

Write a program that will ask the user whether they want to see information about integers, floats,
booleans, or doubles.

Whichever data-type the user selects:

1. Create a variable of that type.
2. Create a pointer and assign it the address of that variable.
3. Output the size of the variable using the **sizeof(...)** function.
4. Output the address of the variable by outputting the pointer (no address-of operator).

You can pass any variable name into the sizeof function to get its size. For example:


<table>
<tr><th>C++</th><th>Output</th></tr>

<tr><td>
<pre>
char choice;
cout << sizeof( choice ) << endl;
</pre>
</td></tr>

<tr><td>
<pre>
1
</pre>
</td></tr>
</table>

**Sample Output:**

        [i]nt, [f]loat, [b]oolean, or [d]ouble? i
        Integer size: 4, address: 0x69fee8

---

## Program 5: Food

Write a program that has 3 float variables, named priceHamburger, priceFries, priceSalad.
Assign some prices to each of these variables.

Create a variable that is a float pointer, called ptrPrice. Do not assign it to anything initially.

Ask the user whether they want a hamburger, fries, or a salad. Based on what their answer is, assign
ptrPrice the address of the corresponding price variable (priceHamburger, priceFries, or priceSalad).

Create another float called taxAmt. Figure out the tax by multiplying the value of ptrPrice by 0.065.
Then, increase the price by the tax amount by adding the taxAmt to the value of ptrPrice.

Finally, output the price-plus-tax, by outputting the value of ptrPrice.

**Sample Output:**

        [h]amburger, [f]ries, or [s]alad? h
        Original price: $3.99
        With tax price: $4.24935

---

## Program 6: Students

Write a program that has an array of strings, called students. The array should be of size 3. Assign
some values to these array elements.

Then, create a variable that is a string pointer, called ptrStudent.

Ask the user to enter an index: 0, 1, or 2. Assign ptrStudent the address of the student at this index
(e.g., student[1]’s address).

Then, ask the user to enter a new name for the student. Use cin and store the result to the appropriate
element through the ptrStudent pointer – use the de-reference operator to assign a value to this item.

Finally, display the name of all students with a for-loop:

```c++
for ( int i = 0; i < 3; i++ )
{
        cout << "student " << i << " = " << students[i] << endl;
}
```

**Sample Output:**

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


