#include <iostream>
using namespace std;

int main()
{
    cout << "Enter a number between 1 and 3: ";

    int choice;
    cin >> choice;

    int min = 1;
    int max = 3;
    while (choice < min && choice > max)
    {
        cout << "Invalid, try again:" << endl;
        cin >> choice;
    }

    cout << "You chose " << choice << endl;

    return 0;
}