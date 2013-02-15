#include "WeightWatchers.h"

int main() {
	double height; double weight; char gender;
	cin >> height >> weight >> gender;
	double bmi = bodyMassIndex(height, weight);
	double bsa = bodySurfaceArea(height, weight);
	double lbw = leanBodyWeight(height, weight, gender);
	string clientGender = getGender(gender);
	string bmiResult = bodyMassResult(bmi, gender);
	cout << "Body Mass Index is " << bmi << endl;
	cout << "Body Surface Area is " << bsa << " square metres." << endl;
	cout << "Lean Body Weight is " << lbw << " kilograms." << endl;
	cout << clientGender << endl;
	cout << bmiResult << endl;
	test();
	teddyBear();
	toddler();
}
