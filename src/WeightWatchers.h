#ifndef WEIGHT_WATCHERS_H_
#define WEIGHT_WATCHERS_H_
#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>

using namespace std;

void test();
void teddyBear();
void toddler();

void calculateStatistics();

struct PersonData {
	double height;
	double weight;
	char gender;
};

struct TeddyBear {
  double height;
  string colour;
  string toString();
};

struct Toddler {
  PersonData kiddy;
  TeddyBear bruin;
};

class ShyBear{
private:
	double height;
	string colour;
public:
	string getColour();
	void setColour(string);
	double getHeight();
	void setHeight(double);
	string toString();
};

#endif
