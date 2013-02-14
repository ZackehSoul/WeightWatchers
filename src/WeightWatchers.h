#ifndef WEIGHT_WATCHERS_H_
#define WEIGHT_WATCHERS_H_
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

double bodyMassIndex(double height, double weight);
double bodySurfaceArea(double height, double weight);
double leanBodyWeight(double height, double weight, char gender);
string getGender(char gender);
string bodyMassResult(double bmi, char gender);
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
};

struct Toddler {
  PersonData kiddy;
  TeddyBear bruin;
};

#endif
