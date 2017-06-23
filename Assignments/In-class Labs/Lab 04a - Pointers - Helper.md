# CS 200 Lab 04a: Pointers - Helper

# Memory Addresses

Any time we create a variable, that variable requires some memory from our computer. Different types
of variables require different amounts of memory – Booleans and characters need 1 byte (8 bits),
integers and floats need 4 bytes, and doubles need 8 bytes.

The following 8 bits (1 byte) makes up the number 65, which in ASCII represents the character ‘A’.
So, ‘A’ in binary is 01000001.

<table>
<tr><td>Bit Position</td>
<td>128</td><td>64</td><td>32</td><td>16</td><td>8</td><td>4</td><td>2</td><td>1</td>
</tr>

<tr><td>Value</td>
<td>0</td><td>1</td><td>0</td><td>0</td><td>0</td><td>0</td><td>0</td><td>1</td>
</tr>
</table>

This is just the value, however. When we tell the program that we need 1 byte in order to store a
character, we reserve a memory address to store any character in this space.

<table>
<tr><th>C++</th><th>Translation</th></tr>

<tr><td>char choice;</td><td>I need 1 byte to store some character.<br>Allocate 1 byte at memory address 0x7fff95.</td></tr>
<tr><td>choice = 'Y';</td><td>Assign the value of <strong>01011001</strong> (Y) to address 0x7ff95.</td></tr>
</table>

Every time we run a program, even if the code is the same, each variable will get a different memory
address – it takes any space that is available, and memory is shared across all applications on a
computer. While your program is using memory address 0x7fff95 , no other programs should be able
to access that memory – They can, if the code is written poorly or if it is a malicious program, but in
general the memory allocated for your program is just used for your program until the program ends.

In C++, the “Address-of” operator is the ampersand: &. If you put this operator before a variable name,
you will get its memory address. (Note that this is not the reference operator – same symbol, different
context.)

<table>
<tr><th>C++</th><th>Output</th></tr>

<tr><td>
<pre>
int myNumber;
cout << &myNumber << endl;
</pre>
</td><td>
<pre>
0x69feec
</pre>
</td></tr>
</table>

Arrays are also variables and have memory addresses, but you do not need the address-of operator to
get its address:

<table>
<tr><th>C++</th><th>Output</th></tr>

<tr><td>
<pre>
int myNumbers[20];
cout << myNumbers << endl;
</pre>
</td><td>
<pre>
0x69fe9c
</pre>
</td></tr>
</table>

---

# Pointers

Pointers are a type of variable that stores a memory address. So, instead of storing a value like “Hello,
World!” or 4.99, it would store the address to another variable.

A pointer’s data-type needs to match the kind of data that it will point to, but with a * at the end.

![One pointer, pointing to another variable.](https://github.com/Rachels-Courses/Course-Common-Files/blob/master/Artwork/Cuties/pointer.png?raw=true)

SO remember, if we wanted to output the address of a variable, we would use:

        cout << &myName << endl;

And we use the same if we want to assign its address to a *pointer*.

        int myNumber = 10;
        string myName = "Bob";
        float myPrice = 9.99;
        
        int* ptrInteger = &myNumber;
        string* ptrString = &myName;
        float* ptrFloat = &myPrice;

If we cout the pointer, it will give us the same value as if we had output the variable with the address-of
operator. So, both of these statements would output the same thing:

        cout << &myName << endl;
        cout << ptrString << endl;

---

# Dereferencing Pointers

So, we have a pointer that is pointing to a memory address. What do we do with this?

Using the de-reference operator * , we can get the value that is stored in the memory address.

Note that this * is different from when we’re declaring a pointer variable:

**Creating a pointer:**

        int* ptrInteger;
        
**Outputting the value at the pointed-to address:**

        cout << *ptrInteger << endl;
        
So, let's look at this step-by-step:

<table>
<tr><th>C++</th><th>Description</th></tr>

<tr>
<td>
<pre>
string studentA = "Ashley";
string studentB = "Kaidan";
string studentC = "Liara";
</pre>
</td>
<td>
Creating normal variables.
</td>
</tr>

<tr>
<td>
<pre>
string* ptrStudent;
</pre>
</td>
<td>
Creating a string pointer.
</td>
</tr>

<tr>
<td>
<pre>
ptrStudent = &studentA;
</pre>
</td>
<td>
Pointing *ptrStudent* to one memory address.
</td>
</tr>

<tr>
<td>
<pre>
cout << &studentA << endl;
cout << ptrStudent << endl;
</pre>
</td>
<td>
Outputting the address of a student.
</td>
</tr>

<tr>
<td>
<pre>
cout << studentA << endl;
cout << *ptrStudent << endl;
</pre>
</td>
<td>
Outputting the value of studentA, directly and through a pointer.
</td>
</tr>

<tr>
<td>
<pre>
ptrStudent = &studentB;
</pre>
</td>
<td>
Changing who *ptrStudent* is pointing to.
</td>
</tr>

</table>
