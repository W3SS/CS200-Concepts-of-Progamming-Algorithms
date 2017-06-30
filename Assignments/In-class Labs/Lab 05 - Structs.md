# CS 200 Lab 05: Structs

---

[Information](#information) |
[Helper]() |
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

* [Creating a new project in Visual Studio](https://github.com/Rachels-Courses/Course-Common-Files/blob/master/Visual-Studio/New%20project%20howto.md)

## Turn in

Once you are finished with a project, zip up the entire folder that contains
all source files and project/solution files. Turn in this zip file to **Desire2Learn**.

Also make sure to turn in a text file with your answers to the [question](#questions) section.







![horizontal rule](images/hr.png)

---

# Lab

## Program 1: Dynamic variables and arrays

### Part 1: Variables

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


### Part 2: Arrays

Next, create three additional pointer variables:

* myIntArr, an integer pointer.
* myStrArr, a string pointer.
* myFloatArr, a float pointer.

Also create an integer variable named **size**.

Ask the use how big the arrays should be, and store their response in **size**.

For each of these "my____Arr" pointers, create a new **dynamic array** and
initialize its size to the value stored in the **size** variable.

Use a for-loop to iterate from *0* to *size*, asking the user to enter
a value for each element of myIntArr, myFloatArr, and myStrArr.

After they enter values for these, display them back.

Finally, after the for loop is finished, make sure to free the memory of all your dynamic arrays.

**Sample Output:**

        Enter array size:       3

        i = 0
                Enter int value:        2
                Enter string value:     cheese
                Enter float value       2.10

        i = 1
                Enter int value:        5
                Enter string value:     horse
                Enter float value:      9.92
                
        i = 2
                Enter int value:        1
                Enter string value:     cow
                Enter float value:      10.2

        Here is your data:

        2       cheese          2.10
        5       horse           9.92
        1       cow             10.2

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









![horizontal rule](images/hr.png)


# Questions

1. Using a pointer, how do you allocate memory for a new dynamic variable?
1. Using a pointer, how do you allocate memory for a new dynamic array?
1. How do you deallocate memory for a dynamic variable?
1. How do you deallocate memory for a dynamic array?

