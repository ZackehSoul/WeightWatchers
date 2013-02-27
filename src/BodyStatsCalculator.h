#ifndef BODYSTATSCALCULATOR_H_
#define BODYSTATSCALCULATOR_H_
#include <cmath>
#include <iostream>

using namespace std;

class BodyStatsCalculator {
private:
	// Lists only available with c++11 or gnu++11
	string bodyMassBoundaries[5] = {"underweight.", "of ideal weight.", "slightly overweight.", "overweight.", "obese."};
	double maleBoundaries[4] = {20.7, 26.4, 27.8, 31.1};
	double femaleBoundaries[4] = {19.1, 25.8, 27.3, 32.3};
public:
	BodyStatsCalculator();
	virtual ~BodyStatsCalculator();
	double bodyMassIndex(double height, double weight);
	double bodySurfaceArea(double height, double weight);
	double leanBodyWeight(double height, double weight, string gender);
	string bodyMassResult(double bmi, string gender);
	double twoDecimalPlaces(double x);
	string getBodyMassResults(double bmi, double arr[]);
	string getGender(string gender);
};

#endif
