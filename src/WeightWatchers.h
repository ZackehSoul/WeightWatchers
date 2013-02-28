#ifndef WEIGHT_WATCHERS_H_
#define WEIGHT_WATCHERS_H_
#include <algorithm>
#include <iostream>

using namespace std;

class WeightWatchers{
private:
	string exitStatus;	// If the user wants to exit the program
	string memberName;	// The user's name
	double height;		// The user's height
	double weight;		// The user's weight
	string gender;		// The user's gender
public:
	WeightWatchers();
	virtual ~WeightWatchers();
	string getExitStatus();					// Returns program's exit status
	void calculateStatistics();				// Calculates client's statistics
	void toReturnOrExit();					// Continues or exits the program
	string toLowerCase(string &);			// Converts strings to lower case
	double validateDouble(double);			// Validates input doubles
	string validateString(string, string);	// Validates input strings
};

#endif
