#ifndef ENTITY_H
#define ENTITY_H

#include <string>

class Entity {
public: 
	Entity();
	~Entity();

	std::string GetName();
	int GetHealth();
	int GetAttack();
	int GetDefense();

	void SubtractHealth(int damageReceived);
	void SetName(std::string newName);

protected:
	int health;
	int attack;
	int defense;
	std::string name;

private:
	
};

#endif