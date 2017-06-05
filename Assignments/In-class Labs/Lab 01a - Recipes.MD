# CS 200 Lab 1a: Recipes

---

[Information](#information) | [Introduction](#introduction) | [Lab](#lab) | [Questions](#questions)

---

## Information

### Lab topics

* Variables
* Input/Output

### Rules

* For **in-class labs**, collaboration is allowed.
    * If you work with another student on an assignment, make sure that you both
    turn in a copy of the work, and also mention in the D2L comments who you worked with.
    * You can also ask classmates questions if you're unsure on something.
    * You can ask the instructor for help at any time.

### Turn in

Once you are finished with a project, zip up the entire folder that contains
all source files and project/solution files. Turn in this zip file to **Desire2Learn**.

---

## Introduction

*This is an introduction to the topics covered in this lab. Scroll down
to the *Lab* section if you want to get started.*

### Creating a program

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

#### Bare-minimum program

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

#### Adding libraries

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

#### Comments

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

#### Stopping the program

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

### Displaying output

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

### Variables

### Getting user input

---

## Lab



---

## Questions

*Answer these questions in a text editor and turn them in with your project.
Valid file formats are: .txt, .rtf, .docx, .odt, .pdf*



