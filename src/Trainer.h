#ifndef TRAINER_H_
#define TRAINER_H_
#include <ctime>
#include <iostream>
#include "Member.h"
#include <sstream>
#include <windows.h>

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
	void getTransactionTime();				// Returns the transaction time (for test purposes)
	string doubleDigits(int);				// Forces ints to double digits
};

#endif
