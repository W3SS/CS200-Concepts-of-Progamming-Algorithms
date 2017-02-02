# Homework Project 1: Mars Experiment

## Downloads

Download the **starter project**. This folder contains the code, as well as a Visual Studio project and a Code::Blocks project.

Extract the zip file somewhere to your hard drive.

**To open in Visual Studio**

Open the following file:

	project files/HP1 - Visual Studio/HP1 - Visual Studio.sln

This is marked as "Microsoft Visual Studio Solution" in Windows.

**To open in Code::Blocks**

Open the following file:

	project files/HP1 - CodeBlocks/HP1 - CodeBlocks.cbp

This is marked as "CBP File" in Windows.

## Rules

* Open book / Open note:

	* Do research for this assignment as-needed. Use your textbook, the web, class example code, etc.
 
* Solo work:

	* This is a solo assignment and you should be working on this alone. This means...:
	
    	* ✓ You can verbally brainstorm with others to discuss the problem and techniques for problem solving.
    	* ✓ Your work must be your own work.
    	* ✓ Email the instructor, or ask in the Slack channel, if you are stuck or need clarification on the instructions.
    	* ✗ You cannot give your code to somebody else for them to "verify their work" with (more often than not they just copy it, and then you both get 0%!)
    	* ✗ You cannot copy another student's work. I will use a diff tool to compare student assignments (and code online). If there is obvious copying, all people involved will receive a 0%.

## Turn in

When you're ready to turn in your work, upload the following files:

	hp1_program.hpp
	hp1_program.cpp

file to your GitHub repository, and to the D2L Dropbox.

---

# Introduction

For this program, you will be setting *mission parameters* for a Mars
mission, including the amount of resources produced and consumed
each day.

After setting up the variables, running the simulation will tell you
whether or not your team survives the mission.

## Review

* Variables
* Console input (cin) and console output (cout)
* If statements
* While loops
* Functions

## Files

This program contains a lot of source files, as well as a **class**!

We haven't gone over classes yet, but you won't have to do any
modifications of the class itself... The class is named Program,
and contains variables and functions. You will interact with
the variables that are part of the program through these functions:

	// Functions you will implement:
	void DisplayMenu();
	void SetParameters();
	void ViewParameters();
	void RunSimulation();

	void AdjustFood();
	void AdjustWaste();
	void AdjustOxygen();

	int GetValidInput(int min, int max);

	// These are already implemented:
	void SetFoodGrown_PerDay(int value);
	void SetCleanup_PerPersonPerDay(int value);
	void SetTeamSize(int value);
	void SetMissionLength(int value);
	void SetTeamName(string value);

	void SetFoodCount(int value);
	void SetWasteCount(int value);
	void SetOxygenCount(int value);

	int GetFoodGrown_PerDay();
	int GetCleanup_PerPersonPerDay();
	int GetTeamSize();
	int GetMissionLength();
	string GetTeamName();

	int GetFoodConsumed_PerPersonPerDay();
	int GetWasteCreated_PerPersonPerDay();
	int GetOxygenUsed_PerPersonPerDay();
	int GetOxygenCreated_PerDay();

	int GetFoodCount();
	int GetWasteCount();
	int GetOxygenCount();

Within the *hp1_program.cpp* file, you will implement the function
logic (except the Getters and Setters).

There are comments in the source file to help you along as well.

## Unit tests

When you first run the program, it will ask if you want to run tests.
If you hit "y", you will be able to choose some tests to run.

These can help you validate that your AdjustFood(), AdjustWaste(), and
AdjustOxygen() functions are working correctly.

## Program built

main() has already been written, and a lot of the program will
take care of itself - but you will need to implement
certain functions for things to work correctly. 

---

# Don't write everything at once.

Don't write a ton of code all at once - write a small feature, then COMPILE to make sure your program builds, and run to make sure it runs.

---

# Function Specifications

## DisplayMenu()

Inputs: None

Outputs: None

This function should just display a simple # list and header, such as:

1. Set mission parameters, 
2. View parameters, 
3. Run simulation, 
4. Quit

## SetParameters()

Inputs: None

Outputs: None

