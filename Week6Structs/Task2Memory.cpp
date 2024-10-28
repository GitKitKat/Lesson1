#include <iostream>
#include <sstream>

using namespace std;

void updateArray(int myArray[]);
void logArray(int myArray[]);

int task2() {

	int myStackArray[5] = {}; 
	int* myHeapArray = new int[5];

	updateArray(myStackArray);
	updateArray(myHeapArray);

	cout << "\nThe values of the stack array are: ";
	logArray(myStackArray); 
	cout << "and its memory address is: " << &myStackArray << endl;

	cout << "The values of the heap array are: ";
	logArray(myHeapArray);
	cout << "and its memory address is: " << &myHeapArray << endl;

	delete(myHeapArray);
	myHeapArray = nullptr;

	if (myHeapArray) {} 
	else {
		cout << "\nMemory deallocation successful." << endl;
	}

	return 0;
}

void updateArray(int myArray[]) {
	int index = 0;
	string token;
	string userInput;
	char delimiter = ',';
	
	cout << "Please enter five integers for an array, separated by commas: ";
	cin >> userInput;

	istringstream stream(userInput);
	while (getline(stream, token, delimiter)) {
		myArray[index] = stoi(token);
		index++;
	}
}

void logArray(int myArray[]) {

	for (int i = 0; i < 5; i++) {
		cout << myArray[i] << " ";

	}

}