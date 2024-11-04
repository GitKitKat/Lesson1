#ifndef HAUNTEDHOUSEOBJECT_H
#define HAUNTEDHOUSEOBJECT_H

// Includes: Parent class header 
#include "AdventureObject.h"

// This class contains all the data variables unique to the Haunted House text adventure.
class HauntedHouseObject : public AdventureObject {

public: 
	HauntedHouseObject();
	~HauntedHouseObject();

	virtual void TellTime() override;
	void ChangeFear(int affectFear);

protected:
	int playerFear;
};

#endif
