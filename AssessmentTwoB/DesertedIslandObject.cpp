// Includes: Standard header file
#include <iostream>
// Includes: This file's header
#include "DesertedIslandObject.h"

// Constructor
DesertedIslandObject::DesertedIslandObject() {

	playerStamina = 100;
	playerHealth = 50;
	timer = 5; // Time in days
	filename = "DesertedIsland_Adventure.txt";

}

// Destructor
DesertedIslandObject::~DesertedIslandObject() {

}

void DesertedIslandObject::ChangeStamina(int affectFear) {

	// consider a function that can increase or reduce fear

}

void DesertedIslandObject::ChangeHealth() {

}

// Prints the remaining time in days. 
void DesertedIslandObject::TellTime() {

	if (timer == 0) {

		std::cout << "The storm has come." << std::endl;

	}
	else {

		std::cout << int(timer) << " days until the storm." << std::endl;

	}

}
