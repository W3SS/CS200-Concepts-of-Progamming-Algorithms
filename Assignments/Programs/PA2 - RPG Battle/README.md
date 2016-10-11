# CS 200 Programming Assignment 2

RPG Battle

## Turn-In

Once finished with your project, you will need to turn in all
**.cpp** and **.hpp** files into the Dropbox.

## Groupwork

You are allowed to collaborate with one other classmate if you'd like.
If you work on this program as a group project, you **must** use GitHub
in order to coordinate your code - I will be checking the
commit logs to see who
worked on what portion of the program.

## Introduction

For this game, there will be a group of "players". Each player has HP (Hit Points),
so we will be storing an array of integers for HP.

The human player will be at index #0.

Each turn, the human player will select who to attack.

For the computer players (all others), they will
randomly choose who to attack.

The game will keep going, until either the player's HP is 0, or until everybody else's HP is 0.

---

# Random numbers

You will want to include the cstdlib library in order to use random numbers.

	#include <cstdlib>

And you will want to include time:

	#include <ctime>
	
First, at the beginning of the program, you will want to seed the random number generator in this way:

	srand( time( NULL ) );

Then, within the program, you can generate a number between 0 and n with:

	int randNumber = rand() % n;
	
where *n* is just some integer.

---

# Iterative development

You might want to break down this project into different features so that
you can more easily test each feature at a time.

The entire program spec is under **The Program**, but here is a suggested way of
tackling the program:

## Iteration 1

Create the array of HPs and initialize them. **( A )**

Create your game's while loop (while not done). **( B )**

Within the game loop, just remove 5 from each player's HP automatically - no user menu or input or
anything.

Write the if statements to check to see if the player loses or wins,
and make sure to stop the game loop in this case. **( C )**

Test to make sure your if statements work.

## Iteration 2

Implement the main menu which allows the player to choose who to attack. **( D )**

Adjust the chosen NPC's HP based on the player's input. **( E )**

Don't implement the NPC's attack choices.

## Iteration 3

Create the for-loop within the game loop that lets each NPC choose who to attack,
which works similarly to how the player choses their attack. **( F )**

---

# The Program

## At the beginning of the program:

1. Seed the random number generator
2. Create an **integer** variable named **round** and initialize it to 1.
3. Create an array of integers called **HP**. It is size 4. **( A )**
4. Initialize all the HP to 100. **( A )**
5. Create a **boolean** variable called **done** and initialize it to false. **( B )**

Then, create a game loop that will keep looping while **done** is false. **( B )**

## Within the game loop:

1. Display the stats screen: **( D )**
	1. Display the round #
	2. Display all the players' HP with a for-loop
	3. Ask the user who they want to attack

2. Write code to have the player attack: **( E )**
	2. Create a variable called **attackWho**, which is an integer. 
	3. Have the user input their choice and store it in **attackWho**. 
	4. After the player has selected, display a message: 
	5. "You attack player " and then the player # (attachWho). 
	6. Subtract 5 from the attacked character's HP. 

## Next, each NPC (Non-Player Character) gets to move:

1. Create a for loop that starts at 1 and ends at 3 (inclusive). Increment by 1 each time. **( F )**
2. Within the loop:
	1. You can reuse the variable **attackWho** for each of the NPC's choices.
	Generate a random number for the NPC's decision like this:
	attackWho = rand() % 4; // Between 0 and 3.
	2. Subtract 5 from the attacked character's HP.
	3. Display a message that player [A] attacks player [B], 
	where "A" would be the index that you get from the for-loop, 
	and "B" would be the player index stored in "attackWho".

## Check win/lose:

After each NPC moves, you will want to check to see if any of the win/lose
conditions have been met:

1. If player HP is less than or equal to 0...  **( C )**
	2. Display "You lose"
	3. Set **done** to true.

2. Otherwise, if player1's HP is <= 0, and player2's HP is <= 0, and player3's HP is <= 0... **( C )**
	1. Display "You win!"
	2. Set **done** to true.

## Add to round:

Update the round at the end of the game loop once everything has bene done.
Increment the round by 1.

---

# Sample Output

	-------------------
	ROUND 10
	Player 0 (YOU!)	 HP: 75
	Player 1 (NPC)	 HP: 75
	Player 2 (NPC)	 HP: 10
	Player 3 (NPC)	 HP: 60
	Who do you want to attack? 2
	Player 2 hit for 5 damage
	Player 1 attacks player 3 hit for 5 damage
	Player 2 attacks player 3 hit for 5 damage
	Player 3 attacks player 3 hit for 5 damage

	-------------------
	ROUND 11
	Player 0 (YOU!)	 HP: 75
	Player 1 (NPC)	 HP: 75
	Player 2 (NPC)	 HP: 5
	Player 3 (NPC)	 HP: 45
	Who do you want to attack? 2
	Player 2 hit for 5 damage
	Player 1 attacks player 1 hit for 5 damage
	Player 2 attacks player 2 hit for 5 damage
	Player 3 attacks player 2 hit for 5 damage

---

# Grading Rubric

<table>
	<tr>
		<th>Percentage</th>
		<th>Feature</th>
		<th>Description</th>
	</tr>
	
	<tr>
		<td> 5% </td>
		<td> Code compiles </td>
		<td> Code should build! How are you even testing if you can't build it? </td>
	</tr>
	
	<tr>
		<td> 5% </td>
		<td> Clean code </td>
		<td> Code is easy to read, consistently indented, descriptive variable names used. </td>
	</tr>
	
	<tr>
		<td> 15% </td>
		<td> HP array is being declared and initialized correctly </td>
		<td> Declaring the array, initializing each element of the array to 100 </td>
	</tr>
	
	<tr>
		<td> 10% </td>
		<td> Game loop (while loop) implemented and will eventually end </td>
		<td> Creating a game loop so the game continues until the player either wins or loses </td>
	</tr>
	
	<tr>
		<td> 10% </td>
		<td> Correct if statement check to see if player wins </td>
		<td> Properly checking to see if the player has won </td>
	</tr>
	
	<tr>
		<td> 10% </td>
		<td> "Correct if statement check to see if player loses
(requires using &&)"
 </td>
		<td> Proper logic to see if player has lost </td>
	</tr>
	
	<tr>
		<td> 5% </td>
		<td> Displays the round menu and options menu for player
 </td>
		<td> Display the main menu each cycle of the game loop </td>
	</tr>
	
	<tr>
		<td> 5% </td>
		<td> Gets the user’s input properly
 </td>
		<td> Get the user's input </td>
	</tr>
	
	<tr>
		<td> 10% </td>
		<td> Character is attacked based on player’s input
 </td>
		<td> Accessing the appropriate element of the array and updating it, based on the user's input. </td>
	</tr>
	
	<tr>
		<td> 15% </td>
		<td> For-loop iterates through all NPCs properly (not the player)
 </td>
		<td> Access each element of the array, except for the player character. </td>
	</tr>
	
	<tr>
		<td> 10% </td>
		<td> Each NPC is able to attack correctly
 </td>
		<td> Attacks are done correctly - accessing the correct element. </td>
	</tr>
	

</table>
