#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <vector>
#include <time.h>

using namespace std;

int p5()
{
	int a, b;
	srand ((unsigned int) time(0));

	cout << "Number A ? "; cin >> a;
	cout << "Number B ? "; cin >> b;

	int r = (rand() & (b - a + 1)) + a;
	cout << "Number generated randomly in the interval [" << a << ".." << b << "]: " << r;
	cout << endl;
	return 0;

}
