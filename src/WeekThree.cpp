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
		if (bmi < 20.7){
			result = "underweight.";
		} else if (bmi >= 20.7 && bmi < 26.4){
			result = "of ideal weight.";
		} else if (bmi >= 26.4 && bmi < 27.8){
			result = "moderately overweight.";
		} else if (bmi >= 27.8 && bmi < 31.1){
			result = "overweight.";
		} else if (bmi >= 31.1){
			result = "obese.";
		}
	} else if (gender == ('F' | 'f')){
		if (bmi < 19.1){
			result = "underweight.";
		} else if (bmi >= 19.1 && bmi < 25.8){
			result = "of ideal weight.";
		} else if (bmi >= 25.8 && bmi < 27.3){
			result = "moderately overweight.";
		} else if (bmi >= 27.3 && bmi < 32.3){
			result = "overweight.";
		} else if (bmi >= 32.3){
			result = "obese.";
		}
	}
	return "Your body mass index indicates that you are " + result;
}
