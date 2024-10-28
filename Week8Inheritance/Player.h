#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "Enemy.h"
#include "Entity.h"

// Structs
/*struct PlayerStats
{
    std::string name;
    int health = 100;
    int attack = 20;
    int defense = 10;
};*/

class Player : public Entity {
public:
    Player();
    ~Player();

    void PlayerAttack(Player& player, Enemy& enemy);
};

#endif