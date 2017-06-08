# CS 200 Lab 01b: Branching

---

[Information](#information) | [Introduction](#introduction) | [Lab](#lab) | [Questions](#questions)

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
    3. Set the project **Name** to "CL2 Branching".
    4. Set the project **Location**.
    5. Click **OK**.
2. Create your source file. In the **Solution Explorer**, right-click your project file. *Add > New Item...*
    1. Select **C++ File (.cpp)** and name it **CL2.cpp**.
    2. Click **Add**.

### Turn in

Once you are finished with a project, zip up the entire folder that contains
all source files and project/solution files. Turn in this zip file to **Desire2Learn**.

Also make sure to turn in a text file with your answers to the [question](#questions) section.












![horizontal rule](images/hr.png)

## Introduction

### Relational operators and logic operators

Programming is all about manipulating data. Some of the main functionality we will be dealing with include:

*    Comparing if two values are equal
*    Comparing if two values are not equal
*    Comparing if one value is larger than another value

Programs are essentially a series of "yes/no" questions because, again, computers only understand binary: Yes or no, 1 or 0, true or false. Any question we ask, like "is A and B equal?" or "is A equal to 20?" result in a boolean value -- either true or false.

Our program logic will consist of branches and loops, and the program decides whether to branch or loop based on these "yes/no" questions...

*    If height is greater than 4 ft, allow on the roller coaster...
*    If customer wants beer AND the customer's age is 21 or greater, then serve beer...
*    While the countdown is greater than 0, go down by 1...
*    While the user has not selected "exit", keep running the program...
*    While the user's choice is less than (minimum) AND the user's choice is greater than (maximum), display an error message...

To ask these questions, we will utilize relational operators: 

<table class="table">
<thead>
<tr>
<th>Name</th>
<th>Operator</th>
<th>Question</th>
<th>Example</th>
</tr>
</thead>

<tbody>
<tr>
<td>
Less than
</td>
<td>
&lt;
</td>
<td>
Is A less than B?
</td><td><pre>A &lt; B</pre>
</td>
</tr>

<tr>
<td>
Less than or equal to
</td>
<td>
&lt;=
</td>
<td>
Is A less than, or equal to, B?
</td><td><pre>A &lt;= B</pre>
</td>
</tr>
<tr>
<td>
Greater than
</td>
<td>
&gt;
</td>
<td>
Is A greater than B?
</td><td><pre>A &gt; B</pre>
</td>
</tr>

<tr>
<td>
Greater than or equal to
</td>
<td>
&gt;=
</td>
<td>
Is A greater than, or equal to, B?
</td><td><pre>A &gt;= B</pre>
</td>
</tr>

<tr>
<td>
Equal
</td>
<td>
==
</td>
<td>
Is A equal to B?
</td><td><pre>A == B</pre>
</td>
</tr>

<tr>
<td>
Not equal to
</td>
<td>
!=
</td>
<td>
Is A and B not equal?
</td><td><pre>A != B</pre>
</td>
</tr>

</tbody>

</table>

**Common error! == vs =:**  Make sure to notice that the operator for "is equal?" is TWO equal signs: ==.
A common programming error (and hard to see when trying to look for the error!) is to use a single equals sign = instead of two == within your statements that ask if two things are equal.

Remember this rhyme: To compare if two things are equal, your equal-sign needs a sequel!

Remedy: Be extra mindful when writing conditionals that compare if two things are equal!



When we want to string together multiple questions in one statement,
we may use these **logic operators**:

<table>
<tr>
<th>Name</th><th>Operator</th>
</tr>
<tr><td> And </td><td> && </td></tr>
<tr><td> Or </td><td> || </td></tr>
<tr><td> Not </td><td> ! </td></tr>
</table>

---

### Boolean Expressions

Boolean Expressions are statements that result in either **true** or **false**.
These can be questions like “Is x less than 10?”, or “Is the printer on?”,
or “Is age between 18 and 21?”.

Boolean expression are what if statements and while loops operate on
in order to figure out whether to execute their internal code blocks!

A boolean expression can be created from a simple boolean variable:

```c++
bool savedDocument = true;
if ( savedDocument ) { ... }
```

Or from an expression using relational operators:

```c++
if ( score != 100 ) { ... }
if ( score > 69 ) { ... }
```

And we can combine multiple boolean expressions together using logical operators:

```c++
if ( name == "admin" || name == "administrator" ) { ... }
```

---

### If statements

If statements are one way we can "branch" the flow of our program by
asking questions. Usually these questions are things like,
"Is the printer ready?", "Is balance greater than 0?", "Is locationA
the same as locationB?" and so on.

If statements are built like this:

```c++
if ( CONDITION )
{
    // This executes if true
}
```


#### Solo if statement

With an if statement on its own, the code within the statement's
**code block** (code within curly braces ```{ }```) is only executed
if our **condition** is **true**. Once we're done with the code within
the if statement code-block, we exit the code block and return to the
normal execution of the program.

If the condition ended up being *false*, then we skip that internal code block
and continue on with the program.

**Example:**

```c++
string order = "burger";

string addCheese;
cout << "Do you want cheese on that? (yes/no): ";
cin >> addCheese;

if ( addCheese == "yes" )
{
    order += " with cheese";
}

cout << "Your order: " << order << endl;
```

For this code, the order is displayed either way - whether the user
wants cheese or not. However, if they want cheese, *only then* is
the "with cheese" added onto the order.

So...

With cheese output: ```Your order: burger with cheese```

Without cheese output: ```Your order: burger```



#### If / else statements

With an if/else statement, the *if* code block is executed when the
condition is *true*, and the *else* code block is executed when the
condition is *false*.

```c++
if ( CONDITION )
{
    // Condition was true!
}
else
{
    // Condition was false!
}
```

This way, both options have their own special code associated with it,
and after that internal block is executed, the program continues its flow.

```c++
float price;
bool haveCoupon = false;

if ( haveCoupon )
{
    price = 5.99;
}
else
{
    price = 7.99;
}

cout << "Price: $" << price << endl;
```


**Common error:** Note that the *else* statement doesn't have a conditional!
The else is a catch-all that will be executed if no other if (or else-if) statements
were true.




#### If / else if / else statements

Perhaps there are several scenarios that you want to check for.
Instead of having multiple *if* statements, you can add any amount of
*else if* statements to cover more options.

```c++
if ( CONDITION_A )
{
    // Condition A is true
}
else if ( CONDITION_B )
{
    // Condition B is true, but Condition A was false
}
else if ( CONDITION_C )
{
    // Condition C is true, but Condition A and Condition B were false
}
else
{
    // Default if none of the above was true
}
```

Note that when we have else if statements, those *else if* statements are
only executed if the **if or else if statement above it was false!**.

```c++
float price;
int age;
cout << "Enter your age: ";
cin >> age;

if ( age < 12 )
{
    // Kid price
    price = 5.00;
}
else if ( age < 18 )
{
    // Teen price
    price = 6.00;
}
else if ( age >= 60 )
{
    // Senior price
    price = 4.00;
}
else
{
    // Normal price
    price = 8.00;
}

cout << "Price: $" << price << endl;
```

In this case, if the user entered 14 as their age, the first if statement,
```if ( age < 12 )``` is false, so it goes to the next *else if* statement.
This one ends up being true, so ```price = 6.00;``` is executed. It doesn't
matter that this condition didn't ask if ```age >= 12```, because we already
know this is true, since ```age < 12``` failed.



---

### Switch statements

A switch statement does not use a boolean expression - instead,
it can operate on **integers**, **characters**, and **booleans**.

Each **case** in a switch statement is essentially asking, "is the value of the switch variable this?",
and the lines of code after the case statement are what gets executed.

The case statement ends at a **break** statement.

The **default** case is used like an "else".

Example:

```c++
switch( letter )
{
    case 'a':
        cout << "ABC!" << endl;
    break;
    
    case 'z':
        cout << "XYZ!" << endl;
    break;
    
    
    default:
        cout << "I don't like that letter." << endl;
}
```







![horizontal rule](images/hr.png)

## Lab

*This lab contains multiple different programs. Create *new projects* for each of these.*

### Program 1: Hometown

Write a program that will ask the user for their home town.

If the length of the home town's name is longer than 6 letters,
it will display a message "That's a long name!" - otherwise, it won't comment
before continuing on.

After that, it will ask for the user's name.

Finally, it will display "Hello, (NAME) from (LOCATION)"

Make sure to use ```cout``` to prompt the user for their input
prior to using ```cin```.

#### Using strings

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

To get the length of a string (The # of letters), you can use:

```c++
hometown.size()
```

You can use this with your if statement, to see if ```hometown.size()``` is greater
than 6.

#### Example output

**Long town name:**

![When the town name is long, it displays "That's a long name!"](https://github.com/Rachels-Courses/CS200-Concepts-of-Progamming-Algorithms/raw/2017-06-Summer/Assignments/In-class%20Labs/2017-01%20Spring/images/201701_lab4_program1.png)

**Short town name:**

![No special message is displayed if the town name is short.](https://github.com/Rachels-Courses/CS200-Concepts-of-Progamming-Algorithms/raw/2017-06-Summer/Assignments/In-class%20Labs/2017-01%20Spring/images/201701_lab4_program1b.png)

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

### Program 2: Pass/Fail

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

#### Example output

**Pass:**

![A score of 70% or more passes](https://github.com/Rachels-Courses/CS200-Concepts-of-Progamming-Algorithms/raw/2017-06-Summer/Assignments/In-class%20Labs/2017-01%20Spring/images/201701_lab4_program2.png)

**Fail:**

![A score of 69% or below fails](https://github.com/Rachels-Courses/CS200-Concepts-of-Progamming-Algorithms/raw/2017-06-Summer/Assignments/In-class%20Labs/2017-01%20Spring/images/201701_lab4_program2b.png)

#### Additional hints

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

### Program 3: Battery charge

Write a program that will ask the user to enter the amount of charge of their phone battery. Then, draw a picture for an estimate of whether it's 1/4 charge, 1/2 charge, 3/4 charge, or full charge.

* Full charge:  ```[****]```
* 3/4th charge: ```[*** ]```
* 1/2 charge:   ```[**  ]```
* 1/4th charge: ```[*   ]```

#### Example output

Note that this % here is just because I output the prompt like this:

```c++
cout << "What is your current battery charge? %";
cin >> charge;
```

**Full charge:**

![Screenshot with full charge](https://github.com/Rachels-Courses/CS200-Concepts-of-Progamming-Algorithms/raw/2017-06-Summer/Assignments/In-class%20Labs/2017-01%20Spring/images/201701_lab4_program3a.png)

**3/4ths charge:**

![Screenshot with 3/4 charge](https://github.com/Rachels-Courses/CS200-Concepts-of-Progamming-Algorithms/raw/2017-06-Summer/Assignments/In-class%20Labs/2017-01%20Spring/images/201701_lab4_program3b.png)

**1/2 charge:**

![Screenshot with 1/2 charge](https://github.com/Rachels-Courses/CS200-Concepts-of-Progamming-Algorithms/raw/2017-06-Summer/Assignments/In-class%20Labs/2017-01%20Spring/images/201701_lab4_program3c.png)

**1/4th charge:**

![Screenshot with 1/4 charge](https://github.com/Rachels-Courses/CS200-Concepts-of-Progamming-Algorithms/raw/2017-06-Summer/Assignments/In-class%20Labs/2017-01%20Spring/images/201701_lab4_program3d.png)

#### Additional hints

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

### Program 4: Input validation

Write a program that displays a list of fruits and asks the user to choose one. If the user selects an invalid input, display an error message. Otherwise, display "good choice!"

* Logical operators:
    * And: ```&&```
    * Or: ```||```
    * Not: ```!```

#### Example output

**Valid input:**

![Valid input screenshot](https://github.com/Rachels-Courses/CS200-Concepts-of-Progamming-Algorithms/raw/2017-06-Summer/Assignments/In-class%20Labs/2017-01%20Spring/images/201701_lab4_program4a.png)

**Invalid input 1:**

![Invalid input screenshot](https://github.com/Rachels-Courses/CS200-Concepts-of-Progamming-Algorithms/raw/2017-06-Summer/Assignments/In-class%20Labs/2017-01%20Spring/images/201701_lab4_program4b.png)

**Invalid input 2:**

![Invalid input screenshot](https://github.com/Rachels-Courses/CS200-Concepts-of-Progamming-Algorithms/raw/2017-06-Summer/Assignments/In-class%20Labs/2017-01%20Spring/images/201701_lab4_program4c.png)

#### Additional hints

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

### Program 5: Switch statements

Write a program that asks the user to enter two numbers. Then, ask them whether they want to add, subtract, multiply, or divide.

Use a switch statement to decide what kind of operation to do, and display the result.

#### Steps

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

#### Example output

**Add:**

![Add screenshot](https://github.com/Rachels-Courses/CS200-Concepts-of-Progamming-Algorithms/raw/2017-06-Summer/Assignments/In-class%20Labs/2017-01%20Spring/images/201701_lab4_program6a.png)

**Subtract:**

![Subtract screenshot](https://github.com/Rachels-Courses/CS200-Concepts-of-Progamming-Algorithms/raw/2017-06-Summer/Assignments/In-class%20Labs/2017-01%20Spring/images/201701_lab4_program6b.png)


**Multiply:**

![Multiply screenshot](https://github.com/Rachels-Courses/CS200-Concepts-of-Progamming-Algorithms/raw/2017-06-Summer/Assignments/In-class%20Labs/2017-01%20Spring/images/201701_lab4_program6c.png)


**Divide:**

![Divide screenshot](https://github.com/Rachels-Courses/CS200-Concepts-of-Progamming-Algorithms/raw/2017-06-Summer/Assignments/In-class%20Labs/2017-01%20Spring/images/201701_lab4_program6d.png)


**Invalid:**

![Invalid screenshot](https://github.com/Rachels-Courses/CS200-Concepts-of-Progamming-Algorithms/raw/2017-06-Summer/Assignments/In-class%20Labs/2017-01%20Spring/images/201701_lab4_program6e.png)






![horizontal rule](images/hr.png)

## Questions

*Answer these questions in a text editor and turn them in with your project.
Valid file formats are: .txt, .rtf, .docx, .odt, .pdf*

### A. Operators

"Translate" the following questions into boolean expressions, using variables and operators.

A-1. Is **age** less than 13?

A-2. Does **name1** and **name2** have the same value?

A-3. Does **word1** come before **word2** in the dictionary? *(Hint: The computer considers 'a' to be less than 'b')*

A-4. Is **age** less than 21, and is **age** also greater than 18?

A-5. Is **x** between 5 and 10? *(Hint: You need to phrase this as two separate boolean expressions and combine them with a logical operator!)*

---

### B. Boolean expressions

Figure out whether the following expressions will evaluate to **true** or **false**,
given the variable's value. Simply answer "true" or "false".

B-1. ```( isDone )```, isDone is true.

B-2. ```( !isDone )```, isDone is true.

B-3. ```( age >= 18 && age < 21 )```, age is 20.

B-4. ```( x > 0 && x < 10 )```, x is 0.

B-5. ```( color != "green" )```, color is "cyan".

---

### C. Coin flip

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
