#ifndef WeightWatchers_H_
#define WeightWatchers_H_
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

double bodyMassIndex(double height, double weight);
double bodySurfaceArea(double height, double weight);
double leanBodyWeight(double height, double weight, char gender);
string getGender(char gender);
string bodyMassResult(double bmi, char gender);

#endif
