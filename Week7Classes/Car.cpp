#include "Car.h"

Car::Car() {
	// Constructor
	Model = "";
	Make = "";
	Year = -1;
	CurrentMOTInfo.Condition = "Good";
	CurrentMOTInfo.Faults = "None";
}

Car::~Car() {
	// Destructor
}

bool Car::Service() {

	return true;

}

int Car::GetYear() {
	
	return Year;

}

void Car::SetYear(int newYear) {

	Year = newYear;

}

std::string Car::GetMOTICondition() {

	return CurrentMOTInfo.Condition;

}

std::string Car::GetMOTIFaults() {
	
	return CurrentMOTInfo.Faults;

}

void Car::SetMOTInfo(std::string newCondition, std::string newFaults) {

	CurrentMOTInfo.Condition = newCondition;
	CurrentMOTInfo.Faults = newFaults;

}