#ifndef WEIGHT_WATCHERS_H_
#define WEIGHT_WATCHERS_H_
#include <algorithm>
#include <iostream>

using namespace std;

class WeightWatchers{
private:
public:
	WeightWatchers();
	virtual ~WeightWatchers();
	string exitStatus;
	void calculateStatistics();
	void toReturnOrExit();
	string toLowerCase(string &);
	double validateDouble(double, string);
	string validateString(string, string);
};

#endif
