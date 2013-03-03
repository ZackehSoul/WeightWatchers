#include "BodyStatsCalculator.h"
#include "Trainer.h"

Trainer::Trainer() {
	isBusy = false;
	memberName = "";
	trainerID = 0;
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
void Trainer::setTransactionTime(double hours){
	// Stores transaction time as seconds
	transactionTime = hours * 60 * 60;
}

/**
 * Returns transaction time as an integer.
 *
 * @return transaction time the transaction time
 */
int Trainer::getTransactionTime(){
	return transactionTime;
}

/**
 * Prints out the transaction time remaining for a trainer's session. Converts the
 * transaction time stored in seconds to the HH:MM:SS format.
 */
void Trainer::printTransactionTime(){
	cout << leadingZeros(((transactionTime / 60 / 60) % 24), 2); cout << ":";
	cout << leadingZeros(((transactionTime / 60) % 60), 2); cout << ":";
	cout << leadingZeros((transactionTime % 60), 2) << endl;
}

/**
 * Forces an integer to a given number of digits if necessary and returns it as a string.
 *
 * @param input the input digits
 * @param digitAmount the amount of desired digits
 * @return output the new number
 */
string Trainer::leadingZeros(int input, int digitAmount){
	string output; stringstream ss;
	ss << input;
	if(digitAmount == 3){
		if(input < 10){
			output = "00" + ss.str();
		} else if (input >= 10 && input < 100){
			output = "0" + ss.str();
		} else {
			output = ss.str();
		}
	} else if (digitAmount == 2){
		if(input < 10){
			output = "0" + ss.str();
		} else {
			output = ss.str();
		}
	}
	return output;
}

/**
 * Decrements the transaction time for a trainer so we can keep track of when they become
 * free.
 *
 * @param seconds the transaction time in seconds
 */
void Trainer::decrementTime(){
	// While the user has some time left, decrement in intervals of a second
	while(transactionTime > 0){
		transactionTime--;
		cout << transactionTime << endl; // For testing decrementing
		this_thread::sleep_for(chrono::milliseconds(1000));
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

/**
 * Sets the trainer's ID number
 *
 * @param ID the trainer's ID number
 */
void Trainer::setTrainerID(int ID){
	trainerID = ID;
}

/**
 * Returns trainer ID as a three digit integer
 *
 * @return ID the trainer's ID number
 */
string Trainer::getTrainerID(){
	string ID = leadingZeros(trainerID, 3);
	return ID;
}
