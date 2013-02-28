#ifndef WEIGHT_WATCHERS_H_
#define WEIGHT_WATCHERS_H_
#include <algorithm>
#include <iostream>

using namespace std;

class WeightWatchers{
private:
	string exitStatus;
	string memberName;
	double height;
	double weight;
	string gender;
public:
	WeightWatchers();
	virtual ~WeightWatchers();
	string getExitStatus();
	void calculateStatistics();
	void toReturnOrExit();
	string toLowerCase(string &);
	double validateDouble(double);
	string validateString(string, string);
};

#endif
