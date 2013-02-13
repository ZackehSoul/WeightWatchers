#include "WeightWatchers.h"

int main() {
	char gender = 'm';
	double height = 175;
	double weight = 77;
	double bmi = bodyMassIndex(height, weight);
	double bsa = bodySurfaceArea(height, weight);
	double lbw = leanBodyWeight(height, weight, gender);
	string clientGender = getGender(gender);
	string bmiResult = bodyMassResult(bmi, gender);
	cout << "Body Mass Index is " << bmi << "." << endl;
	cout << "Body Surface Area is " << bsa << " square metres." << endl;
	cout << "Lean Body Weight is " << lbw << " kilograms." << endl;
	cout << clientGender << endl;
	cout << bmiResult << endl;
	test();
	teddyBear();
	toddler();
}
