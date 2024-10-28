#include "House.h"
#include <iostream>

House::House() {
	
	playerFear = 0;
	time = 10.0f; //in hours
	//constructor

}

House::~House() {

	//destructor

}

void House::ChangeTime() {

	// a function that should only reduce time

}

void House::ChangeFear() {

	// consider a function that can increase or reduce fear

}

void House::TellTime() {

	int hours = int(time);
	int minutes = ;

	std::cout << "There are currently " << hours << " hours and " << minutes << " minutes until sundown.";

}