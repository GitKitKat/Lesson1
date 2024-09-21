#include <iostream>

using namespace std;

static int compChars() 
{
	//A: 65; a: 97; ASCII
	char userInput;
	char convertInput;
	cout << "Please enter a single alphabet character: ";
	cin >> userInput;

	if (int(userInput) < 97) {
		convertInput = int(userInput) + 32;
	}
	else {
		convertInput = int(userInput) - 32;
	}

	cout << "Original character: " << userInput << ", Converted character: " << convertInput << endl;

	return 1;
}