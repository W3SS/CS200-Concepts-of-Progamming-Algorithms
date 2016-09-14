C++ Practice Programming

Variables, Data Types, Input/Output, and Arithmetic

# Programming Problems

## Program 1: Output only

Use the **cout** command to display information to the user.

Display the following three lines:

1. A robot may not injure a human being or, through inaction, allow a human being to come to harm.

2. A robot must obey orders given it by human beings except where such orders would conflict with the First Law.

3. A robot must protect its own existence as long as such protection does not conflict with the First or Second Law. 


## Program 2: Input/Output

Use **cout** to display information to the user, and **cin** to retrieve information from the user.

1. Display the message: "2 + 2 = ?"

2. Display the message: "Please enter an answer:"

3. Create a variable called **answer**, whose type is an **integer**.

4. Get the user's input and store it in **answer**

5. Display the result of the math operation ( 2 + 2 ).
    *(You can use math during a cout statement)*


## Program 3: Division

1. Use the **cout** command to display the message to the user: "Please enter a numerator".

2. Create a variable named **numerator**, whose type is a **float**.

3. Use the **cin** command to get input from the user, and store it in the **numerator** variable.

4. Use the **cout** command to display the message to the user: "Please enter a denominator".

5. Create a variable named **denominator**, whose type is a **float**.

6. Use the **cin** command to get input from the user, and store it in the **denominator** variable.

7. Create a variable named **result**, whose data type is a **float**.

8. Calculate **result** by dividing the **numerator** by the **denominator**.

9. Use **cout** to display a message to the user: "Quotient is:"

10. Use **cout** to display the value of **result** to the user.


## Program 4: Price and Tax

1. Declare a variable called **price**, whose type is a **float**.

2. Declare a variable called **tax**, whose type is a **float**.

3. Declare a variable called **pricePlusTax**, whose type is a **float**.

4. Display the message to the user: "What is the price?"

5. Get the user's input and store it in **price**.

6. Display the message to the user: "What is the tax?"

7. Get the user's input and store it in **tax**.

8. Calculate the price plus tax as: **price + price * tax**.
    Store it in the **pricePlusTax** variable.

9. Display the message to the user: "Price plus tax: "

10. Display the value of **pricePlusTax** to the user.

---

# Solutions

## Program 1

    #include <iostream>
    using namespace std;

    int main()
    {
        cout << "1. A robot may not injure a human being or, through inaction, allow a human being to come to harm." << endl;
        cout << "2. A robot must obey orders given it by human beings except where such orders would conflict with the First Law." << endl;
        cout << "3. A robot must protect its own existence as long as such protection does not conflict with the First or Second Law." << endl;

        return 0;
    }

## Program 2

    #include <iostream>
    using namespace std;

    int main()
    {
        cout << "2 + 2 = ?" << endl;
        cout << "Please enter an answer: ";
        
        int answer;
        cin >> answer;
        
        cout << ( 2 + 2 ) << endl;
        
        return 0;
    }


## Program 3

    #include <iostream>
    using namespace std;

    int main()
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
        
        return 0;
    }

## Program 4

    #include <iostream>
    using namespace std;

    int main()
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
        
        return 0;
    }
