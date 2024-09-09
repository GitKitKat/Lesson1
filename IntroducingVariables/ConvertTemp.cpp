#include <iostream>
#include <string> 

using namespace std;

static int conTemp() 
{
	// prompts the user for a temperature in celsius
	cout << "Please enter a temperature in celsius: ";

	// gets and sets the temperature in celsius
	float tempCel;
	cin >> tempCel;

	// converts the temperature from celsius to fahrenheit
	float tempFah = (tempCel * 9.0f) / 5.0f + 32;

	// returns the converted value to the user
	string userCel;
	string userFah;
	if (tempCel == 1) {
		userCel = " degree celsius is ";
	}
	else {
		userCel = " degrees celsius is ";
	}
	if (tempFah == 1) {
		userFah = " degree fahrenheit.";
	}
	else {
		userFah = " degrees fahrenheit.";
	}
	cout << tempCel << userCel << tempFah << userFah << endl;

	return 1;
}