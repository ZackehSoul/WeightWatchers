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
	string memberName;				// The trainer's allocated client
	int transactionTime;			// The trainer's transaction time
	Member client;					// The client associated with the trainer
public:
	Trainer();
	virtual ~Trainer();
	bool isTrainerBusy();					// Returns the trainer's status
	void setStatus(string);					// Sets the trainer's status
	const string currentTime();				// Returns the current time
	void decrementTime(int);				// Decrements the transaction time
	void setTransactionTime(int seconds);	// Sets the transaction time
	string getStatus();						// Returns if the trainer is busy
	void printTransactionTime();				// Returns the transaction time (for test purposes)
	int getTransactionTime();				// Returns the transaction time as an integer
	string doubleDigits(int);				// Forces integers to double digits
};

#endif
