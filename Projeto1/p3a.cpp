#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

int p3a()
{
	char letter;
	cout << "LETTER ? "; cin >> letter;
	while(  !((((int) letter > 65) & ((int) letter < 90)) || (((int) letter > 61) & ((int) letter < 122))) )
	{
		cout << "LETTER ? "; cin >> letter;
		cout << endl;
	}
	return 0;
}
