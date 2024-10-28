#include "House.h"
#include <iostream>
#include <string>

House::House() {
	
	playerFear = 0;
	time = 10.0f; //in hours
	fileName = "HauntedHouse.txt";
	//constructor

}

House::~House() {

	//destructor

}

void House::ChangeTime(float timeDecrease) {
// a function that should only reduce time
	time -= timeDecrease;

}

void House::ChangeFear() {

	// consider a function that can increase or reduce fear

}

void House::TellTime() {

	int hours = int(time);
	int minutes = (time - hours) * 100;

	std::cout << "There are currently " << hours << " hours and " << minutes << " minutes until sundown.";

}

std::string House::TellFile() {

	return fileName;

}