#include "Channel.h"

Channel::Channel(string name){
	this->name = name;
}
string Channel::getName()
{
	return name;
}

void Channel::changeName(string title)
{
	name = title;
}

void Channel::pushProgram(string name, unsigned int duration, string day, unsigned int hour, unsigned int minutes, string type)
{
	programs.push_back(Program(name, duration, day, hour, minutes));
	programs.at(programs.size()-1).changeType(type);
}

bool Channel::removeAndSearchProgram(string programa)
{
	for (int i = 0; i < programs.size(); i++)
	{
		string programa1 = programs.at(i).getName();

		if (programa1 == programa)
		{
			programs.erase(programs.begin() + i);
			return true;
		}

	}
	return false;
}

bool Channel::updateAndSearchProgram(string name, unsigned int duration, string day, unsigned int hour, unsigned int minutes, string type, bool recorded)
{
	for (int i = 0; i < programs.size(); i++)
	{
		if (programs.at(i).getName() == name)
		{
			programs.at(i).updateProgram(name, duration, day, hour, minutes, type, recorded);
			return true;
		}
	}
	return false;
}

