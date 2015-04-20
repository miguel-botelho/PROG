#ifndef _CHANNEL
 #define _CHANNEL

#include<iostream>
#include<vector>
#include<string>

#include "Program.h"

using namespace std;

class Channel{
  string name;
  vector<Program> programs;
 public:
  Channel(string name);
  string getName();
  void changeName(string title);
  void pushProgram(string name, unsigned int duration, string day, unsigned int hour, unsigned int minutes, string type);
  bool removeAndSearchProgram(string programa);
  bool updateAndSearchProgram(string name, unsigned int duration, string day, unsigned int hour, unsigned int minutes, string type, bool recorded);
};

#endif
