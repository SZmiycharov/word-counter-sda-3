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
	int code = int(ch) - 97;
	//for uppercase letters
	if (code < 0)
	{
		code += 32;
	}
	return code;
}

int main(int argc, char* argv[])
{
	// getcode returns 0 to 25 for the characters and -17 for the '0'
	/*string upper = "0ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	string lower = "0abcdefghijklmnopqrstuvwxyz";
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



	Trie test;

	test.insert("test", 0, 5);
	test.insert("yolo", 1, 10);
	test.insert("wtf", 2, -3);

	test.searchWord(test.root, "12345", 5);


	//Vector <char> word;

	//if (argc < 3)
	//{
	//	cerr << "Usage: " << argv[0] << " <FILENAME 1> <FILENAME 2> ... <FILENAME N>" << "\n";
	//	system("pause");
	//	exit(EXIT_FAILURE);
	//}

	//char ch;
	//
	//for (int i = 1; i < argc; i++)
	//{
	//	ifstream wordFile(argv[i]);

	//	if (wordFile.is_open())
	//	{			
	//		while (wordFile >> noskipws >> ch)
	//		{
	//			//if it is a letter
	//			if (-1 < getCode(ch) && getCode(ch) < 26)
	//			{
	//				word.push_back(ch);
	//			}
	//			//if it is not a letter - make it a space no matter what sign it is
	//			else if (!(word.empty()))
	//			{
	//				//proverka v avtomata - ako q ima - produljavame i vkarvame simvola kato space
	//				if (1)
	//				{
	//					//ako v avtomata kraq na dumata e kraino sustoqnie - promenqme koeficienta;
	//					//                              NEkraino sustoqnie - produljavame da 4etem
	//					word.push_back(' ');
	//				}
	//				//ako q nqma - triem dumata i produljavame napred
	//				else
	//				{
	//					word.clear();
	//				}
	//				
	//			}
	//		}

	//		wordFile.close();
	//	}
	//	else
	//	{
	//		cerr << "Unable to open file " << argv[i] << "\n";
	//		exit(EXIT_FAILURE);
	//	}

	//	for (int i = 0; i < word.size(); i++)
	//	{
	//		cout << word[i];
	//	}
	//	cout << endl;
	//	word.clear();

	//}
	
	system("pause");
	return 0;
}

