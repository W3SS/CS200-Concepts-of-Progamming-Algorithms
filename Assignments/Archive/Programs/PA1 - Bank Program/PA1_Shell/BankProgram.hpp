#ifndef BANK_PROGRAM_HPP
#define BANK_PROGRAM_HPP

class BankProgram
{
    public:
    void Start();
    void MainMenu();
    void Deposit();
    void Withdraw();
    void ViewBalance();

    private:
    float m_balance;
};

#endif
