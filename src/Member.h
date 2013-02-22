#ifndef MEMBER_H_
#define MEMBER_H_

#include <iostream>

using namespace std;

class Member {
private:
	string memberName;
	double height;
	double weight;
	char gender;
public:
	Member();
	virtual ~Member();
	string getMemberName();
	double getHeight();
	double getWeight();
	char getGender();
	void setMemberName(string);
	void setHeight(double);
	void setWeight(double);
	void setGender(char);
};

#endif
