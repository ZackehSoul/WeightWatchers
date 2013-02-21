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
	if (gender == 'M' || gender == 'm'){
		result = getBodyMassResults(bmi, maleBoundaries);
	} else if (gender == 'F' || gender == 'f'){
		result = getBodyMassResults(bmi, femaleBoundaries);
	}
	return "Your body mass index indicates that you are " + result;
}

string getBodyMassResults(double bmi, double genderBoundaries[]){
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
