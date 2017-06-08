CS 200 Lab 1a: Recipes - Helper

*This is an introduction to the topics covered in this lab. 
Go to the  [*Lab*](https://github.com/Rachels-Courses/CS200-Concepts-of-Progamming-Algorithms/blob/2017-06-Summer/Assignments/In-class%20Labs/Lab%2001a%20-%20Recipes.MD) 
document for the program instructions.*

## Creating a program

When we create a C++ project, generally it will begin empty. All programs
need *at least one* source file, but for more sophisticated programs,
there may be multiple source files.

**C++ source files have the endings: .cpp, .hpp, and/or .h**. We will work
with .hpp/.h (header) files later, but for now we are just working with
.cpp (source) files.

To create a project in Visual Studio:

1. Create a new project. *File > New > Project...*
    1. Select **Visual C++** from the left category list.
    2. Select **Empty Project** from the template list.
    3. Set the project **Name** to "lab01a_recipes".
    4. Set the project **Location**.
    5. Click **OK**.

And to add your lab source file in Visual Studio:

2. Create your source file. In the **Solution Explorer**, right-click your project file. *Add > New Item...*
    1. Select **C++ File (.cpp)** and name it **main.cpp**.
    2. Click **Add**.

### Bare-minimum program

Your source file will also start out blank. The bare-minimum code you need
for a C++ program is:

```c++
int main()
{
    return 0;
}
```

Every program needs an **entry point** -- a place to begin -- and for C++
it is always in the ```main()``` **function**. We will learn more about
functions later.

Within the ```main()``` function, we have ```return 0;``` - this marks
the **end of our program**. We will be adding code within the curly braces ```{ }```,
and before ```return 0;```.

### Adding libraries

C++ has multiple **libraries** included with it. A **library** is a set of code
that has been pre-written, and packaged so that it is reusable across many projects.

For example, C++ has an **input-output** library called *iostream* that allows
us to write text to the screen, and get user input from the keyboard.

To add this functionality to our program, we need to use an ```#include``` statement.

```c++
#include <iostream>     // add this
using namespace std;    // add this

int main()
{
    return 0;
}
```

### Comments

In C++, you can add comments to the code in two ways:

```c++
// Single-line comment!
```

```c++
/*
    Multi-
    line
    comment!
*/
```

The program doesn't do anything with comments; they are for programmer-use!

### Stopping the program

In Visual Studio, if you run your program in debug mode, it will begin running at ```main()```,
execute its code, and once it hits ```return 0;``` the program will end and the
program window will disappear immediately.

Later on, we will write programs that will continue running until the user explicitly tells it to quit,
but for now we need a *workaround* to make sure our program doesn't stop once its finished.

For now, we can add an **infinite loop** at the end of our program... this is just a workaround!
You can add a while loop like below to prevent the program from reaching the ```return 0;```:

```c++
#include <iostream>
using namespace std;

int main()
{

    while ( true ) ;    // Program stops here
    return 0;
}
```

---

## Displaying output

Once you have the *iostream* library included in your program, you can
display text output to the screen, as well as get input from the user.

To display output, you use the ```cout``` command, as well as the stream
operator ```<<```. A simple output will look like:

```c++
cout << "Hello, world!";
```

Any time you add text to the program, such as during a *cout*, the
text within the double-quotes is known as a **string literal**.

You can also display values of variables with a *cout* statement,
but we will get to that in a minute.

When we use several *cout* statements, new lines are not automatically added:

```c++
#include <iostream>
using namespace std;

int main()
{
    cout << "Hello";
    cout << "World";

    while ( true ) ;    // Program stops here
    return 0;
}
```

![HelloWorld as one word, without a space.](images/lab01a_cout.png)

In C++, we have to tell the program *manually* when to add a new line.
There are two ways we can do this:

```c++
cout << "Hello\nWorld";                 // Way 1: use \n
cout << "Hello" << endl << "World";     // Way 2: use endl
```

The ```\n``` **escape character** is a way that you can add a new-line
into your message without ending your **string literal** (within double-quotes).

The ```endl``` is another command that you can use to add new lines,
but notice that it *cannot go within double-quotes*: You must end the
string literal, then chain together the endl via the **stream operator** ```<<```.

You can chain together as many endls and string literals and variable values
as you'd like, so long as there is a stream operator ```<<``` in-between each item.

```c++
cout << "Hello" << endl << endl;
cout << "World" << endl;
cout << "Goodbye";
```

![Hello World and Goodbye on separate lines.](images/lab01a_cout2.png)

---

## Variables

Variables are a location where you store data. This data can be numbers, strings, boolean values, memory addresses, and many other things. Eventually, we will be creating our own data types and store data in our own custom variables.

In C++, you must **declare** a variable before you can use it. When you
declare a variable, you let the program know what kind of data that the
variable will store: integers? numbers with decimals? symbols? a string of letters? etc.

![A series of boxes, with different types of data being entered into it.](https://github.com/Rachels-Courses/Course-Common-Files/raw/master/Review/Archive/Summary%20Notes/images/variables.png)

Some common data-types are:

<table class="table">
<thead>
<tr>
<th>
Data type
</th>
<th>
Keyword
</th>
<th>
Description
</th>
<th>
Example values
</th>
</tr>
</thead>
<tbody>
<tr>
<td>
Integer
</td>
<td>
<pre>int</pre>
</td>
<td>
Whole numbers
</td>
<td>
<pre>
-5
0
100
</pre>
</td>
</tr>
<tr>
<td>
Float and Double
</td>
<td>
<pre>
float
double
</pre>
</td>
<td>
Numbers with decimal points.
</td>
<td>
<pre>
-10.00
9.99
3.14159
</pre>
</td>
</tr>
<tr>
<td>
Boolean
</td>
<td>
<pre>
bool (C++)
boolean (Java)
</pre>
</td>
<td>
Only stores <strong>true</strong> or <strong>false</strong>.
</td>
<td>
<pre>
true
false
</pre>
</td>
</tr>
<tr>
<td>
Character
</td>
<td>
<pre>char</pre>
</td>
<td>
Single letters, numbers, symbols, etc.<br>Characters values must be contained within single-quotes.
</td>
<td>
<pre>
'a'
'A'
'$'
'0'
</pre>
</td>
</tr>
<tr>
<td>
String
</td>
<td>
<pre>
string (C++)
String (Java)
</pre>
</td>
<td>
Text, numbers, letters, anything.<br>String values must be contained within double-quotes.
</td>
<td>
<pre>
"Hello!"
"12345 College Blvd"
"1... 2... 3..."
</pre>
</td>
</tr>
</tbody>
</table>

A **variable declaration** must contain the **data-type** and the **variable name**:

```c++
int amountOfKittens;
double pricePerSandwich;
bool isSaved;
string username;
```

Once a variable has been declared, its type cannot change.

**Declare once, use multiple times:** Once you declare a variable,
you do not need to keep adding the data-type to the variable name whenever you use it;
this is only for the declaration!

```c++
int amountOfKittens; // declaration

amountOfKittens = 20; // assigning a value

amountOfKittens = amountOfKittens + 5; // adding 5 to the existing value
```

The ```=``` is known as the **assignment operator** and is used to assign
values to variables. On the **left-hand side (LHS)** of the = sign is the
variable that will get the new value. The **right-hand side (RHS)** will
be the new value. The new value can be a hard-coded value, or a computation.

You can generally name your variable anything that you'd like, but there are a few rules to follow when doing so...:

1.    A variable name must begin with a letter (a-z, A-Z), underscore (_), or a dollar sign ($).
2.    You can include numbers in a variable name (0-9), but it cannot be the first character.
3.    The variable name can have virtually any length.
4.    You can use upper-case and lower-case letters in your variable names, but there is a naming convention that you should try to follow. Also, remember that variable names are case-sensitive.
5.    Reserved keywords (such as "if", "int", "public") cannot be used as variable names.

---

## Getting user input

In our programs, we may want to ask the user a question, which may affect
the calculations done, or the program flow, or other behavior.
We can ask for user input with the ```cin``` command:

```c++
int number;
cout << "Please enter a number: ";
cin >> number;
```

When getting user input, you *must* have some variable that you're storing
your information in. As long as it is a basic data-type like *integers*,
*floats*, *strings*, or *chars*, C++ will handle putting the user's input
into the variable.

However, if you're trying to store input into an *integer* variable and the
user enters a *letter*, your program will crash. Adding error detection
to validate the inputted data type is a little tricky, so we won't worry
about that in this class.

**Good practice:** Always add a message with ```cout``` prior to your
```cin``` statement - this lets the user know that you're expecting
some input! Otherwise, it will look like the program has crashed (but it hasn't!)
because it sits there waiting for input, but hasn't told the user this!

**Common error:** ```cin``` statements will never have an ```endl``` at the end;
endl is only for cout!
