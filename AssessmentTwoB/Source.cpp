/* Includes: Standard header files */
#include <iostream>
#include <fstream>
#include <string>

/* Includes: Class header files */
#include "SceneLoader.h"
#include "AdventureObject.h"
#include "HauntedHouseObject.h"
#include "DesertedIslandObject.h"

/* Declaration: */
// This function loads the chosen text adventure and splits its scenes into separate objects.
void loadAdventure(int userInput);

// This is the project's entry point.
int main() {

	// This holds the user's adventure choice.
	int userInput = 0;

	// Here, the user chooses which text adventure to run. 
	// Any numerical error will clear the console and repeat the prompt.
	while (true) {

		std::cout << "From the available text adventures, enter your choice."
			<< "\n1. Retrieve an item from a Haunted House."
			<< "\n2. Survive on a Deserted Island." << std::endl;
		std::cin >> userInput;

		if (userInput == 1 || userInput == 2) {

			break;

		}

		// If there is no error, the following lines will not be processed.
		AdventureObject::ClearConsole();
		std::cout << "That was not one of the available text adventures." << std::endl;

	}

	// Here, the console is cleared before the text adventures start.
	AdventureObject::ClearConsole();

	// Here, the chosen adventure is loaded.
	loadAdventure(userInput);

	return 0;
}

void loadAdventure(int userInput) {

	/* Variable declarations:
	These variables are used to hold and parse the data read from the text file. */
	// This variable stores each whole line read from the text file.
	std::string newLine = "";

	// This variable stores the choices that follow the scene being read.
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

	// This pointer variable is used to create an object that stores data loaded from the text file as a scene.
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

				scenePtr->SetSceneID(newLine.substr(4));

			}
			
			// Here, the scene is marked as changing a value specific to the player
			else if (newLine.rfind("(Stat)", 0) == 0) {

				scenePtr->SetStatCase(newLine.substr(6));

			}

			// Here, the lines of description for a scene are passed to a vector in the SceneLoader class.
			else if (newLine.rfind("(Desc)", 0) == 0) {

				scenePtr->SetDescription(newLine.substr(6));

			}
			
			// Here, the choices at the end of each scene are sorted by Description of the choice and the ID of the scene that choice connects to. 
			else if (newLine.rfind("(Choice)", 0) == 0) {

				lineChoice = newLine.substr(8);

				/* Variable definitions:
				As these variables are not used elsewhere, they are defined and declared here. */

				// This variable stores the index of the last character (of scene ID name) in a line.
				int IDpos = lineChoice.find("]", 0) + 1;

				// This variable stores the description of a choice (following a scene) after cutting off the scene ID it leads to.
				std::string lineChoiceDesc = lineChoice.substr(IDpos);

				// This variable stores the scene ID name of the scene that follows a choice (following a scene).
				std::string lineChoiceID = lineChoice.substr(0, IDpos);
				
				// This information is passed to the SceneLoader class to be stored.
				scenePtr->SetChoices(lineChoiceDesc, lineChoiceID);

			}

			// Each scene in the text file ends with the [EndScene] line. 
			// Here, that scene data is passed to the myAdventure object and the pointer is emptied.
			else if (newLine == "[EndScene]") {

				// Here the scene name (ID) is paired with its description in a map (in the SceneLoader class).
				scenePtr->AddToMap();
				myAdventure[0]->AddScene(*scenePtr);

				delete scenePtr;
				scenePtr = nullptr;

			}

		}

		inFile.close();
		
		// Here, the scenes that were loaded into the Adventure object are printed to the console in sequence. 
		myAdventure[0]->PlayAdventure(myAdventure[0]->GetFirstScene());

	}

	delete myAdventure[0];

}