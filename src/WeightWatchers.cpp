#include "WeightWatchers.h"
#include "BodyStatsCalculator.h"

int main() {
	BodyStatsCalculator * pStats = new BodyStatsCalculator();
	double height; double weight; char gender;
	cout << "Please enter the client's height(cm): "; cin >> height;
	cout << "Please enter the client's weight(kg): "; cin >> weight;
	cout << "Please enter the client's gender: "; cin >> gender;
	double bmi = pStats->bodyMassIndex(height, weight);
	double bsa = pStats->bodySurfaceArea(height, weight);
	double lbw = pStats->leanBodyWeight(height, weight, gender);
	string clientGender = pStats->getGender(gender);
	string bmiResult = pStats->bodyMassResult(bmi, gender);
	cout << "Body Mass Index is " << bmi << endl;
	cout << "Body Surface Area is " << bsa << " square metres." << endl;
	cout << "Lean Body Weight is " << lbw << " kilograms." << endl;
	cout << clientGender << endl;
	cout << bmiResult << endl;
	test();
	teddyBear();
	toddler();

	delete pStats;
}
