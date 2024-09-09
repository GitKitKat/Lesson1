#include <iostream>
#include <string> // include the string file to use the string type (not necessary if you include the namespace)

using namespace std; // any keywords related to std can be written without the std:: prefix (ie: std::cout -> cout)
// related keywords used: string, cout, cin, endl

static int vars()
{
	// dataType of variables is declared
	int age;
	float weight; // typically precice until the 7th decimal
	double distance; // typically precice until the 15th decimal, takes up 2x more data
	bool isAlive; // capitalizing the second word is a protocol
	char initial;
	string name; // string type is in the standard namespace std

	string job = "Trivia";

	unsigned short int betterAge; // unsigned makes the lower limit 0; short puts a small limit on the scale of the variable
	long double hugeDistance;

	betterAge = 4900;
	hugeDistance = 403707;

	age = 30;
	weight = 190.5f; // f denotes this as a float instead of a double
	distance = 1212.987; // default for decimals
	isAlive = true;
	initial = 'F';
	name = "Fineas";

	// profile output
	cout << "Name: " << name << endl; // endl ends the line, following prints will start on a new line
	cout << "Age: " << age << endl;
	if (isAlive == true) {
		cout << "State: " << "Alive" << endl;
	}
	else {
		cout << "State: " << "Dead" << endl;
	}
	cout << "Hobby: " << job << endl;

	cout << "\n" << "The oldest tree in the world was " << betterAge / 1000 << "." << betterAge - 4000 << " years old." << endl;
	cout << "Our moon is currently " << hugeDistance/1000 << " kilometers away." << endl;

	return 1;
}