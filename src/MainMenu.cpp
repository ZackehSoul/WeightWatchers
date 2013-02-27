#include "WeightWatchers.h"

int main() {
	WeightWatchers * pMain = new WeightWatchers();
	int selection;
	while(pMain->exitStatus != "exit"){
		system("CLS");
		cout << "Welcome to the Healthy Club Command System." << endl;
		cout << "Please type the number of the feature you wish to use:\n" << endl;
		cout << "1. Calculate your body statistics\n" << endl;
		cout << "Your selection: "; cin >> selection;

		validateSelection:
		if(selection == 1){
			system("CLS");
			pMain->calculateStatistics();
		} else {
			cout << "Please make a valid selection: ";
			cin.clear(); while (cin.get() != '\n') ;
			cin >> selection;
			goto validateSelection;
		}
	}
	delete pMain;
}