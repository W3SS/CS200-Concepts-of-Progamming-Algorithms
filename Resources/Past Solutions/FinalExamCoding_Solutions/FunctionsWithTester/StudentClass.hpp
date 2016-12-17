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

class Dictionary
{
public:
	Dictionary()
	{
		m_entries[0].english = "cat";
		m_entries[0].hindi = "billee";

		m_entries[1].english = "dog";
		m_entries[1].hindi = "kuttaa";

		m_entries[2].english = "mouse";
		m_entries[2].hindi = "kuhaa";

		m_entries[3].english = "rabbit";
		m_entries[3].hindi = "khargosh";

		m_entries[4].english = "frog";
		m_entries[4].hindi = "mendak";

		m_entries[5].english = "sheep";
		m_entries[5].hindi = "bhed";

		m_size = 6;
	}

	int GetSize()
	{
		return m_size;
	}

	string EnglishToHindi(string english)
	{
		for (int i = 0; i < m_size; i++)
		{
			if (m_entries[i].english == english)
			{
				return m_entries[i].hindi;
			}
		}
		return "";
	}

	string HindiToEnglish(string hindi)
	{
		for (int i = 0; i < m_size; i++)
		{
			if (m_entries[i].hindi == hindi)
			{
				return m_entries[i].english;
			}
		}
		return "";
	}

private:
	DictionaryEntry m_entries[6];
	int m_size;
};

#endif