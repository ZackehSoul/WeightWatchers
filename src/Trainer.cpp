#include "BodyStatsCalculator.h"
#include "Trainer.h"

Trainer::Trainer() {
	isBusy = false;
	memberName = "";
	transactionTime = 0;
}

Trainer::~Trainer() {
	// TODO Auto-generated destructor stub
}

/**
 * Determines if a specified trainer is busy, by looking at the isBusy boolean.
 */
bool Trainer::isTrainerBusy(){
	if(isBusy){
		return true;
	} else {
		return false;
	}
}

/**
 * Retrieves the current local time of the system. Not used for anything major yet, but it
 * will come in useful.
 *
 * @return time the current time
 */
const string Trainer::currentTime() {
	time_t now = time(0);
	struct tm tstruct;
	char time[80];
	// Initializes struct with the localtime
	tstruct = *localtime(&now);
	// Returns time in the format HH:MM:SS
	strftime(time, sizeof(time), "%X", &tstruct);
	return time;
}

/**
 * Sets the transaction time for a trainer's session with a client in seconds.
 *
 * @param minutes the amount of minutes
 */
void Trainer::setTransactionTime(int minutes){
	// Stores transaction time as seconds
	transactionTime = minutes * 60;
}

/**
 * Prints out the transaction time remaining for a trainer's session. Converts the
 * transaction time stored in seconds to the HH:MM:SS format.
 */
void Trainer::getTransactionTime(){
	cout << doubleDigits(((transactionTime / 60 / 60) % 24)); cout << ":";
	cout << doubleDigits(((transactionTime / 60) % 60)); cout << ":";
	cout << doubleDigits((transactionTime % 60)) << endl;
}

/**
 * Forces an int to double digits if necessary and returns it as a string.
 *
 * @param input the input digits
 * @return digits the digits
 */
string Trainer::doubleDigits(int input){
	stringstream newInput;
	// If input is a single digit, add a leading 0 to input
	if((input < 10)){
		newInput << "0" << input;
	} else {
		// Else just add input
		newInput << input;
	}
	return newInput.str(); // Convert stringstream to string
}

/**
 * Decrements the transaction time for a trainer so we can keep track of when they become
 * free.
 *
 * @param seconds the transaction time in seconds
 */
void Trainer::decrementTime(int seconds){
	// While the user has some time left, decrement in intervals of a second
	while(seconds > 0){
		seconds--;
		Sleep(1000);
	}
	// When the user has no time remaining, the trainer becomes available
	isBusy = false;
}

/**
 * Sets the trainer's status when a client is assigned to them. At some point this
 * will implement decrementTime() as a separate thread.
 *
 * @param status the trainer's status
 */
void Trainer::setStatus(string status){
	// If a trainer becomes busy, start decrementing the transaction time
	if(status == "busy"){
		isBusy = true;
		//decrementTime(transactionTime);
		thread myThread = thread(boost::bind(&Trainer::decrementTime, this, transactionTime));
		myThread.join();
	} else {
		isBusy = false;
	}
}

/**
 * Returns the trainer's current status, depending on the isBusy boolean.
 *
 * @return status the trainer's status
 */
string Trainer::getStatus(){
	string status;
	if(isBusy){
		status = "This trainer is busy.";
	} else {
		status = "This trainer is free.";
	}
	return status;
}
