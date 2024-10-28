#include <iostream>
#include <sstream>
#include <list>

using namespace std;

void outList(list<int> myList);

int listsTask() {

	list<int> myNumbers = {};
	string userInput;
	int index = 0;
	int middle;
	char delimiter = ',';
	string token;

	// collect numbers for the list
	cout << "Please enter a list of numbers, separated by commas: ";
	cin >> userInput;

	istringstream stream(userInput);

	while (getline(stream, token, delimiter)) {
		myNumbers.push_back(stoi(token));
	}

	outList(myNumbers);

	// add a number to the front and back of the list
	cout << "Please enter two numbers, separated by a comma: ";
	cin >> userInput;

	istringstream secondStream(userInput);
	list<int>::iterator it = myNumbers.begin();

	while (getline(secondStream, token, delimiter)) {

		if (index == 0) {
			myNumbers.insert(it, 1, stoi(token));
			index++;

		}
		else if (index == 1) {
			it = myNumbers.end();
			myNumbers.insert(it, 1, stoi(token));

		}

	}

	outList(myNumbers);

	// remove a number in the middle of the list
	middle = int(myNumbers.size() / 2);
	it = myNumbers.begin();
	advance(it, middle);
	myNumbers.erase(it);
	outList(myNumbers);

	return 0;
}

void outList(list<int> myList) {

	cout << "Your list is: ";
	for (int i : myList) {

		cout << i << " ";

	}
	cout << endl;

}