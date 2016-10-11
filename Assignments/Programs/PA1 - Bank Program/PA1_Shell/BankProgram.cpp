#include "BankProgram.hpp"

#include <iostream>
#include <string>
using namespace std;

void BankProgram::Start()
{
    // 1. Initialize m_balance to 0
    // 2. Call MainMenu()
}

void BankProgram::MainMenu()
{
    bool done = false;
    while ( !done )
    {
        // 1. Display main menu
        // 2. Get user's choice
        // 3. Either quit, deposit, withdraw, or view balance
    }
}

void BankProgram::Deposit()
{
    // 1. Ask the user how much they want to deposit
    // 2. Get the user's input and store it in a variable
    // 3. Check to see if it's a valid amount (e.g., can't deposit an amount < 0)
    // 4. If it's valid: Add to m_balance. Otherwise: Display error.
}

void BankProgram::Withdraw()
{
    // 1. Ask the user how much they want to withdraw
    // 2. Get the user's input and store it in a variable
    // 3. Check to see if it's a valid amount (can't be < 0 or more than the balance)
    // 4. If it's valid: Subtract from m_balance. Otherwise: Display error.
}

void BankProgram::ViewBalance()
{
    // Output the value of m_balance.
}
