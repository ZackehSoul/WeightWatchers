#include "BodyStatsCalculator.h"

BodyStatsCalculator::BodyStatsCalculator() {

}

BodyStatsCalculator::~BodyStatsCalculator() {

}

double BodyStatsCalculator::bodyMassIndex(double height, double weight){
	// Rounds BMI to two decimal places.
	double bmi = weight / pow((height / 100), 2);
	return twoDecimalPlaces(bmi);
}

double BodyStatsCalculator::bodySurfaceArea(double height, double weight){
	// Rounds BSA to two decimal places.
	double bsa = sqrt((height * weight) / 3600);
	return twoDecimalPlaces(bsa);
}

double BodyStatsCalculator::leanBodyWeight(double height, double weight, char gender){
	double lbw = 0;
	// Rounds LBW to two decimal places.
	if (gender == 'M' || gender == 'm'){
		lbw = (1.10 * weight) - (128 * (pow(weight, 2) / pow(height, 2)));
	} else if (gender == 'F' || gender == 'f'){
		lbw = (1.07 * weight) - (148 * (pow(weight, 2) / pow(height, 2)));
	}
	return twoDecimalPlaces(lbw);
}

double BodyStatsCalculator::twoDecimalPlaces(double x){
	x = floorf(x * 100) / 100;
	return x;
}

string BodyStatsCalculator::getGender(char gender){
	string clientGender;
	if (gender == ('M' | 'm')){
		clientGender = "The client's gender is male.";
	} else if (gender == ('F' | 'f')){
		clientGender = "The client's gender is female.";
	}
	return clientGender;
}

string BodyStatsCalculator::bodyMassResult(double bmi, char gender){
	string result;
	if (gender == 'M' || gender == 'm'){
		result = getBodyMassResults(bmi, maleBoundaries);
	} else if (gender == 'F' || gender == 'f'){
		result = getBodyMassResults(bmi, femaleBoundaries);
	}
	return "Your body mass index indicates that you are " + result;
}

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
