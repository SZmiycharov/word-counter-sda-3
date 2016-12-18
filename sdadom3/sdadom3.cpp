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
#include <string>
#include <sstream>
#include <assert.h>
#include <stdlib.h>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <ctime>
#include "Trie.h"
#include "Vector.h"

using namespace std;

void clearCharArray(char &element, int &arrSize)
{
	element = '\0';
	arrSize = 0;
}

bool isWordDelimeter(char ch)
{
	return (ch == ' ' || ch == ',' || ch == '.' || ch == '!' || ch == '?'
		|| ch == '-' || ch == '.' || ch == '.' || ch == '.' || ch == '.'
		|| ch == '.' || ch == '.' || ch == '.' || ch == '.' || ch == '.'
		|| ch == '.' || ch == '.' || ch == '.' || ch == '.' || ch == '.');
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

void populateDictionary(char* filename, Trie &dict)
{
	char buffer[100];
	char phrase[1000];
	char number[1000];
	char ch;
	int phraseSize = 0;
	int numberSize = 0;
	int factor = 0;
	ifstream dictionaryFile(filename);
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
				istringstream(number) >> factor;
				dict.insert(phrase, factor, phraseSize - 1);

				for (int i = 0; i < numberSize; i++)
				{
					number[i] = '.';
				}
				numberSize = 0;
				phraseSize = 0;
			}
			else
			{
				cout << "CHAR: '" << ch << "' IS NOT ALLOWED!" << endl;
				std::system("pause");
				exit(EXIT_FAILURE);
			}
		}
		istringstream(number) >> factor;
		dict.insert(phrase, factor, phraseSize - 1);
	}
	else
	{
		cerr << "Unable to open file " << filename << "\n";
		exit(EXIT_FAILURE);
	}
}

double calculateFactor(int argc, char* argv[], int &wordCount, Trie &dict)
{
	char buffer[100];
	char number[1000];
	char ch;
	int phraseSize = 0;
	int numberSize = 0;
	int factor = 0;
	int arrSize = 0;
	int lastTotalFactor = 0;

	for (int i = 2; i < argc; i++)
	{
		ifstream wordFile(argv[i]);

		if (wordFile.is_open())
		{
			clearCharArray(buffer[0], arrSize);

			while (wordFile >> noskipws >> ch)
			{
				//if it is a letter
				if (-1 < getCode(ch) && getCode(ch) < 26)
				{
					buffer[arrSize] = ch;
					++arrSize;
				}
				//if it is not a letter ( it is word delimeter (everything except letter) )
				else
				{
					// ako imame pone 1 bukva v buffera
					if (arrSize > 0 &&
						((getCode(buffer[0]) >= 0 && getCode(buffer[0]) <= 25) || (getCode(buffer[1]) >= 0 && getCode(buffer[1]) <= 25)))
					{
						++wordCount;
					}

					if (!(dict.searchWord(buffer, arrSize)))
					{
						clearCharArray(buffer[0], arrSize);
					}
					else if (int(ch) == 9 || int(ch) == 10 || int(ch) == 11 || int(ch) == 32)
					{
						if (lastTotalFactor == Trie::totalFactor)
						{
							buffer[arrSize] = ' ';
							++arrSize;
						}
						else
						{
							clearCharArray(buffer[0], arrSize);
						}

						lastTotalFactor = Trie::totalFactor;
					}
					else
					{
						clearCharArray(buffer[0], arrSize);
					}
				}
			}
			//for the last word in file
			if (arrSize > 0 &&
				(arrSize>1 ||
				(int(buffer[0]) != 9 && int(buffer[0]) != 10 && int(buffer[0]) != 11 && int(buffer[0]) != 32)))
			{
				++wordCount;
			}
			dict.searchWord(buffer, arrSize);
			wordFile.close();
		}
		else
		{
			cerr << "Unable to open file " << argv[i] << "\n";
			exit(EXIT_FAILURE);
		}
	}
	return Trie::totalFactor;
}

int main(int argc, char* argv[])
{
	if (argc < 3)
	{
		cerr << "Usage: " << argv[0] << " <FILENAME 1> <FILENAME 2> ... <FILENAME N>" << "\n";
		std::system("pause");
		exit(EXIT_FAILURE);
	}

	Trie dict;
	int wordCount = 0;

	clock_t begin = clock();

	populateDictionary(argv[1], dict);

	double factor = calculateFactor(argc, argv, wordCount, dict);
	clock_t end = clock();

	double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
	
	cout << "totalfactor: " << factor << endl;
	cout << "wordcount: " << wordCount << endl;

	double result = 0;
	if (wordCount != 0)
	{
		result = factor / double(wordCount);
	}
	
	cout << "FINALRESULT: " << result << endl;
	cout << "elapsed time: " << elapsed_secs << "s" << endl;

	std::system("pause");
	return 0;
}

