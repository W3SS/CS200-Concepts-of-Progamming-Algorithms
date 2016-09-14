# Debugging Homework Assignment

## Introduction

This assignment will step you through using the debugging tools in Visual Studio and Code::Blocks.

You will also have to solve some programming problems and figure out why they're not working as expected!

## Turn-in

Once you're done fixing the different assignments, you will turn in each of the source files to the class Dropbox.


## Group Policy

* This is a solo-effort project.
* You can verbally collaborate with classmates.

---

# Part 1: Debugging Tools

---

# Part 2: Debugging

These small programs contain common programming mistakes. It's your job to investigate these mistakes and correct them so that they perform the expected functionality!

## Program 1: Write out the age!

### Expected functionality

This program gets the user's input (age). After the input is entered, it should check to see if the age is 13, 18, or 21.

If the age is 13, it should display "Thirteen".
If the age is 18, it should display "Eighteen".
If the age is 21, it should display "Twenty One".


### Actual functionality

When the program is run, output looks like this:

	Enter your age: 18
	ThirteenEighteenTwenty One

Fix the program so that it only displays the appropriate output.

**HINT** - You do not need to change these if statements to if / else if statements; that is not where the functionality is going wrong.

**HINT** - You should only need to make changes to three lines of code to fix this problem.


### Entire program

	#include <iostream>
	using namespace std;
	
	int main()
	{
	    int age;
		cout << "Enter your age: ";
		cin >> age;
	
	    if ( age = 13 )
	    {
	        cout << "Thirteen";
	    }
	
	    if ( age = 18 )
	    {
	        cout << "Eighteen";
	    }

		if ( age = 21 )
		{
			cout << "Twenty One";
		}
	
	    return 0;
	}

---

## Program 2: Input Validation

### Expected functionality

This program asks the user to enter a number between 1 and 3. If the user enters a number outside this range, it will keep asking them to input another number until they enter something valid.

After something valid is entered, it will tell the user what their pick was.

### Actual functionality

Invalid input is not detected and the program continues executing either way.

**HINT** - You should only have to fix one line of code to fix this program.

**HINT** - The while loop is *never* executing its contents - this means that the condition it is checking is never *true*.

### Entire program


	#include <iostream>
	using namespace std;
	
	int main()
	{
		cout << "Enter a number between 1 and 3: ";
	
		int choice;
		cin >> choice;
	
		int min = 1;
		int max = 3;
		while (choice < min && choice > max)
		{
			cout << "Invalid, try again:" << endl;
			cin >> choice;
		}
	
		cout << "You chose " << choice << endl;
	
		return 0;
	}

---

## Program 3: Input Validation #2

### Expected functionality

This program asks the user to enter "y" or "n". If the user enters something besides one of these two, it should display an error and ask the user to try again.

Once the user has entered valid input, it should display their choice.

### Actual functionality

The program never continues and is stuck in the while loop, even if you type y or n.

**HINT** - You should only have to fix one line of code to fix this program.

**HINT** - The while loop is *always* executing its contents - this means that the condition it is checking is never *false*, so it never leaves the loop.

### Entire program

	#include <iostream>
	using namespace std;
	
	int main()
	{
		char choice = ' ';
		cout << "What is your choice?" << endl;
		cin >> choice;
	
		while (choice != 'y' || choice != 'n')
		{
			cout << "Invalid try again: ";
			cin >> choice;
		}
	
		cout << "Choice was: " << choice << endl;
	
		return 0;
	}

---

## Program 3: Quantity

### Expected functionality

This program asks the user how much of something they are buying. If they buy over 10 items, they get a discount to $5 each. Otherwise, the standard price is $10 each.

### Actual functionality

The program gives them the discount no matter what.

Output:

	What is the quantity? 2
	Price:    $5
	Quantity: 2
	Total:    $10

**HINT** - You should only have to fix one line of code to fix this program.

**HINT** - There is something wrong with the syntax. Why is the if statement's price override always occurring?

### Entire program

	#include <iostream>
	using namespace std;
	
	int main()
	{
		float price = 10;
		int quantity;
	
		cout << "What is the quantity? ";
		cin >> quantity;
	
		// Give a discount for bulk
		if (quantity > 10);
		{
			price = 5;
		}
	
		cout << "Price:    $" << price << endl;
		cout << "Quantity: " << quantity << endl;
		cout << "Total:    $" << (price * quantity) << endl;
	
		return 0;
	}