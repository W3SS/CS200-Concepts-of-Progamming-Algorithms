#ifndef _STUDENT_POINTERS_HPP
#define _STUDENT_POINTERS_HPP

int* GetAddress(int& var)
{
	return &var;
}

int GetValue(int* ptr)
{
	return *ptr;
}

bool CheckIfNull(int* ptr)
{
	return (ptr == nullptr);
}

bool CompareAddresses(int* ptr1, int* ptr2)
{
	return (ptr1 == ptr2);
}

bool CompareValues(int* ptr1, int* ptr2)
{
	return (*ptr1 == *ptr2);
}

#endif