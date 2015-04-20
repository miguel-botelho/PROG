#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <vector>
#include <time.h>
#include <fstream>

using namespace std;

int rand_int(int a, int b); //p5
int string_to_int(string s); //p2a
string int_to_string(int n); //p2b
int sizeNumber(int number); 
string get_sentence(string filename); //p6b
string string_to_upper(string s); //p1a
string unhide_letters(string s, vector<char> letters); //p4b
bool searchSentenceInVector(char firstletter, vector <char> letters);
void show_vector_char(vector <char> v); //p3b
bool show_file(string filename); // p6a

void p7a()
{
	vector <char> v;
	v.push_back('R');
	v.push_back('T');
	v.push_back('P');
	v.push_back('O');
	v.push_back('F');
	v.push_back('C');
	v.push_back('U');

	int random = rand_int(2, 6);
	cout << "RANDOM(entre 2 e 6): " << random << endl;

	int number = string_to_int ("20");
	cout << "STRING TO NUMBER(20): " << number << endl;
	
	string inteiro = int_to_string(1909);
	cout << "NUMBER TO STRING(1909): " << inteiro << endl;

	string sentence = get_sentence("p6a.txt");
	cout << "RANDOM SENTENCE: " << sentence << endl;

	string maiusculas = string_to_upper("ola98joao");
	cout << "UPPERCASE(ola98joao): " << maiusculas << endl;

	string escondido = unhide_letters("Futebol Clube do Porto", v);
	cout << "LETTERS UNHIDDEN: " << escondido << endl;

	cout << "CONTENTS OF A VECTOR: ";
	show_vector_char(v);
	cout << endl;

	bool var = show_file("p6a.txt");
	if (var == true)
		cout << "FILE EXISTS" << endl;
	else cout << "FILE DOESN'T EXIST" << endl;
}
