C++ Practice Programming

Variables, Data Types, Input/Output, and Arithmetic

# Programming Problems

## Program 1: Price and Tax, part 2

1. Declare a variable called **price**, whose type is a **float**.

2. Declare a variable called **tax**, whose type is a **float**.

3. Declare a variable called **pricePlusTax**, whose type is a **float**.

4. Declare a variable called **state**, whose type is a **string**.

4. Display the message to the user: "What is the price?"

5. Get the user's input and store it in **price**.

6. Display the message to the user: "What state are you in?"

7. Get the user's input and store it in **state**.

8. If **state** is "KS": set **tax** to 0.065.

9. If **state** is "MO": set **tax** to 0.04225.

8. Calculate the price plus tax as: **price + price * tax**.
    Store it in the **pricePlusTax** variable.

9. Display the message to the user: "Price plus tax: "

10. Display the value of **pricePlusTax** to the user.

## Program 2: Generations

1. Declare a variable called **birthYear**, whose type is an **integer**.

2. Declare a variable called **generation**, whose type is a **string**.

2. Display the message to the user: "What year were you born?"

3. If birthYear is between [1901 and 1924), set **generation** to "Greatest Generation".

4. If birthYear is between [1924 and 1946), set **generation** to "Silent Generation".

5. If birthYear is between [1946 and 1965), set **generation** to "Baby Boomer".

6. If birthYear is between [1965 and 1982), set **generation** to "Generation X".

7. If birthYear is between [1982 and 2000), set **generation** to "Millennials".

8. Display the message "Generation:", and then the value of **generation**.

---

# Solutions

## Program 1

    #include <iostream>
    #include <string>
    using namespace std;

    int main()
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
        
        return 0;
    }

## Program 2

    #include <iostream>
    #include <string>
    using namespace std;

    int main()
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
        
        return 0;
    }
