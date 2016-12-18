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

#include <cstdlib>

//english alphabet (26 letters) + space
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
			Node();
			~Node();
	};
	Node * root;

	int getCode(char ch);
};
