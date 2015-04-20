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

int sizeNumber(int number)
{
	int i = 0;
	while (!(0 == number))
	{
		number = number / 10;
		i++;
	}
	return i;
}
//
string string_to_upper(string s)
{
	for (int i = 0; i < s.size(); i++)
	{
		s.at(i) = toupper(s.at(i));
	}
	return s;
}
//
bool searchSentenceInVector(char firstletter, vector <char> vetorf)
{
	for (int i = 0; i < vetorf.size(); i++)
	{
		if (firstletter == vetorf.at(i))
		return true;
	}
	return false;
}
//
int tentativas()
{
	string s;
	ifstream output;
	int nr_tentativas;
	output.open("hangman_config.txt");
	while( !(output.eof()))
	{
		getline(output, s);
		if (s == "(nao alterar)")
		{
			getline(output, s);
			while (! (s == "(nao alterar)"))
			{
				getline(output, s);
				if (s == "(nao alterar)")
					break;
			}
			
			output >> nr_tentativas;
			output.close();
			return nr_tentativas;
		}
	}
	return nr_tentativas;
}
//
bool add_string_to_vector(string searchletter, vector <string> &v)
{
	bool var = true;
	for (unsigned int i = 0; i < v.size(); i++)
	{
		if (searchletter == v.at(i))
		{
			var = true;
			break;
		}
		else var = false;
	}
	if (var == false)
	{
		v.push_back(searchletter);
		return false;
	}
	
	else if ((var == true) && (v.size() == 0))
	{
		v.push_back(searchletter);
		return false;
	}
	return true;
}
//
unsigned int count_letters(string s)
{
	int nr_letras = 0;
	for (unsigned int i = 0; i < s.size(); i++)
	{
		string n = s.substr(i, 1);
		if (((n >= "a") && (n <= "z")) || ((n >= "A") && (n <= "Z")))
			nr_letras++;
	}

	return nr_letras;
}
//
unsigned int count_diff_letters(string s)
{
	int nr_letras = 0;
	vector <string> v;

	for (unsigned int i = 0; i < s.size(); i++)
	{
		string n = s.substr(i, 1);
		n = string_to_upper(n);
		if (((n >= "a") && (n <= "z")) || ((n >= "A") && (n <= "Z")))
		{
			bool var = add_string_to_vector(n, v);
			if (var == false)
				nr_letras++;
		}
		
	}

	return nr_letras;
}
//
unsigned int calculate_score(string s, unsigned int tnm, unsigned int t)
{
	int tnl = count_letters(s);
	int ndl = count_diff_letters(s);
	int mnt = tentativas();
	int score = 100000 * (1 + ndl / tnl) / (t * (1 + 0.1 * tnm / mnt));
	return score;
}
//
vector <Score_info> get_best_scores(string filename)
{
	ifstream display;
	string player;
	vector <Score_info> v;
	int score;
	display.open(filename);
	while( !(display.eof()))
	{
		display >> score;
		getline(display, player);
		if (player == "")
			break;
		else
		{
		player = player.substr(1,(player.size() -1));
		Score_info var = {player, score};
		v.push_back(var);
		}
	}
		return v;
}
//
void show_best_scores(const vector <Score_info> &best_scores)
{
	for (unsigned int i = 0; i < best_scores.size(); i++)
	{
		Score_info n = best_scores.at(i);
		cout << n.score << " - " << n.name << endl;
	}

}
//
void update_best_scores(vector <Score_info>& best_scores, const Score_info &si)
{
	bool var = false;
	best_scores.push_back(si);
	
	while (var == false)
	{
		for (unsigned int i = 0; i < best_scores.size(); i++)
		{
			if (i == (best_scores.size() - 1) )
			{
				var = true;
				break;
			}
			else
			{
			Score_info n = best_scores.at(i);
			Score_info n1 = best_scores.at(i + 1);
			int score = n.score;
			int score1 = n1.score;
			if (score >= score1)
				var = true;
			else
			{
				best_scores.at(i) = n1;
				best_scores.at(i + 1) = n;
				var = false;
				i++;
				break;
			}
			}
		}

	}
		

}
//
void save_best_scores(string filename, const vector <Score_info> &best_scores, int n_best)
{
	ofstream input;
	input.open(filename);
	input.close();
	input.open(filename);
	if (best_scores.size() < (unsigned) n_best)
	{
	for (unsigned int i = 0; i < best_scores.size(); i++)
	{
		if (i == (best_scores.size() - 1) )
		{
			Score_info n = best_scores.at(i);
			int number = n.score;
			string guy = n.name;
			input << number << " " << guy;
		}
		else
		{
			Score_info n = best_scores.at(i);
			int number = n.score;
			string guy = n.name;
			input << number << " " << guy << endl;
		}
	}
	}
	else
	{
		for (int i = 0; i < n_best; i++)
	{
		if (i == (n_best - 1) )
		{
			Score_info n = best_scores.at(i);
			int number = n.score;
			string guy = n.name;
			input << number << " " << guy;
		}
		else
		{
			Score_info n = best_scores.at(i);
			int number = n.score;
			string guy = n.name;
			input << number << " " << guy << endl;
		}
	}
	}


}
//
int inicio()
{
	string s;
	ifstream output;
	int nr_tentativas;
	output.open("hangman_config.txt");
	while( !(output.eof()))
	{
		getline(output, s);
		if (s == "(nao alterar)")
		{
			getline(output, s);
			cout << s << endl;
			while (! (s == "(nao alterar)"))
			{
				getline(output, s);
				if (s == "(nao alterar)")
					break;
				else cout << s << endl;
			}
			
			output >> nr_tentativas;
			output.close();
			return nr_tentativas;
		}
	}
	return nr_tentativas;
}
//
bool add_letter_to_vector(char searchletter, vector <char> &v)
{
	bool var = true;
	if ((searchletter >= 'A') && (searchletter <= 'Z'))
	{
	for (int i = 0; i < v.size(); i++)
	{
		if (searchletter == v.at(i))
		{
			var = true;
			break;
		}
		else var = false;
	}
	if (var == false)
	{
		v.push_back(searchletter);
		return false;
	}
	
	else if ((var == true) && (v.size() == 0))
	{
		v.push_back(searchletter);
		return false;
	}
	return true;
	}
	else
	return true;
}
//
string get_sentence(string filename)
{
	srand ((unsigned int) time(0));

	ifstream display;
	string output;
	const int a = 1;
	int b;
	int i = 0;

	display.open(filename);
	if (display.fail() )
	{
		cout << "ERROR: File not found!" << endl;
		exit(0);
	}
	else 
	{
		display >> b;
		int r = (rand() & b) + a;
		while (! (r == i))
		{
			getline(display, output);
			i++;
		}
		getline(display, output);
	}
	display.close();
	return output;
}
//
string int_to_string(int n)
{
	string numberf;
	int size = sizeNumber(n);
	int sizei = size;

	for (int i = 0; i < sizei; i++)
	{
		int firstnumber = n / (pow(10, (size - 1)));
		n = n % (int) (pow(10, (size - 1)));
		numberf.push_back((char) firstnumber + '0');
		size--;
	}

	return numberf;
}
//
bool right_bet(char searchletter, string frase)
{
	for (int i = 0; i < frase.size(); i++)
	{
		char letra = toupper(frase.at(i));
		if (searchletter == letra)
			return true;
	}
	return false;
}
//
bool show_file(string filename)
{
	ifstream display;
	string output;
	display.open(filename);
	if (display.fail() )
	{
		return false;
	}
	else {
		while(! (display.eof()) )
		{
		getline(display,output);	
		cout << output << endl;
		}
	}
	display.close();
	return true;
}
//
void show_vector_char(vector <char> v)
{
	char letra = '0';
	cout << "[ ";

	for (int i = 0; i < v.size(); i++)
	{
		cout << v.at(i) << " ";
	}

	cout << "]";
}
//
string unhide_letters(string s, vector<char> letters)
{
	char letra = '0';
	string asteriscos;
	// s = sentence e letters = vetorf
	

	for (int i = 0; i < s.size(); i++)
	{
		char firstletter = s.at(i);
		firstletter = toupper(firstletter);
		bool var = searchSentenceInVector(firstletter, letters);
		if (true == var)
			asteriscos.push_back(firstletter);
		else if (firstletter == ' ')
			asteriscos.push_back(' ');
		else asteriscos.push_back((char) 42);
	}
	return asteriscos;
}
