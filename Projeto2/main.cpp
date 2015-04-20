#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Date.h"
#include "Box.h"

// Randomly generates a valid day, hour and minute
Date currentDate(){
  srand ((unsigned int) time(NULL));
  int hour, minute, weekday;

  hour = rand() % (23-0+1) + 0;
  minute = rand() & (59-0+1) + 0;
  weekday = rand() % (6-0+1) + 0;

  if (0 == weekday)
	  Date("Monday", hour, minute);
  else if

}

using namespace std;

int main(){
  Box box = Box("?????????", currentDate());

  exit(0);
}
