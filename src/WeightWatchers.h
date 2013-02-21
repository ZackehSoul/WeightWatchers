#ifndef WEIGHT_WATCHERS_H_
#define WEIGHT_WATCHERS_H_
#include <iostream>
#include <cmath>
#include <vector>
#include <cstdio>
#include <array>

using namespace std;

double bodyMassIndex(double height, double weight);
double bodySurfaceArea(double height, double weight);
double leanBodyWeight(double height, double weight, char gender);
string getGender(char gender);
string bodyMassResult(double bmi, char gender);
double twoDecimalPlaces(double x);
string getBodyMassResults(double bmi, double arr[]);
string bodyMassBoundaries[] = {"underweight.", "of ideal weight.", "marginally overweight.", "overweight.", "obese."};

void test();
void teddyBear();
void toddler();

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
