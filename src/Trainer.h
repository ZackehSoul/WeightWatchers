#ifndef TRAINER_H_
#define TRAINER_H_
#include <chrono>
#include <ctime>
#include <iostream>
#include "Member.h"
#include <sstream>
#include <thread>					// Support for concurrent programming, experimental

class Trainer {
private:
	bool isBusy;					// The trainer's status
	Member * associatedMember;		// The trainer's allocated client
	int transactionTime;			// The trainer's transaction time
	int trainerID;					// The trainer's ID number
public:
	Trainer();
	virtual ~Trainer();
	bool isTrainerBusy();					// Returns the trainer's status
	void setStatus(string);					// Sets the trainer's status
	const string currentTime();				// Returns the current time
	void decrementTime();					// Decrements the transaction time
	void setTransactionTime(double hours);	// Sets the transaction time
	string getStatus();						// Returns if the trainer is busy
	void printTransactionTime();			// Returns the transaction time (for test purposes)
	int getTransactionTime();				// Returns the transaction time as an integer
	string leadingZeros(int, int);			// Forces integers to a given digit amount
	void setTrainerID(int);					// Sets an ID number for each trainer
	string getTrainerID();					// Gets the ID number to 3 digits
	void assignMember(Member *);			// Assigns a member to the trainer
};

#endif
