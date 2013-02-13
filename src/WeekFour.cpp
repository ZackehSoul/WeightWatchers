#include "WeightWatchers.h"

void test() {
	// Create two people, foo & bar.
	PersonData foo, bar;
	// Create new person rumple with the given data
	PersonData rumple = { 1.75, 77, 'F' };

	// Assign data to foo
	foo.height = 1.75;
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
