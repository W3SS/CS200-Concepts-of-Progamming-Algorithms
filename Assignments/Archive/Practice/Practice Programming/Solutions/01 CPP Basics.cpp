#include <iostream>
using namespace std;

void Problem1()
{
    cout << "1. A robot may not injure a human being or, through inaction, allow a human being to come to harm." << endl;
    cout << "2. A robot must obey orders given it by human beings except where such orders would conflict with the First Law." << endl;
    cout << "3. A robot must protect its own existence as long as such protection does not conflict with the First or Second Law." << endl;
}

void Problem2()
{
    cout << "2 + 2 = ?" << endl;
    cout << "Please enter an answer: ";
    
    int answer;
    cin >> answer;
    
    cout << ( 2 + 2 ) << endl;
}

void Problem3()
{
    cout << "Please enter a numerator: ";
    float numerator;
    cin >> numerator;
    
    cout << "Please enter a denominator: ";
    float denominator;
    cin >> denominator;
    
    float result = numerator / denominator;
    
    cout << "Quotient: ";
    cout << result << endl;
}

void Problem4()
{
    float price;
    float tax;
    float pricePlusTax;
    
    cout << "What is the price? ";
    cin >> price;
    
    cout << "What is the tax? ";
    cin >> tax;
    
    pricePlusTax = price + price * tax;
    
    cout << "Price plus tax: " << pricePlusTax << endl;
}

int main()
{
    cout << "1. A robot may not injure a human being or, through inaction, allow a human being to come to harm." << endl;
    cout << "2. A robot must obey orders given it by human beings except where such orders would conflict with the First Law." << endl;
    cout << "3. A robot must protect its own existence as long as such protection does not conflict with the First or Second Law." << endl;
    Problem1();
    Problem2();
    Problem3();
    
    return 0;
}
