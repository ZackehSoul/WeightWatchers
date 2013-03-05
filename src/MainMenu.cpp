#include "WeightWatchers.h"
//--- Testing ---//
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
	int selection; int i = 0;
	// Create a loop which is ended by the user
	while(pMain->getExitStatus() != "exit"){
		// Clear the screen and display opening information
		pMain->clearScreen();
		cout << "Welcome to the Healthy Club Command System." << endl;
		cout << "Please type the number of the feature you wish to use:\n" << endl;
		cout << "1. Calculate your body statistics" << endl;
		cout << "2. Start the Client Server simulation\n" << endl;
		cout << "Your selection: "; cin >> selection;

		// Validates that the user has made a valid selection
		validateSelection:
		if(selection == 1){
			// Clear the screen and continue to generate statistics
			pMain->clearScreen();
			pMain->calculateStatistics();
		} else if (selection == 2){
			// Clear the screen and initialize the simulation
			pMain->clearScreen();
			pMain->runSimulation();
		} else if (selection == 0000){
			//--- Test function ---//
			int trainerNo;
			// Asks for the number of trainers
			cout << "Please enter an amount of trainers: "; cin >> trainerNo;
			// Creates that amount of trainer objects
			Trainer trainers[trainerNo];
			LinkedList pList;
			for(int i = 0; i < trainerNo; i++){
				// Give all trainers an ID number
				trainers[i].setTrainerID(i + 1);
				// Add them to the linked list
				pList.addTrainerElement(&trainers[i]);
			}
			// Check if they added to the list correctly
			cout << pList.listElements() << endl;
			int busyNess;
			// Make some of them busy
			cout << "Please enter the amount you want to make busy: "; cin >> busyNess;
			for(int i = 0; i < busyNess; i++){
				// Remove the busy trainers from the list
				pList.removeTrainerElement();
			}
			// Check they removed correctly
			cout << pList.listElements();
			Sleep(10000);
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
