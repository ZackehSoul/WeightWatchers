#include "WeightWatchers.h"

double bodyMassIndex(double height, double weight){
	// Rounds BMI to two decimal places.
	double bmi = weight / pow((height / 100), 2);
	return twoDecimalPlaces(bmi);
}

double bodySurfaceArea(double height, double weight){
	// Rounds BSA to two decimal places.
	double bsa = sqrt((height * weight) / 3600);
	return twoDecimalPlaces(bsa);
}

double leanBodyWeight(double height, double weight, char gender){
	double lbw = 0;
	// Rounds LBW to two decimal places.
	if (gender == 'M' || gender == 'm'){
		lbw = (1.10 * weight) - (128 * (pow(weight, 2) / pow(height, 2)));
	} else if (gender == 'F' || gender == 'f'){
		lbw = (1.07 * weight) - (148 * (pow(weight, 2) / pow(height, 2)));
	}
	return twoDecimalPlaces(lbw);
}

double twoDecimalPlaces(double x){
	x = floorf(x * 100) / 100;
	return x;
}
