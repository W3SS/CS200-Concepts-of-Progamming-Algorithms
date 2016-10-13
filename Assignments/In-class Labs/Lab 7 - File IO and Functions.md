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

# Program : Save a poll's results

For this program, display a poll, allow multiple people to vote, and
then save the results out in a text file.

Create two arrays:

* **votes**: an array of integers of size 3. Initialize all elements to 0.
* **options**: an array of things the user can vote for. Initialize with 3 options.

Create a while loop that will keep running until the user decides to quit.
If the user doesn't quit, it allows them to vote for one of the 3 options.

*Hint: You can use a for-loop to display the indices of each element, and each option.*

When the user selects a vote, increment that vote's count in the **votes** array.

If the user exits, you will leave your program loop. It will then
open a file through **ofstream** and write out the results (both the options and each option's votes).

Make sure to close the file once you're finished.

![Screenshot](images/cl7-00.png)

<details>
	<summary><strong>
		A solution
	</strong></summary>


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

</details>


# Program : Read all contents from a file

# Program : Save and load a list of courses

# Program : Search a text document

# Program : Randomly generated poetry







