#include <iostream>
#include <iomanip>
#include <string>

using namespace std;
string readSentence();
int p1b()
{
	string word = readSentence();

	for (int i = 0; i < word.size(); i++)
	{
		word.at(i) = toupper(word.at(i));
	}

	cout << "SENTENCE IN UPPERCASE: " << word << endl;
	return 0;
}

string readSentence()
{
	string word;

	cout << "SENTENCE? ";
	getline(cin, word);
	return word;
}