#include "BodyStatsCalculator.h"
#include "Member.h"
#include "Trainer.h"
#include "WeightWatchers.h"

WeightWatchers::WeightWatchers(){
	exitStatus = "";		// Exit status isn't set because user hasn't selected action
	memberName = "";		// Member Name isn't set until user inputs data
	height = 0;				// Height isn't set until user inputs data
	weight = 0;				// Weight isn't set until user inputs data
	gender = "";			// Gender isn't set until user inputs data
	runTime = 0;			// RunTime isn't set until user inputs data
	isSimRunning = false;	// Simulation isn't always running when this class is created
}

WeightWatchers::~WeightWatchers(){
	// TODO Auto-generated destructor stub
}

/**
 * Calculates the client's BMI, BSA and LBW and returns the results to the users after
 * validating the inputs. Asks the user if they want to return to the main menu after usage
 * or if they wish to exit the program.
 */
void WeightWatchers::calculateStatistics(string memberInput, string genderInput){
	BodyStatsCalculator * pStats = new BodyStatsCalculator();
	// Sets up a new member and asks for user input
	cout << "Please enter the required information:\n" << endl;
	Member member;
	member.setMemberName(memberInput);

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
	gender = validateString(genderInput, "gender");
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
	clearScreen();
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
 * Runs the client server simulation after retrieving the desired inputs from the users. Also
 * displays how long the server is going to run from and what the current time is. Asks the
 * user if they want to return to the main menu after running.
 */
void WeightWatchers::runSimulation(){
	int trainerNo; double transactionTime = 0;
	BodyStatsCalculator * pStats = new BodyStatsCalculator();

	// Display the opening information in the cleared screen
	cout << "Please enter the required information:\n" << endl;
	cout << "Please enter the amount of time you want to run the simulation(min): "; cin >> runTime;
	cout << "Please enter the amount of trainers you wish to utilize: "; cin >> trainerNo;
	cout << "Please enter the amount of transaction time you wish to have(hours): ";
	// Input and validate transaction time
	transactionTime = validateDouble(transactionTime);
	// Create array of trainer objects based on user input and a list to track them in
	Trainer trainers[trainerNo];
	for(int i = 1; i <= trainerNo; i++){
		// Give all trainers an ID number
		trainers[i - 1].setTrainerID(i);
		// Set their transaction time
		trainers[i - 1].setTransactionTime(pStats->twoDecimalPlaces(transactionTime));
		// Add them to the trainer queue
		trainerList.addTrainerElement(&trainers[i - 1]);
	}

	// Because the following thread decrements runTime, we need a variable to remember the original
	int runningTime = runTime;
	// The simulation is now running, so set the boolean to true to enable the thread
	isSimRunning = true;
	// Create new thread to track the run time of the simulation
	thread simRunTime(&WeightWatchers::simulationRunTime, this);
	// Detach thread so it can run independently
	simRunTime.detach();

	// Clear screen and display current time and how long simulation will run
	clearScreen();
	cout << "The time is now " << currentTime() << "." << endl;
	cout << "The server will continue to run for ";
	// Formats the remaining server time correctly
	if(((runningTime / 60) % 24) != 0){
		// If the server runs for an hour and X minutes print an hour
		if (((runningTime / 60) % 24) == 1) cout << "an hour";
		// Else print X hours
		else cout << (runningTime / 60) % 24 << " hours";
	}
	// If the server runs for X hours and minutes > 0 append " and X minute(s)"
	if((runningTime % 60) != 0){
		// If there is an hour specified print and
		if(((runningTime / 60) % 24) != 0){
			cout << " and ";
		}
		if(runningTime % 60 != 1){
			// If it's not a minute, append " minutes."
			cout << runningTime % 60 << " minutes.\n" << endl;
		} else {
			// If it's a single minute, print a minute
			cout << "a minute.\n" << endl;
		}
	} else {
		// Else just print a new line
		cout << ".\n" << endl;
	}

	// Start the simulation of visitors arriving and detach so it runs independently
	thread visitorGeneration(&WeightWatchers::generateVisitingMembers, this);
	visitorGeneration.detach();

	// Start serving arriving visitors and detach so it runs independently
	thread visitorAssignment(&WeightWatchers::serveMembers, this);
	visitorAssignment.detach();

	// Just to freeze the menu so you can observe the simulation
	string string; cin >> string;
	// Enter the blank input above to have the ability to return to the main page
	toReturnOrExit();
}

/**
 * Tracks and assigns member objects from the start of the queue to a trainer. This only
 * occurs when both lists aren't empty.
 */
void WeightWatchers::serveMembers(){
	int i = 0;
	// If the simulation is running, the queue is moving
	while(isSimRunning){
		// If there is both a trainer and a member waiting, the member becomes assigned
		if(!memberList.isEmpty() && !trainerList.isEmpty()){
			// A member is removed from the front of the queue
			memberList.removeMemberElement();
			// They're assigned to the first trainer in the trainer queue
			trainerList.removeTrainerElement(memberList.popMemberFunc());
		} else if (!memberList.isEmpty() && trainerList.isEmpty() && newMember == i){
			// newMember has to match i so this message isn't constantly printed
			cout << "A new member is now waiting in the queue. The time is currently" << currentTime() << "." << endl;
			// Notify how many members are in the queue
			cout << "There are now " << memberList.listElements("member") << " members in the queue.\n" << endl;
			// Increment i to stop looped outputs until another member arrives
			i++;
		}
	}
	return; // When the simulation stops running, kill this thread
}

/**
 * Generates visitors for the simulation, making them arrivate at random intervals between each other.
 * The visitors are generated based from the members included in the member list. Runs as a separate thread
 * and is killed when the simulation ends.
 */
void WeightWatchers::generateVisitingMembers(){
	int randomIndex; string memberName;
	// Create array of member objects based the member list
	vector<string> v;
	// Open the members file
	ifstream myfile("members.txt");
	if(myfile.is_open()){
		string name;
		// Whilst there are lines left in the file
		while(getline(myfile, name)){
			// Add the name to the vector
			v.push_back(name);
		}
	}
	// Set the seed to initialize random numbers
	srand(time(NULL));
	// If the simulation is running and there are no members left
	while(isSimRunning && !v.empty()){
		// Sleep for a random amount of time to simulate the gap between member arrival
		this_thread::sleep_for(chrono::milliseconds(((rand() % 9 + 1) * 100000)));
		// Create a member object
		Member member;
		// Choose a random index within the vector
		randomIndex = rand() % v.size();
		// Find the name of the member at the chosen index
		memberName = v.at(randomIndex);
		// Erase this member from the vector
		v.erase(v.begin() + randomIndex);
		// Name the member object the name at the chosen index
		member.setMemberName(memberName);
		// Add this member to the queue of waiting members
		memberList.addMemberElement(&member);
		// Notify of their arrival
		cout << memberName << " has just arrived at the club." << endl;
		// Increment newMember so serveMembers() can print
		if(trainerList.isEmpty()) newMember++;
	}
	return; // If the simulation isn't running, end the thread
}

/**
 * Tracks the allocated run time of the simulation and exits when the time is up.
 */
void WeightWatchers::simulationRunTime(){
	// Converts the run time to seconds, easier to handle
	runTime = (runTime * 60) - 10;
	// If the simulation is still running and it has remaining running time
	while(runTime > 0 && isSimRunning){
		// Decrement the runTime remaining
		runTime--;
		// Sleep for a second
		this_thread::sleep_for(chrono::milliseconds(1000));
	}
	// If the simulation has been closed, end this thread
	if(!isSimRunning){runTime = 0; return;}
	// If the simulation is still running, display termination notice and end the simulation
	cout << "\nYour session is about to expire...  ";
	for(int i = 10; i > 0; i--){
		if(i == 10) cout << "\b" << i;
		else cout << "\b\b" << 0 << i;
		this_thread::sleep_for(chrono::milliseconds(1000));
	}
	// Exit the program when the session time is over
	std::exit(0);
}

/**
 * Validates the users input to check that it's a double.
 *
 * @param input the users input
 * @return input the validated input
 */
double WeightWatchers::validateDouble(double input){
	// Currently has a bug if the user enters a double with an integer as the first character.
	int i = 0;
	while (1) {
		cin >> input;
		if (cin.good()){
			break;
		} else {
			// Only print one blank line for neat formatting
			if (i == 0) cout << endl, i++;
			// Show the error and clear the input
			cout << "Please provide a valid number: ";
			cin.clear();
			while (cin.get() != '\n');
		}
	}
	return input; // Return the validated input
}

/**
 * Validates the input string to force the user to enter a string without any integers.
 *
 * @param input the users input string
 * @param attribute the attribute the user is setting
 * @return input the validated input
 */
string WeightWatchers::validateString(string input, string attribute){
	int i = 0;
	while(1){
		cin >> input;
		// If the input doesn't contain a number, show error
		if (find_if(input.begin(), input.end(), ::isdigit) != input.end())
		{
			// Only print a blank line once for neat formatting
			if (i == 0) cout << endl, i++;
			// Shows error message and require new input
			cout << "Please provide a valid " << attribute << ": ";
			cin.clear();
			while (cin.get() != '\n');
		} else {
			break;
		}
	}
	return input; // Else we return the validated input
}

/**
 * Asks the user if they want to exit the application or return to the main menu.
 *
 */
void WeightWatchers::toReturnOrExit(){
	string selection;
	cout << "To return to the main menu type \"menu\" or type \"exit\" to exit: ";
	cin >> selection;
	// Redirects to setExitStatus instead of inputting exitStatus directly so the simulation is closed
	setExitStatus(selection);
}

/**
 * Converts the input gender to lower case to make for easier handling.
 *
 * @param gender the client's input gender
 * @return gender the client's gender in lowercase
 */
string WeightWatchers::toLowerCase(string &gender){
	transform(gender.begin(), gender.end(), gender.begin(), ::tolower);
	return gender;
}

/**
 * Returns the current exit status of the program.
 */
string WeightWatchers::getExitStatus(){
	return exitStatus;
}

/**
 * Allows setting of the exit status to allow the closing of the program.
 * Used as a way for the user to terminate as opposed to forced closure.
 *
 * @param string the exit status
 */
void WeightWatchers::setExitStatus(string string){
	// If the user chose to exit, we close the simulation first to kill all threads
	if(string == "exit"){
		isSimRunning = false;
	}
	exitStatus = string;
}

/**
 * Clears the current command windows on either Windows or Linux using an if statement
 * to avoid any bad practices. Sometimes unsafe, but for this assignment it's appropriate.
 */
void WeightWatchers::clearScreen(){
#ifdef _WIN32 // Detect if user is running windows
	system("CLS");
#else // If user isn't running Windows (most likely running UNIX)
	system("clear");
#endif
}

/**
 * Retrieves the current local time of the system. Not used for anything major yet, but it
 * will come in useful.
 *
 * @return time the current time
 */
const string WeightWatchers::currentTime() {
	time_t now = time(0);
	struct tm tstruct;
	char time[80];
	// Initializes structure with the local time
	tstruct = *localtime(&now);
	// Returns time in the format HH:MM:SS
	strftime(time, sizeof(time), "%X", &tstruct);
	return time;
}

/**
 * Called from the Trainer class when they're no longer busy so they can add themselves to the queue again.
 *
 * @return trainerList the queue of trainers
 */
void WeightWatchers::noLongerBusy(Trainer * trainer){
	trainerList.addTrainerElement(trainer);
}
