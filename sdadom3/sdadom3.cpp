/**
*
* Solution to homework task
* Data Structures Course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2016/2017
*
* @author Stanislav Zmiycharov
* @idnumber 61883
* @task 3
* @compiler VC
*
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <assert.h>
#include <cstdlib>
#include "Trie.h"

using namespace std;

void clearCharArray(char &element, int &buffSize)
{
	element = '\0';
	buffSize = 0;
}

int getCode(char ch)
{
	//return 0-25 for a-z and A-Z and 26 for "space"

	int code = int(ch) - 97;
	//for uppercase letters
	if (code < 0)
	{
		code += 32;
	}
	if (code == -33)
	{
		return 26;
	}
	return code;
}

void populateDictionary(char* fileName, Trie &dict)
{
	char phrase[10000];
	char number[1000];
	char ch;
	int phraseSize = 0;
	int numberSize = 0;
	int factor = 0;

	ifstream dictionaryFile(fileName);

	if (dictionaryFile.is_open())
	{
		while (dictionaryFile >> noskipws >> ch)
		{
			//chars and space
			if (-1 < getCode(ch) && getCode(ch) < 27)
			{
				phrase[phraseSize] = ch;
				++phraseSize;
			}
			//digits and - (for -200)
			else if (int(ch) == 45 || (48 <= int(ch) && int(ch) <= 57))
			{
				number[numberSize] = ch;
				++numberSize;
			}
			//enter
			else if (int(ch) == 10)
			{
				assert(istringstream(number) >> factor);
				dict.insert(phrase, factor, phraseSize - 1);

				for (int i = 0; i < numberSize; i++)
				{
					number[i] = '.';
				}

				clearCharArray(number[0], numberSize);
				phraseSize = 0;
			}
			else
			{
				cout << "CHAR: '" << ch << "' IS NOT ALLOWED!" << endl;
				system("pause");
				exit(EXIT_FAILURE);
			}
		}
		assert(istringstream(number) >> factor);
		dict.insert(phrase, factor, phraseSize - 1);
	}
	else
	{
		cerr << "Unable to open file " << fileName << "\n";
		exit(EXIT_FAILURE);
	}
}

double calculateFactor(char* fileName, int &wordCount, Trie &dict)
{
	char buffer[10000];
	char ch;
	int factor = 0;
	int buffSize = 0;
	int lastTotalFactor = 0;
	bool incrementedWord = false;

	ifstream wordFile(fileName);

	if (wordFile.is_open())
	{
		clearCharArray(buffer[0], buffSize);

		while (wordFile >> noskipws >> ch)
		{
			//if it is a letter
			if (-1 < getCode(ch) && getCode(ch) < 26)
			{
				buffer[buffSize] = ch;
				++buffSize;
			}
			//if it is not a letter ( it is word delimeter (everything except letter) )
			else
			{
				// if there is at least 1 letter in buffer
				if (buffSize > 0 &&
					(getCode(buffer[0]) >= 0 && getCode(buffer[0]) <= 25))
				{
					++wordCount;
				}

				if (!(dict.searchWord(buffer, buffSize)))
				{
					clearCharArray(buffer[0], buffSize);
				}
				else if (int(ch) == 9 || int(ch) == 10 || int(ch) == 11 || int(ch) == 32)
				{
					if (lastTotalFactor == Trie::totalFactor)
					{
						buffer[buffSize] = ' ';
						++buffSize;
					}
					else
					{
						clearCharArray(buffer[0], buffSize);
					}

					lastTotalFactor = Trie::totalFactor;
				}
				else
				{
					clearCharArray(buffer[0], buffSize);
				}
			}
		}
		//for the last word in file
		if (buffSize > 0 &&
			(getCode(buffer[0]) >= 0 && getCode(buffer[0]) <= 25))
		{
			++wordCount;
		}

		dict.searchWord(buffer, buffSize);
		wordFile.close();
	}
	else
	{
		cerr << "Unable to open file " << fileName << "\n";
		exit(EXIT_FAILURE);
	}

	return Trie::totalFactor;
}

int main(int argc, char* argv[])
{
	if (argc < 3)
	{
		cerr << "Usage: " << argv[0] << " <fileName 1> <fileName 2> ... <fileName N>" << "\n";
		system("pause");
		exit(EXIT_FAILURE);
	}

	Trie dict;
	int wordCount = 0;

	populateDictionary(argv[1], dict);
	double factor = 0;
	char* fileName;
	double result = 0;

	for (int i = 2; i < argc; i++)
	{
		wordCount = 0;
		Trie::totalFactor = 0;
		fileName = argv[i];

		factor = calculateFactor(fileName, wordCount, dict);
		if (wordCount != 0)
		{
			result = factor / double(wordCount);
		}

		cout << fileName << " " << result << endl;
	}

	system("pause");
	return 0;
}