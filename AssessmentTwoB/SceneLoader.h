#ifndef SCENELOADER_H
#define SCENELOADER_H 

/* Includes: Standard header files */
#include <string>
#include <map>
#include <vector>

// This class contains all the logic specific to parsing the text adventures.
class SceneLoader {

public:

	/* Declarations: */
	// Constructor
	SceneLoader();

	// Destructor
	~SceneLoader();


	/* Getter functions: */
	// This function returns the ID name of a certain scene.
	std::string GetSceneID();

	// This function returns whether or not a certain scene positively affects the player's stats.
	bool GetStatUp() const;

	// This function returns whether or not a certain scene negatively affects the player's stats.
	bool GetStatDown() const;


	/* Setter functions: */
	// This function sets the ID name of a certain scene.
	void SetSceneID(std::string sceneID);

	// This function sets the description of a certain scene.
	void SetDescription(std::string lineDesc);

	// This function sets the choices that follow a certain scene.
	void SetChoices(std::string lineChoiceDesc, std::string lineChoiceID);

	// This function sets the effect on a player's stats (positive or negative) for a scene.
	void SetStatCase(std::string statCase);
	
	
	/* Printing functions: 
	These functions print loaded data to the console. */
	// This function prints the description of a certain scene.
	void PrintDescription(std::string sceneID);

	// This function prints the choices that follow a certain scene.
	int PrintChoices();


	/* Loading functions: 
	These functions handle loading and printing the data read from the related adventure's text file into a particular scene.*/
	// This function pairs the ID name and description of a certain scene together in a map.
	void AddToMap();

	// This function returns the ID name of a scene that follows a choice.
	std::string NextScene(int input);

private:

	// This variable holds the ID name of a certain scene.
	std::string sceneIDname;

	// If a player's stats are increased in a certain scene, this variable is true.
	bool statIncrease;
	
	// If a player's stats are decreased in a certain scene, this variable is true.
	bool statDecrease;

	// This variable holds the full description of a certain scene.
	std::vector<std::string> sceneDescriptor;

	// This variable holds the ID name and description of a certain scene.
	std::map<std::string, std::vector<std::string>> scenesMap;

	// This variable holds the description of a choice that follows a certain scene and the ID name of the scene that this choice leads to.
	std::map<std::string, std::string> choicesMap;

};

#endif 