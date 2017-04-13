# CS 200 Lab 14: File IO and Structs

## Chrome!

Please read this in chrome so that the solutions are collapsed by default!

## Topics

* Structs
* File I/O

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

# Review

## Structs

Structs (and later on, Classes) are a way for the programmer to create their own
*data types*. We can put together multiple variables in one container, and give
that container a name to describe the object.

For example, if you're trying to store a list of students, it would be annoying to
work with several arrays for each field:

```c++
string studentNames[100];
float studentGpas[100];
string studentDegree[100];
```

Rather than making several arrays of each field, why not group each field
together under a "Student" object, and make an array of students?

```c++
// OUTSIDE OF ALL FUNCTIONS:
struct Student
{
	string name;
	float gpa;
	string degree;
};

// In main or another function:
Student studentList[100];
```

Using the **Student** object above, let's just work with a single Student
variable for now, and step through how we use it.

```c++
int main()
{
	Student me;
	
	return 0;
}
```

To set those fields, *name*, *gpa*, and *degree*, which are *contained within Student*,
we use the dot operator . with the variable:

```c++
me.name = "Rach";
me.gpa = 3.2;
me.degree = "Computer Science";
```

So now all this information is stored within three variables (strings and a float), but these three
variables also *belong* to a single Student variable.

We can also have our array of students:

```c++
Student studentList[100];
```

and we can set each student's internal variables as well:

```c++
studentList[0].name = "Takahiro";
studentList[0].degree = "Mathematics";

studentList[1].name = "Carla";
studentList[1].degree = "Civil Engineering";
```

We can also store **functions** within our struct object.

```c++
struct Student
{
	string name;
	float allGrades[100];
	int classesTaken;
	string degree;
	
	float GetGPA()
	{
		float sum = 0;
		for ( int i = 0; i < classesTaken; i++ )
		{
			sum += allGrades[i];
		}
		return sum / classesTaken;
	}
};
```

Then, our function can be called from the object itself:

```c++
cout << "NAME: " << studentList[0] << ", GPA: " << studentList[0].GetGPA() << endl;
```

The **variables** and **functions** within a struct are known as **members**.
They belong to the struct, and when you declare a variable of that struct type,
that variable will contain those variables and functions.


## File I/O

We can write text to a file, or read text from a file, in a similar manner
to how we write to the screen and read from the keyboard.
We will continue using stream operators, but instead of **cout** and **cin**,
we need **ofstream** (output-file-stream) and **ifstream** (input-file-stream) objects
to work with.

### Output to text file

Let's say we are going to take this code:

```c++
Student studentList[100];

// [...]

cout << "STUDENT LIST" << endl;

// Display all students to screen
for ( int i = 0; i < 100; i++ )
{
	cout << studentList[i].name 
		<< "\t"
		<< studentList[i].degree
		<< endl;
}
```
and change it so that we are writing to a text file (.txt) instead
of the screen.

First, we need to make sure to include the file stream library **fstream**:

```c++
#include <fstream>
```

Then, somewhere in our program, we are going to declare a variable
whose data-type is **ofstream** (output-file-stream):

```c++
ofstream output;
```

We will first need to open some text file to write to:

```c++
output.open( "StudentList.txt" );
```

And we can output information similar to as we do with cout, but instead
with our *output* variable:

```c++
output << "STUDENT LIST" << endl;
```

Note that we can still use **endl**, **\n**, and **\t** in our file output,
just like with cout.

And when we're done writing to the text file, we need to make sure to **close it**:

```c++
output.close();
```

So when we're done updating the original code, it will look like this:

```c++
Student studentList[100];

// [...]

ofstream output;
output.open( "StudentList.txt" );

output << "STUDENT LIST" << endl;

// Display all students to screen
for ( int i = 0; i < 100; i++ )
{
	output << studentList[i].name 
		<< "\t"
		<< studentList[i].degree
		<< endl;
}

output.close();
```

When we run the program, the *output* items won't be displayed to
the screen, but when you open up the program directory, there will
be the *StudentList.txt* file written there, which you can open
with notepad.

### Input from text file

Opening and closing an input file is similar to with the output file,
except we use the **ifstream** (input-file-stream) object instead of
ofstream:

```c++
ifstream input;
input.open( "StudentGrades.txt" );

// Do stuff

input.close();
```

And, like with **cin**, we can either get one word at a time from the text file.
This way you can load any basic data-type (int, float, string, char, etc.):

```c++
input >> grades[0];
```

Or one line at a time from the text file with **getline**, but you will
have to store it in a string:

```c++
string lineOfText;
getline( input, lineOfText );
```

So, let's assume we have a text file with student info, which looks like:

		Ku Hye-sun
		3.5
		CS

And all student files will be the same format...

		LASTNAME FIRSTNAME
		GPA
		DEGREE

and we can use this standardized format to help us read in the student information
in our program...

```c++
Student topStudent;

ifstream studentFile( "Ku.txt" ); // Named the input file studentFile this time

studentFile >> topStudent.surname;		// changed Student struct to have surname
studentFile >> topStudent.givenName;	// and givenName as separate fields
studentFile >> topStudent.gpa
studentFile >> topStudent.degree

studentFile.close();
```

Once this student is loaded in from the text file, we can work with this
data in our program. Display the information, have the user update the information,
etc.

If we wanted to save the updated text file, it would look like:

```c++
ofstream output( "Ku.txt" ); // Update this record

output << topStudent.surname << " "; // put a space between surname and given name
output << topStudent.givenName << endl;
output << topStudent.gpa << endl;
output << topStudent.degree << endl;
```

---

# Program 1: Poll results

For this program, we are going to display an online poll, which contains
a *question* and several *option*, and we will store the amount of times
each option is voted for. Then, we will write the results to a text file.

## Structs

First, create a struct called **Option**. This struct should have
the following items:

* title, a string
* count, an integer

Second, create another struct called **Poll**. This struct will have:

* question, a string
* options, an array of 4 Option objects.

## Creating a Poll object

Within **main()**, declare a new Poll object:

```c++
Poll myPoll;
```

Then, set up the poll information:

```c++
myPoll.question = "What is the best food?";

myPoll.options[0].title = "Pizza";
myPoll.options[0].count = 0;

myPoll.options[1].title = "Veggie Taco";
myPoll.options[1].count = 0;

myPoll.options[2].title = "Samosas";
myPoll.options[2].count = 0;

myPoll.options[3].title = "Sushi";
myPoll.options[3].count = 0;
```

## Program loop

Your program will continue looping, asking each user to vote for an option.
When an option is voted for, it will increment that option's *count* 
member variable by 1.

The program will continue running until the user decides to quit.

Example:

		What is the best food?
		0. Pizza
		1. Veggie Taco
		2. Samosas
		3. Sushi
		4. EXIT
		
		What is your selection?
		>> 

The # that the user enters corresponds to the option's index in the array!

## Write the results to a text file

Once the user has quit, you will need to write the results to a text file.

First, create an output file stream:

```c++
ofstream output;
```

Then open the file:

```c++
output.open( "results.txt" );
```

and write the results of the poll, similar to how you would with *cout*,
but using the *output* ofstream object instead.

Write out the poll question, as well as each option's *title* and the *count* of votes.
The format doesn't matter, but make sure it is easy for a huamn to read...

		QUESTION
		What is the best food?
		
		RESULTS
		Pizza ......... 5 votes
		Veggie Taco ... 4 votes
		Samosas ....... 2 votes
		Sushi ......... 7 votes

Finally, make sure to close the file once you're done:

```c++
output.close();
```

# Program 2

# Program 3

# Program 4










