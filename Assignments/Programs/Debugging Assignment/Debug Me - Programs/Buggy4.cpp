#include <iostream>
using namespace std;

int main()
{
    float price = 10;
    int quantity;

    cout << "What is the quantity? ";
    cin >> quantity;

    // Give a discount for bulk
    if (quantity > 10);
    {
        price = 5;
    }

    cout << "Price:    $" << price << endl;
    cout << "Quantity: " << quantity << endl;
    cout << "Total:    $" << (price * quantity) << endl;

    return 0;
}