#include "WeightWatchers.h"

string getGender(char gender){
	string clientGender;
	if (gender == ('M' | 'm')){
		clientGender = "The client's gender is male.";
	} else if (gender == ('F' | 'f')){
		clientGender = "The client's gender is female.";
	}
	return clientGender;
}

string bodyMassResult(double bmi, char gender){
	string result;
	if (gender == ('M' | 'm')){
		double maleBoundaries[] = {20.7, 26.4, 27.8, 31.1};
		result = getBodyMassResults(bmi, maleBoundaries);
	} else if (gender == ('F' | 'f')){
		double femaleBoundaries[] = {19.1, 25.8, 27.3, 32.3};
		result = getBodyMassResults(bmi, femaleBoundaries);
	}
	return "Your body mass index indicates that you are " + result;
}

string getBodyMassResults(double bmi, double genderBoundaries[]){
	string result;
	for(int i = 0; i < 5; i++){
		if(i == 0){
			if(bmi < genderBoundaries(i)){
				result = bodyMassBoundaries(i);
			}
		} else if (i > 0 && (i - 2) < 5 && i != 5){
			if(bmi >= genderBoundaries(i) && bmi < genderBoundaries(i + 1)){
				result = bodyMassBoundaries(i);
			}
		} else if (i == 5){
			if(bmi > genderBoundaries(i)){
				result = bodyMassBoundaries(i);
			}
		}
	}
	return result;
}

