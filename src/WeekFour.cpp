#include "WeightWatchers.h"

void test() {
	// Create two people, foo & bar.
	PersonData foo, bar;
	// Create new person rumple with the given data
	PersonData rumple = { 175, 77, 'F' };

	// Assign data to foo
	foo.height = 175;
	foo.weight = 77;
	foo.gender = 'M';

	// Ask for and enter data to bar
	cout << "Enter a person's height, weight and gender: " ;
	cin >> bar.height >> bar.weight >> bar.gender;
	cout << endl;

	// Return foo's data
	cout << "foo's data is : " <<  foo.height << " : "
			<< foo.weight << " : "
			<< foo.gender << endl;

	// Return bar's data
	cout << "bar's data is : " <<  bar.height  << " : "
			<< bar.weight << " : "
			<< bar.gender << endl;

	// Return rumple's data
	cout << "rumple's data is : " <<  rumple.height  << " : "
			<< rumple.weight << " : "
			<< rumple.gender << endl;
}

void teddyBear(){
	TeddyBear rupert;
	rupert.height = 150;
	rupert.colour = "Brown";

	cout << "rupert's data is : " <<  rupert.height  << " : "
			<< rupert.colour << endl;

	TeddyBear freddie;
	freddie.height = 175;
	freddie.colour = "brown";
	ShyBear violet;
	violet.setHeight(175);
	violet.setColour("yellow");

	cout << "Violet: " << violet.toString() << endl;
	cout << "Violet's colour is: " << violet.getColour() << endl;
	cout << "Violet's height is: " << violet.getHeight() << endl;


	cout << "Freddie: " << freddie.toString() << endl;
}

void toddler(){
	Toddler fred;
	fred.kiddy.height = 145;
	fred.kiddy.weight = 79;
	fred.kiddy.gender = 'M';
	fred.bruin.height = 0.34;
	fred.bruin.colour = "Golden";

	cout << "fred's data is : " <<  fred.kiddy.height  << " : "
			<< fred.kiddy.weight   << " : "
			<< fred.kiddy.gender << " : "
			<< fred.bruin.height << " : "
			<< fred.bruin.colour << endl;
}

string TeddyBear::toString(){
	char number[100];
	sprintf(number, "%g", height);
	return "Height = " + string(number) + " colour = " + colour;
}

string ShyBear::getColour(){
	return colour;
}

double ShyBear::getHeight(){
	return height;
}

void ShyBear::setColour(string colour){
	ShyBear::colour = colour;
}

void ShyBear::setHeight(double height){
	ShyBear::height = height;
}

string ShyBear::toString(){
	char number[100];
	sprintf(number, "%g", height);
	return "Height = " + string(number) + " colour = " + colour;
}
