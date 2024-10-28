#include <iostream>
#include <time.h>

using namespace std;

bool userGuess(int a, int b, bool c, int arr[], int rD);

int compGuess() {

	int guessCheck = 1;
	int userInput;
	bool numGuessed = false;
	int numsIn[2] = {};

	srand(time(nullptr));
	int RandomNumber = rand() % 10 + 1;

	cout << "A number between 1 and 10 has been generated. You have three chances to guess it." << endl;

	cout << "Please enter a guess: ";
	cin >> userInput;
	numGuessed = userGuess(userInput, guessCheck, numGuessed, numsIn, RandomNumber);
	numsIn[0] = userInput;
	guessCheck += 1;

	if (!numGuessed) {
		cout << "Please enter a guess: ";
		cin >> userInput;
		numGuessed = userGuess(userInput, guessCheck, numGuessed, numsIn, RandomNumber);
		numsIn[1] = userInput;
		guessCheck += 1;
	}

	if (!numGuessed) {
		cout << "Please enter a guess: ";
		cin >> userInput;
		numGuessed = userGuess(userInput, guessCheck, numGuessed, numsIn, RandomNumber);
		if (!numGuessed) {
			cout << "The number was " << RandomNumber << "." << endl;
		}
	}
	return 1;
}

bool userGuess(int a, int b, bool c, int arr[], int rD) {

	if (a == rD) {
		cout << "You guessed it!" << endl;
		return true;
	}
	else if (a == arr[0] && b == 2) {
		cout << "Are you serious? You guessed that already. Pay attention!" << endl;
		return false;
	}
	else if (a == arr[1] && b == 3) {
		cout << "Oh wow, you guessed that again. Did you think it would magically be right this time?" << endl;
		return false;
	}

	else {
		cout << "That is incorrect." << endl;
		return false;
	}
}