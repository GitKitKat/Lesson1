#include <iostream>

using namespace std;

enum Operations {
	ADD = 1,
	SUBTRACT,
	MULTIPLY,
	DIVIDE
};

int userCalculator();
int zeroCheck(float arr[]);

int userCalculator() {
	float* userNum = new float[2];
	zeroCheck(userNum);
	int userInput;

	cout << "There are four mathematical operations to choose from."
		<< "\n1. add"
		<< "\n2. subtract"
		<< "\n3. multiply"
		<< "\n4. divide: "
		<< "Choose an operation by number: ";

	cin >> userInput;
	switch (userInput) {

	case 1:
		cout << userNum[0] << " plus " << userNum[1] << " is " << userNum[0] + userNum[1] << endl;
		break;
	case 2: 
		cout << userNum[0] << " minus " << userNum[1] << " is " << userNum[0] - userNum[1] << endl;
		break;
	case 3:
		cout << userNum[0] << " times " << userNum[1] << " is " << userNum[0] * userNum[1] << endl;
		break;
	case 4:
		cout << userNum[0] << " divided by " << userNum[1] << " is " << userNum[0] / userNum[1] << endl;
		break;
	default:
		cout << " Sorry, but that isn't an option." << endl;
	}

	delete(userNum);
	userNum = nullptr;
	return 0;
}

int zeroCheck(float arr[]) {
	
	cout << "Please enter two numbers to be used in the operation: " << endl;

	for (int i = 0; i < 2; i++) {

		cin >> arr[i];

	}

	if (arr[0] == 0 || arr[1] == 0) {
		cout << "One of those numbers is zero. Please enter a different number." << endl;
		zeroCheck(arr);
	}

	return 0;
}