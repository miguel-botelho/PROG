#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <fstream>

using namespace std;

int p6b()
{
	srand ((unsigned int) time(0));

	ifstream display;
	string s;
	string output;
	const int a = 1;
	int b;
	int i = 0;

	cout << "FILENAME? "; cin >> s;
	display.open(s);
	if (display.fail() )
	{
		cout << "ERROR: File not found!" << endl;
		exit(0);
	}
	else 
	{
		display >> b;
		int r = (rand() & b) + a;
		cout << r << endl;
		while (! (r == i))
		{
			getline(display, output);
			i++;
		}
		getline(display, output);
		cout << "SENTENCE: " << output << endl;
		
	}
	display.close();
	return 0;
}
