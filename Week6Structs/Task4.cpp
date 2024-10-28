#include <iostream>

using namespace std;

struct Cars {

	string make;
	string model;
	int year;

};

int main() {

	int carList = 0;
	Cars* userCar = new Cars;

	cout << "How many cars do you want to make a list of?: ";
	cin >> carList;
	cout << "Please enter the following information for a car. " << endl;
	carPrompt(carList, *userCar);

	return 0;
}

void carPrompt(int num, Cars carinfo) {
	string promptArr[3] = { "Make: ","Model: ","Year: " };
	string userMake[num];
	string userModel[num];
	int userYear[num];

	for (int i = 0; i < num; i++) {
		for (int j = 0; j < 3; j++) {
			cout << promptArr[i];
			if (j == 0) {
				cin >> userMake[i];
			}
			else if (j == 1) {
				cin >> userModel[i];
			}
			else if (j == 2) {
				cin >> userYear[i];
			}
		}
	}

}