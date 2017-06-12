# CS 200 Lab 02a: File I/O - Helper


## Introduction

### File I/O

Currently, we can output text to the screen with ```cout``` and get input
directly from the keyboard using ```cin```.

Sometimes, we may want to read data from a text file, or write data to
a text file. We can't use ```cin``` and ```cout``` for this, but
there is a related library that we can do this with.

First, we will have to include the file stream library:

```c++
#include <fstream>
```

And we will have to create a variable in order to write out to a file
or read in from a file.

```c++
ofstream outputFile;    // write to a file
ifstream inputFile;     // read from a file
```

For each of these, you will need to **open** a file for this variable
to work with.

```c++
outputFile.open( "program_out.txt" );
inputFile.open( "input.txt" );
```

and, to skip ahead a bit, once we're done dealing with our text files,
we need to make sure to **close** them afterward.

```c++
outputFile.close();
inputFile.close();
```

In-between, using these file streams are similar to how we use
```cin``` and ```cout```.

---

#### Writing out to a text file

When we want to write a message **to the screen**, we use ```cout```:

```c++
cout << "Hello, world!" << endl;
```

Writing to a text file is similar, except that we need to use our
```ofstream``` variable:

```c++
ofstream outputFile;
outputFile.open( "program_out.txt" );

outputFile << "Hello, world!" << endl;

outputFile.close();
```

After you build and run the program, no output will be written to the
screen, but when you open your program's directory, there will
be a **program_out.txt** file.

You can use ```"\n"```, ```"\t"```, and ```endl``` commands with
the file stream just like you can with ```cout```.

---

#### Reading from a text file

When we want to get input directly from the user, we use ```cin```:

```c++
string name;
cin >> name;
```

We can also read in input from a text file. For example, let's
say we had a list of all classes. The text file looked like

classes.txt:
        
        cs134 cs200 cs235 cs250

In our program, we would have to open this text file, and read in one
word at a time.

```c++
string class1, class2, class3, class4;

ifstream inputFile;
inputFile.open( "classes.txt" );

inputFile >> class1;    // Read "cs134"
inputFile >> class2;    // Read "cs200"
inputFile >> class3;    // Read "cs235"
inputFile >> class4;    // Read "cs250"

inputFile.close();
```

#### Reading a full line

Whether we're using ```cin >>``` or ```inputFile >>```, each of these
will only read in **one word at a time** and will stop at any spaces.

If we want to get a full line of text from our input file, we need
to use the ```getline``` function.

First, let's say you're entering a person's full name using ```cin```.
We would use ```getline``` like this:

```c++
string name;
getline( cin, name );
```

We have to pass in ```cin``` as the first input of the function,
and ```name``` as the second input.

If we're dealing with a text file, such as a file where full names
are on each line of the text file...

authors.txt:

       margaret atwood
       suzette haden elgin
       julia serano

Then we could use ```getline``` to get a full line of text at a time:

```c++
string author1, author2, author3;
ifstream inputFile;
inputFile.open( "authors.txt" );

getline( inputFile, author1 );  // read "margaret atwood"
getline( inputFile, author2 );  // read "suzette haden elgin"
getline( inputFile, author3 );  // read "julia serano"

inputFile.close();
```







