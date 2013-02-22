#ifndef MEMBER_H_
#define MEMBER_H_

#include <iostream>

using namespace std;

class Member {
private:
	double height;
	double weight;
	char gender;
public:
	Member();
	virtual ~Member();
	double getHeight();
	double getWeight();
	char getGender();
};

#endif
