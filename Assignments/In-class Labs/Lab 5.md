# CS 200 Lab 5: A mishmash of things

Please read this document in Chrome. :)

## Topics

* For-Loops
* Arrays
* Strings

## Introduction

This lab has several parts, and covers an introduction to each topic, 
and then combines them into bigger problems.

## Turn-in

Make sure to upload all your source files (.cpp) to the Dropbox.

When you're uploading your source to the Dropbox, make sure
to also leave a comment with the URL of your repository!

**Add the name of all people in your team in the upload comments**.

You can either combine all the practices in one source file,
or create separate ones!

---

## Part 1: Strings

* [String reference documentation](http://www.cplusplus.com/reference/string/string/)

The C++ String class has several functions to work with strings,
such as finding a substring in a larger string (like "cat" in "cathode"), getting the length of a string, getting specific characters or letters at some position in a string, and more.

To use the String library, you have to include it:

	#include <string>
	using namespace std;

### Using cin with a string

You can use **cin** on a string just like you do with an integer:

	cin >> myString;

However, this will only allow the user to enter one word; this method
will cut off at any whitespace: tabs, new lines (enter), or spaces. So in order to get a person's first and last name, it would look like this:

	string firstName, lastName;

	cout << "Enter your first name: ";
	cin >> firstName;

	cout << "Enter your last name: ";
	cin >> lastName;

(And, this won't work if there is a space in the last name!)

In order to get a **line** of text as user input, we have to use **cin** a little bit differently:

	string fullname;
	cout << "Enter your full name: ";
	getline(cin, fullname);

However, if you intermix **cin >>** and **getline(cin, ...)**, you will run into some bugs in your program!

To stay safe, if you're going to use **getline** in your program, make sure to add:

	cin.ignore();

after any **cin >>** statement.

#### Practice 1A. Ping a website

1. Create a **string** named **website**.
2. Ask the user to enter a short website URL (cout).
3. Get the user's input and store it in string (cin>>)
4. Create a second **string** variable named **command**.
5. Set command equal to "ping ", and then concatenate your website at the end:
	1. To concatenate two strings (combine two strings), you use the + sign. You can do this between string literals (in "") and variables.
	2. command = "ping " + website;
	3. Make sure ping has a space after it.
6. Run the following command:
	1. system(command.c_str());

Sample output:

	Enter a website: yahoo.com
	
	Pinging yahoo.com [98.138.253.109] with 32 bytes of data:
	Reply from 98.138.253.109: bytes=32 time=52ms TTL=48
	Reply from 98.138.253.109: bytes=32 time=52ms TTL=48
	Reply from 98.138.253.109: bytes=32 time=60ms TTL=48
	Reply from 98.138.253.109: bytes=32 time=52ms TTL=48
	
	Ping statistics for 98.138.253.109:
	    Packets: Sent = 4, Received = 4, Lost = 0 (0% loss),
	Approximate round trip times in milli-seconds:
	    Minimum = 52ms, Maximum = 60ms, Average = 54ms


<details>
	<summary><strong>
		The end should result should look like this.
	</strong></summary>

	#include <iostream>
	#include <string>
	using namespace std;
	
	int main()
	{
		string website;
		cout << "Enter a website: ";
		cin >> website;
	
		string command = "ping " + website;
		 
		system(command.c_str());
	
		return 0;
	}
</details>

It will ask the user for a URL, and then run the **ping** command that you can access from MS DOS or your system terminal. (The "system" command executes programs and commands that are accessible from the terminal.)

**Note:** You don't need to know how to use the system() command for this class - it is just a fun thing to mess with!

#### Practice 1B. Concatenate a name

1. Create two **strings**: firstName and lastName.
2. Ask the user to enter the firstName and lastName - you can either use two cin>> statements or two getline statements.
3. Create a third **string**: formattedName.
4. Assign formattedName the value of **lastName**, then a comma, then the **firstName** by using + to concatenate strings.
5. Display the formattedName to the user.

Sample output:

	Enter your first name: Morris
	Enter your last name: Rachel
	Formatted: Morris, Rachel


<details>
	<summary><strong>
		Program solution
	</strong></summary>

	#include <iostream>
	#include <string>
	using namespace std;
	
	int main()
	{
		string firstName, lastName;
	
		cout << "Enter your first name: ";
		cin >> firstName;
	
		cout << "Enter your last name: ";
		cin >> lastName;
	
		string formattedName;
		formattedName = lastName + ", " + firstName;
	
		cout << "Formatted: " << formattedName << endl;
	
		return 0;
	}
</details>

#### Practice 1C. cin>> and getline mixed together

1. Create two strings: **note** and **filename**.
2. Ask the user to enter a filename (cout).
3. Get the user's input and store it in filename via the **cin>>** command.
4. Make sure to call **cin.ignore();** immediately after the cin.
5. Ask the user to enter their note (cout).
6. Get the user's input and store it in note via the **getline( cin, ...)** function.
7. Create a new string called **command**.
8. Assign **command** a value (see below).
9. Use a system call to run the command (see below).

Command code:

	string command = "echo \"" + note + "\" > " + filename;
	system(command.c_str());


Sample output:

	Filename: hello.txt
	Note: How are you today?

And it generates this file:

![File screenshot](images/cl5-00.png) 
![File screenshot](images/cl5-01.png)

<details>
	<summary><strong>
		Program solution
	</strong></summary>

	#include <iostream>
	#include <string>
	using namespace std;
	
	int main()
	{
		string note, filename;
		cout << "Enter a filename: ";
		cin >> filename;
		cin.ignore();
	
		cout << "Enter a note: ";
		getline(cin, note);
	
		string command = "echo \"" + note + "\" > " + filename;
		system(command.c_str());
	
		return 0;
	}
</details>

#### Practice 1D. Search for a string

The C++ String class has a function called [**find**](http://www.cplusplus.com/reference/string/string/find/), which allows you to find a character or a substring inside of another string.

The reference docs list the function spec:

	size_t find (const string& str, size_t pos = 0) const;

and we will look at how to use it.

1. First, create two strings: **sentence** and **searchFor**.
2. Hard code **sentence** to some phrase or sentence. e.g., "Why bother with subroutines when you can type fast? - Vaughn Rokosz"
3. Ask the user to enter a term to search for (cout).
4. Get the user's input and store it in searchFor with a getline statement.
5. Then we're going to look for the item... In a moment...

##### How find works

The **find** function is written so that it will return the *index* at which a character or word is found in the sentence. For example, if we search for "Why", it is at position 0. If we search for "bother", its position is at 4.

If the word is not found in the string, it will return a -1. C++ also gives this value a name: **string::npos** (no-position) which is a better keyword to use when doing a search for a string.

Practice with these commands first:

	int whyPosition = sentence.find("Why");
	cout << "Why is at: " << whyPosition << endl;

This will display a position of 0 for "Why".

	int fastPosition = sentence.find("fast");
	cout << "fast is at: " << fastPosition << endl;

"fast" is at position 46.

Note that this is also case-sensitive!

If we do a search for a term that isn't found, it will return -1:

	int kittensPosition = sentence.find("kittens");
	cout << "kittens is at: " << kittensPosition << endl;

Again, an **alias** for this is **string::npos**.

Now, with this information we can write an if statement to see if
something is not found...:

	int kittensPosition = sentence.find("kittens");
	cout << "kittens is at: " << kittensPosition << endl;

	if (kittensPosition != string::npos)
	{
		cout << "Found" << endl;
	}

If the position is **not equal to "no position" (string::npos)**, then it is found. Another way you could check is:

	if (kittensPosition >= 0)
	{
		cout << "Found" << endl;
	}

If the position of the found word is at 0, or some greater index,
then it is in the string.

##### Back to the program

Now we want to try to find the item the user is searching for, and either tell them if it was found, or not...:

1. Create an integer called **foundPosition**.
2. Assign foundPosition to: **sentence.find(searchFor)**.
3. If foundPosition **is not string::npos**:
	1. Display "found at", and then display the foundPosition.
4. Otherwise:
	1. Display "not found".

Were you able to figure it out? Solution below...

<details>
	<summary><strong>
		Program solution
	</strong></summary>

	#include <iostream>
	#include <string>
	using namespace std;
	
	int main()
	{
		string sentence = "Why bother with subroutines when you can type fast? - Vaughn Rokosz";
		string searchFor;
	
		cout << "What do you want to search for? ";
		getline(cin, searchFor);
	
		int foundPosition = sentence.find(searchFor);
		if (foundPosition != string::npos)
		{
			cout << "Found at " << foundPosition << endl;
		}
		else
		{
			cout << "Not found" << endl;
		}
	
		return 0;
	}
</details>

---

## Part 2: Arrays

An array is a list of items - it can be any data-type, but an array must only contain one data-type (e.g., an array of ints can only contain ints).

An array has **elements**, where each element is essentially a single variable of the specified data-type.

Each **element** has a position in the array, otherwise known as an **index**.

The first element of the array is at position 0.

If an array is of size *n*, then the last element of the array is at position *n-1*.

So if we **declare** an array of 3 prices:

	float prices[3];

we have 3 prices, so we will have access to elements:

	prices[0] = 9.99;
	prices[1] = 8.99;
	prices[2] = 6.99;

But **prices[3]** is **NOT VALID**! If the size of your array is 3 and you try to access index 3, your program will crash - and this is a pretty common mistake! Keep an eye out!

These *static* arrays cannot be resized, either, so we need to know
what their size will be when we're writing the code. (There are *data structures* that exist to alleviate this problem further down the road!)

### Practice 2A. Create an array of names

1. Declare an array. Its data type is **string**, the name of the variable is **names**, and it is of size 5.
2. Assign the first element of the array (at index 0) the value of "Xia".
3. Assign the second element of the array (at index 1) the value of "Shang".
3. Assign the third element of the array (at index 2) the value of "Zhou".
3. Assign the fourth element of the array (at index 3) the value of "Qin".
3. Assign the fifth element of the array (at index 4) the value of "Han".
1. After assigning all of these elements, display every element to the screen with cout.

Sample Output:

	Xia
	Shang
	Zhou
	Qin
	Han

<details>
	<summary><strong>
		Program solution
	</strong></summary>

	#include <iostream>
	#include <string>
	using namespace std;
	
	int main()
	{
		string names[5];
		names[0] = "Xia";
		names[1] = "Shang";
		names[2] = "Zhou";
		names[3] = "Qin";
		names[4] = "Han";
	
		cout << names[0] << endl
			<< names[1] << endl
			<< names[2] << endl
			<< names[3] << endl
			<< names[4] << endl;
	
		return 0;
	}
</details>

### Note: Keeping track of the array size

C++ doesn't automatically keep track of how many elements are in the array, so we will have to keep track of the size ourselves with an integer variable.

We can also use a variable to get an element of the list, rather than using hard-coded numbers like names[0], names[1]. If a variable is an integer, we can access a specific element of the list like: **names[varName]**.

	int current = 2;
	cout << names[ current ] << endl;
	// This displays item at index 2.

### Practice 2B. Keeping track of the amount of items in the list

Modify 2A to do the following:

1. Erase the cout with all the elements - we are going to do this with a loop.
2. Create a variable called **index**, and assign it to 0.
3. Create a variable called **arraySize**, and assign it to 5.
4. Create a while loop. Its condition will be, "continue looping while index is less than arraySize". Within the loop:
	1. Display the array element at position *index*.
	2. Increment index by 1.

<details>
	<summary><strong>
		Program solution
	</strong></summary>

	#include <iostream>
	#include <string>
	using namespace std;
	
	int main()
	{
		string names[5];
		names[0] = "Xia";
		names[1] = "Shang";
		names[2] = "Zhou";
		names[3] = "Qin";
		names[4] = "Han";
	
		int index = 0;
		int arraySize = 5;
	
		while (index < arraySize)
		{
			cout << names[index] << endl;
			index++;
		}
	
		return 0;
	}
</details>

### Note: Creating arrays that are bigger than we need

Sometimes, we might create an array that is bigger than what we actually need. Because we can't resize the arrays while the program is running, we have to overshoot the amount of items we need so that we can store everything.

Because of this, we might have 100 elements but only be storing information in, say, items 0 through 15. Any elements after position 15 will have "garbage data" in them because they haven't been initialized.

This is fine - but we now also have to keep track of the items in our list, as well as the array size.

Therefore, for our list of 100 names, with only 15 names currently being stored in it, our **arraySize** integer variable would be 100, and our **itemCount** integer variable would be 15.

This also helps because we can check to see if an array is full before adding a new item: if **arraySize == itemCount**, then the array is full, and don't allow any more items added to the list.

Second, **itemCount** is useful because it also ends up tracking **the next available index** in the array: it starts at 0, we add our first item at position 0, then it increments to 1, which is where we will add our next item.

Here is some sample code:

	string names[5];		// Create an array of size 5
	int arraySize = 5;		// Keep track of the array size with this
	int itemCount = 0;		// Keep track of the amount of items with this

	// While the array is not full, add items to the list.
	while (itemCount != arraySize)
	{
		// Ask the user to enter item #___:
		cout << "Enter name " << itemCount << ": ";

		// Get the user's input and store it in the array at the
		// next available position.
		cin >> names[itemCount];

		// Add to the amount of total items we have.
		itemCount++;
	}

It might take some practice to get used to, so let's get to it!

### Practice 2C: Two arrays

1. Declare an array of strings. Its name is **items** and its size is 3.
2. Declare an array of floats. Its name is **prices** and its size is 3.
3. Declare an integer named **arraySize**. Set it to 3.
4. Declare an integer named **itemCount**. Set it to 0.
5. Create a while loop... while the itemCount is less than the arraySize:
	1. Display a message to the user: "Enter item name: " (cout)
	2. Get the user's input and store it in **items** at the position **itemCount**. (cin)
	3. Display a message to the user: "Ener price: "
	4. Get the user's input ands tore it in the **prices** array at the position **itemCount**
	5. Add 1 to **itemCount**
6. Once that while loop is finished, declare a new integer variable named **counter** and initialize it to 0.
7. Create a second while loop... while the counter is less than itemCount:
	1. Display the item # (counter), and then the item name and item price.
	Use the counter variable to access one item of the array.
	2. Increment counter by 1.
	
In each case, the loop is written to access one element of the array at a time.
The loop cycles 3 times, going from 0, 1, and 2, and allows us to access
every element of the array through variables instead of manually
adding things by hard-coding them.

Sample output:

	Enter item name: hamburger
	Enter price: 5.99
	Enter item name: burrito
	Enter price: 3.99
	Enter item name: churro
	Enter price: 0.99

	Item #0: hamburger, $5.99
	Item #1: burrito, $3.99
	Item #2: churro, $0.99


<details>
	<summary><strong>
		Program solution
	</strong></summary>

	#include <iostream>
	#include <string>
	using namespace std;

	int main()
	{
		string items[3];
		float prices[3];
		int arraySize = 3;
		int itemCount = 0;
		
		while ( itemCount < arraySize )
		{
			cout << "Enter item name: ";
			cin >> items[itemCount];
			cout << "Enter price: ";
			cin >> prices[itemCount];
			itemCount++;
		}
		
		cout << endl;
		
		int counter = 0;
		while ( counter < itemCount )
		{
			cout << "Item #" << counter << ": " << items[counter] << ", $" << prices[counter] << endl;
			counter++;
		}
		
		return 0;
	}

</details>

---

## Part 3: For-Loops

For-loops are another type of loop. They generally will use integers (but can use other data types)
and make it easy to specify a begin #, an end #, and some amount to change by each time - all within the
same line of code.

	for ( int i = 0; i < 10; i++ )
	{
		// ...
	}
	
There are three sections within the ( ) of a for-loop:

1. Declaring (and/or) initializing a counter variable.
2. Specifying the condition for how long it will loop (similar to while loop)
3. After the loop executes, this third part is executed: usually used to increment the counter variable.

### Practice 3A. Iterating from 1 to 100

Write a for-loop that begins at 1, ends at 100 (inclusive), and goes up by 5 each time.

Within the loop, output the value of your counter.

Sample output:

	1 6 11 16 21 26 31 36 41 46 51 56 61 66 71 76 81 86 91 96 

<details>
	<summary><strong>
		Program solution
	</strong></summary>

	#include <iostream>
	#include <string>
	using namespace std;

	int main()
	{
		for ( int i = 1; i <= 100; i += 5 )
		{
			cout << i << " ";
		}
		
		return 0;
	}
</details>

### Practice 3B. Iterating from 20 to 0

Write a for-loop that begins at 20 and ends at 0 (exclusive), and goes down by 1 each time.

Sample output:

	20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1 

<details>
	<summary><strong>
		Program solution
	</strong></summary>

	#include <iostream>
	#include <string>
	using namespace std;

	int main()
	{
		for ( int i = 20; i > 0; i-- )
		{
			cout << i << " ";
		}
		
		return 0;
	}
</details>



### Practice 3C. Using a for-loop with an array

For the following code:

	#include <iostream>
	#include <string>
	using namespace std;

	int main()
	{
		string letters[5] = { "A", "B", "C", "D", "E" };
		
		return 0;
	}

Add a for loop that iterates over every element of the **letters** array
and displays it to the screen.

<details>
	<summary><strong>
		Program solution
	</strong></summary>

	#include <iostream>
	#include <string>
	using namespace std;

	int main()
	{
		string letters[5] = { "A", "B", "C", "D", "E" };
		
		for ( int i = 0; i < 5; i++ )
		{
			cout << letters[i] << endl;
		}
		
		return 0;
	}
</details>


### Practice 3D. More for loops with an array

Modify 2C to use two for-loops instead of two while-loops

<details>
	<summary><strong>
		Program solution
	</strong></summary>

	#include <iostream>
	#include <string>
	using namespace std;

	int main()
	{
		string items[3];
		float prices[3];
		int arraySize = 3;
		int itemCount = 0;
		
		for ( itemCount = 0; itemCount < arraySize; itemCount++ )
		{
			cout << "Enter item name: ";
			cin >> items[itemCount];
			cout << "Enter price: ";
			cin >> prices[itemCount];
			itemCount++;
		}
		
		cout << endl;
		
		for ( int counter = 0; counter < itemCount; counter++ )
		{
			cout << "Item #" << counter << ": " << items[counter] << ", $" << prices[counter] << endl;
			counter++;
		}
		
		return 0;
	}
</details>

### Practice 3E. More loops with an array!

For the following code:

	#include <iostream>
	#include <string>
	using namespace std;

	int main()
	{
		string cities[20];
		int arraySize = 20;
		cities[0] = "Lee's Summit";
		cities[1] = "Raytown";
		cities[2] = "Independence";
		cities[3] = "Belton";
		int itemCount = 4;
		
		return 0;
	}

Write a for-loop that iterates over all elements of the array that contain a value,
displaying the value of each element.

<details>
	<summary><strong>
		Program solution
	</strong></summary>

	#include <iostream>
	#include <string>
	using namespace std;

	int main()
	{
		string cities[20];
		int arraySize = 20;
		cities[0] = "Lee's Summit";
		cities[1] = "Raytown";
		cities[2] = "Independence";
		cities[3] = "Belton";
		int itemCount = 4;
		
		for ( int i = 0; i < itemCount; i++ )
		{
			cout << cities[i] << endl;
		}
		
		return 0;
	}

</details>



---
