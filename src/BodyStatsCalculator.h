#ifndef BODYSTATSCALCULATOR_H_
#define BODYSTATSCALCULATOR_H_

#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

class BodyStatsCalculator {
public:
	BodyStatsCalculator();
	virtual ~BodyStatsCalculator();
	double bodyMassIndex(double height, double weight);
	double bodySurfaceArea(double height, double weight);
	double leanBodyWeight(double height, double weight, char gender);
	string bodyMassResult(double bmi, char gender);
	double twoDecimalPlaces(double x);
	string getBodyMassResults(double bmi, double arr[]);
	string getGender(char gender);
};

static string bodyMassBoundaries[] = {"underweight.", "of ideal weight.", "marginally overweight.", "overweight.", "obese."};
static double maleBoundaries[] = {20.7, 26.4, 27.8, 31.1};
static double femaleBoundaries[] = {19.1, 25.8, 27.3, 32.3};

#endif
