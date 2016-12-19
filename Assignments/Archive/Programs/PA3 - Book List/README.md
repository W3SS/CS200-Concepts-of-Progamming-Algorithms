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

The final version of this program will store a list of books on the hard drive and
load in that list any time the program begins. It allows the user to add new books
to the list, or update current books, as well as get stats on the books,
export special book lists to CSV files.

It will offer a clean user interface to allow the user to navigate 
through their books and the options for their book list.

Since this program has a lot of features, we will cover things *iteratively*,
and work on some of these features during class. It is better to work on
a few features at a time and test, rather than trying to implement the entire thing at once.

![Screenshot](images/mainmenu.png)

---

# Iteration 1: Book Objects

First, we are going to start out by creating a Book object. We will be using a struct
in order to create our "Book" data-type. The Book will contain the title,
author, and "reading status" and "purchase status".

## Enumerations: ReadingStatus and PurchaseStatus

Enumerations are helpful because they allow us to give text labels to
integers. Generally, it is a bad idea to store fields as strings, because
it is prone to typos and hard to make sure that all the string fields are
consistent throughout the program.

By using enumerations, the compiler will complain if we use a label that
is not recognized, so it also offers an extra layer of protection for us
from logic errors.

We are going to need two enumerations: One for the purchase status, and one for the reading status.
They will be written like this, toward the top of the .cpp file (above main):

	enum ReadingStatus {  NOT_STARTED = 0, READING = 1, FINISHED = 2 };
	enum PurchaseStatus { OWNED = 0, WISHLIST = 1 };
	
We use enumerations similarly to variables. You could declare a variable like this:

	ReadingStatus rs = NOT_STARTED;
	
or you can **cast** an integer to an enumeration:

	int userInput = 2;
	ReadingStatus rs = (ReadingStatus)userInput;
	
Our Book object will contain these two enumerations to keep track of each Book's status.

## Struct: Book

![Cute](https://github.com/Rachels-Courses/Course-Common-Files/blob/master/Artwork/Cuties/book-cute.png?raw=true)

Our Book struct will contain the title, author, and purchase and reading status.
The struct declaration will also be above main, but below the enumeration declarations.

	struct Book
	{
		string title;
		string author;
		ReadingStatus readingStatus;
		PurchaseStatus purchaseStatus;
	};

Now we've essentially made our own *Book* data type, and can declare books like this:

	Book myBook;
	myBook.title = "A history of dinosaurs";
	myBook.author = "ME!";
	myBook.readingStatus = FINISHED;
	myBook.purchaseStatus = OWNED;
	
All of the *internal member variables* of the Book object must be accessed through
the dot operator "."

## Helper Functions: ReadingStatusString and PurchaseStatusString

If we try to *cout* a PurchaseStatus or ReadingStatus...

	PurchaseStatus ps = OWNED;
	cout << ps << endl;
	
it will only display the number value it is associated with:

	0
	
So, if we want *user-friendly* labels for these, we need to write a 
function that take in a ReadingStatus or PurchaseStatus, and return
a string, the user-friendly label.

### ReadingStatusString

* Return type: string
* Parameters:
	* rs, a ReadingStatus

Use an if-statement to check for all possible values of ReadingStatus:
NOT_STARTED, READING, and FINISHED. You will also want a "default" or an "else"
statement to deal with the case where something is passed in that is not found.

If NOT_STARTED is passed in, **return** "Not started". (Do not cout it, return it!)

If READING is passed in, return "Reading".

If FINISHED is passed in, return "Finished".

Otherwise, return "?".

### PurchaseStatusString

* Return type: string
* Parameters:
	* ps, a PurchaseStatus

Similar to ReadingStatusString, this takes in some ReadingStatus and
returns a user-friendly string.

* OWNED - return "Owned"
* WISHLIST - return "Wishlist"
* Other - return "?"

## Functions: SetBook and DisplayBook

First, we are only going to deal with modifying and displaying *one* book, but later on
we will have an array of books that we will be working with.

Rather than having to set a book's member variables manually each time,
let's create a function that will allow us to set up a book.

### SetBook

* Return type: void
* Parameters:
  * book, a Book, passed by reference
  * title, string
  * author, string
  * ps, PurchaseStatus
  * rs, ReadingStatus

Within the function, a *book* is being passed in - this is the book we are
modifying. We are not declaring a new Book within this function.

With the book object, set each of its member variables to the parameters passed in.
Title, author, purchase status, and reading status.

### DisplayBook

* Return type: void
* Parameters:
  * book, a Book
  
This function is responsible for displaying all the information about a book,
so that we don't have to manually cout all the information *every time we want
to list out a book*.

Make sure to use cout to display all four member variables of the *book*.
You can organize these how you'd like.

Remember to use the **ReadingStatusString** and **PurchaseStatusString**
functions to display user-friendly information instead of just numbers!

## Testing

Within main(), create a few **Book** object variables to work with. Use the
SetBook and DisplayBook to set each of these books and make sure that
everything is outputted to the screen properly.

Tester main():

	int main()
	{
		Book bookA, bookB, bookC, bookD, bookE, bookF;

		// Testing all permutations of purchase/reading status
		SetBook( bookA, "Harry Potter and the Sorcerer's Stone", "J K Rowling", OWNED, FINISHED );
		SetBook( bookB, "Who cooked the last supper?", "Rosalind Miles", OWNED, READING );
		SetBook( bookC, "Marvirinstrato", "Tim Westover", OWNED, NOT_STARTED );

		SetBook( bookD, "Masters of Doom", "David Kushner", WISHLIST, FINISHED );
		SetBook( bookE, "Earthsong", "Suzette Haden Elgin", WISHLIST, READING );
		SetBook( bookF, "Invent to Learn", "Martinez, Stager", WISHLIST, NOT_STARTED );

		DisplayBook( bookA );
		DisplayBook( bookB );
		DisplayBook( bookC );
		DisplayBook( bookD );
		DisplayBook( bookE );
		DisplayBook( bookF );

		return 0;
	}

Output:

![Setting and displaying books](images/test_setdisplay.png)

## Backup!

Make sure to commit your changes to your project repository before continuing! :)

