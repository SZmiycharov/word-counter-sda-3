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
	// getcode returns 0 to 25 for the characters and -33 for the ' '
	/*string upper = "0ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	string lower = " abcdefghijklmnopqrstuvwxyz";
	for (int i = 0; i < 26; i++)
	{
		cout << getCode(upper[i]) << " ";
	}
	cout << endl;
	for (int i = 0; i < 26; i++)
	{
		cout << getCode(lower[i]) << " ";
	}

	cout << endl;*/



	/*Trie test;

	test.insert("test", 0, 5);
	test.insert("yolo", 1, 10);
	test.insert("wtf", 2, -3);

	test.searchWord("12345", 5);*/

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

	int arrSize = 0;
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
				cout << "*";
				for (int i = 0; i < phraseSize - 1; i++)
				{
					cout << phrase[i];
				}
				cout << "*" << endl;

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
				cout << "CHAR: '" << ch << "' NOT ALLOWED!" << endl;
				std::system("pause");
				exit(EXIT_FAILURE);
			}
		}
		istringstream(number) >> factor;
		cout << "*";
		for (int i = 0; i < phraseSize - 1; i++)
		{
			cout << phrase[i];
		}
		cout << "*" << endl;
		dict.insert(phrase, factor, phraseSize - 1);
	}
	else
	{
		cerr << "Unable to open file " << argv[1] << "\n";
		exit(EXIT_FAILURE);
	}

	cout << dict.searchWord("algorithm baby the best ", 23);

	// 48 to 57 are the digits!!!

	//for (int i = 2; i < argc; i++)
	//{
	//	ifstream wordFile(argv[i]);
	//	cout << "\nfile: " << argv[i] << endl;

	//	if (wordFile.is_open())
	//	{			
	//		arrSize = 0;
	//		while (wordFile >> noskipws >> ch)
	//		{
	//			//if it is a letter
	//			if (-1 < getCode(ch) && getCode(ch) < 26)
	//			{
	//				cout << ch;
	//				buffer[arrSize] = ch;
	//				++arrSize;
	//				
	//			}
	//			else
	//			{
	//				if (!(test.searchWord(buffer, arrSize)))
	//				{
	//					arrSize = 0;
	//				}
	//				else
	//				{
	//					buffer[arrSize] = ' ';
	//				}

	//				arrSize = 0;
	//			}
	//		}
	//		cout << " " << test.searchWord(buffer, arrSize) << " ";

	//		wordFile.close();
	//	}
	//	else
	//	{
	//		cerr << "Unable to open file " << argv[i] << "\n";
	//		exit(EXIT_FAILURE);
	//	}
	//}
	//
	//cout << "\ntotalfactor: " << Trie::totalFactor << endl;

	std::system("pause");
	return 0;
}

