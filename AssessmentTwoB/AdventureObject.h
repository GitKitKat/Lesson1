#ifndef ADVENTUREOBJECT_H
#define ADVENTUREOBJECT_H 

// Includes: Standard header files
#include <string>
#include <map>
// Includes: Class header file (not inherited)
#include "SceneLoader.h"

// This class is the base for the text adventures included in this project.
class AdventureObject {
public:
	AdventureObject();
	~AdventureObject();
	
	static void clearConsole();

	std::string GetFile();
	std::string GetFirstScene();

	void AddScene(SceneLoader sceneLine);
	void AccessDescription(std::string sceneID);

	float RandomGenerator();
	void ChangeTime(float timeDecrease);
	virtual void TellTime() = 0;
	
protected: 
	float timer;
	std::string filename;
	SceneLoader tempScene;
	int tempInt;
	int tempInput;
	std::string tempStr;
	std::vector<SceneLoader> adventureScenes;
};

#endif 