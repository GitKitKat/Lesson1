#include <iostream>
#include <sstream>
#include <deque>

using namespace std;

void nameRemove(deque<string> &myDeque);

int dequeTask() {

	deque<string> myQueue;
	string userInput;
	char delimiter = ',';
	string token;

	cout << "Please enter names at the front of the queue, separated by commas: ";
	cin >> userInput;

	istringstream stream(userInput);

	while (getline(stream, token, delimiter)) {
		myQueue.push_front(token);

	}


	cout << "Please enter names at the back of the queue, separated by commas: ";
	cin >> userInput;

	istringstream secondStream(userInput);

	while (getline(secondStream, token, delimiter)) {
		myQueue.push_back(token);

	}

	cout << "Your current queue: ";
	for (string i : myQueue) {
		cout << i << " ";
	}
	cout << endl;

	nameRemove(myQueue);
	cout << "Your popped queue: ";
	for (string i : myQueue) {
		cout << i << " ";
	}

	return 0;
}

void nameRemove(deque<string> &myDeque) {

	myDeque.pop_front();
	myDeque.pop_back();

}