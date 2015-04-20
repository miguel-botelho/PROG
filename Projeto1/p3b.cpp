#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <vector>

using namespace std;
char readChar();
void checkVector(char letra, vector <char> &vetorf);
int p3b()
{
	char letra = '0';
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

	cout << " ]";
	return 0;

}

char readChar()
{
	const char aspas = '"';
	char letra;

	cout << "LETTER or " << aspas << "." << aspas << " ? "; cin >> letra;
	return letra;
}

void checkVector(char letra, vector <char> &vetorf)
{
	bool var = true;
	for (int i = 0; i < vetorf.size(); i++)
	{
		if (vetorf.at(i) == letra)
			var = false;
	}
	if (true == var)
		vetorf.push_back(letra);
}
