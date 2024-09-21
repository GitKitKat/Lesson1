#include <iostream>

using namespace std;

static int compGrade() {

	int userGrade;
	cout << "Please enter the grade scored: ";
	cin >> userGrade;

	if (userGrade < 0 || userGrade > 100) {
		cout << "That score is invalid." << endl;
	}
	else {
		if (userGrade >= 80) {
			cout << "You received an A*." << endl;
		}
		else if (userGrade >= 70) {
			cout << "You received an A." << endl;
		}
		else if (userGrade >= 60) {
			cout << "You received a B." << endl;
		}
		else if (userGrade >= 50) {
			cout << "You received a C." << endl;
		}
		else if (userGrade >= 40) {
			cout << "You received a D." << endl;
		}
		else if (userGrade >= 1) {
			cout << "You received an F." << endl;
		}
		else {
			cout << "You received a U." << endl;
		}
	}

	return 1;
}