#include <iostream>
#include <string> 

using namespace std;

static int uAge()
{
	// prompts the user for their name
	cout << "Please enter your name: ";

	// gets and sets the name
	string userName;
	cin >> userName;

	// prompts user for their year of birth
	cout << "What year were you born? (YYYY): ";

	// gets and sets the year of birth
	int yearOfBirth;
	cin >> yearOfBirth;

	// prompts user for the current year
	cout << "What year is it currently? (YYYY): ";

	// gets and sets the current year
	int currentYear;
	cin >> currentYear;

	// returns the formatted info to the user
	int resultAge = currentYear - yearOfBirth;
	string userYear;
	if (resultAge > 1) {
		userYear = " years old.";
	}
	else {
		userYear = " year old.";
	}
	cout << userName << ", you are now " << resultAge << userYear << endl;

	return 1;
}