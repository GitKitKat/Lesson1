#include <iostream>
#include <fstream>

using namespace std;
#define alphabet_size 26 
// length of the alphabet to be read in alphabet.txt

int charChange() {
	
	char upperChars[alphabet_size] = {};
	//A: 65; a: 97; ASCII; lowercase - 32 = uppercase

	ifstream inFile("alphabet.txt");	// inFile here is a variable, can be called anything (eg. cheese)
	ofstream outFile("upperAlphabet.txt");
	char lowerChar;
	int infCount = 0;

	if (!inFile.is_open()) {

		cout << "The text file, 'alphabet.txt', couldn't be opened." << endl;
		return 0;

	}
	else {

		while (inFile >> lowerChar) {

			upperChars[infCount] = int(lowerChar) - 32; // uperChars[infCount] = toupper(lowerChar);
			infCount++;

		}

		// when the # of lines to be read is known, the above can be written as:
		// for (int i = 0; i < alphabet_size; i++) {
		//		upperChars[i] = int(inFile) - 32;
		// }

		inFile.close();
		cout << "The text file, 'alphabet.txt', was read successfully." << endl;
	}

	if (!outFile) {

		cout << "The text file, 'upperAlphabet.txt', couldn't be opened." << endl;
		return 0;

	}
	else {

		for (int i = 0; i < alphabet_size; i++) {

			outFile << upperChars[i] << endl;

		}
		outFile.close();
		cout << "The text file, 'upperAlphabet.txt', was edited successfully." << endl;
	}

	return 0;
}