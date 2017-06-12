#include <iostream>
using namespace std;

// FUNCTION DECLARATIONS
void MainMenu();
int GetIntChoice();
char GetCharChoice();
float GetFloatChoice();
float Deposit( float balance );
float Withdraw( float balance );
void View( float balance );

// MAIN PROGRAM
int main()
{
    bool done = false;
    float balance = 0;

    while ( !done )
    {
        MainMenu();
        View( balance );
        int choice = GetIntChoice();

        switch( choice )
        {
            case 1: // Deposit
                balance = Deposit( balance );
            break;

            case 2: // Withdraw
                balance = Withdraw( balance );
            break;

            case 3: // Quit
                cout << "Are you sure you want to quit? (y/n)" << endl;
                char chChoice = GetCharChoice();
                if ( chChoice == 'y' || chChoice == 'Y' )
                {
                    done = true;
                }
            break;
        }
    }

    return 0;
}

// FUNCTION DEFINITIONS
void MainMenu()
{
    cout << endl << "----------------------" << endl;
    cout << "BANK PROGRAM 2000" << endl << endl;
    cout << "1. Deposit Money" << endl;
    cout << "2. Withdraw Money" << endl;
    cout << "3. Exit" << endl;
}

int GetIntChoice()
{
    int choice;
    cout << ">> ";
    cin >> choice;
    return choice;
}

char GetCharChoice()
{
    char choice;
    cout << ">> ";
    cin >> choice;
    return choice;
}

float GetFloatChoice()
{
    float choice;
    cout << ">> $";
    cin >> choice;
    return choice;
}


float Deposit( float balance )
{
    cout << "How much do you want to deposit?" << endl;
    float amount = GetFloatChoice();

    if ( amount > 0 )
    {
        balance += amount;
    }
    else
    {
        cout << "Invalid deposit amount!" << endl;
    }

    return balance;
}


float Withdraw( float balance )
{
    cout << "How much do you want to withdraw?" << endl;
    float amount = GetFloatChoice();

    if ( amount <= 0 )
    {
        cout << "Invalid withdraw amount!" << endl;
    }
    else if ( amount > balance )
    {
        cout << "You cannot withdraw more than your balance!" << endl;
    }
    else
    {
        balance -= amount;
    }

    return balance;
}

void View( float balance )
{
    cout << "Your current balance is $" << balance << endl;
}



