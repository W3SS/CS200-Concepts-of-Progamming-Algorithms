#include <iostream>
using namespace std;

float Sum(float numbers[], int size)
{
	float total = 0;
	for (int i = 0; i < size; i++)
	{
		total += numbers[i];
	}
	return total;
}

void Initialize(float numbers[], int size)
{
	for (int i = 0; i < size; i++)
	{
		numbers[i] = i * 10;
	}
}

void Display(const float numbers[], int size)
{
	cout << endl << "Array: " << endl;
	for (int i = 0; i < size; i++)
	{
		cout << i << ": " << numbers[i] << endl;
	}
}

int main()
{
	const int SIZE = 5;
	float numbers[SIZE];

	Initialize(numbers, SIZE);
	Display(numbers, SIZE);

	float sum = Sum(numbers, SIZE);
	cout << "Sum: " << sum << endl;

	return 0;
}
