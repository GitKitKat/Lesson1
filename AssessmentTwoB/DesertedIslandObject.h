#ifndef DESERTEDISLANDOBJECT_H
#define DESERTEDISLANDOBJECT_H

// Includes: Parent class header 
#include "AdventureObject.h"

// This class contains all the data variables unique to the Deserted Island text adventure.
class DesertedIslandObject : public AdventureObject {

public:
	DesertedIslandObject();
	~DesertedIslandObject();

	virtual void TellTime() override;
	void ChangeStamina(int affectFear);
	void ChangeHealth();

protected:
	int playerStamina;
	int playerHealth;
};

#endif