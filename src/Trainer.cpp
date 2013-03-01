#include "Trainer.h"

Trainer::Trainer() {
	isBusy = false;
	memberName = "";
	transactionTime = 0;
}

Trainer::~Trainer() {
	// TODO Auto-generated destructor stub
}

bool Trainer::isTrainerBusy(){
	if(isBusy){
		return true;
	} else {
		return false;
	}
}

const string Trainer::currentTime() {
	time_t now = time(0);
	struct tm tstruct;
	char time[80];
	tstruct = *localtime(&now);
	strftime(time, sizeof(time), "%H%M", &tstruct);
	return time;
}

void Trainer::setTransactionTime(int minutes){
	transactionTime = minutes * 60;
}

int Trainer::getTransactionTime(){
	return transactionTime;
}

void Trainer::decrementTime(int seconds){
	while(seconds != 0){
		seconds--;
		Sleep(1000);
	}
	isBusy = false;
}

void Trainer::setStatus(string status){
	if(status == "true"){
		isBusy = true;
		decrementTime(transactionTime);
	} else if (status == "false"){
		isBusy = false;
	}
}
