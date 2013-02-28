#include "BodyStatsCalculator.h"

BodyStatsCalculator::BodyStatsCalculator() {
	// TODO Auto-generated constructor stub
}

BodyStatsCalculator::~BodyStatsCalculator() {
	// TODO Auto-generated destructor stub
}

/**
 * Calculates the Body Mass Index of the client.
 *
 * @double height the client's height
 * @double weight the client's weight
 * @return bmi to two decimal places
 */
double BodyStatsCalculator::bodyMassIndex(double height, double weight){
	// Rounds BMI to two decimal places.
	double bmi = weight / pow((height / 100), 2);
	return twoDecimalPlaces(bmi);
}

/**
 * Calculates the Body Surface Area of the client.
 *
 * @double height the client's height
 * @double weight the client's weight
 * @return bsa to two decimal places
 */
double BodyStatsCalculator::bodySurfaceArea(double height, double weight){
	// Rounds BSA to two decimal places.
	double bsa = sqrt((height * weight) / 3600);
	return twoDecimalPlaces(bsa);
}

/**
 * Calculates the Lean Body Weight of the client.
 *
 * @double height the client's height
 * @double weight the client's weight
 * @string gender the client's gender
 * @return lbw to two decimal places
 */
double BodyStatsCalculator::leanBodyWeight(double height, double weight, string gender){
	double lbw = 0;
	// Rounds LBW to two decimal places.
	if (gender == "m" || gender == "male"){
		lbw = (1.10 * weight) - (128 * (pow(weight, 2) / pow(height, 2)));
	} else if (gender == "f" || gender == "female"){
		lbw = (1.07 * weight) - (148 * (pow(weight, 2) / pow(height, 2)));
	}
	return twoDecimalPlaces(lbw);
}

/**
 * Calculates the input to two decimal places to keep results nicely rounded.
 *
 * @double x the input result
 * @return x the rounded input
 */
double BodyStatsCalculator::twoDecimalPlaces(double x){
	x = floorf(x * 100) / 100;
	return x;
}

/**
 * Returns the gender of the client.
 *
 * @string gender the gender of the client
 * @return clientGender the client's gender
 */
string BodyStatsCalculator::getGender(string gender){
	string clientGender;
	if (gender == "m" || gender == "male"){
		clientGender = "Your gender is male.";
	} else if (gender == "f" || gender == "female"){
		clientGender = "Your gender is female.";
	}
	return clientGender;
}

/**
 * Returns the result of the client's BMI.
 *
 * @double bmi the client's BMI
 * @string gender the client's gender
 * @return result the client's BMI result
 */
string BodyStatsCalculator::bodyMassResult(double bmi, string gender){
	string result;
	if (gender == "m" || gender == "male"){
		result = getBodyMassResults(bmi, maleBoundaries);
	} else if (gender == "f" || gender == "female"){
		result = getBodyMassResults(bmi, femaleBoundaries);
	}
	return result;
}

/**
 * Calculates which boundary the client's BMI falls under dependent on gender.
 *
 * @double bmi the client's BMI
 * @double[] genderBoundaries the boundaries for the BMI of each gender
 * @return result the client's BMI result
 */
string BodyStatsCalculator::getBodyMassResults(double bmi, double genderBoundaries[]){
	string result;
	for(int i = 0; i <= 4; i++){
		if(i == 0){
			if(bmi < genderBoundaries[i]){
				result = bodyMassBoundaries[i];
			}
		} else if (i > 0 && i != 4){
			if(bmi >= genderBoundaries[i - 1] && bmi < genderBoundaries[i]){
				result = bodyMassBoundaries[i];
			}
		} else if (i == 4){
			if(bmi > genderBoundaries[i - 1]){
				result = bodyMassBoundaries[i];
			}
		}
	}
	return result;
}
