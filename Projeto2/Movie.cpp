#include "Movie.h"


Movie::Movie(string title, float cost){
	this->title = title;
	this->cost = cost;
	timesRented = 0;
}

string Movie::gettitle() const
{
	return title;
}

void Movie::incTimesRented(){
	timesRented++;
}

float Movie::returnCost() const{
	return cost;
}

int Movie::getTimesRented() const{
	return timesRented;
}
