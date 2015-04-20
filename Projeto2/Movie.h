#ifndef _MOVIE
 #define _MOVIE

#include<iostream>

using namespace std;


class Movie{
  string title;
  //  string type; // removed in the final version of the work text
  float cost;
  unsigned timesRented;
 public:
  Movie(string title, float cost);
  string gettitle() const;
  void incTimesRented();
  float returnCost() const;
  int getTimesRented() const;
};

#endif
