#include "BodyStatsCalculator.h"
#include "Member.h"
#include "WeightWatchers.h"

WeightWatchers::WeightWatchers(){
	// TODO Auto-generated constructor stub
}

WeightWatchers::~WeightWatchers(){
	// TODO Auto-generated destructor stub
}

void WeightWatchers::calculateStatistics(){
	BodyStatsCalculator * pStats = new BodyStatsCalculator();
	string memberName; double height; double weight; string gender;

	cout << "Please enter the required information:\n" << endl;
	Member member;
	cout << "Please enter your first name: "; cin >> memberName;
	member.setMemberName(memberName);
	cout << "Please enter your height(cm): "; cin >> height;
	member.setHeight(height);
	cout << "Please enter your weight(kg): "; cin >> weight;
	member.setWeight(weight);
	cout << "Please enter your gender: "; cin >> gender; cout << endl;
	member.setGender(toLowerCase(gender));


	double bmi = pStats->bodyMassIndex(member.getHeight(), member.getWeight());
	double bsa = pStats->bodySurfaceArea(member.getHeight(), member.getWeight());
	double lbw = pStats->leanBodyWeight(member.getHeight(), member.getWeight(), member.getGender());
	string clientGender = pStats->getGender(member.getGender());
	string bmiResult = pStats->bodyMassResult(bmi, member.getGender());

	system("CLS");
	cout << "These are your calculated statistics:\n" << endl;
	cout << "Your Body Mass Index is " << bmi << " which indicates that you are " << bmiResult << endl;
	cout << "Your Body Surface Area is " << bsa << " square metres." << endl;
	cout << "Your Lean Body Weight is " << lbw << " kilograms." << endl;
	cout << clientGender << "\n" << endl;

	toReturnOrExit();
	delete pStats;
}

void WeightWatchers::toReturnOrExit(){
	string selection;
	cout << "To return to the main menu type \"menu\" or type \"exit\" to exit: ";
	cin >> WeightWatchers::exitStatus;
}

string WeightWatchers::toLowerCase(string &gender)
{
	transform(gender.begin(), gender.end(), gender.begin(), ::tolower);
	return gender;
}
