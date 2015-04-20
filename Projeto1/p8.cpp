#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <vector>
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
int inicio();
void checkVector(char letra, vector <char> &vetorf);
bool add_letter_to_vector(char searchletter, vector <char> &vetorf);
bool right_bet(char searchletter, string frase);



void p8()

{
	
	char bet;
	int erros = 1;
	vector <char> v;
	string file;
	string s;
	ifstream output;
	int nr_tentativas = inicio();

	output.open("hangman_config.txt");
	getline(output, file);
	string frase = get_sentence(file);

	output.close();
	
	string asteriscos = unhide_letters(frase, v);
	bool win = true;

	for (int i2 = 0; i2 < nr_tentativas; i2++)
	{

		cout << "PREVIOUS BETS   : "; show_vector_char(v); cout << endl;
		cout << "KNOWN LETTERS   : " << asteriscos << endl;
		cout << "BET (LETTER)    ? "; cin >> bet;
		bet = toupper(bet);
		bool jogada_repetida = add_letter_to_vector(bet, v);
		asteriscos = unhide_letters(frase, v);

		bool var = right_bet(bet, frase);
		ifstream display;
		string output;
		

		if (var == false)
		{
			if (jogada_repetida == true)
			{
				i2--;
			}
			else
			{
			string nr = int_to_string(erros);
			string ficheiro = "hangman_drawing";
			ficheiro.append(nr);
			ficheiro.append(".txt");
			display.open(ficheiro);
			show_file(ficheiro);
			erros++;
			}
		}
		else i2--;


		if (asteriscos == (string_to_upper(frase)) )
		{
			cout << "PREVIOUS BETS   : "; show_vector_char(v); cout << endl;
			cout << "KNOWN LETTERS   : " << asteriscos << endl << endl;
		cout << "YOU ARE A WINNER. CONGRATULATIONS !" << endl;
		win = true;
		break;
		}
		win = false;
	}
	
	if (win == false)
	{
		cout << "PREVIOUS BETS   : "; show_vector_char(v); cout << endl;
		cout << "KNOWN LETTERS   : " << asteriscos << endl << endl;
		cout << "The word/sentence was: " << frase << endl;
		cout << "YOU HAVE LOST ! WE ARE GOING TO CALL THE UNDERTAKERS :-(" << endl;
	}
}

