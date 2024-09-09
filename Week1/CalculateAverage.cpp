#include <iostream>
#include <sstream>
#include <string>

using namespace std;

static int calcAverage()
{

	string numbers;
	float numAverage = 0.0f;

	// prompts the user for five numbers
	cout << "Please enter five real numbers, seperated by commas (ie. 1.4,2,0.3): ";
	cin >> numbers;

	char delimiter = ',';
	int index = 0;
	string numStr[5];

	istringstream stream(numbers);

	string token;

	while (getline(stream, token, delimiter)) {
		numStr[index++] = token;
	}

	for (int i = 0; i < 5; i++) {
		numAverage += stof(numStr[i]);
	}

	numAverage /= 5;

	cout << fixed;
	cout.precision(2);

	cout << "The average of those numbers is " << numAverage << ".";

	return 1;
}