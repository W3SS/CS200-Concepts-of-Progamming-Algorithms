# CS 200 Programming Assignment 3

Book List

## Turn-In

Once finished with your project, you will need to turn in all
**.cpp** and **.hpp** files into the Dropbox.

## Groupwork

You are allowed to collaborate with one other classmate if you'd like.
If you work on this program as a group project, you **must** use GitHub
in order to coordinate your code - I will be checking the
commit logs to see who
worked on what portion of the program.

## Introduction

This program will allow the user to keep track of the books they have.
They can mark each book as "Haven't started", "Currently reading", or "Finished".

The program will save and load to a .txt file to keep track of all the books,
but it can also export the book list to CSV, which can be opened in Excel and looks nicer.

The program will allow the user to add new books or update existing books,
as well as give the stats on their books and be able to save and export the data.

We will be using two arrays to keep track of the *book titles* and *book status* (Finished, reading, etc.), and each core part of functionality will get its own function (save file, display menu, etc.)

---

![Screenshot](images/mainmenu.png)

---

# Function List (overview)

These are the functions that you will be implementing.

* DisplayMenu - Displays the main menu, a list of options the user can choose from.
* GetValidInput - Gets the user's input (via cin), and checks to make sure it is valid before returning that input to the caller.
* AddBook - Allows user to add a new book (title and status)
* UpdateBook - Allows user to update an existing book's title or status
* DisplayBooks - Display a list of all the books to the console window
* DisplayStats - Display stats about the books in the list (# finished, # total, etc.)
* LoadList - Loads the .txt file of books
* SaveList - Saves the .txt file of books
* ExportUnfinishedBook - Exports only "Haven't started" and "Currently reading" books to a .csv file
* ExportCsv - Exports all books to a .csv file

---

# Iterative development

This program has quite a few features, so you will want to start by just implementing
and testing one feature at a time.

## Iteration 1: Main Menu and User Input

For this iteration, we are just going to display the main menu and get the user's input. This will require two functions: **DisplayMenu** and **GetValidInput**.

### DisplayMenu

**Return Type:** void

**Parameters:** none

This function is responsible for displaying the list of menu options to the screen, and nothing else.

When the function is called, its output should look like:

	0. Add book
	1. Update book
	2. Export list to CSV
	3. Export unfinished books to CSV
	4. Display stats
	5. Save and quit

This function does not take any input or process anything, its only job is to display data.

### GetValidInput

**Return Type:** integer

**Parameters:** min (int), max (int)

This function will make sure that the user has entered a valid input value. If they have not, it will keep looping and ask them to try again, until the user finally
enters something valid.

1. Create a local variable called **choice** (int).
2. Display a prompt, asking the user to enter information. (cout)
3. Get the user's input and store it in choice. (cin)
4. Make sure the user's input is valid!
5. Return the user's choice once it is valid.

For step 4, you need a while loop. *While* the input is invalid, ask the user to try again,
and use cin to get their input a second time.
You can reuse the *choice* variable.

When is the input invalid? A max and min value are passed in, so if the choice is
*NOT* between [min, max], then it is invalid. Or, if the choice is less than min or greater than max, then it is invalid.

Use a **return** statement to return the user's input once it is valid.

### main()

In main, create a while loop that will keep running until the user has quit.
You might want to create a boolean variable "isDone" to use to decide when to stop looping.

Inside the loop, **display the menu**, then **get the user's input**.

Then, use an if statement or a switch to figure out whether they entered 0, 1, 2, 3, 4, or 5.

At the moment, the only function we'll implement is the quit option - if the user selected quit, then set "isDone" to true.

#### Calling functions

When you are calling functions, you need to use the *function name*. This name always ends with parenthesis.

If your function has *input*, pass it in within the parenthesis.

If your function has *output*, store its output in a variable; doing so looks like this.

	int myVariable = FunctionName();


### Testing

Test the current functionality before moving on:

1. If you enter an invalid number (-5, 100, etc.) it should display a message and ask the user to re-enter their input.
2. If the user enters invalid input more than once, it should ask them to re-enter their input every time.
3. If the user enters valid input and enters choice 5 (quit), the program should end.

## Iteration 2: Adding Books

---

# Grading Rubric

<table>
	<tr>
		<th>Percentage</th>
		<th>Feature</th>
		<th>Description</th>
	</tr>
	
	<tr>
		<td> 5% </td>
		<td> Code compiles </td>
		<td> Code should build! How are you even testing if you can't build it? </td>
	</tr>
	
	<tr>
		<td> 5% </td>
		<td> Clean code </td>
		<td> Code is easy to read, consistently indented, descriptive variable names used. </td>
	</tr>
	
	<tr>
		<td> 15% </td>
		<td> HP array is being declared and initialized correctly </td>
		<td> Declaring the array, initializing each element of the array to 100 </td>
	</tr>
	
	<tr>
		<td> 10% </td>
		<td> Game loop (while loop) implemented and will eventually end </td>
		<td> Creating a game loop so the game continues until the player either wins or loses </td>
	</tr>
	
	<tr>
		<td> 10% </td>
		<td> Correct if statement check to see if player wins </td>
		<td> Properly checking to see if the player has won </td>
	</tr>
	
	<tr>
		<td> 10% </td>
		<td> "Correct if statement check to see if player loses
(requires using &&)"
 </td>
		<td> Proper logic to see if player has lost </td>
	</tr>
	
	<tr>
		<td> 5% </td>
		<td> Displays the round menu and options menu for player
 </td>
		<td> Display the main menu each cycle of the game loop </td>
	</tr>
	
	<tr>
		<td> 5% </td>
		<td> Gets the user’s input properly
 </td>
		<td> Get the user's input </td>
	</tr>
	
	<tr>
		<td> 10% </td>
		<td> Character is attacked based on player’s input
 </td>
		<td> Accessing the appropriate element of the array and updating it, based on the user's input. </td>
	</tr>
	
	<tr>
		<td> 15% </td>
		<td> For-loop iterates through all NPCs properly (not the player)
 </td>
		<td> Access each element of the array, except for the player character. </td>
	</tr>
	
	<tr>
		<td> 10% </td>
		<td> Each NPC is able to attack correctly
 </td>
		<td> Attacks are done correctly - accessing the correct element. </td>
	</tr>
	

</table>
