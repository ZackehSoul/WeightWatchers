#include "BodyStatsCalculator.h"
#include "Trainer.h"
#include "WeightWatchers.h"

Trainer::Trainer() {
	isBusy = false;
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
 * Sets the transaction time for a trainer's session with a client in seconds.
 *
 * @param minutes the amount of minutes
 */
void Trainer::setTransactionTime(double hours){
	// Stores transaction time as seconds
	transactionTime = (hours * 60) * 60;
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
	// Add the input to the stringstream
	ss << input;
	// If the user desires three digits
	if(digitAmount == 3){
		// If input is a single digit number it needs two zeros
		if(input < 10){
			output = "00" + ss.str();
		// If it's a two digit number, it needs one zero
		} else if (input >= 10 && input < 100){
			output = "0" + ss.str();
		// If it's already a three digit number or higher, leave it alone
		} else {
			output = ss.str();
		}
	// Same concept as above
	} else if (digitAmount == 2){
		if(input < 10){
			output = "0" + ss.str();
		} else {
			output = ss.str();
		}
	}
	return output; // Returns the output number
}

/**
 * Decrements the transaction time for a trainer so we can keep track of when they become
 * free.
 *
 * @param seconds the transaction time in seconds
 */
void Trainer::decrementTime(string memberName){
	WeightWatchers * pMain = new WeightWatchers();
	//Because the transaction time is decremented we need to remember it
	int tTime = transactionTime;
	// While the user has some time left, decrement in intervals of a second
	while(transactionTime > 0){
		transactionTime--;
		this_thread::sleep_for(chrono::milliseconds(1000));
	}
	// When the user has no time remaining, the trainer becomes available
	cout << memberName << " has gone home and Trainer " << getTrainerID() << " is no longer busy at " << pMain->currentTime() << ".\n" << endl;
	associatedMember = NULL;
	transactionTime = tTime;
	isBusy = false;
	delete pMain;
}

/**
 * Sets the trainer's status when a client is assigned to them. At some point this
 * will implement decrementTime() as a separate thread.
 *
 * @param status the trainer's status
 */
void Trainer::setStatus(string status){
	WeightWatchers * pMain = new WeightWatchers();
	// If a trainer becomes busy, start decrementing the transaction time
	if(status == "busy"){
		cout << "Trainer " << getTrainerID() << " is now busy with " << associatedMember->getMemberName() << " at " << pMain->currentTime() << ".\n" << endl;
		isBusy = true;
		thread decrementation(&Trainer::decrementTime, this, associatedMember->getMemberName());
		decrementation.detach();
	} else {
		isBusy = false;
	}
	delete pMain;
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

/**
 * Assigns a member from the queue to the trainer
 *
 * @param member the member to assign to the trainer
 */
void Trainer::assignMember(Member * member){
	associatedMember = member;
}
