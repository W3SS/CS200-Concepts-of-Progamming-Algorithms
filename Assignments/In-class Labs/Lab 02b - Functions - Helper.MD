# CS 200 Lab 02b: Functions - Helper

## Introduction

In algebra, we have functions like this:

```c++
f(x) = 2x + 1
```

This is a function.

The general idea behind a function is that it takes **input** *x*, does some
calculation, and returns an **output** *f(x)*.

We can do the same thing in programming - though, we're not necessarily restricted to numbers.

Functions all have **inputs** and **outputs** - though, sometimes,
the inputs and/or the outputs might be empty, or return nothing.

A basic function declaration looks like this:

```c+++
float DoubleMe( float number )
{
    return 2 * number;
}
```

The function **declaration** begins by specifying the **return type** - a float.
This means that the function will return a float value as its **OUTPUT**.

Second, **DoubleMe**, is the function name.

Third, within parenthesis, are the **function parameters**. This function only 
has one parameter - a number. The parameters are the **INPUTS** of the function.

Finally, within the curly braces { and } is the **function body**. This is where
you define your calculations and your logic that get executed.

The function body works with the **input** to generate some **output**.


## Function

Note: Method is the common term for Java, while Function is the term used for C++. In some languages it is also known as a sub-routine.

A method is a chunk of code that can be called by its method name. Code is usually stored in a method so that it can be reused throughout the program without copying down the same code.

A method in Java, C++, and C# require a **return-type**, 
a **parameter list**, and the **method body**. The parameter list may be empty.

<table>
<tr>
<td><pre>public</pre></td>
<td><pre>int</pre></td>
<td><pre>sum</pre></td>
<td><pre>(int a, int b)</pre></td>
</tr>
<tr>
<td>Accessibility</td>
<td>return-type</td>
<td>method name</td>
<td>parameter list</td>
</tr>
</table>

## Function Header / Function Signature

The method header is the first line of a function,
which defines the expected **inputs** of a function, 
and the type of **output** it will return, if any.

## Accessibility

Member methods and variables can be qualified with an accessibility level: public, protected, or private.

* A **public** member is available to any other classes anywhere outside of the class it belongs to.
* A **protected** member is only available to the class it belongs to, and any children classes (subclasses).
* A **private** member is only available to the class it belongs to – no child classes.

If no accessibility level is specified, methods and variables are private by default.

## Return Type

The return-type is a required part of a method signature. 
It can be any data-type, such as a **primitive** (int, boolean, double, etc.), 
an **Object** (String, Integer, a class that you specify, etc.), 
or **void** if no return statement is required.

## Function Name

The method name is user defined and used to identify the method. It has to follow the same naming rules as variables: It can contain letters and numbers and underscores, but no numbers as the first character of the method name.

## Parameter List

The parameter list is a list of **inputs** that the method expects to receive when it is called. The parameter list is contained within the parenthesis ( ) of a method signature. It can be empty if no input is required, or contain multiple variables, separated by a comma.

These variables declared in the parameter list may be used anywhere within the method itself, but is not available outside of the method.

## Parameter

A parameter is a variable input that a method uses. It is specified in the **method definition**.

## Argument

An argument is the value or variable passed into a method during the **method call**.

## Function Body / Function Definition

The method body is the code within the curly braces { } after the method header. It is the code that is executed when the method is called.

## Function Declaration

In C++, you may **declare** a function without **defining** it in the same line.

The delaration is only the function header, with a semi-colon at the end.

## Function Call

A method is called by using the method's name and passing in arguments. If the method has a return type, you should store the result in a variable at the calling level, otherwise the data will be lost.

## Function Declaration vs. Function Definition vs. Function Call

Make sure you can tell the difference between these!

<table>
<tr>
<th>Function Declaration</th>
<th>Function Definition</th>
<th>Function Call</th>
</tr>

<tr>
<td><pre>
int Area( int w, int h );
</pre></td>

<td><pre>
int Area( int w, int h )
{
    return w * h;
}
</pre></td>

<td><pre>
void main()
{
    int w = 5;
    int h = 4;
    int area = Area( w, h );
}
</pre></td>
</tr>
</table>

