#ifndef WEIGHT_WATCHERS_H_
#define WEIGHT_WATCHERS_H_
#include <algorithm>			// For validation functions and transform()
#include <ctime>		// To retrieve the current time
#include <fstream>				// Needed for the file stream
#include <iostream>				// For input/output
#include "LinkedList.h"			// Needed for the member and trainer queues
#include <thread>				// Support for concurrent programming, experimental
#include <vector>				// Vector used for the visitor simulation

using namespace std;

class WeightWatchers{
private:
	string exitStatus;			// If the user wants to exit the program
	string memberName;			// The user's name
	double height;				// The user's height
	double weight;				// The user's weight
	string gender;				// The user's gender
	int runTime;				// The allocated run time of the simulation
	bool isSimRunning;			// If the simulation is running
	LinkedList trainerList;		// Queue of trainers waiting to serve clients
	LinkedList memberList;		// Queue of members waiting to be served
	int newMember = 0;
public:
	WeightWatchers();
	virtual ~WeightWatchers();
	string getExitStatus();						// Returns program's exit status
	void calculateStatistics(string, string);	// Calculates client's statistics
	void toReturnOrExit();						// Continues or exits the program
	string toLowerCase(string &);				// Converts strings to lower case
	double validateDouble(double);				// Validates input doubles
	string validateString(string, string);		// Validates input strings
	void clearScreen();							// Clears the terminal window for different OS
	void runSimulation();						// Runs the simulation
	void setExitStatus(string);					// Sets the exit status of the program
	void simulationRunTime();					// Keeps track of the runtime and exits the program
	void generateVisitingMembers();				// Generates visitors for the healthy club
	void serveMembers();						// Assigns members to trainers and makes them both busy
	const string currentTime();					// Returns the current time
	void noLongerBusy(Trainer *);				// Called from Trainer class to add themselves back to the queue
};

#endif
