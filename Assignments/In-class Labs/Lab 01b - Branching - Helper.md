# CS 200 Lab 1b: Branching - Helper



# Relational operators and logic operators

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

# Boolean Expressions

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

# If statements

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


## Solo if statement

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



## If / else statements

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




## If / else if / else statements

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

# Switch statements

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

