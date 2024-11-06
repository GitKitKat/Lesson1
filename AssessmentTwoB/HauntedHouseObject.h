#ifndef HAUNTEDHOUSEOBJECT_H
#define HAUNTEDHOUSEOBJECT_H

/* Includes: Parent class header */
#include "AdventureObject.h"

// This class contains all the data variables unique to the Haunted House text adventure.
class HauntedHouseObject : public AdventureObject {

public: 

	/* Declarations: */
	// Constructor
	HauntedHouseObject();

	// Destructor
	~HauntedHouseObject();

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

private:

	// This variable holds the value of the player's stat, 'fear'.
	// The user's actions are interrupted when playerHealth becomes one hundred.
	int playerFear;

};

#endif