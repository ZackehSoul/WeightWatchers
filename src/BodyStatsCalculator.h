#ifndef BODYSTATSCALCULATOR_H_
#define BODYSTATSCALCULATOR_H_
#include <cmath>		// For mathematical functions
#include <iostream>		// For inputs and outputs

using namespace std;

class BodyStatsCalculator {
private:
	// Strings of the results of being outside boundaries with BMI
	string bodyMassBoundaries[5] = {"underweight.", "of ideal weight.", "slightly overweight.", "overweight.", "obese."};
	// Boundaries of classifications for male BMI
	double maleBoundaries[4] = {20.7, 26.4, 27.8, 31.1};
	// Boundaries of classifications for female BMI
	double femaleBoundaries[4] = {19.1, 25.8, 27.3, 32.3};
public:
	BodyStatsCalculator();
	virtual ~BodyStatsCalculator();
	double bodyMassIndex(double height, double weight);					// Calculates Body Mass Index
	double bodySurfaceArea(double height, double weight);				// Calculates Body Surface Area
	double leanBodyWeight(double height, double weight, string gender);	// Calculates Lean Body Weight
	string bodyMassResult(double bmi, string gender);					// Calculates the BMI classification
	double twoDecimalPlaces(double x);									// Rounds doubles to two decimal places
	string getBodyMassResults(double bmi, double arr[]);				// Returns the member's BMI results
	string getGender(string gender);									// Returns the member's gender
};

#endif
