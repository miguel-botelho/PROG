#include "Program.h"

Program::Program(string name, unsigned int duration, string day, unsigned int hour, unsigned int minutes):exhibitionDate(day, hour, minutes){
	this->name = name;
	this->duration = duration;
	type = "???";
	recorded = false;
  // rest of initialisations
}

string Program::getName()
{
	return name;
}

void Program::updateProgram(string name, unsigned int duration, string day, unsigned int hour, unsigned int minutes, string type, bool recorded)
{
	this->name = name;
	this->duration = duration;
	this->type = type;
	this->recorded = recorded;
	
}
void Program::changeType(string type)
{
	this->type=type;
}


