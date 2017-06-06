#include <iostream> // input/output
#include <string>	// string
using namespace std;

int main()
{
	cout << "Do you want to quit? (y/n): ";
	char choice;
	cin >> choice;

	if (choice == 'y' || choice == 'Y')
	{
		cout << "Bye :(" << endl;
		return 0;
	}
	else if (choice == 'n' || choice == 'N')
	{
		cout << "Yay!" << endl;
	}
	else
	{
		cout << "Invalid input" << endl;
	}

	while (true); // kludgey fix
	return 0;
}
