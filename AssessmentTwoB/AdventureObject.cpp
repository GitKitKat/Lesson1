// Includes: Standard header file
#include <iostream>
#include <stdlib.h> 
#include <time.h>
// Includes: This file's header
#include "AdventureObject.h"

// Constructor
AdventureObject::AdventureObject() {

	timer = 0;
	filename = "";
	tempInt = 0;
	tempInput = 0;
	tempStr = "";
	adventureScenes.push_back(tempScene);

}

// Destructor
AdventureObject::~AdventureObject() {

}

// Returns the name of the file connected to the text adventure.
std::string AdventureObject::GetFile() {

	return filename;

}

void AdventureObject::AddScene(SceneLoader sceneLine) {

	if (adventureScenes[0].GetSceneID() == "") {

		adventureScenes[0] = sceneLine;

	}
	else {

		adventureScenes.push_back(sceneLine);

	}

}

// This function removes all text on the console, returning the cursor to the start.
void AdventureObject::clearConsole() {
#ifdef _WIN32
	system("CLS");
#else
	system"clear");
#endif
}

std::string AdventureObject::GetFirstScene() {

	return adventureScenes[0].GetSceneID();

}

float AdventureObject::RandomGenerator() {

	srand(time(0));

	return float((rand() % 100 + 1) * 0.01);

}

void AdventureObject::AccessDescription(std::string sceneID) {

	for (int i = 0; i < adventureScenes.size(); i++) {

		if (adventureScenes[i].GetSceneID() == sceneID) {

			adventureScenes[i].PrintDescription(sceneID);

			if (sceneID == "[Time]") {

				TellTime();

			}
			if (sceneID == "[Exit]") {
				
				return;
			
			}

			std::cout << "\n";

			tempInt = adventureScenes[i].PrintChoices();

			std::cin >> tempInput;
			if (tempInput > tempInt) {

				clearConsole();

				std::cout << "That was not one of the available options." << std::endl;
				AccessDescription(sceneID);

			}
			else {

				clearConsole();

				tempStr = adventureScenes[i].NextScene(tempInput);

				if (timer <= 0 && tempStr != "[Exit]") {

					tempStr = "[End_Time]";

				}
				else {

					ChangeTime(RandomGenerator());

				}

				AccessDescription(tempStr);

			}

		}

	}
}

// Decreases the remaining time by an inputed amount.
void AdventureObject::ChangeTime(float timeDecrease) {

	timer -= timeDecrease;

}