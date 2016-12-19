# CS 200 Lab 7: File I/O and Functions

Please read this document in Chrome. :)

## Topics

* File input
* File output
* Functions

## Introduction

Functions


## Turn-in

Make sure to upload all your source files (.cpp) to the Dropbox.

When you're uploading your source to the Dropbox, make sure
to also leave a comment with the URL of your repository!

**Add the name of all people in your team in the upload comments**.

Turn in as one source file.

---

# Review

## String Searching

[string::find](http://www.cplusplus.com/reference/string/string/find/)

Remember that strings in C++ have a **find** function.

* Call from: The string you're searching
* Input: Substring to find
* Output: Either:
	* If found: The position of the substring, between 0 and the size of the string, OR
	* If not found: string::npos, which is equivalent to -1.

So if you're searching a string, it would look like this:

	string haystack = "We can dance if we want to";
	string search = "dance";
	
	if ( haystack.find( search ) != string::npos )
	{
		cout << "FOUND" << endl;
	}
	else
	{
		cout << "NOT FOUND" << endl;
	}

## getline and ignore

Remember that if you try to get input from the user like this:

	string input;
	cin >> input;
	
it will automatically break at any whitespace - spaces, tabs, new lines, etc.

If you wanted to get someone to enter a string with spaces, you would need to use
the getline function instead of the input stream operator >>.

	string name;
	getline( cin, name );

When dealing with File I/O, you can also use the variable name of your
file in place of **cin** and use this same function.

## Output file

An output file requires an **ofstream** object:

	ofstream outFile;
	outFile.open( "filename.txt" );
	
	outFile << "Hi!" << endl;
	
	outFile.close();

## Input file

An input file requires an **ifstream** object:

	ifstream inFile;
	inFile.open( "filename.txt" );
	
	string text;
	infile >> text;
	
	inFile.close();

---

# Program 1: Save a poll's results

For this program, display a poll, allow multiple people to vote, and
then save the results out in a text file.

Create two arrays:

* **votes**: an array of integers of size 3. Initialize all elements to 0.
* **options**: an array of things the user can vote for. Initialize with 3 options.

These two arrays are related - one is the labels for what you can vote for,
and the other is the count of votes each option has received.
In the future, we can group these together in one data-type, but for now,
we're just keeping track of two separate arrays for this data.

Create a while loop that will keep running until the user decides to quit.
If the user doesn't quit, it allows them to vote for one of the 3 options.

*Hint: You can use a for-loop to display the indices of each element, and each option.*

When the user selects a vote, increment that vote's count in the **votes** array.

If the user exits, you will leave your program loop. It will then
open a file through **ofstream** and write out the results (both the options and each option's votes).

Make sure to close the file once you're finished.

![Screenshot](images/cl7-00.png)

![Screenshot](images/cl7-01.png)

<details>
	<summary><strong>
		A solution
	</strong></summary>

	#include <iostream>
	#include <fstream>
	#include <string>
	using namespace std;

	int main()
	{
		int votes[3] = { 0, 0, 0 };
		string options[3] = { "cats", "dogs", "ferrets" };

		while ( true )
		{
			cout << endl << endl;
			cout << "Vote: " << endl;
			for ( int i = 0; i < 3; i++ )
			{
				cout << i << ". " << options[i] << endl;
			}
			cout << "3. Quit" << endl;

			cout << "Choice? ";
			int choice;
			cin >> choice;

			if ( choice == 3 )
			{
				break;
			}
			else
			{
				votes[ choice ]++;
			}
		}
		
		ofstream output( "poll-results.txt" );
		
		for ( int i = 0; i < 3; i++ )
		{
			output << options[i] << ": " << votes[i] << endl;
		}
		
		output.close();
		
		return 0;
	}


</details>

---

# Program 2: Read all contents from a file

In your project folder (the same directory as your source files),
create a new .txt file and add the contents:

	The Fox and the Grapes - An Aesop's Fable

	One hot summer's day a Fox was strolling through an orchard till he came to a bunch of Grapes just ripening on a vine which had been trained over a lofty branch.

	"Just the thing to quench my thirst," quoth he.

	Drawing back a few paces, he took a run and a jump, and just missed the bunch.

	Turning round again with a One, Two, Three, he jumped up, but with no greater success.

	Again and again he tried after the tempting morsel, but at last had to give it up, and walked away with his nose in the air, saying:

	"I am sure they are sour."

Name the file whatever you'd like - fable.txt, for example.

Then, in a program, you will write a program to read all the contents from the file,
and display the contents to the screen.

Create a function called **ReadFile**, whose return-type is **void** and
whose **parameter** is a string - the filename.

	void ReadFile( string filename )
	{
	}
	
Remember that functions can't go inside of other functions, so this function
should go above main.

The function will be called within main like this:

	int main()
	{
		ReadFile( "fable.txt" );
		
		return 0;
	}

Where you will pass in the text file - this way, you can keep
calling the function multiple times with different files, without
having to chance the core functionality.

In the **ReadFile** function, create a variable. Its data-type is
**ifstream**, and you can give it any name - I usually go with "input".

You can use the .open() function that belongs to ifstreams to open
a file. Pass in the filename from the function parameters:

	input.open( filename );
	
Next, you will want to create a buffer string to store data as it's 
being read in from the file. Create a string named **lineOfText**.

We can read in *one* line of text like this:

	getline( input, lineOfText );
	
but we want to keep looping for the entire file, until we have reached the end.
To do this, we can use a while loop, and use this **getline** function
as the while loop condition -- it will return *true* if reading a line was
successful, and *false* if it has reached the end of the file.

Within the while loop, simply output the lineOfText to the screen.

After the while loop, make sure to close the input file:

	input.close();


![Screenshot](images/cl7-02.png)

<details>
	<summary><strong>
		A solution
	</strong></summary>

	#include <iostream>
	#include <fstream>
	#include <string>
	using namespace std;

	void ReadFile( string filename )
	{
		ifstream input;
		input.open( filename );
		
		string lineOfText;
		
		while ( getline( input, lineOfText ) )
		{
			cout << lineOfText << endl;
		}
		
		input.close();
	}

	int main()
	{
		ReadFile( "fable.txt" );
		
		return 0;
	}

</details>

---

# Program 3: Search a text document

We will use the *fable.txt* file in this project again. You can modify
the previous program, but make this a new program - you will turn them in
as separate projects.

Change your **ReadFile** function to **SearchFile**. Its parameter list
should have:

* filename (string)
* searchFor (string)

Inside the function, add a new integer variable called **lineCount**
and initialize it to 0. Inside the while loop, increment lineCount
at the end of every cycle.

Instead of displaying each line of text to the screen with cout,
you will remove that line and only display lines that have the
item being searched for.

Inside the while loop, use the **find()** function on the lineOfText
to search for the **searchFor** string. If it is found,
display the line # and the string of text.

Back in **main**, update it to ask the user what to search for.
Store their answer in a string. You will also pass this string into
the **SearchFile** function as the 2nd argument.

![Screenshot](images/cl7-06.png)

<details>
	<summary><strong>
		A solution
	</strong></summary>

	#include <iostream>
	#include <fstream>
	#include <string>
	using namespace std;

	void SearchFile( string filename, string searchFor )
	{
		ifstream input;
		input.open( filename );
		
		string lineOfText;
		
		int lineCount = 0;
		while ( getline( input, lineOfText ) )
		{		
			if ( lineOfText.find( searchFor ) != string::npos )
			{
				cout << "FOUND AT LINE " << lineCount << ": " << lineOfText << endl << endl;
			}
			
			lineCount++;
		}
		
		input.close();
	}

	int main()
	{
		string searchFor;
		cout << "Search for what? ";
		cin >> searchFor;
		
		SearchFile( "fable.txt", searchFor );
		
		return 0;
	}


</details>


---

# Program 4: Randomly generated poetry

Create two text files for this one. Add as many words as you want to these files!

nouns.txt:

	roses
	violets
	sugars
	cats
	dogs
	pizzas
	computers
	robots
	dinosaurs

adjectives.txt:

	red
	blue
	sweet
	gigantic
	electronic
	tasty
	friendly
	cute

We will need three functions for this program:

* LoadNouns
	* return type: void
	* parameters:
		* string array of nouns, size 100
		* integer nounCount, passed by reference
* LoadAdjectives
	* return type: void
	* parameters:
		* string array of adjectives, size 100
		* integer adjectiveCount, passed by reference
* GeneratePoem
	* return type: string
	* parameters:
		* string array of nouns, size 100
		* integer nounCount
		* string array of adjectives, size 100
		* integer adjectiveCount

When something is "passed by reference", this means we want to be able
to change its value within the function. Normally, non-array variables
are passed *by value* by default, so a *copy* is made of that variable
when the function is called, and the changes don't get "saved" back
at the caller's level.

Your function definitions should look like this:

	void LoadNouns( string nouns[100], int & nounCount )
	{
	}

	void LoadAdjectives( string adjectives[100], int & adjectiveCount )
	{
	}

	string GeneratePoem( string nouns[100], int nounCount, string adjectives[100], int adjectiveCount )
	{
	}

### main:

First, within main, seed a random number generator:

	srand( time( NULL ) );

(You will need to include cstdlib and ctime libraries!)

	#include <cstdlib>
	#include <ctime>

Then, create some variables:

* a string array of nouns, size 100
* an integer called nounCount
* a string array of adjectives, size 100
* an integer called adjectiveCount

Call the **LoadNouns** function, passing in your noun array and nounCount,
followed by a call to **LoadAdjectives**, passing in the adjective array and adjectiveCount.

Afterwards, create a **string variable** called **poem**.
Call the **GeneratePoem** function, and assign its return value to your poem variable.

Finally, use **cout** to display the random poem to the screen.

### Load Nouns:

1. Create an **ifstream** variable and load in the *nouns.txt* file.
2. Initialize the **nounCount** parameter to 0.
3. Create a string buffer.
4. While we are getting input from the ifstream variable, into the string buffer...
	5. Copy the contents from the buffer into the array at the proper position.
	( nouns[ nounCount ] = buffer; )
	6. Increment the nounCount by 1.
5. After the array is done, close the ifstream variable.

Your LoadAdjectives function will be almost the same, but with different variables!

### Generate Poem:

We are going to copy the format of

	roses are red,
	violets are blue,
	sugar is sweet,
	and so are you!

So instead, we'll do something like:

	random-nouns are random-adjective,
	random-nouns are random-adjective,
	random-nouns are random-adjective,
	and so are you!

Start off by creating a local string variable called **poem**. Initialize it to an empty string.

Build one line of the poem at a time. Remember that the amount of elements in the noun array
is between 0 and *nounCount*. You can get a random noun index through rand():

	int randomNoun = rand() % nounCount;

Then, you can access the *string* (the noun itself) with:

	nouns[ randomNoun ]

so you'll be building the poem line by line:

	int randomNoun = rand() % nounCount;
	int randomAdj = rand() % adjectiveCount;

	poem += nouns[ randomNoun ] + " are " + adjectives[ randomAdj ] + ", \n";

...and so on.


![Screenshot](images/cl7-07.png)

<details>
	<summary><strong>
		A solution
	</strong></summary>

	#include <iostream>
	#include <fstream>
	#include <string>
	#include <cstdlib>
	#include <ctime>
	using namespace std;

	void LoadNouns( string nouns[100], int & nounCount )
	{
		ifstream input( "nouns.txt" );
	
		nounCount = 0;
	
		string buffer;
		while ( input >> buffer )
		{
			nouns[ nounCount ] = buffer;
			nounCount++;
		}
	
		input.close();
	}

	void LoadAdjectives( string adjectives[100], int & adjectiveCount )
	{
		ifstream input( "adjectives.txt" );
	
		adjectiveCount = 0;
	
		string buffer;
		while ( input >> buffer )
		{
			adjectives[ adjectiveCount ] = buffer;
			adjectiveCount++;
		}
	
		input.close();
	}

	string GeneratePoem( string nouns[100], int nounCount, string adjectives[100], int adjectiveCount )
	{
		string poem = 	nouns[ rand() % nounCount ] + " are " +
						adjectives[ rand() % adjectiveCount ] + ", \n" +
						nouns[ rand() % nounCount ] + " are " +
						adjectives[ rand() % adjectiveCount ] + ", \n" +
						nouns[ rand() % nounCount ] + " are " +
						adjectives[ rand() % adjectiveCount ] + ", \n" +
						"and so are you!";
		return poem;
	}


	int main()
	{
		srand( time( NULL ) );
	
		string nouns[100];
		int nounCount;
		string adjectives[100];
		int adjectiveCount;
	
		LoadNouns( nouns, nounCount );
		LoadAdjectives( adjectives, adjectiveCount );
	
		string poem = GeneratePoem( nouns, nounCount, adjectives, adjectiveCount );
	
		cout << "RANDOM POEM:" << endl;
		cout << poem << endl;
	
		return 0;
	}



</details>

---

# Program 5: Save and load a list of courses

Create a text file of courses that contains the following:

	CS134
	CS200
	CS201
	CS205
	CS210
	CS211
	CS225
	CS235
	CS236
	CS250
	CS255

Remember that the text file needs to go in the same directory as the
source files!

Create two functions in your program:

1. LoadClasses
	1. Return type: int
	2. Parameters:
		1. A string array of classes, of size 100.
2. SaveClasses
	1. Return type: void
	2. Parameters:
		1. A string array of classes, of size 100.
		2. An integer of the class count.
		
Your function signatures should look like this:

	int LoadClasses( string classes[100] )
	{
	}

	void SaveClasses( string classes[100], int classCount )
	{
	}
	
Remember that when we have arrays as function parameters, they are passed
*by reference* automatically, so we can make changes to the array
and those changes will be preserved at the caller-level (in our case,
we will eventually call it from main.)


### main:

Copy this code into main:

	int main()
	{
		string classes[100];
		int classCount = LoadClasses( classes );
		
		for ( int i = 0; i < classCount; i++ )
		{
			cout << i << ". " << classes[i] << endl;
		}
		
		cout << "Edit which class? ";
		int edit;
		cin >> edit;
		
		cout << "New class name? ";
		cin >> classes[edit];
		
		SaveClasses( classes, classCount );
		
		return 0;
	}

We are creating an array of strings to store class names. We don't know
how many classes are in the text file, so we're high-balling it with 
a size of 100.

We also need to keep track of the actual *classCount*, because we could have
anywhere between 0 and 100 items in our list.

The **LoadClasses** function is called, and it will return the amount of
classes loaded in, so we need to store this in a variable, so we are storing
it in **classCount**.

Next, we have a for-loop to display all of the courses and their index # in the array.

We ask the user what class they want to edit, and then what they want to change
the course's name to.

Afterward, we call **SaveClasses** to save the changes. We pass in the
array of classes *and* the classCount, because otherwise it wouldn't know
how many items to output.

### LoadClasses function:

1. Create an **ifstream** object and open the *courses.txt* file (or whatever you saved it as.)
2. Create an integer variable to count how many courses are loaded in from the text file. Initialize it to 0.
3. Create a string "buffer" variable to store class names into before we store them in the array.
4. Create a while-loop that will continue looping while we're getting input from the **input** ifstream variable and storing it
	in the **buffer** string variable.
	
In the loop, the buffer variable is storing the current class read in at this point. You will need to store it into the array.
You can save it at the correct position by using your *counter* integer variable.

For example:

	classes[counter] = buffer;
	counter++;

After the loop is finished, make sure to **close** the ifstream object,
and then **return** the counter variable.

### SaveClasses function:

1. Create an **ofstream** object and open the *courses.txt* file.
2. Use a for-loop to iterate through every element of the array: from 0 to the classCount.
	1. Within the loop, output the class at the current position (for example, classes[i]).
	Make sure you're outputting it to your ofstream, *not* your cout.
3. After the loop is done, make sure to close your ofstream object.

Solution is below if you need additional help.

#### Screenshots

Original text file:

![Original text file](images/cl7-03.png)

Program run:

![Program run](images/cl7-04.png)

New text file:

![New text file](images/cl7-05.png)

<details>
	<summary><strong>
		A solution
	</strong></summary>

	#include <iostream>
	#include <fstream>
	#include <string>
	using namespace std;

	int LoadClasses( string classes[100] )
	{
		ifstream input( "courses.txt" );
		
		int index = 0;
		string buffer;
		
		while ( input >> buffer )
		{
			classes[index] = buffer;
			index++;
		}
		
		input.close();
		
		return index;
	}

	void SaveClasses( string classes[100], int classCount )
	{
		ofstream output( "courses.txt" );
		
		for ( int i = 0; i < classCount; i++ )
		{
			output << classes[i] << endl;
		}
		
		output.close();
	}

	int main()
	{
		string classes[100];
		int classCount = LoadClasses( classes );
		
		for ( int i = 0; i < classCount; i++ )
		{
			cout << i << ". " << classes[i] << endl;
		}
		
		cout << "Edit which class? ";
		int edit;
		cin >> edit;
		
		cout << "New class name? ";
		cin >> classes[edit];
		
		SaveClasses( classes, classCount );
		
		return 0;
	}


</details>








