#ifndef HOUSE_H
#define HOUSE_H

#include "Stats.h"
#include <string>

class House : public Stats {

public: 
	House();
	~House();

	virtual void TellTime() override;
	std::string TellFile();

	void ChangeTime(float timeDecrease);
	void ChangeFear();


protected:
	int playerFear;
};

#endif
