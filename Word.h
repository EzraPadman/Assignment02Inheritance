#pragma once

#include <fstream>
#include <string>

using namespace std;

// The Word class stores the information about a word such as the word itself, the type of word and also the definitons of these respective words
// Ezra Padmanabham 10511360
// Semester One 2021
// Edith Cowan University 
// Assignment One Part 1
// Finalised on the 13th of April 2021


class Word
{
private:
	string word;
	string type;
	string definition;
	
public:
	Word(string word, string type, string definition)
	{
		this->word = word; this->type = type; this->definition = definition;
	}
	string getWord() { return word; }
	string getType() { return type; }
	string getDefinition() { return definition; }
	
	// This tokenize function is used to separate the definitions with the delimiter (the indicator that a new definition is beginning), being ";". 

	void tokenize(string s, string del = " ")
	{
		int start = 0;
		int end = s.find(del);
		while (end != -1) {
			cout << s.substr(start, end - start) << endl;
			start = end + del.size();
			end = s.find(del, start);
		}
		cout << s.substr(start, end - start);
	}
	void printDefinition(string s)
	{
		tokenize(s, ";");
	}

};
