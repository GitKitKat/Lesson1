#include "Enemy.h"
#include <string>
#include <iostream>

Enemy::Enemy() {

    health = 80;
    attack = 15;
    defense = 8;

}

Enemy::~Enemy() {}

void Enemy::EnemyAttack(Player& player, Enemy& enemy) {
    std::cout << enemy.GetName() << " attacks " << player.GetName() << "!\n";
    int damage = enemy.GetAttack() - player.GetDefense();
    if (damage > 0)
    {
        player.SubtractHealth(damage);
        std::cout << player.GetName() << " takes " << damage << " damage!\n\n";
    }
    else
    {
        std::cout << "The attack was ineffective!\n";
    }
}
