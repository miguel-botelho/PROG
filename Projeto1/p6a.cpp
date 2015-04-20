#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

int p6a()
{
	ifstream display;
	string s;
	string output;
	cout << "FILENAME? "; cin >> s;
	display.open(s);
	if (display.fail() )
	{
		cout << "ERROR: File not found!" << endl;
		exit(0);
	}
	else {
		while(! (display.eof()) )
		{
		getline(display,output);	
		cout << output << endl;
		}
	}
	display.close();
	return 0;
}
