#include "Box.h"



Box::Box(string passwd, Date date):currentDate(date){
  password = passwd;
}

bool Box::rentMovies(string title)
{
	for (int i = 0; i < movieClub.size(); i++)
	{
		string titulo = movieClub.at(i).gettitle();
		if (titulo == title)
		{
			movieClub.at(i).incTimesRented();	
			seenMovies.push_back(movieClub.at(i));
			movieClub.erase(movieClub.begin() + i);
			return true;
		}
		}

	for (int i = 0; i < seenMovies.size(); i++)
	{
		string titulo = seenMovies.at(i).gettitle();
		if (titulo == title)
		{
			seenMovies.at(i).incTimesRented();
			return true;
		}

	}
	return false;
}

float Box::moneySpent() const
{

	float money = 0;

	for(int i = 0; i < seenMovies.size(); i++)
	{
		money = money + seenMovies.at(i).returnCost();
	}
	return money;

}

int Box::timesWhatched(string title) const
{

	for (int i = 0; i < seenMovies.size(); i++)
	{
		string titulo = seenMovies.at(i).gettitle();
		if (titulo == title)
		{
			return seenMovies.at(i).getTimesRented();
		}
}
	return -1;
}

bool Box::changePassword()
{
	string pass;
	cout << "Your password: "; cin >> pass; cin.ignore(1000, '\n');
	if (pass == password)
	{
		cout << "Your new password: "; cin >> password; cin.ignore(1000, '\n');
		return true;
	}
	return false;
}

bool Box::createdChanel()
{
	string chanel;
	cout << "Name of the channel: "; cin >> chanel; cin.ignore(1000, '\n');

	for (int i = 0; i < channels.size(); i++)
	{
		string canal = channels.at(i).getName();
		if (canal == chanel)
		{
			return false;
		}
	}
	channels.push_back(Channel(chanel));
	return true;
}

bool Box::removeChanel()
{
	string chanel;
	cout << "Name of the channel: "; cin >> chanel; cin.ignore(1000, '\n');
	for (int i = 0; i < channels.size(); i++)
	{
		string canal = channels.at(i).getName();
		if (canal == chanel)
		{
			channels.erase(channels.begin() + i);
			return true;
		}
	}
	return false;

}

bool Box::updateChanel()
{
	string name;

	cout << "Name of the channel: "; cin >> name; cin.ignore(1000, '\n');

	for (int i = 0; i < channels.size(); i++)
	{
		string canal = channels.at(i).getName();
		if (canal == name)
		{
			cout << "New name of the channel: "; cin >> name; cin.ignore(1000, '\n');
			channels.at(i).changeName(name);
			return true;
		}

	}
	return false;
}

bool Box::createdProgram(string chanel)
{
	string programa;
	unsigned int duracao;
	string dia;
	unsigned int hora;
	unsigned int minutos;

	string tipo;
	for (int i = 0; i < channels.size(); i++)
	{
		string canal = channels.at(i).getName();
	if (canal == chanel)
	{
		cout << "Name of the program: "; cin >> programa; cin.ignore(1000, '\n');
		cout << "Duration of the program: "; cin >> duracao; cin.ignore(1000, '\n');
		cout << "Day of the program: "; cin >> dia; cin.ignore(1000, '\n');
		cout << "Hours of the program: "; cin >> hora; cin.ignore(1000, '\n');
		cout << "Minutes of the program: "; cin >> minutos; cin.ignore(1000, '\n');
		cout << "Type of the program: "; cin >> tipo; cin.ignore(1000, '\n');
		channels.at(i).pushProgram(programa, duracao, dia, hora, minutos, tipo);
		return true;
	}
	}
	return false;
}

bool Box::removeProgram()
{
	string programa;
	bool flag;
	
	cout << "Name of the program: "; cin >> programa; cin.ignore(1000, '\n');

	for (int i = 0; i < channels.size(); i++)
	{
		if (channels.at(i).removeAndSearchProgram(programa))
			flag = true;
	}
	if (flag == true)
		return true;
	else return false;
}

bool Box::updateProgram()
{
	string programa;
	unsigned int duracao;
	string dia;
	unsigned int hora;
	unsigned int minutos;
	string tipo;
	int recorded;
	bool recordedFlag;

	cout << "Name of the program: "; cin >> programa; cin.ignore(1000, '\n');
	cout << "Duration of the program: "; cin >> duracao; cin.ignore(1000, '\n');
	cout << "Day of the program: "; cin >> dia; cin.ignore(1000, '\n');	
	cout << "Hours of the program: "; cin >> hora; cin.ignore(1000, '\n');
	cout << "Minutes of the program: "; cin >> minutos; cin.ignore(1000, '\n');
	cout << "Type of the program: "; cin >> tipo; cin.ignore(1000, '\n');
	cout << "Program recorded (0 - false, 1 - true)? "; cin >> recorded; cin.ignore(1000, '\n');

	if (recorded == 0)
		recordedFlag = false;
	else recordedFlag = true;

	for (int i = 0; i < channels.size(); i++)
	{
		if (channels.at(i).updateAndSearchProgram(programa, duracao, dia, hora, minutos, tipo, recordedFlag))

	}
	
	return false;
}
