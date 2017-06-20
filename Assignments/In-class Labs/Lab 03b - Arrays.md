# CS 200 Lab 03b: Arrays

---

[Information](#information) |
[Helper]() |
[Lab](#lab) | [
Questions](#questions)

---

# Information

## Lab topics

* Functions

## Rules

* For **in-class labs**, collaboration is allowed.
    * If you work with another student on an assignment, make sure that you both
    turn in a copy of the work, and also mention in the D2L comments who you worked with.
    * You can also ask classmates questions if you're unsure on something.
    * You can ask the instructor for help at any time.

## Reference

* [Creating a new project in Visual Studio](https://github.com/Rachels-Courses/Course-Common-Files/blob/master/Visual-Studio/New%20project%20howto.md)

## Turn in

Once you are finished with a project, zip up the entire folder that contains
all source files and project/solution files. Turn in this zip file to **Desire2Learn**.

Also make sure to turn in a text file with your answers to the [question](#questions) section.



![horizontal rule](images/hr.png)


# Lab

Start off with the following code:

```c++
#include <iostream>
#include <string>
using namespace std;

void Program1()
{
}

void Program2()
{
}

void Program3()
{
}

void Program4()
{
}

void Program5()
{
}

void Program6()
{
}

int main()
{
    bool done = false;

    while ( !done )
    {
        int choice;
        cout << "0. QUIT" << endl;
        cout << "1. Program 1" << endl;
        cout << "2. Program 2" << endl;
        cout << "3. Program 3" << endl;
        cout << "4. Program 4" << endl;
        cout << "5. Program 5" << endl;
        cout << "6. Program 6" << endl;
        cout << endl << ">> ";
        cin >> choice;

        switch( choice )
        {
            case 0: done = true; break;
            case 1: Program1(); break;
            case 2: Program2(); break;
            case 3: Program3(); break;
            case 4: Program4(); break;
            case 5: Program5(); break;
            case 6: Program6(); break;
        }
    }
    
	return 0;
}
```

Your lab programs will go in each function that matches the program name


---

## Program 1: Create an array of names

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


### Note: Keeping track of the array size

C++ doesn't automatically keep track of how many elements are in the array, so we will have to keep track of the size ourselves with an integer variable.

We can also use a variable to get an element of the list, rather than using hard-coded numbers like names[0], names[1]. If a variable is an integer, we can access a specific element of the list like: **names[varName]**.

```c++
int current = 2;
cout << names[ current ] << endl;
// This displays item at index 2.
```


### Hints

<details>
	<summary><strong>
		Program solution
	</strong></summary>
	
```c++
void Program1()
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
}
```

</details>


---

## Program 2: Keeping track of the amount of items in the list

Modify Program 1 to do the following (but put this program in the ```Program2()``` function)

1. Erase the cout with all the elements - we are going to do this with a loop.
2. Create a variable called **index**, and assign it to 0.
3. Create a variable called **arraySize**, and assign it to 5.
4. Create a while loop. Its condition will be, "continue looping while index is less than arraySize". Within the loop:
	1. Display the array element at position *index*.
	2. Increment index by 1.

### Hints

<details>
	<summary><strong>
		Program solution
	</strong></summary>

```c++
void Program2()
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
}
```
</details>

### Note: Creating arrays that are bigger than we need

Sometimes, we might create an array that is bigger than what we actually need. Because we can't resize the arrays while the program is running, we have to overshoot the amount of items we need so that we can store everything.

Because of this, we might have 100 elements but only be storing information in, say, items 0 through 15. Any elements after position 15 will have "garbage data" in them because they haven't been initialized.

This is fine - but we now also have to keep track of the items in our list, as well as the array size.

Therefore, for our list of 100 names, with only 15 names currently being stored in it, our **arraySize** integer variable would be 100, and our **itemCount** integer variable would be 15.

This also helps because we can check to see if an array is full before adding a new item: if **arraySize == itemCount**, then the array is full, and don't allow any more items added to the list.

Second, **itemCount** is useful because it also ends up tracking **the next available index** in the array: it starts at 0, we add our first item at position 0, then it increments to 1, which is where we will add our next item.

Here is some sample code:

```c++
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
```

It might take some practice to get used to, so let's get to it!

---

### Program 3: Two arrays

1. Declare an array of strings. Its name is **items** and its size is 3.
2. Declare an array of floats. Its name is **prices** and its size is 3.
3. Declare an integer named **arraySize**. Set it to 3.
4. Declare an integer named **itemCount**. Set it to 0.
5. Create a while loop... while the itemCount is less than the arraySize:
	1. Display a message to the user: "Enter item name: " (cout)
	2. Get the user's input and store it in **items** at the position **itemCount**. (cin)
	3. Display a message to the user: "Enter price: "
	4. Get the user's input and store it in the **prices** array at the position **itemCount**
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

**Sample output:**

		Enter item name: hamburger
		Enter price: 5.99
		Enter item name: burrito
		Enter price: 3.99
		Enter item name: churro
		Enter price: 0.99

		Item #0: hamburger, $5.99
		Item #1: burrito, $3.99
		Item #2: churro, $0.99

### Hints

<details>
<summary><strong>
	Declaring the arrays
</strong></summary>

```c++
string items[3];
float prices[3];
```

</details>


<details>
<summary><strong>
	While loop to fill the arrays
</strong></summary>

```c++
while ( itemCount < arraySize )
{
	cout << "Enter item name: ";
	cin >> items[itemCount];
	cout << "Enter price: ";
	cin >> prices[itemCount];
	itemCount++;
}
```

</details>


<details>
<summary><strong>
	Displaying the array contents
</strong></summary>

```c++
int counter = 0;
while ( counter < itemCount )
{
	cout << "Item #" << counter << ": " << items[counter] << ", $" << prices[counter] << endl;
	counter++;
}

```

</details>

---


### Program 4: Using a for-loop with an array

Start with the following:

```c++
void Program4()
{
	string letters[5] = { "A", "B", "C", "D", "E" };
}
```

This creates an array named **letters** and assigns A, B, C, D, and E as items in the array.

Add a for loop that iterates over every element of the **letters** array
and displays it to the screen.

### Hints

<details>
<summary><strong>
	The for loop
</strong></summary>

```c++
for ( int i = 0; i < 5; i++ )
{
	cout << letters[i] << endl;
}
```

</details>


---


### Program 5: More for loops with an array

Modify Program 3 to use two for-loops instead of two while-loops.

Make sure to put this code in the Program5() function.

### Hints

<details>
<summary><strong>
	The for loop
</strong></summary>

```c++
for ( int counter = 0; counter < itemCount; counter++ )
```

</details>

---

### Program 6: More loops with an array!

Start with the following code:

```c++
void Program6()
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
```

Write a for-loop that iterates over all elements of the array that contain a value,
displaying the value of each element.


### Hints

<details>
<summary><strong>
	The for loop
</strong></summary>

```c++
for ( int i = 0; i < itemCount; i++ )
```

</details>







![horizontal rule](images/hr.png)


# Questions

1. What is an array index?
2. What is an array element?
3. If we have an array of size 5, what are the valid indices of the array?
4. What happens if we [go outside the bounds of the array?](https://github.com/Rachels-Courses/Course-Common-Files/blob/organized/STUDENT_REFERENCE/REVIEW/Common_errors.md)
