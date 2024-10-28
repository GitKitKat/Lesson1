#ifndef STATS.H
#define STATS.H

#include <string>

class Stats {

public:
	Stats();
	~Stats();

	virtual void TellTime() = 0;
	// a pure virtual class cannot be instanced

	//void ClearConsole();
	//void SetAdventure(std::string txtName);

protected:
	float time;
	//std::string adventureName;
	
};

#endif 