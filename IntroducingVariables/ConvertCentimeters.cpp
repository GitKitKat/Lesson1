#include <iostream>
#include <string> 

using namespace std;

static int conCenti()
{
	// prompts the user for a distance in centimeters
	cout << "Please enter a measurement in centimeters (cm): ";

	// gets and sets the inputted measurement in cm
	int userCm;
	cin >> userCm;

	// converts the measurement from cm to feet
	float conTotal = userCm / 30.48f;
	int conFeet = (int)conTotal;

	// calculates the remainer as inches
	int conInches = (int)((conTotal - conFeet) * 12);

	// returns the converted measurement to the user
	string userFeet;
	string userInches;
	if (conInches == 1) {
		userInches = " inch.";
	}
	else {
		userInches = " inches.";
	}
	if (conFeet == 1) {
		userFeet = " foot and ";
	}
	else {
		userFeet = " feet and ";
	}
	cout << userCm << "cm is " << conFeet << userFeet << conInches << userInches << endl;

	return 1;
}