#include <iostream>
#include <time.h>

using namespace std;

// function declarations (this allows them to use variables defined after them)
float functionA(int a, int b, float c);
bool functionB(float d);

int compUserFunct() {
	// Seed the Random Number Generator
	srand(time(nullptr));

	int userA;
	int userB;
	float userC;
	float userD;

	cout << "Please input an integer: ";
	cin >> userA;
	cout << "Please input a second integer: ";
	cin >> userB;
	cout << "Please input a float: ";
	cin >> userC;

	userD = functionA(userA, userB, userC);
	
	if (functionB(userD)) { // same as functionB(userD) == true
		cout << "true" << endl;
	}
	else {
		cout << "false" << endl;
	}
	return 1;
}

float functionA(int a, int b, float c) {

	return (a + b) * c;

}

// function definitions
bool functionB(float d) {
	// Get a random number between 1 and 10
	int RandomNumber = rand() % 10 + 1;

	cout << d << " " << RandomNumber;

	if (d < RandomNumber) {
		return true;
	}
	else {
		return false;
	}
}