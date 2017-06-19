# CS 200 Lab 03b: Arrays - Helper

## Introduction

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

---

## Keeping track of the array size

C++ doesn't automatically keep track of how many elements are in the array, so we will have to keep track of the size ourselves with an integer variable.

We can also use a variable to get an element of the list, rather than using hard-coded numbers like names[0], names[1]. If a variable is an integer, we can access a specific element of the list like: **names[varName]**.

```c++
int current = 2;
cout << names[ current ] << endl;
// This displays item at index 2.
```

---

## Creating arrays that are bigger than we need

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

