#include <iostream>
#include <cmath>
#include <sstream>
#include <string> // splitString function from GeeksforGeeks, "How to Split a String into an Array in C++?"

using namespace std;

// & denotes a reference
static void splitString(string& input, char delimiter, string arr[], int& index)
{
	// parse and convert the string to array
	istringstream stream(input);

	string token; // temp, stores tokens as they come

	// reads tokens as separated by the delimiter from the string stream
	while (getline(stream, token, delimiter)) {
		arr[index++] = token;
	}
}

static int calcDistance()
{
	// prompt user for four points
	float pointX = 0.0f;
	float pointY = 0.0f;
	float pointA = 0.0f;
	float pointB = 0.0f;
	string posA;
	string posB;
	string bothPos; // input string
	char delimiter = ',';
	string allPoints[4];
	int index = 0;

	cout << "Enter two numbers to create a position in space (x,y): ";
	cin >> posA;
	cout << "Enter two numbers to create a second position in space (a,b): ";
	cin >> posB;
	bothPos = posA + "," + posB;

	// call the function to convert input to string to array to float
	splitString(bothPos, delimiter, allPoints, index);

	// convert the strings to float and assigns
	pointX = stof(allPoints[0]);
	pointY = stof(allPoints[1]);
	pointA = stof(allPoints[2]);
	pointB = stof(allPoints[3]);

	// calculate the distance and return to user
	float distance = sqrt(pow((pointA - pointX), 2.0f) + pow((pointB - pointY),2.0f));
	cout << "The shortest distance between the two positions is " << distance << "." << endl;

	return 1;
}