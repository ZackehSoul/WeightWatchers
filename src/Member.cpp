#include "Member.h"

Member::Member() {
	memberName = "";
	height = 0;
	weight = 0;
	gender = "";
	string arrivalTime = "";
	string waitingTime = "";
}

Member::~Member() {
	// TODO Auto-generated destructor stub
}

/**
 * Retrieves the client's name from the input information.
 *
 * @return memberName the client's name
 */
string Member::getMemberName(){
	return memberName;
}

/**
 * Retrieves the client's gender from the input information.
 *
 * @return gender the client's gender
 */
string Member::getGender(){
	return gender;
}

/**
 * Retrieves the client's height from the input information.
 *
 * @return height the client's height
 */
double Member::getHeight(){
	return height;
}

/**
 * Retrieves the client's weight from the input information.
 *
 * @return weight the client's weight
 */
double Member::getWeight(){
	return weight;
}

/**
 * Sets the name of the client from the input information.
 *
 * @param name the client's name
 */
void Member::setMemberName(string name){
	Member::memberName = name;
}

/**
 * Sets the gender of the client from the input information.
 *
 * @param gender the client's gender
 */
void Member::setGender(string gender){
	Member::gender = gender;
}

/**
 * Sets the height of the client from the input information.
 *
 * @param height the client's height
 */
void Member::setHeight(double height){
	Member::height = height;
}

/**
 * Sets the weight of the client from the input information.
 *
 * @param weight the client's weight
 */
void Member::setWeight(double weight){
	Member::weight = weight;
}
