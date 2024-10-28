#include <iostream>
#include <fstream>
#include <string>

#include "Stats.h"
#include "House.h"
//#include "Island.h"

void clearConsole();
std::string startingChoice();
void playAdventure();

int main() {

	std::string userChoice = startingChoice();
	std::ifstream inFile(userChoice);

	if (!inFile.is_open()) {
		std::cout << "The text adventure, " << userChoice << ", couldn't be opened." << std::endl;
		return 0;
	}
	else {

		playAdventure();




		inFile.close();
	}


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

	int userInput;

	std::cout << "Available text adventures: "
		"\n1. Retrieve an item from a Haunted House. "
		"\n2. Survive a week on a Deserted Island."
		"\nWhich adventure will you pick?: ";
	std::cin >> userInput;

	if (userInput == 1) {
		House* houseAdventure = new House();
		return "HauntedHouse.txt";
	}
	else if (userInput == 2) {
		//return "DesertedIsland.txt";
	}
	else {
		clearConsole();
		std::cout << "That was not one of the available text adventures." << std::endl;
		startingChoice();
	}

}

void playAdventure() {



}