#include <iostream>

using namespace std;


static int compRange()
{

	int number;
	cout << "Please enter a number between 1 and 10: ";
	cin >> number;

	if (number < 1 || number > 10) {
		cout << "The number is invalid." << endl;
		return 1;
	}

	if (number > 5) {
		cout << "The number is greater than 5." << endl;
	}
	else if (number < 5) {
		cout << "The number is less than 5" << endl;
	}
	else {
		cout << "The number is equal to 5." << endl;
	}

	return 1;
}