# CS 200 Lab 5: While Loops

## Chrome!

Please read this in chrome so that the solutions are collapsed by default!

## Topics

* While Loops
* If Statements
* Input (cin) and Output (cout)

## Turn in

**You will need to upload your code both to the class D2L Dropbox, and to your CS 200 GitHub repository!**

Locate your source files for this project. They should have the extentions .cpp, .hpp, and/or .h. In Windows, they are labelled as "C++ source file" and/or "Header file". 

![Windows, you're annoying.](images/sourcefiles.png)

**These are the only files you need** - You do not need to upload any Visual Studio files.

Upload these source files to your GitHub repository and to the Dropbox.

See also: 
[TURNING IN SOURCE CODE instructions](https://github.com/Rachels-Courses/Course-Common-Files/blob/master/How-to/Turning%20in%20source%20code.md)


## Rules

* Finishing the lab after class:
   * If you are not able to complete the lab during the class period, please finish it up outside of class and turn it in as soon as you can. The lab dropbox will be open for 1 week after the class session.

* Group work:
   * You may work with other students on labs:
   * All people working together must turn in code in their own dropboxes, and upload the code to their own GitHub repositories.
   * All group work must be noted as such - either put a comment in the code file or in the dropbox upload.
   * If you turn in duplicate works without noting that you worked together, you may get a 0% grade.


---

# Assignments

## Project 1: 1 through 10

You will use a while loop to display a list of numbers between 1 and 10, increasing.

1. Create an integer variable called **countUp** and initialize it to 1.

2. Create a while loop. It should loop while **countUp** is less than 11.
Inside the while loop...

	1. Display the current value of **countUp** with a cout statement.
	
	2. Increment the value of **countUp** by one.
	
3. Once the loop has completed, display the message "done!" with cout.

### Knowledge

You can increment variables in a few different ways:

	++countUp; 					// Increment countUp by 1, ++ can only be used for + 1
	countUp++; 					// Increment countUp by 1, ++ can only be used for + 1
	countUp += 1; 				// Increment countUp by 1
	countUp = countUp + 1;		// Increment countUp by 1

### Example output

![Screenshot](images/cl3-00.png)

### Solution

<details>
	<summary><strong><em>
		View the solution
	</em></strong></summary>

	#include <iostream>
	using namespace std;

	int main()
	{
		int countUp = 1;
		
		while ( countUp < 11 )
		{
			cout << countUp << " ";
			countUp++;
		}
		
		cout << endl << endl << "Done!" << endl;
		
		return 0;
	}

</details>

---

## Project 2: 10 through 1

You will use a while loop to display a list of numbers between 10 and 1, decreasing.

1. Create a variable called **countDown** and initialize it to 10.

2. Create a while loop. It should loop while **countDown** is greater than 0.
Inside the while loop...

	1. Display the current value of **countDown** with a cout statement.
	
	2. Increment the value of **countDown** by one.
	
3. One the loop has completed, display the message "done!" with cout.

### Example output

![Screenshot](images/cl3-01.png)

### Solution

<details>
	<summary><strong><em>
		View the solution
	</em></strong></summary>

	#include <iostream>
	using namespace std;

	int main()
	{
		int countDown = 10;
		
		while ( countDown > 0 )
		{
			cout << countDown << " ";
			countDown--;
		}
		
		cout << endl << endl << "Done!" << endl;
		
		return 0;
	}

    
</details>

---

## Project 3: Count by 5's

You will use a while loop to display a list of numbers between 0 and 20,
increasing by 5 each time.

1. Create a variable called **counter** and initialize it to 0.

2. Create a while loop. It should loop while **counter** is less than or equal to 20.
Within the while loop...

	1. Display the current value of **counter** with a cout statement.
	
	2. Increment the value of **counter** by 5. (Add 5 to it).

3. Once the loop has completed, display the message "done!" with cout.

### Example output

![Screenshot](images/cl3-02.png)

### Solution

<details>
	<summary><strong><em>
		View the solution
	</em></strong></summary>

	#include <iostream>
	using namespace std;

	int main()
	{
		int counter = 0;
		
		while ( counter <= 20 )
		{
			cout << counter << " ";
			counter += 5;
		}
		
		cout << endl << endl << "Done!" << endl;
		
		return 0;
	}

    
</details>

---

## Project 4: Number guesser

Write a number-guesser game. The user will continue to guess numbers
until they get it right.
We will use a while loop to have the program keep asking the player for a guess,
until they finally get it right.

For this one, you will need a do-while loop. These look like:

	do
	{
		// code to execute
	} while ( condition );
	
And they are guaranteed to run the internal code *at least once*.

1. Create an integer variable called **secretNumber**, and set it to
your favorite number.

2. Create another integer variable called **playerGuess**. It does not need to be initialized.

3. Create a **do-while** loop. Inside the loop:
	
	1. Display a message to the user, asking them to enter a number guess. (cout)
	
	2. Get the player's guess and store it in the **playerGuess** variable. (cin)
	
	3. Compare the **playerGuess** value to the **secretNumber** value...
	
		1. If playerGuess is less than secretNumber, display the message "too low!"
		
		2. Otherwise, if playerGuess is greater than secretNumber, display the message "too high!"
		
4. At the end of the do-while loop you will put the condition for looping.
Make the condition: while playerGuess is not equal to secretNumber.

5. Outside the do-while loop, display the message "You win!" - this is displayed
once the loop is "escaped", which only happens once the player has 
correctly guessed the number.

### Example output

![Screenshot](images/cl3-03.png)

### Solution

<details>
	<summary><strong><em>
		View the solution
	</em></strong></summary>

	#include <iostream>
	using namespace std;

	int main()
	{
		int secretNumber = 7;
		int playerGuess;
		
		do
		{
			cout << "Enter your guess: ";
			cin >> playerGuess;
			
			if ( playerGuess < secretNumber )
			{
				cout << "Too low!" << endl;
			}
			else if ( playerGuess > secretNumber )
			{
				cout << "Too high!" << endl;
			}
			
		} while ( playerGuess != secretNumber );
		
		cout << "You win!" << endl;
		
		return 0;
	}

    
</details>

---

## Project 5: Input validator

Write a program that will act as an "input validator" for user input.
Basically, it expects the input to be between a certain range,
and if it is not, it requires the user to re-enter their choice.

1. Display a message that says "Please enter a number between 0 and 5."

2. Create a variable called **choice**, which is an integer.

3. Use cin to get the user's input and store it in **choice**.

4. Create a while loop. While **choice** is either
less than 0 or greater than 5...

	1. Display the message "invalid entry. Try again:"
	
	2. Get the user's input again (with cin) and store it in **choice**.

5. Outside of the loop, display the message "Thank you".

### Example output

![Screenshot](images/cl3-04.png)

### Solution

<details>
	<summary><strong><em>
		View the solution
	</em></strong></summary>

	#include <iostream>
	using namespace std;

	int main()
	{

		cout << "Please enter a number between 0 and 5: ";
		
		int choice;
		cin >> choice;
		
		while ( choice < 0 || choice > 5 )
		{
			cout << "Invalid entry. Try again: ";
			cin >> choice;
		}
		
		cout << "Thank you." << endl;
		
		return 0;
	}

</details>




