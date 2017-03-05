# CS 200 Lab 10: Classes

Please read this document in Chrome. :)

## Topics

* Classes

## Introduction

This lab is meant to help you practice with classes.

We're writing a program that quizzes the user. Eventually, we will extend this
to use inheritance.

## Turn-in

Zip up the Visual Studio project, including all the source files (.cpp, .hpp)

When you're uploading your source to the Dropbox.

Add the name of all people in your team in the upload comments.

---

# Program: Question and Answer

For this program, we will be creating a simple class to use. We will need three files:

* main.cpp - Where the main function goes,
* Question.hpp - Where the class declaration and function declarations go.
* Question.cpp - Where the function definitions go.

## Question.hpp - The header file for the Question class
 
Make sure to start off your Question.hpp file like this:

	#ifndef QUESTION_HPP
	#define QUESTION_HPP

	#include <string>
	#include <iostream>
	using namespace std;

	#endif


Your class declaration will go inside the #define QUESTION_HPP and #endif.
This is only needed for .hpp files.

Within any .hpp files, you will also need to include any other libraries you're
using within - it isn't good enough to only include those in main.cpp.

Declare a class named **Question**.

### Private members of Question:

* m_question, a string variable.
* m_answer, a string variable.

### Public members of Question:

* SetQuestion, a method:
	* Return type: void
	* Parameters: 
		* question, a const string reference.
		* answer, a const string reference.
* AskQuestion, a method:
	* Return type: boolean
	* Parameters: none
	
The function definitions will go in the .cpp file, so make sure you have single
lines for the function declarations, and end them with a semi-colon.

## Question.cpp - The source file for the Question class

Within the Question.cpp file, you will need to include your Question header file:

	#include "Question.hpp"

Notice that the file name goes within double-quotes, but the C++ libraries go within < > signs.

You will need to define the methods within this file. When you're defining a function
outside of the class declaration, you will also need to prefix the function name
with the class name, and the :: scope resolution operator...

	void Question::SetQuestion( const string& question, const string& answer )
	{
	}
	
and so on.

### SetQuestion

This function will overwrite the values of the private member variables **m_question** and **m_answer**
with the corresponding parameters passed in.

### AskQuestion

This function will display the value of **m_question** to the user.

Afterward, it will get the user's guess and store it in a temporary string variable.

Finally, it will check to see if the user's answer matches the actual answer (**m_answer**),
if so, display "Correct" and return **true**. Otherwise, display "Incorrect" and return **false**.

Example:

	QUESTION: 2 + 2 = ?
	Your answer: 5
	INCORRECT
	
## main.cpp

Within your main program source file, make sure to include Question.hpp:

	#include "Question.hpp"

You do not have to include the .cpp file, only the header file .hpp.

Within main, declare a score variable:

	int score = 0;

And declare a few questions:

	Question q1, q2, q3;
	
Use the **SetQuestion** function to set up all the questions and answers.

Then, for each question that you made, call the **AskQuestion** function.
However, this function should return either **true** or **false** based on
whether it was answered correctly or not. So, you can put your function
call within an **if statement**.

	if ( function call == true ) { ... }
	
If the answer was correct, then you want to increment score by 1.

Once all the questions have been answered, display the user's final score.

## Example output:

	QUIZ
	
	QUESTION: 2 + 2 = ?
	Your answer: 5
	INCORRECT
	
	QUESTION: 2 + 3 = ?
	Your answer: 5
	CORRECT
	
	QUESTION: The opposite of open is ...?
	Your answer: closed
	CORRECT

	Final Score: 2
	
## Implement with arrays

Modify the program to use arrays instead of separate Question variables.

You will still need to maually call **SetQuestion** for each element,
but you can use a for loop to ask each question.

---

# Brainstorming

* What is the advantage of using an array of Questions, rather than declaring each
question as a separate variable?

* This question type is essentially a "fill in the blank". How would you implement
other types of questions, like True / False or Multiple Choice?

* For each type of question, what is **in common?** What is **different?**

* Based on what is common, can you figure out what would go in a **QuestionBase** class?

* Based on what is different, can you figure out what type of child classes of QuestionBase 
you would declare, what member variables they would have, and how the **AskQuestion** function
work change?


