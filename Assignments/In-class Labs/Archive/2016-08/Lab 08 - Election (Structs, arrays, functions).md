# CS 200 Lab 8: Election (Structs)

![Screenshot](images/cl8-00.png)

Please read this document in Chrome. :)

## Topics

* Arrays
* Functions
* Structs

## Introduction

For this program, a lot has already been implemented.

Issues are randomly generated, as are political candidates.

You have to complete the election by creating an array of citizens,
who have their own views on issues.

Run the program as-is and you'll be able to see a list of candidates
and their stance on issues.


## Turn-in

Make sure to upload all your source files (.cpp) to the Dropbox.

When you're uploading your source to the Dropbox, make sure
to also leave a comment with the URL of your repository!

**Add the name of all people in your team in the upload comments**.

Turn in as one source file.

---

# Step 1: Creating the citizens

First, we must create a struct to contain information about
our citizens.

A citizen must have the following member variable:

* positions, an array of Issues, of size 10

And the following functions:

## ChooseIssues

* Function name: ChooseIssues
* Return type: void
* Parameters:
	* An array of Issues, of size 10.
	
Within this function, the citizen will randomly chose their stance
on an issue. Use the random number generator to choose between "for" or "against":

	rand() % 2; // 0 = false, 1 = true
	
The citizen will need to chose their position for all 10 issues, so use
a **for loop** to generate positions for all 10.	

If the citizen is *for* the issue, the amount of supporters of the issue should
go up.

### How to increment issue supporters?

The Issue struct is:

	struct Issue
	{
		string name;
		bool isPro;
		int totalSupporters;
	};

And in the function, we have an array of issues:

	...( Issue issues[10] )...
	
Within our for-loop, we are currently looking at issue *i*. If that issue
is supported (1 = true), then add one to the issue with:

	issues[i].totalSupporters++;
	

## CheckCandidateAgreement

* Function name: CheckCandidateAgreement
* Return type: int
* Parameters:
	* A single Candidate
	
This function will tally up the amount of agreement between this citizen
and a political candidate. The return value will be the amount of
agreement (between 0 and 10).

Create a temporary int variable called **agreementCount**, and initialize it to 0.

Create a for loop to iterate through all issues. Within the loop, 
check to see if the candidate and the citizen agree on the issue.

If they do agree, increment agreementCount by 1.

After the for loop, return the value of the **agreementCount** variable.

### How to check agreement?

The Issue struct is:

	struct Issue
	{
		string name;
		bool isPro;
		int totalSupporters;
	};

The Citizen and the Candidate each contain an array of 10 issues,
that they are either **for** or **against**.

While iterating through the for loop, check the **isPro** value for 
the issues for each.

	positions[i] == candidate.positions[i] ?
	
(Note: since this function belongs to a *Citizen*, the right-hand side
here implicitly refers to that citizen, while the left-hand side
explicitly refers to the Candidate.)

## Testing...

Test your code by creating one Citizen in main():

	Citizen myCitizen;
	
Call its ChooseIssues function to get it set up:

	myCitizen.ChooseIssues( issues );
	
And then call the CheckCandidateAgreement with one of the candidates and output the
result:

	int agree = myCitizen.CheckCandidateAgreement( candidate[0] );
	cout << agree << endl;
	
This is only temporary code, but if everything is working, each time
you run the program, there should be a different agreement level.

While you're testing, you can also *cout* each issue and isPro within the ChooseIssues
function if you want to, though you won't want to keep it because we'll be generating
a lot of citizens.

---

# Step 2: Creating and initializing an array of citizens

Within main, you will create an array of Citizens, similar to how there is
already an array of issues and candidates in the program.

Create an array of 1000 citizens.

Use a for loop to initialize each citizen, calling ChooseIssues on all of them.

After you're done generating the citizens, display the list of issues and
support for each issue.

![A list of issues](images/cl8-01.png)

Iterate through the list of all issues, from 0 to 10.
Display the list of all issues, and the amount of supporters each.

(Remember that the Issue object has a *totalSupporters* member variable.)

---

# Step 3: Election day

Create a new function, which does not belong to any structs.

* Function name: ElectionDay
* Return type: Void
* Parameters: The array of 3 candidates, the array of 1000 citizens

Within the function, each citizen will have a chance to cast their votes.

Create a for loop that iterates over all 1000 citizens.

Within the for loop, the citizen will need to look at all 3 candidates,
and choose the one whose agreement is ranked highest with them.

We will do this similar to a "Find Max Number" function...:

	int Max( int numbers[5] )
	{
		int max = 0;
		for ( int i = 0; i < 5; i++ )
		{
			if ( numbers[i] > max )
			{
				max = numbers[i];
			}
		}
		return max;
	}
	
For this logic, however, we will have to keep track of the **maximum agreement**,
and the **index of the most agreeable candidate**.

Create two integer variables: choiceIndex, initialized to -1, and maxAgreement, initialized to 0.

Create an internal for loop to iterate over each candidate. For each candidate...

* Check the agreement between the Citizen and the Candidate, using the Citizen's **CheckCandidateAgreement** function.
* If the agreement between this Citizen and Candidate is greater than **maxAgreement**, then:
	* Set **choiceIndex** to this candidate's index.
	* Set **maxAgreement** to this agreement value.

Once we're done with the candidate for-loop, we should have an index of a
candidate to vote for.

If choice is not -1 (the default), then increment the candidate's total votes by one:

	candidates[ choiceIndex ].totalVotes++;

Call the **ElectionDay** function from main(), passing in the correct arguments.

	ElectionDay( candidates, citizens );
	
---
	
# Step 4: Election Results

After the election is over, we will need to tally the votes. Similar to
our "Find max number" or "Choose candidate" logic, we will need to find out which
candidate has the maximum amount of votes.

Create two integer variables: **winner** (initialize to 0), and **mostVotes** (initialize to 0).

Iterate through all 3 candidates. For each candidate, display the candidate's name and their totalVotes:

	// For my for-loop, I used c, going from 0 (inclusive) to 3 (exclusive).
	cout << "* " << candidates[c].name << " with " << candidates[c].totalVotes << " votes" << endl;
	
Then, check to see if this candidates **totalVotes** is greater than the **mostVotes** variable.
If it is, then set **winner** to the current iterator variable (for me, it was *c*),
and set the **mostVotes** variable to the current candidate's amount of votes.

After the for loop going over candidates is over, you should be able to display the winner in this manner:

	cout << endl << candidates[ winner ].name << " wins!" << endl;
	

![Screenshot](images/cl08-02.png)
