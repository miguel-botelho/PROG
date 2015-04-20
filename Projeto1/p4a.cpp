#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <vector>

using namespace std;
char readChar();
void checkVector(char letra, vector <char> &vetorf);
bool searchVector(char searchletter, vector <char> vetorf);

int p4a()
{
	char letra = '0';
	char searchletter;
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

	cout << endl << endl << "LETTER TO SEARCH ? "; cin >> searchletter;
	searchletter = toupper(searchletter);
	if (true == searchVector(searchletter, vetorf) )
		cout << "letter " << searchletter << " belongs to the vector";
	else cout << "letter " << searchletter << " does not belong to the vector";
	cout << endl;

	return 0;

}

bool searchVector(char searchletter, vector <char> vetorf)
{
	bool var = true;
	for (int i = 0; i < vetorf.size(); i++)
	{
		if (searchletter == vetorf.at(i) )
		{
			var = true;
			break;
		}
		else var = false;
	}
	if (false == var)
		return false;
	else return true;
}

