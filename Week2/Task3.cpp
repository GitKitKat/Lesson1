#include <iostream>

using namespace std;

static int compPrimes() 
{

	int userNum;
	cout << "Please enter a number between 1 and 10: ";
	cin >> userNum;

	if (!(userNum > 0 && userNum <= 10)) {
		cout << "The number entered is invalid." << endl;
		return 1;
	}
	
	if ((userNum != 1) 
		|| (userNum % 5 == 0 && userNum != 5)
		|| (userNum % 3 == 0 && userNum != 3)
		|| (userNum % 2 == 0 && userNum != 2))
	{
		cout << "The number is not prime." << endl;
	}
	else {
		cout << "The number is prime." << endl;
	}

	return 1;
}