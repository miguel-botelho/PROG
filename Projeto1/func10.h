#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <vector>
#include <fstream>

using namespace std;

struct Score_info {
	string name;
	int score;
};
unsigned int count_letters(string s);
unsigned int count_diff_letters(string s);
unsigned int calculate_score(string s, unsigned int tnm, unsigned int t);
vector <Score_info> get_best_scores(string filename);
void show_best_scores(const vector <Score_info> &best_scores);
void update_best_scores(vector <Score_info>& best_scores, const Score_info &si);
void save_best_scores(string filename, const vector <Score_info> &best_scores, int n_best);
bool add_string_to_vector(string searchletter, vector <string> &v);
int tentativas();
string string_to_upper(string s);
int inicio();
bool add_letter_to_vector(char searchletter, vector <char> &v);
string get_sentence(string filename);
string int_to_string(int n);
int sizeNumber(int number);
bool right_bet(char searchletter, string frase);
bool show_file(string filename);
void show_vector_char(vector <char> v);
string unhide_letters(string s, vector<char> letters);
bool searchSentenceInVector(char firstletter, vector <char> vetorf);
