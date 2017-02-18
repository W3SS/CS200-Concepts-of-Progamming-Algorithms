# Homework Exercise 2: If/Else Branching

## Rules

* Team size: **1 person**
    * You can brainstorm with others - that is, you can verbally discuss the problem.
    * You cannot copy another person's work. 
    Code will be checked against other submissions with a diff tool.
    If a copy is found, both people will receive a 0 on the assignment.
* Open book / open note - do research as-needed.

## Turn in

**You will need to upload your code both to the class D2L Dropbox, and to your CS 200 GitHub repository!**

Locate your source files for this project. They should have the extentions .cpp, .hpp, and/or .h. In Windows, they are labelled as "C++ source file" and/or "Header file". 

![Windows, you're annoying.](https://github.com/Rachels-Courses/Course-Common-Files/raw/master/How-to/images/sourcefiles.png)

**These are the only files you need** - You do not need to upload any Visual Studio files.

Upload these source files to your GitHub repository and to the Dropbox.

## Reference Information

* [How to turn in your source code](https://github.com/Rachels-Courses/Course-Common-Files/blob/master/How-to/Turning%20in%20source%20code.md)
* [Visual Studio - How to create a new project](https://github.com/Rachels-Courses/Course-Common-Files/blob/master/How-to/New%20project%20-%20Visual%20Studio.md)
* [Common programming errors](https://github.com/Rachels-Courses/Course-Common-Files/blob/master/Review/Common-errors.md)

---

## Making sure your program doesn't immediately end

This is not the best way to make sure your program doesn't quit, but it is OK for now.

Within main, do this:

 	int main()
	{
		while ( true ) { }
		return 0;
	}

This essentially puts an *infinite loop* at the end of your program - but at least it won't quit while you're trying to see it run! :P

You can stop the program in Visual Studio through the square "stop" button.

---

## Part 1: If statement and integer

Create a program that asks the user for their age. If their age is less than 13, then it sets a ticket price to $5.00. Otherwise, it sets the ticket price to $7.00. Afterward, display the ticket price amount.

* Your ticket price variable should be a float and should be declared *before* the if statement, so it can be used within the if statement.
* You also need to declare an integer variable to store the user's age.
* You will need to use **cout** and **cin** to display messages to the user and get input from the user.

### Solution (this problem only)
	
	#include <iostream>
	using namespace std;
	
	int main()
	{
		int age;
		float ticketPrice;
	
		cout << "Age? ";
		cin >> age;
	
		if (age < 13)
		{
			ticketPrice = 5.00;
		}
		else
		{
			ticketPrice = 7.00;
		}
	
		cout << "Ticket price: " << ticketPrice << endl;
	
		while ( true ) { } // temp - don't let program quit.
	
		return 0;
	}

### Questions & Answers

Write your program, and answer these questions as comments above main():

* What is the scope of your age variable?
* What is the scope of your ticket price variable?

---

## Part 2: If statement and boolean

**You will need to make a new project!**

In this program, create a boolean variable called **likesPizza**.

First, manually set it to true (i.e., you're not asking the user to input it, you're setting it in the code.)

Then, create an if statement: If likesPizza is true, then display the message "Likes pizza."

Otherwise, display the message "Doesn't like pizza."

First, test it out with **likesPizza = true;**, then try it out with **likesPizza = false;**. Make sure both messages output correctly!

### Questions & Answers

Write your program, and answer these questions as comments above main():

* If you try to output **likesPizza** on its own, like this: **cout << likesPizza;** , what is displayed? What is the value for true, and for false?

---

## Part 3: If statement and a boolean expression

**You will need to make a new project!**

In this program, create a boolean variable called **isTallEnoughForRide**. You do not need to initialize it to any values.

Also create a variable called **feet**, and ask the user what their height, in feet, is. Store it in the feet variable.

Next, you're going to assign a value to the **isTallEnoughForRide** boolean variable. You're going to use a boolean expression, similar to what you'd put in an if statement's ( ), but use it as the value for the boolean.

Assign isTallEnoughForRide the value of: ( feet > 3 ).

Then, the boolean will either be **true** if feet is > 3, or it will be **false** if feet is <= 3.

Create an if statement that checks whether **isTallEnoughForRide** is true or false. If true, display the message "Permitted to ride the roller coaster."

If it is false, display the message "Too short to ride the roller coaster."

### Questions & Answers

Write your program, and answer these questions as comments above main():

* If you write a less-than/greater-than expression as the condition of an if statement (what's written between the parentheses), can you also write it as the value of a boolean variable?

---

## Part 4: If statement and characters

**You will need to make a new project!**

In this program, create two **char** variables: letter1 and letter2.

Ask the user to enter two letters. Use cin to get values for letter1 and letter2.

Afterward, we're going to figure out which one alphabetically comes first. In C++, you can use < and > to compare letters as well as numbers - 'a' comes before 'b', so 'a' < 'b'.

Use an if statement to check if letter1 is less than letter2. If so, display the message "first letter comes first".

If not, display the message "second letter comes first".

### Questions & Answers

Write your program, and answer these questions as comments above main():

* What happens if the user enters 'a' and 'A'? Is this correct?
* If you do some research online (5 minutes), can you find out why this happens?

---

## Submit your work

### GitHub

Upload your project to GitHub in your CS200 repository:

Go to your CS200 repository page from the GitHub website. The URL to get to your profile page
should be github.com/YOURUSERNAME.

Click on the **Exercises** folder that you should have created during Lab 1.

Use the [upload files instructions](https://github.com/Rachels-Courses/CS200-Concepts-of-Progamming-Algorithms/blob/master/Assignments/In-class%20Labs/Lab%2001%20-%20Intro%20to%20GitHub%20and%20CPP.md#upload-files)
from Lab 1 to upload your **folder for this exercise** to GitHub.

### D2L

Once you're finished with all the steps, zip up **all of your** project folders
and upload them to the dropbox in D2L.

In the comments, paste the URL of your CS 200 repository.
