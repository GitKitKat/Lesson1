// Includes: Standard header files
#include <iostream>
#include <fstream>
#include <string>

// Includes: Class header files
#include "SceneLoader.h"
#include "AdventureObject.h"
#include "HauntedHouseObject.h"
#include "DesertedIslandObject.h"

// Declaration

void playAdventure(int userInput);

// This is the project's entry point.
int main() {

	// This holds the user's adventure choice.
	int userInput = 0;

	// Here, the user chooses which text adventure to run. 
	// Any numerical error (the user inputs a number not in the list) will cause the prompt to clear the console and repeat.
	while (true) {

		std::cout << "From the available text adventures, enter your choice."
			<< "\n1. Retrieve an item from a Haunted House."
			<< "\n2. Survive a week on a Deserted Island." << std::endl;
		std::cin >> userInput;

		if (userInput == 1 || userInput == 2) {

			break;

		}

		// If there is no error, the following lines will not be processed.
		AdventureObject::clearConsole();
		std::cout << "That was not one of the available text adventures." << std::endl;

	}

	// Clears the console of any interactions before the text adventures start.
	AdventureObject::clearConsole();

	// Here, the chosen adventure is loaded.
	playAdventure(userInput);

	return 0;
}

// This function loads the chosen text adventure and splits its scenes into separate objects.
void playAdventure(int userInput) {

	// Variable declarations:
	// (only for variables that most of playAdventure's logic will need)

	std::string newLine = "";
	std::string lineID = "";
	std::string lineDescription = "";
	std::string lineChoice = "";

	// This variable stores all information relevant to the chosen adventure, including scenes.
	std::vector<AdventureObject*> myAdventure;

	// Here, the given input is used to determine the loaded text file.
	switch (userInput) {
	case 1:

		myAdventure.push_back(new HauntedHouseObject());
		break;

	case 2:

		myAdventure.push_back(new DesertedIslandObject());
		break;

	}

	// This variable acts as an input stream.
	std::ifstream inFile(myAdventure[0]->GetFile());
	SceneLoader* scenePtr = nullptr;

	if (!inFile.is_open()) {
		
		// This is printed if the file loading fails.
		std::cout << "The text adventure, " << myAdventure[0]->GetFile() << ", couldn't be opened." << std::endl;
		return;

	}
	else {
		
		// This loop reads and relays lines from the chosen adventure's text file into the Adventure object.
		while (std::getline(inFile, newLine)) {
			
			// Each scene in the text file starts with the [Scene] line, so here the pointer is defined with a new Scene object.
			if (newLine == "[Scene]") {

				scenePtr = new SceneLoader;

			}
			
			// Here, the name of a scene is changed in the SceneLoader class (through a setter).
			else if (newLine.rfind("(ID)", 0) == 0) {

				lineID = newLine.substr(4);
				scenePtr->SetSceneID(lineID);

			}
			
			// Here, the lines of description for a scene are passed to a vector in the SceneLoader class.
			else if (newLine.rfind("(Desc)", 0) == 0) {

				lineDescription = newLine.substr(6);
				scenePtr->SetDescription(lineDescription);

			}
			
			// Each scene in the text file ends with the [EndScene] line. 
			// Here, that scene data is passed to the myAdventure object and the pointer is emptied.
			else if (newLine.rfind("[EndScene]", 0) == 0) {

				// Here the scene name (ID) is paired with its description in a map (in the SceneLoader class).
				scenePtr->AddToMap(lineID);
				myAdventure[0]->AddScene(*scenePtr);

				delete scenePtr;
				scenePtr = nullptr;

			}
			
			// Here, the choices at the end of each scene are sorted by Description of the choice and the ID of the scene that choice connects to. 
			else if (newLine.rfind("(Choice)", 0) == 0) {

				lineChoice = newLine.substr(8);

				// Variable definitions: 
				// (as these variables are not used elsewhere, they are defined and declared here.

				int IDpos = lineChoice.find("]", 0) + 1;
				std::string lineChoiceDesc = lineChoice.substr(IDpos);
				std::string lineChoiceID = lineChoice.substr(0, IDpos);
				
				// This information is passed to the SceneLoader class to be stored.
				scenePtr->SetChoices(lineChoiceDesc, lineChoiceID);

			}

		}

		inFile.close();
		
		// Here, the scenes that were loaded into the Adventure object are printed to the console in sequence. 
		myAdventure[0]->AccessDescription(myAdventure[0]->GetFirstScene());

	}

	delete myAdventure[0];

}