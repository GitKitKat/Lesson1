#ifndef SCENELOADER_H
#define SCENELOADER_H 

// Includes: Standard header files
#include <string>
#include <map>
#include <vector>

// This class contains all the logic specific to parsing the text adventures.
class SceneLoader {

public:
	SceneLoader();
	~SceneLoader();

	std::string GetSceneID();
	void SetSceneID(std::string sceneID);
	void SetDescription(std::string lineDesc);
	void SetChoices(std::string lineChoiceDesc, std::string lineChoiceID);
	
	void PrintDescription(std::string sceneID);
	void AddToMap(std::string sceneID);
	std::string NextScene(int input);
	int PrintChoices();

protected:
	std::string sceneIDname;
	// Full description of a particular scene
	std::vector<std::string> sceneDescriptor;

	// ID of a scene, Description of the scene
	std::map<std::string, std::vector<std::string>> scenesMap;

	// Description of a choice, ID the choice leads to
	std::map<std::string, std::string> choicesMap;
};

#endif 
