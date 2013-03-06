#include "WeightWatchers.h"
//--- Testing ---//
#include <fstream>
#include "LinkedList.h"
#include "Trainer.h"
#include <windows.h>
//--- Testing ---//

/**
 * Main method for the Healthy Club system. Provides a menu to the user to decide
 * what they wish to do and allows them to enter their information. Makes calls
 * to different classes depending on what the user chooses.
 *
 * @author Isaac Whitfield
 * @version 28/02/2013
 */
int main() {
	WeightWatchers * pMain = new WeightWatchers();
	// Set the variables needed by the menu
	int selection; int i = 0; string firstName, lastName, gender;
	// Create a loop which is ended by the user
	while(pMain->getExitStatus() != "exit"){
		// Clear the screen and display opening information
		pMain->clearScreen();
		cout << "Welcome to the Healthy Club Command System.\n" << endl;
		cout << "Please type in your first name: "; cin >> firstName;
		cout << "Please type in your last name: "; cin >> lastName;
		cout << "Please type in your gender: "; cin >> gender;

		pMain->clearScreen();
		ifstream memberFile("resources/" + firstName + " " + lastName + ".txt");
		ofstream members;
		if(memberFile){
			cout << "Welcome back, " << firstName << "." << endl;
		} else {
			ofstream createFile("resources/" + firstName + " " + lastName + ".txt");
			members.open("members.txt", ios_base::app);
			members << firstName << " " << lastName << endl;
			members.close();
			cout << "Welcome to the club, " << firstName << "." << endl;
		}
		cout << "Please type the number of the feature you wish to use:\n" << endl;
		cout << "1. Start the Client Server simulation" << endl;
		cout << "2. Calculate your body statistics\n" << endl;
		cout << "Your selection: "; cin >> selection;

		// Validates that the user has made a valid selection
		validateSelection:
		if(selection == 1){
			// Clear the screen and initialize the simulation
			pMain->clearScreen();
			pMain->runSimulation();
		} else if (selection == 2){
			// Clear the screen and continue to generate statistics
			pMain->clearScreen();
			pMain->calculateStatistics(firstName + " " + lastName, gender);
		} else if (selection == 0000){
			//--- Test function ---//
			vector<string> lines;
			ifstream myfile("members.txt");
			if(myfile.is_open()){
				string line;
				while(getline(myfile, line))
				{
					lines.push_back(line);
				}
			}
			for(unsigned int i = 0; i < lines.size(); i++){
				cout << lines.at(i) << endl;
			}
			cout << lines.size();
			Sleep(60000);
			//--- Test function ---//
		} else {
			// Show the error and ask for a valid selection
			if (i == 0) cout << endl, i++;
			cout << "Please make a valid selection: ";
			cin.clear(); while (cin.get() != '\n');
			cin >> selection;
			goto validateSelection;
		}
	}
	delete pMain;
}
