#include "Trainer.h"

Trainer::Trainer() {
	isBusy = true;
	memberName = "";
	transactionTime = 0;
	decrementCounter = 0;
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
	time_t     now = time(0);
	struct tm  tstruct;
	char       buf[80];
	tstruct = *localtime(&now);
	strftime(buf, sizeof(buf), "%R", &tstruct);
	return buf;
}

int Trainer::setTransactionTime(int hour, int minutes){
	transactionTime = (hour * 3600) + (minutes * 60);
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
	} else if (status == "false"){
		isBusy = false;
	}
}
