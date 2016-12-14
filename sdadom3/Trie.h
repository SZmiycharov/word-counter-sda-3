#include <vector>
#include <cstdlib>
#include <cstdio>
#include <cstring>

using namespace std;

//english alphabet + space
const int symbolsLength = 27;

class TrieNode
{
public:
	TrieNode * parent;
	TrieNode * children[26];
	vector<int> occurrences;
	int factor;
};

class Trie
{
public:
	static int totalFactor;
	TrieNode * root;

	Trie();

	// Inserts a word 'text' into the Trie Tree
	// 'trie' and marks it's occurence as 'index'.
	void insert(char text[], int index, int factor);

	// Searches for the occurence of a word in 'trie',
	// if not found, returns NULL,
	// if found, returns poniter pointing to the
	// last node of the word in the 'trie'
	bool searchWord(TrieNode * trie, char * text, int arrSize);

private:
	int getCode(char ch);

};
