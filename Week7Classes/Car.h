// #pragma once 
// if this file is included in multiple cpps, it will only compile once

#ifndef CAR_H
#define CAR_H

#include <string>

struct MOTInfo { 
	
	std::string Condition;
	std::string Faults;

};

class Car { 
public:
	// classes are private by default (structs are public by default)
	Car(); // constructor creates the base values
	~Car(); // destructor destroys the variables after runtime

	bool Service();

	// Getter/Setter are used so data isn't accidentally changed
	int GetYear();
	void SetYear(int newYear);

	std::string GetMOTICondition();
	std::string GetMOTIFaults();
	void SetMOTInfo(std::string newCondition, std::string newFaults);

private:
	// variables can be defined here but it's not liked (industry)
	std::string Model;
	std::string Make;
	int Year;
	MOTInfo CurrentMOTInfo;
	
};

#endif
// this header documentation does the same as pragma, but pragma is new so it won't work with older IDEs