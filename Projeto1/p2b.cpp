#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;
int readNumber();
int sizeNumber(int number);
int p2b()
{
	int number = readNumber();
	string numberf;
	int size = sizeNumber(number);
	int sizei = size;

	for (int i = 0; i < sizei; i++)
	{
		int firstnumber = number / (pow(10, (size - 1)));
		number = number % (int) (pow(10, (size - 1)));
		numberf.push_back((char) firstnumber + '0');
		size--;
	}

	cout << "STRING  : " << numberf << endl;
	return 0;
}

int readNumber()
{
	int number;
	cout << "INTEGER ? "; cin >> number;
	return number;
}