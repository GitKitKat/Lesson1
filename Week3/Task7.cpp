#include <iostream>

using namespace std;

void diamond(int max, int dInc, int dCheck, bool rCheck);

int main() {

	int dirCheck = 0;
	int diamondP = 0;
	bool rowsCheck = false;
	int userInput;
	cout << "Please enter an integer: ";
	cin >> userInput;

	if (userInput % 2 == 0) {
		diamondP = 0;
		dirCheck = 0;
	}
	else {
		diamondP = 1;
		dirCheck = 1;
	}

	diamond(userInput,diamondP,dirCheck,rowsCheck);
	return 1;
}

void diamond(int max, int dInc, int dCheck, bool rCheck) {

	if (dCheck <= max && rCheck == false) {
		if (dInc < dCheck) {
			cout << "*";
			dInc += 1;
			diamond(max, dInc, dCheck, rCheck);
		} if (dInc == dCheck) {
			cout << "*" << endl;
			dInc = 1;
			dCheck += 2;
			//diamond(max, dInc, dCheck, rCheck);
		}	
		diamond(max, dInc, dCheck, rCheck);
	}

	if (dCheck == max + 2) {
		rCheck = true;
		dCheck = max;
		dInc = 1;
		//diamond(max, dInc, dCheck, rCheck);
	}
}