#ifndef TRAINER_H_
#define TRAINER_H_
#include <ctime>
#include <iostream>
#include <windows.h>

using namespace std;

class Trainer {
private:
	bool isBusy;					// The trainer's status
	string memberName;				// The trainer's allocated client
	int transactionTime;			// The trainer's transaction time
public:
	Trainer();
	virtual ~Trainer();
	bool isTrainerBusy();					// Returns the trainer's status
	void setStatus(string);					// Sets the trainer's status
	const string currentTime();				// Returns the current time
	void decrementTime(int);				// Decrements the transaction time
	void setTransactionTime(int seconds);	// Sets the transaction time
	int getTransactionTime();				// Returns the transaction time (for test purposes)
};

#endif
