#include <iostream>
using namespace std;

int main()
{
	bool isDone = false;

	while (isDone == false)
	{
		cout << endl << endl;

		float width, length;

		cout << "Please enter the width: ";
		cin >> width;

		cout << "Please enter the length: ";
		cin >> length;

		float area = width * length;

		float perimeter = (2 * width) + (2 * length);

		cout << endl;
		cout << "Area is: \t" << area << " sqft" << endl;
		cout << "Perimeter is: \t" << perimeter << " ft" << endl;

		cout << endl;
		cout << "Do you want to quit? (y/n): ";
		char choice;
		cin >> choice;

		if (choice == 'y')
		{
			isDone = true;
		}

	}


	return 0;
}