In this function, we will get the user's input for the following fields:

- food grown per day (int)	
- cleanup per person per day (int)
- team name	(string)			
- team size (int)
- mission length in days (int)	
- starting units of food (int)

Create variables for each of these. Prompt the user for each
of these items with a cout command ("please enter ___:"),
and get their input through cin.

Finally, once those are all entered, you will use the following functions
to set these variables in the simulator:

- SetFoodGrown_PerDay(int)		
- SetCleanup_PerPersonPerDay(int)
- SetTeamName(string)			
- SetTeamSize(int)
- SetMissionLength(int)			
- SetFoodCount(int)

## ViewParameters()

Inputs: None

Outputs: None

In this function, you will just display the parameters that were entered
in the SetParameters() function. You can do this by utilizing the "getter"
functions available to the simulation...:

- GetFoodConsumed_PerPersonPerDay()			
- GetWasteCreated_PerPersonPerDay()
- GetOxygenCreated_PerDay()					
- GetOxygenUsed_PerPersonPerDay()
- GetFoodGrown_PerDay()						
- GetCleanup_PerPersonPerDay()
- GetTeamName()								
- GetTeamSize()
- GetMissionLength()

All of these functions *return* a value - either ints or strings.
You can cout each of these, like:
cout << GetOxygenUsed_PerPersonPerDay() << endl;

Just display each value, but also make sure to display a label for each.

## AdjustFood()

Inputs: None

Outputs: None

This function deals with the following functions:

- GetFoodGrown_PerDay()		
- GetFoodConsumed_PerPersonPerDay()		
- GetFoodCount()			
- GetTeamSize()

It will calculate the amount of food produced and consumed,
and update the food count.

First, create a temporary local int variable, named something like "foodCount".
Assign it the return value of the GetFoodCount() function.

Then, adjust the food count with the formula:

	new food count = old food count + food grown per day - ( food consumed per person per day * team size )

After the calculation, update the food count using SetFoodCount(int).

## AdjustOxygen()

Inputs: None

Outputs: None

This function deals with the following functions:

- GetOxygenCount()		
- GetOxygenCreated_PerDay()
- GetTeamSize()			
- GetOxygenUsed_PerPersonPerDay()

Create a temporary variable and assign it the value of GetOxygenCount().

Calculate the new oxygen count with the formula:

	new oxygen count = old oxygen count + oxygen created per day - (oxygen used per person per day * team size)

After the calculation, update the oxygen count using SetOxygenCount(int).

## RunSimulation()

Inputs: None

Outputs: None

The simulation runs through each day, adjusting values to see if
the astronauts can survive for the set amount of days.

### 1. Set up the simulation

1. Create an integer variable called day, and initialize it to 1.
2. Use SetOxygenCount(int) to initialize the oxygen count to 100.
3. Use SetWasteCount(int) to initialize the waste count to 0.
4. Create a boolean variable called missionSuccess, and set it to true.

### 2. Simulation loop

Create a while loop. This will continue looping while
the day is less than the mission length (GetMissionLength()),
and while missionSuccess is true.

#### Within the loop...

Adjust current supplies via the AdjustFood(), AdjustWaste(), and AdjustOxygen() functions.

Display the following values, and make sure to label them as well. Example:

	 cout << "LABEL: " << values << endl;

Display:

* The current day
* Food grown				
	* GetFoodGrown_PerDay()
* Waste cleaned			
	* GetCleanup_PerPersonPerDay()
* Oxygen created			
	* GetOxygenCreated_PerDay()
* Food consumed			
	* GetFoodConsumed_PerPersonPerDay()
* Waste created			
	* GetWasteCreated_PerPersonPerDay
* Oxygen consumed		
	* GetOxygenUsed_PerPersonPerDay
* Current food count		
	* GetFoodCount()
* Current waste count	
	* GetWasteCount()
* Current oxygen count	
	* GetOxygenCount()

Check to see if the resources have been depleted. If so, then the mission is a failure.

* If food count is less than 0, display a message that they ran out of food and set missionSuccess to false.
* If waste count is greater than 20, display a message that they drowned in trash and set missionSuccess to false.
* If oxygen count is less than 0, display a message that they ran out of air and set missionSuccess to false.

