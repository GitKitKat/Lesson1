#include <iostream>

using namespace std;

static int uDAge() 
{
	// prompt user for an age in years
	int inYears;
	cout << "Please enter your age in years: ";
	cin >> inYears;

	// calculate the conversion of years to days; include a calculation for possible leap years
	int cLeap;
	int inDays;
	string userDays;
	inDays = inYears * 365;
	cLeap = inYears / 4;
	if (inDays == 1) {
		userDays = " day old.";
	}
	else {
		userDays = " days old.";
	}

	// return age in days to user
	cout << "You are " << inDays + cLeap << userDays << endl;

	return 1;
}