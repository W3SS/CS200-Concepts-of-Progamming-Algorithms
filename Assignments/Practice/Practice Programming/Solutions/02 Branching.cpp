#include <iostream>
#include <string>
using namespace std;

void Problem1()
{
    float price;
    float tax;
    float pricePlusTax;
    string state;
    
    cout << "What is the price? ";
    cin >> price;
    
    cout << "What is the state? ";
    cin >> state;
    
    if ( state == "KS" )
    {
        tax = 0.065;
    }
    else if ( state == "MO" )
    {
        tax = 0.04225;
    }
    
    pricePlusTax = price + price * tax;
    
    cout << "Price plus tax: " << pricePlusTax << endl;
}

void Problem2()
{     
    int birthYear;
    string generation;
    
    cout << "What year were you born? ";
    cin >> birthYear;
    
    if ( birthYear >= 1901 && birthYear < 1924 )
    {
        generation = "Greatest Generation";
    }
    else if ( birthYear >= 1924 && birthYear < 1946 )
    {
        generation = "Silent Generation";
    }
    else if ( birthYear >= 1946 && birthYear < 1965 )
    {
        generation = "Baby Boomer";
    }
    else if ( birthYear >= 1965 && birthYear < 1982 )
    {
        generation = "Generation X";
    }
    else if ( birthYear >= 1982 && birthYear < 2000 )
    {
        generation = "Millennials";
    }
    
    cout << "Generation: " << generation << endl;
}

int main()
{
    Problem1();
    
    return 0;
}
