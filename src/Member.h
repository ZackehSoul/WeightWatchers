#ifndef MEMBER_H_
#define MEMBER_H_
#include <iostream>

using namespace std;

class Member {
private:
	string memberName;
	double height;
	double weight;
	string gender;
public:
	Member();
	virtual ~Member();
	string getMemberName();
	double getHeight();
	double getWeight();
	string getGender();
	void setMemberName(string);
	void setHeight(double);
	void setWeight(double);
	void setGender(string);
};

#endif
