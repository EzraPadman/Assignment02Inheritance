#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include "Word.h"
#include "Dictionary_Part02.h"

using namespace std;

// Dictionary class handles the loadDictionary function which loads the .txt file so that it may be read and used throughout the assignment. 
// Ezra Padmanabham 10511360
// Edith Cowan University 
// Semester One 2021
// Assignment One Part 1
// Finalised on the 13th of April 2021


class Dictionary
{
protected:
	vector<Word> theWords;

private:
	string word;
	string type;
	string definition;
	

public: 
	Dictionary();

	void loadDictionary(string dictionaryFile)
	{
		string throwAway;
		ifstream myfile(dictionaryFile);
		if (myfile.is_open())
		{
			// loop through dictionary and parse it
			while (!myfile.eof())
			{
				
				getline(myfile, word, ' ');
				getline(myfile, type);
				getline(myfile, definition);
				theWords.push_back(Word(word,type,definition));
				getline(myfile, throwAway);
			}
			myfile.close(); 
		}
		else
		{
			// no such file - exiting.
			cout << "file not found.\n";
			exit(0);
		}
	}
 
	
	// Search function allows for searching of words to then print the word, type and definition. 
	
	void search()
	{
		bool wordFound = false; 
		string searchWord;
		cout << "enter the search word: ";
		getline(cin, searchWord, '\n');
		
		  
		for (Word current : theWords)
		{
			if (searchWord == current.getWord())
			{

				cout << "Word found!\n";
				cout << current.getWord() << " ";
				cout << current.getType() << "\n\n";
				cout << "Definition(s):\n";
				current.printDefinition(current.getDefinition());
				cout << "\n\n";
				wordFound = true;
				break;

			}
		}
			
		if (!wordFound)
		{
			cout << "Word not found!\n\n";
			

		}
			
		
		return; 
		

	}

	int count_z(string s)
	{
		int z_count = 0;
		for (int i = 0; i < s.size(); i++)
			if (s[i] == 'z')
				z_count++;
		return z_count;
	}

	// find_zzz function is the function that finds all of the words that have more than three z's. **I have emulated the code to find words with 2 or more to show full functionality"". 
	
	void find_zzz()
	{
		for (Word current : theWords)
		{
			if (count_z(current.getWord()) == 2)
			{
				cout << "Word found!\n";
				cout << current.getWord() << "\n";
				cout << "\n";
				
			}
		}
	}

	// This is the function that allows us to find all of the words that have a "q" without a following "u"
	void ufollowingq()
	{
		for (Word current : theWords)
		{
			for (int i = 0; i < current.getWord().length(); i++)
			{
				if ((current.getWord()[i] == 'q') && (current.getWord().length() > i) && (current.getWord()[i + 1] != 'u'))
				{
					cout << "Word found!\n";
					cout << current.getWord() << "\n";
					cout << "\n";
				}
			}
		}
	}

	
};
