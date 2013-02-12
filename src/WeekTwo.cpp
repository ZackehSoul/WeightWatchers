#include "OOSD.h"

double bodyMassIndex(double height, double weight){
	double bmi = weight / pow(height, 2);
	return bmi;
}

double bodySurfaceArea(double height, double weight){
	double bsa = std::sqrt((height * weight) / 3600);
	return bsa;
}

double leanBodyWeight(double height, double weight){
	double lbw = (1.10 * weight) - (128 * (pow(weight, 2) / pow(height, 2)));
	return lbw;
}
