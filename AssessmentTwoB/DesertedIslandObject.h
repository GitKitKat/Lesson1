#ifndef DESERTEDISLANDOBJECT_H
#define DESERTEDISLANDOBJECT_H

/* Includes: Parent class header */
#include "AdventureObject.h"

// This class contains all the data variables unique to the Deserted Island text adventure.
class DesertedIslandObject : public AdventureObject {

public:

	/* Declarations: */
	// Constructor
	DesertedIslandObject();

	// Destructor
	~DesertedIslandObject();

	/* Getter functions: */
	// This function returns whether or not a scene affects a player's stats.
	virtual bool GetStat() override;

	// This function prints the current time or time remaining.
	virtual void GetTime() override;

	/* Setter functions: */
	// This function increases the player's stats by an amount.
	virtual void SetStatIncrease(std::string sceneID) override;

	// This function decreases the player's stats by an amount.
	virtual void SetStatDecrease() override;

	// This function creates a condition for a forced ending and (if true) passes that ending's ID name.
	virtual void SetEnding(std::string& sceneID) override;

	// This function sets a new value for the timer.
	virtual void SetTime(std::string& sceneID) override;

private:

	// This variable holds a time value that changes depending on the 'timer' variable.
	int daysLeft;
	
	// This variable holds the value of the player's stat, 'health'.
	// The user's actions are interrupted when playerHealth becomes zero.
	int playerHealth;

};

#endif