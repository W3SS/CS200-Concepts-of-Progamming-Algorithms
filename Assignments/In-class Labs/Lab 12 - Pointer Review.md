# CS 200 Lab 12: Pointer review lab

## Chrome!

Please read this in chrome so that the solutions are collapsed by default!

## Topics

* Pointers
* Memory management

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

# Quick reference

* A pointer is a type of variable that stores a memory address. It is declared with a * after the data-type, and must be assigned to the address of another variable.
* To get the memory address of any variable (non-array), you prefix the variable name with &.
* If you output the pointer variable with just the variable name, you will get a memory address.
* If you output the pointer variable prefixed with the dereference operator * you will get the value at that memory address.

        string name = "Cross";
        string* ptrCurrent = &name;
        // Outputs the address of the "name" variable
        cout << ptrCurrent << endl;
        // Outputs the value of the "name" variable
        cout << *ptrCurrent << endl;
        // Updates the value of the "name" variable
        *ptrCurrent = "Singh";

<table>

<tr>
<td>Address-of operator</td>
<td>&</td>
<td><pre>
cout << &cost << endl;
</pre></td>
<td></td>
</tr>

<tr>
<td>Dereference operator</td>
<td>*</td>
<td><pre>
cout << *ptrPrice << endl;
</pre></td>
<td></td>
</tr>

<tr>
<td>Member-of operator</td>
<td>-></td>
<td><pre>
cout << ptrStudent->name << endl;
</pre></td>
<td>The member-of operator is used for classes, where with a non-pointer it would be student.name</td>
</tr>

<tr>
<td>Declaring a pointer</td>
<td></td>
<td><pre>
string* ptrStringVal;
</pre></td>
<td></td>
</tr>

<tr>
<td>Getting the address of a variable</td>
<td></td>
<td><pre>
&variableName
</pre></td>
<td></td>
</tr>

<tr>
<td>Assigning an address to a pointer</td>
<td></td>
<td><pre>
*ptrCurrent
</pre></td>
<td>Use this to get the value, or set the value at that address.</td>
</tr>

</table>

---

# Exercise: Students and Colleges

You will create two objects for this project. They can be either classes or structs, but structs might be
the simplest.

## College struct

* name, a string (public)
* state, a string (public)

```c++
struct College
{
  string name;
  string state;
};
```

(paste this code above main, outside of all functions.)

## Student struct

* name, a string (public)
* ptrSchool, a College pointer (public)

```c++
struct Student
{
  string name;
  College* ptrSchool;
};
```

(paste this code above main, outside of all functions.)

For the “ptrSchool” pointer, you will create a pointer that will point to a College object. It would be
declared as: **College* ptrSchool;**

## main() function

Create an array of 3 colleges and fill in the information:

<table>
<tr>
<th>Name</th>
<th>State</th>
</tr>

<tr>
<td>JCCC</td>
<td>KS</td>
</tr>

<tr>
<td>MCCKC</td>
<td>MO</td>
</tr>

<tr>
<td>KCKCC</td>
<td>KS</td>
</tr>
</table>

Then you will create an array of 5 students.

### Student setup

First in main, you will have the user set up each of the 5 students. Use a for-loop to iterate through each
student for the setup:

1. Output the student # (the index from the for-loop)
2. Have the user input the student name, with either a cin or a getline. Store it in the name variable
of the student object.
3. Display a list of all 3 colleges (this will be an internal for-loop). Display each college's index
(the loop index), state, and name.
4. After all colleges have been displayed, have the user enter the index of the college they wish to
assign this student to.
5. Assign the ptrSchool pointer the address of that college from the array.

### Sudent roster

Once all of the students have been set up, we need to loop back through everything and display their
information.

Use another for-loop to iterate through all students.

1. Display the student's name.
2. Display the student's ID (the index from the for-loop)
3. Display the student's college via the ptrSchool pointer.
4. Display the student's state via the ptrSchool pointer.

Note that *ptrSchool* is a pointer. To access an item's member variables through a pointer,
you need the ```->``` operator:

```c++
Student student;
// stuff

// Display the school's name
cout << student.ptrSchool->name;
```

### Example output

    Enter name for student 1: Acantha
    Which college for Acantha?
    
    1. JCCC
    2. MCCKC
    3. KCKCC
 
    >> 1
    
    Enter name for student 2: Isaak 
    Which college for Isaak?
    
    1. JCCC
    2. MCCKC
    3. KCKCC
    
    >> 2
    
    (etc)
    
    All students:
    
    1. Acantha    JCCC    KS
    2. Isaak      MCCKC   MO
    3. Vilim      KCKCC   KS
    4. Faelan     JCCC    KS
    5. Branca     MCCKC   MO
    
