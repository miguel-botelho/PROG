#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;
string readString();

int p2a()
{
	string number = readString();
	int finaln = 0;
	int size = number.size();

	for (int i = 0; i < number.size(); i++)
	{
		finaln = finaln + number.at(i) * pow(10, (size - 1));
		size--;
	}
	cout << "INTEGER : " << number << endl;
	return 0;
}

string readString()
{
	string number;
	cout << "STRING   ? "; cin >> number;
	return number;
}

