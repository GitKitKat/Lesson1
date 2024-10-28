#include "Entity.h"

Entity::Entity() {

    health = 0;
    attack = 0;
    defense = 0;
    name = "name";

}

Entity::~Entity() {}

void Entity::SetName(std::string newName) {

    name = newName;

}

void Entity::SubtractHealth(int damageReceived) {

    health -= damageReceived;

}

std::string Entity::GetName() {

    return name;

}

int Entity::GetHealth() {

    return health;

}

int Entity::GetAttack() {

    return attack;

}

int Entity::GetDefense() {

    return defense;

}