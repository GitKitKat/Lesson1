#include <iostream>

using namespace std;

static int compMax() 
{

	int userNum1;
	int userNum2;
	int userNum3;
	int userNum4;
	int userNum5;
	int numLarge;
	int numSmall;

	cout << "Please enter an integer: ";
	cin >> userNum1;
	cout << "Please enter a second integer: ";
	cin >> userNum2;
	cout << "Please enter a third integer: ";
	cin >> userNum3;
	cout << "Please enter a fourth integer: ";
	cin >> userNum4;
	cout << "Please enter a fifth integer: ";
	cin >> userNum5;

	if (userNum1 < 0 || userNum2 < 0 || userNum3 < 0 || userNum4 < 0 || userNum5 < 0) {
		cout << "There is an invalid input." << endl;
		return 1;
	}

	numLarge = userNum1;
	numSmall = userNum1;
	
	if (userNum2 >= numLarge) {
		numLarge = userNum2;
	}
	else {
		numSmall = userNum2;
	}

	if (userNum3 >= numLarge) {
		numLarge = userNum3;
	}
	if (userNum3 <= numSmall) {
		numSmall = userNum3;
	}

	if (userNum4 >= numLarge) {
		numLarge = userNum4;
	}
	if (userNum4 <= numSmall) {
		numSmall = userNum4;
	}

	if (userNum5 >= numLarge) {
		numLarge = userNum5;
	}
	if (userNum5 <= numSmall) {
		numSmall = userNum5;
	}


	cout << "The largest number is: " << numLarge << endl;
	cout << "The smallest number is: " << numSmall << endl;

	if (userNum1 == userNum2
		|| userNum1 == userNum3
		|| userNum1 == userNum4
		|| userNum1 == userNum5
		|| userNum2 == userNum3
		|| userNum2 == userNum4
		|| userNum2 == userNum5
		|| userNum3 == userNum4
		|| userNum3 == userNum5
		|| userNum4 == userNum5) {
		cout << "There are duplicate integers." << endl;
	}
	else {
		cout << "There are no duplicate integers." << endl;
	}

	return 1;
}