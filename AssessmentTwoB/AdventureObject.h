#ifndef ADVENTUREOBJECT_H
#define ADVENTUREOBJECT_H 

/* Includes: Standard header files */
#include <string>
#include <map>
/* Includes: Class header file(not inherited) */
#include "SceneLoader.h"

// The text adventure classes in this project are derived from this class.
class AdventureObject {

public:

	/* Declarations: */
	// Constructor
	AdventureObject();

	// Destructor
	~AdventureObject();


	/* Utility functions:
	These are not directly related to reading, loading or printing from the text files. */
	// This function removes all text on the console, returning the cursor to the start.
	static void ClearConsole();

	// This function returns a randomly generated float number between 1 and 100.
	float RandomGenerator();


	/* Getter functions: */
	// This function returns the name of the text file connected to the text adventure.
	std::string GetFile();

	// This function returns the ID name of the text adventure's first loaded scene and starting point.  
	std::string GetFirstScene();

	// When overriden, this function returns whether or not a scene affects a player's stats.
	virtual bool GetStat() = 0;

	// When overriden, this function prints the current value of the timer.
	virtual void GetTime() = 0;


	/* Setter functions: */
	// This function will check whether or not a scene affects a player stat.
	void SetStat(bool statUp, bool statDown, std::string sceneID);

	// When overriden, this function increases the player's stats by an amount.
	virtual void SetStatIncrease(std::string sceneID) = 0;

	// When overriden, this function decreases the player's stats by an amount.
	virtual void SetStatDecrease() = 0;

	// When overriden, this function creates a condition for a forced ending and (if true) passes that ending's ID name.
	virtual void SetEnding(std::string& sceneID) = 0;

	// This function sets a new value for the timer.
	virtual void SetTime(std::string& sceneID);


	/* Loading functions:
	These functions handle loading and printing the data read from the related adventure's text file. */
	// This function enters a fully-loaded scene object into the adventureScene vector to be stored.
	void AddScene(SceneLoader sceneLine);

	// This recursive function prints the scenes loaded (description and choices) from the related text file.
	void PlayAdventure(std::string sceneID);
	
protected: 
	
	// This variable is used to limit the number of times a user can play through a sequence of scenes.
	float timer;
	
	// This variable holds the name of the related text adventure's text file.
	std::string filename;
	
	// This variable holds all the scenes loaded from a text adventure's text file as objects in a vector.
	std::vector<SceneLoader> adventureScenes;

	/* Variable declarations:
	These variables are used as placeholders or to temporarily store data passed between functions. */

	int tempInput;
	int tempChoices;
	SceneLoader tempScene;
	
};

#endif 