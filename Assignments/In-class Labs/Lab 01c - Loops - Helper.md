# CS 200 Lab 01c: Loops - Helper


## Introduction

### While loops

While loops are similar to an if statement (without the else if or else), in that it checks a condition and
executes its internal code if that condition is true.

However, with while loops, as long as that condition stays true, the loop will continue running the same
code over and over. This can be useful for doing repetitive tasks.

```c++
while ( countdown > 0 )
{
    cout << countdown << endl;
    countdown--;
}
```

Here, if ```countdown``` is equal to 0 or less than 0, then this while
loop will never start, just like with an if statement. The program flow
will continue after the while's code block.

However, if the countdown is greater than 0, it will enter into the
while loop code block and continue looping until that **condition** evaluates
to false.

If we want a loop to execute *at least once*, then we can use a do-while loop:

```c++
int input;

do
{
    cout << "1. Option A" << endl;
    cout << "2. Option B" << endl;
    cout << "3. Option C" << endl;
    cout << "Choice: ";
    cin >> input;
} while ( input > 3 );
```

**Common error:** Make sure that, somewhere inside your while loop,
the condition is set to false at some point! If you don't, your program
will encounter an **infinite loop** and crash!

---

### For loops

A for loop is a useful type of loop if you want to do counting,
such as processing items *1 through 10*.

For loops contain three sections within their parenthesis:

```c++
for ( STARTING_CODE; LOOP_CONDITION; RUN_AFTER_EACH_LOOP )
{
}
```

* The **STARTING_CODE** is done at the beginning, before the loop starts.
We can use this to make a counter variable, or initialize some variable state.
* The **LOOP_CONDITION** is the same as with a while loop; the loop will continue
while this condition evaluates to true.
* The **RUN_AFTER_EACH_LOOP** is a small bit of code that will be executed
*after* each iteration of the loop, so we could adjust the counter variable each time...

```c++
// Display numbers 1 through 10
for ( int i = 1; i <= 10; i++ )
{
    cout << i << endl;
}
```

---

### Break and Continue

You can also use special keywords to alter the flow of your loops.

Let's say that you encounter a situation where you need to leave the loop
immediately (maybe an error or some special case) - you can use the ```break```
command to leave any loop and continue the program flow.

```c++
while ( isProcessing )
{
    if ( foundError )
    {
        break; // leave the loop!
    }
    // ...
}
```

Or, if you want to continue running the loop, but find something that
you want to skip over, you can use ```continue``` to finish this iteration
of the loop and keep going.

```c++
while ( isProcessing )
{
    if ( foundError )
    {
        continue; // stop this iteration, continue at next iteration
    }
    // ...
}
```


