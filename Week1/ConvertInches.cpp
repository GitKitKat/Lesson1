#include <iostream>

using namespace std;

static int conInch() 
{
	// prompt user for an amount in inches
	cout << "Please enter a measurement in inches (in): ";

	// gets and sets the inputted measurement in in
	float userIn;
	cin >> userIn;

	// prompts user for the conversion type (meters or feet)
	cout << "Do you want make a conversion to meters (m) or feet (ft)?: ";
	string userChoice;
	cin >> userChoice;

	cout << fixed;
	cout.precision(2);

	if (userChoice == "m" || userChoice == "M") {
		// converts the measurement from inches to meters
		float conMeters = userIn * 0.0254f;
		string userMeters;
		if (conMeters == 1) {
			userMeters = " meter.";
		}
		else {
			userMeters = " meters.";
		}

		// returns the converted measurement (m) to the user
		cout << userIn << "in is " << conMeters << userMeters << endl;
	}
	else if (userChoice == "ft" || userChoice == "Ft" || userChoice == "FT") {
		// converts the measurement from inches to feet
		float conFeet = userIn / 12.0f;
		string userFeet;
		if (conFeet == 1) {
			userFeet = " foot.";
		}
		else {
			userFeet = " feet.";
		}

		// returns the converted measurement (ft) to the user
		cout << userIn << " in is " << conFeet << userFeet << endl;
	}

	return 1;
}