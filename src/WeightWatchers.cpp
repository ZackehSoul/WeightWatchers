#include "WeightWatchers.h"
#include "BodyStatsCalculator.h"
#include "Member.h"

int main() {
	int selection;
	system("CLS");
	cout << "Welcome to the Healthy Club Command System. " << endl;
	cout << "Please type the number of the feature you wish to use\n" << endl;
	cout << "1. Calculate your body statistics\n" << endl;
	cout << "Your selection: "; cin >> selection;

	if(selection == 1){
		system("CLS");
		calculateStatistics();
	}
}

void calculateStatistics(){
	BodyStatsCalculator * pStats = new BodyStatsCalculator();
		string memberName; double height; double weight; char gender;

		system("CLS");

		cout << "Please enter the required information\n" << endl;
		Member member;
		cout << "Please enter the client's first name: "; cin >> memberName;
		member.setMemberName(memberName);
		cout << "Please enter the client's height(cm): "; cin >> height;
		member.setHeight(height);
		cout << "Please enter the client's weight(kg): "; cin >> weight;
		member.setWeight(weight);
		cout << "Please enter the client's gender: \n"; cin >> gender;
		member.setGender(gender);

		double bmi = pStats->bodyMassIndex(member.getHeight(), member.getWeight());
		double bsa = pStats->bodySurfaceArea(member.getHeight(), member.getWeight());
		double lbw = pStats->leanBodyWeight(member.getHeight(), member.getWeight(), member.getGender());
		string clientGender = pStats->getGender(member.getGender());
		string bmiResult = pStats->bodyMassResult(bmi, member.getGender());

		cout << "Body Mass Index is " << bmi << endl;
		cout << "Body Surface Area is " << bsa << " square metres." << endl;
		cout << "Lean Body Weight is " << lbw << " kilograms." << endl;
		cout << clientGender << endl;
		cout << bmiResult << endl;

		delete pStats;
}
