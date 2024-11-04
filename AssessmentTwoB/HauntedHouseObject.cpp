// Includes: Standard header file
#include <iostream>
// Includes: This file's header
#include "HauntedHouseObject.h"

// Constructor
HauntedHouseObject::HauntedHouseObject() {
	
	playerFear = 0;
	time = 10.0f; // Time in hours
	filename = "HauntedHouse_Adventure.txt";

}

// Destructor
HauntedHouseObject::~HauntedHouseObject() {

}

void HauntedHouseObject::ChangeFear(int affectFear) {

	// consider a function that can increase or reduce fear

}

// Prints the remaining time in hours and minutes. 
void HauntedHouseObject::TellTime() {

	int hours = int(time);
	int minutes = int((time - hours) * 100);

	std::cout << "There are currently " << hours << " hours and " << minutes << " minutes until sundown." << std::endl;

}
