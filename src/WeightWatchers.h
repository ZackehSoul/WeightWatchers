#ifndef WEIGHT_WATCHERS_H_
#define WEIGHT_WATCHERS_H_
#include <algorithm>
#include <iostream>
#include <thread>					// Support for concurrent programming, experimental

using namespace std;

class WeightWatchers{
private:
	string exitStatus;	// If the user wants to exit the program
	string memberName;	// The user's name
	double height;		// The user's height
	double weight;		// The user's weight
	string gender;		// The user's gender
	int runTime;		// The allocated run time of the simulation
public:
	WeightWatchers();
	virtual ~WeightWatchers();
	string getExitStatus();					// Returns program's exit status
	void calculateStatistics();				// Calculates client's statistics
	void toReturnOrExit();					// Continues or exits the program
	string toLowerCase(string &);			// Converts strings to lower case
	double validateDouble(double);			// Validates input doubles
	string validateString(string, string);	// Validates input strings
	void clearScreen();						// Clears the terminal window for different OS
	void runSimulation();					// Runs the simulation
	void setExitStatus(string);				// Sets the exit status of the program
	void simulationRunTime();				// Keeps track of the runtime and exits the program
};

#endif
