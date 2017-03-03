# Homework Project 2: Tic Tac Toe

## Downloads

Download the **starter project**. This folder contains the code, as well as a Visual Studio project and a Code::Blocks project.

Extract the zip file somewhere to your hard drive.

**To open in Visual Studio**

Open the following file:

	project files/HP2 - Visual Studio/HP2 - Visual Studio.sln

This is marked as "Microsoft Visual Studio Solution" in Windows.

**To open in Code::Blocks**

Open the following file:

	project files/HP2 - CodeBlocks/HP2 - CodeBlocks.cbp

This is marked as "CBP File" in Windows.

## Rules

* Open book / Open note:

	* Do research for this assignment as-needed. Use your textbook, the web, class example code, etc.
 
* Solo work:

	* This is a solo assignment and you should be working on this alone. This means...:
	
    	* ✓ You can verbally brainstorm with others to discuss the problem and techniques for problem solving.
    	* ✓ Your work must be your own work.
    	* ✓ Email the instructor, or ask in the Slack channel, if you are stuck or need clarification on the instructions.
    	* ✗ You cannot give your code to somebody else for them to "verify their work" with (more often than not they just copy it, and then you both get 0%!)
    	* ✗ You cannot copy another student's work. I will use a diff tool to compare student assignments (and code online). If there is obvious copying, all people involved will receive a 0%.

## Turn in

When you're ready to turn in your work, upload the following files:

	hp2_program.hpp
	hp2_program.cpp

file to your GitHub repository, and to the D2L Dropbox.

### General turn in information

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

# Introduction

## Review

* 2D arrays

## Files

* hp2_program.hpp
* hp2_program.cpp
* hp2_tester.hpp
* hp2_tester.cpp
* Menu.hpp
* StringUtil.hpp
* TesterBase.hpp
* TesterBase.cpp

## Unit tests

---

# Don't write everything at once.

Don't write a ton of code all at once - write a small feature, then COMPILE to make sure your program builds, and run to make sure it runs.

---

# Private member variables

These variables are part of the **Program** class and you will use them throughout the functions.

    char gameBoard[3][3];
    int turn;
    int playerWins[PLAYER_COUNT];
    int playerMarker[PLAYER_COUNT];

* gameBoard - A 2D array that stores **characters** - either empty (' '), or a player piece 'x' or 'o'.
* playerMarker - A 1D array with 2 elements. playerMarker 0 should be 'x', and playerMarker 1 should be 'o'.
* turn - An integer to mark whose turn it is; this should correspond to the playerMarker (turn can be 0 or 1.)
* playerWins - A 1D array. Count the amount of times that player 0 has won, and player 1 has won, in this array.

---

# Function Specifications

## void Main()

## void Setup()

## void GameLoop()

## void DrawBoard()

## void DrawStats()

## int GetValidInput( int min, int max )

## int GetCurrentPlayerTurn()

## void SwapTurn()

## bool PlaceMarker( int x, int y, char marker )

## int CheckForWinner

---

# Extra Credit

## Option 1: CheckForWinner

Update CheckForWinner to be more generic, using loops to check all the cells for "3-in-a-row", instead of a big series of for-loops.

## Option 2: Add a third player

Update the program to work with three players!!11