---

# Iteration 2: Array of Books

![Cute books](https://github.com/Rachels-Courses/Course-Common-Files/blob/master/Artwork/Cuties/books.png?raw=true)

Now we're going to start dealing with an array of books, as well as starting a simple menu system.
Rather than storing a lot of logic in main(), let's create functions to distribute all
functionality of the program - from displaying menus, to updating books.

We will be creating the book array in main(), but passing it around to each function so that
it can be utilized throughout the program. Later on, once we're working with classes more,
we will be writing programs that don't require so much "passing around".

What we currently have in main() from Iteration 1 was just for testing, so we can erase this stuff.

## main()

Create an array of Books, as well as an integer to keep track of book size.

	int main()
	{
		Book books[100];
		int bookCount = 0;

		return 0;
	}

## Functions: GetValidInput MainMenu, AddBookMenu, UpdateBookMenu, DisplayBookList

main() is only the entry-point of the program, but that doesn't mean that it
has to hold all the core logic of the program. Instead, we're going to distribute
the functionality of the program between multiple functions.

### GetValidInput

* Return type: int
* Parameters:
	* min (int)
	* max (int)

For this function, we will have it handle getting numeric input from the user.
If the user enters something invalid (less than min or greater than max),
it will keep asking the user to re-enter their choice until the user finally
gives a valid item.

When this function returns the user's input, it will be guaranteed to have
a valid number (between [min, max]).

1. Create an integer variable named **choice**.
2. Prompt the user for input (could just cout ">> " or "Input: ")
3. Get the user's input and store it in **choice** (use cin).
4. Create a while loop. While choice is less than min, or greater than max:
	1. Display an error message.
	2. Prompt the user for input.
	3. Get the user's input and store it in **choice**.
5. Call cin.ignore() after the while loop
6. Return the choice.

We have to use cin.ignore() in our program because we will be switching
between getting user input with

	cin >> var;
	
and

	getline( cin, var );

-- the problem is, if we inter-mix these, it might skip over our getline statement
during the program, because the way the input stream works. To get around this,
you can use *cin.ignore()* after an input using the stream operator >> to
make sure it doesn't skip over the next input.

### AddBookMenu

This menu is responsible for getting the book's information, and then calling
the **SetBook** function.

* Return type: void
* Parameters:
	* Array of Books
	* Book count (int), passed by reference

1. Create two temporary string variables: title and author.
2. Create two temporary integer variables: ps and rs.
3. Ask the user to enter a title, store it in **title**. (use getline)
4. Ask the user to enter an author, store it in **author**. (use getline)

Then, you'll display the options for purchase status like this:

    cout << endl << "Purchase Status:" << endl;
    cout << "\t" << OWNED       << ". " << PurchaseStatusString( OWNED ) << endl;
    cout << "\t" << WISHLIST    << ". " << PurchaseStatusString( WISHLIST ) << endl;
	
Remember, when using cout with one of these enum values, it will display the NUMBER value.
We can use this as a shortcut to build a numeric menu - the user will enter 0 for OWNED, or 1 for WISHLIST.
We're going to store their integer choice in an int variable, then **cast** it to a PurchaseStatus for the book.

Use **GetValidInput** to get the user's input and make sure it is one of the valid PurchaseStatus options:

	ps = GetValidInput( OWNED, WISHLIST );
	
Do the same sort of thing with Reading Status. Then, once everything is entered, call
**SetBook** to set the specific book, then increment the bookCount. Your call to SetBook will look like this:

	SetBook( books[ bookCount ], title, author, (PurchaseStatus)ps, (ReadingStatus)rs );

We are passing in books[ bookCount ], which will pass in **one element of the books array** -- essentially, one Book variable.
We are using the bookCount as the index, because it begins at 0 when there are no books, which coincidentally is also
the index of the first book we will add. As the bookCount goes up, its value stores the *index that the next book will go at.*

We are casting the integers *ps* and *rs* to their proper enumerations.
One way we can cast values to other data-types is to use the data-type in parenthesis before the variable name.
This won't work for *all* variables, but it will work for us here.

### DisplayBookList

* Return type: void
* Parameters:
	* Array of Books
	* Book count (int)

For this function, simply create a for-loop that goes from 0 to the bookCount (not-inclusive),
and displays each book with **DisplayBook**.

First, make sure to display the value of *i* (if that is your counter variable), then call the DisplayBook function in this manner:

	DisplayBook( books[i] );

Where *i* is the counter variable in the for-loop. Again, we're passing in **one element of the books array**,
which is essentially one variable.

### UpdateBookMenu

* Return type: void
* Parameters:
	* Array of Books
	* Book count (int), passed by reference

This menu allows the user to choose which Book field to update (so they don't have to re-enter *all* the
information every time they want to make an update). It will store these values in temp variables,
then call **SetBook** to update the book chosen.

1. Use **DisplayBookList** to show the list of all possible books the user can update.
2. Ask the user what index they want to update.
3. Get the user's choice and store it in an integer variable **index**. Make sure to use **GetValidInput**! The value should be between 0 <= index < bookCount.
4. Create temporary variables: title (string), author (string), ps (PurchaseStatus), rs (ReadingStatus).
	Initialize *each of these variables* to the book's current values...

	title = books[ index ].title;
	
After this setup, ask the user what they want to update in another number menu. Something like:

	1. Update title
	2. Update author
	3. Update purchase status
	4. Update reading status

Get the user's input (again, through *GetValidInput*), and use an if or switch statement.

Based on the user's input, have them either enter a new title (to the *title* variable),
author (to the *author* variable), purchase status, or reading status.

Note: For the status variables, you might need to create a temporary *int* variable and then
cast their input to the proper value, similar to in **AddBook**.

### MainMenu

* Return type: void
* Parameters:
	* The book array
	* The book count, passed by reference.
	
	void MainMenu( Book books[100], int & bookCount )

Within the main menu, it should display the list of options the user can do.
Create a while loop that will keep the program running until the user quits.
Let's only display a few menu options for now.

1. Add book
2. Update book
3. Display book list
4. Quit

Get the user's input with the **GetValidInput** function, then use a switch
or if statement to decide what to do.

* Add book - call **AddBookMenu**
* Update book - call **UpdateBookMenu**
* Display book list - call **DisplayBookMenu**
* Quit - stop the program loop.

## Test and backup

Test the program and make sure to backup your work before continuing!

* Add several books
* Update each field of each book, to make sure each type of update works
* Display the list of books after each add

---

# Iteration 3: Book stats

![Books being ranked](https://github.com/Rachels-Courses/Course-Common-Files/blob/master/Artwork/Cuties/books-ranking.png?raw=true)

We are going to add a feature to the program so that the user can see
stats on their books - how many are finished, currently reading, and 
"unstarted".

## DisplayStats

* Return type: void
* Parameters:
	* Book array of size 100 (named books)
	* bookCount, an integer

Within this function, create three temporary integer variables:

* totalFinished
* totalReading
* totalUnstarted

Initialize each of these to 0.

Create a for loop to go through each of the books and look at their
status. If the status is FINISHED, add 1 to the totalFinished. If the status is NOT_STARTED, add 1 to totalUnstarted. If the status is READING, then add 1 to the totalReading.

After you're done computing the information, display it to the user with some cout statements.

## Test and backup

* Add several books with the different statuses
* Call DisplayStats to make sure it is accurate and works properly.

---

# Iteration 4: Saving book data to a text file

Now that we have the core functionality, we will want to save our
book list to a file so that we don't have to keep entering books in
every time we run the program.

## SaveList

* Return type: void
* Parameters:
	* Book array, size 100
	* bookCount, an integer passed by reference

The book text file will need to follow a specific format so that,
when we read the file back in, we can easily write a **parser** to
deal with the data.

The format of the file will look like this:

	BOOK_0
	Harry Potter and the Sorcerer's Stone
	J K Rowling
	1
	0
	BOOK_1
	Refactoring
	Martin Fowler
	2
	1

The output will always be in the order:

1. BOOK_number - the marker that we're loading in a new book.
2. Title
3. Author
4. Purchase Status
5. Reading Status

In your SaveList function, do the following:

1. Create an **ofstream** object named output.
2. Use the open() function of output to open "booklist.txt".
3. Create a for loop. For each of the books in the array...
	1. output "BOOK_" and then the current index (from the for loop) on its own line
	2. output the book's title on its own line
	3. output the book's author on its own line
	4. output the book's purchase status on its own line
	5. output the book's reading status on its own line 
4. Close the output.

Make sure to call this function before the program quits - before the return 0 in main().

## Test and backup

Test your program by adding several books and then quitting.

Open your project folder, where your source code is stored, and look for
*booklist.txt*. Its contents should look similar to:

	BOOK_0
	Harry Potter and the Sorcerer's Stone
	J K Rowling
	0
	2
	BOOK_1
	Harry Potter and the Chamber of Secrets
	J K Rowling
	0
	2
	BOOK_2
	City of Ladies
	Christine de Pizan
	0
	1
	BOOK_3
	Hitchhiker's Guide to the Galaxy
	Douglas Adams
	1
	0

It might not be pretty, but it's for the computer to read - not the humans. :)

---

# Iteration 5: Loading book data from text file

Next, when our program starts up, we will be loading in the book data
from the text file, so that each time we run it, we don't have to add
books manually.

## LoadList

* Return type: void
* Parameters:
	* Book array, size 100
	* bookCount, an integer passed by reference

Do the following...

1. Create an **ifstream** object called input.
2. Use the open() function on input to load in the "booklist.txt" file.
3. Initialize **bookCount** to 0.
3. Create four temporary string variables: **title**, **status**, **author**, and **buffer**.
4. Create two temporary integer variables: **rstatus**, **pstatus**.
5. Create a while loop that will continue looping while we are able to get text from **input** and store it into the **buffer**...:

	while ( input >> buffer )
	{
	}

Within the while loop, it will need to load everything in a specific order.

1. Use **input.ignore();** to flush the buffer.
2. Use **getline** on the input, store the line of text in title.
	getline( input, title );
3. Use **getline** on the input, store the line of text in the author.
4. Use **input >>** to store the next value in the pstatus.
5. Use **input >>** to store the next value in the rstatus.


This is loading each line of text from the file. After we've read in
the data into *temporary variables*, we need to set up the data
in the actual Book element.

We will be accessing one book at a time through the book array.
You can access the current book with:

	books[ bookCount ]

and after you're done adding one book, you will increment the bookCount:

	bookCount++;

This will all go within the while loop.

* At the current book (books[ bookCount]), set its title to the temporary **title** variable.
* At the current book, set its author to the temporary **author** variable.
* At the current book, set its **purchaseStatus** equal to the **pstatus** variable - you will have to cast it to a PurchaseStatus. See below.
* At the current book, set its **readingStatus** equal to **rstatus**, cast to a ReadingStatus.
* Increment bookCount by 1.

To cast an integer variable (such as pstatus) to an enum, you will use the
enum's name within parenthesis before the integer variable.

To store the book's purchaseStatus, it would look like this:

	books[ bookCount ].purchaseStatus = (PurchaseStatus)pstatus;

Outside of the while loop, at the end of the **LoadList** function, make sure to close the input.

Call the function in main(), before you call the MainMenu function. 

## Test and backup

Build and test the program. Make sure that the books you added *last time* you ran the program have been loaded in and are available to view and update.

Add several books, save and quit, then open the program again to make sure all your changes were saved.

---

# Iteration 6: CSV files

Finally, we're going to create some functions to output book data to a CSV file. .csv files can be opened in Excel, and are presented in a spreadsheet format, but are just stored as plain text.

## ExportCsv

* Return type: void
* Parameters:
	* Book array, size 100
	* bookCount, integer


Here, you will create an **ofstream** file and open the file "booklist.csv".

The first line of this CSV file should be the header of each column:
TITLE, then AUTHOR, then READING?, then OWNED?

All lines after the first line will contain the data - one row per book.

Your function will look like this:

	void ExportCsv( Book books[100], int & bookCount )
	{
		ofstream output( "booklist.csv" );
	
		output << "TITLE,AUTHOR,READING?,OWNED?" << endl;
	
		for ( int i = 0; i < bookCount; i++ )
		{
			output << books[i].title << ","
	            << books[i].author << ","
	            << books[i].readingStatus << ","
	            << books[i].purchaseStatus << ","
	            << endl;
		}
	
		output.close();
	}

## ExportUnfinishedBooks

* Return type: void
* Parameters:
	* Book array, size 100
	* bookCount, integer

Similar to the other CSV file, this will also output the same data, but **only if the book is set as NOT_STARTED or READING**.

Using the functionality from the **ExportCsv** function, create this new function, but modify it.

While looping through all the books, check the readingStatus of the book:
If it is NOT_STARTED or READING, output the book information to the file.
Otherwise, skip that book.

Make sure to add function calls to both of these functions from your MainMenu.

## Test and backup

Open the program, and call both export functions. Check the directory that your code is in to make sure the .csv files are generated. Open each of them to make sure they appear correct.  

---

# Grading Rubric

<table border="0" cellspacing="0" cellpadding="0" class="ta1"><colgroup><col width="12"/><col width="427"/><col width="63"/><col width="163"/><col width="162"/><col width="83"/></colgroup><tr class="ro1"><td style="text-align:left;width:7.51pt; " class="ce20"> </td><td colspan="4" style="text-align:left;width:276.66pt; " class="ce21"><p>Grading Rubric</p></td><td style="text-align:left;width:54pt; " class="ce20"> </td></tr><tr class="ro1"><td style="text-align:left;width:7.51pt; " class="ce20"> </td><td style="text-align:left;width:276.66pt; " class="ce22"><p>Name:</p></td><td style="text-align:left;width:40.99pt; " class="ce22"> </td><td colspan="2" style="text-align:left;width:105.76pt; " class="ce20"> </td><td style="text-align:left;width:54pt; " class="ce20"> </td></tr><tr class="ro1"><td style="text-align:left;width:7.51pt; " class="ce20"> </td><td style="text-align:left;width:276.66pt; " class="ce22"><p>Assignment:</p></td><td colspan="3" style="text-align:left;width:40.99pt; " class="ce27"><p>Programming Assignment 3</p></td><td style="text-align:left;width:54pt; " class="ce20"> </td></tr><tr class="ro2"><td style="text-align:left;width:7.51pt; " class="ce20"> </td><td style="text-align:left;width:276.66pt; " class="ce20"> </td><td style="text-align:left;width:40.99pt; " class="ce20"> </td><td style="text-align:left;width:105.76pt; " class="ce20"> </td><td style="text-align:left;width:105pt; " class="ce20"> </td><td style="text-align:left;width:54pt; " class="ce20"> </td></tr><tr class="ro1"><td style="text-align:left;width:7.51pt; " class="ce20"> </td><td colspan="4" style="text-align:left;width:276.66pt; " class="ce21"><p>Breakdown</p></td><td style="text-align:left;width:54pt; " class="ce20"> </td></tr><tr class="ro1"><td style="text-align:left;width:7.51pt; " class="ce20"> </td><td style="text-align:left;width:276.66pt; " class="ce23"><p>Item</p></td><td style="text-align:left;width:40.99pt; " class="ce23"> </td><td style="text-align:left;width:105.76pt; " class="ce23"><p>Total %</p></td><td style="text-align:left;width:105pt; " class="ce23"><p>Your Score</p></td><td style="text-align:left;width:54pt; " class="ce20"> </td></tr><tr class="ro3"><td style="text-align:left;width:7.51pt; " class="ce20"> </td><td style="text-align:left;width:276.66pt; " class="ce24"><p>Builds &amp; Runs</p></td><td style="text-align:left;width:40.99pt; " class="ce28"> </td><td style="text-align:right; width:105.76pt; " class="ce30"><p>2.00%</p></td><td style="text-align:left;width:105pt; " class="ce30"> </td><td style="text-align:left;width:54pt; " class="ce20"> </td></tr><tr class="ro3"><td style="text-align:left;width:7.51pt; " class="ce20"> </td><td style="text-align:left;width:276.66pt; " class="ce25"><p>Clean Code</p></td><td style="text-align:left;width:40.99pt; " class="ce29"> </td><td style="text-align:right; width:105.76pt; " class="ce31"><p>2.00%</p></td><td style="text-align:left;width:105pt; " class="ce31"> </td><td style="text-align:left;width:54pt; " class="ce20"> </td></tr><tr class="ro4"><td style="text-align:left;width:7.51pt; " class="ce20"> </td><td style="text-align:left;width:276.66pt; " class="ce24"><p>enums created for reading status and purchase status</p></td><td style="text-align:left;width:40.99pt; " class="ce28"> </td><td style="text-align:right; width:105.76pt; " class="ce30"><p>2.00%</p></td><td style="text-align:left;width:105pt; " class="ce30"> </td><td style="text-align:left;width:54pt; " class="ce20"> </td></tr><tr class="ro3"><td style="text-align:left;width:7.51pt; " class="ce20"> </td><td style="text-align:left;width:276.66pt; " class="ce25"><p>Book struct created with proper fields</p></td><td style="text-align:left;width:40.99pt; " class="ce29"> </td><td style="text-align:right; width:105.76pt; " class="ce31"><p>10.00%</p></td><td style="text-align:left;width:105pt; " class="ce31"> </td><td style="text-align:left;width:54pt; " class="ce20"> </td></tr><tr class="ro4"><td style="text-align:left;width:7.51pt; " class="ce20"> </td><td style="text-align:left;width:276.66pt; " class="ce24"><p><span class="T1">ReadingStatusString</span> and <span class="T1">PurchaseStatusString</span> functions</p></td><td style="text-align:left;width:40.99pt; " class="ce28"> </td><td style="text-align:right; width:105.76pt; " class="ce30"><p>3.00%</p></td><td style="text-align:left;width:105pt; " class="ce30"> </td><td style="text-align:left;width:54pt; " class="ce20"> </td></tr><tr class="ro5"><td style="text-align:left;width:7.51pt; " class="ce20"> </td><td style="text-align:left;width:276.66pt; " class="ce25"><p><span class="T1">SetBook</span></p><p>Takes in arguments and assigns values to the book object</p></td><td style="text-align:left;width:40.99pt; " class="ce29"> </td><td style="text-align:right; width:105.76pt; " class="ce31"><p>5.00%</p></td><td style="text-align:left;width:105pt; " class="ce31"> </td><td style="text-align:left;width:54pt; " class="ce20"> </td></tr><tr class="ro5"><td style="text-align:left;width:7.51pt; " class="ce20"> </td><td style="text-align:left;width:276.66pt; " class="ce24"><p><span class="T1">DisplayBook</span></p><p>Uses cout to display all the attributes of the book.</p></td><td style="text-align:left;width:40.99pt; " class="ce28"> </td><td style="text-align:right; width:105.76pt; " class="ce30"><p>5.00%</p></td><td style="text-align:left;width:105pt; " class="ce30"> </td><td style="text-align:left;width:54pt; " class="ce20"> </td></tr><tr class="ro4"><td style="text-align:left;width:7.51pt; " class="ce20"> </td><td style="text-align:left;width:276.66pt; " class="ce25"><p>Array of books added to main, passed to functions correctly.</p></td><td style="text-align:left;width:40.99pt; " class="ce29"> </td><td style="text-align:right; width:105.76pt; " class="ce31"><p>10.00%</p></td><td style="text-align:left;width:105pt; " class="ce31"> </td><td style="text-align:left;width:54pt; " class="ce20"> </td></tr><tr class="ro5"><td style="text-align:left;width:7.51pt; " class="ce20"> </td><td style="text-align:left;width:276.66pt; " class="ce24"><p><span class="T1">MainMenu</span></p><p>Display list of options, use branch to call proper function based on user selection.</p></td><td style="text-align:left;width:40.99pt; " class="ce28"> </td><td style="text-align:right; width:105.76pt; " class="ce30"><p>5.00%</p></td><td style="text-align:left;width:105pt; " class="ce30"> </td><td style="text-align:left;width:54pt; " class="ce20"> </td></tr><tr class="ro6"><td style="text-align:left;width:7.51pt; " class="ce20"> </td><td style="text-align:left;width:276.66pt; " class="ce25"><p><span class="T1">GetValidInput</span></p><p>Prompts user for input, continues looping until valid input is given, only returns valid input.</p></td><td style="text-align:left;width:40.99pt; " class="ce29"> </td><td style="text-align:right; width:105.76pt; " class="ce31"><p>5.00%</p></td><td style="text-align:left;width:105pt; " class="ce31"> </td><td style="text-align:left;width:54pt; " class="ce20"> </td></tr><tr class="ro6"><td style="text-align:left;width:7.51pt; " class="ce20"> </td><td style="text-align:left;width:276.66pt; " class="ce24"><p><span class="T1">AddBookMenu</span></p><p>Outputs prompts and gets user input for the book attributes. Calls SetBook to set up the book in the array.</p></td><td style="text-align:left;width:40.99pt; " class="ce28"> </td><td style="text-align:right; width:105.76pt; " class="ce30"><p>5.00%</p></td><td style="text-align:left;width:105pt; " class="ce30"> </td><td style="text-align:left;width:54pt; " class="ce20"> </td></tr><tr class="ro5"><td style="text-align:left;width:7.51pt; " class="ce20"> </td><td style="text-align:left;width:276.66pt; " class="ce25"><p><span class="T1">DisplayBookList</span></p><p>Uses a loop to display every book in the array.</p></td><td style="text-align:left;width:40.99pt; " class="ce29"> </td><td style="text-align:right; width:105.76pt; " class="ce31"><p>2.00%</p></td><td style="text-align:left;width:105pt; " class="ce31"> </td><td style="text-align:left;width:54pt; " class="ce20"> </td></tr><tr class="ro7"><td style="text-align:left;width:7.51pt; " class="ce20"> </td><td style="text-align:left;width:276.66pt; " class="ce24"><p><span class="T1">UpdateBookMenu</span></p><p>Asks user which book to update, and which field to update. Gets updated information from user. Updates the book in the array.</p></td><td style="text-align:left;width:40.99pt; " class="ce28"> </td><td style="text-align:right; width:105.76pt; " class="ce30"><p>10.00%</p></td><td style="text-align:left;width:105pt; " class="ce30"> </td><td style="text-align:left;width:54pt; " class="ce20"> </td></tr><tr class="ro7"><td style="text-align:left;width:7.51pt; " class="ce20"> </td><td style="text-align:left;width:276.66pt; " class="ce25"><p><span class="T1">DisplayStats</span></p><p>Iterates through each book, counting how many finished / unfinished / unstarted books there are, and displays the stats to the user.</p></td><td style="text-align:left;width:40.99pt; " class="ce29"> </td><td style="text-align:right; width:105.76pt; " class="ce31"><p>2.00%</p></td><td style="text-align:left;width:105pt; " class="ce31"> </td><td style="text-align:left;width:54pt; " class="ce20"> </td></tr><tr class="ro5"><td style="text-align:left;width:7.51pt; " class="ce20"> </td><td style="text-align:left;width:276.66pt; " class="ce24"><p><span class="T1">SaveList</span></p><p>Saves the book data to a structured text file.</p></td><td style="text-align:left;width:40.99pt; " class="ce28"> </td><td style="text-align:right; width:105.76pt; " class="ce30"><p>10.00%</p></td><td style="text-align:left;width:105pt; " class="ce30"> </td><td style="text-align:left;width:54pt; " class="ce20"> </td></tr><tr class="ro5"><td style="text-align:left;width:7.51pt; " class="ce20"> </td><td style="text-align:left;width:276.66pt; " class="ce25"><p><span class="T1">LoadList</span></p><p>Loads the book data from the structured text file and stores books in the array.</p></td><td style="text-align:left;width:40.99pt; " class="ce29"> </td><td style="text-align:right; width:105.76pt; " class="ce31"><p>15.00%</p></td><td style="text-align:left;width:105pt; " class="ce31"> </td><td style="text-align:left;width:54pt; " class="ce20"> </td></tr><tr class="ro5"><td style="text-align:left;width:7.51pt; " class="ce20"> </td><td style="text-align:left;width:276.66pt; " class="ce24"><p><span class="T1">ExportCsv</span></p><p>Exports book data in a human-readable csv file</p></td><td style="text-align:left;width:40.99pt; " class="ce28"> </td><td style="text-align:right; width:105.76pt; " class="ce30"><p>2.00%</p></td><td style="text-align:left;width:105pt; " class="ce30"> </td><td style="text-align:left;width:54pt; " class="ce20"> </td></tr><tr class="ro5"><td style="text-align:left;width:7.51pt; " class="ce20"> </td><td style="text-align:left;width:276.66pt; " class="ce25"><p><span class="T1">ExportUnfinishedBooks</span></p><p>Exports unfinished book data in a human-readable csv file</p></td><td style="text-align:left;width:40.99pt; " class="ce29"> </td><td style="text-align:right; width:105.76pt; " class="ce31"><p>5.00%</p></td><td style="text-align:left;width:105pt; " class="ce31"> </td><td style="text-align:left;width:54pt; " class="ce20"> </td></tr><tr class="ro3"><td style="text-align:left;width:7.51pt; " class="ce20"> </td><td style="text-align:left;width:276.66pt; " class="ce26"> </td><td style="text-align:left;width:40.99pt; " class="ce26"> </td><td style="text-align:left;width:105.76pt; " class="ce32"> </td><td style="text-align:left;width:105pt; " class="ce32"> </td><td style="text-align:left;width:54pt; " class="ce20"> </td></tr><tr class="ro1"><td style="text-align:left;width:7.51pt; " class="ce20"> </td><td style="text-align:left;width:276.66pt; " class="ce22"><p>Totals</p></td><td style="text-align:left;width:40.99pt; " class="ce22"> </td><td style="text-align:left;width:105.76pt; " class="ce32"> </td><td style="text-align:left;width:105pt; " class="ce32"> </td><td style="text-align:left;width:54pt; " class="ce20"> </td></tr><tr class="ro8"><td style="text-align:left;width:7.51pt; " class="ce20"> </td><td style="text-align:left;width:276.66pt; " class="ce26"> </td><td style="text-align:left;width:40.99pt; " class="ce26"> </td><td style="text-align:right; width:105.76pt; " class="ce32"><p>100.00%</p></td><td style="text-align:right; width:105pt; " class="ce33"><p>0.00%</p></td><td style="text-align:left;width:54pt; " class="ce20"> </td></tr><tr class="ro8"><td style="text-align:left;width:7.51pt; " class="ce20"> </td><td style="text-align:left;width:276.66pt; " class="ce26"> </td><td style="text-align:left;width:40.99pt; " class="ce26"> </td><td style="text-align:left;width:105.76pt; " class="ce26"> </td><td style="text-align:left;width:105pt; " class="ce26"> </td><td style="text-align:left;width:54pt; " class="ce20"> </td></tr><tr class="ro1"><td style="text-align:left;width:7.51pt; " class="ce20"> </td><td colspan="4" style="text-align:left;width:276.66pt; " class="ce21"><p>Notes</p></td><td style="text-align:left;width:54pt; " class="ce20"> </td></tr><tr class="ro2"><td style="text-align:left;width:7.51pt; " class="ce20"> </td><td style="text-align:left;width:276.66pt; " class="ce20"> </td><td style="text-align:left;width:40.99pt; " class="ce20"> </td><td style="text-align:left;width:105.76pt; " class="ce20"> </td><td style="text-align:left;width:105pt; " class="ce20"> </td><td style="text-align:left;width:54pt; " class="ce20"> </td></tr><tr class="ro9"><td style="text-align:left;width:7.51pt; " class="ce20"> </td><td style="text-align:left;width:276.66pt; " class="ce20"> </td><td style="text-align:left;width:40.99pt; " class="ce20"> </td><td style="text-align:left;width:105.76pt; " class="ce20"> </td><td style="text-align:left;width:105pt; " class="ce20"> </td><td style="text-align:left;width:54pt; " class="ce20"> </td></tr><tr class="ro9"><td style="text-align:left;width:7.51pt; " class="ce20"> </td><td style="text-align:left;width:276.66pt; " class="ce20"> </td><td style="text-align:left;width:40.99pt; " class="ce20"> </td><td style="text-align:left;width:105.76pt; " class="ce20"> </td><td style="text-align:left;width:105pt; " class="ce20"> </td><td style="text-align:left;width:54pt; " class="ce20"> </td></tr><tr class="ro9"><td style="text-align:left;width:7.51pt; " class="ce20"> </td><td style="text-align:left;width:276.66pt; " class="ce20"> </td><td style="text-align:left;width:40.99pt; " class="ce20"> </td><td style="text-align:left;width:105.76pt; " class="ce20"> </td><td style="text-align:left;width:105pt; " class="ce20"> </td><td style="text-align:left;width:54pt; " class="ce20"> </td></tr><tr class="ro9"><td style="text-align:left;width:7.51pt; " class="ce20"> </td><td style="text-align:left;width:276.66pt; " class="ce20"> </td><td style="text-align:left;width:40.99pt; " class="ce20"> </td><td style="text-align:left;width:105.76pt; " class="ce20"> </td><td style="text-align:left;width:105pt; " class="ce20"> </td><td style="text-align:left;width:54pt; " class="ce20"> </td></tr><tr class="ro9"><td style="text-align:left;width:7.51pt; " class="ce20"> </td><td style="text-align:left;width:276.66pt; " class="ce20"> </td><td style="text-align:left;width:40.99pt; " class="ce20"> </td><td style="text-align:left;width:105.76pt; " class="ce20"> </td><td style="text-align:left;width:105pt; " class="ce20"> </td><td style="text-align:left;width:54pt; " class="ce20"> </td></tr><tr class="ro9"><td style="text-align:left;width:7.51pt; " class="ce20"> </td><td style="text-align:left;width:276.66pt; " class="ce20"> </td><td style="text-align:left;width:40.99pt; " class="ce20"> </td><td style="text-align:left;width:105.76pt; " class="ce20"> </td><td style="text-align:left;width:105pt; " class="ce20"> </td><td style="text-align:left;width:54pt; " class="ce20"> </td></tr></table>
