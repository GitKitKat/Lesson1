// Includes: Standard header files
#include <iostream>
#include <fstream>
#include <string>

// Includes: Class header files
#include "SceneLoader.h"
#include "AdventureObject.h"
#include "HauntedHouseObject.h"
#include "DesertedIslandObject.h"

// Declarations

void clearConsole();
void playAdventure();

// This is the project's entry point.
int main() {

	// Prompts the user for a text adventure and loads it.
	playAdventure();

	return 0;
}

// This function removes all text on the console, returning the cursor to the start.
void clearConsole() {
#ifdef _WIN32
	system("CLS");
#else
	system"clear");
#endif
}

// This function executes most of the project's logic and handles user interactions.
void playAdventure() {

	// Variable declarations

	int userChoice = 0;
	std::string textFilename = "";
	std::vector<AdventureObject*> myAdventure;

	// Here, the user chooses which text adventure to run. 
	// Any numerical error (the user inputs a number not in the list) will cause the prompt to clear the console and repeat.
	do {

		std::cout << "From the available text adventures, enter your choice."
			<< "\n1. Retrieve an item from a Haunted House."
			<< "\n2. Survive a week on a Deserted Island." << std::endl;
		std::cin >> userChoice;
		
		// If there is no error, the loop will "break" after the user's input and the following lines will not be processed.
		clearConsole();
		std::cout << "That was not one of the available text adventures." << std::endl;

	} while (userChoice != 1 && userChoice != 2);

	// Here, the user's choice is passed on to the program, which performs based on the loaded text file.
	switch (userChoice) {
	case 1:
		// This setup enables overriding functions later in the code.
		myAdventure.push_back(new HauntedHouseObject());
		textFilename = myAdventure[0]->GetFile();
		break;
	case 2:
		myAdventure.push_back(new DesertedIslandObject());
		textFilename = myAdventure[0]->GetFile();
		break;
	}

	// Clears the console of the interactions before the text adventures start.
	clearConsole();



	int userInput = 0;
	std::string newLine = "";
	std::string lineID = "";
	std::string lineDescription = "";
	std::string lineChoice = "";
	std::string lineChoiceID = "";
	std::string lineChoiceDesc = "";
	std::ifstream inFile(textFilename);
	//SceneLoader currentScene;
	SceneLoader* scenePtr = nullptr;

	if (!inFile.is_open()) {
		std::cout << "The text adventure, " << textFilename << ", couldn't be opened." << std::endl;
		return;
	}
	else {
		// this loop reads and relays lines from the related adventure's text file
		while (std::getline(inFile, newLine)) {

			if (newLine == "[Scene]") {

				scenePtr = new SceneLoader;
				std::cout << "scene" << std::endl;

			}
			else if (newLine.rfind("(ID)",0) == 0) {

				lineID = newLine.substr(4);
				std::cout << "id" << std::endl;

			}
			else if (newLine.rfind("(Desc)", 0) == 0) {

				lineDescription = newLine.substr(6);
				if (scenePtr != nullptr) {

					std::cout << "desc" << std::endl;
					scenePtr->SetDescription(lineDescription);

				}

			} 
			else if (newLine.rfind("[EndScene]", 0) == 0) {

				scenePtr->AddToMap(lineID);
				myAdventure[0]->AddScene(*scenePtr);
				//delete scenePtr;
				//scenePtr->ClearScene();
				scenePtr = nullptr;
				lineID = "";
				std::cout << "end" << std::endl;

			}
			else if (newLine.rfind("(Choice)", 0) == 0) {

				lineChoice = newLine.substr(8);
				int IDpos = lineChoice.rfind("]", 0);
				lineChoiceDesc = lineChoice.substr(IDpos + 1);
				lineChoiceID = lineChoice.substr(0, IDpos);
				scenePtr->SetChoices(lineChoiceDesc, lineChoiceID);
				std::cout << "choice" << std::endl;

			}
			else if (newLine == "(Input)") {

				std::cin >> userInput;
				clearConsole();

			}
			/*else if (newLine == "(Exit)") {
					return;
					}*/
			

			if (scenePtr == nullptr) {

				myAdventure[0]->AccessDescription(lineID);
				std::cout << "print" << std::endl;

			}
		}

		inFile.close();
	}

	//delete currentScene;
	delete myAdventure[0];

}