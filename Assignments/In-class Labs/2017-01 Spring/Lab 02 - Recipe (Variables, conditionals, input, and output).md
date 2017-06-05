# CS 200 Lab 2: Recipe (Variables, Input, and Output)

## Introduction

Follow along step-by-step to work on this program. 

## Review

* Variables, Data Types
* Output (cout)
* Input (cin)

  
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

## Setting up your project

### Visual Studio

1. Create a new project. *File > New > Project...*
    1. Select **Visual C++** from the left category list.
    2. Select **Empty Project** from the template list.
    3. Set the project **Name** to "CL2 Branching".
    4. Set the project **Location**.
    5. Click **OK**.
2. Create your source file. In the **Solution Explorer**, right-click your project file. *Add > New Item...*
    1. Select **C++ File (.cpp)** and name it **CL2.cpp**.
    2. Click **Add**.

### Code::Blocks

1. Create a new project. *File > New > Project...*
2. Select **Empty project** and click **Go**.
    1. Enter a **Project title** (e.x., "CL2 Branching"),
    2. Choose a **Folder to create project in**.
    3. Click **Next >**
    4. Leave defaults checked for **Compiler**, **Create "Debug" configuration**, and **Create "Release" configuration**.
    5. Click **Finish**
3. Create your source file. **File > New > Empty File*
    1. It will ask if you want to save it. Select **Yes**.
    2. Save it in your project directory as **CL2.cpp**.
    3. Click **Save**
    4. Leave the default **Debug** and **Release** checked and click **OK**.

## Starter code

Paste the following into your .cpp file to start with:

```c++
#include <iostream>
#include <string>
using namespace std;

int main()
{
    return 0;
}
```
    
---

# Assignments

## Cookies

Here are the ingredients for sugar cookies:

* 1 tsp baking soda
* 1/2 tsp baking powder
* 1 c butter
* 1 1/2 c white sugar
* 1 egg

## Step 1: Output the recipe

Using the **cout** command, output the ingredient list above.

Test the program.

### Sample output:

![Screenshot](images/cl2-00.png)

### Solution

```c++
#include <iostream>
#include <string>
using namespace std;

int main()
{
    cout << "1 tsp baking soda" << endl;
    cout << "1/2 tsp baking powder" << endl;
    cout << "1 c butter" << endl;
    cout << "1 1/2 c white sugar" << endl;
    cout << "1 egg" << endl;

    while (true); // kludgey fix
    return 0;
}
```

---

## Step 2: Store amounts in variables

1. Create variables for the following. These should be **floats** or **doubles**:

    1. teaspoons of baking soda
    2. teaspoons of baking powder
    3. cups of butter
    4. cups of white sugar
    5. amount of eggs

2. Store the default ingredient amounts in these variables.
(Use "0.5" instead of 1/2)

3. Replace the hard-coded ingredient amounts with the variables
so that they can be tweaked and the program will update the amounts.

4. Test the program to make sure it still works.

```c++
#include <iostream>
#include <string>
using namespace std;

int main()
{
    float tspBakingSoda = 2;
    float tspBakingPowder = 0.5;
    float cupsOfButter = 1;
    float cupsOfSugar = 1.5;
    float eggs = 1;

    cout << tspBakingSoda << " tsp baking soda" << endl;
    cout << tspBakingPowder << " tsp baking powder" << endl;
    cout << cupsOfButter << " c butter" << endl;
    cout << cupsOfSugar << " c white sugar" << endl;
    cout << eggs << " egg" << endl;

    while (true); // kludgey fix
    return 0;
}
```

---

## Step 3: Allow ratios

1. Create a variable called **ratio**. It should be a float or a double.

2. Ask the user how many batches they want to make, then store their input into **ratio**.
( 0.5 = half, 2.0 = double, 1.0 = normal )

3. Update the ingredient display, this time adjusting each ingredient by the ratio.

### Sample output:

![Screenshot](images/cl2-01.png)

![Screenshot](images/cl2-02.png)

```c++
#include <iostream>
#include <string>
using namespace std;

int main()
{
    float ratio;
    cout << "How many batches do you want to make? ";
    cin >> ratio;

    float tspBakingSoda = 1 * ratio;
    float tspBakingPowder = 0.5 * ratio;
    float cupsOfButter = 1 * ratio;
    float cupsOfSugar = 1.5 * ratio;
    float eggs = 1 * ratio;

    cout << tspBakingSoda << " tsp baking soda" << endl;
    cout << tspBakingPowder << " tsp baking powder" << endl;
    cout << cupsOfButter << " c butter" << endl;
    cout << cupsOfSugar << " c white sugar" << endl;
    cout << eggs << " egg" << endl;

    while (true); // kludgey fix
    return 0;
}
```

---
