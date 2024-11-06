/* Includes: Standard header file */
#include <iostream>
/* Includes: This file's header */
#include "DesertedIslandObject.h"

DesertedIslandObject::DesertedIslandObject() {

	/* Definitions: */
	timer = 70.0f;
	playerHealth = 30;
	daysLeft = 7;
	filename = "DesertedIsland_Adventure.txt";

}

DesertedIslandObject::~DesertedIslandObject() {

}

bool DesertedIslandObject::GetStat() {

	if (playerHealth <= 0) {

		return true;

	}

}

void DesertedIslandObject::GetTime() {

	// Here, the remaining time in days is printed. 
	if (daysLeft == 0) {

		std::cout << "The storm has come." << std::endl;
		timer = 0;

	}
	else {

		std::cout << daysLeft << " days until the storm arrives." << std::endl;

	}

}

void DesertedIslandObject::SetStatIncrease(std::string sceneID) {

	if (playerHealth < 30) {

		playerHealth += RandomGenerator() * 0.1;

	}

	if (playerHealth > 30 || sceneID == "[Interruption]") {

		playerHealth = 30;

	}

}

void DesertedIslandObject::SetStatDecrease() {

	playerHealth -= RandomGenerator() * 0.05;

	if (playerHealth < 0) {

		playerHealth = 0;

	}

}

void DesertedIslandObject::SetEnding(std::string& sceneID) {

	if (sceneID == "[Camp]") {

		daysLeft -= 1;
		if (daysLeft > 0) {
		
			timer = 70;
		
		}

	}

	if (daysLeft <= 0 && timer <= 0 && sceneID != "[Exit]") {

		sceneID = "[End_Time]";

	}
	else {

		if (sceneID == "[Exit]") {

			return;

		}

		SetTime(sceneID);

		if (sceneID != "[Time]") {

			SetStatDecrease();

		}

	}

}

void DesertedIslandObject::SetTime(std::string& sceneID) {

	timer -= RandomGenerator() * 0.2;

	if (timer <= 0) {

		daysLeft -= 1;
		timer = 70;
		sceneID = "[Time]";

	}

}