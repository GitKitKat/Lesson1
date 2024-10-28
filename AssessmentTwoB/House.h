#ifndef HOUSE.H
#define HOUSE.H

#include "Stats.h"

class House : public Stats {

public: 
	House();
	~House();

	virtual void TellTime() override;
	void ChangeTime();
	void ChangeFear();

protected:
	int playerFear;
};

#endif
