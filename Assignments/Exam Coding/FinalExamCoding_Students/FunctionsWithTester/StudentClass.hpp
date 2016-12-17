#ifndef _STUDENT_CLASS_HPP
#define _STUDENT_CLASS_HPP

#include <string>
using namespace std;

/*
* Dictionary Class
*
* Member variables:
*	entries, an array of DictionaryEntry objects, size 6.
*	size, an integer
*
* Member methods:
*	Constructor
*		Initializes the following items in the dictionary.
*		Also sets the size to 6.
*
*		ENGLISH			HINDI
*		cat				billee
*		dog				kuttaa
*		mouse			kuhaa
*		rabbit			khargosh
*		frog			mendak
*		sheep			bhed
*
*	GetSize
*		Returns the size of the array, which should be stored
*		in the private member variable "size".
*
*	EnglishToHindi
*		Input: an English string
*		Output: a Hindi string
*
*		Search the entries array. If you can find an entry
*		whose english string is the same as the input,
*		then return that entry's hindi string as the output.
*
*	HindiToEnglish
*		Input: a Hindi string
*		Output: an English string
*
*		Search the entries array. If you can find an entry
*		whose hindi string is the same as the input,
*		then return that entry's english string as the output.
*/

struct DictionaryEntry
{
	string english;
	string hindi;
};



#endif