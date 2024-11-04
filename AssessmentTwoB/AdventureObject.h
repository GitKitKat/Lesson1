#ifndef ADVENTUREOBJECT_H
#define ADVENTUREOBJECT_H 

// Includes: Standard header files
#include <string>
#include <map>
// Includes: Class header file (not inherited)
#include "SceneLoader.h"
//class SceneLoader;

// This class is the base for the text adventures included in this project.
class AdventureObject {

	//friend class SceneLoader;

public:
	AdventureObject();
	~AdventureObject();
	
	std::string GetFile();
	void AddScene(SceneLoader sceneLine);
	void AccessDescription(std::string sceneID);

	void ChangeTime(float timeDecrease);
	virtual void TellTime() = 0;
	
protected: 
	float time;
	std::string filename;
	std::vector<SceneLoader> adventureScenes;
};

#endif 