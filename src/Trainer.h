#ifndef TRAINER_H_
#define TRAINER_H_
#include <chrono>			// To allow the threads to sleep
#include <iostream>			// For inputs and outputs
#include "Member.h"			// To create member pointers
#include "ServerClient.h"	// To allow printing to the server
#include <sstream>			// For string streams and converting numbers to strings
#include <thread>			// Support for concurrent programming, experimental

class Trainer {
private:
	bool isBusy;								// The trainer's status
	Member * associatedMember;					// The trainer's allocated client
	int transactionTime;						// The trainer's transaction time
	int trainerID;								// The trainer's ID number
	ServerClient * pServer = new ServerClient;	// Pointer to allow printing to server
public:
	Trainer();
	virtual ~Trainer();
	bool isTrainerBusy();					// Returns the trainer's status
	void setStatus(string);					// Sets the trainer's status
	const string currentTime();				// Returns the current time
	void decrementTime(string);				// Decrements the transaction time
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
