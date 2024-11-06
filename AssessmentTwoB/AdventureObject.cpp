/* Includes: Standard header file */
#include <iostream>
#include <stdlib.h> 
#include <time.h>
/* Includes: This file's header */
#include "AdventureObject.h"

AdventureObject::AdventureObject() {

	/* Definitions: */
	tempChoices = 0;
	tempInput = 0;
	timer = 0;
	//tempStr = "";
	filename = "";
	adventureScenes.push_back(tempScene);

}

AdventureObject::~AdventureObject() {

}

void AdventureObject::ClearConsole() {

#ifdef _WIN32
	system("CLS");
#else
	system("clear");
#endif

}

float AdventureObject::RandomGenerator() {

	srand(time(0));

	return float(rand() % 100 + 1);

}

std::string AdventureObject::GetFile() {

	return filename;

}

std::string AdventureObject::GetFirstScene() {

	return adventureScenes[0].GetSceneID();

}

void AdventureObject::SetStat(bool statUp, bool statDown, std::string sceneID) {

	if (statUp == true) {

		SetStatIncrease(sceneID);

	}
	else if (statDown == true) {

		SetStatDecrease();

	}

}

void AdventureObject::SetTime(std::string& sceneID) {

	timer -= RandomGenerator() * 0.01;

}

void AdventureObject::AddScene(SceneLoader sceneLine) {

	// Here, the temporary scene is replaced with a genuine scene.
	if (adventureScenes[0].GetSceneID() == "") {

		adventureScenes[0] = sceneLine;

	}
	else {

		adventureScenes.push_back(sceneLine);

	}

}

void AdventureObject::PlayAdventure(std::string sceneID) {

	// If the player's stats have reached the predetermined limit, the scene is changed here.
	// Otherwise, the scenes printed will be chosen based on the user's input.
	if (GetStat() == true) {

		sceneID = "[Interruption]";

	}

	// Here, adventureScenes is searched until a particular scene is found (by matching ID name) and printed.
	for (int i = 0; i < adventureScenes.size(); i++) {

		if (adventureScenes[i].GetSceneID() == sceneID) {

			// Here, whether the scene affects the player's stats or not is checked.
			SetStat(adventureScenes[i].GetStatUp(), adventureScenes[i].GetStatDown(), sceneID);

			// Here, the description of the scene is printed.
			adventureScenes[i].PrintDescription(sceneID);

			// Here, the user is told the current time.
			if (sceneID == "[Time]") {

				GetTime();

			}
			// Here, the recursive loop is broken if the user has reached the end of the text adventure.
			if (sceneID == "[Exit]") {

				return;

			}

			// Here, the choices following a scene are printed.
			tempChoices = adventureScenes[i].PrintChoices();

			// Here, the user's choise (inputted as an integer) is collected and checked for numerical errors. 
			std::cin >> tempInput;

			ClearConsole();

			if (tempInput > tempChoices || tempInput < 1) {

				std::cout << "That was not one of the available options." << std::endl;

				// Here, the function calls itself to create a loop.
				// The ID name of the scene doesn't change as the user's input was outside the bounds.
				PlayAdventure(sceneID);

			}
			else {

				// Here, the user's choice (integer) is passed to a function that returns the ID name of the scene that follows.
				sceneID = adventureScenes[i].NextScene(tempInput);

				// Whether or not the user meets the requirements for a forced ending is checked here.
				SetEnding(sceneID);

				// Here, the function calls itself to create a loop.
				PlayAdventure(sceneID);

			}

		}

		else if (adventureScenes[i].GetSceneID() != sceneID && i == adventureScenes.size() - 1 && sceneID != "[Exit]") {

			i = 0;

		}

	}

}