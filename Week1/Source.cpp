#include <iostream>

#include "AgeInDays.cpp"
#include "PointDistance.cpp"
#include "ConvertInches.cpp"
#include "CalculateAverage.cpp"
#include "CalculateTotalCost.cpp"

using namespace std;

static bool welcomeMSG()
{
	// to run or not to run Week1
	cout << " Welcome to Week 1 of CG Spectrum's Programming Course.\n Do you want to run a program? (Y/N): ";
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
	// choosing a program within Week1
	cout << "\n There are five programs available:\n	1. AgeInDays.cpp : Converts a user's age from years to days.\n	2. PointDistance.cpp : Calculates the distance between two points.\n	3. ConvertInches.cpp : Converts a measurement in inches to meters or feet.\n	4. CalculateAverage.cpp : Calculates the average of five numbers inputted by the user.\n	5. CalculateTotalCost.cpp : Calculates the total cost of several items, including a 5% tax." << endl;
	cout << "\n Which of these do you want to run? (ie: 1): ";
	int choiceUser;
	cin >> choiceUser;

	return choiceUser;
}

static void repeatMSG()
{

	int programChoice = choiceMSG();
	int programRun;
	string arrayChoice[] = { "AgeInDays","PointDistance","ConvertInches","CalculateAverage","CalculateTotalCost" };

	cout << "\n"; // /n will move the print cursor to a new line, anything in the same std::cout line as the \n will be printed on this line, anything following will be on a new line
	if (programChoice > 0 && programChoice < 6) {
		cout << "\n";

		if (programChoice == 1) {
			programRun = uDAge(); // run AgeInDays.cpp
		}
		else if (programChoice == 2) {
			programRun = calcDistance(); // run PointDistance.cpp
		}
		else if (programChoice == 3) {
			programRun = conInch(); // run ConvertInches.cpp
		}
		else if (programChoice == 4) {
			programRun = calcAverage(); // run CalculateAverage.cpp
		}
		else if (programChoice == 5) {
			programRun = calcTCost(); // run CalculateTotalCost.cpp
		}

		if (programRun > 0) {
			cout << "\n	" << arrayChoice[programChoice - 1] << ".cpp run complete." << endl;
		}
	}

	else {
		cout << " Sorry, but that isn't an option." << endl;
	}
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
				cout << "\n . \n\n . \n\n ." << endl;
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