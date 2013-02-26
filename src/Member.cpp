#include "Member.h"

Member::Member() {
	// TODO Auto-generated constructor stub
}

Member::~Member() {
	// TODO Auto-generated destructor stub
}

string Member::getMemberName(){
	return memberName;
}

string Member::getGender(){
	return gender;
}

double Member::getHeight(){
	return height;
}

double Member::getWeight(){
	return weight;
}

void Member::setMemberName(string name){
	Member::memberName = name;
}

void Member::setGender(string gender){
	Member::gender = gender;
}

void Member::setHeight(double height){
	Member::height = height;
}

void Member::setWeight(double weight){
	Member::weight = weight;
}
