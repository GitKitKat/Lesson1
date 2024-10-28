#include <iostream>
#include <vector>

using namespace std;

void addNumbers(vector<int>& vector);
void removEvens(vector<int>& vector);

int vectorTask() {

	vector<int> myNumbers = { 1,2,3,4,5,6,7,8,9,10 };
	cout << "Initial values of myNumbers: ";
	for (int i : myNumbers) {

		cout << i << " ";

	}
	cout << endl;
	addNumbers(myNumbers);
	removEvens(myNumbers);

	return 0;
}

void addNumbers(vector<int>& vector) {

	for (int i = 0; i < 20; i++) {
	
		vector.push_back(i + 11);
		cout << "Capacity of myNumbers: " << vector.capacity() << ", size of myNumbers: " << vector.size() << endl;

	}

}

void removEvens(vector<int>& vector) {

	for (int i = 0; i < vector.size(); i++) {

		if (vector[i] % 2 == 0) {

			vector.erase(vector.begin() + i);

		} // check if any numbers are skipped

	}

	cout << "Final values of myNumbers: ";
	for (int i : vector) {

		cout << i << " ";

	}
	cout << "\nFinal capacity: " << vector.capacity() << ", final size: " << vector.size() << endl;

}