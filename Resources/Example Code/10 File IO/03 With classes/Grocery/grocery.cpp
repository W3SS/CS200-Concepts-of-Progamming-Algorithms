#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

#include "Menu.hpp"

struct Product
{
	string itemCode;
	string section;
	float price;
	int quantityInStock;

	void Display() const
	{
		cout << "ITEM CODE: " << itemCode << "\t"
			<< "SECTION: " << section << "\t"
			<< "PRICE: $" << price << "\t"
			<< "QUANTITY: " << quantityInStock << endl;
	}
};

void LoadInventory(Product productList[100], int arraySize, int& productCount)
{
	ifstream input("inventory.txt");
	string buffer;

	input >> buffer;
	input >> buffer;
	input >> buffer;
	input >> buffer;

	while (
		input
			>> productList[productCount].itemCode
			>> productList[productCount].section
			>> productList[productCount].price
			>> productList[productCount].quantityInStock
		)
	{
		productCount++;
	}

	input.close();
}

void DisplayItems(const Product productList[100], int productCount, Product cart[100], int& cartCount, const string& section)
{
	Menu::ClearScreen();
	Menu::Header("CHOOSE AN ITEM");

	for (int i = 0; i < productCount; i++)
	{
		if (productList[i].section == section)
		{
			cout << i << ". " << productList[i].itemCode << "\t" << productList[i].price << "\t" << productList[i].quantityInStock << endl;
		}
	}

	int item;
	cout << " What item? ";
	cin >> item;

	// Error checking goes here...

	cart[cartCount] = productList[item];
	cartCount++;
}

void DisplayCart(const Product cart[100], int cartCount)
{
	cout << endl << "CART CONTENTS" << endl;
	for (int i = 0; i < cartCount; i++)
	{
		cout << "ITEM " << (i + 1) << endl;
		cart[i].Display();
		cout << endl;
	}
}

void OutputReceipt(const Product cart[100], int cartCount)
{
	float tax = 0.0885;
	ofstream output("receipt.txt");

	output << "ITEM\t\tPRICE" << endl;

	float total = 0;
	for (int i = 0; i < cartCount; i++)
	{
		output << cart[i].itemCode << "\t" << cart[i].price << endl;
		total += cart[i].price;
	}

	float pricePlusTax = total + (total*tax);

	output << "TOTAL: " << total << endl;
	output << "TAX: " << tax << endl;
	output << "TOTAL WITH TAX: " << pricePlusTax << endl;

	output.close();
}

int main()
{
	Product productList[100];
	Product cart[100];
	int arraySize = 100;
	int productCount = 0;
	int cartCount = 0;
	LoadInventory(productList, arraySize, productCount);

	bool done = false;

	while (!done)
	{
		Menu::ClearScreen();
		DisplayCart(cart, cartCount);
		Menu::Header("CHOOSE A SECTION");
		int choice = Menu::ShowMenuWithPrompt({ "Movies", "Games", "Snacks", "Check Out" });

		if (choice == 1) // movies
		{
			DisplayItems(productList, productCount, cart, cartCount, "MOVIES");
		}
		else if (choice == 2) // games
		{
			DisplayItems(productList, productCount, cart, cartCount, "GAMES");
		}
		else if (choice == 3) // snacks
		{
			DisplayItems(productList, productCount, cart, cartCount, "SNACKS");
		}
		else if (choice == 4)
		{
			done = true;
		}
	}

	OutputReceipt(cart, cartCount);

	return 0;
}
