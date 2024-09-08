#include <iostream>

#include "VariableMath.cpp"
#include "VariableVariety.cpp"
#include "UserAge.cpp"
#include "ConvertTemp.cpp"
#include "ConvertMeasure.cpp"

using namespace std;

static bool welcomeMSG()
{
	// to run or not to run the IntroducingVariables package
	cout << " Welcome to Week 0 of CG Spectrum's Programming Course.\n Do you want to run a program? (Y/N): ";
	char welcUser;
	cin >> welcUser;

	if (welcUser == 'Y' || welcUser == 'y') {
		return true;
	}
	else {
		cout << " Goodbye." << endl;
		return false;
	}
}

static int choiceMSG()
{
	// choosing a program within IntroducingVariables
	cout << "\n There are five programs available:\n	1. VariableMath.cpp : Runs a few mathematical operations.\n	2. VariableVariety.cpp : Runs operations centered around a variety of variable types.\n	3. UserAge.cpp : Runs an operation to determine the user's current age.\n	4. ConvertTemp.cpp : Runs an operation to convert a temperature from celsius to fahrenheit.\n	5. ConvertMeasure.cpp : Runs an operation to convert a size from centimeters to feet and inches." << endl;
	cout << "\n Which of these do you want to run? (ie: 1): ";
	int choiceUser;
	cin >> choiceUser;

	return choiceUser;
}

static int repeatMSG()
{

	int programChoice = choiceMSG();

	cout << "\n";

	if (programChoice == 1) {
		cout << "\n";
		int runMath = math(); // run VariableMath.cpp	
		if (runMath == 1) {
			cout << "\n	VariableMath.cpp run complete." << endl; // /n will move the print cursor to a new line, anything in the same std::cout line as the \n will be printed on this line, anything following will be on a new line
		}
		else {
			cout << "\n VariableMath.cpp run unsuccessful." << endl;
		}
	}
	else if (programChoice == 2) {
		cout << "\n";
		int runVars = vars(); // run VariableVariety.cpp
		if (runVars == 1) {
			cout << "\n	VariableVariety.cpp run complete." << endl;
		}
		else {
			cout << "\n VariableVariety.cpp run unsuccessful." << endl;
		}
	}
	else if (programChoice == 3) {
		cout << "\n";
		int runAge = uAge(); // run UserAge.cpp
		if (runAge == 1) {
			cout << "\n	UserAge.cpp run complete." << endl;
		}
		else {
			cout << "\n UserAge.cpp run unsuccessful." << endl;
		}
	}
	else if (programChoice == 4) {
		cout << "\n";
		int runTemp = conTemp(); // run ConvertTemp.cpp
		if (runTemp == 1) {
			cout << "\n	ConvertTemp.cpp run complete." << endl;
		}
		else {
			cout << "\n ConvertTemp.cpp run unsuccessful." << endl;
		}
	}
	else if (programChoice == 5) {
		cout << "\n";
		int runMeasure = conMeasure(); // run ConvertMeasure.cpp
		if (runMeasure == 1) {
			cout << "\n	ConvertMeasure.cpp run complete." << endl;
		}
		else {
			cout << "\n ConvertMeasure.cpp run unsuccessful." << endl;
		}
	}
	else {
		cout << " Sorry, but that isn't an option." << endl;
	}

	return 0;
}

int main() {

	bool repeatCheck = true;

	bool welcome = welcomeMSG();
	if (welcome == true) {
		repeatMSG();

		// to run again or not to run again
		while (repeatCheck == true) {
			cout << " \n\n Do you want to run another program? (Y/N): ";
			char repUser;
			cin >> repUser;

			if (repUser == 'Y' || repUser == 'y') {
				repeatMSG();
			}
			else {
				cout << " Goodbye." << endl;
				break;
			}
		}
	}

	return 0;
}