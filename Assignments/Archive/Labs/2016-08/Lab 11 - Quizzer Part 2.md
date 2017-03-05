# CS 200 Lab 11: Inheritance

Please read this document in Chrome. :)

## Topics

* Classes

## Introduction

This lab is meant to help you practice with classes.

We're writing a program that quizzes the user. We will have different
types of questions, such as true/false, fill in the blank, and multiple choice.

## Downloads

Make sure to download the files from the first part:

* main.cpp
* Question.hpp
* Question.cpp

## Turn-in

Zip up the Visual Studio project, including all the source files (.cpp, .hpp)

When you're uploading your source to the Dropbox.

Add the name of all people in your team in the upload comments.

---

Currently the only type of question is a fill-in-the-blank type of question.

We're going to want to create a **base class** that contains any *common functionality*
that is shared between each type of question.

You will want to keep your existing **Question** class for reference,
but it might be best to start over on the code, so comment it out.

## Questions

Declare the following classes within Question.hpp:

* BaseQuestion
* TrueFalseQuestion
* MulipleChoiceQuestion
* FillInTheBlankQuestion

TrueFalseQuestion, MultipleChoiceQuestion, and FitbQuestion will inherit
from BaseQuestion...:

        class TrueFalseQuestion : public BaseQuestion
        {
                // ...
        }

When TrueFalseQuestion inherits from BaseQuestion, then all of the
**public** and **protected** members of BaseQuestion now also belong
to the TrueFalseQuestion class. So, for example, every question will
need question text to display to the user, so this will be stored in BaseQuestion.

But first we need to implement that within BaseQuestion...

### BaseQuestion

BaseQuestion will have one member method and one member variable.

#### Member variables:
* m_question, a string. Accessibility is protected.
        
#### Member methods:
* SetQuestion. Accessibility is public.
        * Return type: void
        * Parameters:
                * question, a const string reference
                        

Within the SetQuestion method, it should simply assign m_question the value of the parameter question.


### FillInTheBlankQuestion

The FillInTheBlankQuestion question will be similar to what we had last time.
The user will have to enter in their answer, and their answer will be compared
to the stored answer.

We do not need to re-implement the SetQuestion method, or to re-declare the
m_question variable - these are automatically made part of the class via inheritance.

We do need these members, though:

#### Member variables:

* m_answer, a protected string.

#### Member methods:

* SetAnswer, a public function.
        * Return type: void
        * Parameters:
                * answer, a constant string reference
* AskQuestion, a public function.
        * Return type: boolean
        * Parameters: None
        
Within SetAnswer, just set the value of the m_answer variable to the 
answer passed in.

For AskQuestion, display the question to the user, then ask the user for their input.
Compare the user's answer to the m_answer value and return
*true* if they got it right, or *false* if they didn't.

Example output:

        Question: The result of 2+2 is
        Answer: 4

**Make sure to test it out before continuing!**

### TrueFalseQuestion

The TrueFalseQuestion will just ask the user to select true or false from
a menu, and then compare it with the answer (in this case, a boolean).

#### Member variables:

* m_isTrue, a protected boolean.

#### Member methods:

* SetAnswer, a public function
        * Return type: void
        * Parameters:
                * isTrue, a boolean.
* AskQuestion, a public function
        * Return type: boolean
        * Parameters: None

Again, with SetAnswer, set the m_isTrue equal to the parameter.

For AskQuestion, display the question to the user. Then, display
a small menu to let them choose true or false. For example:

        Question: The capital of Kansas is Topeka
        Answer: (1) True, (2) False
        Choice: 1

Get the user's input. Compare their answer to the m_isTrue value.
Again, if the user got it right, return *true*, and otherwise return *false*.

### MultipleChoiceQuestion

This one will have a menu of several items to choose from. The user will
have to select one of the four options.
You will have to store an array of answers, as well as the index of the correct item.

#### Member variables:

* m_answers, a string array of size 4.
* m_correctIndex, an integer.

#### Member methods:

* SetAnswers, a public function
        * Return type: void
        * Parameters:
                * answers, a const string array of size 4.
                * correctIndex, an integer
* AskQuestion, a public function
        * Return type: boolean
        * Parameters: None

For SetAnswers, you will move all the values from *answers* to *m_answers*.
Don't forget to store *correctIndex* as well.

In AskQuestion, display the question, the menu, and get the user's input.
Compare the user's answer selection to the stored m_correctIndex.
Again, if the user got it right, return *true*, and otherwise return *false*.

You might change the display to use 1, 2, 3, 4 instead of 0, 1, 2, 3, 
but you will have to remember to change the index after the user enters it.

Example display:

        Question: Which of the following is a primary color?
        Answers: 
        1. Orange
        2. Purple
        3. Red
        4. Black
        Choice: 3

## main program

You will have to modify the main program to work with these Question types
now. You will still keep track of a score.

Declare at least three variables: one FillInTheBlankQuestion, one TrueFalseQuestion, one MultipleChoiceQuestion.

Set each of these up, and then call the AskQuestion() functions in order.

At the end, display the result to the user.

        Question: The result of 2+2 is
        Answer: 5


        Question: The capital of Kansas is Topeka
        Answer: (1) True, (2) False
        Choice: 1


        Question: Which of the following is a primary color?
        Answers: 
        1. Orange
        2. Purple
        3. Red
        4. Black
        Choice: 3

        Final score: 2/3



