
#include <iostream>
#include <string>
#include "Dictionary.h"
#include "Dictionary_Part02.h"


using namespace std;

Dictionary_Part02::Dictionary_Part02(): Dictionary() {}

void Dictionary_Part02::palindrome()
{
	int i, length;
	int flag = 0;

	for (Word current : theWords)
	{
		string test_word = current.getWord();
		length = strlen(test_word.c_str());

		for (i = 0; i < length; i++)
		{
			if (test_word[i] != test_word[length - i - 1])
			{
				flag = 1;
				break;
			}
		}
		if (flag) {
			break;
		}
		else {
			cout << test_word << "is a palindrome" << endl;
		}
	}


}

void Dictionary_Part02::noun_and_verb()
{
}

void Dictionary_Part02::anagrams() 
{
}
	


