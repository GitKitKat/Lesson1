#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int iteratorsTask() {

	string userInput;
	vector<string> myWords = {};
	char delimiter = ',';
	string token;

	cout << "Please enter a list of words, separated by commas: ";
	cin >> userInput;

	istringstream stream(userInput);

	while (getline(stream, token, delimiter)) {
		myWords.push_back(token);
	}

	for (string i : myWords) {	// auto& creates a local reference
		for (auto& j : i) {
			j = toupper(j);
			cout << j;

		}
		cout << " ";
	}

	cout << endl;

	reverse(myWords.begin(), myWords.end());
	for (string i : myWords) {
		cout << i << " ";
	}

	return 0;
}