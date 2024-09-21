#include <iostream>

using namespace std;

static int compNumState() 
{

	int userNumber;
	cout << "Please enter a whole number: ";
	cin >> userNumber;

	if (userNumber == 0) {
		cout << "The number is zero, which is considered even." << endl;
	}

	if (userNumber < 0) {
		if (userNumber % 2 == 0) {
			cout << "The number is negative and even." << endl;
		}
		else {
			cout << "The number is negative and odd." << endl;
		}
	}

	if (userNumber > 0) {
		if (userNumber % 2 == 0) {
			cout << "The number is positive and even." << endl;
		}
		else {
			cout << "The number is positive and odd." << endl;
		}
	}
	return 1;
}