Finally, increment the **day** variable by 1.

### 3. After the simulation ends

After the while loop: Display the results.

If missionSuccess is true, display "MISSION SUCCESS!". 
Otherwise, display "MISSION FAILURE!"


## GetValidInput(int, int)

Inputs: min (int), max (int)

Outputs: int

This function takes in a minimum and maximum value that
can be entered by the user.

First, prompt the user for input with a cout statement.
Create a variable (int) to store their decision,
and get the user's input with cin.

Then, create a while loop that will keep asking the user
to re-enter their selection, WHILE the input is invalid.

Invalid input is if it is < min or > max.

After the while loop (once the input is valid), return
the variable that is storing the user's choice.

---

# Grading rubric

<table border="0" cellspacing="0" cellpadding="0" class="ta1"><colgroup><col width="12"/><col width="200"/><col width="256"/><col width="163"/><col width="162"/></colgroup><tr class="ro1"><td style="text-align:left;width:7.71pt; " class="Default"> </td><td colspan="4" style="text-align:left;width:129.91pt; " class="ce1"><p>Grading Rubric</p></td></tr><tr class="ro1"><td style="text-align:left;width:7.71pt; " class="Default"> </td><td style="text-align:left;width:129.91pt; " class="ce2"><p>Name:</p></td><td colspan="3" style="text-align:left;width:165.94pt; " class="ce7"> </td></tr><tr class="ro1"><td style="text-align:left;width:7.71pt; " class="Default"> </td><td style="text-align:left;width:129.91pt; " class="ce2"><p>Assignment:</p></td><td colspan="3" style="text-align:left;width:165.94pt; " class="ce8"><p>HP1: Mars Experiment, CS 200</p></td></tr><tr class="ro2"><td style="text-align:left;width:7.71pt; " class="Default"> </td><td style="text-align:left;width:129.91pt; " class="Default"> </td><td style="text-align:left;width:165.94pt; " class="Default"> </td><td style="text-align:left;width:105.76pt; " class="Default"> </td><td style="text-align:left;width:104.94pt; " class="Default"> </td></tr><tr class="ro1"><td style="text-align:left;width:7.71pt; " class="Default"> </td><td colspan="4" style="text-align:left;width:129.91pt; " class="ce1"><p>Breakdown</p></td></tr><tr class="ro1"><td style="text-align:left;width:7.71pt; " class="Default"> </td><td style="text-align:left;width:129.91pt; " class="ce3"><p>Item</p></td><td style="text-align:left;width:165.94pt; " class="ce3"><p>Description</p></td><td style="text-align:left;width:105.76pt; " class="ce3"><p>Total %</p></td><td style="text-align:left;width:104.94pt; " class="ce3"><p>Your Score</p></td></tr><tr class="ro1"><td style="text-align:left;width:7.71pt; " class="Default"> </td><td style="text-align:left;width:129.91pt; " class="ce4"><p>Builds and runs</p></td><td style="text-align:left;width:165.94pt; " class="ce9"> </td><td style="text-align:right; width:105.76pt; " class="ce13"><p>5.00%</p></td><td style="text-align:left;width:104.94pt; " class="ce13"> </td></tr><tr class="ro1"><td style="text-align:left;width:7.71pt; " class="Default"> </td><td style="text-align:left;width:129.91pt; " class="ce5"><p>Clean code</p></td><td style="text-align:left;width:165.94pt; " class="ce10"> </td><td style="text-align:right; width:105.76pt; " class="ce14"><p>5.00%</p></td><td style="text-align:left;width:104.94pt; " class="ce14"> </td></tr><tr class="ro1"><td style="text-align:left;width:7.71pt; " class="Default"> </td><td style="text-align:left;width:129.91pt; " class="ce4"><p>No logic errors</p></td><td style="text-align:left;width:165.94pt; " class="ce9"> </td><td style="text-align:right; width:105.76pt; " class="ce13"><p>5.00%</p></td><td style="text-align:left;width:104.94pt; " class="ce13"> </td></tr><tr class="ro1"><td style="text-align:left;width:7.71pt; " class="Default"> </td><td style="text-align:left;width:129.91pt; " class="ce5"><p>No runtime errors</p></td><td style="text-align:left;width:165.94pt; " class="ce10"> </td><td style="text-align:right; width:105.76pt; " class="ce14"><p>5.00%</p></td><td style="text-align:left;width:104.94pt; " class="ce14"> </td></tr><tr class="ro1"><td style="text-align:left;width:7.71pt; " class="Default"> </td><td style="text-align:left;width:129.91pt; " class="ce4"><p>DisplayMenu()</p></td><td style="text-align:left;width:165.94pt; " class="ce9"> </td><td style="text-align:right; width:105.76pt; " class="ce13"><p>5.00%</p></td><td style="text-align:left;width:104.94pt; " class="ce13"> </td></tr><tr class="ro1"><td style="text-align:left;width:7.71pt; " class="Default"> </td><td style="text-align:left;width:129.91pt; " class="ce5"><p>SetParameters()</p></td><td style="text-align:left;width:165.94pt; " class="ce10"> </td><td style="text-align:right; width:105.76pt; " class="ce14"><p>15.00%</p></td><td style="text-align:left;width:104.94pt; " class="ce14"> </td></tr><tr class="ro1"><td style="text-align:left;width:7.71pt; " class="Default"> </td><td style="text-align:left;width:129.91pt; " class="ce4"><p>ViewParameters()</p></td><td style="text-align:left;width:165.94pt; " class="ce9"> </td><td style="text-align:right; width:105.76pt; " class="ce13"><p>15.00%</p></td><td style="text-align:left;width:104.94pt; " class="ce13"> </td></tr><tr class="ro1"><td style="text-align:left;width:7.71pt; " class="Default"> </td><td style="text-align:left;width:129.91pt; " class="ce5"><p>RunSimulation()</p></td><td style="text-align:left;width:165.94pt; " class="ce10"> </td><td style="text-align:right; width:105.76pt; " class="ce14"><p>20.00%</p></td><td style="text-align:left;width:104.94pt; " class="ce14"> </td></tr><tr class="ro1"><td style="text-align:left;width:7.71pt; " class="Default"> </td><td style="text-align:left;width:129.91pt; " class="ce4"><p>AdjustFood()</p></td><td style="text-align:left;width:165.94pt; " class="ce9"> </td><td style="text-align:right; width:105.76pt; " class="ce13"><p>5.00%</p></td><td style="text-align:left;width:104.94pt; " class="ce13"> </td></tr><tr class="ro1"><td style="text-align:left;width:7.71pt; " class="Default"> </td><td style="text-align:left;width:129.91pt; " class="ce5"><p>AdjustWaste()</p></td><td style="text-align:left;width:165.94pt; " class="ce10"> </td><td style="text-align:right; width:105.76pt; " class="ce14"><p>5.00%</p></td><td style="text-align:left;width:104.94pt; " class="ce14"> </td></tr><tr class="ro1"><td style="text-align:left;width:7.71pt; " class="Default"> </td><td style="text-align:left;width:129.91pt; " class="ce4"><p>AdjustOxygen()</p></td><td style="text-align:left;width:165.94pt; " class="ce9"> </td><td style="text-align:right; width:105.76pt; " class="ce13"><p>5.00%</p></td><td style="text-align:left;width:104.94pt; " class="ce13"> </td></tr><tr class="ro1"><td style="text-align:left;width:7.71pt; " class="Default"> </td><td style="text-align:left;width:129.91pt; " class="ce5"><p>GetValidInput()</p></td><td style="text-align:left;width:165.94pt; " class="ce10"> </td><td style="text-align:right; width:105.76pt; " class="ce14"><p>10.00%</p></td><td style="text-align:left;width:104.94pt; " class="ce14"> </td></tr><tr class="ro1"><td style="text-align:left;width:7.71pt; " class="Default"> </td><td style="text-align:left;width:129.91pt; " class="ce5"> </td><td style="text-align:left;width:165.94pt; " class="ce10"> </td><td style="text-align:left;width:105.76pt; " class="ce14"> </td><td style="text-align:left;width:104.94pt; " class="ce14"> </td></tr><tr class="ro1"><td style="text-align:left;width:7.71pt; " class="Default"> </td><td style="text-align:left;width:129.91pt; " class="ce6"> </td><td style="text-align:left;width:165.94pt; " class="ce6"> </td><td style="text-align:left;width:105.76pt; " class="ce15"> </td><td style="text-align:left;width:104.94pt; " class="ce15"> </td></tr><tr class="ro1"><td style="text-align:left;width:7.71pt; " class="Default"> </td><td style="text-align:left;width:129.91pt; " class="ce2"><p>Totals</p></td><td style="text-align:left;width:165.94pt; " class="ce2"> </td><td style="text-align:left;width:105.76pt; " class="ce15"> </td><td style="text-align:left;width:104.94pt; " class="ce15"> </td></tr><tr class="ro1"><td style="text-align:left;width:7.71pt; " class="Default"> </td><td style="text-align:left;width:129.91pt; " class="ce6"> </td><td style="text-align:left;width:165.94pt; " class="ce6"> </td><td style="text-align:right; width:105.76pt; " class="ce15"><p>100.00%</p></td><td style="text-align:right; width:104.94pt; " class="ce17"><p>0.00%</p></td></tr><tr class="ro1"><td style="text-align:left;width:7.71pt; " class="Default"> </td><td style="text-align:left;width:129.91pt; " class="ce6"> </td><td style="text-align:left;width:165.94pt; " class="ce6"> </td><td style="text-align:left;width:105.76pt; " class="ce6"> </td><td style="text-align:left;width:104.94pt; " class="ce6"> </td></tr><tr class="ro2"><td style="text-align:left;width:7.71pt; " class="Default"> </td><td style="text-align:left;width:129.91pt; " class="Default"> </td><td style="text-align:left;width:165.94pt; " class="Default"> </td><td style="text-align:left;width:105.76pt; " class="Default"> </td><td style="text-align:left;width:104.94pt; " class="Default"> </td></tr><tr class="ro2"><td style="text-align:left;width:7.71pt; " class="Default"> </td><td style="text-align:left;width:129.91pt; " class="Default"> </td><td style="text-align:left;width:165.94pt; " class="Default"> </td><td style="text-align:left;width:105.76pt; " class="Default"> </td><td style="text-align:left;width:104.94pt; " class="Default"> </td></tr><tr class="ro2"><td style="text-align:left;width:7.71pt; " class="Default"> </td><td style="text-align:left;width:129.91pt; " class="Default"> </td><td style="text-align:left;width:165.94pt; " class="Default"> </td><td style="text-align:left;width:105.76pt; " class="Default"> </td><td style="text-align:left;width:104.94pt; " class="Default"> </td></tr><tr class="ro2"><td style="text-align:left;width:7.71pt; " class="Default"> </td><td style="text-align:left;width:129.91pt; " class="Default"> </td><td style="text-align:left;width:165.94pt; " class="Default"> </td><td style="text-align:left;width:105.76pt; " class="Default"> </td><td style="text-align:left;width:104.94pt; " class="Default"> </td></tr><tr class="ro2"><td style="text-align:left;width:7.71pt; " class="Default"> </td><td style="text-align:left;width:129.91pt; " class="Default"> </td><td style="text-align:left;width:165.94pt; " class="Default"> </td><td style="text-align:left;width:105.76pt; " class="Default"> </td><td style="text-align:left;width:104.94pt; " class="Default"> </td></tr><tr class="ro2"><td style="text-align:left;width:7.71pt; " class="Default"> </td><td style="text-align:left;width:129.91pt; " class="Default"> </td><td style="text-align:left;width:165.94pt; " class="Default"> </td><td style="text-align:left;width:105.76pt; " class="Default"> </td><td style="text-align:left;width:104.94pt; " class="Default"> </td></tr><tr class="ro1"><td style="text-align:left;width:7.71pt; " class="Default"> </td><td colspan="4" style="text-align:left;width:129.91pt; " class="ce1"><p>Notes</p></td></tr></table>