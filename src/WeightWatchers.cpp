#include "WeightWatchers.h"

int main() {
	double bmi = bodyMassIndex(175, 77);
	double bsa = bodySurfaceArea(175, 77);
	double lbw = leanBodyWeight(175, 77);
	cout << "Body Mass Index is " << bmi << "." << endl;
	cout << "Body Surface Area is " << bsa << " square metres." << endl;
	cout << "Lean Body Weight is " << lbw << " kilograms." << endl;
	return 0;
}
