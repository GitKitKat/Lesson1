#include <iostream>
#include <fstream>
#include <string>

#include "Stats.h"
#include "House.h"
//#include "Island.h"

void clearConsole();
std::string startingChoice();
void playAdventure(std::string txtFilename);

int main() {

	std::string userChoice;
	House * houseAdventure = new House();

	playAdventure(startingChoice());


	return 0;
}

void clearConsole() {
#ifdef _WIN32
	system("CLS");
#else
	system"clear");
#endif
}

std::string startingChoice() {

	int userInput = 1;

	std::cout << "Available text adventures: "
		"\n1. Retrieve an item from a Haunted House. "
		"\n2. Survive a week on a Deserted Island."
		"\n\nWhich adventure will you pick?: ";
	std::cin >> userInput;

	if (userInput == 1) {
		return "HauntedHouse.txt";

	} else if (userInput == 2) {
		return "";

	}
	else {
		clearConsole();
		std::cout << "That was not one of the available text adventures." << std::endl;
		startingChoice();
	}

}

void playAdventure(std::string txtFilename) {
	
	clearConsole();

	std::string newLine;
	char linePtr = '[ID=';
	std::ifstream inFile(txtFilename);

	if (!inFile.is_open()) {
		std::cout << "The text adventure, " << txtFilename << ", couldn't be opened." << std::endl;
	}
	else {
		// this loop pulls a line from the related text file
		while (std::getline(inFile,newLine)) {
			
			std::cout << newLine << std::endl;
		
		}



		inFile.close();
	}

}