#include <iostream>
#include <iomanip>
#include <string>

using namespace std;
string readWord();

int p1a()
{
	string word = readWord();
	for (int i = 0; i < word.size(); i++)
	{
		word.at(i) = toupper(word.at(i));
	}
	cout << "WORD IN UPPERCASE: " << word;
	return 0;
}

string readWord()
{
	string word;
	cout << "WORD ? "; cin >> word;
	return word;
}

