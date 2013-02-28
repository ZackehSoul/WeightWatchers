#include "BodyStatsCalculator.h"
#include "Member.h"
#include "WeightWatchers.h"

WeightWatchers::WeightWatchers(){
	exitStatus = "";
	memberName = "";
	height = 0;
	weight = 0;
	gender = "";
}

WeightWatchers::~WeightWatchers(){
	// TODO Auto-generated destructor stub
}

/**
 * Calculates the client's BMI, BSA and LBW and returns the results to the users after
 * validating the inputs. Asks the user if they want to return to the main menu after usage
 * or if they wish to exit the program.
 */
void WeightWatchers::calculateStatistics(){
	BodyStatsCalculator * pStats = new BodyStatsCalculator();
	// Sets up a new member and asks for user input
	cout << "Please enter the required information:\n" << endl;
	Member member;

	// Validates and sets the client's name
	cout << "Please enter your first name: ";
	memberName = validateString(memberName, "name");
	member.setMemberName(memberName);

	// Validates and sets the client's height
	cout << "Please enter your height(cm): ";
	height = validateDouble(height);
	member.setHeight(height);

	// Validates and sets the client's weight
	cout << "Please enter your weight(kg): ";
	weight = validateDouble(weight);
	member.setWeight(weight);

	// Validates and sets the client's gender
	cout << "Please enter your gender: ";
	gender = validateString(gender, "gender");
	gender = toLowerCase(gender);

	// Verify the user has entered a correct gender before allowing them to continue
	enterGender:
	if (gender == "male" || gender == "female" || gender == "f" || gender == "m"){
		member.setGender(gender);
	} else {
		cout << "Please provide a valid gender: ";
		goto enterGender;
	}

	// Pass all the information to the Member class
	double bmi = pStats->bodyMassIndex(member.getHeight(), member.getWeight());
	double bsa = pStats->bodySurfaceArea(member.getHeight(), member.getWeight());
	double lbw = pStats->leanBodyWeight(member.getHeight(), member.getWeight(), member.getGender());
	string clientGender = pStats->getGender(member.getGender());
	string bmiResult = pStats->bodyMassResult(bmi, member.getGender());

	// Clear the screen and display the resulting information
	system("CLS");
	cout << "These are your calculated statistics:\n" << endl;
	cout << "Your Body Mass Index is " << bmi << " which indicates that you are " << bmiResult << endl;
	cout << "Your Body Surface Area is " << bsa << " square metres." << endl;
	cout << "Your Lean Body Weight is " << lbw << " kilograms." << endl;
	cout << clientGender << "\n" << endl;

	// Ask the user if they wish to exit or return to the main menu
	toReturnOrExit();
	delete pStats;
}

/**
 * Validates the users input to check that it's a double.
 *
 * @double input the users input
 * @return input the validated input
 */
double WeightWatchers::validateDouble(double input){
	// Currently has a bug if the user enters a double with an integer as the first character.
	// Can be solved by changing the input to string and converting to double.
	int i = 0;
	while (1) {
		cin >> input;
		if (cin.good()){
			break;
		} else {
			if (i == 0) cout << endl, i++;
			cout << "Please provide a valid number: ";
			cin.clear();
			while (cin.get() != '\n');
		}
	}
	return input;
}

/**
 * Validates the input string to force the user to enter a string without any integers.
 *
 * @string input the users input string
 * @string attribute the attribute the user is setting
 * @return input the validated input
 */
string WeightWatchers::validateString(string input, string attribute){
	int i = 0;
	while(1){
		cin >> input;
		if (find_if(input.begin(), input.end(), ::isdigit) != input.end())
		{
			if (i == 0) cout << endl, i++;
			cout << "Please provide a valid " << attribute << ": ";
			cin.clear();
			while (cin.get() != '\n');
		} else {
			break;
		}
	}
	return input;
}

/**
 * Asks the user if they want to exit the application or return to the main menu.
 *
 */
void WeightWatchers::toReturnOrExit(){
	string selection;
	cout << "To return to the main menu type \"menu\" or type \"exit\" to exit: ";
	cin >> WeightWatchers::exitStatus;
}

/**
 * Converts the input gender to lower case to make for easier handling.
 *
 * @string gender the client's input gender
 * @return gender the client's gender in lowercase
 */
string WeightWatchers::toLowerCase(string &gender)
{
	transform(gender.begin(), gender.end(), gender.begin(), ::tolower);
	return gender;
}

string WeightWatchers::getExitStatus(){
	return exitStatus;
}
