// Includes: Standard header file
#include <iostream>
// Includes: This file's header
#include "HauntedHouseObject.h"

// Constructor
HauntedHouseObject::HauntedHouseObject() {
	
	playerFear = 0;
	timer = 10.0f; // Time in hours
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

	int hours = int(timer);
	int minutes = int((timer - hours) * 100);

	if (minutes >= 60) {
		
		minutes -= 60;
		hours++;

	}

	if (timer <= 0) {

		minutes = 0;

	}
	
	if (minutes == 0 && hours > 0) {

		std::cout << "There are currently " << hours << " hours until sundown." << std::endl;

	} else if (hours == 0) {

		std::cout << "There are currently " << minutes << " minutes until sundown." << std::endl;

	}
	else {

		std::cout << "There are currently " << hours << " hours and " << minutes << " minutes until sundown." << std::endl;
	
	}
}

