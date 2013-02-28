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
	int transactionTime;		// The trainer's transaction time
	int decrementCounter;
public:
	Trainer();
	virtual ~Trainer();
	bool isTrainerBusy();
	void setStatus(string);
	const string currentTime();
	void decrementTime(int);
	int setTransactionTime(int hour, int minutes);
};

#endif
