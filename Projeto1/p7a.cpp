#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <vector>
#include <time.h>
#include <fstream>

using namespace std;

int sizeNumber(int n);
bool searchSentenceInVector(char firstletter, vector <char> letters);
string string_to_upper(string s);

int rand_int(int a, int b)
{
	srand ((unsigned int) time(0));
	int r = (rand() & (b - a + 1)) + a;
	return r;
}

int string_to_int(string s)
{
	int finaln = 0;
	int size = s.size();
	int potencia = pow(10, (size - 1));
	for (int i = 0; i < s.size(); i++)
	{
		finaln = finaln + (s.at(i) - '0') * potencia;
		potencia = potencia / 10;
	}
	return finaln;
}
