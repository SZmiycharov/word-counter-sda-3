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

using namespace std;

int main(int argc, char* argv[])
{
	if (argc < 3)
	{
		cerr << "Usage: " << argv[0] << " <FILENAME 1> <FILENAME 2> ... <FILENAME N>" << "\n";
		system("pause");
		exit(EXIT_FAILURE);
	}

	for (int i = 1; i < argc; i++)
	{
		ifstream wordFile(argv[i]);

		if (wordFile.is_open())
		{
			int priority;
			string word;


			while (wordFile >> word)
			{
				cout << word << " ";
			}

			wordFile.close();
			cout << endl;
		}
		else
		{
			cerr << "Unable to open file " << argv[i] << "\n";
			exit(EXIT_FAILURE);
		}
	}
	
	return 0;
}

