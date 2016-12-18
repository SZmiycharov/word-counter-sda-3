#include <vector>
#include <cstdlib>
#include <cstdio>
#include <cstring>

using namespace std;

//english alphabet + space
const int symbolsCount = 27;

class Trie
{
public:
	static int totalFactor;
	
	Trie();
	~Trie();

	void insert(char text[], int factor, int arrSize);
	bool searchWord(char * text, int arrSize);

private:
	struct Node
	{
		public:
			Node * parent;
			Node * children[symbolsCount];
			int factor;
			~Node();
	};
	Node * root;

	//void deleteAll(Node * root);
	int getCode(char ch);
};
