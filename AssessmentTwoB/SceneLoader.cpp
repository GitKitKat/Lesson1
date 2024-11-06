/* Includes: Standard header files */
#include <string>
#include <iostream>
/* Includes: This file's header */
#include "SceneLoader.h"

SceneLoader::SceneLoader() {

	/* Definitions: */
	sceneIDname = "";
	statIncrease = false;
	statDecrease = false;
	sceneDescriptor.push_back("");
	scenesMap["[Introduction]"] = sceneDescriptor;
	choicesMap[""] = "";

}

SceneLoader::~SceneLoader() {

}

std::string SceneLoader::GetSceneID() {

	return sceneIDname;

}

bool SceneLoader::GetStatUp() const {

	return statIncrease;

}

bool SceneLoader::GetStatDown() const {

	return statDecrease;

}

void SceneLoader::SetSceneID(std::string sceneID) {

	sceneIDname = sceneID;

}

void SceneLoader::SetDescription(std::string lineDesc) {

	// Here, the temporary description is replaced with a genuine description.
	if (sceneDescriptor[0] == "") {

		sceneDescriptor[0] = lineDesc;

	}
	else {

		sceneDescriptor.push_back(lineDesc);

	}

}

void SceneLoader::SetChoices(std::string lineChoiceDesc, std::string lineChoiceID) {

	choicesMap.erase("");
	choicesMap[lineChoiceDesc] = lineChoiceID;

}

void SceneLoader::SetStatCase(std::string changeCase) {

	if (changeCase == "+") {

		statIncrease = true;

	}
	else if (changeCase == "-") {

		statDecrease = true;

	}

}

void SceneLoader::PrintDescription(std::string sceneID) {

	for (std::string i : scenesMap[sceneID]) {

		std::cout << i << std::endl;

	}

}

int SceneLoader::PrintChoices() {

	int i = 1;
	std::cout << "\n";

	// Here, an iterator (it) is used to parse choicesMap.
	for (auto it = choicesMap.begin(); it != choicesMap.end(); it++) {

		// Here, i is used to numerically list the scene's choices to the user.
		std::cout << i << ". " << it->first << std::endl;
		i++;

	}

	return choicesMap.size();

}

void SceneLoader::AddToMap() {

	scenesMap[sceneIDname] = sceneDescriptor;

}

std::string SceneLoader::NextScene(int input) {

	// Here, an iterator (it) is used to parse choicesMap.
	for (auto it = choicesMap.begin(); it != choicesMap.end(); it++) {

		// Here, the value of the distance between the iterator and the start of the map (0) is compared to the user's input (starts at 1),
		if (std::distance(choicesMap.begin(), it) == input - 1) {

			return it->second;

		}

	}

}