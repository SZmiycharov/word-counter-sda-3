#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <assert.h>
#include <stdlib.h>
#include "Trie.h"

int Trie::totalFactor;

Trie::Trie()
{
	root = (TrieNode *)calloc(1, sizeof(TrieNode));
}

void Trie::insert(char text[], int index, int factor)
{
	// Converting the input word 'text'
	// into a vector for easy processing
	vector<char> word(text, text + strlen(text));
	TrieNode * temp = root;

	int i = 0;

	while (i < word.size()) {      // Until there is something to process
		if (temp->children[word[i] - 'a'] == NULL) {
			// There is no node in 'trie_tree' corresponding to this alphabet

			// Allocate using calloc(), so that components are initialised
			temp->children[word[i] - 'a'] =
				(TrieNode *)calloc(1, sizeof(TrieNode));
			temp->children[word[i] - 'a']->parent = temp; // Assigning parent
		}

		temp = temp->children[word[i] - 'a'];
		++i;   // Next alphabet
	}

	temp->occurrences.push_back(index);      //Mark the occurence of the word
}

bool Trie::searchWord(TrieNode * trie, char * text, int arrSize)
{
	// Functions very similar to insert() function
	vector<char> word(text, text + strlen(text));
	TrieNode * temp = trie;

	while (word.size() != 0) {
		if (temp->children[word[0] - 'a'] != NULL) {
			temp = temp->children[word[0] - 'a'];
			word.erase(word.begin());
		}
		else {
			break;
		}
	}

	if (word.size() == 0 && temp->occurrences.size() != 0) {
		// Word found
		return true;
	}
	else {
		// Word not found
		return false;
	}
}

int Trie::getCode(char ch)
{
	int code = int(ch) - 97;
	//for uppercase letters
	if (code < 0)
	{
		code += 32;
	}
	return code;
}