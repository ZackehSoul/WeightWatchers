#ifndef MEMBER_H_
#define MEMBER_H_
#include <iostream>

using namespace std;

class Member {
private:
	string memberName;				// The user's name
	double height;					// The user's height
	double weight;					// The user's weight
	string gender;					// The user's gender
	const string arrivalTime;		// The user's arrival time
	const string waitingTime;		// The user's waiting time
public:
	Member();
	virtual ~Member();
	string getMemberName();		// Returns the member's name
	double getHeight();			// Returns the member's height
	double getWeight();			// Returns the member's weight
	string getGender();			// Returns the member's gender
	void setMemberName(string);	// Sets the member's name
	void setHeight(double);		// Sets the member's height
	void setWeight(double);		// Sets the member's weight
	void setGender(string);		// Sets the member's gender
};

#endif
