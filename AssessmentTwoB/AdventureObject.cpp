// Includes: Standard header file
#include <iostream>
// Includes: This file's header
#include "AdventureObject.h"

// Constructor
AdventureObject::AdventureObject() {

	time = 0;
	filename = "";
	SceneLoader tempScene;
	adventureScenes[0] = tempScene;

}

// Destructor
AdventureObject::~AdventureObject() {

}

// Returns the name of the file connected to the text adventure.
std::string AdventureObject::GetFile() {

	return filename;

}

void AdventureObject::AddScene(SceneLoader sceneLine) {

	adventureScenes.push_back(sceneLine);

}

void AdventureObject::AccessDescription(std::string sceneID) {

	for (int i = 0; i < adventureScenes.size(); i++) {

		if (adventureScenes[i].GetSceneID() == sceneID) {

			adventureScenes[i].PrintDescription(sceneID);

		}

	}

}

// Decreases the remaining time by an inputed amount.
void AdventureObject::ChangeTime(float timeDecrease) {

	time -= timeDecrease;

}