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

#include "Trie.h"

int Trie::totalFactor;

Trie::Node::~Node()
{
	for (int i = 0; i < symbolsCount; i++)
	{
		if (children[i] != NULL)
		{
			delete children[i];
		}	
	}
}

Trie::Trie()
{
	root = (Node *)calloc(1, sizeof(Node));
}

Trie::~Trie()
{
	delete root;
}

void Trie::insert(char * text, int factor, int arrSize)
{
	Node * temp = root;

	int code = 0;

	for (int i = 0; i < arrSize; ++i)
	{   
		code = getCode(text[i]);
		if (temp->children[code] == NULL) 
		{
			temp->children[code] = (Node *)calloc(1, sizeof(Node));
			temp->children[code]->parent = temp;
		}

		temp = temp->children[code];
	}

	temp->factor = factor;
}

bool Trie::searchWord(char * text, int arrSize)
{
	if (arrSize == 0) return false;

	Node * temp = root;
	int code = 0;
	int counter = 0;

	for (int i = 0; i < arrSize; ++i)
	{
		code = getCode(text[i]);
		if (temp->children[code] == NULL)
		{
			break;
		}
		else
		{
			temp = temp->children[code];
			counter++;
		}
	}

	if (counter == arrSize) 
	{
		totalFactor += temp->factor;
		return true;
	}
	else 
	{
		return false;
	}
}

int Trie::getCode(char ch)
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