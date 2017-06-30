# CS 200 Lab 01b: Branching

---

[Information](#information) |
[Helper](https://github.com/Rachels-Courses/CS200-Concepts-of-Progamming-Algorithms/blob/2017-06-Summer/Assignments/In-class%20Labs/Lab%2001b%20-%20Branching%20-%20Helper.md) |
[Lab](#lab) |
[Questions](#questions)

---

## Information

### Lab topics

* Boolean Expressions
* Relational Operators
* If statements
* Switch statements

### Rules

* For **in-class labs**, collaboration is allowed.
    * If you work with another student on an assignment, make sure that you both
    turn in a copy of the work, and also mention in the D2L comments who you worked with.
    * You can also ask classmates questions if you're unsure on something.
    * You can ask the instructor for help at any time.

### Setting up a project in Visual Studio

1. Create a new project. *File > New > Project...*
    1. Select **Visual C++** from the left category list.
    2. Select **Empty Project** from the template list.
    3. Set the project **Name** to "Lab 01b Branching".
    4. Set the project **Location**.
    5. Click **OK**.
2. Create your source file. In the **Solution Explorer**, right-click your project file. *Add > New Item...*
    1. Select **C++ File (.cpp)** and name it **lab01b.cpp**.
    2. Click **Add**.

### Turn in

Once you are finished with a project, zip up the entire folder that contains
all source files and project/solution files. Turn in this zip file to **Desire2Learn**.

Also make sure to turn in a text file with your answers to the [question](#questions) section.
















![horizontal rule](images/hr.png)

# Lab

*This lab contains multiple different programs. Create *new projects* for each of these.*

## Program 1: Hometown

Write a program that will ask the user for their home town.

If the length of the home town's name is longer than 6 letters,
it will display a message "That's a long name!" - otherwise, it won't comment
before continuing on.

After that, it will ask for the user's name.

Finally, it will display "Hello, (NAME) from (LOCATION)"

Make sure to use ```cout``` to prompt the user for their input
prior to using ```cin```.

### Using strings

To use *string* variables in your program, you will
have to include the string library:

```c++
#include <string>   // use strings
```

To declare a string, use it as a data type:

```c++
string hometown;
```

You can use ```cin``` as normal, and store the result into ```hometown```.

```c++
cin >> hometown;
```

To get the length of a string (The # of letters), you can use:

```c++
hometown.size()
```

You can use this with your if statement, to see if ```hometown.size()``` is greater
than 6. The conditional will look like:

```c++
(hometown.size() > 6)
```

### Example output

Note: Using ```cin >>``` will only allow us to retrieve **single words** at a time from the user.
There is a different method to get a whole line of text from the user, which we will cover later on.
For now, keep your town names all one word, like ```kansascity```.

**Long town name:**

![When the town name is long, it displays "That's a long name!"](https://github.com/Rachels-Courses/CS200-Concepts-of-Progamming-Algorithms/blob/2017-06-Summer/Assignments/Archive/Labs/2017-01%20Spring/images/201701_lab4_program1.png?raw=true)

**Short town name:**

![No special message is displayed if the town name is short.](https://github.com/Rachels-Courses/CS200-Concepts-of-Progamming-Algorithms/blob/2017-06-Summer/Assignments/Archive/Labs/2017-01%20Spring/images/201701_lab4_program1b.png?raw=true)

#### Additional hints

Expand the following to get additional hints for this lab

<details>
	<summary><strong><em>
		View hints
	</em></strong></summary>

1. Create two string variables: **homeTown** and **name**.
2. Display a message: "What is your home town?"
3. Get the user's input, and store it in the **homeTown** variable.
    1. NOTE: If you're using **cin >>**, the home town name will have to be all one word!
4. Create an if statement. If the homeTown's name is longer than 6 letters, then:
    1. Display the message, "That's a long name!"
5. Display a message: "What is your name?"
6. Get the user's input, and store it in the **name** variable.
7. Finally, display the message: "Hello, (NAME) from (HOMETOWN)", by replacing (NAME) with **name**, and (HOMETOWN) with **homeTown**.
    
</details>

---

# Program 2: Pass/Fail

Write a program that will ask the user for their score on an assignment,
and the maximum points of the assignment.

It will check the ratio, and either display "Pass" or "Fail" based on whether
the assignment is 70% or higher (for pass), or less than 70% (for fail)

**Notes**

* The logical opposite of ( percent > 50 ) is ( percent <= 50 )
* The logical opposite of ( percent >= 50 ) is ( percent < 50 )
* Note the different relational operators!
* By utilizing **else**, we don't need to specify that failing is less than 70, 
    if we've already specified that passing is 70 or greater.

## Example output

**Pass:**

![A score of 70% or more passes](https://github.com/Rachels-Courses/CS200-Concepts-of-Progamming-Algorithms/blob/2017-06-Summer/Assignments/Archive/Labs/2017-01%20Spring/images/201701_lab4_program2.png?raw=true)

**Fail:**

![A score of 69% or below fails](https://github.com/Rachels-Courses/CS200-Concepts-of-Progamming-Algorithms/blob/2017-06-Summer/Assignments/Archive/Labs/2017-01%20Spring/images/201701_lab4_program2b.png?raw=true)

## Additional hints

<details>
	<summary><strong><em>
		View hints
	</em></strong></summary>

1. Create two float variables: **studentPoints** and **totalPoints**.
2. Ask the user to enter their score. Store their score in the **studentPoints** variable.
3. Ask the user to enter the total points. Store the total points in the **totalPoints** variable.
4. Create another float variable called **percent**. Assign it to **( studentPoints / totalPoints ) * 100**.
5. Display the score, displaying the **percent** variable.
6. Create an if statement. If **percent** is greater than or equal to 70%, display "Pass".
7. Otherwise, display "Fail".
    
</details>


---

# Program 3: Battery charge

Write a program that will ask the user to enter the amount of charge of their phone battery. Then, draw a picture for an estimate of whether it's 1/4 charge, 1/2 charge, 3/4 charge, or full charge.

* Full charge:  ```[****]```
* 3/4th charge: ```[*** ]```
* 1/2 charge:   ```[**  ]```
* 1/4th charge: ```[*   ]```

## Example output

Note that this % here is just because I output the prompt like this:

```c++
cout << "What is your current battery charge? %";
cin >> charge;
```

**Full charge:**

![Screenshot with full charge](https://github.com/Rachels-Courses/CS200-Concepts-of-Progamming-Algorithms/blob/2017-06-Summer/Assignments/Archive/Labs/2017-01%20Spring/images/201701_lab4_program3a.png?raw=true)

**3/4ths charge:**

![Screenshot with 3/4 charge](https://github.com/Rachels-Courses/CS200-Concepts-of-Progamming-Algorithms/blob/2017-06-Summer/Assignments/Archive/Labs/2017-01%20Spring/images/201701_lab4_program3b.png?raw=true)

**1/2 charge:**

![Screenshot with 1/2 charge](https://github.com/Rachels-Courses/CS200-Concepts-of-Progamming-Algorithms/blob/2017-06-Summer/Assignments/Archive/Labs/2017-01%20Spring/images/201701_lab4_program3c.png?raw=true)

**1/4th charge:**

![Screenshot with 1/4 charge](https://github.com/Rachels-Courses/CS200-Concepts-of-Progamming-Algorithms/blob/2017-06-Summer/Assignments/Archive/Labs/2017-01%20Spring/images/201701_lab4_program3d.png?raw=true)

## Additional hints

<details>
	<summary><strong><em>
		View hints
	</em></strong></summary>

1. Create a float variable called **battery**.
2. Ask the user what their current battery charge is. Store their response in **battery**.
3. If battery is 75% or greater, display the drawing: ```[****]```
3. If battery is 50% or greater, display the drawing: ```[*** ]```
3. If battery is 25% or greater, display the drawing: ```[**  ]```
3. Otherwise, display the drawing: ```[*   ]```

    
</details>

---

# Program 4: Input validation

Write a program that displays a list of fruits and asks the user to choose one. If the user selects an invalid input, display an error message. Otherwise, display "good choice!"

* Logical operators:
    * And: ```&&```
    * Or: ```||```
    * Not: ```!```

## Example output

**Valid input:**

![Valid input screenshot](https://github.com/Rachels-Courses/CS200-Concepts-of-Progamming-Algorithms/blob/2017-06-Summer/Assignments/Archive/Labs/2017-01%20Spring/images/201701_lab4_program4a.png?raw=true)

**Invalid input 1:**

![Invalid input screenshot](https://github.com/Rachels-Courses/CS200-Concepts-of-Progamming-Algorithms/blob/2017-06-Summer/Assignments/Archive/Labs/2017-01%20Spring/images/201701_lab4_program4b.png?raw=true)

**Invalid input 2:**

![Invalid input screenshot](https://github.com/Rachels-Courses/CS200-Concepts-of-Progamming-Algorithms/blob/2017-06-Summer/Assignments/Archive/Labs/2017-01%20Spring/images/201701_lab4_program4c.png?raw=true)

## Additional hints

<details>
	<summary><strong><em>
		View hints
	</em></strong></summary>

* Display the following menu:

    ```
    What is your favorite fruit?
    1. Apple
    2. Banana
    3. Pear
    4. Strawberry
    ```
    
* Create an integer variable called **choice**.
* Get the user's selection and store it in **choice**.
* If the user's selection is invalid (their choice is less than 1, or it is greater than 4), display an error message, "Invalid choice!"
* Otherwise, display "Good choice!"

</details>

---

# Program 5: Switch statements

Write a program that asks the user to enter two numbers. Then, ask them whether they want to add, subtract, multiply, or divide.

Use a switch statement to decide what kind of operation to do, and display the result.

## Steps

1. Create two float variables: **a** and **b**.
2. Ask the user to enter a value for a, and store it in the **a** variable.
2. Ask the user to enter a value for b, and store it in the **b** variable.
3. Display a menu for the user to select what kind of operation:
    * 1. Add
    * 2. Subtract
    * 3. Multiply
    * 4. Divide
4. Ask the user for their selection.
5. Create a new variable, an integer called **choice**. Store the user's selection in this variable.
6. Use a switch statement to check the value of **choice**.
    * If choice is 1, show the result of a + b.
    * If choice is 2, show the result of a - b.
    * If choice is 3, show the result of a * b.
    * If choice is 4, show the result of a / b.
    * Otherwise, display an error: "Invalid choice."

## Example output

**Add:**

![Add screenshot](https://github.com/Rachels-Courses/CS200-Concepts-of-Progamming-Algorithms/blob/2017-06-Summer/Assignments/Archive/Labs/2017-01%20Spring/images/201701_lab4_program6a.png?raw=true)

**Subtract:**

![Subtract screenshot](https://github.com/Rachels-Courses/CS200-Concepts-of-Progamming-Algorithms/blob/2017-06-Summer/Assignments/Archive/Labs/2017-01%20Spring/images/201701_lab4_program6b.png?raw=true)


**Multiply:**

![Multiply screenshot](https://github.com/Rachels-Courses/CS200-Concepts-of-Progamming-Algorithms/blob/2017-06-Summer/Assignments/Archive/Labs/2017-01%20Spring/images/201701_lab4_program6c.png?raw=true)


**Divide:**

![Divide screenshot](https://github.com/Rachels-Courses/CS200-Concepts-of-Progamming-Algorithms/blob/2017-06-Summer/Assignments/Archive/Labs/2017-01%20Spring/images/201701_lab4_program6d.png?raw=true)


**Invalid:**

![Invalid screenshot](https://github.com/Rachels-Courses/CS200-Concepts-of-Progamming-Algorithms/blob/2017-06-Summer/Assignments/Archive/Labs/2017-01%20Spring/images/201701_lab4_program6e.png?raw=true)






![horizontal rule](images/hr.png)

# Questions

Use the [Introduction](#introduction) portion of this document to help answer these problems.

*Answer these questions in a text editor and turn them in with your project.
Valid file formats are: .txt, .rtf, .docx, .odt, .pdf*

## A. Operators

"Translate" the following questions into boolean expressions, using variables and operators.

A-1. Is **age** less than 13?

A-2. Does **name1** and **name2** have the same value?

A-3. Does **word1** come before **word2** in the dictionary? *(Hint: The computer considers 'a' to be less than 'b')*

A-4. Is **age** less than 21, and is **age** also greater than 18?

A-5. Is **x** between 5 and 10? *(Hint: You need to phrase this as two separate boolean expressions and combine them with a logical operator!)*

---

## B. Boolean expressions

Figure out whether the following expressions will evaluate to **true** or **false**,
given the variable's value. Simply answer "true" or "false".

B-1. ```( isDone )```, isDone is true.

B-2. ```( !isDone )```, isDone is true.

B-3. ```( age >= 18 && age < 21 )```, age is 20.

B-4. ```( x > 0 && x < 10 )```, x is 0.

B-5. ```( color != "green" )```, color is "cyan".

---

## C. Coin flip

Suppose that we’re tossing coins and recording the result as a boolean.
Therefore, when we flip a coin, if it lands on heads, then ```pennyHeads = true```, 
and if it lands on tails, then ```pennyHeads = false```.

C-1. We are just tossing one penny. List out all possible outcomes. How many total outcomes are there?

C-2. We are tossing one penny and one dime.
The variables will be ```pennyHeads``` and ```dimeHeads```.
List out all possible outcomes. How many total outcomes are there?

C-3. We are tossing one penny, one dime, and one nickel.
The variables will be ```pennyHeads```, ```dimeHeads```, and ```nickelHeads```.
List all possible outcomes. How many total outcomes are there?

C-4. Given the following boolean expression, there is only one way to get a value of true. What do the values of each of the variables need to be?

```( pennyHeads && dimeHeads && nickelHeads )```

* ```pennyHeads =```
* ```dimeHeads =```
* ```nickelHeads =```

C-5. Given the same boolean expression, there are seven different ways that the result can
be **false**. List four combinations.

```( pennyHeads && dimeHeads && nickelHeads )```

* Combination 1
    * ```pennyHeads =```
    * ```dimeHeads =```
    * ```nickelHeads =```
* Combination 2
    * ```pennyHeads =```
    * ```dimeHeads =```
    * ```nickelHeads =```
* Combination 3
    * ```pennyHeads =```
    * ```dimeHeads =```
    * ```nickelHeads =```
* Combination 4
    * ```pennyHeads =```
    * ```dimeHeads =```
    * ```nickelHeads =```

C-6: Given the following boolean expression, there are three ways we can get a result of true. List them all.

```( pennyHeads || dimeHeads )```

* Combination 1
    * ```pennyHeads =```
    * ```dimeHeads =```
* Combination 2
    * ```pennyHeads =```
    * ```dimeHeads =```
* Combination 3
    * ```pennyHeads =```
    * ```dimeHeads =```

C-7: With the same boolean expression, there is only one way to get a result of **false**. What do the variables need to be?

* ```pennyHeads =```
* ```dimeHeads =```
