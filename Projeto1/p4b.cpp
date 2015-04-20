#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <vector>

using namespace std;
char readChar();
void checkVector(char letra, vector <char> &vetorf);
bool searchSentenceInVector(char firstletter, vector <char> vetorf);

int p4b()
{
	char letra = '0';
	string sentence;
	string asteriscos;
	vector <char> vetorf;

	
	while ( !('.' == letra))
	{
		if ( (letra >= 'a' && letra <= 'z') || (letra >= 'A' && letra <= 'Z') )
		{
			letra = toupper(letra);
			checkVector(letra, vetorf);
		}
		letra = readChar();
	}
	cout << "VECTOR: [ ";

	for (int i = 0; i < vetorf.size(); i++)
	{
		cout << vetorf.at(i) << " ";
	}

	cout << "]";
	
	cin.ignore();
	cout << endl << endl;
	cout << "SENTENCE ? ";
	getline(cin, sentence);

	for (int i = 0; i < sentence.size(); i++)
	{
		char firstletter = sentence.at(i);
		firstletter = toupper(firstletter);
		bool var = searchSentenceInVector(firstletter, vetorf);
		if (true == var)
			asteriscos.push_back(firstletter);
		else asteriscos.push_back((char) 42);
	}
	cout << "RESULT   : " << asteriscos << endl;
	return 0;
}