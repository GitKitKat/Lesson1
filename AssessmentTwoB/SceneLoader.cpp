// Includes: Standard header files
#include <string>
#include <iostream>
// Includes: This file's header
#include "SceneLoader.h"

// Constructor
SceneLoader::SceneLoader() {

	sceneIDname = "";
	sceneDescriptor.push_back("");
	scenesMap["[Introduction]"] = sceneDescriptor;
	choicesMap[""] = "";

}

// Destructor 
SceneLoader::~SceneLoader() {

}

std::string SceneLoader::GetSceneID() {

	return sceneIDname;

}

void SceneLoader::SetSceneID(std::string sceneID) {

	sceneIDname = sceneID;

}

void SceneLoader::SetDescription(std::string lineDesc) {

	if (sceneDescriptor[0] == "") {

		sceneDescriptor[0] = lineDesc;

	}
	else {

		sceneDescriptor.push_back(lineDesc);

	}

}

void SceneLoader::PrintDescription(std::string sceneID) {

	if (scenesMap[sceneID].size() > 1) {

		for (std::string i : scenesMap[sceneID]) {

			std::cout << i << std::endl;

		}

	}

}

void SceneLoader::AddToMap(std::string sceneID) {

	scenesMap[sceneID] = sceneDescriptor;
	sceneDescriptor.clear();
	sceneDescriptor.push_back("");

}

void SceneLoader::SetChoices(std::string lineChoiceDesc, std::string lineChoiceID) {

	choicesMap[lineChoiceDesc] = lineChoiceID;

}

void SceneLoader::ClearScene() {

	scenesMap.clear();
	sceneDescriptor.clear();
	choicesMap.clear();
	SceneLoader();

}