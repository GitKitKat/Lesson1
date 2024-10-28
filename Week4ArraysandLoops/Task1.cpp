#include <iostream>

using namespace std;

int guessFive() {

	int guessCheck = 0;
	float userInput = 0;

	while (guessCheck < 10) {
		cout << "Please enter a number that is not 5: ";
		cin >> userInput;

		if (userInput == 5) {
			cout << "Hey, you weren't supposed to enter 5!" << endl;
			break;
		}

		guessCheck++;
	}

	if (guessCheck == 10) {
		cout << "Wow, you're more patient than I am, you win." << endl;
	}
	
	return 0;
}