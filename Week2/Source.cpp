#include <iostream>
#include "Task1.cpp"
#include "Task2.cpp"
#include "Task3.cpp"
#include "Task4.cpp"
#include "Task6.cpp"
#include "Task7.cpp"

using namespace std;

static bool welcomeMSG()
{
	// to run or not to run Week2
	cout << " Welcome to Week 2 of CG Spectrum's Programming Course.\n Do you want to run a program? (Y/N): ";
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
	// choosing a program within Week2
	cout << "\n There are six programs available:"
		<< "\n	1. Task1.cpp : Compares a number inputted by the user to the number 5."
		<< "\n	2. Task2.cpp : Returns the grade letter corresponding to a grade inputted by the user."
		<< "\n	3. Task3.cpp : Determines whether a number inputted by the user is prime."
		<< "\n	4. Task4.cpp : Determines whether a number inputted by the user is positive, negative, even or odd."
		<< "\n	5. Task6.cpp : Converts a character inputted by the user into the opposite (lower/uppercase) case."
		<< "\n	6. Task7.cpp : Finds the largest, smallest and duplicate numbers in a set inputted by the user." << endl;
	cout << "\n Which of these do you want to run? (ie: 1): ";
	int choiceUser;
	cin >> choiceUser;

	return choiceUser;
}

static void repeatMSG()
{

	int programChoice = choiceMSG();
	int programRun;
	string arrayChoice[] = { "Task1","Task2","Task3","Task4","Task6","Task7" };

	cout << "\n\n"; 

	switch (programChoice)
	{
	case 1:
	{
		programRun = compRange(); // run Task1.cpp
		break;
	}
	case 2:
	{
		programRun = compGrade(); // run Task2.cpp
		break;
	}
	case 3:
	{
		programRun = compPrimes(); // run Task3.cpp
		break;
	}
	case 4:
	{
		programRun = compNumState(); // run Task4.cpp
		break;
	}
	case 5:
	{
		programRun = compChars(); // run Task6.cpp
		break;
	}
	case 6:
	{
		programRun = compMax(); // run Task7.cpp
		break;
	}
	default:
	{
		cout << " Sorry, but that isn't an option." << endl;
	}
	}
	if (programRun > 0) {
		cout << "\n	" << arrayChoice[programChoice - 1] << ".cpp run complete." << endl;
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