#include <iostream>
using namespace std;

/*
With this code, write a function called GetYorN. Its return type is a char, and takes no parameters.

Within the function, use cin to get a letter from the user. As long as they enter something besides 'y' or 'n', keep looping until they enter a valid answer.

Once they've entered a valid answer, return the user's input.

The function must only allow a 'y' or 'n' to be returned, so a loop must be used to check every time the user enters an answer.
*/

char GetYorN()
{
    char input;
    cout << ">> ";
    cin >> input;
    // While input is not 'y' AND input is not 'n',
    // it is invalid, so have them re-enter their choice.
    while ( input != 'y' && input != 'n' )
    {
        cout << "Invalid input, try again." << endl;
        cout << ">> ";
        cin >> input;
    }

    // Return the input once it is valid. At this point,
    // input will be either 'y' or 'n'.
    return input;
}

int main()
{
    char answer;

    do
    {
        cout << "Are you sure you want to quit? (y/n): ";
        answer = GetYorN();
    } while ( answer == 'n' );

    return 0;
}

