#ifndef ENEMY_H
#define ENEMY_H

#include <string>
#include "Player.h"
#include "Entity.h"

// Structs
/*struct EnemyStats
{
    std::string name;
    int health = 80;
    int attack = 15;
    int defense = 8;
};*/

class Enemy : public Entity {
public:
    Enemy();
    ~Enemy();

    void EnemyAttack(Player& player, Enemy& enemy);
};

#endif