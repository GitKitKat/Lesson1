#include <iostream>

using namespace std;

int checkArrNums() {

	int userNum[5];

	for (int i = 0; i < 5; i++) {

		cout << "Please enter a value for index " << i << ": ";
		cin >> userNum[i];

	}

	cout << "\nYou entered the following values: " << endl;

	for (int i = 0; i < 5; i++) {

		cout << "userNum[" << i << "] = " << userNum[i] << endl;

	}

	return 0;
}