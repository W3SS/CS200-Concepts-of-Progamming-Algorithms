# CS 200 Lab 13: Group Pointer Project

## Topics

* Pointers
* Address-of Operator


## Turn-in

Zip up the Visual Studio project, including all the source files (.cpp, .hpp)

When you're uploading your source to the Dropbox.

Add the name of all people in your team in the upload comments.

**Put everybody's name in the comments**

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

## Student struct

* name, a string (public)
* ptrSchool, a College pointer (public)

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
3. Display the student's college via the ptrSchool pointer. You will need to either dereference
the ptrSchool pointer, or use the member-of operator.
4. Display the student's state via the ptrSchool pointer. You will need to either dereference
the ptrSchool pointer, or use the member-of operator.
