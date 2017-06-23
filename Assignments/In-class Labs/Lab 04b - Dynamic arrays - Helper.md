# CS 200 Lab 04b: Dynamic variables and arrays - Helper

# Dynamic Variables

We can create new variables and arrays dynamically. With arrays, we no longer need to
know the size of the array at compile-time, but we can decide that at run-time. For
example, we could ask the user for the amount of items, and then create an array of that
size.

To create dynamic variables and arrays, we need to use pointers. Remember that a
pointer points to a memory address. By using the **new** keyword, we can allocate memory
through a pointer – it will point to a new address, and have that memory address
prepared for whatever we've created.

But, unlike our normal variables, dynamic variables do not free their memory
automatically. This means, we have to manually free that memory with the delete
keyword. So, a good practice to start with is, any time we write a **new** keyword, we also
need a **delete** somewhere.

If you don't free your allocated memory, you will get a memory leak. If your program
allocates a lot of memory and never frees it, it will eat up RAM and cause system
problems – you can't get that memory back until the user resets their computer.

## Dynamic Variable Reference

Here are the steps to creating a new dynamic variable:

<table>
<tr>
<th>Code</th>
<th>Description</th>
</tr>

<tr>
<td><pre>
string* dynamicString;
</pre></td>

<td>
Create a pointer variable.
</td>
</tr>

<tr>
<td><pre>
dynamicString = new string;
</pre></td>

<td>
Create a new string with the pointer.
</td>
</tr>

<tr>
<td><pre>
*dynamicString = "Hello!";
</pre></td>

<td>
Assign a value to our new variable.
(must go through the pointer – use the
de-reference operator)
</td>
</tr>

<tr>
<td><pre>
cout << *dynamicString << endl;
</pre></td>

<td>
Display the value of the variable.
</td>
</tr>

<tr>
<td><pre>
delete dynamicString;
</pre></td>

<td>
Free up the memory when done.
</td>
</tr>
</table>

---

# Dynamic Arrays

The **new** and **delete** keywords can be used to make arrays, too. With dynamic arrays,
you don't need to estimate the size of an array – which wastes memory, and could have
problems if you run out of array space!

You also create dynamic arrays through pointers. Remember that you will still need to
delete whatever you create with new!

## Dynamic Array Reference


<table>
<tr>
<th>Code</th>
<th>Description</th>
</tr>

<tr>
<td><pre>
float* prices;
</pre></td>

<td>
Create a pointer variable.
</td>
</tr>

<tr>
<td><pre>
prices = new float[ 5 ];
</pre></td>

<td>
Allocate memory as an array.
</td>
</tr>

<tr>
<td><pre>
for ( int i = 0; i < 5; i++ )
{
        prices[i] = i * 2;
        cout << prices[i] << endl;
}
</pre></td>

<td>
Assign values and display the values.
</td>
</tr>

<tr>
<td><pre>
delete [] prices;
</pre></td>

<td>
Free the memory up afterward.
</td>
</tr>
</table>

Note that with dynamic arrays, you don't need to use the de-reference operator when
accessing elements of the array – just treat it like a normal array!

You can also set a dynamic array's size based on a variable value:

        int size;
        cout << "Size: ";
        cin >> size;
        
        float* prices;
        prices = new float[ size ];
        // ...
        
        delete [] prices;

So they are very useful for all sorts of applications!


