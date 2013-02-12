#include "OOSD.h"

int main() {
	double bmi = bodyMassIndex(1.8, 75.0);
	double bsa = bodySurfaceArea(180, 75);
	double lbw = leanBodyWeight(180, 75);
	cout << "Body Mass Index is " << bmi << "." << endl;
	cout << "Body Surface Area is " << bsa << " cubic metres." << endl;
	cout << "Lean Body Weight is " << lbw << " kilograms." << endl;
	return 0;
}
