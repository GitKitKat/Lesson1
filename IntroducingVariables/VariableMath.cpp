#include <iostream>

using namespace std;

static int math()
{
	//simple operators
	int a = 10;
	int b = 3;

	int x = 10;
	x = x + 20; // = 30

	int add = a + b; // = 13
	int subtract = 10 - b; // = 7
	int multiply = a * 3; // = 30
	int division = a / b; // = 3 (truncated from 3.333...)
	int mod = a % b; // = 1; returns the remainder between two ints (ie: 3 % 2 = 1; 4 % 2 = 0)

	float divTwo = 10 / 3.0f; // if neither number in the equation is a float, the result will be an int

	cout << "Float: " << divTwo << ", Int: " << 10 / 3 << endl;

	int result = 1 + (2 * 3) + 4; // = 11 (follows PEMDAS); including parenthesis is a protocol
	if (result == 11) {
		cout << "PEMDAS!" << endl;
	}


	// creates a variable to hold the number entered
	int numEntered = 0;

	// prints out a message to tell the user to enter a number
	cout << "\n" << "Pick a whole number between 1 and 10: "; // putting endl here will move userinput to a new line

	// stores the number the user enters in the "numEntered" variable
	cin >> numEntered;

	// adds 3 to the number entered, and prints out a new line
	int finalResult = numEntered + 3;
	cout << "That number plus three equals " << finalResult << "." << endl;


	// compound operators 
	x += 20; // = 50; often used in for loops (ie: i += 1;)
	x -= 10; // = 40
	x *= 10; // = 400
	x /= 10; // = 40
	x %= 10; // = 0


	// conversion
	float myFloat = 30.5f;
	int myInt = (int)myFloat; // without (int), the error "possible loss of data" will be called

	int c = 20;
	float d = (float)c;

	int resultTwo = (int)(2.4 + 1.6); // = 4; (int) here acts on the sum, and has less data loss than (int)2.4 + (int)1.6 (truncated 2 + 1)
	if (resultTwo == 4) {
		cout << "\n" << "No data lost!" << endl; 
	}

	return 1;
}


