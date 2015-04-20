#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <vector>
#include <fstream>

using namespace std;

int tentativas();
bool add_string_to_vector(string searchletter, vector <string> &v);
string string_to_upper(string s);
struct Score_info;
unsigned int count_letters(string s);
unsigned int count_diff_letters(string s);
unsigned int calculate_score(string s, unsigned int tnm, unsigned int t);
void show_best_scores(const vector <Score_info> &best_scores);
vector <Score_info> get_best_scores(string filename);
void save_best_scores(string filename, const vector <Score_info> &best_scores, int n_best);
void update_best_scores(vector <Score_info> &best_scores, const Score_info &si);
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


struct Score_info {
	string name;
	int score;
};

void p9()
{	
	char bet;
	int erros = 1;
	string nome;
	vector <char> v;
	vector <Score_info> best_scores = get_best_scores("best.txt");
	string file;
	string s;
	int pontuacao = 0;
	ifstream output;
	int nr_tentativas = inicio();
	cout << "Best players until now:" << endl;
	show_best_scores(best_scores);
	cout << "Player name ? "; getline(cin, nome);

	output.open("hangman_config.txt");
	getline(output, file);
	string frase = get_sentence(file);
	output.close();
	
	string asteriscos = unhide_letters(frase, v);
	bool win = true;
	
	unsigned int time_begin = (unsigned int) time(0);
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
			unsigned int time_end = (unsigned int) time(0);
			int elapsed_time = time_end - time_begin;
			pontuacao = calculate_score(frase, nr_tentativas, elapsed_time);

			cout << "PREVIOUS BETS   : "; show_vector_char(v); cout << endl;
			cout << "KNOWN LETTERS   : " << asteriscos << endl << endl;
			cout << "YOU ARE A WINNER. CONGRATULATIONS !" << endl;
			cout << "You took " << elapsed_time << " seconds and have obtained " << pontuacao << " points" << endl;
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

	Score_info si = {nome, pontuacao};
	update_best_scores(best_scores, si);
	save_best_scores("best.txt", best_scores, 10);
	best_scores = get_best_scores("best.txt");
	cout << "Best players until now:" << endl;
	show_best_scores(best_scores);
}
