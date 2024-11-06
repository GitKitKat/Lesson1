/* Includes: Standard header file */
#include <iostream>
/* Includes: This file's header */
#include "HauntedHouseObject.h"

HauntedHouseObject::HauntedHouseObject() {
	
	/* Definitions: */
	playerFear = 0;
	timer = 10.0f;
	filename = "HauntedHouse_Adventure.txt";

}

HauntedHouseObject::~HauntedHouseObject() {

}

bool HauntedHouseObject::GetStat() {

	if (playerFear >= 100) {

		return true;

	}

}

void HauntedHouseObject::GetTime() {

	int hours = int(timer);
	int minutes = int((timer - hours) * 100);

	if (minutes >= 60) {
		
		minutes -= 60;
		hours++;

	}

	if (timer <= 0) {

		minutes = 0;

	}
	
	// Here, the remaining time is printed in hours and minutes. 
	if (minutes == 0 && hours > 0) {

		std::cout << "There are " << hours << " hours left until sundown." << std::endl;

	} else if (hours == 0) {

		std::cout << "There are " << minutes << " minutes left until sundown." << std::endl;

	}
	else {

		std::cout << "There are " << hours << " hours and " << minutes << " minutes left until sundown." << std::endl;
	
	}
}

void HauntedHouseObject::SetStatIncrease(std::string sceneID) {

	playerFear += RandomGenerator() * 0.5;

	if (sceneID == "[Interruption]") {

		playerFear += RandomGenerator() * 0.8;

	}

}

void HauntedHouseObject::SetStatDecrease() {

	playerFear -= RandomGenerator() * 0.5;

}

void HauntedHouseObject::SetEnding(std::string& sceneID) {

	if (timer <= 0 && sceneID != "[Exit]") {

		sceneID = "[End_Time]";

	}
	else {

		SetTime(sceneID);

	}

}