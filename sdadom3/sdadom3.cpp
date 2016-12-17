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
#include "Trie.h"
#include "Vector.h"

using namespace std;

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

int main(int argc, char* argv[])
{
	Trie dict;

	if (argc < 3)
	{
		cerr << "Usage: " << argv[0] << " <FILENAME 1> <FILENAME 2> ... <FILENAME N>" << "\n";
		std::system("pause");
		exit(EXIT_FAILURE);
	}

	char buffer[100];
	char phrase[1000];
	char number[1000];
	char ch;

	
	int phraseSize = 0;
	int numberSize = 0;
	int factor = 0;
	
	ifstream dictionaryFile(argv[1]);
	if (dictionaryFile.is_open())
	{
		while (dictionaryFile >> noskipws >> ch)
		{
			if (-1 < getCode(ch) && getCode(ch) < 27)
			{
				phrase[phraseSize] = ch;
				++phraseSize;
			}
			else if (int(ch) == 45 || (48 <= int(ch) && int(ch) <= 57)) 
			{
				number[numberSize] = ch;
				++numberSize;
			}
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
		cerr << "Unable to open file " << argv[1] << "\n";
		exit(EXIT_FAILURE);
	}


	/*cout << dict.searchWord("algorithm", 9) << endl;
	cout << dict.searchWord("selection sort", 14) << endl;
	cout << dict.searchWord("programs", 8) << endl;
	cout << dict.searchWord("program", 7) << endl;
	cout << dict.searchWord("viagra", 6) << endl;*/

	


	int arrSize = 0;
	int lastTotalFactor = 0;
	int wordCount = 0;

	for (int i = 2; i < argc; i++)
	{
		ifstream wordFile(argv[i]);
		cout << "\nfile: " << argv[i] << endl;

		if (wordFile.is_open())
		{			
			arrSize = 0;
			for (int i = 0; i < arrSize; i++)
			{
				buffer[i] = '\0';
			}
			while (wordFile >> noskipws >> ch)
			{
				


				//if it is a letter
				if (-1 < getCode(ch) && getCode(ch) < 26)
				{
 					buffer[arrSize] = ch;
					++arrSize;					
				}
				else
				{
					if (arrSize > 0)
					{
						++wordCount;
					}
					if (!(dict.searchWord(buffer, arrSize)))
					{
						cout << "arrsize: " << arrSize << "; ";
						cout << "*";
						for (int i = 0; i < arrSize; i++)
						{
							cout << buffer[i];
						}
						cout << "* ";
						cout << "word not found!!!\n";
						for (int i = 0; i < arrSize; i++)
						{
							buffer[i] = '\0';
						}
						arrSize = 0;
					}
					else
					{
						cout << "arrsize: " << arrSize << "; ";
						cout << "*";
						for (int i = 0; i < arrSize; i++)
						{
							cout << buffer[i];
						}
						cout << "* ";
						cout << "found it! Factor: " << Trie::totalFactor << "\n";

						if (lastTotalFactor == Trie::totalFactor)
						{
							buffer[arrSize] = ' ';
							++arrSize;
						}
						else
						{
							for (int i = 0; i < arrSize; i++)
							{
								buffer[i] = '\0';
							}
							arrSize = 0;
						}
						
						lastTotalFactor = Trie::totalFactor;
					}
				}
			}
			wordFile.close();
		}
		else
		{
			cerr << "Unable to open file " << argv[i] << "\n";
			exit(EXIT_FAILURE);
		}
	}
	
	cout << "\ntotalfactor: " << Trie::totalFactor << endl;
	cout << "wordcount: " << wordCount << endl;

	cout << "FINALRESULT: " << Trie::totalFactor / wordCount << endl;

	std::system("pause");
	return 0;
}

