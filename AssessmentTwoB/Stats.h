#ifndef STATS_H
#define STATS_H // options: Gameobject, Entity

#include <string>

struct Room {



};

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
	std::string fileName;
	//std::string adventureName;
	
};

#endif 