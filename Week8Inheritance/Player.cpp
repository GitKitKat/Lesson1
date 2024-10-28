#include "Player.h"
#include <string>
#include <iostream>

Player::Player() {

    health = 100;
    attack = 20;
    defense = 10;

}

Player::~Player() {}

void Player::PlayerAttack(Player& player, Enemy& enemy) {
    std::cout << player.GetName() << " attacks " << enemy.GetName() << "!\n";
    int damage = player.GetAttack() - enemy.GetDefense();
    if (damage > 0)
    {
        enemy.SubtractHealth(damage);
        std::cout << enemy.GetName() << " takes " << damage << " damage!\n\n";
    }
    else
    {
        std::cout << "The attack was ineffective!\n\n";
    }
}